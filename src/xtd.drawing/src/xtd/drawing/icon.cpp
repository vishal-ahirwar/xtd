#include "../../../include/xtd/drawing/icon.h"
#include <fstream>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/icon.h>
#include <xtd/drawing/native/image_formats.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;

icon icon::empty;

icon::icon(const ustring& filename) {
  data_->handle = native::icon::create(filename);
  data_->size = {native::icon::get_width(handle()), native::icon::get_height(handle())};
}

icon::icon(const xtd::ustring& filename, const xtd::drawing::size& size) : icon(filename, size.width(), size.height()) {
}

icon::icon(const xtd::ustring& filename, int32_t width, int32_t height) {
  data_->handle = native::icon::create(filename, width, height);
  data_->size = {width, height};
}

icon::icon(std::istream& stream) {
  data_->handle = native::icon::create(stream);
  data_->size = {native::icon::get_width(handle()), native::icon::get_height(handle())};
}

icon::icon(std::istream& stream, const xtd::drawing::size& size) : icon(stream, size.width(), size.height()) {
}

icon::icon(std::istream& stream, int32_t width, int32_t height) {
  data_->handle = native::icon::create(stream, width, height);
  data_->size = {native::icon::get_width(handle()), native::icon::get_height(handle())};
}

icon::icon(const char* const* bits) {
  data_->handle = native::icon::create(bits);
  data_->size = {native::icon::get_width(handle()), native::icon::get_height(handle())};
}

icon::icon(const char* const* bits, const xtd::drawing::size& size) : icon(bits, size.width(), size.height()) {
}

icon::icon(const char* const* bits, int32_t width, int32_t height) {
  data_->handle = native::icon::create(bits, width, height);
  data_->size = {native::icon::get_width(handle()), native::icon::get_height(handle())};
}

icon::icon(const icon& original, const xtd::drawing::size& size) : icon(original, size.width(), size.height()) {
}

icon::icon(const icon& original, int32_t width, int32_t height) {
  data_->handle = native::icon::create(original.data_->handle, width, height);
  data_->size = {native::icon::get_width(handle()), native::icon::get_height(handle())};
}

icon::icon(const drawing::bitmap& bitmap) {
  if (bitmap == drawing::bitmap::empty) return;
  data_->handle = native::icon::create(bitmap.handle());
  data_->size = {native::icon::get_width(handle()), native::icon::get_height(handle())};
}

icon::~icon() {
  if (data_.use_count() == 1 && data_->handle)
    native::icon::destroy(data_->handle);
}

bool icon::operator==(const icon& icon) const {
  return data_->handle == icon.data_->handle;
}

bool icon::operator!=(const icon& icon) const {
  return !operator==(icon);
}

intptr_t icon::handle() const {
  return data_->handle;
}

int32_t icon::height() const {
  return data_->size.width();
}

const xtd::drawing::size& icon::size() const {
  return data_->size;
}

int32_t icon::width() const {
  return data_->size.width();
}

void icon::save(const ustring& filename) const {
  native::icon::save(data_->handle, filename);
}

void icon::save(std::ostream& stream) const {
  native::icon::save(data_->handle, stream, IFM_ICO);
}

icon icon::from_handle(intptr_t handle) {
  drawing::icon icon;
  icon.data_->handle = native::icon::from_handle(handle);
  icon.data_->size = {native::icon::get_width(icon.data_->handle), native::icon::get_height(icon.data_->handle)};
  return icon;
}

icon icon::from_bitmap(const bitmap& bitmap) {
  return icon(bitmap);
}

bitmap icon::to_bitmap() const {
  return image::from_hbitmap(native::icon::to_image(data_->handle));
}


