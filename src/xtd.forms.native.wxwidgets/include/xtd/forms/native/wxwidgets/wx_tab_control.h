#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <codecvt>
#include <xtd/argument_exception.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/create_params.h>
#include <xtd/forms/native/tab_control_styles.h>
#include <wx/bookctrl.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class tab_control;
      class wx_tab_control : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::tab_control;
      private:
        explicit wx_tab_control(const forms::create_params& create_params) {
          if (!create_params.parent()) throw xtd::argument_exception("control must have a parent"_t, current_stack_frame_);
          control_handler::create<wxNotebook>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
          #if defined(__WIN32__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;
          
          if ((style & WS_TABSTOP) != WS_TABSTOP) wx_style |= wxTAB_TRAVERSAL;
          if ((style & TCS_VERTICAL) != TCS_VERTICAL) {
            if ((style & TCS_BOTTOM) == TCS_BOTTOM) wx_style |= wxNB_BOTTOM;
            else wx_style |= wxNB_TOP;
          } else {
            if ((style & TCS_RIGHT) == TCS_RIGHT) wx_style |= wxNB_RIGHT;
            else wx_style |= wxNB_LEFT;
          }
          
          return wx_style;
        }
      };
    }
  }
}
