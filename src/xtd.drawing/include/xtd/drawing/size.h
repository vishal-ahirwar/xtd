/// @file
/// @brief Contains xtd::drawing::size class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <ostream>
#include <xtd/object.h>
#include <xtd/ustring.h>
#include "../drawing_export.h"
#include "size_f.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class point;
    /// @endcond
    
    /// @brief Stores an ordered pair of integers, which specify a height and width.
    /// @code
    /// class drawing_export_ size : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::drawing::size
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    class drawing_export_ size : public xtd::object {
    public:
      /// @name Fields
      
      /// @{
      /// @brief Gets a xtd::drawing::size class that has a Height and Width value of 0. This field is constant.
      static const xtd::drawing::size empty;
      /// @}
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::drawing::size class that has a Height and Width value of 0.
      size() = default;
      /// @brief Initializes a new instance of the xtd::drawing::size class from the specified xtd::drawing::point class.
      /// @param point The xtd::drawing::point class from which to initialize this xtd::drawing::size class
      explicit size(const xtd::drawing::point& point) noexcept;
      /// @brief Initializes a new instance of the xtd::drawing::size class from the specified dimensions.
      /// @param width The width component of the new xtd::drawing::size.
      /// @param height The height component of the new xtd::drawing::size.
      size(int32_t width, int32_t height) noexcept;
      /// @}
      
      /// @cond
      size(const xtd::drawing::size&) noexcept = default;
      bool operator==(const xtd::drawing::size& value) const noexcept;
      bool operator!=(const xtd::drawing::size& value) const noexcept;
      size& operator=(const xtd::drawing::size& size) noexcept = default;
      size operator+(const xtd::drawing::size& size) const noexcept;
      size operator-(const xtd::drawing::size& size) const noexcept;
      size& operator+=(const xtd::drawing::size& size) noexcept;
      size& operator-=(const xtd::drawing::size& size) noexcept;
      operator size_f() const noexcept;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets he vertical component of this xtd::drawing::size class.
      /// @return The vertical component of this xtd::drawing::size class, typically measured in pixels.
      /// @remarks The unit for the xtd::drawing::size::height and xtd::drawing::size::width of the xtd::drawing::size class depend on the xtd::drawing::graphics:page_unit and xtd::drawing::graphics::page_scale settings for the xtd::drawing::::graphics object that is used to draw.
      int32_t height() const noexcept;
      /// @brief Sets the vertical component of this xtd::drawing::size class.
      /// @param value The vertical component of this xtd::drawing::size class, typically measured in pixels.
      /// @remarks The unit for the xtd::drawing::size::height and xtd::drawing::size::width of the xtd::drawing::size class depend on the xtd::drawing::graphics:page_unit and xtd::drawing::graphics::page_scale settings for the xtd::drawing::::graphics object that is used to draw.
      void height(int32_t value) noexcept;
      
      /// @brief Tests whether this xtd::drawing::size class has xtd::drawing::size_fwidth and xtd::drawing::size_fheight of 0.
      /// @return Returns true  when this xtd::drawing::size class has both a xtd::drawing::size::width and xtd::drawing::size::height of 0; otherwise, false.
      bool is_empty() const noexcept;
      
      /// @brief Gets the horizontal component of this xtd::drawing::size class.
      /// @return int The horizontal component of this xtd::drawing::size class, typically measured in pixels.
      /// @remarks The unit for the xtd::drawing::size::height and xtd::drawing::size::width of the xtd::drawing::size class depend on the xtd::drawing::graphics:page_unit and xtd::drawing::graphics::page_scale settings for the xtd::drawing::::graphics object that is used to draw.
      int32_t width() const noexcept;
      /// @brief Sets the horizontal component of this xtd::drawing::size class.
      /// @param value The horizontal component of this xtd::drawing::size class, typically measured in pixels.
      /// @remarks The unit for the xtd::drawing::size::height and xtd::drawing::size::width of the xtd::drawing::size class depend on the xtd::drawing::graphics:page_unit and xtd::drawing::graphics::page_scale settings for the xtd::drawing::::graphics object that is used to draw.
      void width(int32_t value) noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Adds the width and height of one xtd::drawing::size class to the width and height of another size class.
      /// @param size1 The first xtd::drawing::size class to add.
      /// @param size2 The second xtd::drawing::size class to add.
      /// @return xtd::drawing::size A xtd::drawing::size class that is the result of the addition operation.
      static size add(const size& size1, const size& size2) noexcept;
      
      /// @brief Converts the specified xtd::drawing::size_f to a xtd::drawing::size by rounding the values of the xtd::drawing::size_f to the next higher integer values.
      /// @param value The xtd::drawing::size_f to convert.
      /// @return The xtd::drawing::size this method converts to.
      static size ceiling(const size_f& value) noexcept;
      
      /// @brief Converts the specified xtd::drawing::size_f to a xtd::drawing::size object by rounding the xtd::drawing::size_f values to the nearest integer.
      /// @param value The xtd::drawing::size_f to convert.
      /// @return The xtd::drawing::size this method converts to.
      static size round(const size_f& value) noexcept;
      
      /// @brief Returns the result of subtracting specified xtd::drawing::size from the specified xtd::drawing::size.
      /// @param sz1 The xtd::drawing::size to be subtracted from.
      /// @param sz2 The xtd::drawing::size to subtract from the xtd::drawing::size.
      /// @return The xtd::drawing::size that is the result of the subtraction operation.
      static xtd::drawing::size subtract(const xtd::drawing::size& sz1, const xtd::drawing::size& sz2) noexcept;
      
      /// @brief Creates a human-readable string that represents this xtd::drawing::size class.
      /// @return A xtd::ustring that represents this xtd::drawing::size.
      xtd::ustring to_string() const noexcept override;
      
      /// @brief Converts the specified xtd::drawing::size_f to a xtd::drawing::size by truncating the values of the xtd::drawing::size_f.
      /// @param value The xtd::drawing::size_f to convert.
      /// @return The xtd::drawing::size this method converts to.
      static size truncate(const size_f& value) noexcept;
      /// @}
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::size& size) noexcept {return os << size.to_string();}
      /// @endcond
      
    private:
      int32_t width_ = 0;
      int32_t height_ = 0;
    };
  }
  
  /// @cond
  template<>
  inline drawing::size parse<drawing::size>(const std::string& str) {
    auto values = xtd::ustring(str).replace("}", "").replace(" height=", "").replace("{width=", "").split({','});
    return {xtd::parse<int32_t>(values[0]), xtd::parse<int32_t>(values[1])};
  }
  /// @endcond
}
