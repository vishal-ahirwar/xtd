#include "../../../include/xtd/forms/check_box_renderer.h"
#include "../../../include/xtd/forms/control_paint.h"
#include <map>
#include <xtd/environment.h>
#include <xtd/drawing/pen.h>
#include <xtd/drawing/solid_brush.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/drawing/drawing2d/linear_gradient_brush.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::visual_styles;

namespace {
  xtd::ustring get_hotkey_prefix_locations(const xtd::ustring& str, std::vector<size_t>& locations) {
    auto offset = 0U;
    for (auto index = 0U; index < str.size(); index++) {
      if (str[index] == '&' && str[index + 1] != '&')
        locations.push_back(index + offset);
      else if (str[index] == '&' && str[index + 1] == '&') {
        offset -= 2;
        ++index;
      }
    }
    auto new_str = str.replace("&&", "&");
    for (auto index = 0U; index < locations.size(); ++index)
      new_str = new_str.remove(locations[index], 1);
    return new_str;
  }
  
  void draw_string(graphics g, const ustring& text, const font& font, const color& text_color, const rectangle_f& button_rect, text_format_flags flags) {
    vector<size_t> hotkey_prefix_locations;
    ustring text_without_hotkey_prefix = get_hotkey_prefix_locations(text, hotkey_prefix_locations);
    if ((flags & text_format_flags::prefix_only) == text_format_flags::prefix_only && hotkey_prefix_locations.size()) g.draw_string(text_without_hotkey_prefix.substring(hotkey_prefix_locations[0], 1), xtd::drawing::font(font, font_style::underline), solid_brush(text_color), button_rect, control_paint::string_format(flags));
    else g.draw_string(text, font, solid_brush(text_color), button_rect, control_paint::string_format(flags));
  }
}

