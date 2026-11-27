#include "OriginalPropertyListXml.h"

#include "../third_party/tinyxml2/tinyxml2.h"

#include <algorithm>
#include <charconv>
#include <cmath>
#include <limits>
#include <optional>

namespace elastik_plist_detail {
std::u16string decode_utf8(std::string_view bytes) {
    std::u16string result;
    result.reserve(bytes.size());
    for (size_t pos = 0; pos < bytes.size();) {
        const auto first = static_cast<unsigned char>(bytes[pos++]);
        if (first < 0x80) {
            result.push_back(first);
            continue;
        }
        if (first < 0xc2 || first > 0xf4) return {};
        const unsigned count = first < 0xe0 ? 1 : first < 0xf0 ? 2 : 3;
        if (bytes.size() - pos < count) return {};
        uint32_t unit = first & (0x7fu >> (count + 1));
        for (unsigned i = 0; i < count; ++i) {
            const auto continuation = static_cast<unsigned char>(bytes[pos++]);
            if (continuation < 0x80 || continuation > 0xbf) return {};
            unit = (unit << 6) | (continuation & 0x3f);
        }
        if ((count == 2 && unit < 0x800) || (count == 3 && unit < 0x10000) || unit > 0x10ffff) {
            return {};
        }
        if (unit < 0x10000) {
            // Original UTF-8 accepts a surrogate encoded as a three-byte unit.
            result.push_back(static_cast<char16_t>(unit));
        } else {
            unit -= 0x10000;
            result.push_back(static_cast<char16_t>(0xd800 + (unit >> 10)));
            result.push_back(static_cast<char16_t>(0xdc00 + (unit & 0x3ff)));
        }
    }
    return result;
}

namespace {

bool ascii_space(char16_t ch) noexcept {
    return ch == u' ' || (ch >= u'\t' && ch <= u'\r');
}

bool digit(char16_t ch) noexcept {
    return ch >= u'0' && ch <= u'9';
}

template <class Char>
void skip_space(std::basic_string_view<Char>& text) noexcept {
    while (!text.empty() && ascii_space(text.front())) text.remove_prefix(1);
}

// 0x18b3ce. Its pre-multiply bound is stricter than a usual int32 scanner.
std::optional<int32_t> scan_exponent(std::u16string_view text) noexcept {
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

} // namespace

// GN scanner 0x18b560, followed by the original conversion to float32.
// OpenStep passes only bare decimal tokens. XML also uses signs and exponents.
float number_real(std::u16string_view text) noexcept {
    skip_space(text);
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
        if (!digit(ch)) break;
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
        const auto exp = scan_exponent(text.substr(pos + 1));
        if (!exp) return 0;
        scale = std::clamp(scale + *exp, int64_t(INT32_MIN), int64_t(INT32_MAX));
    }
    if (value != 0 && scale != 0) value *= std::pow(10.0, scale);
    return static_cast<float>(negative ? -value : value);
}

namespace {

using tinyxml2::XMLElement;

std::optional<int64_t> read_integer(std::string_view& text) noexcept {
    skip_space(text);
    if (text.empty()) return std::nullopt;
    if (text.front() == '+') {
        text.remove_prefix(1);
        if (text.empty() || !digit(text.front())) return std::nullopt;
    }
    int64_t value = 0;
    const auto parsed = std::from_chars(text.data(), text.data() + text.size(), value);
    if (parsed.ec == std::errc::invalid_argument) return std::nullopt;
    if (parsed.ec == std::errc::result_out_of_range) {
        value = text.front() == '-' ? INT64_MIN : INT64_MAX;
    }
    text.remove_prefix(static_cast<size_t>(parsed.ptr - text.data()));
    return value;
}

ElastikPropertyValue integer(std::string_view text) noexcept {
    const int64_t value = read_integer(text).value_or(0);
    if (value > INT32_MIN && value <= INT32_MAX) return {static_cast<int32_t>(value)};
    return {value};
}

ElastikPropertyDate date(std::string_view text, bool empty) noexcept {
    ElastikPropertyDate result;
    result.use_current_time = empty;
    // 0x673d2 reads DD.MM.YYYY HH:MM:SS. The original call swaps MM and SS.
    constexpr size_t field_order[] = {2, 1, 0, 3, 5, 4};
    constexpr char separators[] = {'\0', '.', '.', '\0', ':', ':'};
    for (size_t i = 0; i < std::size(field_order); ++i) {
        if (separators[i] != '\0') {
            if (text.empty() || text.front() != separators[i]) break;
            text.remove_prefix(1);
        }
        const auto field = read_integer(text);
        if (!field) break;
        result.calendar[field_order[i]] = static_cast<int32_t>(
            std::clamp(*field, int64_t(INT32_MIN), int64_t(INT32_MAX)));
    }
    return result;
}

void set(ElastikPropertyValue::Dictionary& entries, std::u16string name, ElastikPropertyValue value) {
    const auto found = std::find_if(entries.begin(), entries.end(),
                                    [&name](const auto& entry) { return entry.first == name; });
    if (found == entries.end()) entries.emplace_back(std::move(name), std::move(value));
    else found->second = std::move(value);
}

ElastikPropertyValue::Data data(std::string_view text, bool empty) {
    if (empty) return {};
    constexpr std::string_view alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    // GN removes LF and TAB, then decodes the valid Base64 prefix.
    // Preserve its allocation length but supply zero for unspecified padding.
    ElastikPropertyValue::Data result;
    uint32_t bits = 0;
    unsigned pending = 0;
    size_t digits = 0;
    for (char ch : text) {
        if (ch == '\n' || ch == '\t') continue;
        const size_t digit = alphabet.find(ch);
        if (digit == std::string_view::npos) break;
        bits = (bits << 6) | static_cast<uint32_t>(digit);
        pending += 6;
        ++digits;
        if (pending >= 8) {
            pending -= 8;
            result.push_back(static_cast<uint8_t>(bits >> pending));
        }
    }
    result.resize(((digits + 3) / 4) * 3 + 1);
    return result;
}

bool has_utf8_entities(std::string_view bytes, const tinyxml2::XMLDocument& document) {
    if (bytes.substr(0, 3) == "\xef\xbb\xbf") return true;
    for (auto* node = document.FirstChild(); node; node = node->NextSibling()) {
        if (node->ToElement() && std::string_view(node->Value()) == "plist") break;
        const auto* declaration = node->ToDeclaration();
        if (!declaration) continue;
        std::string_view value = declaration->Value();
        if (value.substr(0, 3) != "xml") continue;
        const size_t encoding = value.find("encoding");
        if (encoding == std::string_view::npos) return true;
        const size_t quote = value.find_first_of("\"'", encoding + 8);
        if (quote == std::string_view::npos) return false;
        value.remove_prefix(quote + 1);
        std::string label(value.substr(0, value.find_first_of("\"'")));
        std::transform(label.begin(), label.end(), label.begin(), [](char ch) {
            return ch >= 'a' && ch <= 'z' ? static_cast<char>(ch - ('a' - 'A')) : ch;
        });
        return label.empty() || label == "UTF-8" || label == "UTF8";
    }
    return false;
}

void append_utf8(std::string& text, uint32_t code) {
    if (code < 0x80) {
        text.push_back(static_cast<char>(code));
        return;
    }
    if (code >= 0x200000) return;
    const unsigned count = code < 0x800 ? 2 : code < 0x10000 ? 3 : 4;
    text.push_back(static_cast<char>((0xffu << (8 - count)) | (code >> (6 * (count - 1)))));
    for (unsigned n = count - 1; n > 0; --n) {
        text.push_back(static_cast<char>(0x80 | ((code >> (6 * (n - 1))) & 0x3f)));
    }
}

bool append_entity(std::string& text, std::string_view& input, bool utf8) {
    input.remove_prefix(1);
    if (!input.empty() && input.front() == '#') {
        input.remove_prefix(1);
        const bool hex = !input.empty() && input.front() == 'x';
        if (hex) input.remove_prefix(1);
        const size_t semicolon = input.find(';');
        if (semicolon == std::string_view::npos) return false;
        const auto code_text = input.substr(0, semicolon);
        uint32_t code = 0;
        if (!code_text.empty()) {
            const auto parsed = std::from_chars(
                code_text.data(), code_text.data() + code_text.size(), code, hex ? 16 : 10);
            if (parsed.ec != std::errc{} || parsed.ptr != code_text.data() + code_text.size()) return false;
        }
        if (utf8) append_utf8(text, code);
        else text.push_back(static_cast<char>(code & 0xff));
        input.remove_prefix(semicolon + 1);
        return true;
    }
    constexpr std::pair<std::string_view, char> named[] = {
        {"amp;", '&'}, {"lt;", '<'}, {"gt;", '>'}, {"quot;", '"'}, {"apos;", '\''},
    };
    for (const auto& [name, value] : named) {
        if (input.substr(0, name.size()) == name) {
            text.push_back(value);
            input.remove_prefix(name.size());
            return true;
        }
    }
    // TinyXML's old unmatched-reference path consumes just the ampersand.
    return true;
}

std::optional<std::string> read_text(std::string_view input, bool utf8) {
    std::string text;
    skip_space(input);
    while (!input.empty()) {
        if (ascii_space(input.front())) {
            skip_space(input);
            if (!input.empty()) text.push_back(' ');
        } else if (input.front() == '&') {
            if (!append_entity(text, input, utf8)) return std::nullopt;
        } else {
            text.push_back(input.front());
            input.remove_prefix(1);
        }
    }
    return text;
}

class Projector {
public:
    explicit Projector(bool utf8) : utf8_(utf8) {}

