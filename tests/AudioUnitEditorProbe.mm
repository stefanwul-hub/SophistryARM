// Exercise the actual component Cocoa factory inside this process.
// Remote host validation uses only public APIs in AudioUnitRemoteHostProbe.mm.
#include "../src/au/PresetBrowser.h"
#include "../src/au/SophistryProperties.h"
#include "../src/engine/CompleteEditorControls.h"
#include "../src/engine/EditorControls.h"
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

// Use a genuinely fresh instance: a same-instance round trip can hide a lost
// name in a native member variable. Simulate a host replacing the standard
// label with Default and assigning that placeholder again after restoration.
static NSDictionary *presetLabelRoundTrip(AudioComponent component,
                                          AudioUnit source) {
  CFPropertyListRef saved = nullptr, before = nullptr, after = nullptr;
  CFMutableDictionaryRef edited = nullptr;
  AudioUnit fresh = nullptr;
  UInt32 size = sizeof(saved);
  OSStatus status =
      AudioUnitGetProperty(source, kAudioUnitProperty_ClassInfo,
                           kAudioUnitScope_Global, 0, &saved, &size);
  bool stored = false, restored = false, exposed = false, retained = false,
       bankExact = false, generatorTypesRetained = false;
  sophistry::GeneratorPanelState sourceGenerators{}, freshGenerators{};
  UInt32 generatorBytes = sizeof(sourceGenerators);
  const auto sourceGeneratorStatus = AudioUnitGetProperty(
      source, sophistry::generatorPanelProperty, kAudioUnitScope_Global, 0,
      &sourceGenerators, &generatorBytes);
  if (!status && saved && CFGetTypeID(saved) == CFDictionaryGetTypeID()) {
    auto dict = static_cast<CFDictionaryRef>(saved);
    const auto name =
        CFDictionaryGetValue(dict, CFSTR("SophistryARMPresetName"));
    stored = name && CFEqual(name, CFSTR("BT_lightgarden_02"));
    edited = CFDictionaryCreateMutableCopy(nullptr, 0, dict);
    if (edited) {
      CFDictionarySetValue(edited, CFSTR("name"), CFSTR("Default"));
      status = AudioComponentInstanceNew(component, &fresh);
    } else
      status = -108;
  } else
    status = status ? status : kAudioUnitErr_InvalidPropertyValue;
  if (!status) {
    CFPropertyListRef state = edited;
    status =
        AudioUnitSetProperty(fresh, kAudioUnitProperty_ClassInfo,
                             kAudioUnitScope_Global, 0, &state, sizeof(state));
  }
  OSStatus runtime = noErr;
  if (!status) {
    NSDictionary *info = runtimeStatus(fresh, runtime);
    restored = !runtime && [info[@"state_loaded"] boolValue] &&
               [info[@"preset_name"] isEqualToString:@"BT_lightgarden_02"];
    generatorBytes = sizeof(freshGenerators);
    const auto freshStatus = AudioUnitGetProperty(
        fresh, sophistry::generatorPanelProperty, kAudioUnitScope_Global, 0,
        &freshGenerators, &generatorBytes);
    generatorTypesRetained = !sourceGeneratorStatus && !freshStatus &&
                             sourceGenerators.types == freshGenerators.types;
    size = sizeof(before);
    status = AudioUnitGetProperty(fresh, kAudioUnitProperty_ClassInfo,
                                  kAudioUnitScope_Global, 0, &before, &size);
  }
  if (!status) {
    AUPreset placeholder{-1, CFSTR("Default")};
    status = AudioUnitSetProperty(fresh, kAudioUnitProperty_PresentPreset,
                                  kAudioUnitScope_Global, 0, &placeholder,
                                  sizeof(placeholder));
  }
  if (!status) {
    AUPreset current{};
    size = sizeof(current);
    status = AudioUnitGetProperty(fresh, kAudioUnitProperty_PresentPreset,
                                  kAudioUnitScope_Global, 0, &current, &size);
    exposed = !status && current.presetName &&
              CFEqual(current.presetName, CFSTR("BT_lightgarden_02"));
    if (current.presetName)
      CFRelease(current.presetName);
    NSDictionary *info = runtimeStatus(fresh, runtime);
    retained =
        !runtime && [info[@"preset_name"] isEqualToString:@"BT_lightgarden_02"];
  }
  if (!status) {
    size = sizeof(after);
    status = AudioUnitGetProperty(fresh, kAudioUnitProperty_ClassInfo,
                                  kAudioUnitScope_Global, 0, &after, &size);
    if (!status && before && after) {
      auto a = CFDictionaryGetValue(static_cast<CFDictionaryRef>(before),
                                    CFSTR("vstdata"));
      auto b = CFDictionaryGetValue(static_cast<CFDictionaryRef>(after),
                                    CFSTR("vstdata"));
      bankExact = a && b && CFEqual(a, b);
    }
  }
  if (fresh)
    AudioComponentInstanceDispose(fresh);
  if (edited)
    CFRelease(edited);
  if (saved)
    CFRelease(saved);
  if (before)
    CFRelease(before);
  if (after)
    CFRelease(after);
  return @{
    @"passed" : @(!status && stored && restored && exposed && retained &&
                  bankExact && generatorTypesRetained),
    @"status" : @(status),
    @"name_serialized" : @(stored),
    @"name_restored_in_fresh_instance" : @(restored),
    @"present_preset_name_preserved" : @(exposed),
    @"generic_host_name_does_not_replace_original" : @(retained),
    @"bank_unchanged_by_name_assignment" : @(bankExact),
    @"generator_types_retained" : @(generatorTypesRetained)
  };
}

