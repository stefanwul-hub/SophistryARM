#include "../src/OriginalArchivePropertyList.h"
#include "ArchiveOpenFixture.h"

#include <cstdio>
#include <cstring>
#include <memory>
#include <new>
#include <type_traits>

namespace {

bool write(const void* bytes, size_t length) {
    return !length || std::fwrite(bytes, 1, length, stdout) == length;
}

template <typename T> bool scalar(const T& value) {
    return write(&value, sizeof(value));
}

bool string(const std::u16string& text) {
    return scalar(static_cast<uint32_t>(text.size())) && write(text.data(), text.size() * 2);
}

bool value(const ElastikPropertyValue& node) {
    return std::visit([&node](const auto& item) {
        using T = std::decay_t<decltype(item)>;
        if constexpr (std::is_same_v<T, std::u16string>) {
            return scalar('s') && string(item);
        } else if constexpr (std::is_same_v<T, int32_t>) {
            return scalar('i') && scalar(item);
        } else if constexpr (std::is_same_v<T, float>) {
            return scalar('f') && scalar(item);
        } else if constexpr (std::is_same_v<T, ElastikPropertyValue::Data>) {
            return scalar('d') && scalar(static_cast<uint32_t>(item.size())) && write(item.data(), item.size());
        } else if constexpr (std::is_same_v<T, ElastikPropertyValue::Array>) {
            if (!scalar('a') || !scalar(static_cast<uint32_t>(item.size()))) return false;
            for (const auto& child : item) {
                if (!value(child)) return false;
            }
            return true;
        } else {
            if (!scalar('m') || !scalar(static_cast<uint32_t>(item.size()))) return false;
            for (const auto& entry : item) {
                if (node.find(entry.first) != &entry.second || !string(entry.first) || !value(entry.second)) {
                    return false;
                }
            }
            return true;
        }
    }, node.value);
}

bool document(const ElastikPropertyList& plist) {
    return scalar(plist.format) && scalar(plist.status) &&
           (plist.status != ElastikPropertyListStatus::Parsed || value(plist.root));
}

bool archive_property_list(std::string_view raw, uint32_t flags) {
    uint32_t length;
    if (std::fread(&length, 1, sizeof(length), stdin) != sizeof(length)) return false;
    std::unique_ptr<uint16_t, decltype(&std::free)> path(
        static_cast<uint16_t*>(std::malloc((length + 1) * sizeof(uint16_t))), &std::free);
    if (!path || std::fread(path.get(), sizeof(uint16_t), length, stdin) != length) return false;

    auto* bytes = static_cast<unsigned char*>(std::malloc(raw.size()));
    if (!bytes) return false;
    std::memcpy(bytes, raw.data(), raw.size());
    using Context = ArchiveOpenFixture::Context;
    void* storage = std::malloc(sizeof(Context));
    if (!storage) {
        std::free(bytes);
        return false;
    }
    std::unique_ptr<Context, decltype(&ArchiveNameFixture::cleanup)> c(
        new (storage) Context{}, &ArchiveNameFixture::cleanup);
    int settings[32]{};
    settings[0] = settings[2] = static_cast<int>(raw.size());
    settings[1] = length;
    settings[4] = settings[6] = settings[7] = settings[13] = 1;
    settings[10] = flags & 1;
    settings[11] = (flags >> 1) & 1;
    settings[12] = settings[14] = -1;
    ArchiveOpenFixture::setup(c.get(), settings, bytes, path.release());

    const int opened = elastik_original_archive_open_read(
        &c->container, reinterpret_cast<void*>(1), &c->opening);
    if (!scalar(opened)) return false;
    if (opened != ElastikArchiveOk) return true;
    ElastikArchiveStatus status;
    auto* plist_path = elastik_original_archive_path_for_container(
        &c->container, reinterpret_cast<void*>(1000), &c->opening, &status);
    if (!scalar(static_cast<int>(status))) return false;
    const auto result = elastik_original_archive_plist(plist_path, &c->factory);
    return scalar(static_cast<int>(result.archive_status)) &&
           scalar(static_cast<uint8_t>(result.document.has_value())) &&
           (!result.document || document(*result.document));
}

} // namespace

int main() {
    for (;;) {
        uint32_t header[3];
        const size_t count = std::fread(header, 1, sizeof(header), stdin);
        if (count == 0 && std::feof(stdin)) return 0;
        if (count != sizeof(header)) return 2;
        std::string raw(header[0], '\0');
        if (std::fread(raw.data(), 1, raw.size(), stdin) != raw.size()) return 2;
        const bool has_reader = header[1] != 0;
        if (header[2] == 2) {
            if (!archive_property_list(raw, header[1])) return 3;
        } else if (header[2] == 1) {
            if (!document(elastik_original_plist(raw, has_reader))) return 3;
        } else if (!scalar(elastik_original_plist_format(raw, has_reader))) {
            return 3;
        }
        if (std::fflush(stdout) != 0) return 3;
    }
}
