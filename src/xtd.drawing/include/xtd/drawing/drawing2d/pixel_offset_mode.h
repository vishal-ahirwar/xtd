/// @file
/// @brief Contains xtd::drawing::drawing2d::pixel_offset_mode enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::drawing2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing2d {
      /// @brief Specifies how pixels are offset during rendering.
      /// @par Namespace
      /// xtd::drawing::drawing2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      /// @rremarks By offsetting pixels during rendering, you can improve render quality at the cost of render speed.
      enum class pixel_offset_mode {
        /// @brief Specifies the default mode.
        invalid = -1,
        /// @brief Specifies default mode.
        default_value = 0,
        /// @brief Specifies high speed, low quality rendering.
        high_speed = 1,
        /// @brief Specifies high quality, low speed rendering.
        high_quality = 2,
        /// @brief Specifies no pixel offset.
        none = 3,
        /// @brief Specifies that pixels are offset by -.5 units, both horizontally and vertically, for high speed antialiasing.
        half = 4,
      };
      
      /// @cond
      inline std::ostream& operator<<(std::ostream& os, pixel_offset_mode value) {return os << to_string(value, {{pixel_offset_mode::invalid, "invalid"}, {pixel_offset_mode::default_value, "default_value"}, {pixel_offset_mode::high_speed, "high_speed"}, {pixel_offset_mode::high_quality, "high_quality"}, {pixel_offset_mode::none, "none"}, {pixel_offset_mode::half, "half"}});}
      inline std::wostream& operator<<(std::wostream& os, pixel_offset_mode value) {return os << to_string(value, {{pixel_offset_mode::invalid, L"invalid"}, {pixel_offset_mode::default_value, L"default_value"}, {pixel_offset_mode::high_speed, L"high_speed"}, {pixel_offset_mode::high_quality, L"high_quality"}, {pixel_offset_mode::none, L"none"}, {pixel_offset_mode::half, L"half"}});}
      /// @endcond
    }
  }
}
