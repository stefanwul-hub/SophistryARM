#pragma once
#include <cstdint>
#include <vector>
namespace sophistry {
struct LegacyRecord {
    std::uint32_t tag=0, index=0;
    std::vector<std::uint8_t> payload;
    std::vector<LegacyRecord> children;
};
struct LegacyState {
    bool little_endian=true;
    std::vector<LegacyRecord> records;
};
// Structural container reader only; it does not create a DSP graph or restore AU parameters.
LegacyState read_legacy_state(const std::vector<std::uint8_t>& bytes);
std::vector<std::uint8_t> write_legacy_state(const LegacyState& state);
}
