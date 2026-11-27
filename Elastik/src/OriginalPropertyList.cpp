#include "OriginalPropertyList.h"
#include "OriginalPropertyListXml.h"
#include "OriginalStringEncoding.h"

#include <algorithm>
#include <limits>
#include <optional>

const ElastikPropertyValue* ElastikPropertyValue::find(std::u16string_view key) const noexcept {
    const auto* dictionary = std::get_if<Dictionary>(&value);
    if (!dictionary) return nullptr;
    const auto it = std::find_if(dictionary->begin(), dictionary->end(),
                                 [key](const auto& entry) { return entry.first == key; });
    return it == dictionary->end() ? nullptr : &it->second;
}

namespace {

using elastik_plist_detail::decode_utf8;
using elastik_plist_detail::number_real;

bool probe_space(unsigned char ch) noexcept {
    return ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n';
}

bool has_openstep_marker(std::string_view bytes, bool path) noexcept {
    size_t pos = 0;
    auto next = [&] { return static_cast<unsigned char>(bytes[pos++]); };
    while (pos < bytes.size()) {
        auto ch = next();
        if (probe_space(ch) || (path && ch == 0)) continue;
        if (ch == 0xff || ch == 0xfe) {
            if (pos == bytes.size() || next() != (ch ^ 1)) return false;
            continue;
        }
        if (ch != '/') return ch == '{';
        if (pos == bytes.size()) return false;

        ch = next();
        if (ch == '/') {
            while (pos < bytes.size() && ch != '\n') ch = next();
            if (ch == '\n') continue;
            return ch == '{';
        }
        if (ch != '*') return false;

        bool closed = false;
        while (pos < bytes.size()) {
            ch = next();
            if (ch != '*') continue;
            if (pos == bytes.size()) return false;
            ch = next();
            if (ch == '/') {
                closed = true;
                break;
            }
            // The path scanner reads one more byte before testing for '*'.
            // The data scanner advances its index after the non-slash byte.
        }
        if (!closed) return ch == '{';
    }
    return false;
}

std::u16string decode(std::string_view bytes, ElastikPropertyListFormat format) {
    std::u16string result;
    result.reserve(bytes.size());
    if (bytes.size() >= 2 && bytes.size() % 2 == 0) {
        const auto first = static_cast<unsigned char>(bytes[0]);
        const auto second = static_cast<unsigned char>(bytes[1]);
        if ((first == 0xff || first == 0xfe) && second == (first ^ 1)) {
            const size_t low = first == 0xff ? 0 : 1;
            for (size_t pos = 2; pos < bytes.size(); pos += 2) {
                const auto lo = static_cast<unsigned char>(bytes[pos + low]);
                const auto hi = static_cast<unsigned char>(bytes[pos + (1 - low)]);
                result.push_back(static_cast<char16_t>(lo | (hi << 8)));
            }
            return result;
        }
    }
    if (format == ElastikPropertyListFormat::OpenStepPath) return decode_utf8(bytes);
    bytes = bytes.substr(0, bytes.find('\0'));
    for (unsigned char byte : bytes) {
        if (byte >= 32 && byte <= 126) {
            result.push_back(byte);
        } else {
            const auto pair = std::lower_bound(std::begin(legacy_archive_characters),
                                               std::end(legacy_archive_characters), byte,
                                               [](const auto& p, unsigned char b) { return p.byte < b; });
            result.push_back(pair == std::end(legacy_archive_characters) || pair->byte != byte
                                 ? u'\ufffd' : static_cast<char16_t>(pair->unicode));
        }
    }
    return result;
}

bool digit(char16_t ch) noexcept {
    return ch >= u'0' && ch <= u'9';
}

bool bare(char16_t ch) noexcept {
    return (ch >= u'A' && ch <= u'Z') || (ch >= u'a' && ch <= u'z') ||
           digit(ch) || std::u16string_view(u"_$/.:").find(ch) != std::u16string_view::npos;
}

int hex_digit(char16_t ch) noexcept {
    if (digit(ch)) return ch - u'0';
    if (ch >= u'A' && ch <= u'F') return ch - u'A' + 10;
    if (ch >= u'a' && ch <= u'f') return ch - u'a' + 10;
    return -1;
}

// Scanner 0x18b3ce ceases accumulating at the original conservative bound.
int32_t number_integer(std::u16string_view text) noexcept {
    uint32_t value = 0;
    for (char16_t ch : text) {
        if (!digit(ch)) break;
        if (value >= 0x19999999u) return std::numeric_limits<int32_t>::max();
        value = value * 10 + (ch - u'0');
    }
    return static_cast<int32_t>(std::min(value, static_cast<uint32_t>(std::numeric_limits<int32_t>::max())));
}

class OpenStepParser {
public:
    explicit OpenStepParser(std::u16string_view text) : text_(text) {}

    std::optional<ElastikPropertyValue> value(unsigned depth = 0) {
        // This native limit protects the stack while parsing nested files.
        if (depth >= 128) {
            nesting_limit = true;
            return std::nullopt;
        }
        skip();
        switch (peek()) {
            case u'{': ++pos_; return dictionary(depth);
            case u'(': ++pos_; return array(depth);
            case u'<': ++pos_; return data();
            case u'\'': case u'"': {
                auto str = quoted();
                if (!str) return std::nullopt;
                return ElastikPropertyValue{std::move(*str)};
            }
            default: break;
        }

        const auto token = bare_token();
        if (token.empty()) return std::nullopt;
        if (token.find_first_not_of(u"-.+0123456789") != std::u16string_view::npos) {
            return ElastikPropertyValue{std::u16string(token)};
        }
        if (token.find(u'.') == std::u16string_view::npos) {
            return ElastikPropertyValue{number_integer(token)};
        }
        return ElastikPropertyValue{number_real(token)};
    }

