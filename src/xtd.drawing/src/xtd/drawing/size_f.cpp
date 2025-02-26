#include "../../../include/xtd/drawing/point_f.h"
#include "../../../include/xtd/drawing/size_f.h"

using namespace xtd::drawing;

const size_f size_f::empty;

size_f::size_f(const point_f& point) noexcept : width_(point.x()), height_(point.y()) {
}

size_f::size_f(float width, float height) noexcept : width_(width), height_(height) {
}

bool size_f::operator==(const xtd::drawing::size_f& value) const noexcept {
  return width_ == value.width_ && height_ == value.height_;
}

bool size_f::operator!=(const xtd::drawing::size_f& value) const noexcept {
  return !operator==(value);
}

size_f size_f::operator+(const size_f& size) const noexcept {
  return {width_ + size.width_, height_ + size.height_};
}

size_f size_f::operator-(const size_f& size) const noexcept {
  return {width_ - size.width_, height_ - size.height_};
}

size_f& size_f::operator+=(const size_f& size) noexcept {
  width_ += size.width_;
  height_ += size.height_;
  return *this;
}

size_f& size_f::operator-=(const size_f& size) noexcept {
  width_ -= size.width_;
  height_ -= size.height_;
  return *this;
}

float size_f::height() const noexcept {
  return height_;
}

void size_f::height(float value) noexcept {
  height_ = value;
}

bool size_f::is_empty() const noexcept {
  return *this == size_f::empty;
}

float size_f::width() const noexcept {
  return width_;
}

void size_f::width(float value) noexcept {
  width_ = value;
}

size_f size_f::add(const size_f& size1, const size_f& size2) noexcept {
  return size1 + size2;
}

size_f size_f::subtract(const size_f& size1, const size_f& size2) noexcept {
  return size1 - size2;
}

xtd::ustring size_f::to_string() const noexcept {
  return ustring::format("{{width={}, height={}}}", width(), height());
}
