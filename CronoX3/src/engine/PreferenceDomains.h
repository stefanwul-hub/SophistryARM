#pragma once
#include <string>
#include <vector>

namespace sophistry {
// Comparison builds share the original licence as a read-only fallback.
// Every remembered path, editor setting and validated key is written separately.
inline constexpr const char* originalPreferenceDomain = "com.linplug.CronoX3";
inline constexpr const char* comparisonPreferenceDomain = "com.linplug.CronoX3.ARMTest";
inline std::string preferenceWriteDomain(const std::string& application) {
  return application == originalPreferenceDomain ? comparisonPreferenceDomain : application;
}
inline std::vector<std::string> preferenceReadDomains(const std::string& application) {
  if(application == originalPreferenceDomain)
    return {comparisonPreferenceDomain, originalPreferenceDomain};
  return {application};
}
} // namespace sophistry
