#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/argument_exception.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/create_params.h>
#include <xtd/forms/native/track_bar_styles.h>
#include <wx/slider.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class track_bar;
      class wx_track_bar : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::track_bar;
      private:
        explicit wx_track_bar(const forms::create_params& create_params) {
          if (!create_params.parent()) throw xtd::argument_exception("control must have a parent"_t, current_stack_frame_);
          control_handler::create<wxSlider>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, 0, 0, 10, wxPoint(create_params.x(), create_params.y()), wxDefaultSize, style_to_wx_style(create_params.style(), create_params.ex_style()));
          control()->SetSize(wxSize(create_params.width(), create_params.height()));
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
          if ((style & TBS_VERT) == TBS_VERT) wx_style |= wxSL_VERTICAL | wxSL_INVERSE;
          else wx_style |= wxSL_HORIZONTAL;
          
          if ((style & TBS_BOTH) == TBS_BOTH) wx_style |= wxSL_BOTH;
          else if ((style & TBS_NOTICKS) != TBS_NOTICKS) {
            wx_style |= wxSL_AUTOTICKS;
            if ((style & TBS_VERT) == TBS_VERT) {
              if ((style & TBS_LEFT) == TBS_LEFT) wx_style |= wxSL_LEFT;
              else wx_style |= wxSL_RIGHT;
            } else {
              if ((style & TBS_TOP) == TBS_TOP) wx_style |= wxSL_TOP;
              else wx_style |= wxSL_BOTTOM;
            }
          }
          
          return wx_style;
        }
      };
    }
  }
}
