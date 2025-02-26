#include <stdexcept>
#include "../../../../include/xtd/drawing/drawing2d/matrix.h"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/matrix.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/argument_exception.h>
#include <xtd/as.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;

matrix::matrix() : matrix(1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f) {
}

matrix::matrix(float m11, float m12, float m21, float m22, float dx, float dy) {
  data_->handle = native::matrix::create(m11, m12, m21, m22, dx, dy);
}

matrix::matrix(const rectangle& rect, const vector<point>& plgpts) {
  if (plgpts.size() != 3) throw argument_exception(csf_);
  init_from_rect_3points(rectangle_f(rect), point_f(plgpts[0]), point_f(plgpts[1]), point_f(plgpts[2]));
}

matrix::matrix(const rectangle_f& rect, const vector<point_f>& plgpts) {
  if (plgpts.size() != 3) throw argument_exception(csf_);
  init_from_rect_3points(rect, plgpts[0], plgpts[1], plgpts[2]);
}

matrix::matrix(intptr_t handle) {
  data_->handle = handle;
}

matrix::~matrix() {
  if (data_.use_count() == 1 && data_->handle != 0) {
    native::matrix::destroy(data_->handle);
    data_->handle = 0;
  }
}

bool matrix::operator==(const matrix& value) const {
  return data_ == value.data_;
}

bool matrix::operator!=(const matrix& value) const {
  return !operator==(value);
}

std::vector<float> matrix::elements() const {
  return native::matrix::elenents(handle());
}

intptr_t matrix::handle() const noexcept {
  return data_->handle;
}

bool matrix::is_identity() const {
  return native::matrix::is_identity(handle());
}

bool matrix::is_invertible() const {
  return native::matrix::is_invertible(handle());
}

float matrix::offset_x() const {
  return native::matrix::offset_x(handle());
}

float matrix::offset_y() const {
  return native::matrix::offset_y(handle());
}

void matrix::invert() {
  native::matrix::invert(handle());
}

void matrix::multiply(const xtd::drawing::drawing2d::matrix& matrix) {
  multiply(matrix, xtd::drawing::drawing2d::matrix_order::prepend);
}

void matrix::multiply(const xtd::drawing::drawing2d::matrix& matrix, xtd::drawing::drawing2d::matrix_order order) {
  native::matrix::multiply(handle(), matrix.handle(), static_cast<int32_t>(order));
}

void matrix::reset() {
  native::matrix::reset(handle());
}

void matrix::rotate(float angle) {
  rotate(angle, xtd::drawing::drawing2d::matrix_order::prepend);
}

void matrix::rotate(float angle, xtd::drawing::drawing2d::matrix_order order) {
  native::matrix::rotate(handle(), angle, static_cast<int32_t>(order));
}

void matrix::rotate_at(float angle, const point_f& point) {
  rotate_at(angle, point, xtd::drawing::drawing2d::matrix_order::prepend);
}

void matrix::rotate_at(float angle, const point_f& point, xtd::drawing::drawing2d::matrix_order order) {
  native::matrix::rotate_at(handle(), angle, point.x(), point.y(), static_cast<int32_t>(order));
}

void matrix::scale(float scale_x, float scale_y) {
  scale(scale_x, scale_y, matrix_order::prepend);
}

void matrix::scale(float scale_x, float scale_y, xtd::drawing::drawing2d::matrix_order order) {
  native::matrix::scale(handle(), scale_x, scale_y, static_cast<int32_t>(order));
}

void matrix::shear(float scale_x, float scale_y) {
  shear(scale_x, scale_y, xtd::drawing::drawing2d::matrix_order::prepend);
}

void matrix::shear(float scale_x, float scale_y, xtd::drawing::drawing2d::matrix_order order) {
  native::matrix::shear(handle(), scale_x, scale_y, static_cast<int32_t>(order));
}

void matrix::transform_points(std::vector<xtd::drawing::point>& points) {
  vector<pair<float, float>> tr_points;
  for (auto& point : points) {
    int32_t tx = point.x(), ty = point.y();
    native::matrix::transform_point(handle(), tx, ty);
    point.x(tx);
    point.y(ty);
  }
}

void matrix::transform_points(std::vector<xtd::drawing::point_f>& points) {
  vector<pair<float, float>> tr_points;
  for (auto& point : points) {
    float tx = point.x(), ty = point.y();
    native::matrix::transform_point(handle(), tx, ty);
    point.x(tx);
    point.y(ty);
  }
}

void matrix::transform_vectors(std::vector<xtd::drawing::point>& points) {
  vector<pair<int32_t, int32_t>> tr_points;
  for (auto point : points)
    tr_points.push_back(make_pair(point.x(), point.y()));
  native::matrix::transform_vectors(handle(), tr_points);
  points.clear();
  for (auto point : tr_points)
    points.push_back(xtd::drawing::point(point.first, point.second));
}

void matrix::transform_vectors(std::vector<xtd::drawing::point_f>& points) {
  vector<pair<float, float>> tr_points;
  for (auto point : points)
    tr_points.push_back(make_pair(point.x(), point.y()));
  native::matrix::transform_vectors(handle(), tr_points);
  points.clear();
  for (auto point : tr_points)
    points.push_back(xtd::drawing::point_f(point.first, point.second));
}

void matrix::translate(float offset_x, float offset_y) {
  translate(offset_x, offset_y, xtd::drawing::drawing2d::matrix_order::prepend);
}

void matrix::translate(float offset_x, float offset_y, xtd::drawing::drawing2d::matrix_order order) {
  native::matrix::translate(handle(), offset_x, offset_y, static_cast<int32_t>(order));
}

void matrix::vector_transform_points(std::vector<xtd::drawing::point>& points) {
  vector<pair<int32_t, int32_t>> tr_points;
  for (auto point : points)
    tr_points.push_back(make_pair(point.x(), point.y()));
  native::matrix::vector_transform_points(handle(), tr_points);
  points.clear();
  for (auto point : tr_points)
    points.push_back(xtd::drawing::point(point.first, point.second));
}

xtd::ustring matrix::to_string() const noexcept {
  return ustring::full_class_name(*this);
}

void matrix::init_from_rect_3points(const rectangle_f& rect, const point_f pt1, const point_f pt2, const point_f pt3) {
  auto m11 = (pt2.x() - pt1.x()) / rect.width();
  auto m12 = (pt2.y() - pt1.y()) / rect.width();
  auto m21 = (pt3.x() - pt1.x()) / rect.height();
  auto m22 = (pt3.y() - pt1.y()) / rect.height();
  
  data_->handle = native::matrix::create(m11, m12, m21, m22, pt1.x(), pt1.y());
  native::matrix::translate(handle(), -rect.x(), -rect.y(), static_cast<int32_t>(matrix_order::prepend));
}