void check_box_renderer::draw_check_box(const ustring& theme, graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (theme == "gnome") draw_check_box_gnome(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "gnome (dark)") draw_check_box_gnome_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "gnome (light)") draw_check_box_gnome_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "kde") draw_check_box_kde(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "kde (dark)") draw_check_box_kde_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "kde (light)") draw_check_box_kde_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "macos") draw_check_box_macos(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "macos (dark)") draw_check_box_macos_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "macos (light)") draw_check_box_macos_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "symbolic") draw_check_box_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "symbolic (dark)") draw_check_box_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "symbolic (light)") draw_check_box_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "windows") draw_check_box_windows(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "windows (dark)") draw_check_box_windows_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "windows (light)") draw_check_box_windows_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "xtd") draw_check_box_xtd(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "xtd (dark)") draw_check_box_xtd_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "xtd (light)") draw_check_box_xtd_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else draw_check_box_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_gnome(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_check_box_gnome_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_check_box_gnome_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_gnome_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = xtd::forms::theme_colors::current_theme().control_dark();
  auto button_color = control_paint::dark(background_color, 0.1);
  auto text_color = foreground_color;
  auto mark_color = xtd::forms::theme_colors::current_theme().accent_text();
  
  if (state == xtd::forms::visual_styles::check_box_state::unchecked_hot || state == xtd::forms::visual_styles::check_box_state::unchecked_pressed)
    button_color = control_paint::light(button_color, 0.1);
  else if (state == xtd::forms::visual_styles::check_box_state::checked_normal || state == xtd::forms::visual_styles::check_box_state::checked_hot || state == xtd::forms::visual_styles::check_box_state::checked_pressed || state == xtd::forms::visual_styles::check_box_state::mixed_normal || state == xtd::forms::visual_styles::check_box_state::mixed_hot || state == xtd::forms::visual_styles::check_box_state::mixed_pressed)
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
  else if (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled || state == xtd::forms::visual_styles::check_box_state::checked_disabled || state == xtd::forms::visual_styles::check_box_state::mixed_disabled) {
    if (!back_color.has_value()) border_color = color::from_argb(90, 90, 90);
    text_color = mark_color = xtd::forms::theme_colors::current_theme().gray_text();
  }
  
  rectangle button_rectangle = {bounds.x() + 1, bounds.y() + bounds.height() / 2 - 8, 16, 16};
  g.fill_rounded_rectangle(drawing2d::linear_gradient_brush(point {bounds.x(), bounds.top()}, point {bounds.x(), bounds.bottom()}, control_paint::light(button_color, 0.15), button_color), button_rectangle, 3);
  g.draw_rounded_rectangle(pen(border_color, 1), rectangle::add(button_rectangle, {-1, -1}), 3);
  rectangle string_rectangle = { bounds.x() + 19, bounds.y(), bounds.width() - 19, bounds.height() };
  if (state == xtd::forms::visual_styles::check_box_state::checked_normal || state == xtd::forms::visual_styles::check_box_state::checked_hot || state == xtd::forms::visual_styles::check_box_state::checked_pressed || state == xtd::forms::visual_styles::check_box_state::checked_disabled) {
    g.draw_line(pen(mark_color, 3), button_rectangle.x() + 4, button_rectangle.y() + button_rectangle.height() / 2 - 1, button_rectangle.x() + button_rectangle.width() / 2 - 1, button_rectangle.y() + button_rectangle.height() - 6);
    g.draw_line(pen(mark_color, 3), button_rectangle.x() + button_rectangle.width() / 2 - 1, button_rectangle.y() + button_rectangle.height() - 6, button_rectangle.x() + button_rectangle.width() - 4, button_rectangle.y() + 5);
  } else if (state == xtd::forms::visual_styles::check_box_state::mixed_normal || state == xtd::forms::visual_styles::check_box_state::mixed_hot || state == xtd::forms::visual_styles::check_box_state::mixed_pressed || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)
    g.draw_line(pen(mark_color, 4), button_rectangle.x() + 5, button_rectangle.y() + button_rectangle.height() / 2, button_rectangle.x() + button_rectangle.width() - 5, button_rectangle.y() + button_rectangle.height() / 2);
  if (image != image::empty && (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled || state == xtd::forms::visual_styles::check_box_state::checked_disabled || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, string_rectangle, flags);
}

void check_box_renderer::draw_check_box_gnome_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = xtd::forms::theme_colors::current_theme().control_dark();
  auto button_color = control_paint::light(background_color, 0.25);
  auto text_color = foreground_color;
  auto mark_color = xtd::forms::theme_colors::current_theme().accent_text();
  
  if (state == xtd::forms::visual_styles::check_box_state::unchecked_hot || state == xtd::forms::visual_styles::check_box_state::unchecked_pressed)
    button_color = control_paint::dark(button_color, 0.1);
  else if (state == xtd::forms::visual_styles::check_box_state::checked_normal || state == xtd::forms::visual_styles::check_box_state::checked_hot || state == xtd::forms::visual_styles::check_box_state::checked_pressed || state == xtd::forms::visual_styles::check_box_state::mixed_normal || state == xtd::forms::visual_styles::check_box_state::mixed_hot || state == xtd::forms::visual_styles::check_box_state::mixed_pressed)
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
  else if (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled || state == xtd::forms::visual_styles::check_box_state::checked_disabled || state == xtd::forms::visual_styles::check_box_state::mixed_disabled) {
    if (!back_color.has_value()) border_color = color::from_argb(90, 90, 90);
    text_color = mark_color = xtd::forms::theme_colors::current_theme().gray_text();
  }
  
  rectangle button_rectangle = {bounds.x() + 1, bounds.y() + bounds.height() / 2 - 8, 16, 16};
  g.fill_rounded_rectangle(drawing2d::linear_gradient_brush(point {bounds.x(), bounds.top()}, point {bounds.x(), bounds.bottom()}, control_paint::light(button_color, 0.5), button_color), button_rectangle, 3);
  g.draw_rounded_rectangle(pen(border_color, 1), rectangle::add(button_rectangle, {-1, -1}), 3);
  rectangle string_rectangle = { bounds.x() + 19, bounds.y(), bounds.width() - 19, bounds.height() };
  if (state == xtd::forms::visual_styles::check_box_state::checked_normal || state == xtd::forms::visual_styles::check_box_state::checked_hot || state == xtd::forms::visual_styles::check_box_state::checked_pressed || state == xtd::forms::visual_styles::check_box_state::checked_disabled) {
    g.draw_line(pen(mark_color, 3), button_rectangle.x() + 4, button_rectangle.y() + button_rectangle.height() / 2 - 1, button_rectangle.x() + button_rectangle.width() / 2 - 1, button_rectangle.y() + button_rectangle.height() - 6);
    g.draw_line(pen(mark_color, 3), button_rectangle.x() + button_rectangle.width() / 2 - 1, button_rectangle.y() + button_rectangle.height() - 6, button_rectangle.x() + button_rectangle.width() - 4, button_rectangle.y() + 5);
  } else if (state == xtd::forms::visual_styles::check_box_state::mixed_normal || state == xtd::forms::visual_styles::check_box_state::mixed_hot || state == xtd::forms::visual_styles::check_box_state::mixed_pressed || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)
    g.draw_line(pen(mark_color, 4), button_rectangle.x() + 5, button_rectangle.y() + button_rectangle.height() / 2, button_rectangle.x() + button_rectangle.width() - 5, button_rectangle.y() + button_rectangle.height() / 2);
  if (image != image::empty && (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled || state == xtd::forms::visual_styles::check_box_state::checked_disabled || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, string_rectangle, flags);
}

void check_box_renderer::draw_check_box_kde(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_check_box_kde_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_check_box_kde_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_kde_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_check_box_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_kde_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_check_box_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_macos(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_check_box_macos_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_check_box_macos_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_macos_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = control_paint::dark(back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control(), 0.05);
  auto button_color = xtd::forms::theme_colors::current_theme().button_face();
  auto text_color = control_paint::light(foreground_color, 0.1);
  auto mark_color = control_paint::dark(xtd::forms::theme_colors::current_theme().accent_text(), 0.15);
  
  if (state == xtd::forms::visual_styles::check_box_state::checked_normal || state == xtd::forms::visual_styles::check_box_state::checked_hot || state == xtd::forms::visual_styles::check_box_state::mixed_normal || state == xtd::forms::visual_styles::check_box_state::mixed_hot || state == xtd::forms::visual_styles::check_box_state::checked_pressed || state == xtd::forms::visual_styles::check_box_state::mixed_pressed)
    button_color = control_paint::dark(xtd::forms::theme_colors::current_theme().accent(), 0.15);
  else if (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled || state == xtd::forms::visual_styles::check_box_state::checked_disabled || state == xtd::forms::visual_styles::check_box_state::mixed_disabled) {
    border_color = color::from_argb(85, 85, 55);
    mark_color = text_color = xtd::forms::theme_colors::current_theme().gray_text();
    button_color = control_paint::dark(xtd::forms::theme_colors::current_theme().button_face(), 0.7);
  }
  
  rectangle button_rectangle = {bounds.x() + 1, bounds.y() + bounds.height() / 2 - 7, 16, 16};
  if (state == xtd::forms::visual_styles::check_box_state::unchecked_normal || state == xtd::forms::visual_styles::check_box_state::unchecked_hot || state == xtd::forms::visual_styles::check_box_state::unchecked_pressed || state == xtd::forms::visual_styles::check_box_state::unchecked_disabled)
    g.fill_rounded_rectangle(drawing2d::linear_gradient_brush(point {button_rectangle.x(), button_rectangle.top()}, point {button_rectangle.x(), button_rectangle.bottom()}, control_paint::dark(button_color, .5), button_color), button_rectangle, 4);
  else
    g.fill_rounded_rectangle(solid_brush(button_color), button_rectangle, 4);
  g.draw_rounded_rectangle(pen(border_color, 1), rectangle::add(button_rectangle, {-1, -1}), 4);
  rectangle string_rectangle = {bounds.x() + 19, bounds.y(), bounds.width() - 19, bounds.height()};
  if (state == xtd::forms::visual_styles::check_box_state::checked_normal || state == xtd::forms::visual_styles::check_box_state::checked_hot || state == xtd::forms::visual_styles::check_box_state::checked_pressed || state == xtd::forms::visual_styles::check_box_state::checked_disabled) {
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + 4, button_rectangle.y() + button_rectangle.height() / 2, button_rectangle.x() + button_rectangle.width() / 2, button_rectangle.y() + button_rectangle.height() - 4);
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + button_rectangle.width() / 2, button_rectangle.y() + button_rectangle.height() - 4, button_rectangle.x() + button_rectangle.width() - 4, button_rectangle.y() + 4);
  } else if (state == xtd::forms::visual_styles::check_box_state::mixed_normal || state == xtd::forms::visual_styles::check_box_state::mixed_hot || state == xtd::forms::visual_styles::check_box_state::mixed_pressed || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + 5, button_rectangle.y() + button_rectangle.height() / 2, button_rectangle.x() + button_rectangle.width() - 5, button_rectangle.y() + button_rectangle.height() / 2);
  if (image != image::empty && (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled || state == xtd::forms::visual_styles::check_box_state::checked_disabled || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, string_rectangle, flags);
}

void check_box_renderer::draw_check_box_macos_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = color::from_argb(200, 200, 200);
  auto button_color = back_color.has_value() ? color::from_argb(128, xtd::forms::theme_colors::current_theme().control()) : xtd::forms::theme_colors::current_theme().button_face();
  auto text_color = foreground_color;
  auto mark_color = control_paint::dark(xtd::forms::theme_colors::current_theme().accent_text(), 0.15);
  
  if (state == xtd::forms::visual_styles::check_box_state::checked_normal || state == xtd::forms::visual_styles::check_box_state::checked_hot || state == xtd::forms::visual_styles::check_box_state::mixed_normal || state == xtd::forms::visual_styles::check_box_state::mixed_hot || state == xtd::forms::visual_styles::check_box_state::checked_pressed || state == xtd::forms::visual_styles::check_box_state::mixed_pressed)
    button_color = xtd::forms::theme_colors::current_theme().accent();
  else if (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled || state == xtd::forms::visual_styles::check_box_state::checked_disabled || state == xtd::forms::visual_styles::check_box_state::mixed_disabled) {
    border_color = mark_color = text_color = xtd::forms::theme_colors::current_theme().gray_text();
    button_color = back_color.has_value() ? color::from_argb(210, 255, 255, 255) : control_paint::dark(button_color, 0.04);
  }
  
  rectangle button_rectangle = {bounds.x() + 1, bounds.y() + bounds.height() / 2 - 7, 16, 16};
  if (state == xtd::forms::visual_styles::check_box_state::unchecked_normal || state == xtd::forms::visual_styles::check_box_state::unchecked_hot || state == xtd::forms::visual_styles::check_box_state::unchecked_pressed || state == xtd::forms::visual_styles::check_box_state::unchecked_disabled)
    g.fill_rounded_rectangle(drawing2d::linear_gradient_brush(point {bounds.x(), bounds.top()}, point {bounds.x(), bounds.bottom()}, button_color, control_paint::light(button_color)), button_rectangle, 4);
  else
    g.fill_rounded_rectangle(solid_brush(button_color), button_rectangle, 4);
  g.draw_rounded_rectangle(pen(border_color, 1), rectangle::add(button_rectangle, {-1, -1}), 4);
  rectangle string_rectangle = {bounds.x() + 19, bounds.y(), bounds.width() - 19, bounds.height()};
  if (state == xtd::forms::visual_styles::check_box_state::checked_normal || state == xtd::forms::visual_styles::check_box_state::checked_hot || state == xtd::forms::visual_styles::check_box_state::checked_pressed || state == xtd::forms::visual_styles::check_box_state::checked_disabled) {
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + 4, button_rectangle.y() + button_rectangle.height() / 2, button_rectangle.x() + button_rectangle.width() / 2, button_rectangle.y() + button_rectangle.height() - 4);
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + button_rectangle.width() / 2, button_rectangle.y() + button_rectangle.height() - 4, button_rectangle.x() + button_rectangle.width() - 4, button_rectangle.y() + 4);
  } else if (state == xtd::forms::visual_styles::check_box_state::mixed_normal || state == xtd::forms::visual_styles::check_box_state::mixed_hot || state == xtd::forms::visual_styles::check_box_state::mixed_pressed || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + 5, button_rectangle.y() + button_rectangle.height() / 2, button_rectangle.x() + button_rectangle.width() - 5, button_rectangle.y() + button_rectangle.height() / 2);
  if (image != image::empty && (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled || state == xtd::forms::visual_styles::check_box_state::checked_disabled || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, string_rectangle, flags);
  
}

