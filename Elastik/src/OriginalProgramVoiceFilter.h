#pragma once

#include <array>
#include <cstdint>

namespace elastik_state {

struct ProgramFilterSettings {
    float cutoff = 0.0f;
    float resonance = 0.0f;
    int32_t q = 0;
    int32_t type = 0;
    float dirt = 0.05f;
    float resonance_dirt = 0.1f;
    float limiter_knee = 0.5f;
};

// Supply the processor rate and share this stream between voices in render order.
struct ProgramVoiceFilterContext {
    double sample_rate;
    uint32_t noise = 0x56ce;
};

struct ProgramVoiceFilter {
    struct History {
        float stages[4]{};
        float previous_input{};
    };
    struct Coefficients {
        float feedback = -1.0f;
        float input = 0.0f;
        float dirt = 0.0f;
    };
    struct Mode {
        std::array<std::array<History, 2>, 3> history{};
        Coefficients target{};
        Coefficients current{};
        Coefficients step{0.0f, 0.0f, 0.0f};
        float cutoff_hz = 0.0f;
        float resonance = 0.0f;
        float dirt = 0.0f;
        float resonance_dirt = 0.0f;
        float limiter_knee = 0.0f;
        float feedback_scale = 0.0f;
        double rate = 0.0;
        int order = 0;
        int remaining = 0;
    };

    int previous_type = -1;
    Mode modes[4]{};

    void clear_history() noexcept;
    void bypass() noexcept { previous_type = -1; }
    static bool valid(const ProgramFilterSettings&, const ProgramVoiceFilterContext&) noexcept;
    // The four original modes filter the stereo pair in place.
    void render(const ProgramFilterSettings&, ProgramVoiceFilterContext&, float* const*, int) noexcept;
};

} // namespace elastik_state
