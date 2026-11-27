#pragma once

#include "../src/OriginalPropertyList.h"

#include <cstdio>
#include <type_traits>

namespace property_list_probe_io {

inline bool write(const void* bytes, size_t length) {
    return !length || std::fwrite(bytes, 1, length, stdout) == length;
}

template <typename T> bool scalar(const T& value) {
    return write(&value, sizeof(value));
}

inline bool string(const std::u16string& text) {
    return scalar(static_cast<uint32_t>(text.size())) && write(text.data(), text.size() * 2);
}

inline bool value(const ElastikPropertyValue& node) {
    return std::visit([&node](const auto& item) {
        using T = std::decay_t<decltype(item)>;
        if constexpr (std::is_same_v<T, std::u16string>) {
            return scalar('s') && string(item);
        } else if constexpr (std::is_same_v<T, int32_t>) {
            return scalar('i') && scalar(item);
        } else if constexpr (std::is_same_v<T, int64_t>) {
            return scalar('q') && scalar(item);
        } else if constexpr (std::is_same_v<T, bool>) {
            return scalar('b') && scalar(static_cast<uint8_t>(item));
        } else if constexpr (std::is_same_v<T, ElastikPropertyDate>) {
            return scalar('t') && scalar(static_cast<uint8_t>(item.use_current_time)) &&
                   write(item.calendar.data(), item.calendar.size() * sizeof(int32_t));
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

inline bool document(const ElastikPropertyList& plist) {
    return scalar(plist.format) && scalar(plist.status) &&
           (plist.status != ElastikPropertyListStatus::Parsed || value(plist.root));
}

} // namespace property_list_probe_io
