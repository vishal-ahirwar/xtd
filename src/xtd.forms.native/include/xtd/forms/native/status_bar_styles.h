/// @file
/// @brief Contains tool bar styles constants.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstddef>

#ifndef TBSTYLE_TOOLTIPS
/// @brief The status bar control will include a sizing grip at the right end of the status bar. A sizing grip is similar to a sizing border; it is a rectangular area that the user can click and drag to resize the parent window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sbstyle
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SBARS_SIZEGRIP = 0x0100;
/// @brief Use this style to enable tooltips.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sbstyle
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SBARS_TOOLTIPS = 0x0800;
#endif

/// @brief Replace the end of the status texts with an ellipsis when the status text widths exceed status bar or status panel width.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sbstyle
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t SBARS_ELLIPSIZE = 0x1000;
