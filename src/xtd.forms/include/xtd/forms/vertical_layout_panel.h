/// @file
/// @brief Contains xtd::forms::vertical_layout_panel container.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "panel.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Used to group collections of verticaly alligned controls.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @par Examples
    /// The following code example demonstrate the use of vertical_layout_panel container.
    /// @include vertical_layout_panel.cpp
    /// @par Windows
    /// @image html vertical_layout_panel_w.png
    /// <br>
    /// @image html vertical_layout_panel_wd.png
    /// @par macOS
    /// @image html vertical_layout_panel_m.png
    /// <br>
    /// @image html vertical_layout_panel_md.png
    /// @par Gnome
    /// @image html vertical_layout_panel_g.png
    /// <br>
    /// @image html vertical_layout_panel_gd.png
    class vertical_layout_panel : public panel {
    protected:
      void on_layout(const xtd::event_args& e) override {
        panel::on_layout(e);
        if (controls().size() == 0) return;
        auto top = padding().top();
        auto left = padding().left();
        auto width = client_size().width() - padding().left() - padding().right();
        auto height = client_size().height() / controls().size() - padding().top() - padding().bottom();
        for (size_t index = 0; index < controls().size(); ++index) {
          controls()[index].get().set_bounds(left, top, width, height);
          top += height + padding().bottom() + padding().top();
        }
      }
    };
  }
}
