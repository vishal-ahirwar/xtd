#include <codecvt>
#include <iostream>
#include <set>
#include <xtd/invalid_operation_exception.h>
#include <xtd/diagnostics/debug.h>
#include <xtd/diagnostics/debugger.h>
#include <xtd/diagnostics/trace_switch.h>
#include <xtd/drawing/system_fonts.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/graphics.h>
#include <xtd/drawing/native/system_colors.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/mouse_key.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/control.h"
#include "../../../include/xtd/forms/control_paint.h"
#include "../../../include/xtd/forms/control_renderer.h"
#include "../../../include/xtd/forms/enable_debug.h"
#include "../../../include/xtd/forms/form.h"
#include "../../../include/xtd/forms/message_box.h"
#include "../../../include/xtd/forms/screen.h"
#include "../../../include/xtd/forms/visual_styles/control_state.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace {
  class reentrant_layout {
  public:
    explicit reentrant_layout(control* do_layout) : do_layout_(do_layout) {do_layouts.insert(do_layout_);}
    ~reentrant_layout() {do_layouts.erase(do_layout_);}
    static bool is_reentrant(control* do_layout) {return do_layouts.find(do_layout) != do_layouts.end(); }
  private:
    control* do_layout_ = nullptr;
    static set<control*> do_layouts;
  };
  
  set<control*> reentrant_layout::do_layouts;
  
  mouse_buttons wparam_to_mouse_buttons(const message& message) {
    if ((message.wparam() & MK_LBUTTON) == MK_LBUTTON)
      return mouse_buttons::left;
    else if ((message.wparam() & MK_RBUTTON) == MK_RBUTTON)
      return mouse_buttons::right;
    else if ((message.wparam() & MK_MBUTTON) == MK_MBUTTON)
      return mouse_buttons::middle;
    return mouse_buttons::none;
  }
  
  bool is_trace_form_or_control(const string& name) {
    return name == "9f5767d6-7a21-4ebe-adfe-2427b2024a55" || name == "d014d407-851c-49c1-a343-3380496a639a";
  }
}

bool control::check_for_illegal_cross_thread_calls_ = diagnostics::debugger::is_attached();
std::thread::id control::handle_created_on_thread_id_ = std::this_thread::get_id();
forms::keys control::modifier_keys_ = forms::keys::none;
forms::mouse_buttons control::mouse_buttons_ = forms::mouse_buttons::none;
map<intptr_t, control*> control::handles_;
control::control_collection control::top_level_controls_;

control::control_collection::control_collection(const control::control_collection::allocator_type& allocator) : control::control_collection::base(allocator) {
}

control::control_collection::control_collection(const control::control_collection::base& collection) : control::control_collection::base(collection) {}
control::control_collection::control_collection(const control::control_collection& collection) : control::control_collection::base(collection) {}
control::control_collection& control::control_collection::operator=(const control::control_collection& collection) {
  base::operator=(collection);
  return *this;
}

optional<control::control_collection::value_type> control::control_collection::operator[](const ustring& name) const {
  for (auto item : *this)
    if (item.get().name() == name) return item;
  return {};
}

optional<control::control_collection::value_type> control::control_collection::operator[](const ustring& name) {
  for (auto item : *this)
    if (item.get().name() == name) return item;
  return {};
}

control::control() {
  native::application::initialize();
  if (!application::message_loop() && cursor::current() == cursor::none) cursor::current(cursors::wait_cursor());
  set_state(state::enabled, true);
  set_state(state::visible, true);
  set_state(state::tab_stop, true);
  set_style(control_styles::all_painting_in_wm_paint | control_styles::user_paint | control_styles::standard_click | control_styles::standard_double_click | control_styles::use_text_for_accessibility | control_styles::selectable, true);
  
  data_->controls.item_added += [&](size_t, reference_wrapper<control> item) {
    on_control_added(control_event_args(item.get()));
    item.get().data_->parent = data_->handle;
    if (data_->handle)
      item.get().create_control();
  };
  
  data_->controls.item_removed += [&](size_t, reference_wrapper<control> item) {
    on_control_removed(control_event_args(item.get()));
    item.get().data_->parent = 0;
    item.get().destroy_control();
  };
}

control::control(const xtd::ustring& name, bool) {
  data_->name = name;
}

control::~control() {
  destroy_control();
}

anchor_styles control::anchor() const {
  return data_->anchor;
}

control& control::anchor(anchor_styles anchor) {
  if (data_->anchor != anchor) {
    data_->anchor = anchor;
    set_state(state::docked, false);
    if (handle() && parent()) data_->anchoring = {left(), location().y(), parent().value().get().client_size().width() - width() - left(), parent().value().get().client_size().height() - height() - top()};
    perform_layout();
  }
  return *this;
}

drawing::point control::auto_scroll_point() const {
  return data_->auto_scroll_point;
}

bool control::auto_size() const {
  return get_state(state::auto_size);
}

control& control::auto_size(bool auto_size) {
  if (get_state(state::auto_size) != auto_size) {
    set_state(state::auto_size, auto_size);
    on_auto_size_changed(event_args::empty);
  }
  return *this;
}

color control::back_color() const {
  for (const control* control = this; control; control = control->parent().has_value() ? &control->parent().value().get() : nullptr)
    if (control->data_->back_color.has_value()) return control->data_->back_color.value();
  return default_back_color();
}

control& control::back_color(const color& color) {
  if (back_color() != color) {
    data_->back_color = color;
    if (is_handle_created()) native::control::back_color(handle(), data_->back_color.value());
    for (auto& control : controls())
      if (control.get().data_->parent) control.get().on_parent_back_color_changed(event_args::empty);
    on_back_color_changed(event_args::empty);
  }
  return *this;
}

control& control::back_color(std::nullptr_t) {
  if (data_->back_color.has_value()) {
    data_->back_color.reset();
    post_recreate_handle();
    for (auto& control : controls())
      if (control.get().data_->parent) control.get().on_parent_back_color_changed(event_args::empty);
    on_back_color_changed(event_args::empty);
  }
  return *this;
}

const xtd::drawing::image& control::background_image() const {
  return data_->background_image;
}

control& control::background_image(const xtd::drawing::image& background_image) {
  if (data_->background_image != background_image) {
    data_->background_image = background_image;
    on_background_image_changed(event_args::empty);
  }
  return *this;
}

xtd::forms::image_layout control::background_image_layout() const {
  return data_->background_image_layout;
}

control& control::background_image_layout(xtd::forms::image_layout background_image_layout) {
  if (data_->background_image_layout != background_image_layout) {
    data_->background_image_layout = background_image_layout;
    on_background_image_layout_changed(event_args::empty);
  }
  return *this;
}

int32_t control::bottom() const {
  return top() + height();
}

drawing::rectangle control::bounds() const {
  return {location(), size()};
}

control& control::bounds(const drawing::rectangle& bounds) {
  set_bounds_core(bounds.x(), bounds.y(), bounds.width(), bounds.height(), bounds_specified::all);
  return *this;
}

bool control::can_focus() const {
  bool visible_and_enabled = handle() && get_state(state::visible) && get_state(state::enabled);
  
  optional<reference_wrapper<control>> top_level_control = const_cast<control&>(*this);
  while (visible_and_enabled && top_level_control.has_value() && !top_level_control.value().get().get_state(state::top_level)) {
    top_level_control = top_level_control.value().get().parent();
    if (top_level_control.has_value()) visible_and_enabled = top_level_control.value().get().get_state(state::visible) && get_state(state::enabled);
  }
  
  if (!visible_and_enabled) return false;
  return data_->can_focus;
}

bool control::can_select() const {
  return enabled() && visible() && get_style(control_styles::selectable);
}

bool control::can_raise_events() const {
  return data_->can_raise_events;
}

bool control::check_for_illegal_cross_thread_calls() {
  return check_for_illegal_cross_thread_calls_;
}

void control::check_for_illegal_cross_thread_calls(bool value) {
  check_for_illegal_cross_thread_calls_ = value;
}

