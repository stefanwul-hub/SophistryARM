#pragma once
// Isolated numeric kernel recovered from Sophistry 3.0.8 i386 0x73fb0.
// This is not the synth engine or an Audio Unit.
extern "C" {
float sophistry_satur_sample(float x, float a, float b) noexcept;
void sophistry_satur_block(const float* input, float* output, unsigned frames,
                          float a, float b, bool in_place) noexcept;
}
extern "C" void sophistry_satur_process(const float* input_l, const float* input_r,
        float* output_l, float* output_r, unsigned frames, float a, float b,
        unsigned channels, bool enabled) noexcept;
