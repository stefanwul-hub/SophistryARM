#include "OriginalStateArchive.h"
#include "OriginalStringEncoding.h"

#include <algorithm>
#include <cstring>

namespace elastik_state {

const Object* Archive::get(Reference ref) const noexcept {
    return ref > 0 && ref <= objects.size() ? &objects[ref - 1] : nullptr;
}

std::optional<Reference> Archive::find_key(Reference dictionary, std::u16string_view key) const noexcept {
    const auto* object = get(dictionary);
    const auto* dict = object ? std::get_if<Dictionary>(&object->value) : nullptr;
    if (!dict) return std::nullopt;
    const auto* keys_object = get(dict->keys);
    const auto* values_object = get(dict->values);
    const auto* keys = keys_object ? std::get_if<List>(&keys_object->value) : nullptr;
    const auto* values = values_object ? std::get_if<List>(&values_object->value) : nullptr;
    if (!keys || !values || keys->items.size() != values->items.size()) return std::nullopt;

    for (size_t i = 0; i < keys->items.size(); ++i) {
        const auto* key_object = get(keys->items[i]);
        const auto* string = key_object ? std::get_if<String>(&key_object->value) : nullptr;
        if (string && string->text == key) return values->items[i];
    }
    return std::nullopt;
}

namespace {

struct Failure {
    Error error;
    size_t offset;
    Reference object;
};

class Reader {
public:
    explicit Reader(std::string_view input) : input_(input) {}

    Archive read_archive() {
        if (integer() != 1) fail(Error::UnsupportedArchiveVersion);
        Archive archive;
        const auto class_count = count(16);
        archive.classes.reserve(class_count);
        for (uint32_t i = 0; i < class_count; ++i) {
            if (integer() != static_cast<int32_t>(i + 1)) fail(Error::InvalidDirectory);
            const auto version = integer();
            const auto name = tagged_bytes('*');
            if (version < 0 || name.empty() ||
                std::any_of(name.begin(), name.end(), [](unsigned char ch) { return ch < 0x21 || ch > 0x7e; })) {
                fail(Error::InvalidDirectory);
            }
            archive.classes.push_back({version, std::string(name)});
        }

        object_count_ = count(5);
        if (!object_count_) fail(Error::MissingRoot);
        archive.objects.reserve(object_count_);
        for (uint32_t i = 0; i < object_count_; ++i) {
            const auto number = integer();
            if (number < 1 || static_cast<uint32_t>(number) > class_count) fail(Error::InvalidDirectory);
            archive.objects.push_back({static_cast<uint32_t>(number), Dictionary{}});
        }
        for (auto& object : archive.objects) {
            ++object_;
            read_body(object, archive.classes[object.class_number - 1]);
        }
        if (remaining()) fail(Error::TrailingBytes);
        return archive;
    }

    size_t offset() const noexcept { return at_; }

private:
    [[noreturn]] void fail(Error error) const { throw Failure{error, at_, object_}; }

    size_t remaining() const noexcept { return input_.size() - at_; }

    std::string_view take(size_t bytes) {
        if (bytes > remaining()) fail(Error::Truncated);
        const auto result = input_.substr(at_, bytes);
        at_ += bytes;
        return result;
    }

    void tag(char expected) {
        if (take(1).front() != expected) fail(Error::UnexpectedTag);
    }

    uint64_t big_endian(size_t size) {
        uint64_t bits = 0;
        for (unsigned char byte : take(size)) bits = (bits << 8) | byte;
        return bits;
    }

    uint32_t integer_bits() {
        tag('i');
        return static_cast<uint32_t>(big_endian(4));
    }

    int32_t integer() {
        const auto bits = integer_bits();
        int32_t result;
        std::memcpy(&result, &bits, sizeof(result));
        return result;
    }

    uint32_t count(size_t minimum_bytes) {
        const int32_t n = integer();
        if (n < 0) fail(Error::InvalidDirectory);
        if (static_cast<uint32_t>(n) > remaining() / minimum_bytes) fail(Error::Truncated);
        return static_cast<uint32_t>(n);
    }

    std::string_view tagged_bytes(char expected) {
        tag(expected);
        const auto n = integer();
        if (n < 0) fail(Error::InvalidBody);
        return take(static_cast<size_t>(n));
    }

    char character() {
        tag('c');
        return take(1).front();
    }

    bool boolean() { return character() == 'Y'; }

