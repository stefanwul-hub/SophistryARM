#include "../src/OriginalProgramVoice.h"

#include <cstdio>

namespace {
using namespace elastik_state;

bool read(void*, float* const* output, int first, int count) {
    const int channel = output[0] ? 0 : 1;
    for (int i = 0; i < count; ++i) {
        const auto index = static_cast<uint32_t>(first) + static_cast<uint32_t>(i);
        const int value = static_cast<int>((index * 73u + channel * 1009u) % 32768u) - 16384;
        output[channel][i] = static_cast<float>(value) / 32768.0f;
    }
    return true;
}
void lock(void*) {}

template <class T>
bool write(T value) { return std::fwrite(&value, sizeof(value), 1, stdout) == 1; }

bool ramp(const ElastikOriginalRamp& r) { return write(r.target) && write(r.current) && write(r.step); }

bool snapshot(const ProgramVoicePlayback& v) {
    const auto& s = v.loop.chunk;
    if (!write(static_cast<uint8_t>(v.active)) || !write(static_cast<uint8_t>(s.released)) ||
        !write(v.note) || !write(v.velocity) || !write(v.release_velocity) ||
        !write(v.loop.cursor) || !write(v.leading_frames) || !write(v.release_offset) ||
        !write(s.loop_start) || !write(s.loop_stop) || !write(v.loop.length)) return false;
    for (const auto* ramps : {v.gain, s.fade_in, s.fade_out}) {
        if (!ramp(ramps[0]) || !ramp(ramps[1])) return false;
    }
    return ramp(v.attack) && ramp(v.release);
}

bool run(const int* header) {
    std::string raw(header[0], '\0');
    if (std::fread(raw.data(), 1, raw.size(), stdin) != raw.size()) return false;
    const auto archive = decode_program_state(raw);
    if (!archive.program) return false;
    const auto& program = *archive.program;
    const int frame_count = header[1];
    if (!frame_count) {
        for (int note = 0; note < 128; ++note) {
            const auto* mapping = program_mapping_for_note(program, note);
            if (!write(mapping ? mapping->record : Reference{0})) return false;
        }
        return true;
    }

    const auto* mapping = program_mapping_for_note(program, 36);
    if (!mapping) return false;
    const ElastikOriginalSampleReader reader{nullptr, nullptr, read};
    ElastikOriginalSampleFile file{};
    file.known_frames = frame_count;
    file.channel_format = 2;
    file.reader = &reader;
    file.lock = file.unlock = lock;
    ElastikOriginalSampleHandle handle{&file, nullptr, true};

    ProgramVoicePlayback voice{};
    const int channels = header[2];
    if (!trigger_program_voice(voice, *mapping, file, channels, 36, header[4], header[3]) || !snapshot(voice)) return false;
    for (int block = 0; block < header[7]; ++block) {
        if (block == 1) {
            if (!release_program_voice(voice, *mapping, file, channels, header[5], header[6]) || !snapshot(voice)) {
                return false;
            }
        }
        int frames;
        if (std::fread(&frames, sizeof(frames), 1, stdin) != 1) return false;
        std::vector<std::vector<float>> audio(channels, std::vector<float>(frames + 8, 0.125f));
        std::vector<float*> buffers;
        for (auto& channel : audio) buffers.push_back(channel.data() + 4);
        const auto result = render_program_voice(voice, *mapping, handle, buffers.data(), channels, frames);
        if (!write(result.status) || !snapshot(voice)) return false;
        for (const auto& channel : audio) {
            if (std::fwrite(channel.data(), sizeof(float), channel.size(), stdout) != channel.size()) return false;
        }
    }
    return true;
}

} // namespace

int main() {
    for (;;) {
        int header[8];
        const auto n = std::fread(header, 1, sizeof(header), stdin);
        if (!n && std::feof(stdin)) return 0;
        if (n != sizeof(header) || !run(header) || std::fflush(stdout)) return 2;
    }
}