const drawing::rectangle& control::client_rectangle() const {
  return data_->client_rectangle;
}

const drawing::size& control::client_size() const {
  return data_->client_size;
}

control& control::client_size(const drawing::size& client_size) {
  if (!get_state(state::client_size_setted) || data_->client_size != client_size) {
    set_state(state::client_size_setted, true);
    set_client_size_core(client_size.width(), client_size.height());
  }
  return *this;
}

xtd::ustring control::company_name() const {
  return "Gammasoft";
}

std::optional<std::reference_wrapper<xtd::forms::context_menu>> control::context_menu() const {
  return data_->context_menu;
}

control& control::context_menu(xtd::forms::context_menu& value) {
  if (!data_->context_menu.has_value() || &data_->context_menu.value().get() != &value)
    data_->context_menu = const_cast<forms::context_menu&>(value);
  return *this;
}

control& control::context_menu(std::nullptr_t) {
  if (data_->context_menu.has_value()) {
    data_->context_menu.reset();
    if (is_handle_created()) native::control::context_menu(handle(), 0, xtd::drawing::point::empty);
  }
  return *this;
}

forms::control_appearance control::control_appearance() const {
  return data_->control_appearance;
}

control& control::control_appearance(forms::control_appearance value) {
  if (data_->control_appearance != value) {
    data_->control_appearance = value;
    post_recreate_handle();
  }
  return *this;
}

control::control_collection& control::controls() {
  return data_->controls;
}

const control::control_collection& control::controls() const {
  return data_->controls;
}

bool control::created() {
  return get_state(state::created);
}

forms::cursor control::cursor() const {
  for (const control* control = this; control; control = control->parent().has_value() ? &control->parent().value().get() : nullptr)
    if (control->data_->cursor.has_value()) return control->data_->cursor.value();
  return default_cursor();
}

control& control::cursor(const forms::cursor& cursor) {
  if (data_->cursor != cursor) {
    data_->cursor = cursor;
    if (is_handle_created()) native::control::cursor(handle(), data_->cursor.value().handle());
    for (auto& control : controls())
      if (control.get().data_->parent) control.get().on_parent_cursor_changed(event_args::empty);
    on_cursor_changed(event_args::empty);
  }
  return *this;
}

control& control::cursor(std::nullptr_t) {
  if (data_->cursor.has_value()) {
    data_->cursor.reset();
    post_recreate_handle();
    for (auto& control : controls())
      if (control.get().data_->parent) control.get().on_parent_cursor_changed(event_args::empty);
    on_cursor_changed(event_args::empty);
  }
  return *this;
}

drawing::font control::default_font() const {
  return system_fonts::default_font();
}

drawing::size control::default_size() const {
  return native::control::default_size(create_params().class_name());
}

drawing::rectangle control::display_rectangle() const {
  return data_->client_rectangle;
}

dock_style control::dock() const {
  return data_->dock;
}

control& control::dock(dock_style dock) {
  if (data_->dock != dock) {
    data_->dock = dock;
    set_state(state::docked, true);
    on_dock_changed(event_args::empty);
  }
  return *this;
}

bool control::double_buffered() const {
  return get_state(state::double_buffered);
}

control& control::double_buffered(bool double_buffered) {
  set_state(state::double_buffered, double_buffered);
  return *this;
}

bool control::enabled() const {
  return get_state(state::enabled);
}

control& control::enabled(bool enabled) {
  if (get_state(state::enabled) != enabled) {
    set_state(state::enabled, enabled);
    if (is_handle_created()) native::control::enabled(handle(), get_state(state::enabled));
    for (auto& control : controls())
      if (control.get().data_->parent) control.get().on_parent_enabled_changed(event_args::empty);
    on_enabled_changed(event_args::empty);
  }
  return *this;
}

bool control::focused() const {
  return data_->focused;
}

drawing::font control::font() const {
  for (const control* control = this; control; control = control->parent().has_value() ? &control->parent().value().get() : nullptr)
    if (control->data_->font.has_value()) return control->data_->font.value();
  return default_font();
}

control& control::font(const drawing::font& font) {
  if (data_->font != font) {
    data_->font = font;
    if (is_handle_created()) native::control::font(handle(), data_->font.value());
    for (auto& control : controls())
      if (control.get().data_->parent) control.get().on_parent_font_changed(event_args::empty);
    on_font_changed(event_args::empty);
  }
  return *this;
}

control& control::font(std::nullptr_t) {
  if (data_->font.has_value()) {
    data_->font.reset();
    post_recreate_handle();
    for (auto& control : controls())
      if (control.get().data_->parent) control.get().on_parent_font_changed(event_args::empty);
    on_font_changed(event_args::empty);
  }
  return *this;
}

color control::fore_color() const {
  for (const control* control = this; control; control = control->parent().has_value() ? &control->parent().value().get() : nullptr)
    if (control->data_->fore_color.has_value()) return control->data_->fore_color.value();
  return default_fore_color();
}

control& control::fore_color(const color& color) {
  if (!data_->fore_color.has_value() || data_->fore_color != color) {
    data_->fore_color = color;
    if (is_handle_created()) native::control::fore_color(handle(), data_->fore_color.value());
    for (auto& control : controls())
      if (control.get().data_->parent) control.get().on_parent_fore_color_changed(event_args::empty);
    on_fore_color_changed(event_args::empty);
  }
  return *this;
}

control& control::fore_color(std::nullptr_t) {
  if (data_->fore_color.has_value()) {
    data_->fore_color.reset();
    post_recreate_handle();
    for (auto& control : controls())
      if (control.get().data_->parent) control.get().on_parent_fore_color_changed(event_args::empty);
    on_fore_color_changed(event_args::empty);
  }
  return *this;
}

int32_t control::height() const {return size().height();}

control& control::height(int32_t height) {
  if (size().height() != height)
    set_bounds_core(0, 0, 0, height, bounds_specified::height);
  return *this;
}

intptr_t control::handle() const {
  if (check_for_illegal_cross_thread_calls() && invoke_required())
    throw invalid_operation_exception(ustring::format("Cross-thread operation not valid: {}"_t, to_string()), csf_);
  return data_->handle;
}

bool control::invoke_required() const {
  return handle_created_on_thread_id_ != this_thread::get_id();
}

bool control::is_handle_created() const {
  return data_->handle != 0;
}

int32_t control::left() const {
  return data_->location.x();
}

control& control::left(int32_t left) {
  if (data_->location.x() != left)
    set_bounds_core(left, 0, 0, 0, bounds_specified::x);
  return *this;
}

drawing::point control::location() const {
  return data_->location;
}

control& control::location(const drawing::point& location) {
  if (data_->location != location)
    set_bounds_core(location.x(), location.y(), 0, 0, bounds_specified::location);
  return *this;
}

forms::padding control::margin() const {
  return data_->margin;
}

control& control::margin(const forms::padding& margin) {
  data_->margin = margin;
  return *this;
}

const drawing::size& control::maximum_client_size() const {
  return data_->maximum_client_size;
}

control& control::maximum_client_size(const drawing::size& size) {
  if (data_->maximum_client_size != size) {
    data_->maximum_client_size = size;
    client_size({this->size().width() > maximum_client_size().width() ? data_->maximum_client_size.width() : client_size().width(), this->size().height() > maximum_client_size().height() ? maximum_client_size().height() : client_size().height()});
    if (handle()) native::control::maximum_client_size(handle(), data_->maximum_client_size);
  }
  return *this;
}

const drawing::size& control::maximum_size() const {
  return data_->maximum_size;
}

control& control::maximum_size(const drawing::size& size) {
  if (data_->maximum_size != size) {
    data_->maximum_size = size;
    this->size({this->size().width() > maximum_size().width() ? maximum_size().width() : this->size().width(), this->size().height() > maximum_size().height() ? maximum_size().height() : this->size().height()});
    if (handle()) native::control::maximum_size(handle(), data_->maximum_size);
  }
  return *this;
}

