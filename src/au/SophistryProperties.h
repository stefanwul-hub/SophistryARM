#pragma once
#include <cstdint>
namespace sophistry {
constexpr char wrapperVersion[] = "SophistryARM CP-019";
// Private properties use flat bytes, never process-local CF pointers: Logic
// can host the audio unit and its Cocoa view in separate processes.
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
constexpr std::uint32_t reloadStateProperty = 0x5370526c; // SpRl, UInt32=1
} // namespace sophistry
