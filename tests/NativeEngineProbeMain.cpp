#include "../src/engine/LegacyEngine.h"
#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#ifdef __APPLE__
#include <CoreFoundation/CoreFoundation.h>
#endif

namespace {
using Bytes = std::vector<std::uint8_t>;
Bytes readFile(const std::filesystem::path &path) {
  std::ifstream f(path, std::ios::binary | std::ios::ate);
  if (!f)
    throw std::runtime_error("Cannot open state");
  auto n = f.tellg();
  if (n < 0 || n > 32 * 1024 * 1024)
    throw std::runtime_error("Invalid state size");
  Bytes bytes(static_cast<std::size_t>(n));
  f.seekg(0);
  if (n && !f.read(reinterpret_cast<char *>(bytes.data()), n))
    throw std::runtime_error("Cannot read state");
  return bytes;
}
void writeFile(const std::filesystem::path &path, const Bytes &data) {
  std::ofstream f(path, std::ios::binary);
  if (!f || !f.write(reinterpret_cast<const char *>(data.data()),
                     std::streamsize(data.size())))
    throw std::runtime_error("Cannot save probe result");
}
std::uint32_t big32(const Bytes &b, std::size_t at) {
  if (b.size() < at + 4)
    throw std::runtime_error("Truncated state");
  std::uint32_t n = 0;
  for (unsigned i = 0; i < 4; ++i)
    n = n * 256 + b[at + i];
  return n;
}
Bytes readChunk(const std::filesystem::path &path, bool &program) {
  auto b = readFile(path);
  if (b.size() < 12)
    throw std::runtime_error("Truncated state");
  if (std::string(b.begin(), b.begin() + 4) == "CcnK") {
    if (b.size() < 60 || std::string(b.begin() + 8, b.begin() + 12) != "FPCh" ||
        big32(b, 56) != b.size() - 60)
      throw std::runtime_error("Invalid FXP program chunk");
    program = true;
    return {b.begin() + 60, b.end()};
  }
  if (path.extension() == ".aupreset") {
    program = false;
#ifdef __APPLE__
    CFDataRef data = CFDataCreate(nullptr, b.data(), CFIndex(b.size()));
    CFPropertyListRef plist =
        data ? CFPropertyListCreateWithData(
                   nullptr, data, kCFPropertyListImmutable, nullptr, nullptr)
             : nullptr;
    if (data)
      CFRelease(data);
    if (!plist || CFGetTypeID(plist) != CFDictionaryGetTypeID()) {
      if (plist)
        CFRelease(plist);
      throw std::runtime_error("Invalid AU property list");
    }
    CFTypeRef value = CFDictionaryGetValue(static_cast<CFDictionaryRef>(plist),
                                           CFSTR("vstdata"));
    if (!value || CFGetTypeID(value) != CFDataGetTypeID()) {
      CFRelease(plist);
      throw std::runtime_error("AU state lacks vstdata");
    }
    CFDataRef chunk = static_cast<CFDataRef>(value);
    Bytes result(CFDataGetBytePtr(chunk),
                 CFDataGetBytePtr(chunk) + CFDataGetLength(chunk));
    CFRelease(plist);
    return result;
#else
    // Test-file reader for the supplied XML plist. Binary plists use native
    // CoreFoundation on macOS; no XML entities or external files are read.
    const std::string xml(b.begin(), b.end());
    auto at = xml.find("<key>vstdata</key>");
    if (at == std::string::npos)
      throw std::runtime_error("Expected XML plist vstdata");
    at = xml.find("<data>", at);
    auto end = xml.find("</data>", at);
    if (at == std::string::npos || end == std::string::npos)
      throw std::runtime_error("Invalid XML CFData");
    const std::string alphabet =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    Bytes result;
    unsigned bits = 0, value = 0;
    bool padding = false;
    for (std::size_t i = at + 6; i < end; ++i) {
      unsigned char c = xml[i];
      if (c == ' ' || c == '\t' || c == '\r' || c == '\n')
        continue;
      if (c == '=') {
        padding = true;
        continue;
      }
      auto digit = alphabet.find(char(c));
      if (padding || digit == std::string::npos)
        throw std::runtime_error("Invalid plist base64");
      value = (value << 6) | unsigned(digit);
      bits += 6;
      if (bits >= 8) {
        bits -= 8;
        result.push_back(std::uint8_t(value >> bits));
      }
    }
    return result;
#endif
  }
  throw std::runtime_error("Expected FXP or aupreset");
}
template <class T> void little(Bytes &b, T v) {
  for (unsigned i = 0; i < sizeof(T); ++i)
    b.push_back(std::uint8_t(v >> (8 * i)));
}
Bytes wave(const std::vector<std::vector<float>> &audio, std::uint32_t frames) {
  std::uint16_t channels = std::uint16_t(audio.size());
  std::uint32_t size = frames * channels * 4;
  Bytes b;
  b.reserve(size + 44);
  for (char c : std::string("RIFF"))
    b.push_back(std::uint8_t(c));
  little(b, size + 36);
  for (char c : std::string("WAVEfmt "))
    b.push_back(std::uint8_t(c));
  little(b, std::uint32_t(16));
  little(b, std::uint16_t(3));
  little(b, channels);
  little(b, std::uint32_t(44100));
  little(b, std::uint32_t(44100 * channels * 4));
  little(b, std::uint16_t(channels * 4));
  little(b, std::uint16_t(32));
  for (char c : std::string("data"))
    b.push_back(std::uint8_t(c));
  little(b, size);
  for (std::uint32_t i = 0; i < frames; ++i)
    for (const auto &channel : audio) {
      const auto *p = reinterpret_cast<const std::uint8_t *>(&channel[i]);
      b.insert(b.end(), p, p + 4);
    }
  return b;
}
std::string quote(const std::string &s) {
  std::ostringstream out;
  out << std::quoted(s);
  return out.str();
}
} // namespace