@interface NSView (SophistryEditorTesting)
- (BOOL)loadPresetURL:(NSURL *)url;
- (NSDictionary *)sophistryEditorReport;
- (void)selectTab:(NSButton *)sender;
- (void)parameterChanged:(NSControl *)sender;
- (BOOL)testGeneratorControl:(UInt32)tag normalized:(float)value;
- (BOOL)testCompleteControl:(UInt32)tag normalized:(float)value;
- (BOOL)testCompleteText:(UInt32)tag value:(NSString *)value;
- (NSDictionary *)testAuxiliaryPage:(unsigned)page snapshot:(NSString *)path;
- (BOOL)testGeneratorRoutingClick:(unsigned)slot;
- (BOOL)testEditorButtonAtX:(double)x y:(double)y;
- (BOOL)testOriginalControlAtX:(double)x y:(double)y normalized:(float)value;
- (BOOL)testOriginalXYAtX:(double)x
                        y:(double)y
              normalizedX:(float)nx
              normalizedY:(float)ny;
@end

static NSDictionary *generatorAliasTests(NSView *view) {
  NSMutableArray *cases = [NSMutableArray array];
  BOOL passed = YES;
  for (unsigned g = 0; g < 4; ++g) {
    NSButton *tab = [NSButton new];
    tab.tag = g < 2 ? 1 : 2;
    [view selectTab:tab];
    const unsigned maximum = g < 2 ? 3 : 2;
    for (unsigned source = 0; source <= maximum; ++source)
      for (unsigned target = 0; target <= maximum; ++target) {
        const unsigned canonical = sophistry::generatorTypeTag(g);
        const BOOL setup = [view testGeneratorControl:canonical
                                           normalized:float(source) / maximum];
        NSDictionary *before = [view sophistryEditorReport][@"generator_panel"];
        unsigned visible = 0;
        for (NSDictionary *c in before[@"controls"])
          if (sophistry::generatorForTypeTag([c[@"tag"] unsignedIntValue]) == g)
            visible = [c[@"tag"] unsignedIntValue];
        const unsigned expected =
            g < 2 ? 766 + 2 * source + g : 774 + 2 * source + g - 2;
        const BOOL selected =
            [view testGeneratorControl:canonical
                            normalized:float(target) / maximum];
        NSDictionary *after = [view sophistryEditorReport][@"generator_panel"];
        const BOOL ok =
            setup && selected && visible == expected &&
            [before[@"types"][g] unsignedIntValue] == source &&
            [after[@"types"][g] unsignedIntValue] == target &&
            [after[@"property_status"] intValue] == 0 &&
            [after[@"active_controls_in_bounds"] boolValue] &&
            [after[@"image_dimensions_match_original_pixels"] boolValue] &&
            [after[@"sprites_loaded"] boolValue];
        passed = passed && ok;
        [cases addObject:@{
          @"generator" : @(g + 1),
          @"source" : @(source),
          @"target" : @(target),
          @"requested_tag" : @(canonical),
          @"visible_tag" : @(visible),
          @"setup_succeeded" : @(setup),
          @"selection_succeeded" : @(selected),
          @"passed" : @(ok)
        }];
      }
  }
  return @{@"passed" : @(passed && cases.count == 50), @"transitions" : cases};
}