    Reference reference() {
        const auto ref = integer_bits();
        if (ref > object_count_) fail(Error::InvalidReference);
        return ref;
    }

    List read_list(int32_t version) {
        if (version > 3) fail(Error::UnsupportedClassVersion);
        List list{};
        if (version >= 2) list.avoids_retaining_objects = boolean();
        if (version >= 3) list.accepts_null = boolean();
        const size_t n = count(5);
        list.items.reserve(n);
        for (size_t i = 0; i < n; ++i) list.items.push_back(reference());
        return list;
    }

    static char16_t mode_zero(unsigned char ch) {
        if (ch >= 32 && ch <= 126) return ch;
        const auto* end = std::end(legacy_archive_characters);
        const auto* pair = std::lower_bound(std::begin(legacy_archive_characters), end, ch,
                                            [](const auto& row, unsigned char byte) { return row.byte < byte; });
        return pair != end && pair->byte == ch ? static_cast<char16_t>(pair->unicode) : u'\ufffd';
    }

    String read_string(int32_t version) {
        if (version > 3) fail(Error::UnsupportedClassVersion);
        String value{version >= 2 ? integer() : 0, false, {}};
        if (value.encoding == 0) {
            const auto raw = tagged_bytes('b');
            if (raw.empty() || raw.back() != '\0') fail(Error::InvalidBody);
            const auto text = raw.substr(0, raw.find('\0'));
            value.text.reserve(text.size());
            for (unsigned char byte : text) value.text.push_back(mode_zero(byte));
        } else if (value.encoding == 5) {
            const auto mark = tagged_bytes('b');
            const bool big = mark == std::string_view("\xfe\xff", 2);
            if (!big && mark != std::string_view("\xff\xfe", 2)) fail(Error::InvalidBody);
            const auto raw = tagged_bytes('b');
            if (raw.size() < 2 || (raw.size() % 2) || raw.substr(raw.size() - 2) != std::string_view("\0\0", 2)) {
                fail(Error::InvalidBody);
            }
            value.text.reserve(raw.size() / 2 - 1);
            const size_t low = big ? 1 : 0;
            for (size_t pos = 0; pos < raw.size() - 2; pos += 2) {
                const auto lo = static_cast<unsigned char>(raw[pos + low]);
                const auto hi = static_cast<unsigned char>(raw[pos + 1 - low]);
                value.text.push_back(static_cast<char16_t>(lo | (hi << 8)));
            }
        } else {
            fail(Error::UnsupportedEncoding);
        }
        value.mutable_value = boolean();
        return value;
    }

    Number read_number(int32_t version) {
        if (version > 2) fail(Error::UnsupportedClassVersion);
        const char kind = character();
        if (kind == 'i') return {kind, integer_bits(), true};
        if (kind == 'b') return {kind, boolean() ? uint64_t{1} : uint64_t{0}, true};
        if (version < 2) fail(Error::UnsupportedClassVersion);
        switch (kind) {
            case 'f': tag('f'); return {kind, big_endian(4), true};
            case 'd': tag('d'); return {kind, big_endian(8), true};
            case 'l': return {kind, 0, false};
            default: fail(Error::InvalidBody);
        }
    }

    Data read_data() {
        if (integer() != 0) fail(Error::UnsupportedCompression);
        const auto length = integer();
        const auto raw = tagged_bytes('b');
        if (length < 0 || static_cast<size_t>(length) != raw.size()) fail(Error::InvalidBody);
        return {std::vector<uint8_t>(raw.begin(), raw.end())};
    }

    void read_body(Object& object, const ClassEntry& cls) {
        if (cls.name == "GNDictionary") object.value = Dictionary{reference(), reference()};
        else if (cls.name == "GNList") object.value = read_list(cls.version);
        else if (cls.name == "GNString") object.value = read_string(cls.version);
        else if (cls.name == "GNNumber") object.value = read_number(cls.version);
        else if (cls.name == "GNData") object.value = read_data();
        else fail(Error::UnsupportedClass);
    }

    std::string_view input_;
    size_t at_ = 0;
    uint32_t object_count_ = 0;
    Reference object_ = 0;
};

} // namespace

DecodeResult decode(std::string_view bytes) {
    Reader reader(bytes);
    try {
        auto archive = reader.read_archive();
        return {std::move(archive), Error::None, reader.offset(), 0};
    } catch (const Failure& failure) {
        return {std::nullopt, failure.error, failure.offset, failure.object};
    }
}

} // namespace elastik_state
