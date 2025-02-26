#include "../../../include/xtd/forms/light_button.h"
#include "../../../include/xtd/forms/button_renderer.h"
#include "../../../include/xtd/forms/form.h"
#include "../../../include/xtd/forms/theme_colors.h"
#include "../../../include/xtd/forms/theme_renderers.h"
#include <xtd/drawing/pen.h>
#include <xtd/drawing/solid_brush.h>
#include <xtd/drawing/string_format.h>
#include <xtd/drawing/system_brushes.h>
#include <xtd/drawing/system_pens.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/light_button.h>
#include <xtd/forms/native/button_styles.h>
#include <xtd/forms/native/control.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/window_messages.h>

using namespace xtd;
using namespace xtd::forms;

namespace {
  xtd::forms::visual_styles::push_button_state to_push_button_style(xtd::forms::visual_styles::check_box_state state) {
    switch (state) {
      case xtd::forms::visual_styles::check_box_state::unchecked_normal: return xtd::forms::visual_styles::push_button_state::normal;
      case xtd::forms::visual_styles::check_box_state::unchecked_hot: return xtd::forms::visual_styles::push_button_state::hot;
      case xtd::forms::visual_styles::check_box_state::unchecked_pressed: return xtd::forms::visual_styles::push_button_state::normal;
      case xtd::forms::visual_styles::check_box_state::unchecked_disabled: return xtd::forms::visual_styles::push_button_state::disabled;
      case xtd::forms::visual_styles::check_box_state::checked_normal: return xtd::forms::visual_styles::push_button_state::normal;
      case xtd::forms::visual_styles::check_box_state::checked_hot: return xtd::forms::visual_styles::push_button_state::hot;
      case xtd::forms::visual_styles::check_box_state::checked_pressed: return xtd::forms::visual_styles::push_button_state::normal;
      case xtd::forms::visual_styles::check_box_state::checked_disabled: return xtd::forms::visual_styles::push_button_state::disabled;
      case xtd::forms::visual_styles::check_box_state::mixed_normal: return xtd::forms::visual_styles::push_button_state::normal;
      case xtd::forms::visual_styles::check_box_state::mixed_hot: return xtd::forms::visual_styles::push_button_state::hot;
      case xtd::forms::visual_styles::check_box_state::mixed_pressed: return xtd::forms::visual_styles::push_button_state::normal;
      case xtd::forms::visual_styles::check_box_state::mixed_disabled: return xtd::forms::visual_styles::push_button_state::disabled;
      default: return xtd::forms::visual_styles::push_button_state::normal;
    }
  }
}

light_button& light_button::auto_check(bool auto_check) {
  data_->auto_check = auto_check;
  return *this;
}

light_button& light_button::checked(bool checked) {
  check_state(checked ? forms::check_state::checked : forms::check_state::unchecked);
  return *this;
}

light_button& light_button::light_align(content_alignment light_align) {
  if (data_->light_align != light_align) {
    data_->light_align = light_align;
    post_recreate_handle();
  }
  return *this;
}

light_button& light_button::check_state(forms::check_state check_state) {
  if (data_->check_state != check_state) {
    data_->check_state = check_state;
    if (data_->checked != (data_->check_state != forms::check_state::unchecked)) {
      data_->checked = data_->check_state != forms::check_state::unchecked;
      on_checked_changed(event_args::empty);
    }
    if (is_handle_created() && flat_style() == xtd::forms::flat_style::system) native::light_button::check_state(handle(), static_cast<int32_t>(data_->check_state));
    on_check_state_changed(event_args::empty);
  }
  return *this;
}

light_button& light_button::three_state(bool three_state) {
  if (data_->three_state != three_state) {
    data_->three_state = three_state;
    post_recreate_handle();
  }
  return *this;
}

drawing::color light_button::light_off_color() const {
  return data_->light_off_color.value_or(default_light_off_color());
}

light_button& light_button::light_off_color(const drawing::color& value) {
  if (!data_->light_off_color.has_value() || data_->light_off_color.value() != value) {
    data_->light_off_color = value;
    invalidate();
  }
  
  return *this;
}

light_button& light_button::light_off_color(std::nullptr_t) {
  if (data_->light_off_color.has_value()) {
    data_->light_off_color.reset();
    invalidate();
  }
  
  return *this;
}

drawing::color light_button::light_on_color() const {
  return data_->light_on_color.value_or(default_light_on_color());
}

light_button& light_button::light_on_color(const drawing::color& value) {
  if (!data_->light_on_color.has_value() || data_->light_on_color.value() != value) {
    data_->light_on_color = value;
    invalidate();
  }
  
  return *this;
}

light_button& light_button::light_on_color(std::nullptr_t) {
  if (data_->light_on_color.has_value()) {
    data_->light_on_color.reset();
    invalidate();
  }
  
  return *this;
}

forms::create_params light_button::create_params() const {
  forms::create_params create_params = button_base::create_params();
  
  create_params.class_name("lightbutton");
  
  create_params.style(create_params.style() | BS_PUSHBUTTON);
  
  return create_params;
}

