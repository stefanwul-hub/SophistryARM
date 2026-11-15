// Local-only setup. No serial is accepted in argv, logged, or sent over a
// network.
#include "../engine/LegacyEngine.h"
#import <AppKit/AppKit.h>
#include <CoreFoundation/CoreFoundation.h>
#include <algorithm>
#include <array>
#include <cerrno>
#include <fcntl.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unistd.h>
#include <vector>

namespace {
CFStringRef const domain = CFSTR("com.linplug.Sophistry");
std::string quote(const std::string &s) {
  std::string out = "\"";
  for (unsigned char c : s) {
    if (c == '"' || c == '\\') {
      out += '\\';
      out += char(c);
    } else if (c == '\n')
      out += "\\n";
    else if (c >= 32)
      out += char(c);
  }
  return out + '"';
}
std::string utf8(CFStringRef s) {
  if (!s)
    return {};
  CFIndex n = CFStringGetMaximumSizeForEncoding(CFStringGetLength(s),
                                                kCFStringEncodingUTF8) +
              1;
  if (n < 1 || n > 65536)
    throw std::runtime_error("Invalid local preference length");
  std::vector<char> bytes(n);
  if (!CFStringGetCString(s, bytes.data(), n, kCFStringEncodingUTF8))
    throw std::runtime_error("Invalid local preference encoding");
  return bytes.data();
}
CFPropertyListRef copyPreference(CFStringRef key) {
  return CFPreferencesCopyValue(key, domain, kCFPreferencesCurrentUser,
                                kCFPreferencesAnyHost);
}
std::filesystem::path currentRoot() {
  CFPropertyListRef value = copyPreference(CFSTR("SophistryARMSampleRoot"));
  if (!value)
    return {};
  std::string result;
  if (CFGetTypeID(value) == CFStringGetTypeID())
    result = utf8(static_cast<CFStringRef>(value));
  CFRelease(value);
  return result;
}
void privateBackup(const std::filesystem::path &directory) {
  namespace fs = std::filesystem;
  fs::create_directories(directory);
  fs::permissions(directory, fs::perms::owner_all, fs::perm_options::replace);
  CFMutableDictionaryRef dict =
      CFDictionaryCreateMutable(nullptr, 0, &kCFTypeDictionaryKeyCallBacks,
                                &kCFTypeDictionaryValueCallBacks);
  if (!dict)
    throw std::bad_alloc();
  for (CFStringRef key :
       {CFSTR("SophistrySysGlo"), CFSTR("SophistryARMSampleRoot")}) {
    CFPropertyListRef value = copyPreference(key);
    CFDictionarySetValue(dict, key, value ? value : kCFBooleanFalse);
    if (value)
      CFRelease(value);
  }
  CFDataRef data = CFPropertyListCreateData(
      nullptr, dict, kCFPropertyListXMLFormat_v1_0, 0, nullptr);
  CFRelease(dict);
  if (!data)
    throw std::runtime_error("Cannot serialize private preference backup");
  auto filename = directory / "Preferences-privees-avant-installation.plist";
  int fd = ::open(filename.c_str(), O_WRONLY | O_CREAT | O_EXCL, 0600);
  if (fd < 0) {
    CFRelease(data);
    throw std::runtime_error("Cannot create private preference backup");
  }
  const UInt8 *bytes = CFDataGetBytePtr(data);
  std::size_t count = CFDataGetLength(data), offset = 0;
  bool ok = true;
  while (offset < count) {
    ssize_t n = ::write(fd, bytes + offset, count - offset);
    if (n < 0 && errno == EINTR)
      continue;
    if (n <= 0) {
      ok = false;
      break;
    }
    offset += std::size_t(n);
  }
  if (ok)
    ok = ::fsync(fd) == 0;
  if (::close(fd))
    ok = false;
  CFRelease(data);
  if (!ok)
    throw std::runtime_error("Cannot finish private preference backup");
}
void restorePrivateBackup(const std::filesystem::path &file) {
  std::ifstream input(file, std::ios::binary);
  if (!input)
    throw std::runtime_error("Cannot read private preference backup");
  std::vector<UInt8> bytes((std::istreambuf_iterator<char>(input)), {});
  if (bytes.empty() || bytes.size() > 131072)
    throw std::runtime_error("Invalid private preference backup size");
  CFDataRef data = CFDataCreate(nullptr, bytes.data(), bytes.size());
  if (!data)
    throw std::bad_alloc();
  CFPropertyListRef plist = CFPropertyListCreateWithData(
      nullptr, data, kCFPropertyListImmutable, nullptr, nullptr);
  CFRelease(data);
  if (!plist || CFGetTypeID(plist) != CFDictionaryGetTypeID()) {
    if (plist)
      CFRelease(plist);
    throw std::runtime_error("Invalid private preference backup");
  }
  auto dict = static_cast<CFDictionaryRef>(plist);
  // Validate both fields before changing either; all other legacy preferences
  // stay intact.
  for (CFStringRef key :
       {CFSTR("SophistrySysGlo"), CFSTR("SophistryARMSampleRoot")}) {
    CFTypeRef value = CFDictionaryGetValue(dict, key);
    if (!value || (value != kCFBooleanFalse &&
                   CFGetTypeID(value) != CFStringGetTypeID())) {
      CFRelease(plist);
      throw std::runtime_error("Invalid private preference backup fields");
    }
  }
  for (CFStringRef key :
       {CFSTR("SophistrySysGlo"), CFSTR("SophistryARMSampleRoot")}) {
    CFTypeRef value = CFDictionaryGetValue(dict, key);
    CFPreferencesSetValue(key, value == kCFBooleanFalse ? nullptr : value,
                          domain, kCFPreferencesCurrentUser,
                          kCFPreferencesAnyHost);
  }
  CFRelease(plist);
  if (!CFPreferencesSynchronize(domain, kCFPreferencesCurrentUser,
                                kCFPreferencesAnyHost))
    throw std::runtime_error("Cannot restore local preference backup");
}
std::filesystem::path chooseRoot() {
  [NSApplication sharedApplication];
  [NSApp setActivationPolicy:NSApplicationActivationPolicyAccessory];
  [NSApp activateIgnoringOtherApps:YES];
  NSOpenPanel *panel = [NSOpenPanel openPanel];
  panel.title = @"Banque de sons Sophistry";
  panel.message =
      @"Choisissez le dossier contenant votre banque et ses samples d’origine.";
  panel.canChooseDirectories = YES;
  panel.canChooseFiles = NO;
  panel.allowsMultipleSelection = NO;
  panel.resolvesAliases = YES;
  panel.prompt = @"Choisir ce dossier";
  if ([panel runModal] != NSModalResponseOK || !panel.URL)
    throw std::runtime_error("Configuration cancelled before installation");
  return panel.URL.fileSystemRepresentation;
}
} // namespace