const drawing::size& control::minimum_client_size() const {
  return data_->minimum_client_size;
}

control& control::minimum_client_size(const drawing::size& size) {
  if (data_->minimum_client_size != size) {
    data_->minimum_client_size = size;
    client_size({this->size().width() < minimum_client_size().width() ? minimum_client_size().width() : client_size().width(), this->size().height() < minimum_client_size().height() ? minimum_client_size().height() : client_size().height()});
    if (handle()) native::control::minimum_client_size(handle(), data_->minimum_client_size);
  }
  return *this;
}

const drawing::size& control::minimum_size() const {
  return data_->minimum_size;
}

control& control::minimum_size(const drawing::size& size) {
  if (data_->minimum_size != size) {
    data_->minimum_size = size;
    this->size({this->size().width() < minimum_size().width() ? minimum_size().width() : this->size().width(), this->size().height() < minimum_size().height() ? minimum_size().height() : this->size().height()});
    if (handle()) native::control::minimum_size(handle(), data_->minimum_size);
  }
  return *this;
}

forms::keys control::modifier_keys() {
  return modifier_keys_;
}

forms::mouse_buttons control::mouse_buttons() {
  return mouse_buttons_;
}

xtd::drawing::point control::mouse_position() {
  return xtd::forms::cursor::position();
}

const xtd::ustring& control::name() const {
  return data_->name;
}

control& control::name(const xtd::ustring& name) {
  data_->name = name;
  return*this;
}

intptr_t control::native_handle() const {
  return native::control::native_handle(handle());
}

forms::padding control::padding() const {
  return data_->padding;
}

control& control::padding(const forms::padding& padding) {
  data_->padding = padding;
  return *this;
}

std::optional<control_ref> control::parent() const {
  return from_handle(data_->parent);
}

control& control::parent(const control& parent) {
  if (parent.data_->handle != data_->parent) {
    if (this->parent().has_value())
      this->parent(nullptr);
    else {
      set_state(control::state::created, false);
      on_parent_changed(event_args::empty);
    }
    if (parent.handle()) const_cast<control&>(parent).data_->controls.push_back(*this);
  } else if (parent.data_->handle == 0)
    const_cast<control&>(parent).data_->controls.push_back(*this);
  return *this;
}

control& control::parent(std::nullptr_t) {
  if (parent().has_value()) {
    on_parent_changed(event_args::empty);
    for (size_t index = 0; index < parent().value().get().data_->controls.size(); index++) {
      if (parent().value().get().data_->controls[index].get().handle() == handle()) {
        auto prev_parent = parent();
        parent().value().get().data_->controls.erase_at(index);
        if (!get_state(state::destroying) && !prev_parent.value().get().get_state(state::destroying)) prev_parent.value().get().refresh();
        break;
      }
    }
  }
  return *this;
}

xtd::ustring control::product_name() const {
  return "xtd";
}

bool control::recreating_handle() const {
  return get_state(state::recreate);
}

const xtd::drawing::region& control::region() const {
  return data_->region;
}

control& control::region(const xtd::drawing::region& value) {
  if (value != data_->region) {
    data_->region = value;
    on_region_changed(event_args::empty);
  }
  return *this;
}

int32_t control::right() const {
  return left() + width();
}

drawing::size control::size() const {
  return data_->size.value_or(default_size());
}

control& control::size(const drawing::size& size) {
  if (get_state(state::client_size_setted) || this->size() != size) {
    set_state(state::client_size_setted, false);
    set_bounds_core(0, 0, size.width(), size.height(), bounds_specified::size);
  }
  return *this;
}

style_sheets::style_sheet control::style_sheet() const {
  return data_->style_sheet;
}

control& control::style_sheet(const style_sheets::style_sheet& value) {
  data_->style_sheet = value;
  if (data_->style_sheet.data_->theme.name().empty()) data_->style_sheet.data_->theme.name("-- user style sheet --");
  return *this;
}

control& control::style_sheet(const ustring& value) {
  return style_sheet(style_sheets::style_sheet(value));
}

bool control::tab_stop() const {
  return get_state(control::state::tab_stop);
}

control& control::tab_stop(bool value) {
  if (get_state(control::state::tab_stop) != value) {
    set_state(control::state::tab_stop, value);
    on_tab_stop_changed(event_args::empty);
  }
  return *this;
}

std::any control::tag() const {
  return data_->tag;
}

control& control::tag(std::any tag) {
  data_->tag = tag;
  return*this;
}

const xtd::ustring& control::text() const {
  return data_->text;
}

control& control::text(const ustring& text) {
  if (data_->text != text) {
    data_->text = text;
    if (is_handle_created()) native::control::text(handle(), data_->text);
    on_text_changed(event_args::empty);
  }
  return *this;
}

intptr_t control::toolkit_handle() const {
  return native::control::toolkit_handle(handle());
}

int32_t control::top() const {
  return data_->location.y();
}

control& control::top(int32_t top) {
  if (data_->location.y() != top)
    set_bounds_core(0, top, 0, 0, bounds_specified::y);
  return *this;
}

optional<reference_wrapper<control>> control::top_level_control() const {
  optional<reference_wrapper<control>> top_level_control = const_cast<control&>(*this);
  while (top_level_control.has_value() && !top_level_control.value().get().get_state(state::top_level))
    top_level_control = top_level_control.value().get().parent();
  if (top_level_control.has_value() && !top_level_control.value().get().get_state(state::top_level)) top_level_control.reset();
  return top_level_control;
}

bool control::visible() const {
  return get_state(state::visible);
}

control& control::visible(bool visible) {
  if (get_state(state::visible) != visible) {
    set_state(state::visible, visible);
    if (is_handle_created()) native::control::visible(handle(), get_state(state::visible));
    on_visible_changed(event_args::empty);
  }
  return *this;
}

int32_t control::width() const {
  return size().width();
}

control& control::width(int32_t width) {
  if (size().width() != width)
    set_bounds_core(0, 0, width, 0, bounds_specified::width);
  return *this;
}

std::shared_ptr<xtd::iasync_result> control::begin_invoke(delegate<void()> value) {
  return begin_invoke(delegate<void(std::vector<std::any>)>(value), {});
}

shared_ptr<iasync_result> control::begin_invoke(delegate<void(vector<any>)> value, const vector<any>& args) {
  while (!xtd::forms::application::message_loop()) this_thread::sleep_for(10ms);
  shared_ptr<async_result_invoke> async = make_shared<async_result_invoke>(std::reference_wrapper(*this));
  async->async_mutex().lock();
  if (is_handle_created()) native::control::invoke_in_control_thread(data_->handle, value, args, async->async_mutex_, async->is_completed_);
  this_thread::yield();
  return async;
}

void control::bring_to_front() {
  focus();
}

void control::create_control() {
  if (!get_state(state::destroying) && !get_state(state::creating) && !get_state(state::created)) {
    set_state(state::destroyed, false);
    set_state(state::creating, true);
    create_handle();
    send_message(handle(), WM_CREATE, 0, handle());
    set_state(state::creating, false);
    set_state(state::created, true);
  }
}

void control::destroy_control() {
  if (get_state(state::created)) {
    set_state(state::created, false);
    set_state(state::destroying, true);
    if (is_handle_created()) {
      if (parent().has_value() && !parent().value().get().get_state(state::destroying)) {
        auto parent_prev = parent();
        parent_prev.value().get().suspend_layout();
        parent(nullptr);
        parent_prev.value().get().resume_layout(false);
      } else {
        for (size_t index = 0; index < top_level_controls_.size(); index++) {
          if (top_level_controls_[index].get().handle() == handle()) {
            top_level_controls_.erase_at(index);
            break;
          }
        }
      }
      destroy_handle();
    }
    set_state(state::destroying, false);
    set_state(state::destroyed, true);
  }
}

graphics control::create_graphics() const {
  if (!is_handle_created())
    throw invalid_operation_exception(csf_);
  return graphics(native::control::create_graphics(handle()));
}

