#pragma once

#include "OriginalKeyedState.h"
#include "OriginalProgramVoiceFilter.h"

namespace elastik_state {

struct ProgramLoopSettings {
    float start_degree = 0.0f;
    float stop_degree = 0.0f;
    int32_t direction = 0;
    int32_t mode = 1;
};

struct ProgramMixSettings {
    float volume = 0.7f;
    float panorama = 0.5f;
    int32_t first_output_channel = 0;
    bool filter_on = false;
    float envelope_attack = 0.0f;
    float envelope_release = 0.0f;
};

struct ProgramMapping {
    Reference record;
    int32_t midi_note;
    bool user_key;
    Reference sample_path;
    Reference bank_identifier;
    Reference program;
    ProgramLoopSettings loop{};
    ProgramMixSettings mix{};
    ProgramFilterSettings filter{};
};

struct ProgramState {
    Archive values;
    KeyedState keyed;
    ModelRecord root;
    double tempo;
    bool autoselect;
    int32_t automap_mode;
    int32_t algorithm;
    bool sync_user_tempo_to_file_tempo;
    std::vector<ProgramMapping> mappings;
    // References preserve automation parameters in archive order. Zero
    // denotes an original default parameter with a one-based slot number.
    std::vector<Reference> automation_parameters;
};

enum class ProgramError : uint8_t {
    None, ClassInfoVersion, ClassInfoIdentity, Archive, Keyed, RootClass,
    InvalidProgramField, InvalidMappingList, InvalidMapping, InvalidMappingField,
    InvalidAutomationList, InvalidAutomationParameter
};

struct ProgramStateResult {
    std::optional<ProgramState> program;
    ProgramError error = ProgramError::None;
    Reference object = 0;
    Error archive_error = Error::None;
    KeyedError keyed_error = KeyedError::None;
    size_t archive_offset = 0;
};

struct ClassInfo {
    int32_t version;
    uint32_t type;
    uint32_t subtype;
    uint32_t manufacturer;
    std::string_view data;
};

// Decode the GNArchiver payload of the original AU writer into an owned
// program and its mapping order. Bank checks and sample reads are runtime
// steps. The returned graph also exposes properties beyond this projection.
ProgramStateResult decode_program_state(std::string_view);
ProgramStateResult decode_class_info(const ClassInfo&);

} // namespace elastik_state