static NSDictionary *completeEditorTests(NSView *view, AudioUnit unit,
                                         NSString *fxp, NSString *prefix,
                                         NSString *loop) {
  NSMutableArray *pages = [NSMutableArray array],
                 *effects = [NSMutableArray array],
                 *modulation = [NSMutableArray array],
                 *auxiliary = [NSMutableArray array];
  BOOL passed = YES;
  auto page = [&](unsigned index) {
    NSButton *tab = [NSButton new];
    tab.tag = index;
    [view selectTab:tab];
  };
  auto valid = [&](NSDictionary *r) {
    return [r[@"status"] intValue] == 0 &&
           [r[@"active_controls_in_bounds"] boolValue] &&
           [r[@"image_dimensions_match_original_pixels"] boolValue] &&
           [r[@"sprites_loaded"] boolValue] && [r[@"controls"] count] > 0;
  };
  for (unsigned i = 0; i < 7; ++i) {
    page(i);
    NSMutableDictionary *r =
        [[view sophistryEditorReport][@"original_panel"] mutableCopy];
    NSBitmapImageRep *rep =
        [view bitmapImageRepForCachingDisplayInRect:view.bounds];
    BOOL saved = NO;
    if (rep) {
      [view cacheDisplayInRect:view.bounds toBitmapImageRep:rep];
      saved = [[rep representationUsingType:NSBitmapImageFileTypePNG
                                 properties:@{}]
          writeToFile:[NSString stringWithFormat:@"%@-page%u.png", prefix, i]
           atomically:YES];
    }
    r[@"snapshot_saved"] = @(saved);
    passed = passed && valid(r) && saved;
    [pages addObject:r];
  }
  page(4);
  for (unsigned slot = 0; slot < 6; ++slot)
    for (unsigned type = 0; type < 12; ++type) {
      BOOL edited = [view testCompleteControl:213 + slot
                                   normalized:float(type) / 11];
      NSDictionary *r = [view sophistryEditorReport][@"original_panel"];
      BOOL selected = NO;
      for (NSDictionary *c in r[@"controls"])
        if ([c[@"tag"] unsignedIntValue] == 213 + slot)
          selected = [c[@"value"] unsignedIntValue] == type;
      BOOL ok = edited && selected && valid(r);
      passed = passed && ok;
      [effects addObject:@{
        @"slot" : @(slot),
        @"type" : @(type),
        @"passed" : @(ok),
        @"panels" : r[@"panels"] ?: @[]
      }];
    }
  page(5);
  for (auto pair :
       std::array<std::pair<unsigned, unsigned>, 2>{{{606, 4}, {605, 5}}})
    for (unsigned i = 0; i < pair.second; ++i) {
      BOOL edited = [view testCompleteControl:pair.first
                                   normalized:float(i) / (pair.second - 1)];
      NSDictionary *r = [view sophistryEditorReport][@"original_panel"];
      BOOL selected = NO;
      for (NSDictionary *c in r[@"controls"])
        if ([c[@"tag"] unsignedIntValue] == pair.first)
          selected = [c[@"value"] unsignedIntValue] == i;
      BOOL ok = edited && selected && valid(r);
      passed = passed && ok;
      [modulation addObject:@{
        @"selector" : @(pair.first),
        @"value" : @(i),
        @"passed" : @(ok)
      }];
    }
  for (unsigned i = 7; i < 9; ++i) {
    NSDictionary *r =
        [view testAuxiliaryPage:i
                       snapshot:[NSString stringWithFormat:@"%@-aux%u.png",
                                                           prefix, i]];
    BOOL ok = [r[@"status"] intValue] == 0 &&
              [r[@"active_controls_in_bounds"] boolValue] &&
              [r[@"image_dimensions_match_original_pixels"] boolValue] &&
              [r[@"sprites_loaded"] boolValue] &&
              [r[@"snapshot_saved"] boolValue];
    passed = passed && ok;
    [auxiliary addObject:r];
  }
  std::array<char, sophistry::editorStringBytes> sequence{};
  UInt32 size = sequence.size();
  BOOL arp = !AudioUnitGetProperty(unit, sophistry::editorStringProperty,
                                   kAudioUnitScope_Global, 648, sequence.data(),
                                   &size) &&
             strnlen(sequence.data(), sequence.size()) == 258;
  if (arp) {
    auto changed = sequence;
    changed[2] = 61;
    changed[3] = char(129);
    sophistry::EditorTextEditHeader h{1, 648, 259};
    std::vector<char> data(sizeof(h) + 259);
    memcpy(data.data(), &h, sizeof(h));
    memcpy(data.data() + sizeof(h), changed.data(), 259);
    arp = !AudioUnitSetProperty(unit, sophistry::editorTextEditProperty,
                                kAudioUnitScope_Global, 0, data.data(),
                                UInt32(data.size()));
    std::array<char, sophistry::editorStringBytes> read{};
    size = read.size();
    arp = arp &&
          !AudioUnitGetProperty(unit, sophistry::editorStringProperty,
                                kAudioUnitScope_Global, 648, read.data(),
                                &size) &&
          !memcmp(read.data(), changed.data(), 259);
  }
  BOOL restored = [view loadPresetURL:[NSURL fileURLWithPath:fxp]];
  BOOL markers = [view loadPresetURL:[NSURL fileURLWithPath:loop]];
  page(1);
  for (auto [tag, value] : std::array<std::pair<unsigned, int>, 4>{
           {{950, 1024}, {952, 4096}, {954, 32000}, {956, 8000}}}) {
    BOOL ok = [view testCompleteText:tag
                               value:[NSString stringWithFormat:@"%d", value]];
    NSDictionary *r = [view sophistryEditorReport][@"original_panel"];
    BOOL found = NO;
    for (NSDictionary *c in r[@"controls"])
      if ([c[@"tag"] unsignedIntValue] == tag)
        found = [c[@"value"] intValue] == value;
    markers = markers && ok && found;
  }
  restored = restored && [view loadPresetURL:[NSURL fileURLWithPath:fxp]];
  return @{
    @"passed" : @(passed && arp && restored && markers),
    @"pages" : pages,
    @"effects" : effects,
    @"modulation" : modulation,
    @"auxiliary" : auxiliary,
    @"arpeggiator_binary_text_edit" : @(arp),
    @"numeric_loop_markers" : @(markers),
    @"public_preset_restored" : @(restored)
  };
}

