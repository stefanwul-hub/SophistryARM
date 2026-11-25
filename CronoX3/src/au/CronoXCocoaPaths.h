#pragma once
#import <Foundation/Foundation.h>
#include <filesystem>

namespace cronox::cocoa {
// An unset location is optional. NSString throws when asked to convert @""
// with fileSystemRepresentation, so preserve absence before that conversion.
inline std::filesystem::path path(NSString* value) {
  if (!value.length)
    return {};
  return std::filesystem::path(value.fileSystemRepresentation);
}
} // namespace cronox::cocoa
