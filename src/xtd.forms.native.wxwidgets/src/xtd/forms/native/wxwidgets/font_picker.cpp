#include <xtd/argument_exception.h>
#include <xtd/drawing/system_fonts.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/font_picker.h>
#include <xtd/forms/native/content_alignment.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_font_picker.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

color font_picker::color(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return {};
  }
  wxColour colour = static_cast<wxFontPickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetSelectedColour();
  return color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
}

void font_picker::color(intptr_t control, const drawing::color& color) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxFontPickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetSelectedColour(wxColour(color.r(), color.g(), color.b(), color.a()));
}

font font_picker::font(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return system_fonts::default_font();
  }
  return drawing::font::from_hfont(reinterpret_cast<intptr_t>(new wxFont(static_cast<wxFontPickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetSelectedFont())));
}

void font_picker::font(intptr_t control, const drawing::font& font) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxFontPickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetSelectedFont(*reinterpret_cast<wxFont*>(font.handle()));
}
