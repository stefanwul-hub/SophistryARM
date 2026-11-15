// Known IEEE answers on all platforms; independent Core Audio oracle on Mac.
#include "../src/engine/PcmConversion.h"
#include <algorithm>
#include <iostream>
#include <string>
#ifdef __APPLE__
#include <AudioToolbox/AudioToolbox.h>
#endif
using namespace sophistry;
using Bytes = std::vector<std::uint8_t>;
struct Value {
  std::uint64_t raw;
  std::uint32_t expected;
};
static void store(std::uint8_t *p, std::uint64_t value, unsigned n, bool big) {
  for (unsigned i = 0; i < n; ++i)
    p[big ? n - 1 - i : i] = std::uint8_t(value >> (i * 8));
}
static PcmFormat format(unsigned bits, unsigned channels, unsigned flags) {
  const auto stride = (bits / 8) * ((flags & 32) ? 1 : channels);
  return {0, 0x6c70636d, flags, stride, 1, stride, channels, bits, 0};
}
static std::vector<Value> values(unsigned bits, unsigned flags) {
  const int integers[] = {-128, -96, -64, -1, 0, 1, 16, 32, 64, 96, 127};
  const std::uint32_t expected[] = {
      0xbf800000, 0xbf400000, 0xbf000000, 0xbc000000, 0,         0x3c000000,
      0x3e000000, 0x3e800000, 0x3f000000, 0x3f400000, 0x3f7e0000};
  std::vector<Value> result;
  for (unsigned i = 0; i < 11; ++i) {
    std::uint64_t raw;
    if (flags & 1) {
      if (bits == 32)
        raw = expected[i];
      else {
        float f;
        std::memcpy(&f, &expected[i], 4);
        double d = f;
        std::memcpy(&raw, &d, 8);
      }
    } else {
      std::int64_t n =
          std::int64_t(integers[i]) * (std::int64_t(1) << (bits - 8));
      if (!(flags & 4))
        n += std::int64_t(1) << (bits - 1);
      raw = std::uint64_t(n) & ((std::uint64_t(1) << bits) - 1);
    }
    result.push_back({raw, expected[i]});
  }
  if (!(flags & 1) && bits == 32) {
    result.push_back({0x01000001, 0x3c000000}); // halfway, ties to even
    result.push_back({0x01000003, 0x3c000002});
    result.push_back({0x7fffffff, 0x3f800000});
    result.push_back({0xfeffffff, 0xbc000000});
  }
  if (!(flags & 1) && bits == 24)
    result.push_back({0x7fffff, 0x3f7ffffe});
  if (flags & 1) {
    result.push_back(
        {bits == 32 ? 0x80000000ull : 0x8000000000000000ull, 0x80000000});
    if (bits == 64) {
      result.push_back({0x3fe0000010000000, 0x3f000000});
      result.push_back({0x3fe0000030000000, 0x3f000002});
    }
  }
  return result;
}
#ifdef __APPLE__
struct NativeInput {
  PcmFormat format;
  const std::vector<Bytes> *data;
  UInt32 position = 0, frames = 0;
};
static OSStatus nativeInput(AudioConverterRef, UInt32 *packets,
                            AudioBufferList *out,
                            AudioStreamPacketDescription **description,
                            void *user) {
  auto &s = *static_cast<NativeInput *>(user);
  const auto n = std::min(*packets, s.frames - s.position);
  *packets = n;
  out->mNumberBuffers = UInt32(s.format.buffers());
  for (unsigned i = 0; i < out->mNumberBuffers; ++i)
    out->mBuffers[i] = {
        s.format.bufferChannels(), n * s.format.bytesPerFrame,
        const_cast<std::uint8_t *>((*s.data)[i].data() +
                                   s.position * s.format.bytesPerFrame)};
  s.position += n;
  if (description)
    *description = nullptr;
  return noErr;
}
static AudioStreamBasicDescription asbd(PcmFormat f) {
  // The original loaders pass equal zero rates. Give the modern oracle an
  // equal positive rate; these tests never perform sample-rate conversion.
  return {44100,
          f.format,
          f.flags,
          f.bytesPerPacket,
          f.framesPerPacket,
          f.bytesPerFrame,
          f.channels,
          f.bits,
          0};
}
static bool nativeCheck(const PcmFormat &source, const PcmFormat &target,
                        const std::vector<Bytes> &input,
                        const std::vector<Bytes> &expected, UInt32 frames) {
  auto a = asbd(source), b = asbd(target);
  AudioConverterRef converter = nullptr;
  OSStatus status = AudioConverterNew(&a, &b, &converter);
  bool normalized = false;
  if (status && source.floating() && (a.mFormatFlags & 4)) {
    a.mFormatFlags &= ~UInt32(4);
    normalized = true;
    status = AudioConverterNew(&a, &b, &converter);
  }
  if (status)
    throw std::runtime_error("Native AudioConverterNew status " +
                             std::to_string(status));
  std::vector<Bytes> result(target.buffers(),
                            Bytes(frames * target.bytesPerFrame));
  struct {
    UInt32 count;
    AudioBuffer buffers[2];
  } storage{};
  auto *out = reinterpret_cast<AudioBufferList *>(&storage);
  out->mNumberBuffers = UInt32(result.size());
  for (unsigned i = 0; i < result.size(); ++i)
    out->mBuffers[i] = {target.bufferChannels(), UInt32(result[i].size()),
                        result[i].data()};
  NativeInput inputState{source, &input, 0, frames};
  UInt32 count = frames;
  status = AudioConverterFillComplexBuffer(converter, nativeInput, &inputState,
                                           &count, out, nullptr);
  AudioConverterDispose(converter);
  if (status || count != frames || result != expected)
    throw std::runtime_error("Native PCM differs: status " +
                             std::to_string(status) + " " +
                             describePcm(source));
  return normalized;
}
#endif
int main() {
  unsigned passed = 0, oracle = 0, normalized = 0, rejected = 0;
  std::string error;
  try {
    const struct {
      unsigned bits, flags;
    } types[] = {{8, 12},  {8, 8},  {16, 12}, {24, 12},
                 {32, 12}, {32, 9}, {32, 13}, {64, 13}};
    for (auto type : types)
      for (unsigned channels : {1u, 2u})
        for (unsigned endian : {0u, 2u})
          for (unsigned planar : {0u, 32u})
            for (unsigned outputPlanar : {0u, 32u})
              for (unsigned outputEndian : {0u, 2u}) {
                const auto a =
                    format(type.bits, channels, type.flags | endian | planar);
                const auto b =
                    format(32, channels, 9 | outputPlanar | outputEndian);
                PcmConversion converter(a, b);
                const auto samples = values(type.bits, type.flags);
                constexpr unsigned frames = 77;
                std::vector<Bytes> input(a.buffers(),
                                         Bytes(frames * a.bytesPerFrame));
                std::vector<Bytes> expected(b.buffers(),
                                            Bytes(frames * b.bytesPerFrame));
                for (unsigned f = 0; f < frames; ++f)
                  for (unsigned c = 0; c < channels; ++c) {
                    const auto &v = samples[(f * 3 + c * 5) % samples.size()];
                    store(input[a.planar() ? c : 0].data() +
                              f * a.bytesPerFrame +
                              (a.planar() ? 0 : c * (a.bits / 8)),
                          v.raw, a.bits / 8, a.bigEndian());
                    store(expected[b.planar() ? c : 0].data() +
                              f * b.bytesPerFrame + (b.planar() ? 0 : c * 4),
                          v.expected, 4, b.bigEndian());
                  }
                std::vector<Bytes> storage(
                    b.buffers(), Bytes(frames * b.bytesPerFrame + 32, 0xa5));
                std::vector<PcmReadBuffer> reads;
                std::vector<PcmWriteBuffer> writes;
                for (auto &v : input)
                  reads.push_back({v.data(), v.size()});
                for (auto &v : storage)
                  writes.push_back({v.data() + 16, v.size() - 32});
                converter.convert(reads, writes, frames);
                for (unsigned c = 0; c < storage.size(); ++c) {
                  if (!std::equal(expected[c].begin(), expected[c].end(),
                                  storage[c].begin() + 16) ||
                      !std::all_of(storage[c].begin(), storage[c].begin() + 16,
                                   [](auto n) { return n == 0xa5; }) ||
                      !std::all_of(storage[c].end() - 16, storage[c].end(),
                                   [](auto n) { return n == 0xa5; }))
                    throw std::runtime_error("PCM output or guard differs: " +
                                             describePcm(a));
                }
#ifdef __APPLE__
                // These are the layouts actually requested by the original
                // loaders.
                if (!planar && !outputEndian &&
                    outputPlanar == (channels == 2 ? 32u : 0u)) {
                  normalized += nativeCheck(a, b, input, expected, frames);
                  ++oracle;
                }
#endif
                ++passed;
                writes[0].bytes -= 1;
                try {
                  converter.convert(reads, writes, frames);
                  throw 1;
                } catch (const std::runtime_error &) {
                  ++rejected;
                }
                reads[0].bytes -= 1;
                writes[0].bytes += 1;
                try {
                  converter.convert(reads, writes, frames);
                  throw 1;
                } catch (const std::runtime_error &) {
                  ++rejected;
                }
              }
    auto a = format(16, 2, 12), b = format(32, 2, 41);
    for (unsigned bad = 0; bad < 4; ++bad) {
      auto source = a;
      if (bad == 0)
        source.sampleRate = 48000;
      if (bad == 1)
        source.bytesPerFrame = 3;
      if (bad == 2)
        source.format = 0;
      if (bad == 3)
        source.flags |= 256;
      try {
        PcmConversion invalid(source, b);
        throw 1;
      } catch (const std::runtime_error &) {
        ++rejected;
      }
    }
  } catch (const std::exception &e) {
    error = e.what();
  } catch (...) {
    error = "An invalid PCM conversion was unexpectedly accepted";
  }
  // Error text here contains no paths or private data.
  std::cout << "{\"passed\":" << (error.empty() ? "true" : "false")
            << ",\"known_ieee_cases\":" << passed
            << ",\"rejected_invalid_buffers_or_formats\":" << rejected
            << ",\"native_core_audio_cases\":" << oracle
            << ",\"native_float_signed_flags_normalized\":" << normalized
            << ",\"error\":\"" << error << "\"}\n";
  return error.empty() ? 0 : 1;
}