    std::optional<ElastikPropertyValue> parse(const XMLElement& element, unsigned depth = 0) {
        if (depth >= 128) {
            limit = true;
            return std::nullopt;
        }
        const std::string_view tag = element.Name();
        if (tag == "dict") return dictionary(element, depth);
        if (tag == "array") return array(element, depth);
        if (tag == "true") return ElastikPropertyValue{true};
        if (tag == "false") return ElastikPropertyValue{false};


        const auto content = first_child_value(element);
        if (invalid_text_) return std::nullopt;
        const std::string_view text = content ? std::string_view(*content) : std::string_view{};
        if (tag == "string") return ElastikPropertyValue{decode_utf8(text)};
        if (tag == "integer") return integer(text);
        if (tag == "real") return ElastikPropertyValue{number_real(decode_utf8(text))};
        if (tag == "date") return ElastikPropertyValue{date(text, !content)};
        if (tag == "data") return ElastikPropertyValue{data(text, !content)};
        return std::nullopt;
    }

    bool limit = false;

private:
    std::optional<std::string> first_child_value(const XMLElement& element) {
        for (auto* child = element.FirstChild(); child; child = child->NextSibling()) {
            const auto* text = child->ToText();
            const std::string_view value = child->Value();
            if (!text) return std::string(value);
            if (text->CData()) {
                // Original TinyXML treated CDATA as an unknown node ending at '>'.
                const auto end = value.find('>');
                auto result = std::string("![CDATA[") + std::string(value.substr(0, end));
                if (end == std::string_view::npos) result += "]]";
                return result;
            }
            auto decoded = read_text(value, utf8_);
            if (!decoded) {
                invalid_text_ = true;
                return std::nullopt;
            }
            decoded->resize(std::string_view(*decoded).substr(0, decoded->find('\0')).size());
            if (std::any_of(decoded->begin(), decoded->end(), [](char ch) { return !ascii_space(ch); })) {
                return decoded;
            }
        }
        return std::nullopt;
    }

