#include "OriginalProgramVoice.h"

#include <algorithm>

namespace elastik_state {
namespace {

constexpr double turn = 360.0;

bool valid_degrees(float degrees) noexcept {
    return degrees >= 0.0f && degrees <= turn;
}

int boundary(float degrees, int frames, int zero_position) noexcept {
    if (degrees == 0.0f || degrees == turn) return zero_position;
    return static_cast<int>((static_cast<double>(frames) * degrees) / turn);
}

} // namespace

VoiceLoopStatus configure_program_voice(ProgramVoiceLoop& voice, const ProgramMapping& mapping,
                                        const ElastikOriginalSampleFile& sample, int voice_channels) noexcept {
    const auto& loop = mapping.loop;
    if (!valid_degrees(loop.start_degree) || !valid_degrees(loop.stop_degree)) {
        return VoiceLoopStatus::InvalidDegrees;
    }
    const int frames = elastik_original_file_frame_count(&sample);
    if (frames <= 0) return VoiceLoopStatus::EmptySample;

    const int first = boundary(loop.start_degree, frames, 0);
    int last = boundary(loop.stop_degree, frames, frames - 1);
    if (last == first) last = first == 0 ? frames - 1 : first - 1;

    if (first == last) voice.length = frames;
    else if (first < last) voice.length = last - first + 1;
    else voice.length = (frames - first) + (last + 1);

    auto& chunk = voice.chunk;
    chunk.sample_frames = frames;
    chunk.loop_start = first;
    chunk.loop_stop = last;
    chunk.direction = loop.direction;
    chunk.last_direction = loop.direction;
    chunk.looping = loop.mode;
    voice.cursor = loop.direction == 0 ? first : last;

    const ElastikOriginalRamp fade_in = first == 0 ? ElastikOriginalRamp{1.0f, 1.0f, 0.0f}
                                                   : ElastikOriginalRamp{1.0f, 0.0f, 0.01f};
    for (int i = 0; i < std::min(voice_channels, 2); ++i) {
        chunk.fade_in[i] = fade_in;
        chunk.fade_out[i] = {1.0f, 1.0f, 0.0f};
    }
    return VoiceLoopStatus::Ready;
}

} // namespace elastik_state