void control::create_handle() {
  set_state(state::creating_handle, true);
  auto params = create_params();
  if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::creation), ustring::format("create handle {} with params {}", *this, params));
  data_->handle = native::control::create(params);
  suspend_layout();
  handles_[handle()] = this;
  native::control::register_wnd_proc(handle(), {*this, &control::wnd_proc_});
  for (auto child : data_->controls) {
    child.get().data_->parent = handle();
    child.get().create_handle();
  }
  on_handle_created(event_args::empty);
  set_state(state::creating_handle, false);
  resume_layout();
}

void control::destroy_handle() {
  if (!is_handle_created()) return;
  native::control::unregister_wnd_proc(handle());
  suspend_layout();
  for (auto child : data_->controls)
    child.get().destroy_handle();
  handles_.erase(handle());
  on_handle_destroyed(event_args::empty);
  native::control::destroy(handle());
  data_->handle = 0;
}

bool control::focus() {
  if (!is_handle_created() || !data_->can_focus) return false;
  native::control::focus(handle());
  data_->focused = true;
  return true;
}

optional<reference_wrapper<control>> control::from_child_handle(intptr_t handle) {
  try {
    auto it = handles_.find(handle);
    if (it != handles_.end())
      return it->second->parent();
    return optional<reference_wrapper<control>>();
  } catch (...) {
    return optional<reference_wrapper<control>>();
  }
}

optional<reference_wrapper<control>> control::from_handle(intptr_t handle) {
  try {
    auto it = handles_.find(handle);
    if (it != handles_.end())
      return *it->second;
    return optional<reference_wrapper<control>>();
  } catch (...) {
    return optional<reference_wrapper<control>>();
  }
}

forms::auto_size_mode control::get_auto_size_mode() const {
  return data_->auto_size_mode;
}

size_t control::get_child_index(intptr_t child) const {
  for (size_t index = 0; index < controls().size(); ++index)
    if (controls()[index].get().handle() == child) return index;
  throw xtd::argument_exception(current_stack_frame_);
}

size_t control::get_child_index(intptr_t child, bool& throw_exception) const {
  throw_exception = false;
  try {
    return get_child_index(child);
  } catch (...) {
    throw_exception = true;
    return control_collection::npos;
  }
}

void control::hide() {
  visible(false);
}

void control::invalidate() const {
  invalidate(drawing::rectangle({ 0, 0 }, client_size()), false);
}

void control::invalidate(bool invalidate_children) const {
  invalidate(drawing::rectangle({ 0, 0 }, client_size()), invalidate_children);
}

void control::invalidate(const drawing::rectangle& rect) const {
  invalidate(rect, false);
}

void control::invalidate(const drawing::rectangle& rect, bool invalidate_children) const {
  if (invalidate_children)
    for (auto child : data_->controls)
      child.get().invalidate(rect, invalidate_children);
  if (is_handle_created()) native::control::invalidate(handle(), rect, true);
}

void control::invoke(delegate<void()> value) {
  invoke(delegate<void(std::vector<std::any>)>(value), std::vector<std::any> {});
}

void control::invoke(delegate<void(std::vector<std::any>)> value, const std::vector<std::any>& args) {
  end_invoke(begin_invoke(value, args));
}

void control::invoke(delegate<void(std::vector<std::any>)> value, std::any arg) {
  end_invoke(begin_invoke(value, std::vector<std::any> {arg}));
}

void control::end_invoke(shared_ptr<iasync_result> async) {
  lock_guard<shared_mutex> lock(async->async_mutex());
}

forms::create_params control::create_params() const {
  forms::create_params create_params;
  
  create_params.caption(data_->text);
  create_params.style(WS_VISIBLE | WS_CHILD);
  if (get_state(control::state::tab_stop)) create_params.style(WS_TABSTOP);
  if (parent().has_value()) create_params.parent(parent().value().get().handle());
  create_params.location(data_->location);
  //create_params.size(size());
  create_params.size({0, 0});
  
  return create_params;
}
bool control::get_state(control::state flag) const {
  return ((int32_t)data_->state & (int32_t)flag) == (int32_t)flag;
}

bool control::get_style(control_styles flag) const {
  return ((int32_t)data_->style & (int32_t)flag) == (int32_t)flag;
}

drawing::size control::measure_control() const {
  return data_->client_size;
}

drawing::size control::measure_text() const {
  return drawing::size::ceiling(screen::create_graphics().measure_string(data_->text, font())) + drawing::size(2, 1);
}

void control::on_auto_size_changed(const event_args& e) {
  perform_layout();
  if (can_raise_events()) auto_size_changed(*this, e);
}

void control::on_back_color_changed(const event_args& e) {
  refresh();
  if (can_raise_events()) back_color_changed(*this, e);
}

void control::on_background_image_changed(const event_args& e) {
  refresh();
  if (can_raise_events()) background_image_changed(*this, e);
}

void control::on_background_image_layout_changed(const event_args& e) {
  refresh();
  if (can_raise_events()) background_image_layout_changed(*this, e);
}

void control::on_create_control() {
  if (!parent().has_value())
    top_level_controls_.push_back(control_ref(*this));
  for (auto control : data_->controls) {
    control.get().data_->parent = handle();
    control.get().create_control();
  }
  perform_layout();
}

void control::on_click(const event_args& e) {
  if (can_raise_events()) click(*this, e);
}

void control::on_client_size_changed(const event_args& e) {
  if (can_raise_events()) client_size_changed(*this, e);
}

void control::on_control_added(const control_event_args& e) {
  perform_layout();
  size_changed += {e.control(), &control::on_parent_size_changed};
  if (can_raise_events()) control_added(*this, e);
}

void control::on_control_removed(const control_event_args& e) {
  perform_layout();
  size_changed -= {e.control(), &control::on_parent_size_changed};
  if (can_raise_events()) control_removed(*this, e);
}

void control::on_cursor_changed(const event_args& e) {
  if (can_raise_events()) cursor_changed(*this, e);
}

void control::on_dock_changed(const event_args& e) {
  if (parent().has_value()) parent().value().get().perform_layout();
  perform_layout();
  if (can_raise_events()) dock_changed(*this, e);
}

void control::on_double_click(const event_args& e) {
  if (can_raise_events()) double_click(*this, e);
}

void control::on_enabled_changed(const event_args& e) {
  if (is_handle_created()) set_state(state::enabled, native::control::enabled(handle()));
  if (control_appearance() == xtd::forms::control_appearance::standard) data_->control_state = enabled() ? xtd::forms::visual_styles::control_state::normal : xtd::forms::visual_styles::control_state::disabled;
  refresh();
  if (can_raise_events()) enabled_changed(*this, e);
}

void control::on_fore_color_changed(const event_args& e) {
  refresh();
  if (can_raise_events()) fore_color_changed(*this, e);
}

void control::on_font_changed(const event_args& e) {
  if (parent().has_value() && parent().value().get().auto_size()) parent().value().get().perform_layout();
  perform_layout();
  if (can_raise_events()) font_changed(*this, e);
}

void control::on_got_focus(const event_args& e) {
  if (can_raise_events()) got_focus(*this, e);
}

