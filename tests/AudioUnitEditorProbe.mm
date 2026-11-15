// Exercise the actual published Cocoa factory and snapshot its initial view.
// No installed component or private project is opened by this probe.
#include "../src/au/SophistryProperties.h"
#import <AppKit/AppKit.h>
#import <AudioToolbox/AUCocoaUIView.h>
#import <AudioToolbox/AudioToolbox.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <memory>
#include <mutex>
#include <vector>

struct RemoteCompletion {
  std::mutex mutex;
  bool done = false, abandoned = false;
  AudioComponentInstance instance = nullptr;
  OSStatus status = 0;
};

static void put16(std::ofstream &out, UInt32 v) {
  char b[] = {char(v), char(v >> 8)};
  out.write(b, 2);
}
static void put32(std::ofstream &out, UInt32 v) {
  char b[] = {char(v), char(v >> 8), char(v >> 16), char(v >> 24)};
  out.write(b, 4);
}
static double renderAudio(AudioUnit unit, NSString *path, UInt32 &completed,
                          OSStatus &result) {
  constexpr UInt32 total = 132300;
  float left[512]{}, right[512]{};
  struct {
    UInt32 count;
    AudioBuffer buffers[2];
  } storage{};
  auto *abl = reinterpret_cast<AudioBufferList *>(&storage);
  abl->mNumberBuffers = 2;
  std::vector<float> pcm(total * 2);
  double peak = 0;
  result = MusicDeviceMIDIEvent(unit, 0x90, 60, 100, 0);
  for (UInt32 at = 0; at < total && !result; at += 512) {
    UInt32 n = std::min(UInt32(512), total - at);
    if (at <= 88200 && 88200 < at + n)
      result = MusicDeviceMIDIEvent(unit, 0x80, 60, 0, 88200 - at);
    abl->mBuffers[0] = {1, n * 4, left};
    abl->mBuffers[1] = {1, n * 4, right};
    AudioTimeStamp timestamp{};
    timestamp.mSampleTime = at;
    timestamp.mFlags = kAudioTimeStampSampleTimeValid;
    AudioUnitRenderActionFlags flags = 0;
    if (!result)
      result = AudioUnitRender(unit, &flags, &timestamp, 0, n, abl);
    if (result)
      break;
    for (UInt32 c = 0; c < 2; ++c) {
      const auto *values = static_cast<const float *>(abl->mBuffers[c].mData);
      if (!values || abl->mBuffers[c].mDataByteSize < n * 4) {
        result = -50;
        break;
      }
      for (UInt32 i = 0; i < n; ++i) {
        if (!std::isfinite(values[i])) {
          result = -50;
          break;
        }
        pcm[(at + i) * 2 + c] = values[i];
        peak = std::max(peak, std::fabs(double(values[i])));
      }
    }
    if (!result)
      completed += n;
  }
  if (!result) {
    std::ofstream out(path.fileSystemRepresentation, std::ios::binary);
    out.write("RIFF", 4);
    put32(out, 36 + total * 8);
    out.write("WAVEfmt ", 8);
    put32(out, 16);
    put16(out, 3);
    put16(out, 2);
    put32(out, 44100);
    put32(out, 44100 * 8);
    put16(out, 8);
    put16(out, 32);
    out.write("data", 4);
    put32(out, total * 8);
    out.write(reinterpret_cast<const char *>(pcm.data()), pcm.size() * 4);
    if (!out)
      result = -50;
  }
  return peak;
}

@interface NSView (SophistryEditorTesting)
- (BOOL)loadPresetURL:(NSURL *)url;
- (NSDictionary *)sophistryEditorReport;
- (void)selectTab:(NSButton *)sender;
- (void)parameterChanged:(NSControl *)sender;
@end

