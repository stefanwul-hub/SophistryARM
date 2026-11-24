// Generated from the pinned original; guest bytes are never executed.
#pragma once
#include <cstddef>
#include <cstdint>
namespace sophistry {
struct LegacyImport { std::uint32_t address; const char* name; };
extern const unsigned char legacy_image_data[];
extern const std::size_t legacy_image_size;
extern const LegacyImport legacy_imports[];
extern const std::size_t legacy_import_count;
extern const std::uint32_t legacy_initializers[];
extern const std::size_t legacy_initializer_count;
}
