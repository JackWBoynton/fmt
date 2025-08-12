// Formatting library for C++
//
// Copyright (c) 2012 - 2016, Victor Zverovich
// All rights reserved.
//
// For the license information refer to format.h.

#include "fmt/format-inl.h"

FMT_BEGIN_NAMESPACE
namespace detail {

#if FMT_USE_ERROR_CODES
// EMSCRIPTEN error state implementation
thread_local ::fmt::detail::error_state g_error_state;

FMT_FUNC ::fmt::detail::error_state& get_error_state() noexcept {
  return g_error_state;
}

FMT_FUNC void set_error_state(::fmt::fmt_error_code code, const char* message, 
                             const char* file, int line) noexcept {
  g_error_state.code = code;
  g_error_state.message = message;
  g_error_state.file = file;
  g_error_state.line = line;
}

FMT_FUNC void clear_error_state() noexcept {
  g_error_state.code = ::fmt::fmt_error_code::none;
  g_error_state.message = nullptr;
  g_error_state.file = nullptr;
  g_error_state.line = 0;
}
#endif  // FMT_USE_ERROR_CODES

template FMT_API auto dragonbox::to_decimal(float x) noexcept
    -> dragonbox::decimal_fp<float>;
template FMT_API auto dragonbox::to_decimal(double x) noexcept
    -> dragonbox::decimal_fp<double>;

#if FMT_USE_LOCALE
// DEPRECATED! locale_ref in the detail namespace
template FMT_API locale_ref::locale_ref(const std::locale& loc);
template FMT_API auto locale_ref::get<std::locale>() const -> std::locale;
#endif

// Explicit instantiations for char.

template FMT_API auto thousands_sep_impl(locale_ref)
    -> thousands_sep_result<char>;
template FMT_API auto decimal_point_impl(locale_ref) -> char;

// DEPRECATED!
template FMT_API void buffer<char>::append(const char*, const char*);

// DEPRECATED!
template FMT_API void vformat_to(buffer<char>&, string_view,
                                 typename vformat_args<>::type, locale_ref);

// Explicit instantiations for wchar_t.

template FMT_API auto thousands_sep_impl(locale_ref)
    -> thousands_sep_result<wchar_t>;
template FMT_API auto decimal_point_impl(locale_ref) -> wchar_t;

template FMT_API void buffer<wchar_t>::append(const wchar_t*, const wchar_t*);

}  // namespace detail
FMT_END_NAMESPACE
