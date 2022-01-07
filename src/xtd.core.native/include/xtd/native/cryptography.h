/// @file
/// @brief Contains cryptography API.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export.h>
#include <cstddef>
#include <string>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace security {
    class secure_string;
  }
  /// @endcond
  
  /// @internal
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @internal
    /// @brief Contains cryptography native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ cryptography final {
      cryptography() = delete;
      friend xtd::security::secure_string;
    protected:
      /// @name Protected methods
      
      /// @{
      /// @internal
      /// @brief Gets the machine's GUID.
      /// @return A byte array that contains the machine GUID.
      /// @warning Internal use only
      static std::vector<uint8_t> machine_guid();
      /// @}
    };
  }
}
