#include "OriginalSoundbankArchive.h"
#include "OriginalSoundbankInternal.h"

#include <memory>

namespace {

int open_readonly(const void* context, void* archive, void* source) noexcept {
    const auto& reader = *static_cast<const ElastikOriginalSoundbankReadOnly*>(context);
    auto* container = reader.container(reader.context, archive);
    return elastik_original_archive_open_read(container, source, reader.opening);
}

void read_readonly(const void* context, ElastikOriginalSoundbank* bank,
                   const ElastikOriginalSoundbankPlatform* platform, void* source) {
    using elastik_soundbank_detail::apply_metadata;
    using elastik_soundbank_detail::path_diagnostic;
    const auto& reader = *static_cast<const ElastikOriginalSoundbankReadOnly*>(context);
    auto* container = reader.container(reader.context, bank->archive);
    void* name = reader.path_string(reader.context, "/Info.plist");
    if (!name) {
        path_diagnostic(platform, 1, source);
        return;
    }

    ElastikArchiveStatus status;
    auto* member = elastik_original_archive_path_for_container(container, name, reader.opening, &status);
    if (status != ElastikArchiveOk) {
        path_diagnostic(platform, 2, source);
        return;
    }
    auto result = elastik_original_archive_plist(member, reader.factory);
    if (result.archive_status != ElastikArchiveOk) {
        path_diagnostic(platform, 2, source);
        return;
    }
    if (!result.document) {
        path_diagnostic(platform, 1, source);
        return;
    }
    if (result.document->status != ElastikPropertyListStatus::Parsed) {
        path_diagnostic(platform, 2, source);
        return;
    }

    auto release = [platform](void* document) noexcept {
        platform->reference(platform->context, 2, document);
    };
    std::unique_ptr<void, decltype(release)> document(
        reader.make_document(reader.context, std::move(result.document->root)), release);
    if (document) apply_metadata(bank, platform, document.get());
    else path_diagnostic(platform, 2, source);
}

} // namespace

void* elastik_original_bank_archive_readonly(
    ElastikOriginalSoundbank* bank, const ElastikOriginalSoundbankPlatform* platform,
    const ElastikOriginalSoundbankReadOnly* reader) {
    return elastik_soundbank_detail::load(bank, platform, {reader, open_readonly, read_readonly});
}
