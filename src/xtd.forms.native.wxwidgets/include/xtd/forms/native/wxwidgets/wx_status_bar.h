#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <codecvt>
#include <xtd/argument_exception.h>
#include <xtd/convert_string.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/create_params.h>
#include <xtd/forms/native/status_bar_styles.h>
#include <wx/statusbr.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class status_bar;
      class wx_status_bar : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::status_bar;
      private:
        explicit wx_status_bar(const forms::create_params& create_params) {
          if (!create_params.parent()) throw xtd::argument_exception("control must have a parent"_t, current_stack_frame_);
          control_handler::create<wxStatusBar>(reinterpret_cast<control_handler*>(create_params.parent())->control(), wxID_ANY, style_to_wx_style(create_params.style(), create_params.ex_style()));
          #if defined(__WIN32__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = wxFULL_REPAINT_ON_RESIZE;
          
          if ((style & SBARS_SIZEGRIP) == SBARS_SIZEGRIP) wx_style |= wxSTB_SIZEGRIP;
          if ((style & SBARS_TOOLTIPS) == SBARS_TOOLTIPS) wx_style |= wxSTB_SHOW_TIPS;
          if ((style & SBARS_ELLIPSIZE) == SBARS_ELLIPSIZE) wx_style |= wxSTB_ELLIPSIZE_END;

          return wx_style;
        }
        
        std::vector<int> panel_styles;
        std::vector<wxString> panel_texts;
        std::vector<int> panel_widths;
      };
    }
  }
}
