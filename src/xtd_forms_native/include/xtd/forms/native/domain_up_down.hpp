#pragma once
#include "../create_params.hpp"
#include <xtd/static.hpp>

namespace xtd {
  namespace forms {
    namespace native {
      class domain_up_down static_ {
      public:
        static void delete_item(intptr_t control, size_t pos);
        static void insert_item(intptr_t control, size_t pos, const std::string& value);
        static size_t selected_index(intptr_t control);
        static void selected_index(intptr_t control, size_t index);
        static void update_item(intptr_t control, size_t pos, const std::string& value);
      };
    }
  }
}
