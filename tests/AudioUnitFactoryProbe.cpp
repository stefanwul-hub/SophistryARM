// Exercise the compiled AU factory in this process, without system
// installation.
#include <AudioToolbox/AudioToolbox.h>
#include <CoreFoundation/CoreFoundation.h>
#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace {
constexpr UInt32 registrationProperty = 0x53705267;
std::string quote(const std::string &s) {
  std::ostringstream o;
  o << '"';
  for (unsigned char c : s) {
    if (c == '"' || c == '\\')
      o << '\\' << c;
    else if (c == '\n')
      o << "\\n";
    else if (c >= 32)
      o << c;
  }
  o << '"';
  return o.str();
}
std::string text(CFStringRef s) {
  if (!s)
    return {};
  std::vector<char> b(CFStringGetMaximumSizeForEncoding(CFStringGetLength(s),
                                                        kCFStringEncodingUTF8) +
                      1);
  if (!CFStringGetCString(s, b.data(), b.size(), kCFStringEncodingUTF8))
    throw std::runtime_error("CFString conversion");
  return b.data();
}
std::string diagnostic(AudioUnit unit, UInt32 property) {
  CFStringRef value = nullptr;
  UInt32 bytes = sizeof(value);
  if (AudioUnitGetProperty(unit, property, kAudioUnitScope_Global, 0, &value,
                           &bytes) ||
      !value)
    return {};
  std::string result = text(value);
  CFRelease(value);
  return result;
}
void check(OSStatus s, const char *label) {
  if (s)
    throw std::runtime_error(std::string(label) + ": OSStatus " +
                             std::to_string(s));
}
CFPropertyListRef readPlist(const std::filesystem::path &path) {
  std::ifstream f(path, std::ios::binary);
  if (!f)
    throw std::runtime_error("Cannot read fixture");
  std::vector<UInt8> b((std::istreambuf_iterator<char>(f)), {});
  CFDataRef d = CFDataCreate(nullptr, b.data(), b.size());
  CFPropertyListRef p = CFPropertyListCreateWithData(
      nullptr, d, kCFPropertyListImmutable, nullptr, nullptr);
  CFRelease(d);
  if (!p)
    throw std::runtime_error("Invalid fixture plist");
  return p;
}
double number(CFDictionaryRef d, CFStringRef k) {
  auto v = CFDictionaryGetValue(d, k);
  double n = 0;
  if (!v || CFGetTypeID(v) != CFNumberGetTypeID() ||
      !CFNumberGetValue(static_cast<CFNumberRef>(v), kCFNumberDoubleType, &n))
    throw std::runtime_error("Invalid numeric contract fixture");
  return n;
}
CFDataRef bank(CFPropertyListRef p) {
  if (!p || CFGetTypeID(p) != CFDictionaryGetTypeID())
    throw std::runtime_error("State is not a dictionary");
  auto d =
      CFDictionaryGetValue(static_cast<CFDictionaryRef>(p), CFSTR("vstdata"));
  if (!d || CFGetTypeID(d) != CFDataGetTypeID())
    throw std::runtime_error("State has no vstdata");
  return static_cast<CFDataRef>(d);
}
CFPropertyListRef save(AudioUnit unit) {
  CFPropertyListRef p = nullptr;
  UInt32 n = sizeof(p);
  check(AudioUnitGetProperty(unit, kAudioUnitProperty_ClassInfo,
                             kAudioUnitScope_Global, 0, &p, &n),
        "Save state");
  bank(p);
  return p;
}
void restore(AudioUnit unit, CFPropertyListRef p) {
  check(AudioUnitSetProperty(unit, kAudioUnitProperty_ClassInfo,
                             kAudioUnitScope_Global, 0, &p, sizeof(p)),
        "Restore state");
}
void configure(AudioUnit unit, UInt32 channels) {
  AudioStreamBasicDescription format{44100,
                                     kAudioFormatLinearPCM,
                                     kAudioFormatFlagIsFloat |
                                         kAudioFormatFlagIsPacked |
                                         kAudioFormatFlagIsNonInterleaved,
                                     4,
                                     1,
                                     4,
                                     channels,
                                     32,
                                     0};
  check(AudioUnitSetProperty(unit, kAudioUnitProperty_StreamFormat,
                             kAudioUnitScope_Output, 0, &format,
                             sizeof(format)),
        "Set stream format");
  UInt32 maximum = 512;
  check(AudioUnitSetProperty(unit, kAudioUnitProperty_MaximumFramesPerSlice,
                             kAudioUnitScope_Global, 0, &maximum,
                             sizeof(maximum)),
        "Set maximum frames");
}
void put16(std::ofstream &f, UInt32 n) {
  char b[2] = {char(n), char(n >> 8)};
  f.write(b, 2);
}
void put32(std::ofstream &f, UInt32 n) {
  char b[4] = {char(n), char(n >> 8), char(n >> 16), char(n >> 24)};
  f.write(b, 4);
}
void wave(const std::filesystem::path &path,
          const std::vector<std::vector<float>> &audio, UInt32 frames) {
  std::ofstream f(path, std::ios::binary);
  if (!f)
    throw std::runtime_error("Cannot write WAV");
  UInt32 channels = audio.size(), bytes = frames * channels * 4;
  f.write("RIFF", 4);
  put32(f, 36 + bytes);
  f.write("WAVEfmt ", 8);
  put32(f, 16);
  put16(f, 3);
  put16(f, channels);
  put32(f, 44100);
  put32(f, 44100 * channels * 4);
  put16(f, channels * 4);
  put16(f, 32);
  f.write("data", 4);
  put32(f, bytes);
  for (UInt32 i = 0; i < frames; ++i)
    for (UInt32 c = 0; c < channels; ++c)
      f.write(reinterpret_cast<const char *>(&audio[c][i]), 4);
  if (!f)
    throw std::runtime_error("WAV write failed");
}
struct Unit {
  AudioUnit value = nullptr;
  ~Unit() {
    if (value) {
      AudioUnitUninitialize(value);
      AudioComponentInstanceDispose(value);
    }
  }
};
} // namespace

