#include "OriginalProgramVoice.h"

#include <algorithm>
#include <cmath>

namespace elastik_state {
namespace {

constexpr ElastikOriginalRamp loop_fade{1.0f, 0.0f, 0.01f};

void advance(ElastikOriginalRamp& ramp) noexcept {
    ramp.current += ramp.step;
    if ((ramp.step > 0.0f && ramp.current >= ramp.target) ||
        (ramp.step < 0.0f && ramp.current <= ramp.target)) {
        ramp.current = ramp.target;
        ramp.step = 0.0f;
    }
}

void multiply_gain(ElastikOriginalRamp& gain, float target, float* samples, int frames) noexcept {
    gain.target = target;
    gain.step = (target - gain.current) / 100.0f;
    for (int i = 0; i < frames; ++i) {
        if (gain.step != 0.0f) advance(gain);
        samples[i] *= gain.current;
    }
}

void multiply_envelope(ElastikOriginalRamp& envelope, float* const* pair, int frames) noexcept {
    if (envelope.step == 0.0f) return;
    for (int i = 0; i < frames; ++i) {
        if (envelope.step != 0.0f) advance(envelope);
        pair[0][i] *= envelope.current;
        pair[1][i] *= envelope.current;
    }
}

} // namespace

VoiceRenderResult render_program_voice(ProgramVoicePlayback& voice, const ProgramMapping& mapping,
    ElastikOriginalSampleHandle& sample, float* const* outputs, int output_channels, int frames) noexcept {
    if (!voice.active) return {VoiceRenderStatus::Inactive, 0};
    if (mapping.mix.filter_on) return {VoiceRenderStatus::FilterRequired, 0};
    auto& loop = voice.loop;
    auto& chunk = loop.chunk;
    const auto direction = mapping.loop.direction;
    if (!sample.file || !sample.file->reader || !outputs || output_channels < 1 || frames < 0 ||
        voice.leading_frames < -1 || voice.leading_frames > frames || chunk.sample_frames <= 0 ||
        loop.cursor < 0 || loop.cursor >= chunk.sample_frames || direction < 0 || direction > 1 ||
        (direction && chunk.loop_start == chunk.loop_stop) ||
        !std::isfinite(mapping.mix.volume) || !std::isfinite(mapping.mix.panorama)) {
        return {VoiceRenderStatus::InvalidVoice, 0};
    }

    const int channels = std::min(output_channels, 2);
    const int first_output = (mapping.mix.first_output_channel / 2 * 2) % output_channels;
    const bool envelopes = voice.attack.step != 0.0f || voice.release.step != 0.0f;
    if (first_output < 0 || first_output > output_channels - (envelopes ? 2 : channels)) {
        return {VoiceRenderStatus::InvalidVoice, 0};
    }
    auto* const pair = outputs + first_output;
    if (!pair[0] || ((channels == 2 || envelopes) && !pair[1])) {
        return {VoiceRenderStatus::InvalidVoice, 0};
    }

    chunk.direction = direction;
    chunk.looping = mapping.loop.mode;
    int written = std::max(voice.leading_frames, 0);
    for (int channel = 0; channel < channels; ++channel) std::fill_n(pair[channel], written, 0.0f);
    voice.leading_frames = -1;

    const float pan = mapping.mix.panorama;
    const int attenuation_channel = pan < 0.5f ? 1 : (pan > 0.5f ? 0 : -1);
    const float pan_factor = pan < 0.5f ? pan + pan : (1.0f - pan) + (1.0f - pan);
    while (written < frames) {
        int next = loop.cursor;
        int count = 0;
        for (int channel = 0; channel < channels; ++channel) {
            ElastikOriginalReadRange range{};
            count = elastik_original_read_voice_chunk(&chunk, pair[channel] + written, channel,
                loop.cursor, frames - written, &next, &range, elastik_original_sample_provider, &sample);
            if (count <= 0) return {VoiceRenderStatus::Stalled, written};
            const auto target = channel == attenuation_channel ? mapping.mix.volume * pan_factor : mapping.mix.volume;
            multiply_gain(voice.gain[channel], target, pair[channel] + written, count);
        }
        loop.cursor = next;
        written += count;
        if (next != (direction == 0 ? chunk.loop_start : chunk.loop_stop)) continue;

        if (!chunk.looping) {
            chunk.released = 1;
            break;
        }
        // A changed mapping enters the same initializer at the loop boundary.
        // Configure on a copy so an invalid live edit never alters the current loop.
        auto updated = loop;
        if (configure_program_voice(updated, mapping, *sample.file, channels) != VoiceLoopStatus::Ready) {
            return {VoiceRenderStatus::InvalidVoice, written};
        }
        if (updated.chunk.loop_start != chunk.loop_start || updated.chunk.loop_stop != chunk.loop_stop) {
            if (direction && updated.chunk.loop_start == updated.chunk.loop_stop) {
                return {VoiceRenderStatus::InvalidVoice, written};
            }
            loop = updated;
        } else if (chunk.loop_start != 0) {
            for (int channel = 0; channel < channels; ++channel) chunk.fade_in[channel] = loop_fade;
        }
    }

    multiply_envelope(voice.attack, pair, frames);
    multiply_envelope(voice.release, pair, frames);
    if (chunk.released && voice.release.step == 0.0f) {
        chunk.released = 0;
        voice.active = false;
        return {VoiceRenderStatus::Finished, written};
    }
    return {VoiceRenderStatus::Rendered, written};
}

} // namespace elastik_state
