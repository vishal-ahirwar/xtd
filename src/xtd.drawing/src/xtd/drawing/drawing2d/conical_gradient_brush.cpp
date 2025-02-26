#include "../../../../include/xtd/drawing/drawing2d/conical_gradient_brush.h"
#include <xtd/argument_exception.h>
#include <xtd/as.h>
#include <tuple>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/brush.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;

conical_gradient_brush::conical_gradient_brush() : conical_gradient_brush(point_f(.0f, .0f), {color::transparent, color::transparent}, .0f) {
}

conical_gradient_brush::conical_gradient_brush(const xtd::drawing::point& center, const xtd::drawing::color& color1, const xtd::drawing::color& color2) : conical_gradient_brush(point_f(as<float>(center.x()), as<float>(center.y())), {color1, color2}, .0f) {
}

conical_gradient_brush::conical_gradient_brush(const xtd::drawing::point_f& center, const xtd::drawing::color& color1, const xtd::drawing::color& color2) : conical_gradient_brush(center, {color1, color2}, .0f) {
}

conical_gradient_brush::conical_gradient_brush(const xtd::drawing::point& center, const xtd::drawing::color& color1, const xtd::drawing::color& color2, float angle) : conical_gradient_brush(point_f(as<float>(center.x()), as<float>(center.y())), {color1, color2}, angle) {
}

conical_gradient_brush::conical_gradient_brush(const xtd::drawing::point_f& center, const xtd::drawing::color& color1, const xtd::drawing::color& color2, float angle) : conical_gradient_brush(center, {color1, color2}, angle) {
}

conical_gradient_brush::conical_gradient_brush(const xtd::drawing::point& center, const std::vector<xtd::drawing::color>& conical_colors) : conical_gradient_brush(point_f(as<float>(center.x()), as<float>(center.y())), conical_colors) {
}

conical_gradient_brush::conical_gradient_brush(const xtd::drawing::point_f& center, const std::vector<xtd::drawing::color>& conical_colors) : conical_gradient_brush(center, conical_colors, .0f) {
}

conical_gradient_brush::conical_gradient_brush(const xtd::drawing::point& center, const std::vector<xtd::drawing::color>& conical_colors,  float angle) : conical_gradient_brush(point_f(as<float>(center.x()), as<float>(center.y())), conical_colors, angle) {
}

conical_gradient_brush::conical_gradient_brush(const xtd::drawing::point_f& center, const std::vector<xtd::drawing::color>& conical_colors, float angle) {
  if (conical_colors.size() < 2) throw argument_exception(csf_);
  
  data_->center_point = center;
  data_->angle = angle;
  float pos = 0;
  float increment = 1.0f / (conical_colors.size() - 1);
  for (auto color : conical_colors) {
    data_->conical_colors.push_back({color, pos});
    pos += increment;
  }
  recreate_handle();
}

float conical_gradient_brush::angle() const noexcept {
  return data_->angle;
}

conical_gradient_brush& conical_gradient_brush::angle(float value) noexcept {
  if (data_->angle != value) {
    data_->angle = value;
    recreate_handle();
  }
  return *this;
}

conical_gradient_brush& conical_gradient_brush::conical_colors(const gradient_stop_collection& value) {
  if (data_->conical_colors != value) {
    if (value.size() < 2) throw argument_exception(csf_);
    data_->conical_colors = value;
    recreate_handle();
  }
  return *this;
}

const gradient_stop_collection& conical_gradient_brush::conical_colors() const noexcept {
  return data_->conical_colors;
}

xtd::drawing::point_f conical_gradient_brush::center_point() const noexcept {
  return data_->center_point;
}

conical_gradient_brush& conical_gradient_brush::center_point(const point_f& value) noexcept {
  if (data_->center_point != value) {
    data_->center_point = value;
    recreate_handle();
  }
  return *this;
}

conical_gradient_brush& conical_gradient_brush::center_point(const point& value) noexcept {
  return center_point(point_f(as<float>(value.x()), as<float>(value.y())));
}

void conical_gradient_brush::recreate_handle() {
  vector<tuple<uint8_t, uint8_t, uint8_t, uint8_t, float>> colors;
  
  for (auto color : data_->conical_colors)
    colors.push_back(make_tuple(color.first.r(), color.first.g(), color.first.b(), color.first.a(), color.second));
    
  native::brush::conical_gradient(handle(), as<int32_t>(data_->center_point.x()), as<int32_t>(data_->center_point.y()), colors, data_->angle);
}

conical_gradient_brush::conical_gradient_brush(const conical_gradient_brush& value) : brush(value), data_(value.data_) {
}

conical_gradient_brush& conical_gradient_brush::operator=(const conical_gradient_brush& value) {
  brush::operator=(value);
  data_ = value.data_;
  return *this;
}
