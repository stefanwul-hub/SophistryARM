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
};

enum class VoiceRenderStatus : uint8_t { Rendered, Finished, Inactive, InvalidVoice, FilterRequired, Stalled };

struct VoiceRenderResult {
    VoiceRenderStatus status;
    int frames_written;
};

// Direct sample branch of 0x1532f8. Audio buffers use distinct planar outputs
// with sufficient room for frames. Provide the resolved sample, a configured
// loop, and the current envelope ramps. A host may supply a start offset via
// leading_frames. The caller handles the Finished note notification.
VoiceRenderResult render_program_voice(ProgramVoicePlayback&, const ProgramMapping&,
    ElastikOriginalSampleHandle&, float* const* outputs, int output_channels, int frames) noexcept;

} // namespace elastik_state