static NSDictionary *mainButtonTests(NSView *view, NSString *fxpPath,
                                     NSString *statePath) {
  NSMutableArray *edits = [NSMutableArray array],
                 *navigation = [NSMutableArray array];
  NSButton *main = [NSButton new];
  main.tag = 0;
  const double points[][2] = {{175, 118}, {175, 133}, {421, 126}, {664, 126}};
  BOOL passed = YES;
  for (unsigned i = 0; i < 4; ++i) {
    [view selectTab:main];
    BOOL clicked = [view testEditorButtonAtX:points[i][0] y:points[i][1]];
    NSDictionary *report = [view sophistryEditorReport];
    BOOL ok = clicked && [report[@"selected_tab"] unsignedIntValue] == i + 1;
    [edits addObject:@{
      @"target_tab" : @(i + 1),
      @"point" : @[ @(points[i][0]), @(points[i][1]) ],
      @"passed" : @(ok),
      @"hit" : report[@"last_click"] ?: @{}
    }];
    passed = passed && ok;
  }
  NSURL *folder = [[NSURL fileURLWithPath:NSTemporaryDirectory()
                              isDirectory:YES]
      URLByAppendingPathComponent:[@"SophistryNavigation-"
                                      stringByAppendingString:NSUUID.UUID
                                                                  .UUIDString]
                      isDirectory:YES];
  BOOL made = [NSFileManager.defaultManager createDirectoryAtURL:folder
                                     withIntermediateDirectories:NO
                                                      attributes:nil
                                                           error:nil];
  NSArray<NSString *> *names = @[ @"Alpha", @"Bravo", @"Charlie" ];
  NSArray<NSURL *> *urls = @[
    [folder URLByAppendingPathComponent:@"A Alpha.fxp"],
    [folder URLByAppendingPathComponent:@"B Bravo.FXP"],
    [folder URLByAppendingPathComponent:@"C Charlie.aupreset"]
  ];
  NSData *source = [NSData dataWithContentsOfFile:fxpPath];
  made = made && source.length >= 60;
  for (unsigned i = 0; made && i < 2; ++i) {
    NSMutableData *data = [source mutableCopy];
    char *bytes = static_cast<char *>(data.mutableBytes);
    memset(bytes + 28, 0, 28);
    memcpy(bytes + 28, names[i].UTF8String, names[i].length);
    made = [data writeToURL:urls[i] atomically:YES];
  }
  NSMutableDictionary *state =
      [[NSDictionary dictionaryWithContentsOfFile:statePath] mutableCopy];
  state[@"name"] = names[2];
  state[@"SophistryARMPresetName"] = names[2];
  made = made && state && [state writeToURL:urls[2] atomically:YES];
  BOOL catalogue =
      made && sophistryPresetBrowser::directory(folder).count == 3 &&
      [sophistryPresetBrowser::find(folder, @"Bravo").lastPathComponent
          isEqual:urls[1].lastPathComponent] &&
      !sophistryPresetBrowser::find(folder, @"No such sound");
  NSURL *duplicate = [folder URLByAppendingPathComponent:@"D Duplicate.fxp"];
  if (catalogue) {
    catalogue = [NSFileManager.defaultManager copyItemAtURL:urls[1]
                                                      toURL:duplicate
                                                      error:nil] &&
                !sophistryPresetBrowser::find(folder, @"Bravo");
    [NSFileManager.defaultManager removeItemAtURL:duplicate error:nil];
  }
  [view selectTab:main];
  BOOL loaded = made && [view loadPresetURL:urls[0]];
  const unsigned order[] = {1, 2, 0, 2, 1, 0};
  for (unsigned i = 0; loaded && i < 6; ++i) {
    BOOL clicked = [view testEditorButtonAtX:(i < 3 ? 116 : 40) y:272];
    NSDictionary *report = [view sophistryEditorReport];
    BOOL ok = clicked &&
              [report[@"status"][@"preset_name"] isEqual:names[order[i]]] &&
              [report[@"source_preset_file"]
                  isEqual:urls[order[i]].lastPathComponent];
    [navigation addObject:@{
      @"direction" : i < 3 ? @"next" : @"previous",
      @"expected_name" : names[order[i]],
      @"passed" : @(ok),
      @"hit" : report[@"last_click"] ?: @{}
    }];
    passed = passed && ok;
    if (!ok)
      break;
  }
  BOOL restored = [view loadPresetURL:[NSURL fileURLWithPath:fxpPath]];
  [NSFileManager.defaultManager removeItemAtURL:folder error:nil];
  return @{
    @"passed" : @(passed && catalogue && restored && navigation.count == 6),
    @"edit_buttons" : edits,
    @"preset_navigation" : navigation,
    @"catalogue_unique_missing_and_ambiguous_checks" : @(catalogue),
    @"original_public_preset_restored" : @(restored)
  };
}