void control::on_handle_created(const event_args& e) {
  if (get_state(state::client_size_setted)) {
    native::control::maximum_client_size(handle(), maximum_client_size());
    native::control::minimum_client_size(handle(), minimum_client_size());
    native::control::client_size(handle(), client_size());
  } else {
    native::control::maximum_size(handle(), maximum_size());
    native::control::minimum_size(handle(), minimum_size());
    native::control::size(handle(), this->size());
  }
  if (data_->back_color.has_value() || back_color() != default_back_color()) native::control::back_color(handle(), back_color());
  if (data_->cursor.has_value() || cursor() != default_cursor()) native::control::cursor(handle(), cursor().handle());
  if (data_->fore_color.has_value() || fore_color() != default_fore_color()) native::control::fore_color(handle(), fore_color());
  if (data_->font.has_value() || font() != default_font()) native::control::font(handle(), font());
  native::control::enabled(handle(), enabled());
  native::control::visible(handle(), visible());
  if (focused()) native::control::focus(handle());
  
  data_->client_rectangle = native::control::client_rectangle(handle());
  data_->client_size = native::control::client_size(handle());
  data_->location = native::control::location(handle());
  data_->size = native::control::size(handle());
  
  if (parent().has_value()) data_->anchoring = {left(), location().y(), parent().value().get().client_size().width() - width() - left(), parent().value().get().client_size().height() - height() - top()};
  
  if (can_raise_events()) handle_created(*this, e);
  
  if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::creation), ustring::format("on handle created control={}, location={}, size={}, client_size={}", *this, location(), this->size(), client_size()));
  
  if (!get_state(control::state::recreate) && parent().has_value()) parent().value().get().perform_layout();
  if (!get_state(control::state::recreate)) perform_layout();
}

void control::on_handle_destroyed(const event_args& e) {
  if (can_raise_events()) handle_destroyed(*this, e);
}

void control::on_help_requested(help_event_args &e) {
  if (can_raise_events()) help_requested(*this, e);
}

void control::on_key_down(key_event_args& e) {
  if (can_raise_events()) key_down(*this, e);
}

void control::on_key_press(key_press_event_args& e) {
  if (can_raise_events()) key_press(*this, e);
}

void control::on_key_up(key_event_args& e) {
  if (can_raise_events()) key_up(*this, e);
}

void control::on_layout(const event_args& e) {
  do_layout_with_anchor_styles();
  do_layout_with_auto_size_mode();
  do_layout_children_with_dock_style();
  if (can_raise_events()) layout(*this, e);
}

void control::on_location_changed(const event_args& e) {
  if (parent().has_value() && parent().value().get().auto_size()) parent().value().get().perform_layout();
  if (can_raise_events()) location_changed(*this, e);
}

void control::on_lost_focus(const event_args& e) {
  if (can_raise_events()) lost_focus(*this, e);
}

void control::on_mouse_click(const mouse_event_args& e) {
  if (can_raise_events()) mouse_click(*this, e);
}

void control::on_mouse_double_click(const mouse_event_args& e) {
  if (can_raise_events()) mouse_double_click(*this, e);
}

void control::on_mouse_down(const mouse_event_args& e) {
  if (mouse_buttons_ == forms::mouse_buttons::right && data_->context_menu.has_value())
    native::control::context_menu(handle(), data_->context_menu.value().get().handle(), e.location());
  if (control_appearance() == xtd::forms::control_appearance::standard && enabled()) {
    data_->control_state = xtd::forms::visual_styles::control_state::pressed;
    //invalidate();
  }
  if (can_raise_events()) mouse_down(*this, e);
}

void control::on_mouse_horizontal_wheel(const mouse_event_args& e) {
  if (can_raise_events()) mouse_horizontal_wheel(*this, e);
}

void control::on_mouse_enter(const event_args& e) {
  if (control_appearance() == xtd::forms::control_appearance::standard && enabled()) {
    data_->control_state = (mouse_buttons() & mouse_buttons::left) == mouse_buttons::left ? xtd::forms::visual_styles::control_state::pressed : xtd::forms::visual_styles::control_state::hot;
    //invalidate();
  }
  if (can_raise_events()) mouse_enter(*this, e);
}

void control::on_mouse_leave(const event_args& e) {
  if (control_appearance() == xtd::forms::control_appearance::standard && enabled()) {
    data_->control_state = xtd::forms::visual_styles::control_state::normal;
    //invalidate();
  }
  if (can_raise_events()) mouse_leave(*this, e);
}

void control::on_mouse_move(const mouse_event_args& e) {
  if (can_raise_events()) mouse_move(*this, e);
}

void control::on_mouse_up(const mouse_event_args& e) {
  if (control_appearance() == xtd::forms::control_appearance::standard && enabled() && data_->control_state == xtd::forms::visual_styles::control_state::pressed) {
    data_->control_state = xtd::forms::visual_styles::control_state::hot;
    //invalidate();
  }
  if (can_raise_events()) mouse_up(*this, e);
}

void control::on_mouse_wheel(const mouse_event_args& e) {
  if (can_raise_events()) mouse_wheel(*this, e);
}

void control::on_paint(paint_event_args& e) {
  def_wnd_proc(e.message_);
  if (data_->background_image != xtd::drawing::image::empty) control_paint::draw_image(e.graphics(), data_->background_image, e.clip_rectangle(), data_->background_image_layout);
  if (can_raise_events()) paint(*this, e);
}

void control::on_paint_background(paint_event_args& e) {
  def_wnd_proc(e.message_);
}

void control::on_parent_back_color_changed(const event_args& e) {
  if (!data_->back_color.has_value() || (parent().has_value() && parent().value().get().back_color() != data_->back_color.value())) {
    if (!parent().value().get().data_->back_color.has_value()) post_recreate_handle();
    else if (is_handle_created()) native::control::back_color(handle(), parent().value().get().back_color());
    for (auto control : controls())
      control.get().on_parent_back_color_changed(event_args::empty);
  }
}

void control::on_parent_changed(const event_args& e) {
  if (!get_state(state::destroying) && parent().has_value() && !parent().value().get().get_state(state::destroying)) perform_layout();
  if (can_raise_events()) parent_changed(*this, e);
}

void control::on_parent_cursor_changed(const event_args& e) {
  if (!data_->cursor.has_value() || (parent().has_value() && parent().value().get().cursor() != data_->cursor.value())) {
    if (!parent().value().get().data_->cursor.has_value()) post_recreate_handle();
    else if (is_handle_created()) native::control::cursor(handle(), parent().value().get().cursor().handle());
    for (auto control : controls())
      control.get().on_parent_back_color_changed(event_args::empty);
  }
}

void control::on_parent_enabled_changed(const event_args& e) {
  if (parent().has_value()) {
    set_state(state::enabled, parent().value().get().enabled());
    if (is_handle_created()) native::control::enabled(handle(), get_state(state::enabled));
    for (auto control : controls())
      control.get().on_parent_enabled_changed(event_args::empty);
  }
}

void control::on_parent_fore_color_changed(const event_args& e) {
  if (!data_->fore_color.has_value() || (parent().has_value() && parent().value().get().fore_color() != data_->fore_color.value())) {
    if (!parent().value().get().data_->fore_color.has_value()) post_recreate_handle();
    else if (is_handle_created()) native::control::fore_color(handle(), parent().value().get().fore_color());
    for (auto control : controls())
      control.get().on_parent_fore_color_changed(event_args::empty);
  }
}

void control::on_parent_font_changed(const event_args& e) {
  if (!data_->font.has_value() || (parent().has_value() && parent().value().get().font() != font())) {
    if (!parent().value().get().data_->font.has_value()) post_recreate_handle();
    else if (is_handle_created()) native::control::font(handle(), parent().value().get().font());
    for (auto control : controls())
      control.get().on_parent_font_changed(event_args::empty);
  }
}

void control::on_region_changed(const event_args& e) {
  if (can_raise_events()) region_changed(*this, e);
}

void control::on_resize(const event_args& e) {
  if (is_handle_created()) data_->client_rectangle = native::control::client_rectangle(handle());
  if (parent().has_value() && parent().value().get().auto_size()) parent().value().get().perform_layout();
  perform_layout();
  invalidate();
  if (can_raise_events()) resize(*this, e);
}

void control::on_size_changed(const event_args& e) {
  if (is_handle_created()) data_->client_rectangle = native::control::client_rectangle(handle());
  if (can_raise_events()) size_changed(*this, e);
}

void control::on_tab_stop_changed(const event_args& e) {
  post_recreate_handle();
  if (can_raise_events()) tab_stop_changed(*this, e);
}

void control::on_text_changed(const event_args& e) {
  if (parent().has_value() && parent().value().get().auto_size()) parent().value().get().perform_layout();
  perform_layout();
  if (can_raise_events()) text_changed(*this, e);
}

