#include "OriginalProgramState.h"
#include "OriginalScannedNumber.h"

#include <cstring>
#include <limits>
#include <utility>

namespace elastik_state {
namespace {

template <class T>
const T* value_at(const Archive& archive, Reference ref) noexcept {
    const auto* value = archive.get(ref);
    return value ? std::get_if<T>(&value->value) : nullptr;
}

bool has_class(const Archive& archive, const ModelRecord& record, std::u16string_view expected) noexcept {
    const auto* name = value_at<String>(archive, record.class_name);
    return name && name->text == expected;
}

int32_t signed_number(uint32_t bits) noexcept {
    if (bits <= static_cast<uint32_t>(std::numeric_limits<int32_t>::max())) return static_cast<int32_t>(bits);
    return static_cast<int32_t>(static_cast<int64_t>(bits) - (int64_t{1} << 32));
}

struct InvalidField {
    ProgramError error;
    Reference object;
};

class ProgramReader {
public:
    explicit ProgramReader(ProgramState& result) : result_(result) {
        for (const auto& record : result_.keyed.records()) records_.emplace(record.dictionary, &record);
    }

    void read() {
        const auto& root = result_.root;
        if (!has_class(result_.values, root, u"ETProgram")) {
            throw InvalidField{ProgramError::RootClass, root.dictionary};
        }

        const auto formatted = text(root, u"formattedTempo", ProgramError::InvalidProgramField);
        result_.tempo = formatted ? elastik_number::number_real(value_at<String>(result_.values, formatted)->text) : 120.0;
        result_.autoselect = boolean(root, u"autoselect", true, ProgramError::InvalidProgramField);
        result_.automap_mode = integer(root, u"automapMode", 0, ProgramError::InvalidProgramField);
        result_.algorithm = integer(root, u"algorithm", 0, ProgramError::InvalidProgramField);
        const auto sync = integer(root, u"syncUserTempoToFileTempo", 1, ProgramError::InvalidProgramField);
        // The legacy property uses an int code but the program reads one byte.
        result_.sync_user_tempo_to_file_tempo = static_cast<uint8_t>(sync) != 0;

        const auto mappings = list(root, u"keyMappings", ProgramError::InvalidMappingList);
        if (mappings) {
            result_.mappings.reserve(mappings->size());
            for (const auto& item : *mappings) add_mapping(item);
        } else {
            // ETProgram creates the notes, then its post-decode clears
            // the user-key flag on the empty mappings (0x14b946).
            for (int32_t note = 36; note <= 103; ++note) {
                result_.mappings.push_back({0, note, false, 0, 0, 0});
            }
        }

        const auto parameters = list(root, u"automationParameters", ProgramError::InvalidAutomationList);
        if (parameters) {
            result_.automation_parameters.reserve(parameters->size());
            for (const auto& item : *parameters) {
                const auto& parameter = model(item, u"ETAutomationParameter", ProgramError::InvalidAutomationParameter);
                result_.automation_parameters.push_back(parameter.dictionary);
            }
        }
        // Original ETProgram post-decode (0x160ba8) fills any missing slots.
        if (result_.automation_parameters.size() < 8) result_.automation_parameters.resize(8, 0);
    }

private:
    const ModelRecord& model(KeyedValue value, std::u16string_view name, ProgramError error) const {
        const auto found = records_.find(value.reference);
        if (value.kind != KeyedValueKind::Model || found == records_.end() ||
            !has_class(result_.values, *found->second, name)) {
            throw InvalidField{error, value.reference ? value.reference : result_.root.dictionary};
        }
        return *found->second;
    }

    std::optional<std::vector<KeyedValue>> list(const ModelRecord& record, std::u16string_view name,
                                                ProgramError error) const {
        const auto result = result_.keyed.field(result_.values, record, name);
        if (result.kind == KeyedValueKind::Absent) return std::nullopt;
        const auto& node = model(result, u"GNList", error);
        auto items = result_.keyed.list_items(result_.values, node);
        if (!items) throw InvalidField{error, node.dictionary};
        return items;
    }

    Reference text(const ModelRecord& record, std::u16string_view name, ProgramError error) const {
        const auto value = result_.keyed.field(result_.values, record, name);
        if (value.kind == KeyedValueKind::Absent) return 0;
        if (value.kind != KeyedValueKind::Inline ||
            (value.reference && !value_at<String>(result_.values, value.reference))) {
            throw InvalidField{error, record.dictionary};
        }
        return value.reference;
    }