void light_button::on_image_changed(const xtd::event_args& e) {
  button_base::on_image_changed(e);
}

void light_button::on_handle_created(const event_args& e) {
  button_base::on_handle_created(e);
  if (flat_style() == xtd::forms::flat_style::system) native::light_button::check_state(handle(), static_cast<int32_t>(data_->check_state));
  if (flat_style() != xtd::forms::flat_style::system && data_->check_state != xtd::forms::check_state::unchecked) invalidate();
}

void light_button::on_paint(paint_event_args& e) {
  if (flat_style() != xtd::forms::flat_style::system) {
    text_format_flags flags = to_text_format_flags(text_align());
    if (flat_style() == xtd::forms::flat_style::flat) button_renderer::draw_flat_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image(), compute_image_bounds(), focused(), to_push_button_style(data_->state), !get_back_color().has_value() && back_color() != xtd::forms::theme_colors::current_theme().control() ? back_color() : get_back_color(), !get_fore_color().has_value() && fore_color() != xtd::forms::theme_colors::current_theme().control_text() ? fore_color() : get_fore_color(), flat_appearance());
    else if (flat_style() == xtd::forms::flat_style::popup) button_renderer::draw_popup_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image(), compute_image_bounds(), focused(), to_push_button_style(data_->state), !get_back_color().has_value() && back_color() != xtd::forms::theme_colors::current_theme().control() ? back_color() : get_back_color(), !get_fore_color().has_value() && fore_color() != xtd::forms::theme_colors::current_theme().control_text() ? fore_color() : get_fore_color(), flat_appearance());
    else theme_renderers::current_theme().draw_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image(), compute_image_bounds(), focused(), to_push_button_style(data_->state), !get_back_color().has_value() && back_color() != xtd::forms::theme_colors::current_theme().control() ? back_color() : get_back_color(), !get_fore_color().has_value() && fore_color() != xtd::forms::theme_colors::current_theme().control_text() ? fore_color() : get_fore_color());
    
    drawing::color light_color = light_off_color();
    if (data_->check_state == check_state::checked) light_color = light_on_color();
    else if (data_->check_state == check_state::indeterminate) light_color = drawing::color::dark(light_on_color());
    if (!enabled()) light_color = back_color();
    int left = e.clip_rectangle().left() + 5;
    if (data_->light_align == content_alignment::top_right || data_->light_align == content_alignment::middle_right || data_->light_align == content_alignment::bottom_right) left = e.clip_rectangle().right() - 15;
    else if (data_->light_align == content_alignment::top_center || data_->light_align == content_alignment::middle_center || data_->light_align == content_alignment::bottom_center) left = e.clip_rectangle().left() + (e.clip_rectangle().width() / 2) - 5;
    int top = e.clip_rectangle().top() + (e.clip_rectangle().height() / 2) - 7;
    if (data_->light_align == content_alignment::top_right || data_->light_align == content_alignment::top_center || data_->light_align == content_alignment::top_left) top = e.clip_rectangle().top() + 5;
    else if (data_->light_align == content_alignment::bottom_right || data_->light_align == content_alignment::bottom_center || data_->light_align == content_alignment::bottom_left) top = e.clip_rectangle().bottom() - 20;
    e.graphics().fill_rounded_rectangle(drawing::solid_brush(light_color), drawing::rectangle {left, top, 10, 16}, 2);
    e.graphics().draw_rounded_rectangle(drawing::pen(drawing::solid_brush(drawing::color::dark(back_color()))), drawing::rectangle {left, top, 9, 15}, 2);
  }
  button_base::on_paint(e);
}

drawing::size light_button::measure_control() const {
  /// @todo Add light according to the alignment
  return button_base::measure_text();
}

void light_button::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_LBUTTONDOWN: wm_mouse_down(message); break;
    case WM_LBUTTONUP: wm_mouse_up(message); break;
    case WM_LBUTTONDBLCLK: wm_mouse_double_click(message); break;
    default: button_base::wnd_proc(message);
  }
}

void light_button::wm_mouse_double_click(message& message) {
  on_double_click(event_args::empty);
}

void light_button::wm_mouse_down(message& message) {
  set_state(control::state::double_click_fired, message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_XBUTTONDBLCLK);
  mouse_event_args e = mouse_event_args::create(message, get_state(state::double_click_fired));
  set_mouse_buttons(mouse_buttons() | e.button());
  on_mouse_down(e);
}

void light_button::wm_mouse_up(message& message) {
  if (data_->auto_check)
    switch (check_state()) {
      case forms::check_state::unchecked: check_state(forms::check_state::checked); break;
      case forms::check_state::checked: check_state(three_state() ? forms::check_state::indeterminate : forms::check_state::unchecked); break;
      case forms::check_state::indeterminate: check_state(forms::check_state::unchecked); break;
    }
  mouse_event_args e = mouse_event_args::create(message);
  set_mouse_buttons(mouse_buttons() & ~e.button());
  if (client_rectangle().contains(e.location())) on_click(event_args::empty);
  on_mouse_click(e);
  on_mouse_up(e);
}
