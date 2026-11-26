#pragma once
#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#include <CommonCrypto/CommonDigest.h>
#include <sys/stat.h>
#include "LegacySamplePaths.h"
#include <array>

namespace cronox::samples {
inline NSString* text(const std::string& value){
  NSString* s=[[NSString alloc] initWithBytes:value.data() length:value.size() encoding:NSUTF8StringEncoding];
  return s?:[[NSString alloc] initWithBytes:value.data() length:value.size() encoding:NSMacOSRomanStringEncoding];
}
inline NSString* digest(NSData* data){
  if(!data||data.length>512ull*1024*1024)throw std::runtime_error("Cannot read a sample for the preflight content check");
  unsigned char bytes[CC_SHA256_DIGEST_LENGTH];CC_SHA256(data.bytes,CC_LONG(data.length),bytes);
  NSMutableString* result=[NSMutableString string];for(unsigned char c:bytes)[result appendFormat:@"%02x",c];return result;
}
inline NSData* contents(const fs::path& path){return [NSData dataWithContentsOfFile:text(path.string()) options:NSDataReadingMappedIfSafe error:nil];}
// Read only the existing sample-folder grant. No licence/preferences are
// written, and bookmark bytes or full paths are never copied to reports.
struct BankGrant {
  NSString* __strong root=nil;
  NSURL* __strong url=nil;
  bool active=false;
  BankGrant(){
    CFPropertyListRef path=CFPreferencesCopyValue(CFSTR("CronoX3ARMSampleRoot"),CFSTR("com.linplug.CronoX3.ARMTest"),kCFPreferencesCurrentUser,kCFPreferencesAnyHost);
    if(path){if(CFGetTypeID(path)==CFStringGetTypeID())root=[(__bridge NSString*)path copy];CFRelease(path);}
    CFPropertyListRef value=CFPreferencesCopyValue(CFSTR("CronoX3ARMSampleBookmark"),CFSTR("com.linplug.CronoX3.ARMTest"),kCFPreferencesCurrentUser,kCFPreferencesAnyHost);
    if(value){if(CFGetTypeID(value)==CFDataGetTypeID())url=[NSURL URLByResolvingBookmarkData:(__bridge NSData*)value options:NSURLBookmarkResolutionWithSecurityScope|NSURLBookmarkResolutionWithoutUI relativeToURL:nil bookmarkDataIsStale:nil error:nil];CFRelease(value);}
    if(url&&root.length&&[url.URLByResolvingSymlinksInPath.path isEqualToString:root.stringByResolvingSymlinksInPath])active=[url startAccessingSecurityScopedResource];
    else url=nil;
  }
  ~BankGrant(){if(active)[url stopAccessingSecurityScopedResource];}
};
inline void prepareAliases(AudioUnit unit,NSData* bank,NSDictionary* engine,NSBundle* bundle,NSString* directory,BankGrant& grant,NSMutableDictionary* report){
  if(!directory.length||!directory.isAbsolutePath)throw std::runtime_error("Expected a private absolute sample-alias directory");
  NSMutableDictionary* info=[NSMutableDictionary dictionary];report[@"sample_paths"]=info;
  std::vector<fs::path> roots;if(grant.root.length)roots.emplace_back(grant.root.fileSystemRepresentation);
  if(bundle.resourcePath.length){roots.emplace_back([[bundle.resourcePath stringByAppendingPathComponent:@"Samples"] fileSystemRepresentation]);roots.emplace_back([[bundle.resourcePath stringByAppendingPathComponent:@"Presets"] fileSystemRepresentation]);}
  AssetIndex index(roots);info[@"readable_roots"]=@(index.roots());info[@"indexed_sample_names"]=@(index.names());
  std::set<std::string> opened;NSMutableArray* failed=[NSMutableArray array];
  for(NSDictionary* asset in engine[@"asset_open_results"]){
    NSString* name=asset[@"name"];if(![name isKindOfClass:NSString.class])continue;
    if([asset[@"opened"] boolValue])opened.insert(lower(name.UTF8String));else [failed addObject:name];
  }
  info[@"arm_missing_samples"]=failed;
  if(failed.count)throw std::runtime_error("ARM reported missing samples; correct the sound-bank location before comparing CPU");
  auto references=framedPaths(static_cast<const unsigned char*>(bank.bytes),bank.length);
  // Known sample-file string tags from the original parameter schema. Never
  // enumerate private registration fields (notably tag766).
  for(unsigned tag:samplePathTags){std::array<char,4096> data{};UInt32 size=data.size();
    if(AudioUnitGetProperty(unit,0x53705478,kAudioUnitScope_Global,tag,data.data(),&size))throw std::runtime_error("Cannot read an original sample-file string");
    std::string value(data.data(),strnlen(data.data(),data.size()));if(!value.empty())references.insert(value);
  }
  auto plan=planAliases(references,opened,index);NSMutableArray* missing=[NSMutableArray array];for(const auto& name:plan.unresolved)[missing addObject:text(name)];
  info[@"unresolved_active_samples"]=missing;info[@"inactive_references_ignored"]=@(plan.inactiveReferences);info[@"legacy_links"]=@(plan.aliases.size());
  if(missing.count)throw std::runtime_error("Cannot prepare all active sample paths for Intel; see unresolved_active_samples");
  fs::path root(directory.fileSystemRepresentation);createAliases(root,plan);
  NSMutableArray* entries=[NSMutableArray array];NSMutableArray* samples=[NSMutableArray array];
  std::map<fs::path,NSString*> hashes;
  for(const auto& alias:plan.aliases){
    auto it=hashes.find(alias.target);if(it==hashes.end())it=hashes.emplace(alias.target,digest(contents(alias.target))).first;
    if(![digest(contents(root/alias.relative)) isEqualToString:it->second])throw std::runtime_error("Temporary sample link content differs from the bank file");
    [entries addObject:@{@"relative":text(alias.relative.generic_string()),@"sha256":it->second}];
  }
  for(const auto& pair:hashes)[samples addObject:@{@"name":text(pair.first.filename().string()),@"sha256":pair.second}];
  NSDictionary* manifest=@{@"version":@1,@"input_bank_sha256":digest(bank),@"entries":entries};
  NSData* data=[NSJSONSerialization dataWithJSONObject:manifest options:NSJSONWritingSortedKeys error:nil];
  NSString* file=[directory stringByAppendingPathComponent:@"alias-manifest.json"];
  if(!data||![data writeToFile:file options:NSDataWritingAtomic error:nil]||chmod(file.fileSystemRepresentation,0600))throw std::runtime_error("Cannot save the private alias manifest");
  info[@"samples"]=samples;info[@"opened_sample_names"]=@(opened.size());info[@"asset_manifest_sha256"]=digest(data);
  info[@"au_bank_bytes_changed"]=@NO;info[@"preset_or_component_files_changed"]=@NO;
}
inline NSString* verifyAliases(NSString* directory,NSData* bank){
  if(!directory.length||!directory.isAbsolutePath)throw std::runtime_error("Expected the prepared private sample-alias directory");
  NSData* data=[NSData dataWithContentsOfFile:[directory stringByAppendingPathComponent:@"alias-manifest.json"]];
  id manifest=data?[NSJSONSerialization JSONObjectWithData:data options:0 error:nil]:nil;
  if(![manifest isKindOfClass:NSDictionary.class]||[manifest[@"version"] intValue]!=1||![manifest[@"input_bank_sha256"] isEqualToString:digest(bank)])throw std::runtime_error("Private alias manifest does not match the shared AU bank");
  fs::path root(directory.fileSystemRepresentation);
  for(NSDictionary* item in manifest[@"entries"]){
    NSString* relative=item[@"relative"];if(![relative isKindOfClass:NSString.class])throw std::runtime_error("Invalid private sample alias");
    auto path=root/safeAlias(relative.UTF8String);
    if(![digest(contents(path)) isEqualToString:item[@"sha256"]])throw std::runtime_error("A sample link changed after preparation; CPU comparison refused");
  }return digest(data);
}
} // namespace cronox::samples