void control::on_visible_changed(const event_args& e) {
  if (is_handle_created()) set_state(state::visible, native::control::visible(handle()));
  if (focused())
    focus();
  for (auto item : data_->controls)
    if (item.get().focused()) item.get().focus();
  if (parent().has_value() && parent().value().get().auto_size()) parent().value().get().perform_layout();
  if (can_raise_events()) visible_changed(*this, e);
}

void control::perform_layout() {
  if (get_state(state::layout_deferred) || reentrant_layout::is_reentrant(this)) return;
  reentrant_layout reentrant_laout(this);
  on_layout(event_args::empty);
}

drawing::point control::point_to_client(const xtd::drawing::point& p) const {
  return is_handle_created() ? native::control::point_to_client(handle(), p) : drawing::point {};
}

drawing::point control::point_to_screen(const xtd::drawing::point& p) const {
  return is_handle_created() ? native::control::point_to_screen(handle(), p) : drawing::point {};
}

bool control::pre_process_message(xtd::forms::message& message) {
  bool message_processed = false;
  for (auto child : controls()) {
    message_processed = child.get().pre_process_message(message);
    if (message_processed) break;
  }
  return message_processed;
}

void control::resume_layout() {
  resume_layout(true);
}

void control::resume_layout(bool perform_layout) {
  set_state(state::layout_deferred, false);
  native::control::resume_layout(handle());
  if (perform_layout) this->perform_layout();
}

void control::refresh() const {
  invalidate(true);
  update();
}

intptr_t control::send_message(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam) const {
  return is_handle_created() ? native::control::send_message(handle(), hwnd, msg, wparam, lparam) : static_cast<intptr_t>(-1);
}

void control::set_auto_size_mode(forms::auto_size_mode value) {
  if (data_->auto_size_mode != value) {
    data_->auto_size_mode = value;
    perform_layout();
  }
}

void control::set_bounds(int32_t x, int32_t y, int32_t width, int32_t height) {
  set_bounds(x, y, width, height, bounds_specified::all);
}

void control::set_bounds(int32_t x, int32_t y, int32_t width, int32_t height, bounds_specified specified) {
  set_bounds_core(x, y, width, height, specified);
}

void control::set_state(control::state flag, bool value) {
  data_->state = value ? (control::state)((int32_t)data_->state | (int32_t)flag) : (control::state)((int32_t)data_->state & ~(int32_t)flag);
}

void control::set_can_focus(bool value) {
  data_->can_focus = value;
}

void control::set_text(const xtd::ustring& text) {
  data_->text = text;
}

void control::set_mouse_buttons(forms::mouse_buttons value) {
  mouse_buttons_ = value;
}

void control::set_parent(intptr_t handle) {
  data_->parent = handle;
}

void control::set_style(control_styles flag, bool value) {
  data_->style = value ? (control_styles)((int32_t)data_->style | (int32_t)flag) : (control_styles)((int32_t)data_->style & ~(int32_t)flag);
}

void control::show() {
  visible(true);
}

void control::suspend_layout() {
  set_state(state::layout_deferred, true);
  native::control::suspend_layout(handle());
}

ustring control::to_string() const noexcept {
  if (!data_->name.empty()) return ustring::format("{}, name: {}", ustring::full_class_name(*this), data_->name);
  if (!data_->text.empty()) return ustring::format("{}, text: {}", ustring::full_class_name(*this), data_->text);
  return ustring::full_class_name(*this);
}

void control::update() const {
  if (is_handle_created()) native::control::update(handle());
}

intptr_t control::wnd_proc_(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
  //try {
  message message = forms::message::create(hwnd, msg, wparam, lparam, 0, handle);
  wnd_proc(message);
  return message.result();
  /*
  } catch(const exception& e) {
    message_box::show(from_handle(hwnd).value(), xtd::ustring::format("message: {}", e.what()), xtd::ustring::format("Exception {}", xtd::ustring::class_name(e)), message_box_buttons::ok, message_box_icon::error);
  } catch(...) {
    message_box::show(from_handle(hwnd).value(), "message: An unknown exception occur", "Unknown Exception", message_box_buttons::ok, message_box_icon::error);
  }
  return 0;
   */
}

bool control::on_context_menu_item_click(xtd::forms::context_menu& menu, intptr_t menu_id) const {
  return menu.on_item_click(menu_id);
}

void control::show_context_menu(xtd::forms::context_menu& menu, const xtd::drawing::point& pos) const {
  on_context_menu_item_click(menu, native::control::user_context_menu(handle(), menu.handle(), pos));
}

void control::wnd_proc(message& message) {
  if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::events), ustring::format("({}) receive message [{}]", *this, message));
  switch (message.msg()) {
    // keyboard:
    case WM_CREATE: wm_create(message); break;
    case WM_CHAR:
    case WM_KEYDOWN:
    case WM_KEYUP:
    case WM_SYSCHAR:
    case WM_SYSKEYDOWN:
    case WM_SYSKEYUP: wm_key_char(message); break;
    // mouse events
    case WM_LBUTTONDOWN:
    case WM_MBUTTONDOWN:
    case WM_RBUTTONDOWN:
    case WM_XBUTTONDOWN: wm_mouse_down(message); break;
    case WM_LBUTTONUP:
    case WM_MBUTTONUP:
    case WM_RBUTTONUP:
    case WM_XBUTTONUP: wm_mouse_up(message); break;
    case WM_LBUTTONDBLCLK:
    case WM_MBUTTONDBLCLK:
    case WM_RBUTTONDBLCLK:
    case WM_XBUTTONDBLCLK: wm_mouse_double_click(message); break;
    case WM_MOUSEMOVE: wm_mouse_move(message); break;
    case WM_MOUSEENTER: wm_mouse_enter(message); break;
    case WM_MOUSELEAVE: wm_mouse_leave(message); break;
    case WM_CHILDACTIVATE: wm_child_activate(message); break;
    case WM_SETFOCUS: wm_set_focus(message); break;
    case WM_KILLFOCUS: wm_kill_focus(message); break;
    case WM_MOUSEHWHEEL:
    case WM_MOUSEWHEEL: wm_mouse_wheel(message); break;
    // System events
    case WM_COMMAND: wm_command(message); break;
    case WM_ERASEBKGND: wm_erase_background(message); break;
    case WM_HELP: wm_help(message); break;
    case WM_PAINT: wm_paint(message); break;
    case WM_MENUCOMMAND: wm_menu_command(message); break;
    case WM_MOVE: wm_move(message);  break;
    case WM_NOTIFY: wm_notify(message);  break;
    case WM_SETTEXT: wm_set_text(message); break;
    case WM_SHOWWINDOW: wm_show(message); break;
    case WM_SIZE: wm_size(message); break;
    case WM_SIZING: wm_sizing(message); break;
    case WM_HSCROLL:
    case WM_VSCROLL: wm_scroll(message); break;
    case WM_ENTERIDLE: wm_enter_idle(message); break;
    default: def_wnd_proc(message); break;
  }
}

void control::def_wnd_proc(message& message) {
  if (is_handle_created() && message.handle()) message.result(native::control::def_wnd_proc(handle(), message.hwnd(), message.msg(), message.wparam(), message.lparam(), message.result(), message.handle()));
}

void control::recreate_handle() {
  if (is_handle_created()) {
    set_state(state::recreate, true);
    for (auto control : controls()) 
      control.get().set_state(state::parent_recreating, true);
    
    destroy_handle();
    create_handle();
    
    for (auto control : controls()) 
      control.get().set_state(state::parent_recreating, false);
    set_state(state::recreate, false);
    data_->recreate_handle_posted = false;

    perform_layout();
  }
}

