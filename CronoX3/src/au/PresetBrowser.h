#pragma once
#import <Foundation/Foundation.h>
#include <cstring>

namespace sophistryPresetBrowser {
inline bool supported(NSURL *url) {
  NSString *ext = url.pathExtension.lowercaseString;
  NSNumber *regular = nil;
  return ([ext isEqualToString:@"fxp"] || [ext isEqualToString:@"aupreset"]) &&
         [url getResourceValue:&regular
                        forKey:NSURLIsRegularFileKey
                         error:nil] &&
         regular.boolValue;
}
inline NSString *normalized(NSString *text) {
  NSString *folded =
      [text stringByFoldingWithOptions:NSCaseInsensitiveSearch |
                                       NSDiacriticInsensitiveSearch
                                locale:[NSLocale localeWithLocaleIdentifier:
                                                     @"en_US_POSIX"]];
  return [[folded
      componentsSeparatedByCharactersInSet:NSCharacterSet
                                               .alphanumericCharacterSet
                                               .invertedSet]
      componentsJoinedByString:@""];
}
inline NSArray<NSURL *> *directory(NSURL *folder) {
  NSArray *all = [NSFileManager.defaultManager
        contentsOfDirectoryAtURL:folder
      includingPropertiesForKeys:@[ NSURLIsRegularFileKey ]
                         options:NSDirectoryEnumerationSkipsHiddenFiles
                           error:nil];
  NSMutableArray<NSURL *> *files = [NSMutableArray array];
  for (NSURL *url in all)
    if (supported(url))
      [files addObject:url];
  [files sortUsingComparator:^NSComparisonResult(NSURL *a, NSURL *b) {
    return [a.lastPathComponent localizedStandardCompare:b.lastPathComponent];
  }];
  return files;
}
inline NSURL *adjacent(NSArray<NSURL *> *files, NSURL *current,
                       NSInteger step) {
  if (!files.count || (step != -1 && step != 1))
    return nil;
  NSUInteger index = NSNotFound;
  NSString *path = current.URLByStandardizingPath.path;
  for (NSUInteger i = 0; i < files.count; ++i)
    if ([files[i].URLByStandardizingPath.path isEqualToString:path]) {
      index = i;
      break;
    }
  if (index == NSNotFound)
    return nil;
  const NSInteger next = (NSInteger(index) + step + NSInteger(files.count)) %
                         NSInteger(files.count);
  return files[NSUInteger(next)];
}
inline NSString *label(NSURL *url) {
  if ([url.pathExtension.lowercaseString isEqualToString:@"aupreset"]) {
    NSNumber *size = nil;
    [url getResourceValue:&size forKey:NSURLFileSizeKey error:nil];
    if (size.unsignedLongLongValue > 2 * 1024 * 1024)
      return @"";
    NSData *data = [NSData dataWithContentsOfURL:url];
    id plist = data ? [NSPropertyListSerialization
                          propertyListWithData:data
                                       options:NSPropertyListImmutable
                                        format:nil
                                         error:nil]
                    : nil;
    if (![plist isKindOfClass:NSDictionary.class])
      return @"";
    id value = plist[@"SophistryARMPresetName"] ?: plist[@"name"];
    return [value isKindOfClass:NSString.class] ? value : @"";
  }
  NSFileHandle *file = [NSFileHandle fileHandleForReadingFromURL:url error:nil];
  if (!file)
    return @"";
  NSData *header = nil;
  @try {
    header = [file readDataOfLength:60];
  } @catch (NSException *exception) {
    header = nil;
  }
  [file closeFile];
  if (header.length != 60)
    return @"";
  const unsigned char *bytes = static_cast<const unsigned char *>(header.bytes);
  if (memcmp(bytes, "CcnK", 4) || memcmp(bytes + 8, "FPCh", 4))
    return @"";
  const auto count = strnlen(reinterpret_cast<const char *>(bytes + 28), 28);
  NSString *name = [[NSString alloc] initWithBytes:bytes + 28
                                            length:count
                                          encoding:NSUTF8StringEncoding];
  if (!name)
    name = [[NSString alloc] initWithBytes:bytes + 28
                                    length:count
                                  encoding:NSMacOSRomanStringEncoding];
  return name ?: @"";
}
// A project stores a sound, not necessarily its source file. Use only a unique
// match in the configured library; an ambiguous or missing match opens a
// picker.
inline NSURL *find(NSURL *root, NSString *name) {
  NSString *key = normalized(name);
  if (!root || !key.length)
    return nil;
  NSMutableArray<NSURL *> *exact = [NSMutableArray array],
                          *suffix = [NSMutableArray array];
  NSDirectoryEnumerator *scan = [NSFileManager.defaultManager
                 enumeratorAtURL:root
      includingPropertiesForKeys:@[ NSURLIsRegularFileKey ]
                         options:NSDirectoryEnumerationSkipsHiddenFiles |
                                 NSDirectoryEnumerationSkipsPackageDescendants
                    errorHandler:^BOOL(NSURL *, NSError *) {
                      return YES;
                    }];
  for (NSURL *url in scan) {
    if (!supported(url))
      continue;
    NSString *stem =
        normalized(url.lastPathComponent.stringByDeletingPathExtension);
    if ([key isEqualToString:stem] ||
        [key isEqualToString:normalized(label(url))])
      [exact addObject:url];
    else if (stem.length >= 8 && [key hasSuffix:stem])
      [suffix addObject:url];
  }
  NSArray<NSURL *> *matches = exact.count ? exact : suffix;
  return matches.count == 1 ? matches.firstObject : nil;
}
} // namespace sophistryPresetBrowser
