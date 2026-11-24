#pragma once

namespace sophistry {
// CronoX retains its original DSP output gain. The +6 dB compensation requested
// for Sophistry CP038 is specific to that separate plugin.
inline constexpr float outputGainDb = 0.0f;
inline constexpr float outputGainLinear = 1.0f;
inline float compensatedOutput(float sample) { return sample * outputGainLinear; }
} // namespace sophistry
