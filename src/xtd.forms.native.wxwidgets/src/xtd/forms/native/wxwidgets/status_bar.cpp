#include <xtd/argument_exception.h>
#include <xtd/diagnostics/stopwatch.h>
#include <xtd/cdebug.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/status_bar.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_status_bar.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  int to_wx_style(int style) {
    switch (style) {
      case 3: return wxSB_SUNKEN;
      case 2: return wxSB_RAISED;
      case 1:
      default: return wxSB_NORMAL;
    }
  }
}

intptr_t status_bar::add_status_bar_panel(intptr_t status_bar, int border_style, const xtd::ustring& text, const xtd::ustring& tool_tip_text, const xtd::drawing::image& image, bool visible, int width, bool stretchable) {
  if (!status_bar || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(status_bar)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(status_bar)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.push_back(to_wx_style(border_style));
  reinterpret_cast<wx_status_bar*>(status_bar)->panel_texts.push_back(convert_string::to_wstring(text));
  reinterpret_cast<wx_status_bar*>(status_bar)->panel_widths.push_back(stretchable ? -1 : width);

  int count = static_cast<int>(reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.size());
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetFieldsCount(count);
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetStatusStyles(count, reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.data());
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetStatusText(reinterpret_cast<wx_status_bar*>(status_bar)->panel_texts[static_cast<int>(reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.size())], count - 1);
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetStatusWidths(count, reinterpret_cast<wx_status_bar*>(status_bar)->panel_widths.data());
  return static_cast<intptr_t>(count - 1);
}

intptr_t status_bar::add_status_bar_control(intptr_t status_bar, intptr_t control, const xtd::ustring& text) {
  if (!status_bar || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(status_bar)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(status_bar)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  if (control && !dynamic_cast<wxControl*>(reinterpret_cast<control_handler*>(control)->control())) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(status_bar)->control() == 0, "Must be a control", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.push_back(wxSB_NORMAL);
  reinterpret_cast<wx_status_bar*>(status_bar)->panel_texts.push_back(wxEmptyString);
  reinterpret_cast<wx_status_bar*>(status_bar)->panel_widths.push_back(0);
  
  int count = static_cast<int>(reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.size());
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetFieldsCount(count);
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetStatusStyles(count, reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.data());
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetStatusText(reinterpret_cast<wx_status_bar*>(status_bar)->panel_texts[static_cast<int>(reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.size())], count - 1);
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetStatusWidths(count, reinterpret_cast<wx_status_bar*>(status_bar)->panel_widths.data());
  return static_cast<intptr_t>(count - 1);
}

bool status_bar::set_system_status_bar(intptr_t control, intptr_t status_bar) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (status_bar != 0 && !dynamic_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())) throw argument_exception("dialog can't have tool bar"_t, current_stack_frame_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return false;
  }

  if (status_bar == 0) {
    static_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())->SetStatusBar(nullptr);
    return true;
  }

  if (static_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())->GetStatusBar() == nullptr)
    static_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())->SetStatusBar(static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control()));
  return true;
}

void status_bar::update_status_bar_item(intptr_t status_bar, intptr_t handle, int border_style, const xtd::ustring& text, const xtd::ustring& tool_tip_text, const xtd::drawing::image& image, bool visible, int width, bool stretchable) {
  if (!status_bar || !handle || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(status_bar)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(status_bar)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }

  if (static_cast<size_t>(handle) > reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.size() - 1) throw argument_exception(csf_);

  reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.push_back(to_wx_style(border_style));
  reinterpret_cast<wx_status_bar*>(status_bar)->panel_texts.push_back(convert_string::to_wstring(text));
  reinterpret_cast<wx_status_bar*>(status_bar)->panel_widths.push_back(stretchable ? -1 : width);
  
  int count = static_cast<int>(reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.size());
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetFieldsCount(count);
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetStatusStyles(count, reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.data());
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetStatusText(reinterpret_cast<wx_status_bar*>(status_bar)->panel_texts[static_cast<int>(reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.size())], static_cast<int>(handle));
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetStatusWidths(count, reinterpret_cast<wx_status_bar*>(status_bar)->panel_widths.data());
}
