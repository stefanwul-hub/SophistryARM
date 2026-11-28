#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <string>
#include <string_view>
#include <variant>
#include <vector>

namespace elastik_state {

using Reference = uint32_t; // Wire index 0 means null. The root is index 1.

struct ClassEntry {
    int32_t version;
    std::string name;
};

struct Dictionary {
    Reference keys;
    Reference values;
};

struct List {
    bool avoids_retaining_objects;
    bool accepts_null;
    std::vector<Reference> items;
};

struct String {
    int32_t encoding;
    bool mutable_value;
    std::u16string text;
};

struct Number {
    char kind;
    uint64_t bits; // Integer or IEEE bits without converting floating-point values.
    bool payload_present; // V2 int64 has no value bytes in the original writer.
};

struct Data {
    std::vector<uint8_t> bytes;
};

struct Object {
    uint32_t class_number;
    std::variant<Dictionary, List, String, Number, Data> value;
};

struct Archive {
    std::vector<ClassEntry> classes;
    std::vector<Object> objects;

    const Object* get(Reference) const noexcept;
    std::optional<Reference> find_key(Reference dictionary, std::u16string_view key) const noexcept;
};

enum class Error : uint8_t {
    None, Truncated, UnexpectedTag, UnsupportedArchiveVersion, InvalidDirectory,
    MissingRoot, UnsupportedClass, UnsupportedClassVersion, InvalidReference,
    InvalidBody, UnsupportedEncoding, UnsupportedCompression, TrailingBytes
};

struct DecodeResult {
    std::optional<Archive> archive;
    Error error;
    size_t offset;
    Reference object;
};

// Decodes the established foundation object bodies of a raw GNArchiver V1
// payload. References remain numeric, including forward links and cycles.
// On failure no partial graph is returned. A memory allocation may throw.
DecodeResult decode(std::string_view);

} // namespace elastik_state