void check_box_renderer::draw_check_box_symbolic(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_check_box_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_check_box_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_symbolic_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = xtd::forms::theme_colors::current_theme().active_border();
  auto button_color = control_paint::light(background_color, .05);
  auto text_color = foreground_color;
  auto mark_color = xtd::forms::theme_colors::current_theme().accent_text();
  
  if (state == xtd::forms::visual_styles::check_box_state::checked_normal || state == xtd::forms::visual_styles::check_box_state::mixed_normal)
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
  else if (state == xtd::forms::visual_styles::check_box_state::unchecked_hot) {
    border_color = control_paint::light(xtd::forms::theme_colors::current_theme().active_border(), 2.0 / 3);
    button_color = control_paint::light(background_color, .1);
  } else if (state == xtd::forms::visual_styles::check_box_state::checked_hot || state == xtd::forms::visual_styles::check_box_state::mixed_hot) {
    border_color = control_paint::light(xtd::forms::theme_colors::current_theme().active_border(), 2.0 / 3);
    button_color = xtd::forms::theme_colors::current_theme().accent();
  } else if (state == xtd::forms::visual_styles::check_box_state::unchecked_pressed || state == xtd::forms::visual_styles::check_box_state::checked_pressed || state == xtd::forms::visual_styles::check_box_state::mixed_pressed)
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
  else if (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled || state == xtd::forms::visual_styles::check_box_state::checked_disabled || state == xtd::forms::visual_styles::check_box_state::mixed_disabled) {
    border_color = color::from_argb(85, 85, 55);
    mark_color = text_color = xtd::forms::theme_colors::current_theme().gray_text();
  }
  
  rectangle button_rectangle = {bounds.x() + 1, bounds.y() + bounds.height() / 2 - 7, 16, 16};
  g.fill_rounded_rectangle(solid_brush(button_color), button_rectangle, 3);
  g.draw_rounded_rectangle(pen(border_color, 1), rectangle::add(button_rectangle, {-1, -1}), 3);
  rectangle string_rectangle = {bounds.x() + 19, bounds.y(), bounds.width() - 19, bounds.height()};
  if (state == xtd::forms::visual_styles::check_box_state::checked_normal || state == xtd::forms::visual_styles::check_box_state::checked_hot || state == xtd::forms::visual_styles::check_box_state::checked_pressed || state == xtd::forms::visual_styles::check_box_state::checked_disabled) {
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + 4, button_rectangle.y() + button_rectangle.height() / 2, button_rectangle.x() + button_rectangle.width() / 2, button_rectangle.y() + button_rectangle.height() - 4);
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + button_rectangle.width() / 2, button_rectangle.y() + button_rectangle.height() - 4, button_rectangle.x() + button_rectangle.width() - 4, button_rectangle.y() + 4);
  } else if (state == xtd::forms::visual_styles::check_box_state::mixed_normal || state == xtd::forms::visual_styles::check_box_state::mixed_hot || state == xtd::forms::visual_styles::check_box_state::mixed_pressed || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + 5, button_rectangle.y() + button_rectangle.height() / 2, button_rectangle.x() + button_rectangle.width() - 5, button_rectangle.y() + button_rectangle.height() / 2);
  if (image != image::empty && (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled || state == xtd::forms::visual_styles::check_box_state::checked_disabled || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, string_rectangle, flags);
}

