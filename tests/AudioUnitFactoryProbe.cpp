// Exercise the compiled AU factory in this process, without system
// installation.
#include "../src/au/SophistryProperties.h"
#include "../src/au/OutputGain.h"
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
#include <thread>
#include <time.h>
#include <vector>

namespace {
constexpr UInt32 registrationProperty = 0x53705267;
double threadCpuSeconds() {
  timespec value{};
  if (clock_gettime(CLOCK_THREAD_CPUTIME_ID, &value))
    throw std::runtime_error("Cannot read render-thread CPU clock");
  return double(value.tv_sec) + double(value.tv_nsec) * 1e-9;
}
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
void configure(AudioUnit unit, UInt32 channels, Float64 rate = 44100,
               UInt32 maximum = 512) {
  AudioStreamBasicDescription format{rate,
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
  bool privateInput = false, registered = false, discoverOnly = false;
  UInt32 channels = 2;
  UInt32 renderBlock = 512, renderCalls = 0;
  UInt32 profileNotes = 0;
  std::filesystem::path profileReady, profileGo;
  std::string profileWarmDiagnostics;
  std::string expectedWrapperVersion = sophistry::wrapperVersion;
  std::string stage = "arguments", error;
  std::vector<std::string> passed;
  std::vector<double> peaks, rms;
  UInt32 frames = 132300, rendered = 0;
  bool audible = false;
  float initialMasterDb = 0;
  double renderSeconds = 0, maximumRenderCallSeconds = 0;
  double renderCallSeconds = 0, renderThreadCpuSeconds = 0;
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
      else if (a == "--registered")
        registered = true;
      else if (a == "--discover-only")
        discoverOnly = true;
      else if (a == "--state")
        statePath = next();
      else if (a == "--contract")
        contractPath = next();
      else if (a == "--output-prefix")
        prefix = next();
      else if (a == "--channels")
        channels = UInt32(std::stoul(next()));
      else if (a == "--render-block-size")
        renderBlock = UInt32(std::stoul(next()));
      else if (a == "--profile-notes")
        profileNotes = UInt32(std::stoul(next()));
      else if (a == "--profile-ready-file")
        profileReady = next();
      else if (a == "--profile-go-file")
        profileGo = next();
      else if (a == "--expected-version") {
        expectedWrapperVersion = next();
        if (expectedWrapperVersion != sophistry::wrapperVersion &&
            expectedWrapperVersion != "SophistryARM CP-037" &&
            expectedWrapperVersion != "SophistryARM CP-032")
          throw std::runtime_error("Unsupported comparison checkpoint");
      }
      else if (a == "--registration-from-stdin")
        privateInput = true;
      else
        throw std::runtime_error("Unknown argument");
    }
    if ((!registered && bundlePath.empty()) ||
        (registered && !bundlePath.empty()) || (registered && privateInput) ||
        (discoverOnly && !registered) || statePath.empty() ||
        contractPath.empty() || prefix.empty() ||
        (channels != 2 && channels != 6) || renderBlock < 64 || renderBlock > 512)
      throw std::runtime_error(
          "Required: --bundle --state --contract --output-prefix [--channels "
          "2|6] [--registration-from-stdin]");
    if ((profileNotes != 0 && profileNotes != 1 && profileNotes != 4) ||
        (profileNotes && (profileReady.empty() || profileGo.empty() ||
                          discoverOnly || privateInput || channels != 2)) ||
        (!profileNotes && (!profileReady.empty() || !profileGo.empty())))
      throw std::runtime_error("Profiling requires 1 or 4 notes and ready/go files");
    if (profileNotes) {
      if (std::filesystem::exists(profileReady) || std::filesystem::exists(profileGo))
        throw std::runtime_error("Profiling control files must be fresh");
      frames = 20 * 44100;
    }
    if (prefix.has_parent_path())
      std::filesystem::create_directories(prefix.parent_path());
    AudioComponentDescription desc{0x61756d75, 0x536f7033, 0x4c696e50, 0, 0};
    AudioComponent component = nullptr;
    if (registered) {
      stage = "find system-registered candidate";
      component = AudioComponentFindNext(nullptr, &desc);
      if (!component)
        throw std::runtime_error("No registered Sophistry AU found");
      if (AudioComponentFindNext(component, &desc))
        throw std::runtime_error(
            "Multiple Sophistry AUs match the original identity");
    } else {
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
          CFBundleGetFunctionPointerForName(bundle,
                                            CFSTR("SophistryAUFactory")));
      if (!factory)
        throw std::runtime_error("Missing SophistryAUFactory");
      component = AudioComponentRegister(
          &desc, CFSTR("LinPlug: Sophistry native candidate"), 0x00030008,
          factory);
      if (!component)
        throw std::runtime_error("Process-local component registration failed");
    }
    stage = "create instance";
    check(AudioComponentInstanceNew(component, &unit.value),
          "Create AU instance");
    if (diagnostic(unit.value, 0x53705672) != expectedWrapperVersion)
      throw std::runtime_error(
          "Loaded component is not the expected checkpoint");
    if (discoverOnly) {
      const std::string result = "{\"system_registry_used\":true,\"expected_"
                                 "native_candidate_loaded\":true}\n";
      std::cout << result;
      std::ofstream(prefix.string() + ".json") << result;
      return 0;
    }
    passed.push_back(registered
                         ? "expected candidate loads through system AU registry"
                         : "candidate factory loads without installation");
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
    check(AudioUnitGetParameter(unit.value, 134, kAudioUnitScope_Global, 0,
                               &initialMasterDb), "Initial Master volume");
    passed.push_back("522 parameter IDs, names, units, ranges and defaults match original");
    stage = "parameter value to string property";
    UInt32 textSize = 0;
    Boolean textWritable = true;
    check(AudioUnitGetPropertyInfo(
              unit.value, kAudioUnitProperty_ParameterStringFromValue,
              kAudioUnitScope_Global, 0, &textSize, &textWritable),
          "Parameter string property info");
    if (textSize != sizeof(AudioUnitParameterStringFromValue) || textWritable)
      throw std::runtime_error("Incorrect native parameter string ABI");
    CFPropertyListRef textFixture = readPlist(
        contractPath.parent_path() / "original-au-parameter-text.plist");
    if (CFGetTypeID(textFixture) != CFArrayGetTypeID()) {
      CFRelease(textFixture);
      throw std::runtime_error("Invalid original parameter text fixture");
    }
    auto textCases = static_cast<CFArrayRef>(textFixture);
    for (CFIndex i = 0; i < CFArrayGetCount(textCases); ++i) {
      auto test =
          static_cast<CFDictionaryRef>(CFArrayGetValueAtIndex(textCases, i));
      UInt32 id = UInt32(number(test, CFSTR("id")));
      stage = "parameter text ID " + std::to_string(id) + " case " +
              text(static_cast<CFStringRef>(
                  CFDictionaryGetValue(test, CFSTR("case"))));
      AudioUnitParameterValue value = float(number(test, CFSTR("value")));
      bool current =
          CFDictionaryGetValue(test, CFSTR("current")) == kCFBooleanTrue;
      AudioUnitParameterStringFromValue request{id, current ? nullptr : &value,
                                                nullptr};
      UInt32 bytes = sizeof(request);
      OSStatus status = AudioUnitGetProperty(
          unit.value, kAudioUnitProperty_ParameterStringFromValue,
          kAudioUnitScope_Global, 0, &request, &bytes);
      bool expectedText =
          CFDictionaryGetValue(test, CFSTR("has_text")) == kCFBooleanTrue;
      bool equal = status == OSStatus(number(test, CFSTR("status"))) &&
                   bool(request.outString) == expectedText &&
                   text(request.outString) ==
                       text(static_cast<CFStringRef>(
                           CFDictionaryGetValue(test, CFSTR("text"))));
      if (request.outString)
        CFRelease(request.outString);
      if (!equal) {
        CFRelease(textFixture);
        throw std::runtime_error("Parameter text differs from original");
      }
    }
    CFRelease(textFixture);
    passed.push_back("596 original property-33 cases match, including "
                     "clamping, current values and null strings");
    stage = "restore provided old AU state";
    state = readPlist(statePath);
    restore(unit.value, state);
    CFPropertyListRef saved = save(unit.value);
    auto savedDictionary = static_cast<CFDictionaryRef>(saved);
    CFTypeRef build =
        CFDictionaryGetValue(savedDictionary, CFSTR("SophistryARMVersion"));
    if (!build || CFGetTypeID(build) != CFStringGetTypeID() ||
        text(static_cast<CFStringRef>(build)) != expectedWrapperVersion) {
      CFRelease(saved);
      throw std::runtime_error(
          "Standard AU state checkpoint marker is missing");
    }
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
    std::vector<std::vector<float>> audio(channels, std::vector<float>(profileNotes ? 0 : frames)),
        buffers(channels, std::vector<float>(512));
    std::vector<std::uint8_t> storage(sizeof(AudioBufferList) +
                                      (channels - 1) * sizeof(AudioBuffer));
    auto *abl = reinterpret_cast<AudioBufferList *>(storage.data());
    abl->mNumberBuffers = channels;
    peaks.assign(channels, 0);
    rms.assign(channels, 0);
    const std::array<UInt32, 4> notes{60, 64, 67, 72};
    for (UInt32 i = 0; i < (profileNotes ? profileNotes : 1); ++i)
      check(MusicDeviceMIDIEvent(unit.value, 0x90, notes[i], 100, 0), "Note on");
    const auto renderStart = std::chrono::steady_clock::now();
    stage = "AU audio render";
    for (UInt32 at = 0; at < frames; at += renderBlock) {
      UInt32 n = std::min(renderBlock, frames - at);
      if (!profileNotes && at <= 88200 && 88200 < at + n)
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
      const double cpuStart = threadCpuSeconds();
      check(AudioUnitRender(unit.value, &flags, &timestamp, 0, n, abl),
            "Render");
      renderThreadCpuSeconds += threadCpuSeconds() - cpuStart;
      const double callSeconds = std::chrono::duration<double>(
          std::chrono::steady_clock::now() - callStart).count();
      renderCallSeconds += callSeconds;
      ++renderCalls;
      maximumRenderCallSeconds =
          std::max(maximumRenderCallSeconds, callSeconds);
      if (abl->mNumberBuffers != channels)
        throw std::runtime_error("Changed output buffer count");
      for (UInt32 c = 0; c < channels; ++c) {
        if (!abl->mBuffers[c].mData || abl->mBuffers[c].mDataByteSize < n * 4)
          throw std::runtime_error("Invalid returned audio buffer");
        const auto *returned =
            static_cast<const float *>(abl->mBuffers[c].mData);
        for (UInt32 i = 0; i < n; ++i) {
          double v = returned[i];
          if (!std::isfinite(v))
            throw std::runtime_error("Non-finite audio");
          peaks[c] = std::max(peaks[c], std::fabs(v));
          rms[c] += v * v;
          if (!profileNotes)
            audio[c][at + i] = float(v);
        }
      }
      rendered += n;
      if (profileNotes && at == 0) {
        // Warm the actual render path before the external sampler attaches.
        // Control/diagnostic work happens outside the measured AU calls.
        profileWarmDiagnostics = diagnostic(unit.value, 0x53704469);
        {
          std::ofstream ready(profileReady);
          ready << "First audio buffer rendered\n";
          if (!ready)
            throw std::runtime_error("Cannot signal profiling readiness");
        }
        const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(30);
        while (!std::filesystem::exists(profileGo)) {
          if (std::chrono::steady_clock::now() >= deadline)
            throw std::runtime_error("External profiling controller did not start");
          std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
      }
    }
    renderSeconds = std::chrono::duration<double>(
                        std::chrono::steady_clock::now() - renderStart)
                        .count();
    for (double &v : rms)
      v = std::sqrt(v / frames);
    audible = std::any_of(peaks.begin(), peaks.end(),
                          [](double v) { return v > 1e-5; });
    if (!profileNotes)
      wave(prefix.string() + ".wav", audio, frames);
    if (!audible)
      throw std::runtime_error(
          "Rendered output stays below -100 dBFS; check local registration");
    passed.push_back(profileNotes ? "20 seconds of finite audible held-note audio for CPU sampling"
                                 : "3 seconds of finite audible audio through AudioUnitRender");
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
    for (auto spec : std::array<std::array<UInt32, 2>, 4>{
             {{22050, 64}, {96000, 137}, {48000, 4096}, {192000, 4096}}}) {
      stage = "rate/block validation rate=" + std::to_string(spec[0]) +
              " frames=" + std::to_string(spec[1]);
      configure(unit.value, channels, spec[0], spec[1]);
      check(AudioUnitInitialize(unit.value), "Initialize rate/block test");
      std::vector<std::vector<float>> trial(channels,
                                            std::vector<float>(spec[1]));
      for (UInt32 c = 0; c < channels; ++c)
        abl->mBuffers[c] = {1, spec[1] * 4, trial[c].data()};
      AudioTimeStamp timestamp{};
      timestamp.mFlags = kAudioTimeStampSampleTimeValid;
      AudioUnitRenderActionFlags flags = 0;
      check(AudioUnitRender(unit.value, &flags, &timestamp, 0, spec[1], abl),
            "Render rate/block test");
      for (UInt32 c = 0; c < channels; ++c) {
        auto *returned = static_cast<const float *>(abl->mBuffers[c].mData);
        if (!returned || abl->mBuffers[c].mDataByteSize < spec[1] * 4)
          throw std::runtime_error("Invalid rate/block output buffer");
        for (UInt32 i = 0; i < spec[1]; ++i)
          if (!std::isfinite(returned[i]))
            throw std::runtime_error("Non-finite rate/block output");
      }
      check(AudioUnitUninitialize(unit.value), "Uninitialize rate/block test");
    }
    passed.push_back(
        "initialize/render at 22050/64, 96000/137, 48000/4096, 192000/4096");
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
         << "{\"scope\":\"candidate AU instance tests; not auval or DAW "
            "project recall\",\"system_registry_used\":"
         << (registered ? "true" : "false") << ",\"stage\":" << quote(stage)
         << ",\"error\":" << (error.empty() ? "null" : quote(error))
         << ",\"engine_error\":" << quote(engineError)
         << ",\"engine_diagnostics_json\":" << quote(engineDiagnostics)
         << ",\"private_registration_input\":"
         << (privateInput ? "true" : "false") << ",\"channels\":" << channels
         << ",\"render_frames\":" << rendered
         << ",\"initial_master_db\":" << initialMasterDb
         << ",\"output_compensation_db\":"
         << (expectedWrapperVersion == sophistry::wrapperVersion ? sophistry::outputGainDb : 0.0f)
         << ",\"profile_note_count\":" << profileNotes
         << ",\"profile_warm_engine_diagnostics_json\":" << quote(profileWarmDiagnostics)
         << ",\"signal_above_minus_100_dbfs\":" << (audible ? "true" : "false")
         << ",\"render_wall_seconds\":" << renderSeconds
         << ",\"render_call_wall_seconds\":" << renderCallSeconds
         << ",\"render_thread_cpu_seconds\":" << renderThreadCpuSeconds
         << ",\"render_block_size\":" << renderBlock
         << ",\"render_calls\":" << renderCalls
         << ",\"expected_checkpoint\":" << quote(expectedWrapperVersion)
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
