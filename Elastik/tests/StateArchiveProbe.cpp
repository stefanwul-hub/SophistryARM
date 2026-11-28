#include "../src/OriginalStateArchive.h"

#include <cstdio>
#include <type_traits>

namespace {

using namespace elastik_state;

bool write(const void* bytes, size_t count) {
    return !count || std::fwrite(bytes, 1, count, stdout) == count;
}

template <class T>
bool scalar(T value) {
    return write(&value, sizeof(value));
}

bool object(const Object& object) {
    if (!scalar(object.class_number)) return false;
    return std::visit([](const auto& value) {
        using T = std::decay_t<decltype(value)>;
        if constexpr (std::is_same_v<T, Dictionary>) {
            return scalar('m') && scalar(value.keys) && scalar(value.values);
        } else if constexpr (std::is_same_v<T, List>) {
            return scalar('a') && scalar(static_cast<uint8_t>(value.avoids_retaining_objects)) &&
                scalar(static_cast<uint8_t>(value.accepts_null)) &&
                scalar(static_cast<uint32_t>(value.items.size())) &&
                write(value.items.data(), value.items.size() * sizeof(Reference));
        } else if constexpr (std::is_same_v<T, String>) {
            return scalar('s') && scalar(value.encoding) &&
                scalar(static_cast<uint8_t>(value.mutable_value)) &&
                scalar(static_cast<uint32_t>(value.text.size())) &&
                write(value.text.data(), value.text.size() * sizeof(char16_t));
        } else if constexpr (std::is_same_v<T, Number>) {
            return scalar('n') && scalar(value.kind) &&
                scalar(static_cast<uint8_t>(value.payload_present)) && scalar(value.bits);
        } else {
            return scalar('d') && scalar(static_cast<uint32_t>(value.bytes.size())) &&
                write(value.bytes.data(), value.bytes.size());
        }
    }, object.value);
}

bool run(uint32_t count, uint32_t queries) {
    std::string raw(count, '\0');
    if (std::fread(raw.data(), 1, raw.size(), stdin) != count) return false;
    auto result = decode(raw);
    if (!scalar(result.error) || !scalar(result.object) ||
        !scalar(static_cast<uint32_t>(result.offset))) return false;
    if (!result.archive) return !queries;

    const auto& archive = *result.archive;
    if (!scalar(static_cast<uint32_t>(archive.classes.size()))) return false;
    for (const auto& cls : archive.classes) {
        if (!scalar(cls.version) || !scalar(static_cast<uint32_t>(cls.name.size())) ||
            !write(cls.name.data(), cls.name.size())) return false;
    }
    if (!scalar(static_cast<uint32_t>(archive.objects.size()))) return false;
    for (const auto& entry : archive.objects) {
        if (!object(entry)) return false;
    }
    for (uint32_t i = 0; i < queries; ++i) {
        uint32_t query[2];
        if (std::fread(query, sizeof(uint32_t), 2, stdin) != 2) return false;
        std::u16string key(query[1], u'\0');
        if (std::fread(key.data(), sizeof(char16_t), key.size(), stdin) != key.size()) return false;
        const auto found = archive.find_key(query[0], key);
        if (!scalar(static_cast<uint8_t>(found.has_value())) || (found && !scalar(*found))) return false;
    }
    return true;
}

} // namespace

int main() {
    for (;;) {
        uint32_t header[2];
        const size_t in = std::fread(header, 1, sizeof(header), stdin);
        if (!in && std::feof(stdin)) return 0;
        if (in != sizeof(header) || !run(header[0], header[1]) || std::fflush(stdout)) return 2;
    }
}
