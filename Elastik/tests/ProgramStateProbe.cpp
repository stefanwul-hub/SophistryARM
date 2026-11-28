#include "../src/OriginalProgramState.h"

#include <cstdio>

namespace {

using namespace elastik_state;

template <class T>
bool write(T value) {
    return std::fwrite(&value, sizeof(value), 1, stdout) == 1;
}

bool run(const uint32_t* header) {
    std::string raw(header[0], '\0');
    if (std::fread(raw.data(), 1, raw.size(), stdin) != raw.size()) return false;
    const auto decoded = header[1]
        ? decode_class_info({static_cast<int32_t>(header[2]), header[3], header[4], header[5], raw})
        : decode_program_state(raw);
    if (!write(decoded.error) || !write(decoded.object) || !write(decoded.archive_error) ||
        !write(decoded.keyed_error) || !write(static_cast<uint32_t>(decoded.archive_offset))) return false;
    if (!decoded.program) return true;

    const auto& state = *decoded.program;
    if (!write(state.root.id) || !write(state.root.dictionary) || !write(state.tempo) ||
        !write(static_cast<uint32_t>(state.autoselect)) || !write(state.automap_mode) || !write(state.algorithm) ||
        !write(static_cast<uint32_t>(state.sync_user_tempo_to_file_tempo)) ||
        !write(static_cast<uint32_t>(state.mappings.size()))) return false;
    for (const auto& entry : state.mappings) {
        if (!write(entry.record) || !write(entry.midi_note) || !write(static_cast<uint32_t>(entry.user_key)) ||
            !write(entry.sample_path) || !write(entry.bank_identifier) || !write(entry.program)) return false;
    }

    if (!write(static_cast<uint32_t>(state.automation_parameters.size()))) return false;
    for (auto ref : state.automation_parameters) {
        if (!write(ref)) return false;
    }

    return true;
}

} // namespace

int main() {
    for (;;) {
        uint32_t header[6];
        const auto read = std::fread(header, 1, sizeof(header), stdin);
        if (!read && std::feof(stdin)) return 0;
        if (read != sizeof(header) || !run(header) || std::fflush(stdout)) return 2;
    }
}
