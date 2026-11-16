#pragma once
#include <cstdint>
namespace sophistry {
constexpr char wrapperVersion[] = "SophistryARM CP-024";
// Private editor properties are for a view with a local AU handle.
// Flat bytes avoid sharing object pointers, but the macOS remote proxy may
// reject these IDs. Host-side remote tests must use public AU properties.
// Runtime status contains no licence or raw state; sample names are basenames.
constexpr std::uint32_t runtimeStatusBytes = 128u * 1024u;
constexpr std::uint32_t runtimeStatusProperty =
    0x53705374; // SpSt, fixed-size zero-padded UTF-8 JSON
constexpr std::uint32_t importProgramProperty =
    0x53705072; // SpPr, raw program chunk, 1..1048576 bytes
struct BankLocationHeader {
  std::uint32_t version = 1, pathBytes = 0, bookmarkBytes = 0;
};
static_assert(sizeof(BankLocationHeader) == 12);
// SpBr: header, NUL-terminated UTF-8 path, private bookmark bytes.
constexpr std::uint32_t sampleRootProperty = 0x53704272;
constexpr std::uint32_t reloadStateProperty = 0x5370526c;    // SpRl, UInt32=1
constexpr std::uint32_t generatorPanelProperty = 0x53704770; // SpGp, flat state
constexpr std::uint32_t generatorEditProperty = 0x53704765;  // SpGe, flat edit
} // namespace sophistry
