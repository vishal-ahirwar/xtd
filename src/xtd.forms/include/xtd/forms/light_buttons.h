/// @file
/// @brief Contains xtd::forms::light_buttons factory.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "light_button.h"
#include "system_texts.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of light_button objects for use by a Windows Forms application.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrates the use of light_buttons control factory.
    /// @include light_buttons.cpp
    class light_buttons final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Create a system-defined light_button that represent abort light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> abort(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::abort(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent abort light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> abort(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::abort(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent about light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> about(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::about(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent about light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> about(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::about(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent actual size light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> actual_size(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::actual_size(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent actual size light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> actual_size(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::actual_size(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent add light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> add(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::add(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent add light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> add(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::add(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent alignment light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> alignment(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::alignment(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent alignment light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> alignment(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::alignment(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent align left light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> align_left(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::align_left(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent align left light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> align_left(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::align_left(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent align right light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> align_right(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::align_right(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent align right light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> align_right(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::align_right(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent apply light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> apply(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::apply(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent apply light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> apply(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::apply(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent ascending light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> ascending(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::ascending(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent ascending light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> ascending(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::ascending(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent back light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> back(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::back(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent back light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> back(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::back(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent bold light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> bold(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::bold(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent bold light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> bold(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::bold(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent bottom light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> bottom(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::bottom(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent bottom light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> bottom(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::bottom(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent cancel light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> cancel(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::cancel(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent cancel light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> cancel(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::cancel(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent CD-Rom light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> cdrom(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::cdrom(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent CD-Rom light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> cdrom(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::cdrom(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent centered light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> centered(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::centered(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent centered light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> centered(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::centered(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent clear light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> clear(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::clear(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent clear light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> clear(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::clear(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent close light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> close(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::close(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent close light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> close(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::close(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent color light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> color(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::color(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent color light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> color(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::color(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent contents light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> contents(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::contents(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent contents light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> contents(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::contents(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent convert light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> convert(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::convert(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent convert light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> convert(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::convert(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent copy light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> copy(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::copy(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent copy light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> copy(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::copy(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent customize light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> customize(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::customize(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent customize light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> customize(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::customize(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent cut light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> cut(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::cut(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent cut light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> cut(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::cut(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent delete light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> del(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::del(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent delete light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> del(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::del(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent descending light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> descending(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::descending(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent descending light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> descending(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::descending(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent down light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> down(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::down(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent down light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> down(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::down(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent edit light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> edit(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::edit(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent edit light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> edit(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::edit(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent execute light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> execute(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::execute(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent execute light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> execute(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::execute(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent file light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> file(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::file(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent file light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> file(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::file(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent find light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> find(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::find(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent find light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> find(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::find(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent first light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> first(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::first(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent first light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> first(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::first(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent floppy light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> floppy(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::floppy(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent floppy light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> floppy(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::floppy(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent font light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> font(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::font(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent font light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> font(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::font(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent forward light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> forward(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::forward(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent forward light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> forward(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::forward(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent hard disk light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> harddisk(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::harddisk(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent hard disk light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> harddisk(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::harddisk(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent help light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> help(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::help(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent help light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> help(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::help(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent home light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> home(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::home(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent home light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> home(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::home(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent ignore light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> ignore(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::ignore(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent ignore light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> ignore(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::ignore(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent indent light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> indent(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::indent(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent indent light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> indent(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::indent(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent index light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> index(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::index(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent index light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> index(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::index(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent info light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> info(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::info(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent info light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> info(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::info(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent italic light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> italic(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::italic(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent italic light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> italic(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::italic(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent justified light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> justified(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::justified(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent justified light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> justified(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::justified(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent jump_to light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> jump_to(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::jump_to(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent jump to light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> jump_to(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::jump_to(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent last light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> last(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::last(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent last light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> last(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::last(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent network light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> network(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::network(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent network light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> network(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::network(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent new light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> new_(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::new_(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent new light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> new_(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::new_(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent no light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> no(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::no(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent no light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> no(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::no(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent ok light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> ok(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::ok(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent ok light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> ok(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::ok(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent open light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> open(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::open(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent open light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> open(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::open(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent options light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> options(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::options(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent options light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> options(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::options(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent paste light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> paste(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::paste(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent paste light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> paste(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::paste(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent preferences light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> preferences(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::preferences(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent preferences light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> preferences(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::preferences(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent print light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> print(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::print(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent print light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> print(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::print(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent print preview light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> print_preview(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::print_preview(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent print preview light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> print_preview(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::print_preview(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent properties light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> properties(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::properties(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent properties light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> properties(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::properties(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent quit light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> quit(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::quit(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent quit light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> quit(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::quit(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent redo light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> redo(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::redo(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent redo light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> redo(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::redo(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent refresh light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> refresh(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::refresh(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent refresh light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> refresh(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::refresh(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent remove light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> remove(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::remove(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent remove light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> remove(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::remove(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent replace light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> replace(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::replace(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent replace light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> replace(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::replace(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent retry light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> retry(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::retry(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent retry light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> retry(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::retry(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent revert to saved light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> revert_to_saved(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::revert_to_saved(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent revert to saved light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> revert_to_saved(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::revert_to_saved(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent save light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> save(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::save(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent save light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> save(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::save(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent save as light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> save_as(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::save_as(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent save as light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> save_as(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::save_as(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent search light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> search(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::search(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent search light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> search(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::search(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent select all light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> select_all(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::select_all(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent select all light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> select_all(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::select_all(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent spell check light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> spell_check(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::spell_check(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent spell check light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> spell_check(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::spell_check(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent stop light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> stop(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::stop(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent stop light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> stop(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::stop(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent strikeout light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> strikeout(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::strikeout(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent strikeout light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> strikeout(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::strikeout(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent tools light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> tools(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::tools(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent tools light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> tools(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::tools(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent top light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> top(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::top(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent top light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> top(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::top(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent undelete light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> undelete(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::undelete(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent undelete light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> undelete(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::undelete(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent underline light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> underline(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::underline(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent underline light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> underline(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::underline(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent undo light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> undo(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::undo(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent undo light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> undo(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::undo(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represents an unindented light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> unindent(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::unindent(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represents an unindented light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> unindent(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::unindent(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent up light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> up(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::up(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent up light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> up(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::up(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent view light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> view(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::view(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent view light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> view(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::view(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent yes light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> yes(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::yes(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent yes light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> yes(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::yes(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent zoom in light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> zoom_in(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::zoom_in(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent zoom in light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> zoom_in(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::zoom_in(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent zoom out light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> zoom_out(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::zoom_out(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent zoom out light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> zoom_out(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::zoom_out(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent zoom to fit light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> zoom_to_fit(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(system_texts::zoom_to_fit(), location, size, back_color, fore_color);}
      /// @brief Create a system-defined light_button that represent zoom to fit light_button.
      /// @param parent The control that contains the light_button.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param back_color The light_button background color.
      /// @param fore_core The light_button foreground color.
      /// @return The created light_button.
      static std::unique_ptr<light_button> zoom_to_fit(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {return control::create<light_button>(parent, system_texts::zoom_to_fit(), location, size, back_color, fore_color);}
      /// @}
    };
  }
}
