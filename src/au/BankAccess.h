#pragma once
#include <CoreFoundation/CoreFoundation.h>
#include <array>
#include <filesystem>
#include <memory>
#include <string>

namespace sophistryMac {
// Keep a resolved grant alive for the lifetime of the AU instance. Bookmark
// bytes are private preferences and never part of a diagnostic/report.
struct BankAccess {
  CFURLRef url = nullptr;
  bool granted = false;
  ~BankAccess() {
    if (granted)
      CFURLStopAccessingSecurityScopedResource(url);
    if (url)
      CFRelease(url);
  }
};
inline CFDataRef createBankBookmark(CFURLRef url) {
  CFDataRef bookmark = CFURLCreateBookmarkData(
      nullptr, url,
      kCFURLBookmarkCreationWithSecurityScope |
          kCFURLBookmarkCreationSecurityScopeAllowOnlyReadAccess,
      nullptr, nullptr, nullptr);
  if (!bookmark)
    bookmark =
        CFURLCreateBookmarkData(nullptr, url, 0, nullptr, nullptr, nullptr);
  return bookmark;
}
inline std::shared_ptr<BankAccess>
openBankBookmark(CFDataRef data, const std::string &expected) {
  if (!data || CFGetTypeID(data) != CFDataGetTypeID())
    return {};
  Boolean stale = false;
  CFURLRef url = CFURLCreateByResolvingBookmarkData(
      nullptr, data,
      kCFURLBookmarkResolutionWithSecurityScope |
          kCFURLBookmarkResolutionWithoutUIMask,
      nullptr, nullptr, &stale, nullptr);
  if (!url)
    return {};
  auto access = std::make_shared<BankAccess>();
  access->url = url;
  std::array<UInt8, 4096> path{};
  if (!CFURLGetFileSystemRepresentation(url, true, path.data(), path.size()) ||
      std::filesystem::path(reinterpret_cast<const char *>(path.data()))
              .lexically_normal() !=
          std::filesystem::path(expected).lexically_normal())
    return {};
  access->granted = CFURLStartAccessingSecurityScopedResource(url);
  return access;
}
inline std::shared_ptr<BankAccess> storedBankAccess(const std::string &path) {
  CFPropertyListRef value = CFPreferencesCopyValue(
      CFSTR("SophistryARMSampleBookmark"), CFSTR("com.linplug.Sophistry"),
      kCFPreferencesCurrentUser, kCFPreferencesAnyHost);
  std::shared_ptr<BankAccess> access;
  if (value && CFGetTypeID(value) == CFDataGetTypeID())
    access = openBankBookmark(static_cast<CFDataRef>(value), path);
  if (value)
    CFRelease(value);
  return access;
}
} // namespace sophistryMac
