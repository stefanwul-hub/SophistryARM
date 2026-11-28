#pragma once

#include "OriginalArchiveOpen.h"
#include "OriginalFileOpen.h"
#include "OriginalProgramSampleTransform.h"

#include <memory>

namespace elastik_state {

using OpenedSample = std::shared_ptr<ElastikOriginalFileOpenState>;

struct ProgramSamplePlatform {
    void* context;
    void* (*system_path)(void*, std::u16string_view);
    bool (*is_system_file)(void*, void* path);
    // The host catalogue supplies a usable bank under the original access rules.
    void* (*find_bank)(void*, std::u16string_view identifier);
    ElastikOriginalArchiveContainer* (*bank_archive)(void*, void* bank);
    // Return a string valid through path construction and its retain callback.
    void* (*archive_string)(void*, std::u16string_view);
    const ElastikOriginalArchiveOpenPlatform* archive_paths;
    // Create an initialized FileOpenState and own all retained objects
    // until the last copy of the returned sample handle is released.
    OpenedSample (*create_sample)(void*);
    const ElastikOriginalFileOpenPlatform* files;
};

enum class SampleLookupStatus : uint8_t {
    Opened, Cached, NoPath, NoProgram, NoBankIdentifier, BankUnavailable,
    ArchiveUnavailable, ArchivePathFailed, SampleOpenFailed
};

struct SampleLookup {
    SampleLookupStatus status;
    OpenedSample sample;
    ElastikArchiveStatus archive_status = ElastikArchiveOk;
    ElastikOriginalFileStatus file_status = ElastikFileOk;
};

struct ProgramSamplePreparation {
    SampleLookup source;
    ProgramSampleRenderPlan plan;
};

// Resolver for one caller-managed sample session. Use a fresh session when
// changing its bank catalogue. Calls and the bound platform are serialized.
class ProgramSampleResolver {
public:
    explicit ProgramSampleResolver(ProgramSamplePlatform platform) : platform_(platform) {}

    // Original ETProgram path dispatch (0x15f48c). A successful open is
    // cached under the original path key, even for a bank member.
    SampleLookup resolve(std::optional<std::u16string_view> path,
                         std::optional<std::u16string_view> bank_identifier);
    // The sample lookup portion of 0x14bcd4, in the saved mapping order.
    std::vector<SampleLookup> resolve_program(const ProgramState&);
    // Prepare an attached mapping using the program's live tempo and the
    // opened source. A Render plan is passed to the offline processor.
    ProgramSamplePreparation prepare_sample(const ProgramState&, const ProgramMapping&);

private:
    SampleLookup open(std::u16string_view key, void* path);
    SampleLookup resolve_mapping(const Archive&, const ProgramMapping&);

    ProgramSamplePlatform platform_;
    std::map<std::u16string, OpenedSample, std::less<>> cache_;
};

} // namespace elastik_state
