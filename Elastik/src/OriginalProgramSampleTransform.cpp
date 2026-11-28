#include "OriginalProgramSampleTransform.h"
#include "OriginalScannedNumber.h"

#include <cmath>
#include <limits>

namespace elastik_state {
namespace {

int32_t processor_mode(int32_t algorithm, int32_t mode) noexcept {
    if (algorithm == 0) return mode == 1 ? 2 : 3;
    switch (mode) {
    case 1: return 1;
    case 2: return 4;
    case 3: return 5;
    default: return 0;
    }
}

} // namespace

double original_sample_tempo(std::u16string_view path, double program_tempo) noexcept {
    const auto slash = path.rfind(u'/');
    auto name = slash == std::u16string_view::npos ? path : path.substr(slash + 1);
    if (name.size() >= 3) name.remove_prefix(3);
    const auto start = name.find_first_of(u"0123456789.");
    if (start == std::u16string_view::npos) return program_tempo;

    name.remove_prefix(start);
    const double tempo = elastik_number::number_double(name.substr(0, name.find_first_not_of(u"0123456789.")));
    return tempo != 0.0 ? tempo : program_tempo;
}

ProgramSampleRenderPlan plan_program_sample(const ProgramMapping& mapping, double program_tempo, int32_t algorithm,
    std::u16string_view path, double source_rate, int32_t source_frames) noexcept {
    const auto& pitch = mapping.pitch;
    const double file_tempo = original_sample_tempo(path, program_tempo);
    // The original rounds the tempo product and quotient separately to float32.
    const float target = static_cast<float>(program_tempo * pitch.user_tempo_factor);
    const float ratio = static_cast<float>(target / file_tempo);
    const float stretch = 1.0f / ratio;
    // The i386 job adds these two contributions in float32 before pow.
    const float exponent = static_cast<float>(pitch.semitones) / 12.0f + static_cast<float>(pitch.cents) / 100.0f;
    const float pitch_ratio = static_cast<float>(std::pow(2.0, static_cast<double>(exponent)));

    const bool valid = std::isfinite(ratio) && ratio > 0.0f && std::isfinite(stretch) &&
        std::isfinite(pitch_ratio) && pitch_ratio > 0.0f;
    const bool render = ratio != 1.0f || pitch.semitones || pitch.cents;
    const auto kind = !valid ? SampleTransformKind::Invalid :
        render ? SampleTransformKind::Render : SampleTransformKind::Direct;
    const float count = static_cast<float>(source_frames) * stretch;
    std::optional<int32_t> output_frames;
    if (valid && source_frames > 0 && count >= 0.0f && count <= double(std::numeric_limits<int32_t>::max())) {
        output_frames = static_cast<int32_t>(count);
    }
    return {kind, file_tempo, source_rate, target, ratio, stretch, pitch_ratio, pitch.shifter_mode, algorithm,
            processor_mode(algorithm, pitch.shifter_mode), output_frames};
}

} // namespace elastik_state