void check_box_renderer::draw_check_box_symbolic_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = xtd::forms::theme_colors::current_theme().active_border();
  auto button_color = control_paint::dark(background_color, .05);
  auto text_color = foreground_color;
  auto mark_color = xtd::forms::theme_colors::current_theme().accent_text();
  
  if (state == xtd::forms::visual_styles::check_box_state::checked_normal || state == xtd::forms::visual_styles::check_box_state::mixed_normal)
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
  else if (state == xtd::forms::visual_styles::check_box_state::unchecked_hot) {
    border_color = control_paint::light(xtd::forms::theme_colors::current_theme().active_border(), 2.0 / 3);
    button_color = control_paint::dark(background_color, .1);
  } else if (state == xtd::forms::visual_styles::check_box_state::checked_hot || state == xtd::forms::visual_styles::check_box_state::mixed_hot) {
    border_color = control_paint::light(xtd::forms::theme_colors::current_theme().active_border(), 2.0 / 3);
    button_color = xtd::forms::theme_colors::current_theme().accent();
  } else if (state == xtd::forms::visual_styles::check_box_state::unchecked_pressed || state == xtd::forms::visual_styles::check_box_state::checked_pressed || state == xtd::forms::visual_styles::check_box_state::mixed_pressed)
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
  else if (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled || state == xtd::forms::visual_styles::check_box_state::checked_disabled || state == xtd::forms::visual_styles::check_box_state::mixed_disabled) {
    border_color = color::from_argb(85, 85, 55);
    mark_color = text_color = xtd::forms::theme_colors::current_theme().gray_text();
  }
  
  rectangle button_rectangle = {bounds.x() + 1, bounds.y() + bounds.height() / 2 - 7, 16, 16};
  g.fill_rounded_rectangle(solid_brush(button_color), button_rectangle, 3);
  g.draw_rounded_rectangle(pen(border_color, 1), rectangle::add(button_rectangle, {-1, -1}), 3);
  rectangle string_rectangle = {bounds.x() + 19, bounds.y(), bounds.width() - 19, bounds.height()};
  if (state == xtd::forms::visual_styles::check_box_state::checked_normal || state == xtd::forms::visual_styles::check_box_state::checked_hot || state == xtd::forms::visual_styles::check_box_state::checked_pressed || state == xtd::forms::visual_styles::check_box_state::checked_disabled) {
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + 4, button_rectangle.y() + button_rectangle.height() / 2, button_rectangle.x() + button_rectangle.width() / 2, button_rectangle.y() + button_rectangle.height() - 4);
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + button_rectangle.width() / 2, button_rectangle.y() + button_rectangle.height() - 4, button_rectangle.x() + button_rectangle.width() - 4, button_rectangle.y() + 4);
  } else if (state == xtd::forms::visual_styles::check_box_state::mixed_normal || state == xtd::forms::visual_styles::check_box_state::mixed_hot || state == xtd::forms::visual_styles::check_box_state::mixed_pressed || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + 5, button_rectangle.y() + button_rectangle.height() / 2, button_rectangle.x() + button_rectangle.width() - 5, button_rectangle.y() + button_rectangle.height() / 2);
  if (image != image::empty && (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled || state == xtd::forms::visual_styles::check_box_state::checked_disabled || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, string_rectangle, flags);
}

