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
#include <xtd/forms/native/static_styles.h>
#include <wx/bookctrl.h>
#include <wx/panel.h>
#include <wx/scrolwin.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class tab_page;
      class wx_tab_page : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::tab_page;
      private:
        explicit wx_tab_page(const forms::create_params& create_params) {
          if (!create_params.parent()) throw xtd::argument_exception("control must have a parent"_t, current_stack_frame_);
          if ((create_params.ex_style() & WS_EX_AUTOSCROLL) == WS_EX_AUTOSCROLL)
            control_handler::create<wxScrolled<wxPanel>>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, wxDefaultPosition, wxDefaultSize, style_to_wx_style(create_params.style(), create_params.ex_style()));
          else
            control_handler::create<wxPanel>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, wxDefaultPosition, wxDefaultSize, style_to_wx_style(create_params.style(), create_params.ex_style()));
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
          if ((style & WS_HSCROLL) == WS_HSCROLL) wx_style |= wxHSCROLL;
          if ((style & WS_VSCROLL) == WS_VSCROLL) wx_style |= wxVSCROLL;
          if (((style & WS_HSCROLL) == WS_HSCROLL || (style & WS_VSCROLL) == WS_VSCROLL) && (ex_style & WS_EX_AUTOSCROLL) != WS_EX_AUTOSCROLL) wx_style |= wxALWAYS_SHOW_SB;
          
          if ((style & WS_BORDER) == WS_BORDER) wx_style |= wxBORDER_SIMPLE;
          else if ((ex_style & WS_EX_CLIENTEDGE) == WS_EX_CLIENTEDGE) wx_style |= wxBORDER_THEME;
          else wx_style |= wxBORDER_NONE;
          
          return wx_style;
        }
        
        wxSize GetClientSize() const override {
          return control()->GetSize();
        }
        
        void SetClientSize(int32_t width, int32_t height) override {
          SetSize(width, height);
        }
      };
    }
  }
}
