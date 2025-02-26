/// @file
/// @brief Contains xtd::drawing::drawing2d::matrix_order enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::drawing2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing2d {
      /// @brief Specifies the order for matrix transform operations.
      /// @par Namespace
      /// xtd::drawing::drawing2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      /// @remarks Matrix transform operations are not necessarily commutative. The order in which they are applied is important.
      enum class matrix_order {
        /// @brief The new operation is applied before the old operation.
        prepend = 0,
        /// @brief The new operation is applied after the old operation.
        append = 1,
      };
      
      /// @cond
      inline std::ostream& operator<<(std::ostream& os, matrix_order value) {return os << to_string(value, {{matrix_order::prepend, "prepend"}, {matrix_order::append, "append"}});}
      inline std::wostream& operator<<(std::wostream& os, matrix_order value) {return os << to_string(value, {{matrix_order::prepend, L"prepend"}, {matrix_order::append, L"append"}});}
      /// @endcond
    }
  }
}
