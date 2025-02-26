#include <xtd/argument_exception.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/command_link_button.h>
#include <xtd/forms/native/content_alignment.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_command_link_button.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms::native;

void command_link_button::image(intptr_t control, const drawing::image& image) {
  if (!control || !wxTheApp || !image.handle()) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxButton*>(reinterpret_cast<control_handler*>(control)->control())->SetBitmapLabel(wxBitmap(*reinterpret_cast<wxImage*>(image.handle())));
}

void command_link_button::image_align(intptr_t control, uint32_t align) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  switch (align) {
    case CA_TOPLEFT: static_cast<wxCommandLinkButton*>(reinterpret_cast<wx_command_link_button*>(control)->control())->SetBitmapPosition(wxLEFT); break;
    case CA_TOPCENTER: static_cast<wxCommandLinkButton*>(reinterpret_cast<wx_command_link_button*>(control)->control())->SetBitmapPosition(wxTOP); break;
    case CA_TOPRIGHT: static_cast<wxCommandLinkButton*>(reinterpret_cast<wx_command_link_button*>(control)->control())->SetBitmapPosition(wxRIGHT); break;
    case CA_MIDDLELEFT: static_cast<wxCommandLinkButton*>(reinterpret_cast<wx_command_link_button*>(control)->control())->SetBitmapPosition(wxLEFT); break;
    case CA_MIDDLECENTER: break;
    case CA_MIDDLERIGHT: static_cast<wxCommandLinkButton*>(reinterpret_cast<wx_command_link_button*>(control)->control())->SetBitmapPosition(wxRIGHT); break;
    case CA_BOTTOMLEFT: static_cast<wxCommandLinkButton*>(reinterpret_cast<wx_command_link_button*>(control)->control())->SetBitmapPosition(wxDirection::wxLEFT); break;
    case CA_BOTTOMCENTER: static_cast<wxCommandLinkButton*>(reinterpret_cast<wx_command_link_button*>(control)->control())->SetBitmapPosition(wxBOTTOM); break;
    case CA_BOTTOMRIGHT: static_cast<wxCommandLinkButton*>(reinterpret_cast<wx_command_link_button*>(control)->control())->SetBitmapPosition(wxDirection::wxRIGHT); break;
  }
}
