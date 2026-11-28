#pragma once

#include "OriginalProgramState.h"
#include "OriginalSampleFile.h"
#include "OriginalVoiceChunk.h"

namespace elastik_state {

struct ProgramVoiceLoop {
    ElastikOriginalVoiceChunkState chunk{};
    int cursor{};
    int length{};
};

enum class VoiceLoopStatus : uint8_t { Ready, EmptySample, InvalidDegrees };

// Use the decoded ETKeyMapping and the sample returned by the file opener.
// Recalculate inclusive source bounds (0x14af3e and 0x14d374) and initialize
// the cursor and active ramps (0x152472). The release state and inactive
// channel ramps remain intact, including when the result is an error.
VoiceLoopStatus configure_program_voice(ProgramVoiceLoop&, const ProgramMapping&,
                                        const ElastikOriginalSampleFile&, int voice_channels) noexcept;

struct ProgramVoicePlayback {
    ProgramVoiceLoop loop{};
    ElastikOriginalRamp gain[2]{};
    ElastikOriginalRamp attack{};
    ElastikOriginalRamp release{};
    int leading_frames = -1;
    bool active = true;
    uint8_t note = 0x80;
    uint8_t velocity = 0;
    uint8_t release_velocity = 0;
    int release_offset = -1;
    ProgramVoiceFilter filter{};
};

// ETProgram::keyMappingForMidiNote (0x15f296), including the alternate
// saved list order. A missing slot is returned as null.
const ProgramMapping* program_mapping_for_note(const ProgramState&, uint8_t note) noexcept;

// Direct sample voice lifecycle (0x152e74 and 0x1521a0). The host selects
// and opens the mapped sample and schedules the calls at the MIDI event.
// A failed initialization leaves the existing voice intact.
bool trigger_program_voice(ProgramVoicePlayback&, const ProgramMapping&, const ElastikOriginalSampleFile&,
    int output_channels, uint8_t note, uint8_t velocity, int sample_offset) noexcept;
bool release_program_voice(ProgramVoicePlayback&, const ProgramMapping&, const ElastikOriginalSampleFile&,
    int output_channels, uint8_t velocity, int sample_offset) noexcept;

enum class VoiceRenderStatus : uint8_t { Rendered, Finished, Inactive, InvalidVoice, FilterRequired, Stalled };

struct VoiceRenderResult {
    VoiceRenderStatus status;
    int frames_written;
};

// Direct sample branch of 0x1532f8. Audio buffers use distinct planar outputs
// with sufficient room for frames. Provide the resolved sample, a configured
// loop, and the current envelope ramps. A host may supply a start offset via
// leading_frames. A filter-enabled stereo voice needs the processor context.
// The caller handles the Finished note notification.
VoiceRenderResult render_program_voice(ProgramVoicePlayback&, const ProgramMapping&,
    ElastikOriginalSampleHandle&, float* const* outputs, int output_channels, int frames, ProgramVoiceFilterContext* filter_context = nullptr) noexcept;

} // namespace elastik_state
