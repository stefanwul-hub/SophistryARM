// Exercise the actual component Cocoa factory inside this process.
// Remote host validation uses only public APIs in AudioUnitRemoteHostProbe.mm.
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

static NSDictionary *runtimeStatus(AudioUnit unit, OSStatus &result) {
  std::vector<char> bytes(sophistry::runtimeStatusBytes);
  UInt32 size = UInt32(bytes.size());
  result = AudioUnitGetProperty(unit, sophistry::runtimeStatusProperty,
                                kAudioUnitScope_Global, 0, bytes.data(), &size);
  if (result)
    return @{};
  NSData *data = [NSData dataWithBytes:bytes.data()
                                length:strnlen(bytes.data(), bytes.size())];
  id json = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
  if (![json isKindOfClass:NSDictionary.class]) {
    result = kAudioUnitErr_InvalidPropertyValue;
    return @{};
  }
  return json;
}

#include "AudioUnitProbeAudio.h"

@interface NSView (SophistryEditorTesting)
- (BOOL)loadPresetURL:(NSURL *)url;
- (NSDictionary *)sophistryEditorReport;
- (void)selectTab:(NSButton *)sender;
- (void)parameterChanged:(NSControl *)sender;
@end

int main(int argc, const char **argv) {
  @autoreleasepool {
    if (argc != 5)
      return 2;
    NSString *bundlePath = [NSString stringWithUTF8String:argv[1]];
    NSString *statePath = [NSString stringWithUTF8String:argv[2]];
    NSString *fxpPath = [NSString stringWithUTF8String:argv[3]];
    NSString *prefix = [NSString stringWithUTF8String:argv[4]];
    AudioUnit unit = nullptr;
    NSString *failure = nil;
    NSDictionary *viewReport = @{};
    NSDictionary *renderStatus = @{};
    NSString *advertisedClass = @"";
    NSString *componentViewClass = @"";
    OSStatus runtimePropertyStatus = noErr;
    UInt32 renderedFrames = 0;
    double peak = 0;
    BOOL fxpNamePreserved = NO;
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
      else {
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
      NSDictionary *initial = runtimeStatus(unit, runtimePropertyStatus);
      if (runtimePropertyStatus ||
          ![initial[@"wrapper_version"]
              isEqualToString:
                  [NSString stringWithUTF8String:sophistry::wrapperVersion]])
        failure = [NSString
            stringWithFormat:@"The AU runtime property is unavailable or "
                             @"belongs to a different checkpoint (%d)",
                             int(runtimePropertyStatus)];
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
        advertisedClass = [(__bridge NSString *)info.mCocoaAUViewClass[0] copy];
        Class cls = [viewBundle classNamed:advertisedClass];
        componentViewClass = cls ? NSStringFromClass(cls) : @"";
        id<AUCocoaUIBase> maker = cls ? [[cls alloc] init] : nil;
        if (!maker || [maker interfaceVersion] != 0)
          failure = @"Invalid Cocoa factory";
        else {
          NSView *view = [maker uiViewForAudioUnit:unit
                                          withSize:NSMakeSize(762, 477)];
          NSView *second = [maker uiViewForAudioUnit:unit
                                            withSize:NSMakeSize(762, 477)];
          unique = view && second && view != second;
          if (!unique)
            failure = @"The component's own factory did not return two views";
          else if (![view respondsToSelector:@selector(sophistryEditorReport)])
            failure =
                @"The component view does not implement its test interface";
          else {
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
            renderStatus = runtimeStatus(unit, runtimePropertyStatus);
            // Check import only after the independent before-init render.
            fxp = [view loadPresetURL:[NSURL fileURLWithPath:fxpPath]];
            fxpNamePreserved =
                [[view sophistryEditorReport][@"status"][@"preset_name"]
                    isEqualToString:@"BT_lightgarden_02"];
            aupreset = aupreset &&
                       [view loadPresetURL:[NSURL fileURLWithPath:statePath]];
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
            if (!failure &&
                (!fxp || !fxpNamePreserved || !aupreset || !controls || !tabs ||
                 rendered || runtimePropertyStatus ||
                 [renderStatus[@"notes_received"] unsignedLongLongValue] != 1 ||
                 [renderStatus[@"render_calls"] unsignedLongLongValue] == 0 ||
                 peak <= 0.00001 || renderedFrames != 132300 ||
                 [viewReport[@"parameter_count"] unsignedIntValue] != 522 ||
                 [viewReport[@"main_dial_count"] unsignedIntValue] != 15 ||
                 ![viewReport[@"background_images_loaded"] boolValue] ||
                 [viewReport[@"sprite_images_loaded"] unsignedIntValue] != 15 ||
                 ![viewReport[@"status"][@"state_loaded"] boolValue] ||
                 ![viewReport[@"status"][@"engine"][@"registration_accepted"]
                     boolValue] ||
                 ![viewReport[@"status"][@"preset_name"] length] ||
                 [viewReport[@"status"][@"preset_name"]
                     isEqualToString:@"empty"] ||
                 ![viewReport[@"status"][@"wrapper_version"]
                     isEqualToString:[NSString stringWithUTF8String:
                                                   sophistry::wrapperVersion]]))
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
      @"out_of_process_requested" : @NO,
      @"view_factory_route" : @"published local Cocoa factory",
      @"advertised_cocoa_factory" : advertisedClass,
      @"tested_component_cocoa_factory" : componentViewClass,
      @"host_managed_remote_window_verified" : @NO,
      @"runtime_property_status" : @(runtimePropertyStatus),
      @"state_restored_before_initialize" : @(renderedFrames > 0),
      @"status_immediately_after_render" : renderStatus,
      @"render_frames" : @(renderedFrames),
      @"render_peak" : @(peak),
      @"passed" : @(!failure),
      @"error" : failure ?: [NSNull null],
      @"unique_views" : @(unique),
      @"seven_tabs_filter_parameters" : @(tabs),
      @"editor_control_changes_original_au_parameter" : @(controls),
      @"fxp_imported" : @(fxp),
      @"fxp_header_name_preserved" : @(fxpNamePreserved),
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
