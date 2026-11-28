#include "../src/OriginalProgramVoice.h"

#include <array>
#include <cstdio>

namespace {
using namespace elastik_state;

struct Source {
    int frames;
};

int frame_count(void* p) { return static_cast<Source*>(p)->frames; }
void lock(void*) {}

bool read(void*, float* const* output, int first, int count) {
    const int channel = output[0] ? 0 : 1;
    for (int i = 0; i < count; ++i) {
        const auto index = static_cast<uint32_t>(first) + static_cast<uint32_t>(i);
        const int value = static_cast<int>((index * 73u + channel * 1009u) % 32768u) - 16384;
        output[channel][i] = static_cast<float>(value) / 32768.0f;
    }
    return true;
}

template <class T>
bool write(T value) { return std::fwrite(&value, sizeof(value), 1, stdout) == 1; }

bool ramp(const ElastikOriginalRamp& r) { return write(r.target) && write(r.current) && write(r.step); }

bool snapshot(const ProgramVoicePlayback& v) {
    const auto& s = v.loop.chunk;
    if (!write(static_cast<uint8_t>(v.active)) || !write(static_cast<uint8_t>(s.released)) ||
        !write(v.loop.cursor) || !write(v.leading_frames) || !write(s.loop_start) || !write(s.loop_stop) ||
        !write(v.loop.length)) return false;
    for (const auto* ramps : {v.gain, s.fade_in, s.fade_out}) {
        if (!ramp(ramps[0]) || !ramp(ramps[1])) return false;
    }
    return ramp(v.attack) && ramp(v.release);
}

bool run(const int* header) {
    std::string raw(header[0], '\0');
    if (std::fread(raw.data(), 1, raw.size(), stdin) != raw.size()) return false;
    const auto archive = decode_program_state(raw);
    if (!archive.program || archive.program->mappings.size() != 1) return false;
    auto mapping = archive.program->mappings.front();

    Source source{header[1]};
    const ElastikOriginalSampleReader reader{&source, frame_count, read};
    ElastikOriginalSampleFile file{};
    file.known_frames = source.frames;
    file.channel_format = 2;
    file.reader = &reader;
    file.lock = file.unlock = lock;
    ElastikOriginalSampleHandle handle{&file, nullptr, true};

    ProgramVoicePlayback voice{};
    voice.leading_frames = header[3];
    voice.attack = header[4] ? ElastikOriginalRamp{1.0f, 0.0f, 0.125f} : ElastikOriginalRamp{};
    voice.release = header[5] ? ElastikOriginalRamp{0.0f, 1.0f, -0.00390625f} : ElastikOriginalRamp{};
    voice.loop.chunk.released = header[6];
    voice.loop.chunk.fade_in[1] = {0.75f, 0.125f, 0.0625f};
    voice.loop.chunk.fade_out[1] = {1.0f, 0.25f, 0.125f};
    voice.gain[0].current = 0.25f;
    voice.gain[1].current = 0.75f;
    const int channels = header[2];
    if (configure_program_voice(voice.loop, mapping, file, channels) != VoiceLoopStatus::Ready) return false;

    for (int block = 0; block < header[8]; ++block) {
        if (header[7] && block == 1) {
            mapping.loop.start_degree = 75.0f;
            mapping.loop.stop_degree = 280.0f;
        }
        int frames;
        if (std::fread(&frames, sizeof(frames), 1, stdin) != 1) return false;
        std::vector<std::vector<float>> audio(channels, std::vector<float>(frames + 8, 0.125f));
        std::vector<float*> buffers;
        for (auto& channel : audio) buffers.push_back(channel.data() + 4);
        const auto result = render_program_voice(voice, mapping, handle, buffers.data(), channels, frames);
        if (!write(result.status) || !write(result.frames_written) || !snapshot(voice)) return false;
        for (const auto& channel : audio) {
            if (std::fwrite(channel.data(), sizeof(float), channel.size(), stdout) != channel.size()) return false;
        }
    }
    return true;
}

} // namespace

int main() {
    for (;;) {
        int header[9];
        const auto n = std::fread(header, 1, sizeof(header), stdin);
        if (!n && std::feof(stdin)) return 0;
        if (n != sizeof(header) || !run(header) || std::fflush(stdout)) return 2;
    }
}