int main(int argc, const char **argv) {
  @autoreleasepool {
    if (argc != 5 && argc != 6)
      return 2;
    const bool remote = argc == 6 && !strcmp(argv[5], "--remote");
    if (argc == 6 && !remote)
      return 2;
    NSString *bundlePath = [NSString stringWithUTF8String:argv[1]];
    NSString *statePath = [NSString stringWithUTF8String:argv[2]];
    NSString *fxpPath = [NSString stringWithUTF8String:argv[3]];
    NSString *prefix = [NSString stringWithUTF8String:argv[4]];
    AudioUnit unit = nullptr;
    NSString *failure = nil;
    NSDictionary *viewReport = @{};
    BOOL screenshot = NO, unique = NO, aupreset = NO, fxp = NO, controls = NO,
         tabs = NO;
    [NSApplication sharedApplication];
    [NSApp setActivationPolicy:NSApplicationActivationPolicyAccessory];
    NSBundle *bundle = [NSBundle bundleWithPath:bundlePath];
    if (![bundle loadAndReturnError:nil])
      failure = @"Cannot load candidate bundle";
    if (!failure) {
      CFBundleRef cf =
          CFBundleCreate(nullptr, (__bridge CFURLRef)bundle.bundleURL);
      auto factory = reinterpret_cast<AudioComponentFactoryFunction>(
          CFBundleGetFunctionPointerForName(cf, CFSTR("SophistryAUFactory")));
      if (!factory)
        failure = @"Missing component factory";
      else if (remote) {
        AudioComponentDescription desc{0x61756d75, 0x536f7033, 0x4c696e50, 0,
                                       0};
        AudioComponent component = AudioComponentFindNext(nullptr, &desc);
        if (!component)
          failure = @"No installed component for remote view test";
        else {
          auto completion = std::make_shared<RemoteCompletion>();
          AudioComponentInstantiate(
              component, kAudioComponentInstantiation_LoadOutOfProcess,
              ^(AudioComponentInstance instance, OSStatus result) {
                bool abandoned;
                {
                  std::lock_guard<std::mutex> lock(completion->mutex);
                  abandoned = completion->abandoned;
                  if (!abandoned) {
                    completion->instance = instance;
                    completion->status = result;
                    completion->done = true;
                  }
                }
                if (abandoned && instance)
                  AudioComponentInstanceDispose(instance);
              });
          const CFAbsoluteTime deadline = CFAbsoluteTimeGetCurrent() + 30;
          for (;;) {
            {
              std::lock_guard<std::mutex> lock(completion->mutex);
              if (completion->done)
                break;
            }
            if (CFAbsoluteTimeGetCurrent() >= deadline)
              break;
            CFRunLoopRunInMode(kCFRunLoopDefaultMode, 0.05, true);
          }
          {
            std::lock_guard<std::mutex> lock(completion->mutex);
            if (!completion->done) {
              completion->abandoned = true;
              failure = @"Remote component creation exceeded 30 seconds";
            } else if (completion->status || !completion->instance)
              failure = [NSString
                  stringWithFormat:@"Remote component creation failed: %d",
                                   int(completion->status)];
            else
              unit = completion->instance;
          }
        }
      } else {
        AudioComponentDescription desc{0x61756d75, 0x536f7033, 0x4c696e50, 0,
                                       0};
        AudioComponent component = AudioComponentRegister(
            &desc, CFSTR("Sophistry editor test"), 0x30008, factory);
        if (!component || AudioComponentInstanceNew(component, &unit))
          failure = @"Cannot create candidate AU";
      }
      if (cf)
        CFRelease(cf);
    }
    if (!failure) {
      AudioUnitCocoaViewInfo info{};
      UInt32 size = sizeof(info);
      OSStatus s =
          AudioUnitGetProperty(unit, kAudioUnitProperty_CocoaUI,
                               kAudioUnitScope_Global, 0, &info, &size);
      if (s || !info.mCocoaAUViewBundleLocation || !info.mCocoaAUViewClass[0])
        failure = @"Missing Cocoa view property";
      else {
        NSBundle *viewBundle = [NSBundle
            bundleWithURL:(__bridge NSURL *)info.mCocoaAUViewBundleLocation];
        [viewBundle loadAndReturnError:nil];
        Class cls = [viewBundle
            classNamed:(__bridge NSString *)info.mCocoaAUViewClass[0]];
        id<AUCocoaUIBase> maker = cls ? [[cls alloc] init] : nil;
        if (!maker || [maker interfaceVersion] != 0)
          failure = @"Invalid Cocoa factory";
        else {
          NSView *view = [maker uiViewForAudioUnit:unit
                                          withSize:NSMakeSize(762, 477)];
          NSView *second = [maker uiViewForAudioUnit:unit
                                            withSize:NSMakeSize(762, 477)];
          unique = view && second && view != second;
          if (!unique ||
              ![view respondsToSelector:@selector(sophistryEditorReport)])
            failure = @"Cocoa factory did not return unique controllable views";
          else {
            fxp = [view loadPresetURL:[NSURL fileURLWithPath:fxpPath]];
            aupreset = [view loadPresetURL:[NSURL fileURLWithPath:statePath]];

            AudioStreamBasicDescription format{
                44100,
                kAudioFormatLinearPCM,
                kAudioFormatFlagIsFloat | kAudioFormatFlagIsPacked |
                    kAudioFormatFlagIsNonInterleaved,
                4,
                1,
                4,
                2,
                32,
                0};
            UInt32 maximum = 512;
            if (AudioUnitSetProperty(unit, kAudioUnitProperty_StreamFormat,
                                     kAudioUnitScope_Output, 0, &format,
                                     sizeof(format)) ||
                AudioUnitSetProperty(
                    unit, kAudioUnitProperty_MaximumFramesPerSlice,
                    kAudioUnitScope_Global, 0, &maximum, sizeof(maximum)) ||
                AudioUnitInitialize(unit))
              failure = @"Cannot initialize the editor test instance";
            OSStatus rendered = noErr;
            if (!failure)
              peak = renderAudio(unit, [prefix stringByAppendingString:@".wav"],
                                 renderedFrames, rendered);
            tabs = YES;
            for (NSInteger tab = 0; tab < 7; ++tab) {
              NSButton *selector = [NSButton new];
              selector.tag = tab;
              [view selectTab:selector];
              if ([[view sophistryEditorReport][@"visible_parameter_count"]
                      unsignedIntValue] == 0)
                tabs = NO;
            }
            NSButton *main = [NSButton new];
            main.tag = 0;
            [view selectTab:main];
            float before = 0, after = 0;
            if (!AudioUnitGetParameter(unit, 134, kAudioUnitScope_Global, 0,
                                       &before)) {
              NSSlider *slider = [NSSlider new];
              slider.tag = 134;
              slider.minValue = -30.2;
              slider.maxValue = 0;
              slider.floatValue = before < -12 ? -6 : -18;
              [view parameterChanged:slider];
              controls = !AudioUnitGetParameter(
                             unit, 134, kAudioUnitScope_Global, 0, &after) &&
                         fabsf(after - before) > 0.5f;
              slider.floatValue = before;
              [view parameterChanged:slider];
            }
            viewReport = [view sophistryEditorReport];
            if (!fxp || !aupreset || !controls || !tabs || rendered ||
                peak <= 0.00001 || renderedFrames != 132300 ||
                [viewReport[@"parameter_count"] unsignedIntValue] != 522 ||
                [viewReport[@"main_dial_count"] unsignedIntValue] != 15 ||
                ![viewReport[@"background_images_loaded"] boolValue] ||
                [viewReport[@"sprite_images_loaded"] unsignedIntValue] != 15 ||
                ![viewReport[@"status"][@"state_loaded"] boolValue] ||
                ![viewReport[@"status"][@"engine"][@"registration_accepted"]
                    boolValue] ||
                ![viewReport[@"status"][@"wrapper_version"]
                    isEqualToString:@"SophistryARM CP-018"])
              failure = @"Cocoa preset loading or parameter contract failed";
            if (!failure) {
              NSBitmapImageRep *rep =
                  [view bitmapImageRepForCachingDisplayInRect:view.bounds];
              if (rep) {
                [view cacheDisplayInRect:view.bounds toBitmapImageRep:rep];
                NSData *png =
                    [rep representationUsingType:NSBitmapImageFileTypePNG
                                      properties:@{}];
                screenshot =
                    [png writeToFile:[prefix stringByAppendingString:@".png"]
                          atomically:YES];
              }
              if (!screenshot)
                failure = @"Cannot snapshot the native Cocoa view";
            }
          }
        }
      }
      if (info.mCocoaAUViewBundleLocation)
        CFRelease(info.mCocoaAUViewBundleLocation);
      if (info.mCocoaAUViewClass[0])
        CFRelease(info.mCocoaAUViewClass[0]);
    }
    NSDictionary *report = @{
      @"scope" : @"actual native Cocoa view factory; public presets only, no "
                 @"private project",
      @"out_of_process_requested" : @(remote),
      @"state_restored_before_initialize" : @YES,
      @"render_frames" : @(renderedFrames),
      @"render_peak" : @(peak),
      @"passed" : @(!failure),
      @"error" : failure ?: [NSNull null],
      @"unique_views" : @(unique),
      @"seven_tabs_filter_parameters" : @(tabs),
      @"editor_control_changes_original_au_parameter" : @(controls),
      @"fxp_imported" : @(fxp),
      @"aupreset_imported" : @(aupreset),
      @"native_view_snapshot_saved" : @(screenshot),
      @"view" : viewReport
    };
    NSData *json =
        [NSJSONSerialization dataWithJSONObject:report
                                        options:NSJSONWritingPrettyPrinted
                                          error:nil];
    [json writeToFile:[prefix stringByAppendingString:@".json"] atomically:YES];
    if (json)
      fwrite(json.bytes, 1, json.length, stdout);
    if (unit) {
      AudioUnitUninitialize(unit);
      AudioComponentInstanceDispose(unit);
    }
    return failure ? 1 : 0;
  }
}