static sophistry::EditorControlState
originalControl(AudioUnit unit, unsigned panel, unsigned tag) {
  sophistry::EditorPanelState state;
  UInt32 size = sizeof(state);
  if (AudioUnitGetProperty(unit, sophistry::editorPanelProperty,
                           kAudioUnitScope_Global, panel, &state, &size))
    return {};
  for (unsigned i = 0; i < state.count && i < state.controls.size(); ++i)
    if (state.controls[i].value.tag == tag)
      return state.controls[i];
  return {};
}
static NSDictionary *originalEditorTests(NSView *view, AudioUnit unit,
                                         NSString *fxp, NSString *loop,
                                         NSString *prefix) {
  NSMutableArray *controls = [NSMutableArray array],
                 *xy = [NSMutableArray array];
  BOOL passed = YES;
  const struct {
    unsigned panel, tag;
    int x, y;
  } cases[] = {{0, 958, 58, 300}, {0, 614, 137, 300}, {0, 482, 625, 293},
               {1, 114, 205, 81}, {1, 116, 205, 143}, {1, 115, 205, 219},
               {1, 117, 205, 281}};
  NSButton *tab = [NSButton new];
  for (auto c : cases) {
    tab.tag = c.panel ? 3 : 0;
    [view selectTab:tab];
    auto before = originalControl(unit, c.panel, c.tag);
    float target = before.normalized < .4f ? .82f : .17f;
    BOOL hit = [view testOriginalControlAtX:c.x y:c.y normalized:target];
    auto after = originalControl(unit, c.panel, c.tag);
    BOOL ok = hit && before.value.tag == c.tag && after.value.tag == c.tag &&
              after.value.value != before.value.value;
    BOOL restored = [view testOriginalControlAtX:c.x
                                               y:c.y
                                      normalized:before.normalized];
    restored = restored && originalControl(unit, c.panel, c.tag).value.value ==
                               before.value.value;
    [controls addObject:@{
      @"tag" : @(c.tag),
      @"hit" : @(hit),
      @"before" : @(before.value.value),
      @"after" : @(after.value.value),
      @"restored" : @(restored),
      @"passed" : @(ok && restored)
    }];
    passed = passed && ok && restored;
  }
  for (unsigned panel = 0; panel < 2; ++panel) {
    tab.tag = panel ? 3 : 0;
    [view selectTab:tab];
    for (auto spec : sophistry::editorXY(panel)) {
      auto x = originalControl(unit, panel, spec.xTag),
           y = originalControl(unit, panel, spec.yTag);
      float nx = x.normalized < .5f ? .81f : .21f,
            ny = y.normalized < .5f ? .79f : .19f;
      int cx = spec.x + spec.size / 2, cy = 37 + spec.y + spec.size / 2;
      BOOL hit = [view testOriginalXYAtX:cx y:cy normalizedX:nx normalizedY:ny];
      auto xx = originalControl(unit, panel, spec.xTag),
           yy = originalControl(unit, panel, spec.yTag);
      BOOL ok = hit && xx.value.value != x.value.value &&
                yy.value.value != y.value.value;
      BOOL restored = [view testOriginalXYAtX:cx
                                            y:cy
                                  normalizedX:x.normalized
                                  normalizedY:y.normalized];
      restored =
          restored &&
          originalControl(unit, panel, spec.xTag).value.value ==
              x.value.value &&
          originalControl(unit, panel, spec.yTag).value.value == y.value.value;
      [xy addObject:@{
        @"x_tag" : @(spec.xTag),
        @"y_tag" : @(spec.yTag),
        @"passed" : @(ok && restored)
      }];
      passed = passed && ok && restored;
    }
  }
  NSBitmapImageRep *filter =
      [view bitmapImageRepForCachingDisplayInRect:view.bounds];
  BOOL filterPNG = NO;
  if (filter) {
    [view cacheDisplayInRect:view.bounds toBitmapImageRep:filter];
    filterPNG = [[filter representationUsingType:NSBitmapImageFileTypePNG
                                      properties:@{}]
        writeToFile:[prefix stringByAppendingString:@"-filters.png"]
         atomically:YES];
  }
  BOOL loaded = [view loadPresetURL:[NSURL fileURLWithPath:loop]];
  tab.tag = 1;
  [view selectTab:tab];
  NSDictionary *waveReport =
      [view sophistryEditorReport][@"generator_panel"][@"waveforms"][0];
  BOOL waveform = loaded && [waveReport[@"status"] intValue] == 0 &&
                  [waveReport[@"source_frames"] unsignedIntValue] == 334664 &&
                  [waveReport[@"lines"] unsignedIntValue] > 300;
  NSBitmapImageRep *rep =
      [view bitmapImageRepForCachingDisplayInRect:view.bounds];
  BOOL wavePNG = NO;
  if (rep) {
    [view cacheDisplayInRect:view.bounds toBitmapImageRep:rep];
    wavePNG = [[rep representationUsingType:NSBitmapImageFileTypePNG
                                 properties:@{}]
        writeToFile:[prefix stringByAppendingString:@"-loop-waveform.png"]
         atomically:YES];
  }
  BOOL restored = [view loadPresetURL:[NSURL fileURLWithPath:fxp]];
  return @{
    @"passed" : @(passed && filterPNG && waveform && wavePNG && restored),
    @"field_and_filter_controls" : controls,
    @"xy_controls" : xy,
    @"loop_waveform" : waveReport ?: @{},
    @"filter_snapshot" : @(filterPNG),
    @"waveform_snapshot" : @(wavePNG),
    @"public_preset_restored" : @(restored)
  };
}