void check_box_renderer::draw_check_box_windows(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_check_box_windows_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_check_box_windows_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_windows_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = xtd::forms::theme_colors::current_theme().active_border();
  auto button_color = control_paint::light(background_color, .1);
  auto text_color = foreground_color;
  auto mark_color = xtd::forms::theme_colors::current_theme().accent_text();
  
  if (state == xtd::forms::visual_styles::check_box_state::unchecked_hot || state == xtd::forms::visual_styles::check_box_state::checked_hot || state == xtd::forms::visual_styles::check_box_state::mixed_hot)
    border_color = xtd::forms::theme_colors::current_theme().accent();
  else if (state == xtd::forms::visual_styles::check_box_state::unchecked_pressed || state == xtd::forms::visual_styles::check_box_state::checked_pressed || state == xtd::forms::visual_styles::check_box_state::mixed_pressed)
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
  else if (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled || state == xtd::forms::visual_styles::check_box_state::checked_disabled || state == xtd::forms::visual_styles::check_box_state::mixed_disabled) {
    if (!back_color.has_value()) border_color = color::from_argb(90, 90, 90);
    text_color = mark_color = xtd::forms::theme_colors::current_theme().gray_text();
  }
  
  rectangle button_rectangle = {bounds.x() + 1, bounds.y() + bounds.height() / 2 - 7, 14, 14};
  g.fill_rectangle(solid_brush(button_color), button_rectangle);
  g.draw_rectangle(pen(border_color, 1), rectangle::add(button_rectangle, {-1, -1}));
  rectangle string_rectangle = { bounds.x() + 19, bounds.y(), bounds.width() - 19, bounds.height() };
  if (state == xtd::forms::visual_styles::check_box_state::checked_normal || state == xtd::forms::visual_styles::check_box_state::checked_hot || state == xtd::forms::visual_styles::check_box_state::checked_pressed || state == xtd::forms::visual_styles::check_box_state::checked_disabled) {
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + 4, button_rectangle.y() + button_rectangle.height() / 2, button_rectangle.x() + button_rectangle.width() / 2, button_rectangle.y() + button_rectangle.height() - 4);
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + button_rectangle.width() / 2, button_rectangle.y() + button_rectangle.height() - 4, button_rectangle.x() + button_rectangle.width() - 4, button_rectangle.y() + 4);
  } else if (state == xtd::forms::visual_styles::check_box_state::mixed_normal || state == xtd::forms::visual_styles::check_box_state::mixed_hot || state == xtd::forms::visual_styles::check_box_state::mixed_pressed || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + 4, button_rectangle.y() + button_rectangle.height() / 2, button_rectangle.x() + button_rectangle.width() - 3, button_rectangle.y() + button_rectangle.height() / 2);
  if (image != image::empty && (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled || state == xtd::forms::visual_styles::check_box_state::checked_disabled || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, string_rectangle, flags);
}

