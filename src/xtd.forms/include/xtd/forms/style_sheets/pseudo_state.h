/// @file
/// @brief Contains xtd::forms::style_sheets::pseudo_state enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The pseudo_state enum class flag specifies the pseudo state of an element.
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      enum class pseudo_state {
        /// @brief The item is in standard state.
        standard,
        /// @brief The item is hover (mouse is on the item).
        hover = 0b1,
        /// @brief The irem is pressed, mouse is down on the item.
        pressed = 0b10,
        /// @brief The irem is disabled, generally the item is grayed.
        disabled = 0b100,
        /// @brief The item is focused.
        focused = 0b1000,
        /// @brief The item is the default (see ibutton_control).
        default_state = 0b10000,
        /// @brief The item is unchecked.
        unchecked = standard,
        /// @brief The item is checked.
        checked = 0b100000,
        /// @brief The item is mixed. For the three-state ittem.
        mixed = 0b1000000,
      };
      
      /// @cond
      inline pseudo_state& operator +=(pseudo_state& lhs, pseudo_state rhs) {lhs = static_cast<pseudo_state>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs;}
      inline pseudo_state& operator -=(pseudo_state& lhs, pseudo_state rhs) {lhs = static_cast<pseudo_state>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs;}
      inline pseudo_state& operator &=(pseudo_state& lhs, pseudo_state rhs) {lhs = static_cast<pseudo_state>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs;}
      inline pseudo_state& operator |=(pseudo_state& lhs, pseudo_state rhs) {lhs = static_cast<pseudo_state>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs;}
      inline pseudo_state& operator ^=(pseudo_state& lhs, pseudo_state rhs) {lhs = static_cast<pseudo_state>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs;}
      inline pseudo_state operator +(pseudo_state lhs, pseudo_state rhs) {return static_cast<pseudo_state>(static_cast<long long>(lhs) + static_cast<long long>(rhs));}
      inline pseudo_state operator -(pseudo_state lhs, pseudo_state rhs) {return static_cast<pseudo_state>(static_cast<long long>(lhs) - static_cast<long long>(rhs));}
      inline pseudo_state operator ~(pseudo_state rhs) {return static_cast<pseudo_state>(~static_cast<long long>(rhs));}
      inline pseudo_state operator &(pseudo_state lhs, pseudo_state rhs) {return static_cast<pseudo_state>(static_cast<long long>(lhs) & static_cast<long long>(rhs));}
      inline pseudo_state operator |(pseudo_state lhs, pseudo_state rhs) {return static_cast<pseudo_state>(static_cast<long long>(lhs) | static_cast<long long>(rhs));}
      inline pseudo_state operator ^(pseudo_state lhs, pseudo_state rhs) {return static_cast<pseudo_state>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs));}
      inline std::ostream& operator<<(std::ostream& os, const pseudo_state value) {return os << to_string(value, {{pseudo_state::standard, "standard"}, {pseudo_state::hover, "hover"}, {pseudo_state::pressed, "pressed"}, {pseudo_state::disabled, "disabled"}, {pseudo_state::focused, "focused"}, {pseudo_state::default_state, "default_state"}, {pseudo_state::unchecked, "unchecked"}, {pseudo_state::checked, "checked"}, {pseudo_state::mixed, "mixed"}});}
      inline std::wostream& operator<<(std::wostream& os, const pseudo_state value) {return os << to_string(value, {{pseudo_state::standard, L"standard"}, {pseudo_state::hover, L"hover"}, {pseudo_state::pressed, L"pressed"}, {pseudo_state::disabled, L"disabled"}, {pseudo_state::focused, L"focused"}, {pseudo_state::default_state, L"default_state"}, {pseudo_state::unchecked, L"unchecked"}, {pseudo_state::checked, L"checked"}, {pseudo_state::mixed, L"mixed"}});}
      /// @endcond
    }
  }
}
