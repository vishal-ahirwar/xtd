/// @file
/// @brief Contains xtd::forms::control_event_args event args.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <xtd/event_args.h>
#include <xtd/drawing/point.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond
    
    /// @brief Provides data for the control_added and control_removed events.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class control_event_args : public event_args {
    public:
      /// @cond
      control_event_args(const control_event_args& control_event_args) = default;
      control_event_args& operator=(const control_event_args& control_event_args) = default;
      /// @endcond
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the control_event_args class for the specified control.
      /// @param control The control to store in this event.
      explicit control_event_args(const forms::control& control) : control_(&control) {}
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the control object used by this event.
      /// @return The control used by this event.
      const forms::control& control() const {return *control_;}
      //// @}
      
    private:
      const forms::control* control_ = nullptr;
    };
  }
}