int main(int argc, char **argv) {
  @autoreleasepool {
    bool fromStdin = false, checkOnly = false, noPanel = false,
         accepted = false, persisted = false, backupSaved = false,
         rootConfigured = false;
    std::string stage = "arguments", error;
    std::filesystem::path root, backup, restore;
    std::vector<std::string> assets;
    try {
      for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        auto next = [&]() {
          if (++i >= argc)
            throw std::runtime_error("Missing argument");
          return std::string(argv[i]);
        };
        if (arg == "--registration-from-stdin")
          fromStdin = true;
        else if (arg == "--check")
          checkOnly = true;
        else if (arg == "--no-folder-panel")
          noPanel = true;
        else if (arg == "--bank-root")
          root = next();
        else if (arg == "--backup-directory")
          backup = next();
        else if (arg == "--restore-backup")
          restore = next();
        else if (arg == "--asset-directory")
          assets.push_back(next());
        else
          throw std::runtime_error("Unknown setup argument");
      }
      if (!restore.empty()) {
        if (fromStdin || checkOnly || !root.empty() || !backup.empty())
          throw std::runtime_error(
              "Preference restore is a separate local operation");
        restorePrivateBackup(restore);
        std::cout << "{\"preferences_restored\":true,\"private_data_in_"
                     "report\":false}\n";
        return 0;
      }
      if (checkOnly && fromStdin)
        throw std::runtime_error(
            "Read-only check does not accept private input");
      if (!checkOnly && backup.empty())
        throw std::runtime_error("A private backup directory is required");
      if (root.empty())
        root = currentRoot();
      std::error_code ec;
      if (root.empty() || !std::filesystem::is_directory(root, ec)) {
        if (checkOnly || noPanel)
          throw std::runtime_error(
              "Select the local Sophistry sample bank first");
        stage = "sample bank folder";
        root = chooseRoot();
      }
      if (!std::filesystem::is_directory(root, ec) || ec)
        throw std::runtime_error("Selected bank folder is unavailable");
      root = std::filesystem::weakly_canonical(root);
      rootConfigured = true;
      stage = "original registration check";
      sophistry::LegacyEngineConfig config;
      config.audioUnitMode = true;
      config.useLocalMacPreferences = true;
      config.recycleFreedBlocks = true;
      config.collectDiagnostics = false;
      config.recursiveAssetSearch = true;
      config.guestMemoryBytes = 256u * 1024u * 1024u;
      config.assetDirectories.push_back(root.string());
      config.assetDirectories.insert(config.assetDirectories.end(),
                                     assets.begin(), assets.end());
      sophistry::LegacyEngine engine(config);
      engine.initialize();
      if (fromStdin) {
        std::string key;
        if (!std::getline(std::cin, key) || key.empty())
          throw std::runtime_error("No private registration input");
        if (key.back() == '\r')
          key.pop_back();
        if (key.empty() || key.size() > 319)
          throw std::runtime_error("Invalid private input length");
        engine.setPrivateRegistration(key);
        std::fill(key.begin(), key.end(), '\0');
      }
      engine.setSampleRate(44100);
      engine.setBlockSize(512);
      engine.activate();
      // The acceptance flag is written exclusively by the original code.
      if (!engine.registrationAccepted()) {
        std::array<float, 1> left{}, right{};
        float *outputs[] = {left.data(), right.data()};
        engine.process(outputs, 2, 1);
      }
      accepted = engine.registrationAccepted();
      if (!accepted)
        throw std::runtime_error(
            "Original Sophistry registration check rejected the local licence");
      if (!checkOnly) {
        stage = "private local preference backup";
        privateBackup(backup);
        backupSaved = true;
        if (fromStdin) {
          stage = "original SysGlo serialization and local save";
          engine.persistValidatedRegistration();
          persisted = true;
        }
        stage = "local sample bank preference";
        CFStringRef value = CFStringCreateWithCString(
            nullptr, root.string().c_str(), kCFStringEncodingUTF8);
        if (!value)
          throw std::bad_alloc();
        CFPreferencesSetValue(CFSTR("SophistryARMSampleRoot"), value, domain,
                              kCFPreferencesCurrentUser, kCFPreferencesAnyHost);
        CFRelease(value);
        if (!CFPreferencesSynchronize(domain, kCFPreferencesCurrentUser,
                                      kCFPreferencesAnyHost))
          throw std::runtime_error("Cannot synchronize local bank preference");
      }
      engine.deactivate();
      stage = "completed";
    } catch (const std::exception &e) {
      error = e.what();
    }
    std::cout
        << "{\"stage\":" << quote(stage)
        << ",\"error\":" << (error.empty() ? "null" : quote(error))
        << ",\"read_only_check\":" << (checkOnly ? "true" : "false")
        << ",\"private_registration_input\":" << (fromStdin ? "true" : "false")
        << ",\"registration_accepted\":" << (accepted ? "true" : "false")
        << ",\"registration_persisted\":" << (persisted ? "true" : "false")
        << ",\"sample_root_configured\":" << (rootConfigured ? "true" : "false")
        << ",\"private_backup_saved\":" << (backupSaved ? "true" : "false")
        << ",\"private_backup_in_report\":false}\n";
    return error.empty() ? 0 : 1;
  }
}