void control::set_bounds_core(int32_t x, int32_t y, int32_t width, int32_t height, bounds_specified specified) {
  if ((specified & bounds_specified::x) == bounds_specified::x) data_->location.x(x);
  if ((specified & bounds_specified::y) == bounds_specified::y) data_->location.y(y);
  if ((specified & bounds_specified::width) == bounds_specified::width) {
    if (!data_->size.has_value()) data_->size = default_size();
    data_->size.value().width(width);
  }
  if ((specified & bounds_specified::height) == bounds_specified::height) {
    if (!data_->size.has_value()) data_->size = default_size();
    data_->size.value().height(height);
  }
  
  if ((specified & bounds_specified::x) == bounds_specified::x || (specified & bounds_specified::y) == bounds_specified::y) {
    if (is_handle_created()) native::control::location(handle(), location());
    on_location_changed(event_args::empty);
    if (parent().has_value()) parent().value().get().perform_layout();
    perform_layout();
  }
  
  if ((specified & bounds_specified::width) == bounds_specified::width || (specified & bounds_specified::height) == bounds_specified::height) {
    if (size().width() < minimum_size().width()) data_->size.value().width(minimum_size().width());
    if (size().height() < minimum_size().height()) data_->size.value().height(minimum_size().height());
    if (!maximum_size().is_empty() && size().width() > maximum_size().width()) data_->size.value().width(maximum_size().width());
    if (!maximum_size().is_empty() && size().height() > maximum_size().height()) data_->size.value().height(maximum_size().height());
    
    if (is_handle_created()) native::control::size(handle(), size());
    on_client_size_changed(event_args::empty);
    on_size_changed(event_args::empty);
    on_resize(event_args::empty);
  }
}

void control::set_client_size_core(int32_t width, int32_t height) {
  data_->client_size.width(width);
  data_->client_size.height(height);
  
  if (is_handle_created()) native::control::client_size(handle(), data_->client_size);
  on_client_size_changed(event_args::empty);
  on_size_changed(event_args::empty);
  on_resize(event_args::empty);
}

void control::on_parent_size_changed(object& sender, const event_args& e) {
  if (!get_state(state::layout_deferred) && !reentrant_layout::is_reentrant(this))
    perform_layout();
}

void control::post_recreate_handle() {
  if(data_->handle)
    data_->recreate_handle_posted = true;
}

void control::do_layout_children_with_dock_style() {
  bool docked = false;
  for (control_ref control : data_->controls) {
    docked = control.get().get_state(state::docked);
    if (docked) break;
  }
  
  if (docked) {
    drawing::rectangle docking_rect = {{0, 0}, client_size()};
    if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::layout), ustring::format("({}) do_layout :", *this));
    if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::indent();
    if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::layout), ustring::format("docking_rect = {}", docking_rect));
    if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::layout), ustring::format("padding = {}", data_->padding));
    docking_rect.x(docking_rect.left() + data_->padding.left());
    docking_rect.y(docking_rect.top() + data_->padding.top());
    docking_rect.width(docking_rect.width() - data_->padding.left() - data_->padding.right());
    docking_rect.height(docking_rect.height() - data_->padding.top() - data_->padding.bottom());
    for (control_collection::reverse_iterator iterator = data_->controls.rbegin(); iterator != data_->controls.rend(); ++iterator) {
      if (!iterator->get().visible()) continue;
      if (iterator->get().dock() == dock_style::top) {
        iterator->get().location({docking_rect.left(), docking_rect.top()});
        iterator->get().width(docking_rect.width());
        docking_rect.y(docking_rect.top() + iterator->get().height());
        docking_rect.height(docking_rect.height() - iterator->get().height());
        if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::layout), ustring::format("top ({}) = location = {}, size = {}", iterator->get().name(), iterator->get().location(), iterator->get().size()));
      } else if (iterator->get().dock() == dock_style::bottom) {
        iterator->get().location({docking_rect.left(), docking_rect.bottom() - iterator->get().height()});
        iterator->get().width(docking_rect.width());
        docking_rect.height(docking_rect.height() - iterator->get().height());
        if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::layout), ustring::format("bottom ({}) = location = {}, size = {}", iterator->get().name(), iterator->get().location(), iterator->get().size()));
      } else if (iterator->get().dock() == dock_style::left) {
        iterator->get().location({docking_rect.left(), docking_rect.top()});
        iterator->get().height(docking_rect.height());
        docking_rect.x(docking_rect.left() + iterator->get().width());
        docking_rect.width(docking_rect.width() - iterator->get().width());
        if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::layout), ustring::format("left ({}) = location = {}, size = {}", iterator->get().name(), iterator->get().location(), iterator->get().size()));
      } else if (iterator->get().dock() == dock_style::right) {
        iterator->get().location({docking_rect.right() - iterator->get().width(), docking_rect.top()});
        iterator->get().height(docking_rect.height());
        docking_rect.width(docking_rect.width() - iterator->get().width());
        if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::layout), ustring::format("right ({}) = location = {}, size = {}", iterator->get().name(), iterator->get().location(), iterator->get().size()));
      } else if (iterator->get().dock() == dock_style::fill) {
        iterator->get().location({docking_rect.left(), docking_rect.top()});
        iterator->get().size({docking_rect.width(), docking_rect.height()});
        if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::layout), ustring::format("fill ({}) = location = {}, size = {}", iterator->get().name(), iterator->get().location(), iterator->get().size()));
      }
    }
    if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::unindent();
    if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::layout), ustring::format("({}) end do_layout :", *this));
  }
}

void control::do_layout_with_anchor_styles() {
  if (parent().has_value()) {
    if ((data_->anchor & anchor_styles::left) == anchor_styles::left && (data_->anchor & anchor_styles::right) != anchor_styles::right)
      left(left());
    else if ((data_->anchor & anchor_styles::left) == anchor_styles::left && (data_->anchor & anchor_styles::right) == anchor_styles::right)
      width(parent().value().get().client_size().width() - data_->anchoring.right() - left());
    else if ((data_->anchor & anchor_styles::left) != anchor_styles::left && (data_->anchor & anchor_styles::right) == anchor_styles::right)
      left(parent().value().get().client_size().width() - width() - data_->anchoring.right());
    else
      left(parent().value().get().client_size().width() / 2 -  width() / 2);
      
    if ((data_->anchor & anchor_styles::top) == anchor_styles::top && (data_->anchor & anchor_styles::bottom) != anchor_styles::bottom)
      top(top());
    else if ((data_->anchor & anchor_styles::top) == anchor_styles::top && (data_->anchor & anchor_styles::bottom) == anchor_styles::bottom)
      height(parent().value().get().client_size().height() - data_->anchoring.bottom() - top());
    else if ((data_->anchor & anchor_styles::top) != anchor_styles::top && (data_->anchor & anchor_styles::bottom) == anchor_styles::bottom)
      top(parent().value().get().client_size().height() - height() - data_->anchoring.bottom());
    else
      top(parent().value().get().client_size().height() / 2 - height() / 2);
  }
}

void control::do_layout_with_auto_size_mode() {
  if (get_state(state::auto_size)) {
    drawing::size auto_size_size_ = measure_control();
    if (data_->auto_size_mode == auto_size_mode::grow_only && auto_size_size_.width() < data_->client_size.width())
      auto_size_size_.width(data_->client_size.width());
    if (data_->auto_size_mode == auto_size_mode::grow_only && auto_size_size_.height() < data_->client_size.height())
      auto_size_size_.height(data_->client_size.height());
    client_size(auto_size_size_);
  }
}

void control::wm_create(message& message) {
  on_create_control();
}

void control::wm_child_activate(message& message) {
  def_wnd_proc(message);
}

void control::wm_command(message& message) {
  def_wnd_proc(message);
  if (message.lparam() != 0 && from_handle(message.lparam()).has_value())
    from_handle(message.lparam()).value().get().send_message(message.hwnd(), WM_REFLECT + message.msg(), message.wparam(), message.lparam());
}

void control::wm_enter_idle(message& message) {
  def_wnd_proc(message);
  for (auto control : controls())
    control.get().wnd_proc(message);
  if (data_->recreate_handle_posted)
    recreate_handle();
 }

