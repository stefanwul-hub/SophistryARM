#pragma once

#include <cstdint>
#include <string>
#include <string_view>
#include <utility>
#include <variant>
#include <vector>

struct ElastikPropertyValue {
    using Array = std::vector<ElastikPropertyValue>;
    using Dictionary = std::vector<std::pair<std::u16string, ElastikPropertyValue>>;
    using Data = std::vector<uint8_t>;

    std::variant<std::u16string, int32_t, float, Data, Array, Dictionary> value;
    const ElastikPropertyValue* find(std::u16string_view key) const noexcept;
};

enum class ElastikPropertyListFormat : uint8_t { Xml, OpenStepPath, OpenStepData };
enum class ElastikPropertyListStatus : uint8_t { XmlPending, Invalid, Parsed, NestingLimit };

struct ElastikPropertyList {
    ElastikPropertyListFormat format;
    ElastikPropertyListStatus status;
    ElastikPropertyValue root;
};

// Original 0x1a4cb0 (path stream), 0x1a4e18 (materialized data), and
// the routing in 0x6739a. has_reader controls the initial path probe.
ElastikPropertyListFormat elastik_original_plist_format(std::string_view bytes,
                                                        bool has_reader) noexcept;

// OpenStep branch of 0x6739a. Accepts a complete member's bytes. The XML
// branch remains an explicit pending result. Allocations can propagate
// std::bad_alloc. The ARM64 parser bounds recursive nesting on hostile input.
ElastikPropertyList elastik_original_plist(std::string_view bytes, bool has_reader);
