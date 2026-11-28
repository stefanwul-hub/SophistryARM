#include "../src/OriginalProgramVoice.h"

#include <cstdio>

namespace {

using namespace elastik_state;

ProgramVoiceLoop seeded(int released) {
    ProgramVoiceLoop voice{};
    voice.chunk = {19, 2, 13, 7, 5, released, 9,
                   {{0.25f, 0.5f, -0.125f}, {0.75f, 0.125f, 0.0625f}},
                   {{0.0f, 0.25f, -0.125f}, {1.0f, 0.25f, 0.125f}}};
    voice.cursor = 17;
    voice.length = 18;
    return voice;
}

struct Samples {
    int frames;
    std::vector<int16_t> pcm;
    int calls{};
    int channel{};
    int first{};
    int count{};
};

int frame_count(void* p) { return static_cast<Samples*>(p)->frames; }
void lock(void*) {}

bool samples(void* p, float* const* destination, int first, int count) {
    auto& state = *static_cast<Samples*>(p);
    if (first < 0 || count < 0 || first + count > state.frames) return false;
    const int channel = destination[0] ? 0 : 1;
    state.first = first;
    state.count = count;
    state.channel = channel;
    ++state.calls;
    const auto start = static_cast<uint32_t>(first);
    for (int i = 0; i < count; ++i) {
        const auto index = start + static_cast<uint32_t>(i);
        const int pcm = state.pcm.empty()
            ? static_cast<int>((index * 73u + channel * 1009u) % 32768u) - 16384
            : state.pcm[index * 2 + channel];
        destination[channel][i] = static_cast<float>(pcm) / 32768.0f;
    }
    return true;
}

template <class T>
bool write(T value) { return std::fwrite(&value, sizeof(T), 1, stdout) == 1; }

bool ramps(const ElastikOriginalVoiceChunkState& s) {
    for (const auto& values : {s.fade_in, s.fade_out}) {
        for (int i = 0; i < 2; ++i) {
            const auto& r = values[i];
            if (!write(r.target) || !write(r.current) || !write(r.step)) return false;
        }
    }
    return true;
}

bool snapshot(const ProgramVoiceLoop& v) {
    const auto& s = v.chunk;
    return write(s.sample_frames) && write(s.loop_start) && write(s.loop_stop) && write(s.direction) &&
        write(s.looping) && write(s.released) && write(s.last_direction) && write(v.cursor) && write(v.length) &&
        ramps(s);
}

bool run(const int* header) {
    std::string raw(header[0], '\0');
    if (std::fread(raw.data(), 1, raw.size(), stdin) != raw.size()) return false;
    Samples source{header[1], std::vector<int16_t>(header[7])};
    if (!source.pcm.empty() &&
        std::fread(source.pcm.data(), sizeof(int16_t), source.pcm.size(), stdin) != source.pcm.size()) return false;
    auto result = decode_program_state(raw);
    if (!write(result.error)) return false;
    if (!result.program) return true;

    const ElastikOriginalSampleReader reader{&source, frame_count, samples};
    ElastikOriginalSampleFile file{};
    file.reader = &reader;
    file.channel_format = 2;
    file.known_frames = header[2] ? 0 : source.frames;
    file.sample_rate = 44100.0;
    file.lock = lock;
    file.unlock = lock;
    auto voice = seeded(header[4]);
    const auto channels = (header[3] & 0x100) ? header[3] & 0xff : header[3];
    const auto status = configure_program_voice(voice, result.program->mappings.front(), file, channels);
    if (!write(status) || !snapshot(voice)) return false;
    if (status != VoiceLoopStatus::Ready || header[6] < 0) return true;

    std::vector<float> audio(header[6] + 16, 0.03125f);
    ElastikOriginalSampleHandle handle{&file, nullptr, true};
    ElastikOriginalReadRange range{-1, -1};
    int next = -1;
    const auto count = elastik_original_read_voice_chunk(&voice.chunk, audio.data() + 8, header[5],
                         voice.cursor, header[6], &next, &range, elastik_original_sample_provider, &handle);
    return write(count) && write(next) && write(range.start) && write(range.count) &&
        write(voice.chunk.last_direction) && ramps(voice.chunk) &&
        write(source.calls) && write(source.channel) && write(source.first) && write(source.count) &&
        std::fwrite(audio.data(), sizeof(float), audio.size(), stdout) == audio.size();
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
