#include "OriginalProgramVoiceFilter.h"

#include <algorithm>
#include <cmath>

namespace elastik_state {
namespace {

float limit_feedback(float x, float knee) noexcept {
    const float magnitude = std::fabs(x);
    if (magnitude <= knee) return x;
    const float headroom = 1.0f - knee;
    const float limited = (1.0f - 1.0f / ((magnitude - knee) * (1.0f / headroom) + 1.0f)) * headroom + knee;
    return x < 0.0f ? -limited : limited;
}

float process_sample(float input, ProgramVoiceFilter::History& history,
    const ProgramVoiceFilter::Coefficients& coeff, float scale, float knee,
    int response, bool steep, uint32_t& noise) noexcept {
    auto& stage = history.stages;
    const float last = stage[3];
    const float high = input - limit_feedback((last + (last * last * last) * -0.01667f) * scale, knee);

    noise = noise * 0x0bb38435u + 0x3619636bu;
    const float perturbation = (static_cast<float>(noise) * 4.66e-10f - 1.0f) * coeff.dirt + 1.0f;
    const float feedback = perturbation * coeff.feedback;
    const float gain = perturbation * coeff.input;
    float previous = high;
    float delayed = history.previous_input;
    for (auto& value : stage) {
        const float filtered = (previous + delayed) * gain - feedback * value;
        delayed = value;
        value = previous = filtered;
    }
    history.previous_input = high;

    switch (response) {
    case 0: return steep ? stage[3] : stage[1];
    case 1: return steep ? high - stage[3] : high - stage[1];
    case 2: return steep ? (high - stage[1] + stage[2]) - stage[0]
                         : (stage[3] + (stage[3] - stage[1])) - stage[1];
    default: return steep ? high + stage[0] : high + stage[2];
    }
}

void update_coefficients(ProgramVoiceFilter::Mode& mode) noexcept {
    const float base = mode.cutoff_hz * (1.0f / 22050.0f);
    const float resonance_curve = 1.7f - base;
    mode.feedback_scale = (resonance_curve * resonance_curve * resonance_curve * 0.66f) * mode.resonance;
    const float clamped = std::min(static_cast<float>(base * (44100.0 / mode.rate)) * 0.907f, 0.907f);
    const float feedback = (clamped * 3.6f + (clamped * -1.6f) * clamped) - 1.0f;
    const float square = clamped * clamped;
    const float dirt = ((mode.dirt + mode.resonance_dirt * mode.resonance) * 0.5f) *
        ((clamped * 0.99f + 0.01f) + (clamped * square) * -1.1f) * (mode.resonance * 0.5f + 0.5f);
    mode.target = {feedback, (feedback + 1.0f) * 0.5f, dirt};
}

} // namespace

void ProgramVoiceFilter::clear_history() noexcept {
    for (auto& mode : modes) mode.history = {};
}

bool ProgramVoiceFilter::valid(const ProgramFilterSettings& settings, const ProgramVoiceFilterContext& context) noexcept {
    return settings.q >= 0 && settings.q <= 5 && std::isfinite(context.sample_rate) && context.sample_rate > 0.0 &&
        std::isfinite(settings.cutoff) && std::isfinite(settings.resonance) && std::isfinite(settings.dirt) &&
        std::isfinite(settings.resonance_dirt) && std::isfinite(settings.limiter_knee);
}

void ProgramVoiceFilter::render(const ProgramFilterSettings& settings, ProgramVoiceFilterContext& context,
                               float* const* pair, int frames) noexcept {
    if (previous_type != settings.type) clear_history();
    previous_type = settings.type;
    if (settings.type < 0 || settings.type > 3) return;

    auto& mode = modes[settings.type];
    const bool nonlinear = settings.type < 2;
    const float cutoff = static_cast<float>(20.0 * std::pow(2.0, static_cast<double>(settings.cutoff * 10.0f)));
    const int order = settings.q + 1;
    const float resonance = (static_cast<float>(settings.q) * -0.1f + 1.0f) * settings.resonance;
    const bool changed_order = order != mode.order;
    mode.dirty |= mode.cutoff_hz != cutoff || mode.resonance != resonance || mode.rate != context.sample_rate;
    mode.order = order;
    mode.rate = context.sample_rate;
    mode.cutoff_hz = cutoff;
    mode.resonance = resonance;
    if (nonlinear) {
        mode.dirty |= mode.dirt != settings.dirt || mode.resonance_dirt != settings.resonance_dirt ||
            mode.limiter_knee != settings.limiter_knee;
        mode.dirt = settings.dirt;
        mode.resonance_dirt = settings.resonance_dirt;
        mode.limiter_knee = settings.limiter_knee;
    }
    if (changed_order) mode.history = {};

    // The limiter uses the new knee immediately. The other control changes
    // wait for the current coefficient sweep unless the order changes.
    const bool begin_ramp = !changed_order && mode.dirty && !mode.remaining;
    if (changed_order || begin_ramp) {
        const auto previous = mode.target;
        update_coefficients(mode);
        mode.dirty = false;
        if (begin_ramp) {
            mode.current = previous;
            mode.step = {mode.target.feedback - previous.feedback, mode.target.input - previous.input,
                         mode.target.dirt - previous.dirt};
            mode.remaining = static_cast<int>(std::max(std::fabs(mode.step.feedback), std::fabs(mode.step.input)) /
                                              0.00019999999494757503);
            if (mode.remaining > 0) {
                const float length = static_cast<float>(mode.remaining);
                mode.step.feedback /= length;
                mode.step.input /= length;
                mode.step.dirt /= length;
            }
        }
    }
    if (!begin_ramp && !mode.remaining) mode.current = mode.target;

    const auto start = mode.current;
    const int remaining = mode.remaining;
    const int additional = (order - 1) / 2;
    constexpr int responses[] = {1, 0, 2, 3};
    const int response = responses[settings.type];
    const bool steep = (order & 1) == 0;
    for (int channel = 0; channel < 2; ++channel) {
        mode.current = start;
        mode.remaining = remaining;
        for (int frame = 0; frame < frames; ++frame) {
            auto& sample = pair[channel][frame];
            for (int pass = additional; pass > 0; --pass) {
                sample = process_sample(sample, mode.history[pass][channel], mode.current, mode.feedback_scale,
                                        mode.limiter_knee, response, true, context.noise);
            }
            sample = process_sample(sample, mode.history[0][channel], mode.current, mode.feedback_scale,
                                    mode.limiter_knee, response, steep, context.noise);
            if (mode.remaining > 0) {
                mode.current.feedback += mode.step.feedback;
                mode.current.input += mode.step.input;
                mode.current.dirt += mode.step.dirt;
                --mode.remaining;
            }
        }
    }
}

} // namespace elastik_state
