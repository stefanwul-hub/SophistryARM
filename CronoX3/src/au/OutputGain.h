#pragma once
namespace sophistry {
// CRX007: apply the requested +6 dB to the original Master's linear coefficient
// in Parameter_c::setValue. The AU output buffers receive no second gain.
inline constexpr float outputGainDb = 6.0f;
inline constexpr float outputGainLinear = 1.0f;
inline float compensatedOutput(float sample) { return sample; }
} // namespace sophistry
