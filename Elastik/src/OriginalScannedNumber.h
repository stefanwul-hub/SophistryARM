#pragma once

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <optional>
#include <string_view>

namespace elastik_number {
namespace detail {

inline bool ascii_space(char16_t ch) noexcept {
    return ch == u' ' || (ch >= u'\t' && ch <= u'\r');
}

inline bool digit(char16_t ch) noexcept {
    return ch >= u'0' && ch <= u'9';
}

template <class Char>
void skip_space(std::basic_string_view<Char>& text) noexcept {
    while (!text.empty() && ascii_space(text.front())) text.remove_prefix(1);
}

// 0x18b3ce. Its pre-multiply bound is stricter than a usual int32 scanner.
inline std::optional<int32_t> scan_exponent(std::u16string_view text) noexcept {
    skip_space(text);
    bool negative = false;
    if (!text.empty() && (text.front() == u'+' || text.front() == u'-')) {
        negative = text.front() == u'-';
        text.remove_prefix(1);
    }
    if (text.empty() || !digit(text.front())) return std::nullopt;
    uint32_t value = 0;
    for (char16_t ch : text) {
        if (!digit(ch)) break;
        if (value >= 0x19999999u) {
            return negative ? INT32_MIN : INT32_MAX;
        }
        value = value * 10 + (ch - u'0');
    }
    const int64_t signed_value = negative ? -int64_t(value) : int64_t(value);
    return static_cast<int32_t>(std::clamp(signed_value, int64_t(INT32_MIN), int64_t(INT32_MAX)));
}

} // namespace detail

// GN scanner 0x18b560. OpenStep passes bare decimal tokens, while XML
// also uses signs and exponents.
inline double number_double(std::u16string_view text) noexcept {
    detail::skip_space(text);
    bool negative = false;
    if (!text.empty() && (text.front() == u'+' || text.front() == u'-')) {
        negative = text.front() == u'-';
        text.remove_prefix(1);
    }
    double value = 0;
    int64_t scale = 0;
    bool after_dot = false;
    bool saw_digit = false;
    size_t pos = 0;
    for (; pos < text.size(); ++pos) {
        const auto ch = text[pos];
        if (ch == u'.' && !after_dot) {
            after_dot = true;
            continue;
        }
        if (!detail::digit(ch)) break;
        if (value < 1.7976931346825464e307) {
            value = value * 10 + (ch - u'0');
            saw_digit = true;
            if (after_dot) --scale;
        } else if (!after_dot) {
            ++scale;
        }
    }
    if (!saw_digit) return 0;
    if (pos < text.size() && (text[pos] == u'e' || text[pos] == u'E')) {
        const auto exp = detail::scan_exponent(text.substr(pos + 1));
        if (!exp) return 0;
        scale = std::clamp(scale + *exp, int64_t(INT32_MIN), int64_t(INT32_MAX));
    }
    if (value != 0 && scale != 0) value *= std::pow(10.0, scale);
    return negative ? -value : value;
}

inline float number_real(std::u16string_view text) noexcept {
    return static_cast<float>(number_double(text));
}

} // namespace elastik_number
