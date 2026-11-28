#include "../src/OriginalProgramVoice.h"

#include <cstdio>

namespace {
using namespace elastik_state;

bool read_pcm(void*, float* const* output, int first, int count) {
    const int channel = output[0] ? 0 : 1;
    for (int i = 0; i < count; ++i) {
        const auto index = static_cast<uint32_t>(first + i);
        const int value = static_cast<int>((index * 73u + channel * 1009u) % 32768u) - 16384;
        output[channel][i] = static_cast<float>(value) / 32768.0f;
    }
    return true;
}

void lock(void*) {}

template <class T>
bool read(T& value) { return std::fread(&value, sizeof(value), 1, stdin) == 1; }

template <class T>
bool write(T value) { return std::fwrite(&value, sizeof(value), 1, stdout) == 1; }

bool run(const int* header) {
    std::string raw(header[0], '\0');
    if (std::fread(raw.data(), 1, raw.size(), stdin) != raw.size()) return false;
    auto archive = decode_program_state(raw);
    if (!archive.program) return false;
    const auto* saved = program_mapping_for_note(*archive.program, 36);
    if (!saved) return false;
    auto mapping = *saved;

    const ElastikOriginalSampleReader reader{nullptr, nullptr, read_pcm};
    ElastikOriginalSampleFile file{};
    file.known_frames = header[1];
    file.channel_format = 2;
    file.reader = &reader;
    file.lock = file.unlock = lock;
    ElastikOriginalSampleHandle handle{&file, nullptr, true};

    ProgramVoicePlayback voice{};
    ProgramVoiceFilterContext context{static_cast<double>(header[3])};
    if (!trigger_program_voice(voice, mapping, file, 2, 36, 95, 7)) return false;
    for (int block = 0; block < header[2]; ++block) {
        int frames, event;
        if (!read(frames) || !read(event)) return false;
        if (event == 1) mapping.mix.filter_on = false;
        if (event == 2) {
            auto& filter = mapping.filter;
            mapping.mix.filter_on = true;
            if (!read(filter.q) || !read(filter.type) || !read(filter.cutoff) || !read(filter.resonance) ||
                !read(filter.dirt) || !read(filter.resonance_dirt) || !read(filter.limiter_knee)) return false;
        }
        if (event == 3 && !trigger_program_voice(voice, mapping, file, 2, 36, 95, 7)) return false;
        if (event == 4 && !release_program_voice(voice, mapping, file, 2, 39, 0)) return false;

        std::vector<float> left(frames + 8, 0.125f), right = left;
        float* buffers[] = {left.data() + 4, right.data() + 4};
        const auto result = render_program_voice(voice, mapping, handle, buffers, 2, frames, &context);
        if (!write(result.status) || !write(context.noise) || !write(voice.filter.previous_type)) return false;
        for (const auto* channel : {&left, &right}) {
            if (std::fwrite(channel->data(), sizeof(float), channel->size(), stdout) != channel->size()) return false;
        }
    }
    return true;
}
} // namespace

int main() {
    for (;;) {
        int header[4];
        const auto count = std::fread(header, sizeof(int), 4, stdin);
        if (!count && std::feof(stdin)) return 0;
        if (count != 4 || !run(header) || std::fflush(stdout)) return 2;
    }
}