void check_box_renderer::draw_check_box_windows_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = xtd::forms::theme_colors::current_theme().control_text();
  auto button_color = control_paint::light(background_color, .75);
  auto text_color = foreground_color;
  auto mark_color = xtd::forms::theme_colors::current_theme().control_text();
  
  if (state == xtd::forms::visual_styles::check_box_state::unchecked_hot || state == xtd::forms::visual_styles::check_box_state::checked_hot || state == xtd::forms::visual_styles::check_box_state::mixed_hot)
    border_color = mark_color = xtd::forms::theme_colors::current_theme().highlight();
  else if (state == xtd::forms::visual_styles::check_box_state::unchecked_pressed || state == xtd::forms::visual_styles::check_box_state::checked_pressed || state == xtd::forms::visual_styles::check_box_state::mixed_pressed)
    border_color = mark_color = xtd::forms::theme_colors::current_theme().highlight();
  else if (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled || state == xtd::forms::visual_styles::check_box_state::checked_disabled || state == xtd::forms::visual_styles::check_box_state::mixed_disabled) {
    if (!back_color.has_value()) border_color = xtd::forms::theme_colors::current_theme().gray_text();
    text_color = mark_color = xtd::forms::theme_colors::current_theme().gray_text();
  }
  
  rectangle button_rectangle = {bounds.x() + 1, bounds.y() + bounds.height() / 2 - 6, 12, 12};
  g.fill_rectangle(solid_brush(button_color), button_rectangle);
  g.draw_rectangle(pen(border_color, 1), rectangle::add(button_rectangle, {-1, -1}));
  rectangle string_rectangle = { bounds.x() + 19, bounds.y(), bounds.width() - 14, bounds.height() };
  if (state == xtd::forms::visual_styles::check_box_state::checked_normal || state == xtd::forms::visual_styles::check_box_state::checked_hot || state == xtd::forms::visual_styles::check_box_state::checked_pressed || state == xtd::forms::visual_styles::check_box_state::checked_disabled) {
    g.draw_line(pen(mark_color, 1), button_rectangle.x() + 2, button_rectangle.y() + button_rectangle.height() / 2, button_rectangle.x() + button_rectangle.width() / 2 - 1, button_rectangle.y() + button_rectangle.height() - 4);
    g.draw_line(pen(mark_color, 1), button_rectangle.x() + button_rectangle.width() / 2 - 1, button_rectangle.y() + button_rectangle.height() - 4, button_rectangle.x() + button_rectangle.width() - 2, button_rectangle.y() + 2);
  } else if (state == xtd::forms::visual_styles::check_box_state::mixed_normal || state == xtd::forms::visual_styles::check_box_state::mixed_hot || state == xtd::forms::visual_styles::check_box_state::mixed_pressed || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)
    g.fill_rectangle(solid_brush(mark_color), rectangle(button_rectangle.x() + 3, button_rectangle.y() + 3, button_rectangle.width() - 6, button_rectangle.height() - 6));
  if (image != image::empty && (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled || state == xtd::forms::visual_styles::check_box_state::checked_disabled || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, string_rectangle, flags);
}

void check_box_renderer::draw_check_box_xtd(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_check_box_xtd_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_check_box_xtd_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_xtd_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_check_box_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_xtd_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_check_box_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_flat_check_box(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_flat_check_box_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_flat_check_box_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_flat_check_box_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
}

void check_box_renderer::draw_flat_check_box_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
}

void check_box_renderer::draw_popup_check_box(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_popup_check_box_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_popup_check_box_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_popup_check_box_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
}

void check_box_renderer::draw_popup_check_box_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
}
