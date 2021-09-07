/// @file
/// @brief Contains xtd::convert class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <any>
#include "static.h"
#include "types.h"
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents API to convert base type code.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks This class cannot be inherited.
  class convert static_ {
  public:
    /// @brief Convert std::any to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    /// @par Examples
    /// @code
    /// std::any value = true;
    /// bool result = convert::to_boolean(value);
    /// @endcode
    /// @exception xtd::invalid_cast_exception the parameters is bad cast.
    static bool to_boolean(std::any value);
    /// @brief Convert bool to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    /// @code
    /// bool value = true;
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(bool value) noexcept;
    /// @brief Convert byte_t to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    /// @code
    /// byte_t value = 42;
    /// bool result = convert::to_boolean(value);
    /// @endcode
    static bool to_boolean(byte_t value) noexcept;
    /// @brief Convert char to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    /// @code
    /// char value = 'a';
    /// bool result = convert::to_boolean(value);
    /// @endcode
    /// @exception xtd::invalid_cast_exception throw always exception.
    static bool to_boolean(char value);
    /// @brief Convert char8_t to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    /// @code
    /// char8_t value = u8'a';
    /// bool result = convert::to_boolean(value);
    /// @endcode
    /// @exception xtd::invalid_cast_exception throw always exception.
    static bool to_boolean(char8_t value);
    /// @brief Convert char16_t to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    /// @code
    /// char16_t value = u'a';
    /// bool result = convert::to_boolean(value);
    /// @endcode
    /// @exception xtd::invalid_cast_exception throw always exception.
    static bool to_boolean(char16_t value);
    /// @brief Convert char32_t to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    /// @code
    /// char32_t value = U'a';
    /// bool result = convert::to_boolean(value);
    /// @endcode
    /// @exception xtd::invalid_cast_exception throw always exception.
    static bool to_boolean(char32_t value);
    /// @brief Convert wchar_t to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    /// @code
    /// wchar_t value = L'a';
    /// bool result = convert::to_boolean(value);
    /// @endcode
    /// @exception xtd::invalid_cast_exception throw always exception.
    static bool to_boolean(wchar_t value);
    /// @brief Convert decimal_t to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    /// @code
    /// decimal_t value = 42.50l;
    /// bool result = convert::to_boolean(value);
    /// @endcode
    /// @remarks The result is rounded.
    /// @exception xtd::overflow_exception value represents a number that is greater than std::numric_limit<byte_t>::max() or is less than 0.
    static bool to_boolean(decimal_t value) noexcept;
    /// @brief Convert double to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(double value) noexcept;
    /// @brief Convert float to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(float value) noexcept;
    /// @brief Convert int16_t to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(int16_t value) noexcept;
    /// @brief Convert int32_t to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(int32_t value) noexcept;
    /// @brief Convert int64_t to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(int64_t value) noexcept;
    /// @brief Convert llong_t to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(llong_t value) noexcept;
    /// @brief Convert sbyte_t to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(sbyte_t value) noexcept;
    /// @brief Convert uint16_t to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(uint16_t value) noexcept;
    /// @brief Convert uint32_t to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(uint32_t value) noexcept;
    /// @brief Convert uint64_t to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(uint64_t value) noexcept;
    /// @brief Convert llong_t to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(ullong_t value) noexcept;
    /// @brief Convert string to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(const xtd::ustring& value);
    /// @brief Convert string to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(const std::string& value);
    /// @brief Convert string to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(const std::u8string& value);
    /// @brief Convert string to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(const std::u16string& value);
    /// @brief Convert string to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(const std::u32string& value);
    /// @brief Convert string to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(const std::wstring& value);
    /// @brief Convert string to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(const char* value);
    /// @brief Convert string to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(char* value);
    /// @brief Convert string to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(const char8_t* value);
    /// @brief Convert string to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(char8_t* value);
    /// @brief Convert string to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(const char16_t* value);
    /// @brief Convert string to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(char16_t* value);
    /// @brief Convert string to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(const char32_t* value);
    /// @brief Convert string to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(char32_t* value);
    /// @brief Convert string to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(const wchar_t* value);
    /// @brief Convert string to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static bool to_boolean(wchar_t* value);
    /// @brief Convert type_t to bool.
    /// @param value object to convert
    /// @return A new bool object converted from value
    template<typename type_t>
    static bool to_boolean(type_t value) {
      return static_cast<bool>(value);
    }

    /// @brief Convert std::any to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(std::any value);
    /// @brief Convert bool to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(bool value) noexcept;
    /// @brief Convert byte_t to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(byte_t value) noexcept;
    /// @brief Convert char to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(char value) noexcept;
    /// @brief Convert char8_t to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(char8_t value) noexcept;
    /// @brief Convert char16_t to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(char16_t value);
    /// @brief Convert char32_t to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(char32_t value);
    /// @brief Convert char32_t to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(wchar_t value);
    /// @brief Convert decimal_t to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(decimal_t value);
    /// @brief Convert double to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(double value);
    /// @brief Convert float to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(float value);
    /// @brief Convert int16_t to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(int16_t value);
    /// @brief Convert int32_t to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(int32_t value);
    /// @brief Convert int64_t to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(int64_t value);
    /// @brief Convert llong_t to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(llong_t value);
    /// @brief Convert sbyte_t to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(sbyte_t value);
    /// @brief Convert uint16_t to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(uint16_t value);
    /// @brief Convert uint32_t to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(uint32_t value);
    /// @brief Convert uint64_t to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(uint64_t value);
    /// @brief Convert llong_t to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(ullong_t value);
    /// @brief Convert string to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(const xtd::ustring& value);
    /// @brief Convert string to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(const std::string& value);
    /// @brief Convert string to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(const std::u8string& value);
    /// @brief Convert string to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(const std::u16string& value);
    /// @brief Convert string to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(const std::u32string& value);
    /// @brief Convert string to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(const std::wstring& value);
    /// @brief Convert string to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(const char* value);
    /// @brief Convert string to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(char* value);
    /// @brief Convert string to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(const char8_t* value);
    /// @brief Convert string to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(char8_t* value);
    /// @brief Convert string to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(const char16_t* value);
    /// @brief Convert string to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(char16_t* value);
    /// @brief Convert string to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(const char32_t* value);
    /// @brief Convert string to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(char32_t* value);
    /// @brief Convert string to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(const wchar_t* value);
    /// @brief Convert string to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    static byte_t to_byte(wchar_t* value);
    /// @brief Convert type_t to byte.
    /// @param value object to convert
    /// @return A new bool object converted from value
    template<typename type_t>
    static byte_t to_byte(type_t value) {
      return static_cast<byte_t>(value);
    }
  };
}
