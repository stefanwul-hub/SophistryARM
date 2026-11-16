// Validate the OS-hosted AU through public APIs only. In particular, a remote
// AudioUnit handle must never be passed to our local editor test interface.
#include "../src/au/SophistryProperties.h"
#include "AudioUnitProbeAudio.h"
#import <AppKit/AppKit.h>
#import <AudioToolbox/AUCocoaUIView.h>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <string>

struct Creation {
  std::mutex mutex;
  bool done = false, abandoned = false;
  AudioUnit unit = nullptr;
  OSStatus status = noErr;
};
struct ViewRequest {
  std::mutex mutex;
  bool done = false, abandoned = false;
  NSViewController *__strong controller = nil;
};
static void pump(double seconds) {
  const auto until = CFAbsoluteTimeGetCurrent() + seconds;
  while (CFAbsoluteTimeGetCurrent() < until)
    CFRunLoopRunInMode(kCFRunLoopDefaultMode, 0.02, false);
}
static void check(OSStatus status, const char *what) {
  if (status)
    throw std::runtime_error(std::string(what) + " (" + std::to_string(status) +
                             ")");
}

int main(int argc, const char **argv) {
  @autoreleasepool {
    if (argc != 4)
      return 2;
    NSString *statePath = [NSString stringWithUTF8String:argv[1]];
    NSString *contractPath = [NSString stringWithUTF8String:argv[2]];
    NSString *prefix = [NSString stringWithUTF8String:argv[3]];
    NSString *expected =
        [NSString stringWithUTF8String:sophistry::wrapperVersion];
    std::string stage = "instance creation", error;
    AudioUnit unit = nullptr;
    UInt32 remote = 0, completed = 0, parameterCount = 0;
    OSStatus remoteStatus = kAudioUnitErr_InvalidProperty, rendered = noErr;
    OSStatus cocoaStatus = kAudioUnitErr_InvalidProperty;
    OSStatus controllerStatus = kAudioUnitErr_InvalidProperty;
    double peak = 0;
    bool restored = false, initialized = false, parameterChange = false;
    bool remoteQueried = false, cocoaQueried = false, controllerQueried = false,
         renderAttempted = false;
    bool versionMatches = false, stateRoundTrip = false, screenshot = false;
    NSString *reportedVersion = @"", *advertisedClass = @"", *viewRoute = @"";
    NSWindow *window = nil;
    NSView *view = nil;
    NSViewController *controller = nil;
    @try {
      try {
        [NSApplication sharedApplication];
        [NSApp setActivationPolicy:NSApplicationActivationPolicyAccessory];
        [NSApp finishLaunching];
        AudioComponentDescription desc{0x61756d75, 0x536f7033, 0x4c696e50, 0,
                                       0};
        AudioComponent component = AudioComponentFindNext(nullptr, &desc);
        if (!component || AudioComponentFindNext(component, &desc))
          throw std::runtime_error(
              "Expected one registered Sophistry component");
        auto pending = std::make_shared<Creation>();
        AudioComponentInstantiate(
            component, kAudioComponentInstantiation_LoadOutOfProcess,
            ^(AudioComponentInstance instance, OSStatus status) {
              bool abandoned;
              {
                std::lock_guard<std::mutex> lock(pending->mutex);
                abandoned = pending->abandoned;
                if (!abandoned) {
                  pending->unit = instance;
                  pending->status = status;
                  pending->done = true;
                }
              }
              if (abandoned && instance)
                AudioComponentInstanceDispose(instance);
            });
        const auto deadline = CFAbsoluteTimeGetCurrent() + 25;
        for (;;) {
          {
            std::lock_guard<std::mutex> lock(pending->mutex);
            if (pending->done) {
              unit = pending->unit;
              check(pending->status, "Remote instantiation");
              break;
            }
            if (CFAbsoluteTimeGetCurrent() >= deadline) {
              pending->abandoned = true;
              throw std::runtime_error(
                  "Remote instantiation exceeded 25 seconds");
            }
          }
          CFRunLoopRunInMode(kCFRunLoopDefaultMode, 0.02, false);
        }
        if (!unit)
          throw std::runtime_error("Remote instantiation returned no instance");
        UInt32 bytes = sizeof(remote);
        remoteQueried = true;
        remoteStatus =
            AudioUnitGetProperty(unit, kAudioUnitProperty_LoadedOutOfProcess,
                                 kAudioUnitScope_Global, 0, &remote, &bytes);
        check(remoteStatus, "Query actual out-of-process loading");
        if (!remote)
          throw std::runtime_error(
              "The OS did not load this AU out of process");

        stage = "restore preset before initialization";
        NSDictionary *state =
            [NSDictionary dictionaryWithContentsOfFile:statePath];
        if (![state[@"vstdata"] isKindOfClass:NSData.class])
          throw std::runtime_error("Public AU preset contains no vstdata");
        CFPropertyListRef plist = (__bridge CFPropertyListRef)state;
        check(AudioUnitSetProperty(unit, kAudioUnitProperty_ClassInfo,
                                   kAudioUnitScope_Global, 0, &plist,
                                   sizeof(plist)),
              "Restore public AU state");
        restored = true;
        AudioStreamBasicDescription format{44100,
                                           kAudioFormatLinearPCM,
                                           kAudioFormatFlagIsFloat |
                                               kAudioFormatFlagIsPacked |
                                               kAudioFormatFlagIsNonInterleaved,
                                           4,
                                           1,
                                           4,
                                           2,
                                           32,
                                           0};
        UInt32 maximum = 512;
        check(AudioUnitSetProperty(unit, kAudioUnitProperty_StreamFormat,
                                   kAudioUnitScope_Output, 0, &format,
                                   sizeof(format)),
              "Set stereo output");
        check(AudioUnitSetProperty(
                  unit, kAudioUnitProperty_MaximumFramesPerSlice,
                  kAudioUnitScope_Global, 0, &maximum, sizeof(maximum)),
              "Set maximum frames");
        check(AudioUnitInitialize(unit), "Initialize remote AU");
        initialized = true;

        stage = "public parameter list";
        Boolean writable = false;
        bytes = 0;
        check(AudioUnitGetPropertyInfo(unit, kAudioUnitProperty_ParameterList,
                                       kAudioUnitScope_Global, 0, &bytes,
                                       &writable),
              "Query remote parameters");
        parameterCount = bytes / sizeof(UInt32);
        if (parameterCount != 522 || bytes != 522 * sizeof(UInt32))
          throw std::runtime_error("Remote AU did not expose 522 parameters");
        std::vector<UInt32> ids(parameterCount);
        check(AudioUnitGetProperty(unit, kAudioUnitProperty_ParameterList,
                                   kAudioUnitScope_Global, 0, ids.data(),
                                   &bytes),
              "Read remote parameter IDs");
        NSArray *contract = [NSArray arrayWithContentsOfFile:contractPath];
        if (contract.count != parameterCount)
          throw std::runtime_error("Invalid public parameter contract");
        for (NSUInteger i = 0; i < contract.count; ++i)
          if (ids[i] != [contract[i][@"id"] unsignedIntValue])
            throw std::runtime_error(
                "Remote parameter ID differs from original");

        stage = "single view via public host APIs";
        window =
            [[NSWindow alloc] initWithContentRect:NSMakeRect(0, 0, 1120, 477)
                                        styleMask:NSWindowStyleMaskTitled |
                                                  NSWindowStyleMaskClosable
                                          backing:NSBackingStoreBuffered
                                            defer:NO];
        window.releasedWhenClosed = NO;
        window.title = @"Sophistry — validation automatique";
        [window center];
        [window orderFrontRegardless];
        pump(0.1);
        UInt32 cocoaBytes = 0;
        cocoaQueried = true;
        cocoaStatus = AudioUnitGetPropertyInfo(unit, kAudioUnitProperty_CocoaUI,
                                               kAudioUnitScope_Global, 0,
                                               &cocoaBytes, &writable);
        if (!cocoaStatus && cocoaBytes >= sizeof(AudioUnitCocoaViewInfo) &&
            cocoaBytes <= 8192) {
          std::vector<unsigned char> data(cocoaBytes);
          cocoaStatus = AudioUnitGetProperty(unit, kAudioUnitProperty_CocoaUI,
                                             kAudioUnitScope_Global, 0,
                                             data.data(), &cocoaBytes);
          if (!cocoaStatus && cocoaBytes >= sizeof(AudioUnitCocoaViewInfo) &&
              cocoaBytes <= data.size()) {
            auto *info =
                reinterpret_cast<AudioUnitCocoaViewInfo *>(data.data());
            const auto count =
                (cocoaBytes - sizeof(CFURLRef)) / sizeof(CFStringRef);
            if (info->mCocoaAUViewBundleLocation && count &&
                info->mCocoaAUViewClass[0]) {
              advertisedClass =
                  [(__bridge NSString *)info->mCocoaAUViewClass[0] copy];
              NSBundle *bundle =
                  [NSBundle bundleWithURL:(__bridge NSURL *)info->
                                          mCocoaAUViewBundleLocation];
              [bundle loadAndReturnError:nil];
              Class cls = [bundle classNamed:advertisedClass];
              id<NSObject, AUCocoaUIBase> factory =
                  cls ? [[cls alloc] init] : nil;
              if ([factory respondsToSelector:@selector(interfaceVersion)] &&
                  [factory respondsToSelector:@selector(uiViewForAudioUnit:
                                                                  withSize:)] &&
                  [factory interfaceVersion] == 0) {
                // A host requests one OS-managed view, without private
                // selectors.
                view = [factory uiViewForAudioUnit:unit
                                          withSize:NSMakeSize(1120, 477)];
                if (view)
                  viewRoute = @"published Cocoa factory, one host-managed view";
              }
            }
            for (std::size_t i = 0; i < count; ++i)
              if (info->mCocoaAUViewClass[i])
                CFRelease(info->mCocoaAUViewClass[i]);
            if (info->mCocoaAUViewBundleLocation)
              CFRelease(info->mCocoaAUViewBundleLocation);
          }
        }
        if (!view) {
          // Standard host fallback used when the OS provides a view controller.
          using Callback = void (^)(NSViewController *);
          bytes = 0;
          controllerQueried = true;
          controllerStatus = AudioUnitGetPropertyInfo(
              unit, kAudioUnitProperty_RequestViewController,
              kAudioUnitScope_Global, 0, &bytes, &writable);
          if (!controllerStatus && writable && bytes == sizeof(Callback)) {
            auto request = std::make_shared<ViewRequest>();
            Callback callback = ^(NSViewController *value) {
              std::lock_guard<std::mutex> lock(request->mutex);
              if (!request->abandoned) {
                request->controller = value;
                request->done = true;
              }
            };
            controllerStatus = AudioUnitSetProperty(
                unit, kAudioUnitProperty_RequestViewController,
                kAudioUnitScope_Global, 0, &callback, sizeof(callback));
            const auto until = CFAbsoluteTimeGetCurrent() + 10;
            while (!controllerStatus) {
              {
                std::lock_guard<std::mutex> lock(request->mutex);
                if (request->done) {
                  controller = request->controller;
                  request->controller = nil;
                  break;
                }
                if (CFAbsoluteTimeGetCurrent() >= until) {
                  request->abandoned = true;
                  break;
                }
              }
              CFRunLoopRunInMode(kCFRunLoopDefaultMode, 0.02, false);
            }
            view = controller.view;
            if (view)
              viewRoute = @"public RequestViewController";
          }
        }
        if (view) {
          if (view.frame.size.width <= 0 || view.frame.size.height <= 0)
            view.frame = NSMakeRect(0, 0, 1120, 477);
          window.contentView = view;
          [window setContentSize:view.frame.size];
          [window center];
          [window orderFrontRegardless];
          pump(0.25);
        }

        stage = "remote MIDI and independent audio render";
        renderAttempted = true;
        peak = renderAudio(unit, [prefix stringByAppendingString:@".wav"],
                           completed, rendered);
        // Still capture the view/status if audio fails, to aid diagnosis.
        pump(0.35);
        if (view) {
          NSBitmapImageRep *image =
              [view bitmapImageRepForCachingDisplayInRect:view.bounds];
          if (image) {
            [view cacheDisplayInRect:view.bounds toBitmapImageRep:image];
            NSData *png =
                [image representationUsingType:NSBitmapImageFileTypePNG
                                    properties:@{}];
            screenshot =
                [png writeToFile:[prefix stringByAppendingString:@".png"]
                      atomically:YES];
          }
        }

        stage = "checkpoint identity through standard AU state";
        CFPropertyListRef saved = nullptr;
        bytes = sizeof(saved);
        check(AudioUnitGetProperty(unit, kAudioUnitProperty_ClassInfo,
                                   kAudioUnitScope_Global, 0, &saved, &bytes),
              "Read standard remote AU state");
        NSDictionary *savedState = CFBridgingRelease(saved);
        if (![savedState isKindOfClass:NSDictionary.class])
          throw std::runtime_error(
              "The remote AU did not return a state dictionary");
        id marker = savedState[@"SophistryARMVersion"];
        if ([marker isKindOfClass:NSString.class])
          reportedVersion = marker;
        versionMatches = [reportedVersion isEqualToString:expected];
        if (!versionMatches)
          throw std::runtime_error("Standard AU state does not identify CP023; "
                                   "cached or unexpected remote code");
        NSData *bank = savedState[@"vstdata"];
        if (![bank isKindOfClass:NSData.class])
          throw std::runtime_error(
              "Standard remote state lost its legacy bank");
        plist = (__bridge CFPropertyListRef)savedState;
        check(AudioUnitSetProperty(unit, kAudioUnitProperty_ClassInfo,
                                   kAudioUnitScope_Global, 0, &plist,
                                   sizeof(plist)),
              "Restore remote standard-state snapshot");
        saved = nullptr;
        bytes = sizeof(saved);
        check(AudioUnitGetProperty(unit, kAudioUnitProperty_ClassInfo,
                                   kAudioUnitScope_Global, 0, &saved, &bytes),
              "Resave remote standard-state snapshot");
        NSDictionary *again = CFBridgingRelease(saved);
        stateRoundTrip = [bank isEqual:again[@"vstdata"]];

        stage = "public parameter change";
        float before = 0, after = 0;
        check(AudioUnitGetParameter(unit, 134, kAudioUnitScope_Global, 0,
                                    &before),
              "Read master volume");
        float target = before < -12 ? -6 : -18;
        check(AudioUnitSetParameter(unit, 134, kAudioUnitScope_Global, 0,
                                    target, 0),
              "Change master volume");
        check(
            AudioUnitGetParameter(unit, 134, kAudioUnitScope_Global, 0, &after),
            "Reread master volume");
        check(AudioUnitSetParameter(unit, 134, kAudioUnitScope_Global, 0,
                                    before, 0),
              "Restore master volume");
        parameterChange = std::isfinite(after) && fabs(after - target) < 0.001;
        stage = "final remote host checks";
        if (!view)
          throw std::runtime_error(
              "The public host APIs did not create a custom view");
        if (!stateRoundTrip || !parameterChange)
          throw std::runtime_error("Remote state or parameter check failed");
        check(rendered, "Remote render");
        if (completed != 132300 || peak <= 0.00001)
          throw std::runtime_error(
              "Remote AU did not render the complete audible fixture");
        stage = "passed";
      } catch (const std::exception &e) {
        error = e.what();
      }
    } @catch (NSException *exception) {
      error = std::string("Host view exception: ") + exception.name.UTF8String;
    }
    NSDictionary *report = @{
      @"scope" : @"public AU host APIs, one OS-managed custom view, public "
                 @"preset only",
      @"passed" : @(error.empty()),
      @"stage" : [NSString stringWithUTF8String:stage.c_str()],
      @"error" : error.empty() ? (id)[NSNull null]
                               : [NSString stringWithUTF8String:error.c_str()],
      @"uses_private_au_properties" : @NO,
      @"loaded_out_of_process_status" : remoteQueried ? (id) @(remoteStatus)
                                                      : [NSNull null],
      @"loaded_out_of_process" : @(remote != 0),
      @"state_restored_before_initialize" : @(restored && initialized),
      @"render_attempted" : @(renderAttempted),
      @"render_status" : renderAttempted ? (id) @(rendered) : [NSNull null],
      @"render_frames" : @(completed),
      @"render_peak" : @(peak),
      @"parameter_count" : @(parameterCount),
      @"parameter_change_passed" : @(parameterChange),
      @"state_bank_roundtrip_exact" : @(stateRoundTrip),
      @"reported_checkpoint" : reportedVersion,
      @"checkpoint_matches" : @(versionMatches),
      @"cocoa_property_status" : cocoaQueried ? (id) @(cocoaStatus)
                                              : [NSNull null],
      @"advertised_cocoa_factory" : advertisedClass,
      @"view_controller_status" : controllerQueried ? (id) @(controllerStatus)
                                                    : [NSNull null],
      @"custom_view_created" : @(view != nil),
      @"custom_view_route" : viewRoute,
      @"host_view_class" : view ? NSStringFromClass(view.class) : @"",
      @"host_view_snapshot_saved" : @(screenshot),
      @"visual_fidelity_certified" : @NO
    };
    NSData *json =
        [NSJSONSerialization dataWithJSONObject:report
                                        options:NSJSONWritingPrettyPrinted
                                          error:nil];
    BOOL written = [json writeToFile:[prefix stringByAppendingString:@".json"]
                          atomically:YES];
    if (json)
      fwrite(json.bytes, 1, json.length, stdout);
    if (window) {
      window.contentView = nil;
      [window orderOut:nil];
      [window close];
    }
    view = nil;
    controller = nil;
    if (unit) {
      if (initialized)
        AudioUnitUninitialize(unit);
      AudioComponentInstanceDispose(unit);
    }
    return error.empty() && written ? 0 : 1;
  }
}