    std::optional<ElastikPropertyValue> dictionary(const XMLElement& element, unsigned depth) {
        ElastikPropertyValue::Dictionary entries;
        for (auto* key = element.FirstChildElement(); key;) {
            const auto* value = key->NextSiblingElement();
            if (std::string_view(key->Name()) != "key" || !value) return std::nullopt;
            const auto name = first_child_value(*key);
            if (!name) return std::nullopt;
            auto item = parse(*value, depth + 1);
            if (!item) return std::nullopt;
            set(entries, decode_utf8(*name), std::move(*item));
            key = value->NextSiblingElement();
        }
        return ElastikPropertyValue{std::move(entries)};
    }

    std::optional<ElastikPropertyValue> array(const XMLElement& element, unsigned depth) {
        ElastikPropertyValue::Array entries;
        for (auto* child = element.FirstChildElement(); child; child = child->NextSiblingElement()) {
            auto item = parse(*child, depth + 1);
            if (!item) return std::nullopt;
            entries.push_back(std::move(*item));
        }
        return ElastikPropertyValue{std::move(entries)};
    }

    bool utf8_;
    bool invalid_text_ = false;
};

} // namespace

ElastikPropertyList parse_xml(std::string_view bytes) {
    constexpr auto format = ElastikPropertyListFormat::Xml;
    bytes = bytes.substr(0, bytes.find('\0'));
    std::string_view start = bytes;
    skip_space(start);
    if (start.empty() || (start.data() != bytes.data() && start.substr(0, 3) == "\xef\xbb\xbf")) {
        return {format, ElastikPropertyListStatus::Invalid, {}};
    }
    tinyxml2::XMLDocument document(false);
    const auto error = document.Parse(bytes.data(), bytes.size());
    if (error != tinyxml2::XML_SUCCESS) {
        const auto status = error == tinyxml2::XML_ELEMENT_DEPTH_EXCEEDED
                            ? ElastikPropertyListStatus::NestingLimit : ElastikPropertyListStatus::Invalid;
        return {format, status, {}};
    }
    const auto* plist = document.FirstChildElement("plist");
    const auto* root = plist ? plist->FirstChildElement() : nullptr;
    if (!root || std::string_view(root->Name()) != "dict") {
        return {format, ElastikPropertyListStatus::Invalid, {}};
    }
    const bool utf8 = has_utf8_entities(bytes, document);
    if (utf8 && decode_utf8(bytes).empty()) {
        return {format, ElastikPropertyListStatus::Invalid, {}};
    }
    Projector projector(utf8);
    auto result = projector.parse(*root);
    if (!result) {
        const auto status = projector.limit ? ElastikPropertyListStatus::NestingLimit
                                            : ElastikPropertyListStatus::Invalid;
        return {format, status, {}};
    }
    return {format, ElastikPropertyListStatus::Parsed, std::move(*result)};
}

} // namespace elastik_plist_detail
