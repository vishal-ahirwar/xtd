#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    static void main() {
      application::run(form1());
    }
    
    form1() {
      text("Border style example");
      client_size({700, 170 + as<int>(20 + bordered_labels.size() / 4 * 70)});
      controls().push_back_range({colored_panel, control_panel});
      maximum_client_size(client_size());
      minimum_client_size(client_size());
      
      colored_panel.controls().push_back_range(bordered_labels);
      colored_panel.dock(dock_style::fill);
      
      for (auto index = 0UL; index < bordered_labels.size(); ++index) {
        bordered_labels[index].border_style(border_styles[index]);
        bordered_labels[index].bounds(rectangle(as<int>(20 + index % 4 * 170), as<int>(20 + index / 4 * 70), 150, 50));
        bordered_labels[index].text(convert::to_string(border_styles[index]));
        bordered_labels[index].text_align(content_alignment::middle_center);
      }
      
      control_panel.border_sides(border_sides::top);
      control_panel.border_style(border_style::etched);
      control_panel.controls().push_back_range({choose_color_label, colors_chooser, select_sides_label, top_side, left_side, bottom_side, right_side});
      control_panel.dock(dock_style::bottom);
      
      choose_color_label.auto_size(true);
      choose_color_label.location({20, 39});
      choose_color_label.text("Choose color");
      
      for (auto color : colors::get_colors())
        colors_chooser.items().push_back({color.name(), color});
      colors_chooser.items()[0] = {back_color().name(), back_color()}; // Replace transparent color by control color.
      colors_chooser.bounds({120, 37, 220, colors_chooser.default_size().height()});
      colors_chooser.selected_index(0);
      
      colors_chooser.selected_index_changed += [&] {
        auto color = as<drawing::color>(colors_chooser.selected_item().tag());
        colored_panel.back_color(color);
        colored_panel.fore_color(color.is_dark() ? control_paint::light(color, 2.0 / 3) : control_paint::dark(color, 2.0 / 3));
      };
      
      select_sides_label.auto_size(true);
      select_sides_label.location({380, 39});
      select_sides_label.text("Select sides");
      
      top_side.checked(true);
      top_side.flat_style(xtd::forms::flat_style::flat);
      top_side.checked(true);
      top_side.location({495, 15});
      top_side.size({50, 10});
      top_side.checked_changed += [&] {
        if (top_side.checked()) border_sides |= forms::border_sides::top;
        else border_sides &= ~forms::border_sides::top;
        for (auto& bordered_label : bordered_labels)
          bordered_label.border_sides(border_sides);
      };
      
      left_side.checked(true);
      left_side.flat_style(xtd::forms::flat_style::flat);
      left_side.location({480, 25});
      left_side.size({10, 50});
      left_side.checked_changed += [&] {
        if (left_side.checked()) border_sides |= forms::border_sides::left;
        else border_sides &= ~forms::border_sides::left;
        for (auto& bordered_label : bordered_labels)
          bordered_label.border_sides(border_sides);
      };
      
      right_side.checked(true);
      right_side.flat_style(xtd::forms::flat_style::flat);
      right_side.location({550, 25});
      right_side.size({10, 50});
      right_side.checked_changed += [&] {
        if (right_side.checked()) border_sides |= forms::border_sides::right;
        else border_sides &= ~forms::border_sides::right;
        for (auto& bordered_label : bordered_labels)
          bordered_label.border_sides(border_sides);
      };
      
      bottom_side.checked(true);
      bottom_side.flat_style(xtd::forms::flat_style::flat);
      bottom_side.location({495, 75});
      bottom_side.size({50, 10});
      bottom_side.checked_changed += [&] {
        if (bottom_side.checked()) border_sides |= forms::border_sides::bottom;
        else border_sides &= ~forms::border_sides::bottom;
        for (auto& bordered_label : bordered_labels)
          bordered_label.border_sides(border_sides);
      };
    }
    
  private:
    inline static const vector<border_style> border_styles {border_style::none, border_style::fixed_single, border_style::thin_sunken, border_style::thin_raised, border_style::bevel_sunken, border_style::bevel_raised, border_style::etched, border_style::bump, border_style::themed, border_style::rounded_single, border_style::dot_single, border_style::dash_single, border_style::dash_dot_single, border_style::dash_dot_dot_single, border_style::fixed_double};
    panel colored_panel;
    vector<label> bordered_labels {border_styles.size()};
    forms::border_sides border_sides = forms::border_sides::all;
    panel control_panel;
    label choose_color_label;
    choice colors_chooser;
    label select_sides_label;
    toggle_button top_side;
    toggle_button left_side;
    toggle_button bottom_side;
    toggle_button right_side;
  };
}

startup_(examples::form1);
