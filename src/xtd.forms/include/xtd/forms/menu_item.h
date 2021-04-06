/// @file
/// @brief Contains xtd::forms::menu_item menu.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <string>
#include <xtd/drawing/image.h>
#include "menu.h"
#include "menu_item_kind.h"
#include "shortcut.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class main_menu;
    class context_menu;
    /// @endcond
  
    /// @brief Represents an individual item that is displayed within a main_menu or context_menu.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms menus_and_toolbars
    class forms_export_ menu_item : public xtd::forms::menu {
    public:
      /// @brief Initializes a menu_item with a blank caption.
      /// @remarks Once you have created a blank menu_item using this constructor, you can use the properties and methods of the menu_item class to specify the appearance and behavior of your menu_item.
      menu_item();
      /// @brief Initializes a new instance of the menu_item class with a specified caption for the menu item.
      /// @param text The caption for the menu item.
      menu_item(const std::string& text);
      menu_item(const std::string& text, xtd::forms::shortcut shortcut);
      menu_item(const std::string& text, const xtd::drawing::image& image);
      menu_item(const std::string& text, const xtd::drawing::image& image, xtd::forms::shortcut shortcut);
      menu_item(const std::string& text, xtd::forms::menu_item_kind kind);
      menu_item(const std::string& text, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut);
      menu_item(const std::string& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind);
      menu_item(const std::string& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut);
      menu_item(const std::string& text, xtd::forms::menu_item_kind kind, bool checked);
      menu_item(const std::string& text, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut);
      menu_item(const std::string& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked);
      menu_item(const std::string& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut);

      /// @brief Initializes a new instance of the class with a specified caption and event handler for the Click event of the menu item.
      /// @param text The caption for the menu item.
      /// @param on_click The event_handler that handles the Click event for this menu item.
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click);
      /// @brief Initializes a new instance of the class with a specified caption, event handler, and associated shortcut key for the menu item.
      /// @param text The caption for the menu item.
      /// @param on_click The event_handler that handles the Click event for this menu item.
      /// @param shortcut One of the xtd::forms::shortcut values.
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, xtd::forms::shortcut shortcut);
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, const xtd::drawing::image& image);
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, const xtd::drawing::image& image, xtd::forms::shortcut shortcut);
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, xtd::forms::menu_item_kind kind);
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut);
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind);
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut);
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, xtd::forms::menu_item_kind kind, bool checked);
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut);
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked);
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut);

      /// @cond
      template<typename delegate_type>
      menu_item(const std::string& text, delegate_type on_click) {menu_item(text, xtd::event_handler<xtd::forms::component&>(on_click));}
      template<typename delegate_type>
      menu_item(const std::string& text, delegate_type on_click, xtd::forms::shortcut shortcut) {menu_item(text, xtd::event_handler<xtd::forms::component&>(on_click), shortcut);}
      template<typename delegate_type>
      menu_item(const std::string& text, delegate_type on_click, const xtd::drawing::image& image) {menu_item(text, xtd::event_handler<xtd::forms::component&>(on_click), image);}
      template<typename delegate_type>
      menu_item(const std::string& text, delegate_type on_click, const xtd::drawing::image& image, xtd::forms::shortcut shortcut) {menu_item(text, xtd::event_handler<xtd::forms::component&>(on_click), image, shortcut);}
      template<typename delegate_type>
      menu_item(const std::string& text, delegate_type on_click, xtd::forms::menu_item_kind kind) {menu_item(text, xtd::event_handler<xtd::forms::component&>(on_click), kind);}
      template<typename delegate_type>
      menu_item(const std::string& text, delegate_type on_click, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut) {menu_item(text, xtd::event_handler<xtd::forms::component&>(on_click), kind, shortcut);}
      template<typename delegate_type>
      menu_item(const std::string& text, delegate_type on_click, xtd::forms::menu_item_kind kind, bool checked) {menu_item(text, xtd::event_handler<xtd::forms::component&>(on_click), kind, checked);}
      template<typename delegate_type>
      menu_item(const std::string& text, delegate_type on_click, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut) {menu_item(text, xtd::event_handler<xtd::forms::component&>(on_click), kind, checked, shortcut);}
      template<typename delegate_type>
      menu_item(const std::string& text, delegate_type on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked) {menu_item(text, xtd::event_handler<xtd::forms::component&>(on_click), image, kind, checked);}
      template<typename delegate_type>
      menu_item(const std::string& text, delegate_type on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut) {menu_item(text, xtd::event_handler<xtd::forms::component&>(on_click), image, kind, checked, shortcut);}
      /// @endcond

      menu_item(const std::string& text, const std::vector<menu_item>& items);

      int menu_id() const;
      const std::string& text() const {return text_;}
      
    protected:
      friend main_menu;
      friend context_menu;

      intptr_t create_menu_handle() override;
      void destroy_menu_handle(intptr_t handle) override;

      /// @cond
      std::string text_;
      xtd::drawing::image image_ = xtd::drawing::image::empty;
      xtd::forms::menu_item_kind kind_ = xtd::forms::menu_item_kind::normal;
      bool checked_ = false;
      xtd::forms::shortcut shortcut_ = static_cast<xtd::forms::shortcut>(0);
      /// @endcond
    };
  }
}
