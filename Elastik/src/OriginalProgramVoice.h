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

} // namespace elastik_state
