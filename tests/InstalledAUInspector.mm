// Inspect a fresh registered AU without opening its editor or a DAW project.
#include "../src/au/SophistryProperties.h"
#import <AudioToolbox/AudioToolbox.h>
#import <Foundation/Foundation.h>
#include <cstring>
#include <memory>
#include <mutex>
#include <vector>

struct LocalCompletion {
  std::mutex mutex;
  bool done = false, abandoned = false;
  AudioUnit unit = nullptr;
  OSStatus status = noErr;
};
static OSStatus createLocal(AudioComponent component, AudioUnit &unit) {
  auto pending = std::make_shared<LocalCompletion>();
  AudioComponentInstantiate(
      component, kAudioComponentInstantiation_LoadInProcess,
      ^(AudioComponentInstance instance, OSStatus result) {
        bool abandoned;
        {
          std::lock_guard<std::mutex> lock(pending->mutex);
          abandoned = pending->abandoned;
          if (!abandoned) {
            pending->unit = instance;
            pending->status = result;
            pending->done = true;
          }
        }
        if (abandoned && instance)
          AudioComponentInstanceDispose(instance);
      });
  const auto deadline = CFAbsoluteTimeGetCurrent() + 30;
  for (;;) {
    {
      std::lock_guard<std::mutex> lock(pending->mutex);
      if (pending->done) {
        unit = pending->unit;
        return pending->status;
      }
      if (CFAbsoluteTimeGetCurrent() >= deadline) {
        pending->abandoned = true;
        return kAudioUnitErr_FailedInitialization;
      }
    }
    CFRunLoopRunInMode(kCFRunLoopDefaultMode, 0.05, true);
  }
}

static NSString *legacyString(AudioUnit unit, UInt32 property) {
  CFStringRef value = nullptr;
  UInt32 bytes = sizeof(value);
  if (AudioUnitGetProperty(unit, property, kAudioUnitScope_Global, 0, &value,
                           &bytes) ||
      !value)
    return @"";
  NSString *result = [(__bridge NSString *)value copy];
  CFRelease(value);
  return result;
}

static NSDictionary *parseJSON(NSData *data) {
  id value = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
  return [value isKindOfClass:NSDictionary.class] ? value : @{};
}

int main(int argc, const char **argv) {
  @autoreleasepool {
    if (argc != 2)
      return 2;
    NSString *output = [NSString stringWithUTF8String:argv[1]];
    AudioComponentDescription desc{0x61756d75, 0x536f7033, 0x4c696e50, 0, 0};
    AudioComponent component = AudioComponentFindNext(nullptr, &desc);
    NSUInteger matches = 0;
    for (AudioComponent next = component; next && matches < 16;
         next = AudioComponentFindNext(next, &desc))
      ++matches;
    AudioUnit unit = nullptr;
    OSStatus created = component ? createLocal(component, unit)
                                 : kAudioUnitErr_InvalidProperty;
    NSDictionary *runtime = @{}, *legacy = @{};
    NSString *wrapper = @"";
    UInt32 cocoaBytes = 0;
    Boolean writable = false;
    OSStatus cocoa = kAudioUnitErr_InvalidProperty;
    OSStatus runtimeResult = kAudioUnitErr_InvalidProperty;
    if (!created && unit) {
      cocoa = AudioUnitGetPropertyInfo(unit, kAudioUnitProperty_CocoaUI,
                                       kAudioUnitScope_Global, 0, &cocoaBytes,
                                       &writable);
      std::vector<char> bytes(sophistry::runtimeStatusBytes);
      UInt32 size = UInt32(bytes.size());
      runtimeResult =
          AudioUnitGetProperty(unit, sophistry::runtimeStatusProperty,
                               kAudioUnitScope_Global, 0, bytes.data(), &size);
      if (!runtimeResult) {
        runtime = parseJSON([NSData
            dataWithBytes:bytes.data()
                   length:strnlen(bytes.data(), bytes.size())]);
        id value = runtime[@"wrapper_version"];
        if ([value isKindOfClass:NSString.class])
          wrapper = value;
      } else {
        // The CP016 installer probes used these CF properties in process.
        // They are diagnostic only, never sent to another AU hosting process.
        wrapper = legacyString(unit, 0x53705672);
        NSString *text = legacyString(unit, 0x53704469);
        legacy = parseJSON([text dataUsingEncoding:NSUTF8StringEncoding]);
      }
    }
    NSString *expected =
        [NSString stringWithUTF8String:sophistry::wrapperVersion];
    NSString *system =
        @"/Library/Audio/Plug-Ins/Components/Sophistry.component";
    NSDictionary *info = [NSDictionary
        dictionaryWithContentsOfFile:
            [system stringByAppendingPathComponent:@"Contents/Info.plist"]];
    NSString *user = [NSHomeDirectory()
        stringByAppendingPathComponent:
            @"Library/Audio/Plug-Ins/Components/Sophistry.component"];
    NSDictionary *report = @{
      @"scope" : @"fresh registered AU; no editor, no project read or modified",
      @"inspects_running_logic_or_live_instance" : @NO,
      @"registered_matches" : @(matches),
      @"instance_creation_status" : @(created),
      @"loaded_wrapper_version" : wrapper,
      @"expected_wrapper_version" : expected,
      @"current_checkpoint_loaded" : @([wrapper isEqualToString:expected]),
      @"system_bundle_build" : info[@"CFBundleVersion"] ?: [NSNull null],
      @"user_component_also_present" :
          @([NSFileManager.defaultManager fileExistsAtPath:user]),
      @"cocoa_property_status" : @(cocoa),
      @"cocoa_property_available" : @(cocoa == noErr && cocoaBytes > 0),
      @"runtime_property_status" : @(runtimeResult),
      @"runtime_status" : runtime,
      @"legacy_engine_status" : legacy,
      @"private_preferences_exported" : @NO
    };
    NSData *json =
        [NSJSONSerialization dataWithJSONObject:report
                                        options:NSJSONWritingPrettyPrinted
                                          error:nil];
    BOOL saved = json && [json writeToFile:output atomically:YES];
    if (json)
      fwrite(json.bytes, 1, json.length, stdout);
    if (unit)
      AudioComponentInstanceDispose(unit);
    return created || !saved ? 1 : 0;
  }
}
