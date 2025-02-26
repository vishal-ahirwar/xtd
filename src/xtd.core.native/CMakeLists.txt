cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.core.native)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_include_directories(include)
add_sources(
  include/xtd/xtd.core.native
  include/xtd/xtd.core.native.h
  include/xtd/native/address_family_constants.h
  include/xtd/native/assert_dialog_results.h
  include/xtd/native/console_color.h
  include/xtd/native/console_special_key.h
  include/xtd/native/console.h
  include/xtd/native/constant_special_item_id_list.h
  include/xtd/native/cryptography.h
  include/xtd/native/date_time.h
  include/xtd/native/debugger.h
  include/xtd/native/directory.h
  include/xtd/native/dns.h
  include/xtd/native/drive_type.h
  include/xtd/native/drive.h
  include/xtd/native/environment.h
  include/xtd/native/environment_variable_target.h
  include/xtd/native/file.h
  include/xtd/native/file_attribute.h
  include/xtd/native/file_system.h
  include/xtd/native/guid.h
  include/xtd/native/interlocked.h
  include/xtd/native/path.h
  include/xtd/native/platform_ids.h
  include/xtd/native/priority_class.h
  include/xtd/native/process.h
  include/xtd/native/process_creation_flags.h
  include/xtd/native/process_window_style.h
  include/xtd/native/protocol_type_constants.h
  include/xtd/native/select_mode_constants.h
  include/xtd/native/socket.h
  include/xtd/native/socket_option_level_constants.h
  include/xtd/native/socket_option_name_constants.h
  include/xtd/native/socket_error_constants.h
  include/xtd/native/socket_shutdown_constants.h
  include/xtd/native/socket_type_constants.h
  include/xtd/native/sounds.h
  include/xtd/native/system_sound.h
  include/xtd/native/translator.h
)
target_type(INTERFACE_LIBRARY)

# Install
add_install_include_directories(include/xtd)
install_component()
