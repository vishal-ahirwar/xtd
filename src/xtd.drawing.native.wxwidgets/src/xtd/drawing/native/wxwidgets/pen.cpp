#include <map>
#include <vector>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/pen.h>
#include <xtd/drawing/native/line_caps.h>
#include <xtd/drawing/native/line_joins.h>
#include <xtd/drawing/native/toolkit.h>
#include "../../../../../include/xtd/drawing/native/wx_pen.h"
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <wx/colour.h>
#include <wx/pen.h>

using namespace std;
using namespace xtd::drawing::native;

intptr_t pen::create() {
  toolkit::initialize(); // Must be first
  return reinterpret_cast<intptr_t>(new wx_pen());
}

void pen::solid_color(intptr_t pen, uint8_t a, uint8_t r, uint8_t g, uint8_t b, float width, float dash_offset, vector<float> dashes) {
  vector<int8_t> wx_dashes;
  for (auto dash : dashes)
    wx_dashes.push_back(static_cast<int8_t>(dash));
  reinterpret_cast<wx_pen*>(pen)->create_solid_color_pen({r, g, b, a}, width, dash_offset, wx_dashes);
}

void pen::hatch_fill(intptr_t pen, intptr_t brush, float width) {
  reinterpret_cast<wx_pen*>(pen)->create_hatch_fill_pen(*reinterpret_cast<wx_brush*>(brush), width);
}

void pen::conical_gradient(intptr_t pen, intptr_t brush, float width) {
  reinterpret_cast<wx_pen*>(pen)->create_conical_gradient_pen(*reinterpret_cast<wx_brush*>(brush), width);
}

void pen::end_cap(intptr_t pen, int32_t line_cap) {
  switch (line_cap) {
    case LC_FLAT: reinterpret_cast<wx_pen*>(pen)->line_cap(wxPenCap::wxCAP_BUTT); break;
    case LC_SQUARE: reinterpret_cast<wx_pen*>(pen)->line_cap(wxPenCap::wxCAP_PROJECTING); break;
    case LC_ROUND: reinterpret_cast<wx_pen*>(pen)->line_cap(wxPenCap::wxCAP_ROUND); break;
    default: reinterpret_cast<wx_pen*>(pen)->line_cap(wxPenCap::wxCAP_BUTT); break;
  }
}

void pen::linear_gradient(intptr_t pen, intptr_t brush, float width) {
  reinterpret_cast<wx_pen*>(pen)->create_linear_gradient_pen(*reinterpret_cast<wx_brush*>(brush), width);
}

void pen::line_join(intptr_t pen, int32_t line_join) {
  switch (line_join) {
    case LJ_MITER: reinterpret_cast<wx_pen*>(pen)->line_join(wxPenJoin::wxJOIN_MITER); break;
    case LJ_BEVEL: reinterpret_cast<wx_pen*>(pen)->line_join(wxPenJoin::wxJOIN_BEVEL); break;
    case LJ_ROUND: reinterpret_cast<wx_pen*>(pen)->line_join(wxPenJoin::wxJOIN_ROUND); break;
    case LJ_MITER_CLIPPED: reinterpret_cast<wx_pen*>(pen)->line_join(wxPenJoin::wxJOIN_MITER); break;
    default: reinterpret_cast<wx_pen*>(pen)->line_join(wxPenJoin::wxJOIN_MITER); break;
  }
}

void pen::miter_limit(intptr_t pen, float miter_limit) {
  // WxWidgets has no mitter limit...
}

void pen::radial_gradient(intptr_t pen, intptr_t brush, float width) {
  reinterpret_cast<wx_pen*>(pen)->create_radial_gradient_pen(*reinterpret_cast<wx_brush*>(brush), width);
}

void pen::start_cap(intptr_t pen, int32_t line_cap) {
  switch (line_cap) {
    case LC_FLAT: reinterpret_cast<wx_pen*>(pen)->line_cap(wxPenCap::wxCAP_BUTT); break;
    case LC_SQUARE: reinterpret_cast<wx_pen*>(pen)->line_cap(wxPenCap::wxCAP_PROJECTING); break;
    case LC_ROUND: reinterpret_cast<wx_pen*>(pen)->line_cap(wxPenCap::wxCAP_ROUND); break;
    default: reinterpret_cast<wx_pen*>(pen)->line_cap(wxPenCap::wxCAP_BUTT); break;
  }
}

void pen::texture_fill(intptr_t pen, intptr_t brush, float width) {
  reinterpret_cast<wx_pen*>(pen)->create_texture_fill_pen(*reinterpret_cast<wx_brush*>(brush), width);
}

void pen::destroy(intptr_t pen) {
  delete reinterpret_cast<wx_pen*>(pen);
}

/*
intptr_t pen::create() {
  toolkit::initialize(); // Must be first
  auto pen = new wx_pen();
  pen->SetQuality(wxPenQuality::wxPEN_QUALITY_HIGH);
  pen->SetCap(wxPenCap::wxCAP_BUTT);
  return reinterpret_cast<intptr_t>(pen);
}

void pen::color(intptr_t pen, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  toolkit::initialize(); // Must be first
  reinterpret_cast<wxPen*>(pen)->SetColour(wxColour(r, g, b, a));
}

void pen::image(intptr_t pen, intptr_t image) {
  toolkit::initialize(); // Must be first
  reinterpret_cast<wx_pen*>(pen)->SetStyle(wxPenStyle::wxPENSTYLE_STIPPLE);
  reinterpret_cast<wx_pen*>(pen)->SetStipple(*reinterpret_cast<wxImage*>(image));
}

void pen::dash_pattern(intptr_t pen, std::vector<float> dash_pattern) {
  toolkit::initialize(); // Must be first
  reinterpret_cast<wx_pen*>(pen)->dashes.clear();
  for (auto dash : dash_pattern)
    reinterpret_cast<wx_pen*>(pen)->dashes.push_back(static_cast<wxDash>(dash));
  reinterpret_cast<wxPen*>(pen)->SetDashes(reinterpret_cast<wx_pen*>(pen)->dashes.size(), reinterpret_cast<wx_pen*>(pen)->dashes.data());
}

void pen::dash_style(intptr_t pen, uint32_t dash_style) {
  toolkit::initialize(); // Must be first
  reinterpret_cast<wx_pen*>(pen)->SetStyle(wxPENSTYLE_USER_DASH);
  switch (dash_style) {
    case 0: reinterpret_cast<wx_pen*>(pen)->dashes = {1}; break;
    case 1: reinterpret_cast<wx_pen*>(pen)->dashes = {3, 2}; break;
    case 2: reinterpret_cast<wx_pen*>(pen)->dashes = {1, 1}; break;
    case 3: reinterpret_cast<wx_pen*>(pen)->dashes = {3, 1, 1, 1}; break;
    case 4: reinterpret_cast<wx_pen*>(pen)->dashes = {3, 1, 1, 1, 1, 1}; break;
    default: break;
  }
  reinterpret_cast<wxPen*>(pen)->SetDashes(reinterpret_cast<wx_pen*>(pen)->dashes.size(), reinterpret_cast<wx_pen*>(pen)->dashes.data());
}

void pen::width(intptr_t pen, float width) {
  toolkit::initialize(); // Must be first
  reinterpret_cast<wxPen*>(pen)->SetWidth(static_cast<int>(width));
}

void pen::destroy(intptr_t pen) {
  delete reinterpret_cast<wx_pen*>(pen);
}
*/