int main(int argc, const char **argv) {
  @autoreleasepool {
    if (argc != 6)
      return 2;
    NSString *bundlePath = [NSString stringWithUTF8String:argv[1]];
    NSString *statePath = [NSString stringWithUTF8String:argv[2]];
    NSString *fxpPath = [NSString stringWithUTF8String:argv[3]];
    NSString *prefix = [NSString stringWithUTF8String:argv[4]];
    NSString *loopPath = [NSString stringWithUTF8String:argv[5]];
    AudioUnit unit = nullptr;
    AudioComponent component = nullptr;
    NSString *failure = nil;
    NSDictionary *viewReport = @{};
    NSDictionary *renderStatus = @{};
    NSDictionary *labelRoundTrip = @{};
    NSMutableArray *generatorCases = [NSMutableArray array];
    NSMutableArray *routingCases = [NSMutableArray array];
    NSDictionary *generatorRecall = @{};
    NSDictionary *generatorAliases = @{};
    NSDictionary *mainButtons = @{};
    NSDictionary *originalEditor = @{};
    NSDictionary *completeEditor = @{};
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
        component = AudioComponentRegister(
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
            NSWindow *testWindow = [[NSWindow alloc]
                initWithContentRect:view.bounds
                          styleMask:NSWindowStyleMaskBorderless
                            backing:NSBackingStoreBuffered
                              defer:NO];
            testWindow.releasedWhenClosed = NO;
            testWindow.contentView = view;
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
            if (fxp && fxpNamePreserved)
              labelRoundTrip = presetLabelRoundTrip(component, unit);
            if (!failure) {
              mainButtons = mainButtonTests(view, fxpPath, statePath);
              if (![mainButtons[@"passed"] boolValue])
                failure =
                    @"Main Edit or Prev/Next coordinate action test failed";
            }
            if (!failure) {
              originalEditor =
                  originalEditorTests(view, unit, fxpPath, loopPath, prefix);
              if (![originalEditor[@"passed"] boolValue])
                failure = @"Original Main/Filter controls or loop waveform "
                          @"test failed";
            }
            for (unsigned generator = 0; !failure && generator < 4;
                 ++generator) {
              NSButton *section = [NSButton new];
              section.tag = generator < 2 ? 1 : 2;
              [view selectTab:section];
              if ((generator & 1) == 0) {
                for (unsigned slot = 0; !failure && slot < 3; ++slot) {
                  const BOOL clicked = [view testGeneratorRoutingClick:slot];
                  float actual = -1;
                  const auto routeStatus =
                      AudioUnitGetParameter(unit, 108 + generator / 2,
                                            kAudioUnitScope_Global, 0, &actual);
                  NSBitmapImageRep *rep =
                      [view bitmapImageRepForCachingDisplayInRect:view.bounds];
                  BOOL saved = NO;
                  if (rep) {
                    [view cacheDisplayInRect:view.bounds toBitmapImageRep:rep];
                    NSData *png =
                        [rep representationUsingType:NSBitmapImageFileTypePNG
                                          properties:@{}];
                    NSString *name = [NSString
                        stringWithFormat:@"%@-routing-pair%u-value%u.png",
                                         prefix, generator / 2 + 1, slot];
                    saved = [png writeToFile:name atomically:YES];
                  }
                  const BOOL passed = clicked && !routeStatus &&
                                      std::isfinite(actual) &&
                                      fabsf(actual - slot) < 0.001f && saved;
                  [routingCases addObject:@{
                    @"pair" : @(generator / 2 + 1),
                    @"requested" : @(slot),
                    @"public_au_value" : @(actual),
                    @"original_coordinate_mouse_click" : @(clicked),
                    @"snapshot_saved" : @(saved),
                    @"passed" : @(passed)
                  }];
                  if (!passed)
                    failure = @"Original routing coordinate mouse test failed";
                }
              }
              const unsigned maximum = generator < 2 ? 3 : 2;
              for (unsigned type = 0; !failure && type <= maximum; ++type) {
                const BOOL selected = [view
                    testGeneratorControl:sophistry::generatorTypeTag(generator)
                              normalized:float(type) / maximum];
                NSDictionary *panel =
                    [view sophistryEditorReport][@"generator_panel"];
                float beforeVolume = 0, afterVolume = 0;
                const auto beforeStatus = AudioUnitGetParameter(
                    unit, 4 + generator, kAudioUnitScope_Global, 0,
                    &beforeVolume);
                const BOOL changed = [view
                    testGeneratorControl:4 + generator
                              normalized:beforeVolume > -12 ? 0.35f : 0.82f];
                const auto afterStatus = AudioUnitGetParameter(
                    unit, 4 + generator, kAudioUnitScope_Global, 0,
                    &afterVolume);
                NSBitmapImageRep *rep =
                    [view bitmapImageRepForCachingDisplayInRect:view.bounds];
                BOOL pngSaved = NO;
                if (rep) {
                  [view cacheDisplayInRect:view.bounds toBitmapImageRep:rep];
                  NSData *png =
                      [rep representationUsingType:NSBitmapImageFileTypePNG
                                        properties:@{}];
                  NSString *name =
                      [NSString stringWithFormat:@"%@-g%u-type%u.png", prefix,
                                                 generator + 1, type];
                  pngSaved = [png writeToFile:name atomically:YES];
                }
                const BOOL passed =
                    selected && changed && !beforeStatus && !afterStatus &&
                    std::isfinite(afterVolume) &&
                    fabsf(afterVolume - beforeVolume) > 0.5f &&
                    [panel[@"property_status"] intValue] == 0 &&
                    [panel[@"types"][generator] unsignedIntValue] == type &&
                    [panel[@"active_controls_in_bounds"] boolValue] &&
                    [panel[@"image_dimensions_match_original_pixels"]
                        boolValue] &&
                    [panel[@"sprites_loaded"] boolValue] &&
                    [panel[@"controls"] count] > 4 && pngSaved;
                [generatorCases addObject:@{
                  @"generator" : @(generator + 1),
                  @"type" : @(type),
                  @"selection_succeeded" : @(selected),
                  @"volume_edit_succeeded" : @(changed),
                  @"passed" : @(passed),
                  @"snapshot_saved" : @(pngSaved),
                  @"panel" : panel,
                  @"au_volume_before" : @(beforeVolume),
                  @"au_volume_after" : @(afterVolume)
                }];
                if (!passed)
                  failure =
                      @"Original generator controls or selector test failed";
              }
            }
            if (!failure) {
              generatorAliases = generatorAliasTests(view);
              if (![generatorAliases[@"passed"] boolValue])
                failure =
                    @"Visible original generator menu transition test failed";
            }
            if (!failure)
              generatorRecall = presetLabelRoundTrip(component, unit);
            if (!failure) {
              completeEditor =
                  completeEditorTests(view, unit, fxpPath, prefix, loopPath);
              if (![completeEditor[@"passed"] boolValue])
                failure = @"Complete recovered editor "
                          @"page/effect/modulation/auxiliary test failed";
            }
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
                (!fxp || !fxpNamePreserved || generatorCases.count != 14 ||
                 routingCases.count != 6 ||
                 ![generatorRecall[@"passed"] boolValue] ||
                 ![labelRoundTrip[@"passed"] boolValue] || !aupreset ||
                 !controls || !tabs || rendered || runtimePropertyStatus ||
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
            [testWindow close];
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
      @"preset_name_fresh_instance_roundtrip" : labelRoundTrip,
      @"generator_cases" : generatorCases,
      @"generator_menu_aliases" : generatorAliases,
      @"routing_mouse_cases" : routingCases,
      @"main_button_tests" : mainButtons,
      @"original_editor_tests" : originalEditor,
      @"complete_editor_tests" : completeEditor,
      @"generator_fresh_instance_recall" : generatorRecall,
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