    uint32_t number_bits(const ModelRecord& record, std::u16string_view name, char kind,
                         uint32_t fallback, ProgramError error) const {
        const auto value = result_.keyed.field(result_.values, record, name);
        if (value.kind == KeyedValueKind::Absent) return fallback;
        const auto* number = value_at<Number>(result_.values, value.reference);
        if (value.kind != KeyedValueKind::Inline || !number || !number->payload_present || number->kind != kind) {
            throw InvalidField{error, record.dictionary};
        }
        return static_cast<uint32_t>(number->bits);
    }

    int32_t integer(const ModelRecord& record, std::u16string_view name, int32_t fallback, ProgramError error) const {
        return signed_number(number_bits(record, name, 'i', static_cast<uint32_t>(fallback), error));
    }

    float floating(const ModelRecord& record, std::u16string_view name, float fallback, ProgramError error) const {
        uint32_t fallback_bits;
        std::memcpy(&fallback_bits, &fallback, sizeof(fallback_bits));
        const auto bits = number_bits(record, name, 'f', fallback_bits, error);
        float value;
        std::memcpy(&value, &bits, sizeof(value));
        return value;
    }

    bool boolean(const ModelRecord& record, std::u16string_view name, bool fallback, ProgramError error) const {
        return number_bits(record, name, 'b', fallback, error) != 0;
    }

    void add_mapping(KeyedValue item) {
        const auto& mapping = model(item, u"ETKeyMapping", ProgramError::InvalidMapping);
        constexpr auto error = ProgramError::InvalidMappingField;
        const auto owner = result_.keyed.field(result_.values, mapping, u"program");
        Reference program = 0;
        if (owner.kind != KeyedValueKind::Absent && owner.kind != KeyedValueKind::UnresolvedModel) {
            program = model(owner, u"ETProgram", error).dictionary;
        }
        result_.mappings.push_back({
            mapping.dictionary, integer(mapping, u"midiNote", 0, error), boolean(mapping, u"isUserKey", false, error),
            text(mapping, u"soundFilePath", error), text(mapping, u"soundBankIdentifier", error), program,
            {floating(mapping, u"startDegree", 0.0f, error), floating(mapping, u"stopDegree", 0.0f, error),
             integer(mapping, u"direction", 0, error), integer(mapping, u"loopMode", 1, error)},
            {floating(mapping, u"volume", 0.7f, error), floating(mapping, u"panorama", 0.5f, error),
             integer(mapping, u"firstOutputChannelIndex", 0, error), boolean(mapping, u"filterOn", false, error),
             floating(mapping, u"envelopeAttack", 0.0f, error), floating(mapping, u"envelopeRelease", 0.0f, error)},
            {floating(mapping, u"filterCutOff", 0.0f, error), floating(mapping, u"filterResonance", 0.0f, error),
             integer(mapping, u"filterQ", 0, error), integer(mapping, u"filterType", 0, error),
             floating(mapping, u"dirt", 0.05f, error), floating(mapping, u"resonanceDirt", 0.1f, error),
             floating(mapping, u"limiterKnee", 0.5f, error)}
        });
    }

    ProgramState& result_;
    std::map<Reference, const ModelRecord*> records_;
};

} // namespace

ProgramStateResult decode_program_state(std::string_view bytes) {
    auto archive = decode(bytes);
    if (!archive.archive) {
        return {std::nullopt, ProgramError::Archive, archive.object, archive.error, KeyedError::None, archive.offset};
    }

    auto keyed = index_keyed_state(*archive.archive);
    if (!keyed.state) {
        return {std::nullopt, ProgramError::Keyed, keyed.object, Error::None, keyed.error};
    }
    const auto root = keyed.state->records().front();
    ProgramState state{std::move(*archive.archive), std::move(*keyed.state), root, 0.0, false, 0, 0, false, {}, {}};
    try {
        ProgramReader(state).read();
    } catch (const InvalidField& error) {
        return {std::nullopt, error.error, error.object};
    }
    return {std::move(state)};
}

ProgramStateResult decode_class_info(const ClassInfo& info) {
    if (info.version != 0) return {std::nullopt, ProgramError::ClassInfoVersion};
    // aumu / ELSK / UBER, as stored in the original CFNumber fields.
    if (info.type != 0x61756d75 || info.subtype != 0x454c534b || info.manufacturer != 0x55424552) {
        return {std::nullopt, ProgramError::ClassInfoIdentity};
    }
    return decode_program_state(info.data);
}

} // namespace elastik_state