int main(int argc, char **argv) {
  std::filesystem::path state, prefix;
  double seconds = 0;
  bool snapshots = false, preferences = false, registrationInput = false;
  sophistry::LegacyEngineConfig config;
  std::unique_ptr<sophistry::LegacyEngine> engine;
  std::string error;
  bool signal = false;
  std::vector<double> peaks, rms;
  std::uint32_t frames = 0;
  int result = 0;
  try {
    for (int i = 1; i < argc; ++i) {
      const std::string a = argv[i];
      auto argument = [&]() {
        if (++i >= argc)
          throw std::runtime_error("Missing command argument");
        return std::string(argv[i]);
      };
      if (a == "--state")
        state = argument();
      else if (a == "--output-prefix")
        prefix = argument();
      else if (a == "--asset-directory")
        config.assetDirectories.push_back(argument());
      else if (a == "--render")
        seconds = std::stod(argument());
      else if (a == "--snapshots")
        snapshots = true;
      else if (a == "--recursive-assets")
        config.recursiveAssetSearch = true;
      else if (a == "--native-clock")
        config.nativeMonotonicClock = true;
      else if (a == "--au-channels") {
        config.audioUnitMode = true;
        config.audioUnitOutputChannels = std::uint32_t(std::stoul(argument()));
      } else if (a == "--local-mac-preferences")
        preferences = true;
      else if (a == "--registration-from-stdin")
        registrationInput = true;
      else
        throw std::runtime_error("Unknown command argument");
    }
    if (state.empty() || prefix.empty())
      throw std::runtime_error(
          "Usage: NativeEngineProbe --state file --output-prefix path "
          "[--asset-directory dir] [--render seconds] [--snapshots] "
          "[--local-mac-preferences] [--native-clock]");
    if (seconds < 0 || seconds > 30 || !std::isfinite(seconds))
      throw std::runtime_error("Invalid render duration");
    if ((preferences || registrationInput) && snapshots)
      throw std::runtime_error("Private inputs disable memory snapshots");
    if (preferences && registrationInput)
      throw std::runtime_error(
          "Choose local preferences or private registration input");
    config.useLocalMacPreferences = preferences;
    if (registrationInput) {
      if (!std::getline(std::cin, config.privateRegistration) ||
          config.privateRegistration.empty())
        throw std::runtime_error("No registration input");
      if (!config.privateRegistration.empty() &&
          config.privateRegistration.back() == '\r')
        config.privateRegistration.pop_back();
      if (config.privateRegistration.size() > 319)
        throw std::runtime_error(
            "Registration input exceeds original field capacity");
    }
    if (prefix.has_parent_path())
      std::filesystem::create_directories(prefix.parent_path());
    bool program = false;
    auto chunk = readChunk(state, program);
    engine = std::make_unique<sophistry::LegacyEngine>(config);
    engine->initialize();
    engine->restoreChunk(chunk, program);
    if (seconds) {
      engine->setSampleRate(44100);
      engine->setBlockSize(512);
      engine->activate();
      engine->restoreChunk(chunk, program);
      const auto channels = engine->outputChannels();
      frames = std::uint32_t(44100 * seconds);
      const std::uint32_t off = std::min(frames, std::uint32_t(88200));
      std::vector<std::vector<float>> audio(channels,
                                            std::vector<float>(frames)),
          buffers(channels, std::vector<float>(512));
      std::vector<float *> pointers;
      for (auto &b : buffers)
        pointers.push_back(b.data());
      peaks.assign(channels, 0);
      rms.assign(channels, 0);
      engine->midi(0x90, 60, 100);
      for (std::uint32_t at = 0; at < frames; at += 512) {
        auto n = std::min(std::uint32_t(512), frames - at);
        if (at <= off && off < at + n)
          engine->midi(0x80, 60, 0, off - at);
        engine->process(pointers.data(), channels, n);
        for (std::uint32_t c = 0; c < channels; ++c)
          for (std::uint32_t i = 0; i < n; ++i) {
            double value = buffers[c][i];
            if (!std::isfinite(value))
              throw std::runtime_error("Non-finite audio output");
            peaks[c] = std::max(peaks[c], std::fabs(value));
            rms[c] += value * value;
            audio[c][at + i] = buffers[c][i];
          }
      }
      for (double &value : rms)
        value = std::sqrt(value / frames);
      signal = std::any_of(peaks.begin(), peaks.end(),
                           [](double value) { return value > 1e-5; });
      writeFile(prefix.string() + ".wav", wave(audio, frames));
      if (!signal) {
        error =
            "Rendered output stays below -100 dBFS; synthesis is not verified";
        result = 1;
      }
    } else {
      auto saved = engine->saveProgram();
      if (!preferences && !registrationInput)
        writeFile(prefix.string() + ".chunk", saved);
    }
    if (snapshots) {
      writeFile(prefix.string() + ".object", engine->objectSnapshot());
      writeFile(prefix.string() + ".heap", engine->heapSnapshot());
      writeFile(prefix.string() + ".globals", engine->globalSnapshot());
    }
  } catch (const std::exception &e) {
    error = e.what();
    result = 1;
  }
  std::ostringstream report;
  report << std::setprecision(17)
         << "{\"backend\":\"native C++ host and static translated "
            "engine\",\"error\":"
         << (error.empty() ? "null" : quote(error))
         << ",\"render_frames\":" << frames
         << ",\"signal_above_minus_100_dbfs\":" << (signal ? "true" : "false")
         << ",\"peak_per_channel\":[";
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
  report << "],\"engine\":" << (engine ? engine->diagnosticJson() : "null")
         << "}\n";
  std::cout << report.str();
  if (!prefix.empty()) {
    std::ofstream f(prefix.string() + ".json");
    if (f)
      f << report.str();
    else
      result = 1;
  }
  return result;
}
