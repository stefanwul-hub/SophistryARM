#include "OriginalProgramSamples.h"

#include "OriginalSampleFile.h"

#include <utility>

namespace elastik_state {
namespace {

std::optional<std::u16string_view> text_at(const Archive& archive, Reference ref) noexcept {
    const auto* object = archive.get(ref);
    const auto* string = object ? std::get_if<String>(&object->value) : nullptr;
    if (!string) return std::nullopt;
    return string->text;
}

} // namespace

SampleLookup ProgramSampleResolver::open(std::u16string_view key, void* path) {
    auto sample = platform_.create_sample(platform_.context);
    if (!sample || !sample->file) {
        return {SampleLookupStatus::SampleOpenFailed, {}, ElastikArchiveOk, ElastikFilePlatformError};
    }
    const auto status = elastik_original_open_sample_file(sample.get(), platform_.files, path);
    if (status != ElastikFileOk) {
        return {SampleLookupStatus::SampleOpenFailed, {}, ElastikArchiveOk, status};
    }
    cache_.emplace(std::u16string(key), sample);
    return {SampleLookupStatus::Opened, std::move(sample)};
}

SampleLookup ProgramSampleResolver::resolve(std::optional<std::u16string_view> path,
                                            std::optional<std::u16string_view> bank_identifier) {
    if (!path) return {SampleLookupStatus::NoPath, {}};
    const auto cached = cache_.find(*path);
    if (cached != cache_.end()) return {SampleLookupStatus::Cached, cached->second};

    auto* context = platform_.context;
    auto* system = platform_.system_path(context, *path);
    if (system && platform_.is_system_file(context, system)) return open(*path, system);
    if (!bank_identifier) return {SampleLookupStatus::NoBankIdentifier, {}};
    auto* bank = platform_.find_bank(context, *bank_identifier);
    if (!bank) return {SampleLookupStatus::BankUnavailable, {}};
    auto* archive = platform_.bank_archive(context, bank);
    if (!archive) return {SampleLookupStatus::ArchiveUnavailable, {}};
    auto* name = platform_.archive_string(context, *path);
    if (!name) return {SampleLookupStatus::ArchivePathFailed, {}, ElastikArchiveAssertion};

    ElastikArchiveStatus status;
    auto* member = elastik_original_archive_path_for_container(archive, name, platform_.archive_paths, &status);
    if (!member || status != ElastikArchiveOk) {
        return {SampleLookupStatus::ArchivePathFailed, {}, status};
    }
    return open(*path, member);
}

SampleLookup ProgramSampleResolver::resolve_mapping(const Archive& values, const ProgramMapping& mapping) {
    const auto path = text_at(values, mapping.sample_path);
    const auto bank = text_at(values, mapping.bank_identifier);
    if (!path) return {SampleLookupStatus::NoPath, {}};
    if (!mapping.program) return {SampleLookupStatus::NoProgram, {}};
    if (!bank) return {SampleLookupStatus::NoBankIdentifier, {}};
    return resolve(path, bank);
}

std::vector<SampleLookup> ProgramSampleResolver::resolve_program(const ProgramState& program) {
    std::vector<SampleLookup> result;
    result.reserve(program.mappings.size());
    for (const auto& mapping : program.mappings) result.push_back(resolve_mapping(program.values, mapping));
    return result;
}

ProgramSamplePreparation ProgramSampleResolver::prepare_sample(const ProgramState& program, const ProgramMapping& mapping) {
    auto source = resolve_mapping(program.values, mapping);
    const auto* file = source.sample ? source.sample->file : nullptr;
    const double sample_rate = file ? file->sample_rate : 0.0;
    int frames = 0;
    if (file && (file->known_frames || (file->reader && file->reader->frame_count))) {
        frames = elastik_original_file_frame_count(file);
    }
    const auto path = text_at(program.values, mapping.sample_path);
    auto plan = plan_program_sample(mapping, program.tempo, program.algorithm, path.value_or(u""), sample_rate, frames);
    return {std::move(source), plan};
}

} // namespace elastik_state
