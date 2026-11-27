#pragma once

#include <array>
#include <cstdint>
#include <string>
#include <string_view>
#include <utility>
#include <variant>
#include <vector>

// Raw Gregorian constructor arguments, in year/month/day/hour/minute/second
// order. An empty date requests the GN runtime's default instant.
struct ElastikPropertyDate {
    std::array<int32_t, 6> calendar{};
    bool use_current_time = false;
};

struct ElastikPropertyValue {
    using Array = std::vector<ElastikPropertyValue>;
    using Dictionary = std::vector<std::pair<std::u16string, ElastikPropertyValue>>;
    using Data = std::vector<uint8_t>;

    std::variant<std::u16string, int32_t, int64_t, float, bool, ElastikPropertyDate, Data, Array, Dictionary> value;
    const ElastikPropertyValue* find(std::u16string_view key) const noexcept;
};

enum class ElastikPropertyListFormat : uint8_t { Xml, OpenStepPath, OpenStepData };
enum class ElastikPropertyListStatus : uint8_t { Invalid = 1, Parsed, NestingLimit };

struct ElastikPropertyList {
    ElastikPropertyListFormat format;
    ElastikPropertyListStatus status;
    ElastikPropertyValue root;
};

// Original 0x1a4cb0 (path stream), 0x1a4e18 (materialized data), and
// the routing in 0x6739a. has_reader controls the initial path probe.
ElastikPropertyListFormat elastik_original_plist_format(std::string_view bytes,
                                                        bool has_reader) noexcept;

// Original 0x6739a, accepting a complete member's bytes. Allocations can
// propagate std::bad_alloc. Parsed values are limited to 128 levels.
ElastikPropertyList elastik_original_plist(std::string_view bytes, bool has_reader);
