#pragma once

#include "OriginalProgramState.h"

namespace elastik_state {

enum class SampleTransformKind : uint8_t { Direct, Render, Invalid };

struct ProgramSampleRenderPlan {
    SampleTransformKind kind;
    double file_tempo;
    double source_rate;
    float target_tempo;
    float tempo_ratio;
    float stretch_ratio;
    float pitch_ratio;
    int32_t shifter_mode;
    int32_t program_algorithm;
    int32_t processor_mode; // Selector passed to the original offline factory.
    // Expected length for the offline renderer. An absent value denotes
    // missing source metadata or an unrepresentable frame count.
    std::optional<int32_t> output_frames;
};

// 0x14a5d8: the basename carries its tempo after a three-character
// prefix. An absent, invalid, or zero tempo uses the attached program tempo.
double original_sample_tempo(std::u16string_view sample_path, double program_tempo) noexcept;

// 0x14b680, 0x14ab7e, 0x1c5456 and the length computation in 0x1c4930.
// The source rate and frame count are zero when the source is unavailable.
ProgramSampleRenderPlan plan_program_sample(const ProgramMapping&, double program_tempo, int32_t algorithm,
    std::u16string_view sample_path, double source_rate, int32_t source_frames) noexcept;

} // namespace elastik_state
