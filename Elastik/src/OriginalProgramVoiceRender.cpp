#include "OriginalProgramVoice.h"

#include <algorithm>
#include <cmath>

namespace elastik_state {
namespace {

constexpr ElastikOriginalRamp loop_fade{1.0f, 0.0f, 0.01f};
constexpr double envelope_threshold = 0.00001;

float voice_gain(const ProgramMixSettings& mix, int channel) noexcept {
    const float pan = mix.panorama;
    if (channel == 1 && pan < 0.5f) return mix.volume * (pan + pan);
    if (channel == 0 && pan > 0.5f) {
        const float attenuation = 1.0f - pan;
        return mix.volume * (attenuation + attenuation);
    }
    return mix.volume;
}

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

const ProgramMapping* program_mapping_for_note(const ProgramState& program, uint8_t note) noexcept {
    const auto& mappings = program.mappings;
    if (note < 36 || note > 103 || mappings.empty()) return nullptr;
    const auto index = static_cast<size_t>(mappings.front().midi_note == 36 ? note - 36 :
                                           (note <= 71 ? note : note - 72));
    return index < mappings.size() ? &mappings[index] : nullptr;
}

bool trigger_program_voice(ProgramVoicePlayback& voice, const ProgramMapping& mapping,
    const ElastikOriginalSampleFile& sample, int output_channels, uint8_t note, uint8_t velocity,
    int sample_offset) noexcept {
    if (output_channels < 1 || sample_offset < -1 || note > 127 ||
        !std::isfinite(mapping.mix.volume) || !std::isfinite(mapping.mix.panorama) ||
        !std::isfinite(mapping.mix.envelope_attack)) return false;
    auto loop = voice.loop;
    if (configure_program_voice(loop, mapping, sample, output_channels) != VoiceLoopStatus::Ready) return false;

    voice.loop = loop;
    voice.filter.clear_history();
    voice.loop.chunk.released = 0;
    for (int channel = 0; channel < std::min(output_channels, 2); ++channel) {
        const float gain = voice_gain(mapping.mix, channel);
        voice.gain[channel] = {gain, gain, 0.0f};
    }

    const float attack = mapping.mix.envelope_attack;
    const float step = attack > envelope_threshold ? 1.0f / (static_cast<float>(loop.length) * attack) : 1.0f;
    voice.attack = step >= 1.0f ? ElastikOriginalRamp{1.0f, 1.0f, 0.0f}
                                : ElastikOriginalRamp{1.0f, 0.0f, step};
    voice.release = {0.0f, 1.0f, 0.0f};
    voice.leading_frames = sample_offset;
    voice.release_offset = -1;
    voice.note = note;
    voice.velocity = velocity;
    voice.active = true;
    return true;
}

bool release_program_voice(ProgramVoicePlayback& voice, const ProgramMapping& mapping,
    const ElastikOriginalSampleFile& sample, int output_channels, uint8_t velocity,
    int sample_offset) noexcept {
    const float release = mapping.mix.envelope_release;
    if (!voice.active || output_channels < 1 || !std::isfinite(release) || sample_offset < 0) return false;
    float step = 0.0f;
    if (release > envelope_threshold) {
        auto current = voice.loop;
        if (configure_program_voice(current, mapping, sample, output_channels) != VoiceLoopStatus::Ready) return false;
        const float computed = -1.0f / (static_cast<float>(current.length) * release);
        if (computed > -1.0f) step = computed;
    } else {
        for (int channel = 0; channel < std::min(output_channels, 2); ++channel) {
            voice.loop.chunk.fade_out[channel] = {0.0f, 1.0f, -0.01f};
        }
    }
    voice.release.step = step;
    voice.release_velocity = velocity;
    voice.release_offset = sample_offset;
    voice.loop.chunk.released = 1;
    return true;
}

VoiceRenderResult render_program_voice(ProgramVoicePlayback& voice, const ProgramMapping& mapping,
    ElastikOriginalSampleHandle& sample, float* const* outputs, int output_channels, int frames,
    ProgramVoiceFilterContext* filter_context) noexcept {
    if (!voice.active) return {VoiceRenderStatus::Inactive, 0};
    if (mapping.mix.filter_on && !filter_context) return {VoiceRenderStatus::FilterRequired, 0};
    if (mapping.mix.filter_on && !ProgramVoiceFilter::valid(mapping.filter, *filter_context)) {
        return {VoiceRenderStatus::InvalidVoice, 0};
    }
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
    const bool pair_required = mapping.mix.filter_on || voice.attack.step != 0.0f || voice.release.step != 0.0f;
    if (first_output < 0 || first_output > output_channels - (pair_required ? 2 : channels)) {
        return {VoiceRenderStatus::InvalidVoice, 0};
    }
    auto* const pair = outputs + first_output;
    if (!pair[0] || ((channels == 2 || pair_required) && !pair[1])) {
        return {VoiceRenderStatus::InvalidVoice, 0};
    }

    chunk.direction = direction;
    chunk.looping = mapping.loop.mode;
    int written = std::max(voice.leading_frames, 0);
    for (int channel = 0; channel < channels; ++channel) std::fill_n(pair[channel], written, 0.0f);
    voice.leading_frames = -1;

    while (written < frames) {
        int next = loop.cursor;
        int count = 0;
        for (int channel = 0; channel < channels; ++channel) {
            ElastikOriginalReadRange range{};
            count = elastik_original_read_voice_chunk(&chunk, pair[channel] + written, channel,
                loop.cursor, frames - written, &next, &range, elastik_original_sample_provider, &sample);
            if (count <= 0) return {VoiceRenderStatus::Stalled, written};
            multiply_gain(voice.gain[channel], voice_gain(mapping.mix, channel), pair[channel] + written, count);
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

    if (mapping.mix.filter_on) voice.filter.render(mapping.filter, *filter_context, pair, frames);
    else voice.filter.bypass();
    multiply_envelope(voice.attack, pair, frames);
    multiply_envelope(voice.release, pair, frames);
    if (chunk.released && voice.release.step == 0.0f) {
        chunk.released = 0;
        voice.active = false;
        voice.note = 0x80;
        return {VoiceRenderStatus::Finished, written};
    }
    return {VoiceRenderStatus::Rendered, written};
}

} // namespace elastik_state
