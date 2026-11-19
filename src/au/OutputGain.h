#pragma once

namespace sophistry {
// User-requested global compensation, applied once after the original DSP to
// every output channel. Master parameters, automation and saved states retain
// their original values. 10^(6/20), rounded once to the float audio format.
inline constexpr float outputGainDb = 6.0f;
inline constexpr float outputGainLinear = 1.9952623149688795f;
inline float compensatedOutput(float sample) { return sample * outputGainLinear; }
} // namespace sophistry