    bool nesting_limit = false;
    bool invalid_escape = false;

private:
    char16_t peek() const noexcept { return pos_ < text_.size() ? text_[pos_] : 0; }

    bool consume(char16_t ch) noexcept {
        if (peek() != ch) return false;
        ++pos_;
        return true;
    }

    void skip() noexcept {
        while (pos_ < text_.size()) {
            const char16_t ch = peek();
            if ((ch >= 9 && ch <= 13) || ch == u' ') {
                ++pos_;
            } else if (text_.substr(pos_, 2) == u"//") {
                const size_t newline = text_.find(u'\n', pos_ + 2);
                pos_ = newline == std::u16string_view::npos ? text_.size() : newline;
            } else if (text_.substr(pos_, 2) == u"/*") {
                const size_t close = text_.find(u"*/", pos_ + 2);
                pos_ = close == std::u16string_view::npos ? text_.size() : close + 2;
            } else {
                break;
            }
        }
    }

    std::u16string_view bare_token() noexcept {
        const size_t start = pos_;
        while (bare(peek())) ++pos_;
        return text_.substr(start, pos_ - start);
    }

    std::optional<std::u16string> quoted() {
        const char16_t quote = text_[pos_++];
        std::u16string result;
        while (pos_ < text_.size()) {
            char16_t ch = text_[pos_++];
            if (ch == quote) break;
            if (ch == u'\\') {
                if (pos_ == text_.size()) return std::nullopt;
                ch = text_[pos_++];
                if (ch >= u'0' && ch <= u'7') {
                    invalid_escape = true;
                    return std::nullopt;
                }
                if (ch == u'U') {
                    ch = 0;
                    for (unsigned i = 0; i < 4; ++i) {
                        const int h = hex_digit(peek());
                        if (h < 0) break;
                        ch = static_cast<char16_t>(ch * 16 + h);
                        ++pos_;
                    }
                } else {
                    constexpr std::u16string_view escapes = u"abfnrtv";
                    constexpr std::u16string_view controls = u"\a\b\f\n\r\t\v";
                    const size_t which = escapes.find(ch);
                    if (which != std::u16string_view::npos) ch = controls[which];
                }
            }
            result.push_back(ch);
        }
        return result;
    }

    std::optional<std::u16string> key() {
        skip();
        if (peek() == u'"' || peek() == u'\'') return quoted();
        const auto token = bare_token();
        if (token.empty()) return std::nullopt;
        return std::u16string(token);
    }

    std::optional<ElastikPropertyValue> dictionary(unsigned depth) {
        ElastikPropertyValue::Dictionary entries;
        do {
            auto name = key();
            if (!name) break;
            skip();
            std::optional<ElastikPropertyValue> item;
            if (consume(u'=')) item = value(depth + 1);
            else if (peek() == u';') item = ElastikPropertyValue{*name};
            if (!item) return std::nullopt;
            const auto existing = std::find_if(entries.begin(), entries.end(),
                                               [&name](const auto& entry) { return entry.first == *name; });
            if (existing == entries.end()) entries.emplace_back(std::move(*name), std::move(*item));
            else existing->second = std::move(*item);
            skip();
        } while (consume(u';'));
        skip();
        if (!consume(u'}')) return std::nullopt;
        return ElastikPropertyValue{std::move(entries)};
    }

    std::optional<ElastikPropertyValue> array(unsigned depth) {
        ElastikPropertyValue::Array entries;
        do {
            auto item = value(depth + 1);
            if (!item) {
                if (nesting_limit) return std::nullopt;
                break;
            }
            entries.push_back(std::move(*item));
            skip();
        } while (consume(u','));
        skip();
        if (!consume(u')')) return std::nullopt;
        return ElastikPropertyValue{std::move(entries)};
    }

    std::optional<ElastikPropertyValue> data() {
        ElastikPropertyValue::Data bytes;
        for (;;) {
            skip();
            const auto token = bare_token();
            if (token.empty()) break;
            if (token.size() % 2 != 0) return std::nullopt;
            for (size_t i = 0; i < token.size(); i += 2) {
                const int hi = hex_digit(token[i]);
                const int lo = hex_digit(token[i + 1]);
                if (hi < 0 || lo < 0) return std::nullopt;
                bytes.push_back(static_cast<uint8_t>((hi << 4) | lo));
            }
        }
        if (!consume(u'>')) return std::nullopt;
        return ElastikPropertyValue{std::move(bytes)};
    }

    std::u16string_view text_;
    size_t pos_ = 0;
};

} // namespace

ElastikPropertyListFormat elastik_original_plist_format(std::string_view bytes,
                                                        bool has_reader) noexcept {
    if (has_reader && has_openstep_marker(bytes, true)) return ElastikPropertyListFormat::OpenStepPath;
    if (has_openstep_marker(bytes, false)) return ElastikPropertyListFormat::OpenStepData;
    return ElastikPropertyListFormat::Xml;
}

ElastikPropertyList elastik_original_plist(std::string_view bytes, bool has_reader) {
    const auto format = elastik_original_plist_format(bytes, has_reader);
    if (format == ElastikPropertyListFormat::Xml) return elastik_plist_detail::parse_xml(bytes);
    const auto text = decode(bytes, format);
    OpenStepParser parser(text);
    auto value = parser.value();
    if (!value || parser.invalid_escape) {
        const auto status = parser.nesting_limit ? ElastikPropertyListStatus::NestingLimit
                                                : ElastikPropertyListStatus::Invalid;
        return {format, status, {}};
    }
    return {format, ElastikPropertyListStatus::Parsed, std::move(*value)};
}
