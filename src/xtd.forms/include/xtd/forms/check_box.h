/// @file
/// @brief Contains xtd::forms::check_box control.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "appearance.h"
#include "button_base.h"
#include "check_state.h"
#include "visual_styles/check_box_state.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows check_box.
    /// @code
    /// class forms_export_ check_box : public xtd::forms::button_base
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::forms::component → xtd::forms::control → xtd::forms::button_base → xtd::forms::check_box
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks Use a check_box to give the user an option, such as true/false or yes/no. The check_box control can display an image or text or both.
    /// @remarks check_box and radio_button controls have a similar function: they allow the user to choose from a list of options. check_box controls let the user pick a combination of options. In contrast, radio_button controls allow a user to choose from mutually exclusive options.
    /// @remarks The appearance property determines whether the check_box appears as a typical check_box or as a button.
    /// @remarks The three_state property determines whether the control supports two or three states. Use the checked property to get or set the value of a two-state check_box control and use the check_state property to get or set the value of a three-state check_box control.
    /// @note If the three_state property is set to true, the checked property will return true for either a checked or indeterminate state.
    /// @remarks The flat_style property determines the style and appearance of the control. If the flat_style property is set to flat_style::system, the user's operating system determines the appearance of the control.
    /// @note When the flat_style property is set to flat_style::system, the check_align property is ignored and the control is displayed using the content_alignment::middle_left or content_alignment::middle_right alignment. If the check_align property is set to one of the right alignments, the control is displayed using the content_alignment::middle_right alignment; otherwise, it is displayed using the content_alignment::middle_left alignment.
    /// @remarks The following describes an indeterminate state: You have a check_box that determines if the selected text in a rich_text_box is bold. When you select text you can click the check_box to bold the selection. Likewise, when you select some text, the check_box displays whether the selected text is bold. If your selected text contains text that is bold and normal, the check_box will have an indeterminate state.
    /// @par Appearance
    /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
    ///   <tr>
    ///     <th style="width:100px"></th>
    ///     <th><b>Windows</b></th>
    ///     <th><b>macOS</b></th>
    ///     <th><b>Gnome</b></th>
    ///   </tr>
    ///   <tr>
    ///     <th>Light</th>
    ///     <td>@image html control_check_box_w.png</td>
    ///     <td>@image html control_check_box_m.png</td>
    ///     <td>@image html control_check_box_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <th>Dark</th>
    ///     <td>@image html control_check_box_wd.png</td>
    ///     <td>@image html control_check_box_md.png</td>
    ///     <td>@image html control_check_box_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of check_box control.
    /// @include check_box.cpp
    class forms_export_ check_box : public xtd::forms::button_base {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the CheckBox class.
      /// @remarks By default, when a new check_box is instantiated, auto_check is set to true, checked is set to false, and appearance is set to normal.
      /// @par Examples
      /// The following code example demonstrates the use of check_box constructor.
      /// @include check_box.cpp
      check_box();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the value that determines the appearance of a check_box control.
      /// @return One of the appearance values. The default value is normal.
      /// @remarks If appearance value is set to normal, the check_box has a typical appearance. If the value is set to button, the check_box appears like a toggle button, which can be toggled to an up or down state.
      /// @par Examples
      /// The following code example demonstrates the use of check_box appearance.
      /// @include check_box.cpp
      virtual forms::appearance appearance() const {return data_->appearance;}
      /// @brief Gets the value that determines the appearance of a check_box control.
      /// @param appearance One of the appearance values. The default value is normal.
      /// @remarks If appearance value is set to normal, the check_box has a typical appearance. If the value is set to button, the check_box appears like a toggle button, which can be toggled to an up or down state.
      virtual check_box& appearance(forms::appearance appearance);
      
      /// @brief Gets a value indicating whether the checked or check_state values and the check_box's appearance are automatically changed when the check_box is clicked.
      /// @return true if the checked value or check_state value and the appearance of the control are automatically changed on the click event; otherwise, false. The default value is true.
      /// @remarks If auto_check is set to false, you will need to add code to update the checked or check_state values in the click event handler.
      /// @par Examples
      /// The following code example demonstrates the use of check_box auto_check.
      /// @include check_box.cpp
      virtual bool auto_check() const {return data_->auto_check;}
      /// @brief Sets a value indicating whether the checked or check_state values and the check_box's appearance are automatically changed when the check_box is clicked.
      /// @param auto_check true if the checked value or check_state value and the appearance of the control are automatically changed on the click event; otherwise, false. The default value is true.
      /// @remarks If auto_check is set to false, you will need to add code to update the checked or check_state values in the click event handler.
      virtual check_box& auto_check(bool auto_check);
      
      /// @brief Gets the horizontal and vertical alignment of the check mark on a check_box control.
      /// @return One of the content_alignment values. The default value is middle_left.
      virtual content_alignment check_align() const {return data_->check_align;}
      /// @brief Sets the horizontal and vertical alignment of the check mark on a check_box control.
      /// @param check_align One of the content_alignment values. The default value is middle_left.
      virtual check_box& check_align(content_alignment check_align);
      
      /// @brief Gets a value indicating whether the check_box is in the checked state.
      /// @return true if the check_box is in the checked state; otherwise, false. The default value is false. If the three_state property is set to true, the checked property will return true for either a checked or indeterminate check_state.
      /// @remarks When the value is true, the check_box portion of the control displays a check mark. If the appearance property is set to button, the control will appear sunken when checked is true and raised like a standard button when false.
      /// @par Examples
      /// The following code example demonstrates the use of check_box checked.
      /// @include check_box.cpp
      virtual bool checked() const {return data_->checked;}
      /// @brief Sets a value indicating whether the check_box is in the checked state.
      /// @param checked true if the check_box is in the checked state; otherwise, false. The default value is false.
      /// @remarks When the value is true, the check_box portion of the control displays a check mark. If the appearance property is set to button, the control will appear sunken when checked is true and raised like a standard button when false.
      virtual check_box& checked(bool checked);
      
      /// @brief Gets the state of the check_box.
      /// @return One of the check_state enumeration values. The default value is unchecked.
      /// @remarks If the three_state property is set to false, the check_state property value can only be set to check_state::indeterminate in code and not by u ser interaction.
      /// @remarks The following table describes the xtd::forms::appearance of the check_box control in its different states for the normal and button style control check_box::appearance.
      /// | Check_state   |  appearance::normal                                                    | appearance::button                     |
      /// |---------------|------------------------------------------------------------------------|----------------------------------------|
      /// | checked       | The check_box displays a check mark.                                   | The control appears sunken.            |
      /// | unchecked     | The CheckBox is empty.                                                 | The control appears raised.            |
      /// | indeterminate | The CheckBox displays a check mark and is shaded.                      | The control appears flat.              |
      /// @par Examples
      /// The following code example demonstrates the use of check_box check_state.
      /// @include check_box.cpp
      virtual forms::check_state check_state() const {return data_->check_state;}
      /// @brief Sets the state of the check_box.
      /// @param check_state One of the check_state enumeration values. The default value is unchecked.
      /// @remarks The following table describes the xtd::forms::appearance of the check_box control in its different states for the normal and button style control check_box::appearance.
      /// | Check_state   |  appearance::normal                                                    | appearance::button                |
      /// |--------------------|------------------------------------------------------------------------|----------------------------------------|
      /// | checked         | The check_box displays a check mark.                        | The control appears sunken. |
      /// | unchecked     | The CheckBox is empty.                                               | The control appears raised.   |
      /// | indeterminate | The CheckBox displays a check mark and is shaded. | The control appears flat.        |
      /// @par Examples
      /// The following code example demonstrates the use of check_box check_state.
      /// @include check_box.cpp
      virtual check_box& check_state(forms::check_state check_state);
      
      /// @brief Gets a value indicating whether the check_box will allow three check states rather than two.
      /// @return true if the check_box is able to display three check states; otherwise, false. The default value is false.
      /// @remarks If the three_state property is set to false, the check_state property value can only be set to the indeterminate value of xtd.forms.check_state in code and not by user interaction.
      /// @par Examples
      /// The following code example demonstrates the use of check_box three_state.
      /// @include check_box.cpp
      virtual bool three_state() const {return data_->three_state;}
      /// @brief Gets a value indicating whether the check_box will allow three check states rather than two.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false. The default value is false.
      /// @remarks If the three_state property is set to false, the check_state property value can only be set to the indeterminate value of xtd.forms.check_state in code and not by user interaction.
      virtual check_box& three_state(bool three_state);
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the value of the appearance property changes.
      /// @ingroup events
      /// @remarks For more information about handling events, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_handle_and_raise_events.md">Handling and Raising Events</a>.
      event<check_box, event_handler> appearance_changed;
      
      /// @brief Occurs when the value of the checked property changes.
      /// @ingroup events
      /// @remarks For more information about handling events, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_handle_and_raise_events.md">Handling and Raising Events</a>.
      event<check_box, event_handler> checked_changed;
      
      /// @brief Occurs when the value of the check_state property changes.
      /// @ingroup events
      /// @remarks For more information about handling events, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_handle_and_raise_events.md">Handling and Raising Events</a>.
      event<check_box, event_handler> check_state_changed;
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      /// @brief Gets state.
      /// @return One of xtd::forms::visual_styles::check_box_state values.
      xtd::forms::visual_styles::check_box_state state() const noexcept {return data_->state;}
      /// @}
      
      /// @name Protected methods
      
      /// @{
      /// @brief Gets the required creation parameters when the control handle is created.
      /// @return A create_params that contains the required creation parameters when the handle to the control is created.
      forms::create_params create_params() const override;
      
      /// @brief Measure this control.
      /// @return The drawing::size size of this control.
      /// @remarks This method is not relevant for this class.
      drawing::size measure_control() const override;
      
      /// @brief Raises the check_box::appearance_changed event.
      /// @param e An event_args that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The on_appearance_changed method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      virtual void on_appearance_changed(const event_args& e) {
        appearance_changed(*this, e);
        if (flat_style() != xtd::forms::flat_style::system) invalidate();
      }
      
      /// @brief Raises the check_box::checked_changed event.
      /// @param e An event_args that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The on_checked_changed method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      virtual void on_checked_changed(const event_args& e) {
        if (flat_style() != xtd::forms::flat_style::system && enabled()) {
          if (data_->check_state == xtd::forms::check_state::unchecked) data_->state = xtd::forms::visual_styles::check_box_state::unchecked_normal;
          else if (data_->check_state == xtd::forms::check_state::checked) data_->state = xtd::forms::visual_styles::check_box_state::checked_normal;
          else if (data_->check_state == xtd::forms::check_state::indeterminate) data_->state = xtd::forms::visual_styles::check_box_state::mixed_normal;
        }
        checked_changed(*this, e);
        if (flat_style() != xtd::forms::flat_style::system) invalidate();
      }
      
      /// @brief Raises the check_box::check_state_changed event.
      /// @param e An event_args that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The on_check_state_changed method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      virtual void on_check_state_changed(const event_args& e) {
        if (flat_style() != xtd::forms::flat_style::system && enabled()) {
          if (data_->check_state == xtd::forms::check_state::unchecked) data_->state = xtd::forms::visual_styles::check_box_state::unchecked_normal;
          else if (data_->check_state == xtd::forms::check_state::checked) data_->state = xtd::forms::visual_styles::check_box_state::checked_normal;
          else if (data_->check_state == xtd::forms::check_state::indeterminate) data_->state = xtd::forms::visual_styles::check_box_state::mixed_normal;
        }
        check_state_changed(*this, e);
        if (flat_style() != xtd::forms::flat_style::system) invalidate();
      }
      
      void on_enabled_changed(const event_args& e) override {
        if (flat_style() != xtd::forms::flat_style::system) {
          if (data_->check_state == xtd::forms::check_state::unchecked) data_->state = enabled() ? xtd::forms::visual_styles::check_box_state::unchecked_normal : xtd::forms::visual_styles::check_box_state::unchecked_disabled;
          else if (data_->check_state == xtd::forms::check_state::checked) data_->state = enabled() ? xtd::forms::visual_styles::check_box_state::checked_normal : xtd::forms::visual_styles::check_box_state::checked_disabled;
          else if (data_->check_state == xtd::forms::check_state::indeterminate) data_->state = enabled() ? xtd::forms::visual_styles::check_box_state::mixed_normal : xtd::forms::visual_styles::check_box_state::mixed_disabled;
        }
        button_base::on_enabled_changed(e);
      }
      
      void on_handle_created(const event_args& e) override;
      
      void on_mouse_down(const mouse_event_args& e) override {
        if (flat_style() != xtd::forms::flat_style::system && enabled()) {
          if (data_->check_state == xtd::forms::check_state::unchecked) data_->state = xtd::forms::visual_styles::check_box_state::unchecked_pressed;
          else if (data_->check_state == xtd::forms::check_state::checked) data_->state = xtd::forms::visual_styles::check_box_state::checked_pressed;
          else if (data_->check_state == xtd::forms::check_state::indeterminate) data_->state = xtd::forms::visual_styles::check_box_state::mixed_pressed;
        }
        button_base::on_mouse_down(e);
      }
      
      void on_mouse_enter(const event_args& e) override {
        if (flat_style() != xtd::forms::flat_style::system && enabled()) {
          if (data_->check_state == xtd::forms::check_state::unchecked) data_->state = (mouse_buttons() & mouse_buttons::left) == mouse_buttons::left ? xtd::forms::visual_styles::check_box_state::unchecked_pressed : xtd::forms::visual_styles::check_box_state::unchecked_hot;
          else if (data_->check_state == xtd::forms::check_state::checked) data_->state = (mouse_buttons() & mouse_buttons::left) == mouse_buttons::left ? xtd::forms::visual_styles::check_box_state::checked_pressed : xtd::forms::visual_styles::check_box_state::checked_hot;
          else if (data_->check_state == xtd::forms::check_state::indeterminate) data_->state = (mouse_buttons() & mouse_buttons::left) == mouse_buttons::left ? xtd::forms::visual_styles::check_box_state::mixed_pressed : xtd::forms::visual_styles::check_box_state::mixed_hot;
        }
        button_base::on_mouse_enter(e);
      }
      
      void on_mouse_leave(const event_args& e) override {
        if (flat_style() != xtd::forms::flat_style::system && enabled()) {
          if (data_->check_state == xtd::forms::check_state::unchecked) data_->state = xtd::forms::visual_styles::check_box_state::unchecked_normal;
          else if (data_->check_state == xtd::forms::check_state::checked) data_->state = xtd::forms::visual_styles::check_box_state::checked_normal;
          else if (data_->check_state == xtd::forms::check_state::indeterminate) data_->state = xtd::forms::visual_styles::check_box_state::mixed_normal;
        }
        button_base::on_mouse_leave(e);
      }
      
      void on_mouse_up(const mouse_event_args& e) override {
        if (flat_style() != xtd::forms::flat_style::system && enabled() && (data_->state == xtd::forms::visual_styles::check_box_state::unchecked_pressed || data_->state == xtd::forms::visual_styles::check_box_state::checked_pressed || data_->state == xtd::forms::visual_styles::check_box_state::mixed_pressed)) {
          if (data_->check_state == xtd::forms::check_state::unchecked) data_->state = xtd::forms::visual_styles::check_box_state::unchecked_hot;
          else if (data_->check_state == xtd::forms::check_state::checked) data_->state = xtd::forms::visual_styles::check_box_state::checked_hot;
          else if (data_->check_state == xtd::forms::check_state::indeterminate) data_->state = xtd::forms::visual_styles::check_box_state::mixed_hot;
        }
        button_base::on_mouse_up(e);
      }
      
      void on_paint(paint_event_args& e) override;
      /// @}
      
      /// @cond
      void wnd_proc(message& message) override;
      virtual void wm_mouse_double_click(message& message);
      virtual void wm_mouse_down(message& message);
      virtual void wm_mouse_up(message& message);
      /// @endcond
      
    private:
      struct data {
        forms::appearance appearance = forms::appearance::normal;
        bool auto_check = true;
        bool three_state = 0;
        bool checked = false;
        content_alignment check_align = content_alignment::middle_left;
        forms::check_state check_state = forms::check_state::unchecked;
        xtd::forms::visual_styles::check_box_state state = xtd::forms::visual_styles::check_box_state::unchecked_normal;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
