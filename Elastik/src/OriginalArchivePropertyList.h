#pragma once

#include "OriginalArchiveLookup.h"
#include "OriginalPropertyList.h"

#include <optional>

struct ElastikArchivePropertyList {
    ElastikArchiveStatus archive_status;
    std::optional<ElastikPropertyList> document;
};

// Compose an existing read-only GNFA member path with the plist parser.
// A missing file returns no document and ElastikArchiveOk. Read failures
// return the archive status. Allocations may throw.
ElastikArchivePropertyList elastik_original_archive_plist(
    ElastikOriginalArchivePath*, const ElastikOriginalArchiveFactory*);
