#pragma once
#include <string>

namespace sophistry {
// Presets can store Windows, HFS or POSIX names. This is a display-only
// operation: the original path and chunk continue to reach the engine.
inline std::string sampleDisplayName(const std::string &path) {
  const auto separator = path.find_last_of("/\\:");
  return separator == std::string::npos ? path : path.substr(separator + 1);
}
} // namespace sophistry
