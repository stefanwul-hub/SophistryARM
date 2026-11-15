#pragma once
// Bounded, equal-rate LPCM conversion used by the original sample loaders.
// D4U/D4T load each channel as mono float32; WAV/AIFF also use integer PCM.
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace sophistry {
struct PcmFormat {
  double sampleRate = 0;
  std::uint32_t format = 0, flags = 0, bytesPerPacket = 0, framesPerPacket = 0,
                bytesPerFrame = 0, channels = 0, bits = 0, reserved = 0;
  bool planar() const { return (flags & 32) != 0; }
  bool floating() const { return (flags & 1) != 0; }
  bool bigEndian() const { return (flags & 2) != 0; }
  std::size_t buffers() const { return planar() ? channels : 1; }
  std::uint32_t bufferChannels() const { return planar() ? 1 : channels; }
};
inline std::string describePcm(const PcmFormat &p) {
  std::ostringstream s;
  s << (p.floating() ? "float" : ((p.flags & 4) ? "signed" : "unsigned"))
    << p.bits << '/' << p.channels << "ch/" << (p.bigEndian() ? "BE" : "LE")
    << "/flags=" << p.flags;
  return s.str();
}
struct PcmReadBuffer {
  const std::uint8_t *data;
  std::size_t bytes;
};
struct PcmWriteBuffer {
  std::uint8_t *data;
  std::size_t bytes;
};
class PcmConversion {
  PcmFormat input_, output_;
  static void validate(const PcmFormat &p, bool output) {
    if (p.format != 0x6c70636d || p.channels < 1 || p.channels > 2 ||
        !std::isfinite(p.sampleRate) || p.sampleRate < 0 ||
        p.framesPerPacket != 1 || !(p.flags & 8) || (p.flags & ~127u) ||
        p.bytesPerFrame != (p.bits / 8) * p.bufferChannels() ||
        p.bytesPerPacket != p.bytesPerFrame)
      throw std::runtime_error("PCM converter: unsupported layout " +
                               describePcm(p));
    const bool valid = p.floating() ? (p.bits == 32 || p.bits == 64)
                                    : (p.bits == 8 || p.bits == 16 ||
                                       p.bits == 24 || p.bits == 32);
    if (!valid || (output && (!p.floating() || p.bits != 32)))
      throw std::runtime_error("PCM converter: unsupported sample type " +
                               describePcm(p));
  }
  static std::uint64_t load(const std::uint8_t *p, unsigned bytes, bool big) {
    std::uint64_t n = 0;
    for (unsigned i = 0; i < bytes; ++i)
      n |= std::uint64_t(p[big ? bytes - 1 - i : i]) << (i * 8);
    return n;
  }
  std::uint32_t sample(const std::uint8_t *p) const {
    const auto raw = load(p, input_.bits / 8, input_.bigEndian());
    // Preserve float32 bits, including signed zero, without a floating
    // operation. The original D4U/D4T path is this identity conversion.
    if (input_.floating() && input_.bits == 32)
      return std::uint32_t(raw);
    float value;
    if (input_.floating()) {
      double d;
      std::memcpy(&d, &raw, sizeof(d));
      value = static_cast<float>(d);
    } else {
      const auto half = std::int64_t(1) << (input_.bits - 1);
      std::int64_t integer = std::int64_t(raw);
      if (input_.flags & 4) {
        if (raw & std::uint64_t(half))
          integer -= half * 2;
      } else
        integer -= half;
      value = static_cast<float>(
          std::ldexp(double(integer), -int(input_.bits - 1)));
    }
    std::uint32_t bits;
    std::memcpy(&bits, &value, sizeof(bits));
    return bits;
  }

public:
  PcmConversion(PcmFormat input, PcmFormat output)
      : input_(input), output_(output) {
    validate(input_, false);
    validate(output_, true);
    if (input_.sampleRate != output_.sampleRate ||
        input_.channels != output_.channels)
      throw std::runtime_error(
          "PCM converter: rate or channel conversion is unsupported");
  }
  const PcmFormat &input() const { return input_; }
  const PcmFormat &output() const { return output_; }
  void convert(const std::vector<PcmReadBuffer> &input,
               const std::vector<PcmWriteBuffer> &output,
               std::size_t frames) const {
    if (input.size() != input_.buffers() || output.size() != output_.buffers())
      throw std::runtime_error("PCM converter: unexpected buffer count");
    for (const auto &b : input)
      if (frames > b.bytes / input_.bytesPerFrame || (frames && !b.data))
        throw std::runtime_error("PCM converter: truncated input buffer");
    for (const auto &b : output)
      if (frames > b.bytes / output_.bytesPerFrame || (frames && !b.data))
        throw std::runtime_error("PCM converter: output buffer is too small");
    for (std::uint32_t channel = 0; channel < input_.channels; ++channel) {
      const auto *src = input[input_.planar() ? channel : 0].data;
      auto *dst = output[output_.planar() ? channel : 0].data;
      const auto sourceOffset =
          input_.planar() ? 0 : channel * (input_.bits / 8);
      const auto targetOffset = output_.planar() ? 0 : channel * 4;
      for (std::size_t frame = 0; frame < frames; ++frame) {
        const auto bits =
            sample(src + frame * input_.bytesPerFrame + sourceOffset);
        auto *p = dst + frame * output_.bytesPerFrame + targetOffset;
        for (unsigned i = 0; i < 4; ++i)
          p[output_.bigEndian() ? 3 - i : i] = std::uint8_t(bits >> (i * 8));
      }
    }
  }
};
} // namespace sophistry
