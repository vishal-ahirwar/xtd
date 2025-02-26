#include "../../../../include/xtd/forms/properties/resources.h"
#include <xtd/io/file.h>
#include <xtd/io/path.h>

using namespace xtd;
using namespace io;
using namespace drawing;
using namespace forms;
using namespace forms::properties;

namespace {
  ustring get_os_postfix() noexcept {return environment::os_version().is_windows_platform() ? "_w" : environment::os_version().is_unix_platform() ? "_g" : environment::os_version().is_macos_platform() ? "_m" : "";}
}

const bitmap& resources::cursor_arrow() {
  if (!file::exists(path::combine(__XTD_RESOURCES_PATH__, "cursors", ustring::format("arrow{}.png", get_os_postfix())))) return bitmap::empty;
  static bitmap bitmap(path::combine(__XTD_RESOURCES_PATH__, "cursors", ustring::format("arrow{}.png", get_os_postfix())));
  return bitmap;
}

const bitmap& resources::cursor_no_move_2d() {
  if (!file::exists(path::combine(__XTD_RESOURCES_PATH__, "cursors", ustring::format("cursor_no_move_2d{}.png", get_os_postfix())))) return bitmap::empty;
  static bitmap bitmap(path::combine(__XTD_RESOURCES_PATH__, "cursors", ustring::format("cursor_no_move_2d{}.png", get_os_postfix())));
  return bitmap;
}

const bitmap& resources::gammasoft() {
  if (!file::exists(path::combine(__XTD_RESOURCES_PATH__, "pictures", "gammasoft.png"))) return bitmap::empty;
  static bitmap bitmap(path::combine(__XTD_RESOURCES_PATH__, "pictures", "gammasoft.png"));
  return bitmap;
}

const bitmap& resources::xtd() {
  if (!file::exists(path::combine(__XTD_RESOURCES_PATH__, "pictures", "xtd.png"))) return bitmap::empty;
  static bitmap bitmap(path::combine(__XTD_RESOURCES_PATH__, "pictures", "xtd.png"));
  return bitmap;
}

const bitmap& resources::xtd_console() {
  if (!file::exists(path::combine(__XTD_RESOURCES_PATH__, "pictures", "xtd_console.png"))) return bitmap::empty;
  static bitmap bitmap(path::combine(__XTD_RESOURCES_PATH__, "pictures", "xtd_console.png"));
  return bitmap;
}

const bitmap& resources::xtd_forms() {
  if (!file::exists(path::combine(__XTD_RESOURCES_PATH__, "pictures", "xtd_forms.png"))) return bitmap::empty;
  static bitmap bitmap(path::combine(__XTD_RESOURCES_PATH__, "pictures", "xtd_forms.png"));
  return bitmap;
}
