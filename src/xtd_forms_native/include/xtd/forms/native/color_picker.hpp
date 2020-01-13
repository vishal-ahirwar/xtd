#pragma once
#include "../create_params.hpp"
#include <xtd/static.hpp>
#include <xtd/drawing/color.hpp>

namespace xtd {
  namespace forms {
    namespace native {
      class color_picker static_ {
      public:
        static drawing::color color(intptr_t control);
        static void color(intptr_t control, const drawing::color& color);
      };
    }
  }
}
