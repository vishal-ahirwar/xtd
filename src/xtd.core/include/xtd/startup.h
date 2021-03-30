/// @file
/// @brief Contains #startup_ keyword.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "environment.h"
#include "static.h"
#include "collections/specialized/string_vector.h"
#if defined(__CMAKE_TARGET_TYPE__) && __CMAKE_TARGET_TYPE__ == 2 // 2 == GUI_APPLICATION
#include <xtd/system_exception.h>
#include "xtd/forms/exception_dialog.h"
#else
#include "strings.h"
#include "system_exception.h"
#include "diagnostics/debug.h"
#endif

/// @cond
#if defined(__CMAKE_TARGET_TYPE__) && __CMAKE_TARGET_TYPE__ == 2 // 2 == GUI_APPLICATION
inline void __startup_catch_exception__(const std::exception& e) {
  xtd::forms::exception_dialog dialog;
  dialog.exception(e);
  dialog.show_dialog();
}
inline void __startup_catch_exception__(const xtd::system_exception& e) {
  xtd::forms::exception_dialog dialog;
  dialog.exception(e);
  dialog.show_dialog();
}
inline void __startup_catch_exception__() {
  xtd::forms::exception_dialog dialog;
  dialog.show_dialog();
}
#else
inline void __startup_catch_exception__(const std::exception& e) {
  xtd::diagnostics::debug::write_line(xtd::strings::format("exception: {}", e.what()));
}
inline void __startup_catch_exception__(const xtd::system_exception& e) {
  xtd::diagnostics::debug::write_line(e);
}
inline void __startup_catch_exception__() {
  xtd::diagnostics::debug::write_line("Unknown exception occured");
}
#endif

#undef startup_
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Defines the entry point to be called when the application loads. Generally this is set either to the main form in your application or to the main procedure that should run when the application starts.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core keywords
  /// @param main_class The class that contains the static main method.
  /// @par Examples
  /// This example show a main method without arguments and without return code
  /// @include main1.cpp
  /// @par
  /// This example show a main method with a return code without arguments
  /// @include main2.cpp
  /// @par
  /// This example show a main method with argument and without return code
  /// @include main3.cpp
  /// @par
  /// This example show a main method with argument and return code
  /// @include main4.cpp
  #define startup_(main_class) \
    int main(int argc, char* argv[]) {\
      struct startup final static_ {\
        static int run(void (*main_function)(), int, char*[]) {main_function(); return xtd::environment::exit_code();}\
        static int run(int (*main_function)(), int, char*[]) {return main_function();}\
        static int run(void (*main_function)(int argc, char* argv[]), int argc, char* argv[]) {main_function(argc, argv); return xtd::environment::exit_code();}\
        static int run(void (*main_function)(xtd::collections::specialized::string_vector), int argc, char* argv[]) {main_function({argv + 1, argv + argc}); return xtd::environment::exit_code();}\
        static int run(void (*main_function)(const xtd::collections::specialized::string_vector&), int argc, char* argv[]) {main_function({argv + 1, argv + argc}); return xtd::environment::exit_code();}\
        static int run(int (*main_function)(int argc, char* argv[]), int argc, char* argv[]) {return main_function(argc, argv);}\
        static int run(int (*main_function)(xtd::collections::specialized::string_vector), int argc, char* argv[]) {return main_function({argv + 1, argv + argc});}\
        static int run(int (*main_function)(const xtd::collections::specialized::string_vector&), int argc, char* argv[]) {return main_function({argv + 1, argv + argc});}\
      };\
      \
      try {\
        return startup::run(main_class::main, argc, argv);\
      } catch(const xtd::system_exception& e) {\
        __startup_catch_exception__(e);\
      } catch(const std::exception& e) {\
        __startup_catch_exception__(e);\
      } catch(...) {\
        __startup_catch_exception__();\
      }\
    }\
    int __startup_force_to_end_with_semicolon__ = 0
}