int main(int argc, char **argv) {
  std::filesystem::path bundlePath, statePath, contractPath, prefix;
  bool privateInput = false;
  UInt32 channels = 2;
  std::string stage = "arguments", error;
  std::vector<std::string> passed;
  std::vector<double> peaks, rms;
  UInt32 frames = 132300, rendered = 0;
  bool audible = false;
  double renderSeconds = 0, maximumRenderCallSeconds = 0;
  std::string engineError, engineDiagnostics;
  Unit unit;
  CFBundleRef bundle = nullptr;
  CFPropertyListRef state = nullptr, contract = nullptr;
  try {
    for (int i = 1; i < argc; ++i) {
      std::string a = argv[i];
      auto next = [&]() {
        if (++i >= argc)
          throw std::runtime_error("Missing argument");
        return std::string(argv[i]);
      };
      if (a == "--bundle")
        bundlePath = next();
      else if (a == "--state")
        statePath = next();
      else if (a == "--contract")
        contractPath = next();
      else if (a == "--output-prefix")
        prefix = next();
      else if (a == "--channels")
        channels = UInt32(std::stoul(next()));
      else if (a == "--registration-from-stdin")
        privateInput = true;
      else
        throw std::runtime_error("Unknown argument");
    }
    if (bundlePath.empty() || statePath.empty() || contractPath.empty() ||
        prefix.empty() || (channels != 2 && channels != 6))
      throw std::runtime_error(
          "Required: --bundle --state --contract --output-prefix [--channels "
          "2|6] [--registration-from-stdin]");
    if (prefix.has_parent_path())
      std::filesystem::create_directories(prefix.parent_path());
    stage = "load candidate bundle";
    std::string absolute = std::filesystem::absolute(bundlePath).string();
    CFURLRef url = CFURLCreateFromFileSystemRepresentation(
        nullptr, reinterpret_cast<const UInt8 *>(absolute.data()),
        absolute.size(), true);
    bundle = CFBundleCreate(nullptr, url);
    CFRelease(url);
    if (!bundle || !CFBundleLoadExecutable(bundle))
      throw std::runtime_error("Cannot load candidate executable");
    auto factory = reinterpret_cast<AudioComponentFactoryFunction>(
        CFBundleGetFunctionPointerForName(bundle, CFSTR("SophistryAUFactory")));
    if (!factory)
      throw std::runtime_error("Missing SophistryAUFactory");
    AudioComponentDescription desc{0x61756d75, 0x536f7033, 0x4c696e50, 0, 0};
    AudioComponent component = AudioComponentRegister(
        &desc, CFSTR("LinPlug: Sophistry CP013 candidate"), 0x00030008,
        factory);
    if (!component)
      throw std::runtime_error("Process-local component registration failed");
    stage = "create instance";
    check(AudioComponentInstanceNew(component, &unit.value),
          "Create AU instance");
    passed.push_back("candidate factory loads without installation");
    if (privateInput) {
      std::string key;
      if (!std::getline(std::cin, key) || key.empty() || key.size() > 319)
        throw std::runtime_error("Missing private input");
      CFStringRef value = CFStringCreateWithCString(nullptr, key.c_str(),
                                                    kCFStringEncodingUTF8);
      std::fill(key.begin(), key.end(), '\0');
      OSStatus status = AudioUnitSetProperty(unit.value, registrationProperty,
                                             kAudioUnitScope_Global, 0, &value,
                                             sizeof(value));
      CFRelease(value);
      check(status, "Private registration setter");
    }
    stage = "parameter contract";
    contract = readPlist(contractPath);
    if (CFGetTypeID(contract) != CFArrayGetTypeID())
      throw std::runtime_error("Expected contract array");
    CFArrayRef list = static_cast<CFArrayRef>(contract);
    UInt32 count = 0;
    Boolean writable = false;
    check(AudioUnitGetPropertyInfo(unit.value, kAudioUnitProperty_ParameterList,
                                   kAudioUnitScope_Global, 0, &count,
                                   &writable),
          "Parameter list info");
    if (count != 522 * sizeof(UInt32) || CFArrayGetCount(list) != 522)
      throw std::runtime_error("Expected 522 parameters");
    std::vector<UInt32> ids(count / 4);
    check(AudioUnitGetProperty(unit.value, kAudioUnitProperty_ParameterList,
                               kAudioUnitScope_Global, 0, ids.data(), &count),
          "Parameter IDs");
    for (std::size_t i = 0; i < ids.size(); ++i) {
      auto expected =
          static_cast<CFDictionaryRef>(CFArrayGetValueAtIndex(list, i));
      if (ids[i] != UInt32(number(expected, CFSTR("id"))))
        throw std::runtime_error("Parameter ID differs from original");
      AudioUnitParameterInfo info{};
      UInt32 size = sizeof(info);
      check(AudioUnitGetProperty(unit.value, kAudioUnitProperty_ParameterInfo,
                                 kAudioUnitScope_Global, ids[i], &info, &size),
            "Parameter metadata");
      std::string name =
          info.cfNameString ? text(info.cfNameString) : std::string(info.name);
      std::string expectedName = text(static_cast<CFStringRef>(
          CFDictionaryGetValue(expected, CFSTR("name"))));
      bool equal =
          name == expectedName &&
          info.unit == UInt32(number(expected, CFSTR("unit"))) &&
          info.minValue == float(number(expected, CFSTR("minimum"))) &&
          info.maxValue == float(number(expected, CFSTR("maximum"))) &&
          info.defaultValue == float(number(expected, CFSTR("default")));
      if ((info.flags & kAudioUnitParameterFlag_CFNameRelease) &&
          info.cfNameString)
        CFRelease(info.cfNameString);
      if (!equal)
        throw std::runtime_error("Parameter metadata differs for ID " +
                                 std::to_string(ids[i]));
      AudioUnitParameterValue v = 0;
      check(AudioUnitGetParameter(unit.value, ids[i], kAudioUnitScope_Global, 0,
                                  &v),
            "Get parameter");
      if (!std::isfinite(v))
        throw std::runtime_error("Non-finite parameter");
      check(AudioUnitSetParameter(unit.value, ids[i], kAudioUnitScope_Global, 0,
                                  v, 0),
            "Set parameter");
    }
    passed.push_back(
        "522 parameter IDs, names, units, ranges and defaults match original");
    stage = "restore provided old AU state";
    state = readPlist(statePath);
    restore(unit.value, state);
    CFPropertyListRef saved = save(unit.value);
    restore(unit.value, saved);
    CFPropertyListRef again = save(unit.value);
    bool same = CFEqual(bank(saved), bank(again));
    CFRelease(saved);
    CFRelease(again);
    if (!same)
      throw std::runtime_error("AU bank serialization changes on round trip");
    passed.push_back(
        "old vstdata restores and serialized AU state round-trips in memory");
    stage = "initialize final render";
    configure(unit.value, channels);
    check(AudioUnitInitialize(unit.value), "Initialize render");
    restore(unit.value, state);
    std::vector<std::vector<float>> audio(channels, std::vector<float>(frames)),
        buffers(channels, std::vector<float>(512));
    std::vector<std::uint8_t> storage(sizeof(AudioBufferList) +
                                      (channels - 1) * sizeof(AudioBuffer));
    auto *abl = reinterpret_cast<AudioBufferList *>(storage.data());
    abl->mNumberBuffers = channels;
    peaks.assign(channels, 0);
    rms.assign(channels, 0);
    check(MusicDeviceMIDIEvent(unit.value, 0x90, 60, 100, 0), "Note on");
    const auto renderStart = std::chrono::steady_clock::now();
    stage = "AU audio render";
    for (UInt32 at = 0; at < frames; at += 512) {
      UInt32 n = std::min(UInt32(512), frames - at);
      if (at <= 88200 && 88200 < at + n)
        check(MusicDeviceMIDIEvent(unit.value, 0x80, 60, 0, 88200 - at),
              "Note off");
      for (UInt32 c = 0; c < channels; ++c) {
        abl->mBuffers[c] = {1, n * 4, buffers[c].data()};
      }
      AudioTimeStamp timestamp{};
      timestamp.mSampleTime = at;
      timestamp.mFlags = kAudioTimeStampSampleTimeValid;
      AudioUnitRenderActionFlags flags = 0;
      const auto callStart = std::chrono::steady_clock::now();
      check(AudioUnitRender(unit.value, &flags, &timestamp, 0, n, abl),
            "Render");
      maximumRenderCallSeconds =
          std::max(maximumRenderCallSeconds,
                   std::chrono::duration<double>(
                       std::chrono::steady_clock::now() - callStart)
                       .count());
      for (UInt32 c = 0; c < channels; ++c)
        for (UInt32 i = 0; i < n; ++i) {
          double v = buffers[c][i];
          if (!std::isfinite(v))
            throw std::runtime_error("Non-finite audio");
          peaks[c] = std::max(peaks[c], std::fabs(v));
          rms[c] += v * v;
          audio[c][at + i] = float(v);
        }
      rendered += n;
    }
    renderSeconds = std::chrono::duration<double>(
                        std::chrono::steady_clock::now() - renderStart)
                        .count();
    for (double &v : rms)
      v = std::sqrt(v / frames);
    audible = std::any_of(peaks.begin(), peaks.end(),
                          [](double v) { return v > 1e-5; });
    wave(prefix.string() + ".wav", audio, frames);
    if (!audible)
      throw std::runtime_error(
          "Rendered output stays below -100 dBFS; check local registration");
    passed.push_back(
        "3 seconds of finite audible audio through AudioUnitRender");
    engineDiagnostics = diagnostic(unit.value, 0x53704469);
    stage = "reset after render";
    check(AudioUnitReset(unit.value, kAudioUnitScope_Global, 0), "Reset");
    check(AudioUnitUninitialize(unit.value), "Uninitialize after render");
    // Exercise lifecycle changes on the same instance after the audio
    // comparison.
    for (UInt32 c : {UInt32(2), UInt32(6), channels}) {
      stage = "stream format and reinitialization";
      configure(unit.value, c);
      check(AudioUnitInitialize(unit.value), "Initialize");
      check(AudioUnitUninitialize(unit.value), "Uninitialize");
    }
    passed.push_back(
        "initialize, uninitialize and change between 2 and 6 channels");
    stage = "completed";
  } catch (const std::exception &e) {
    error = e.what();
  }
  if (unit.value) {
    engineError = diagnostic(unit.value, 0x53704572);
    if (engineDiagnostics.empty())
      engineDiagnostics = diagnostic(unit.value, 0x53704469);
  }
  std::ostringstream report;
  report << std::setprecision(17)
         << "{\"scope\":\"uninstalled candidate AU factory; not auval or DAW "
            "project recall\",\"stage\":"
         << quote(stage)
         << ",\"error\":" << (error.empty() ? "null" : quote(error))
         << ",\"engine_error\":" << quote(engineError)
         << ",\"engine_diagnostics_json\":" << quote(engineDiagnostics)
         << ",\"private_registration_input\":"
         << (privateInput ? "true" : "false") << ",\"channels\":" << channels
         << ",\"render_frames\":" << rendered
         << ",\"signal_above_minus_100_dbfs\":" << (audible ? "true" : "false")
         << ",\"render_wall_seconds\":" << renderSeconds
         << ",\"maximum_render_call_seconds\":" << maximumRenderCallSeconds
         << ",\"checks_passed\":[";
  for (std::size_t i = 0; i < passed.size(); ++i) {
    if (i)
      report << ',';
    report << quote(passed[i]);
  }
  report << "],\"peak_per_channel\":[";
  for (std::size_t i = 0; i < peaks.size(); ++i) {
    if (i)
      report << ',';
    report << peaks[i];
  }
  report << "],\"rms_per_channel\":[";
  for (std::size_t i = 0; i < rms.size(); ++i) {
    if (i)
      report << ',';
    report << rms[i];
  }
  report << "]}\n";
  std::cout << report.str();
  if (!prefix.empty()) {
    std::ofstream out(prefix.string() + ".json");
    out << report.str();
  }
  if (state)
    CFRelease(state);
  if (contract)
    CFRelease(contract);
  // The instance must be disposed before its factory's CFBundle can be
  // unloaded.
  if (unit.value) {
    AudioUnitUninitialize(unit.value);
    AudioComponentInstanceDispose(unit.value);
    unit.value = nullptr;
  }
  if (bundle)
    CFRelease(bundle);
  return error.empty() ? 0 : 1;
}