void control::wm_key_char(message& message) {
  if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::key_events), ustring::format("({}) receive message [{}]", *this, message));
  if (message.msg() == WM_KEYDOWN || message.msg() == WM_SYSKEYDOWN) {
    key_event_args key_event_args(static_cast<keys>(message.wparam()));
    modifier_keys_ = key_event_args.modifiers();
    on_key_down(key_event_args);
    message.result(key_event_args.suppress_key_press());
    if (!key_event_args.handled()) def_wnd_proc(message);
  } else if ((message.msg() == WM_CHAR || message.msg() == WM_SYSCHAR) && (message.wparam() > 255U || std::iscntrl(static_cast<int32_t>(message.wparam()))) == 0) {
    key_press_event_args key_press_event_args(static_cast<int32_t>(message.wparam()));
    on_key_press(key_press_event_args);
    message.result(key_press_event_args.handled());
    if (!key_press_event_args.handled()) def_wnd_proc(message);
  } else if (message.msg() == WM_KEYUP || message.msg() == WM_SYSKEYUP) {
    key_event_args key_event_args(static_cast<keys>(message.wparam()));
    modifier_keys_ = key_event_args.modifiers();
    on_key_up(key_event_args);
    message.result(key_event_args.handled());
    if (!key_event_args.handled()) def_wnd_proc(message);
  } else
    def_wnd_proc(message);
}

void control::wm_kill_focus(message& message) {
  def_wnd_proc(message);
  data_->focused = false;
  on_lost_focus(event_args::empty);
}

void control::wm_mouse_down(message& message) {
  if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::mouse_events), ustring::format("({}) receive message [{}]", *this, message));
  set_state(control::state::double_click_fired, message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_XBUTTONDBLCLK);
  mouse_event_args e = mouse_event_args::create(message, get_state(state::double_click_fired));
  mouse_buttons_ |= e.button();
  def_wnd_proc(message);
  on_mouse_down(e);
}

void control::wm_mouse_double_click(message& message) {
  if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::mouse_events), ustring::format("({}) receive message [{}]", *this, message));
  def_wnd_proc(message);
  set_state(control::state::double_click_fired, message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_XBUTTONDBLCLK);
  on_double_click(event_args::empty);
  on_mouse_double_click(mouse_event_args::create(message, get_state(state::double_click_fired)));
}

void control::wm_mouse_enter(message& message) {
  if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::mouse_events), ustring::format("({}) receive message [{}]", *this, message));
  data_->mouse_in = true;
  def_wnd_proc(message);
  on_mouse_enter(event_args::empty);
}

void control::wm_mouse_leave(message& message) {
  if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::mouse_events), ustring::format("({}) receive message [{}]", *this, message));
  data_->mouse_in = false;
  def_wnd_proc(message);
  on_mouse_leave(event_args::empty);
}

void control::wm_mouse_up(message& message) {
  if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::mouse_events), ustring::format("({}) receive message [{}]", *this, message));
  def_wnd_proc(message);
  mouse_event_args e = mouse_event_args::create(message);
  mouse_buttons_ &= ~e.button();
  if (client_rectangle().contains(e.location())) {
    on_click(event_args::empty);
    on_mouse_click(e);
  }
  on_mouse_up(e);
}

void control::wm_mouse_move(message& message) {
  if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::mouse_events), ustring::format("({}) receive message [{}]", *this, message));
  def_wnd_proc(message);
  mouse_event_args e = mouse_event_args(wparam_to_mouse_buttons(message), get_state(control::state::double_click_fired) ? 2 : 1, point_to_client({(int16_t)LOWORD(message.lparam()), (int16_t)HIWORD(message.lparam())}), 0);
  // Workaround : sometimes mouse enter and/or mouse leave message are not send
  // For example on macos when mouse down in control and mouse is moved out then moved in, the mouse enter message is not send...
  // The two followed line fixed it
  if (!data_->mouse_in && client_rectangle().contains(e.location())) {
    xtd::diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::trace_switch().trace_warning() && enable_debug::get(enable_debug::workaround), "Workaround : mouse enter event !!!");
    wm_mouse_enter(message);
  } else if (data_->mouse_in && !client_rectangle().contains(e.location())) {
    xtd::diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::trace_switch().trace_warning() && enable_debug::get(enable_debug::workaround), "Workaround : mouse leave event !!!");
    wm_mouse_leave(message);
  }
  on_mouse_move(e);
}

void control::wm_menu_command(message &message) {
  def_wnd_proc(message);
  if (data_->context_menu.has_value())
    on_context_menu_item_click(data_->context_menu.value().get(), message.wparam());
}

void control::wm_move(message& message) {
  def_wnd_proc(message);
  if (data_->location != native::control::location(handle())) {
    data_->location = native::control::location(handle());
    on_location_changed(event_args::empty);
  }
}

void control::wm_mouse_wheel(message& message) {
  if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::mouse_events), ustring::format("({}) receive message [{}]", *this, message));
  def_wnd_proc(message);
  if (message.msg() == WM_MOUSEHWHEEL)
    on_mouse_horizontal_wheel(mouse_event_args::create(message, get_state(state::double_click_fired), static_cast<int32_t>(HIWORD(message.wparam()))));
  else
    on_mouse_wheel(mouse_event_args::create(message, get_state(state::double_click_fired), static_cast<int32_t>(HIWORD(message.wparam()))));
}

void control::wm_notify(message& message) {
  def_wnd_proc(message);
  if (message.lparam() != 0) {
    NMHDR* nmhdr = reinterpret_cast<NMHDR*>(message.lparam());
    if (from_handle(reinterpret_cast<intptr_t>(nmhdr->hwndFrom)).has_value())
      from_handle(reinterpret_cast<intptr_t>(nmhdr->hwndFrom)).value().get().send_message(message.hwnd(), WM_REFLECT + message.msg(), message.wparam(), message.lparam());
  }
}

void control::wm_paint(const message& message) {
  paint_event_args e(*this, data_->client_rectangle);
  e.message_ = message;
  //auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
  //if (control_appearance() == forms::control_appearance::standard) control_renderer::draw_control(style, e.graphics(), e.clip_rectangle(), control_state(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt);
  on_paint(e);
}

void control::wm_erase_background(const message& message) {
  paint_event_args e(*this, data_->client_rectangle);
  e.message_ = message;
  on_paint_background(e);
}

void control::wm_help(message& message) {
  def_wnd_proc(message);
  HELPINFO* help_info = reinterpret_cast<HELPINFO*>(message.lparam());
  help_event_args e(point(help_info->MousePos.x, help_info->MousePos.y));
  on_help_requested(e);
  if (!e.handled())
    def_wnd_proc(message);
}

void control::wm_scroll(message& message) {
  def_wnd_proc(message);
  if (message.lparam() != 0 && from_handle(message.lparam()).has_value())
    from_handle(message.lparam()).value().get().send_message(message.hwnd(), WM_REFLECT + message.msg(), message.wparam(), message.lparam());
}

void control::wm_set_focus(message& message) {
  def_wnd_proc(message);
  data_->focused = true;
  on_got_focus(event_args::empty);
}

void control::wm_set_text(message& message) {
  def_wnd_proc(message);
  if (data_->text != reinterpret_cast<const wchar_t*>(message.lparam())) {
    data_->text = reinterpret_cast<const wchar_t*>(message.lparam());
    on_text_changed(event_args::empty);
  }
}

void control::wm_show(message& message) {
  def_wnd_proc(message);
  set_state(state::visible, message.wparam() != 0);
}

void control::wm_size(message& message) {
  def_wnd_proc(message);
  if (data_->client_size != native::control::client_size(handle())) {
    data_->client_size = native::control::client_size(handle());
    on_client_size_changed(event_args::empty);
  }
  if (size() != native::control::size(handle())) {
    data_->size = native::control::size(handle());
    on_size_changed(event_args::empty);
  }
  on_resize(event_args::empty);
}

void control::wm_sizing(message& message) {
  def_wnd_proc(message);
}
