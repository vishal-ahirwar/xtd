#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <wx/slider.h>
#include "control_handler.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_track_bar : public control_handler {
      public:
        wx_track_bar(const forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<wxSlider>(reinterpret_cast<control_handler*>(create_params.parent())->control(), wxID_ANY, 0, 0, 10, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), control_handler::track_bar_to_wx_style(create_params.style(), create_params.ex_style()));
        }
      };
    }
  }
}
