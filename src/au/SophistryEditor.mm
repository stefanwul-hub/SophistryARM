// Native Cocoa view using the recovered original panels and controls.
#include "BankAccess.h"
#include "PresetBrowser.h"
#include "SophistryProperties.h"
#import <AppKit/AppKit.h>
#import <AudioToolbox/AUCocoaUIView.h>
#import <AudioToolbox/AudioToolbox.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

namespace {
NSString *string(CFStringRef value) {
  return value ? [(__bridge NSString *)value copy] : @"";
}
NSString *valueText(AudioUnit unit, UInt32 id, float value) {
  AudioUnitParameterStringFromValue request{id, &value, nullptr};
  UInt32 size = sizeof(request);
  if (!AudioUnitGetProperty(unit, kAudioUnitProperty_ParameterStringFromValue,
                            kAudioUnitScope_Global, 0, &request, &size) &&
      request.outString) {
    NSString *result = string(request.outString);
    CFRelease(request.outString);
    return [result
        stringByTrimmingCharactersInSet:NSCharacterSet.whitespaceCharacterSet];
  }
  return [NSString stringWithFormat:@"%.4g", double(value)];
}
void event(AudioUnit unit, UInt32 id, AudioUnitEventType type) {
  AudioUnitEvent e{};
  e.mEventType = type;
  e.mArgument.mParameter = {unit, id, kAudioUnitScope_Global, 0};
  AUEventListenerNotify(nullptr, nullptr, &e);
}
NSDictionary *status(AudioUnit unit) {
  std::vector<char> result(sophistry::runtimeStatusBytes);
  UInt32 size = UInt32(result.size());
  if (AudioUnitGetProperty(unit, sophistry::runtimeStatusProperty,
                           kAudioUnitScope_Global, 0, result.data(), &size))
    return @{};
  NSData *data = [NSData dataWithBytes:result.data()
                                length:strnlen(result.data(), result.size())];
  id json = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
  if (!json) {
    // Some old program names contain Mac Roman bytes instead of UTF-8.
    NSString *legacy =
        [[NSString alloc] initWithData:data
                              encoding:NSMacOSRomanStringEncoding];
    NSData *converted = [legacy dataUsingEncoding:NSUTF8StringEncoding];
    if (converted)
      json = [NSJSONSerialization JSONObjectWithData:converted
                                             options:0
                                               error:nil];
  }
  return [json isKindOfClass:NSDictionary.class] ? json : @{};
}
NSTextField *label(NSRect rect, NSString *value, CGFloat size) {
  NSTextField *field = [[NSTextField alloc] initWithFrame:rect];
  field.stringValue = value;
  field.editable = NO;
  field.selectable = YES;
  field.bordered = NO;
  field.drawsBackground = NO;
  field.textColor = NSColor.whiteColor;
  field.font = [NSFont systemFontOfSize:size];
  return field;
}
NSButton *button(NSRect rect, NSString *title, id target, SEL action) {
  NSButton *value = [NSButton buttonWithTitle:title
                                       target:target
                                       action:action];
  value.frame = rect;
  value.bezelStyle = NSBezelStyleRounded;
  value.font = [NSFont systemFontOfSize:11];
  return value;
}
BOOL hasGenericBrowser(NSView *view) {
  if ([view isKindOfClass:NSSearchField.class] ||
      [view isKindOfClass:NSScrollView.class])
    return YES;
  for (NSView *child in view.subviews)
    if (hasGenericBrowser(child))
      return YES;
  return NO;
}
} // namespace

@interface SophistryPresetButton : NSButton
@end
@implementation SophistryPresetButton
- (void)drawRect:(NSRect)dirty {
  NSRect face = NSInsetRect(self.bounds, 1, 1);
  NSBezierPath *shape = [NSBezierPath bezierPathWithRoundedRect:face
                                                        xRadius:2
                                                        yRadius:2];
  NSColor *top = [NSColor colorWithRed:.43 green:.47 blue:.58 alpha:1];
  NSColor *bottom = [NSColor colorWithRed:.27 green:.31 blue:.42 alpha:1];
  if (self.highlighted)
    std::swap(top, bottom);
  [[[NSGradient alloc] initWithStartingColor:top
                                 endingColor:bottom] drawInBezierPath:shape
                                                                angle:90];
  NSMutableParagraphStyle *style = [NSMutableParagraphStyle new];
  style.alignment = NSTextAlignmentCenter;
  NSDictionary *attributes = @{
    NSFontAttributeName : [NSFont systemFontOfSize:7
                                            weight:NSFontWeightSemibold],
    NSForegroundColorAttributeName : self.enabled ? NSColor.whiteColor
                                                  : [NSColor colorWithWhite:1
                                                                      alpha:.5],
    NSParagraphStyleAttributeName : style
  };
  [self.title drawInRect:NSMakeRect(1, (self.bounds.size.height - 9) / 2,
                                    self.bounds.size.width - 2, 10)
          withAttributes:attributes];
}
@end
static NSButton *presetButton(NSRect frame, NSString *title, id target,
                              SEL action) {
  auto *b = [SophistryPresetButton buttonWithTitle:title
                                            target:target
                                            action:action];
  b.frame = frame;
  b.bordered = NO;
  return b;
}

#include "CompleteEditorView.h"
#include "GeneratorView.h"

@interface SophistryFlippedView : NSView
@end
@implementation SophistryFlippedView
- (BOOL)isFlipped {
  return YES;
}
@end

@interface SophistryEditorView : SophistryFlippedView
- (instancetype)initWithAudioUnit:(AudioUnit)unit;
- (BOOL)loadPresetURL:(NSURL *)url;
- (NSDictionary *)sophistryEditorReport;
- (BOOL)testGeneratorControl:(UInt32)tag normalized:(float)value;
- (NSView *)controlAtPoint:(NSPoint)point;
- (void)navigatePreset:(NSInteger)direction;
@end

@implementation SophistryEditorView {
  AudioUnit unit_;
  NSBundle *bundle_;
  NSImage *frame_, *panel_;
  NSInteger selectedTab_;
  std::vector<UInt32> parameterIDs_;
  NSMutableArray<NSView *> *mainControls_;
  NSTextField *preset_, *bank_, *message_, *activity_, *lcd_;
  NSSlider *master_;
  NSTextField *masterValue_;
  NSTextField *footer_;
  NSTimer *timer_;
  NSString *lastJSON_;
  SophistryCompletePanel *complete_, *auxiliary_;
  NSPanel *auxiliaryWindow_;
  NSURL *lastPresetURL_;
  NSString *lastPresetLabel_;
  NSButton *previousPreset_, *nextPreset_;
  BOOL presetNavigationBusy_;
  NSDictionary *lastClick_;
}
- (NSImage *)image:(NSUInteger)number {
  NSString *name =
      [NSString stringWithFormat:@"bmp%05lu", (unsigned long)number];
  NSURL *url = [bundle_ URLForResource:name
                         withExtension:@"png"
                          subdirectory:@"OriginalImages"];
  return url ? [[NSImage alloc] initWithContentsOfURL:url] : nil;
}
- (instancetype)initWithAudioUnit:(AudioUnit)unit {
  if (!(self = [super initWithFrame:NSMakeRect(0, 0, 762, 477)]))
    return nil;
  unit_ = unit;
  bundle_ = [NSBundle bundleForClass:self.class];
  mainControls_ = [NSMutableArray array];
  UInt32 size = 0;
  Boolean writable = NO;
  if (!AudioUnitGetPropertyInfo(unit_, kAudioUnitProperty_ParameterList,
                                kAudioUnitScope_Global, 0, &size, &writable) &&
      size < 8192) {
    std::vector<UInt32> ids(size / sizeof(UInt32));
    if (!AudioUnitGetProperty(unit_, kAudioUnitProperty_ParameterList,
                              kAudioUnitScope_Global, 0, ids.data(), &size)) {
      parameterIDs_ = std::move(ids);
    }
  }
  frame_ = [self image:128];
  panel_ = [self image:200];
  complete_ = [[SophistryCompletePanel alloc] initWithAudioUnit:unit_
                                                         bundle:bundle_];
  complete_.changeTarget = self;
  [self addSubview:complete_];
  AudioUnitParameterInfo masterInfo{};
  UInt32 masterBytes = sizeof(masterInfo);
  if (!AudioUnitGetProperty(unit_, kAudioUnitProperty_ParameterInfo,
                            kAudioUnitScope_Global, 134, &masterInfo,
                            &masterBytes)) {
    master_ = [[NSSlider alloc] initWithFrame:NSMakeRect(591, 330, 151, 17)];
    master_.minValue = masterInfo.minValue;
    master_.maxValue = masterInfo.maxValue;
    master_.continuous = YES;
    master_.tag = 134;
    master_.target = self;
    master_.action = @selector(parameterChanged:);
    master_.toolTip = @"Volume principal";
    masterValue_ = label(NSMakeRect(487, 329, 67, 19), @"", 11);
    [self addSubview:master_];
    [self addSubview:masterValue_];
    if ((masterInfo.flags & kAudioUnitParameterFlag_CFNameRelease) &&
        masterInfo.cfNameString)
      CFRelease(masterInfo.cfNameString);
  }
  for (NSInteger i = 0; i < 7; ++i) {
    NSButton *tab = button(NSMakeRect(i * 109, 0, i == 6 ? 108 : 109, 30), @"",
                           self, @selector(selectTab:));
    tab.bordered = NO;
    tab.tag = i;
    tab.toolTip = @[
      @"Main", @"Générateurs 1–2", @"Générateurs 3–4", @"Filtres", @"Effets",
      @"Modulation", @"Réglages"
    ][i];
    [self addSubview:tab];
  }
  lcd_ = label(NSMakeRect(24, 226, 145, 33), @"", 10);
  lcd_.textColor = NSColor.whiteColor;
  [self addSubview:lcd_];
  [mainControls_ addObject:lcd_];
  NSButton *load = presetButton(NSMakeRect(59, 265, 38, 15), @"Load", self,
                                @selector(choosePreset:));
  load.bordered = NO;
  load.toolTip = @"Charger un preset FXP ou AU";
  [self addSubview:load];
  [mainControls_ addObject:load];
  NSButton *save = presetButton(NSMakeRect(135, 265, 38, 15), @"Save", self,
                                @selector(savePreset:));
  save.bordered = NO;
  save.toolTip = @"Enregistrer le son au format AU";
  [self addSubview:save];
  [mainControls_ addObject:save];
  previousPreset_ = presetButton(NSMakeRect(21, 265, 38, 15), @"Prev", self,
                                 @selector(previousPreset:));
  nextPreset_ = presetButton(NSMakeRect(97, 265, 38, 15), @"Next", self,
                             @selector(nextPreset:));
  for (NSButton *control in @[ previousPreset_, nextPreset_ ]) {
    control.bordered = NO;
    [self addSubview:control];
    [mainControls_ addObject:control];
  }
  previousPreset_.toolTip = @"Son précédent dans le dossier du preset";
  nextPreset_.toolTip = @"Son suivant dans le dossier du preset";
  const char *edits[] = {"Générateurs 1–2", "Générateurs 3–4", "Filtres",
                         "Effets"};
  const NSRect editRects[] = {
      NSMakeRect(161, 111, 29, 14), NSMakeRect(161, 126, 29, 14),
      NSMakeRect(406, 111, 30, 30), NSMakeRect(649, 111, 30, 30)};
  for (int i = 0; i < 4; i++) {
    NSButton *edit = button(editRects[i], @"", self, @selector(editSection:));
    edit.bordered = NO;
    edit.tag = i + 1;
    edit.toolTip = [NSString stringWithUTF8String:edits[i]];
    [self addSubview:edit];
    [mainControls_ addObject:edit];
  }
  preset_ = label(NSMakeRect(16, 358, 350, 21), @"Son : …", 13);
  bank_ = label(NSMakeRect(16, 383, 724, 19), @"", 11);
  message_ = label(NSMakeRect(16, 406, 724, 32), @"", 11);
  activity_ = label(NSMakeRect(16, 446, 365, 18), @"", 10);
  for (NSView *v in @[ preset_, bank_, message_, activity_ ])
    [self addSubview:v];
  footer_ = label(NSMakeRect(16, 465, 730, 11),
                  [NSString stringWithUTF8String:sophistry::editorFooter], 8);
  [self addSubview:footer_];
  [self addSubview:button(NSMakeRect(523, 353, 109, 25), @"Charger un son…",
                          self, @selector(choosePreset:))];
  [self addSubview:button(NSMakeRect(638, 353, 109, 25), @"Banque de sons…",
                          self, @selector(chooseBank:))];
  [self addSubview:button(NSMakeRect(386, 440, 102, 26), @"Recharger", self,
                          @selector(reload:))];
  [self addSubview:button(NSMakeRect(492, 440, 78, 26), @"Écouter", self,
                          @selector(audition:))];
  [self
      addSubview:button(NSMakeRect(575, 440, 173, 26), @"Copier le diagnostic",
                        self, @selector(copyDiagnostic:))];
  [self addSubview:button(NSMakeRect(374, 353, 143, 25), @"Clavier / MIDI…",
                          self, @selector(showAuxiliary:))];
  [self refresh:nil];
  return self;
}
- (void)viewDidMoveToWindow {
  [super viewDidMoveToWindow];
  [timer_ invalidate];
  timer_ = nil;
  if (self.window) {
    __weak SophistryEditorView *weak = self;
    timer_ = [NSTimer timerWithTimeInterval:0.25
                                    repeats:YES
                                      block:^(NSTimer *timer) {
                                        [weak refresh:timer];
                                      }];
    [[NSRunLoop mainRunLoop] addTimer:timer_ forMode:NSRunLoopCommonModes];
  }
}
- (void)dealloc {
  [timer_ invalidate];
  [auxiliaryWindow_ close];
}
- (void)viewWillMoveToWindow:(NSWindow *)window {
  if (!window) {
    [auxiliaryWindow_ close];
    auxiliaryWindow_ = nil;
    auxiliary_ = nil;
  }
  [super viewWillMoveToWindow:window];
}
- (void)drawRect:(NSRect)dirty {
  [[NSColor colorWithCalibratedRed:0.13 green:0.15 blue:0.2 alpha:1] setFill];
  NSRectFill(self.bounds);
  [frame_ drawInRect:NSMakeRect(0, 0, 762, 477)
            fromRect:NSZeroRect
           operation:NSCompositingOperationSourceOver
            fraction:1
      respectFlipped:YES
               hints:nil];
  [panel_ drawInRect:NSMakeRect(0, 37, 762, 290)
            fromRect:NSZeroRect
           operation:NSCompositingOperationSourceOver
            fraction:1
      respectFlipped:YES
               hints:nil];
  [[NSColor colorWithCalibratedRed:0.96 green:0.88 blue:0.4 alpha:1] setFill];
  NSRectFill(NSMakeRect(selectedTab_ * 109 + 10, 29, 88, 2));
}
- (void)selectTab:(NSButton *)sender {
  selectedTab_ = sender.tag;
  panel_ = [self image:200 + selectedTab_];
  for (NSView *view in mainControls_)
    view.hidden = selectedTab_ != 0;
  complete_.page = selectedTab_;
  [complete_ refresh];
  [self refreshParameters];
  self.needsDisplay = YES;
}
- (void)showAuxiliary:(id)sender {
  if (!auxiliaryWindow_) {
    auxiliaryWindow_ = [[NSPanel alloc]
        initWithContentRect:NSMakeRect(0, 0, 762, 170)
                  styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskClosable
                    backing:NSBackingStoreBuffered
                      defer:NO];
    auxiliaryWindow_.title = @"Sophistry — Clavier et sorties MIDI";
    auxiliaryWindow_.releasedWhenClosed = NO;
    SophistryFlippedView *content =
        [[SophistryFlippedView alloc] initWithFrame:NSMakeRect(0, 0, 762, 170)];
    auxiliaryWindow_.contentView = content;
    NSSegmentedControl *tabs =
        [[NSSegmentedControl alloc] initWithFrame:NSMakeRect(12, 5, 380, 25)];
    tabs.segmentCount = 2;
    [tabs setLabel:@"Clavier" forSegment:0];
    [tabs setLabel:@"Sorties / MIDI" forSegment:1];
    tabs.selectedSegment = 0;
    tabs.target = self;
    tabs.action = @selector(auxiliaryTab:);
    [content addSubview:tabs];
    auxiliary_ = [[SophistryCompletePanel alloc] initWithAudioUnit:unit_
                                                            bundle:bundle_];
    auxiliary_.frame = NSMakeRect(0, 35, 762, 130);
    auxiliary_.page = 8;
    auxiliary_.changeTarget = self;
    [content addSubview:auxiliary_];
    NSPopUpButton *midi =
        [[NSPopUpButton alloc] initWithFrame:NSMakeRect(420, 5, 325, 25)];
    [midi addItemWithTitle:@"Apprentissage MIDI…"];
    sophistry::EditorChoices choices;
    UInt32 bytes = sizeof(choices);
    if (!AudioUnitGetProperty(unit_, sophistry::editorChoicesProperty,
                              kAudioUnitScope_Global, 610, &choices, &bytes))
      for (unsigned i = 0; i < choices.count; ++i)
        [midi addItemWithTitle:sophistryCompleteView::string(
                                   choices.labels[i].data(),
                                   choices.labels[i].size())];
    midi.target = auxiliary_;
    midi.action = @selector(midiCommand:);
    [content addSubview:midi];
  }
  [auxiliary_ refresh];
  [auxiliaryWindow_ center];
  [self.window addChildWindow:auxiliaryWindow_ ordered:NSWindowAbove];
  [auxiliaryWindow_ makeKeyAndOrderFront:nil];
}
- (void)auxiliaryTab:(NSSegmentedControl *)sender {
  auxiliary_.page = sender.selectedSegment ? 7 : 8;
  [auxiliary_ refresh];
}
- (void)completeChanged:(id)sender {
  [self refresh:nil];
}
- (void)completeSelectPage:(NSNumber *)page {
  NSButton *tab = [NSButton new];
  tab.tag = std::clamp(page.integerValue, NSInteger(0), NSInteger(6));
  [self selectTab:tab];
}
- (void)editSection:(NSButton *)sender {
  [self selectTab:sender];
}
- (void)controlChanged:(id)sender {
  [self refreshParameters];
}
- (void)parameterChanged:(NSControl *)sender {
  UInt32 id = UInt32(sender.tag);
  if (std::find(parameterIDs_.begin(), parameterIDs_.end(), id) ==
      parameterIDs_.end())
    return;
  float value = sender.floatValue;
  event(unit_, id, kAudioUnitEvent_BeginParameterChangeGesture);
  if (!AudioUnitSetParameter(unit_, id, kAudioUnitScope_Global, 0, value, 0))
    event(unit_, id, kAudioUnitEvent_ParameterValueChange);
  event(unit_, id, kAudioUnitEvent_EndParameterChangeGesture);
  [self refreshParameters];
}
- (void)refreshParameters {
  [complete_ refresh];
  if (auxiliaryWindow_.visible)
    [auxiliary_ refresh];
  float masterValue = 0;
  if (master_ && !AudioUnitGetParameter(unit_, 134, kAudioUnitScope_Global, 0,
                                        &masterValue)) {
    master_.floatValue = masterValue;
    masterValue_.stringValue =
        [valueText(unit_, 134, masterValue) stringByAppendingString:@" dB"];
  }
}

- (void)refresh:(NSTimer *)timer {
  NSDictionary *s = status(unit_);
  NSDictionary *engine = s[@"engine"];
  if (!s.count) {
    message_.stringValue =
        @"Le diagnostic de cette instance n’est pas disponible.";
    return;
  }
  NSString *name = s[@"preset_name"];
  if (!name.length || [name isEqualToString:@"empty"])
    name = [s[@"state_loaded"] boolValue]
               ? @"État chargé — nom non enregistré"
               : ([s[@"error"] length] ? @"Chargement interrompu"
                                       : @"Aucun son chargé");
  preset_.stringValue = [@"Son : " stringByAppendingString:name];
  lcd_.stringValue = name;
  NSArray *roots = engine[@"asset_roots"];
  NSDictionary *root = roots.count ? roots[0] : nil;
  bank_.stringValue =
      [NSString stringWithFormat:@"Banque : %@ — %@ fichiers indexés%@",
                                 root[@"name"] ?: @"aucune",
                                 engine[@"asset_index_unique_names"] ?: @0,
                                 [root[@"readable"] boolValue]
                                     ? @""
                                     : @" — dossier inaccessible"];
  NSMutableArray *missing = [NSMutableArray array];
  for (NSDictionary *file in engine[@"asset_open_results"])
    if (![file[@"opened"] boolValue])
      [missing addObject:file[@"name"] ?: @"?"];
  NSString *message = @"Son chargé. Jouez sur la piste pour écouter.";
  if (![engine[@"active"] boolValue])
    message = @"Activez la piste pour vérifier son fonctionnement.";
  else if (![engine[@"registration_accepted"] boolValue])
    message = @"L’enregistrement local n’est pas reconnu dans cet hôte.";
  else if (missing.count)
    message = [@"Samples introuvables : "
        stringByAppendingString:[missing componentsJoinedByString:@", "]];
  else if ([s[@"error"] length])
    message = [s[@"error"] containsString:@"PCM converter"]
                  ? @"Le format audio d’un sample n’est pas encore pris en "
                    @"charge. Copiez le diagnostic."
                  : @"Le chargement du son a échoué. Copiez le diagnostic pour "
                    @"identifier la cause.";
  else if ([engine[@"load_alerts"] count])
    message = @"Le moteur d’origine signale une erreur de chargement. Copiez "
              @"le diagnostic.";
  else if ([s[@"nonfinite_samples"] unsignedLongLongValue])
    message =
        @"Une erreur de calcul empêche le rendu du son. Copiez le diagnostic.";
  else if (![s[@"state_loaded"] boolValue])
    message = @"Aucun état de son restauré. Chargez un preset avec « Charger "
              @"un son… ».";
  else if ([s[@"notes_received"] unsignedLongLongValue] &&
           [s[@"maximum_output"] doubleValue] < 0.00001)
    message = @"Le moteur reçoit les notes, mais sa sortie reste silencieuse. "
              @"Copiez le diagnostic.";
  message_.stringValue = message;
  message_.toolTip = message;
  activity_.stringValue = [NSString
      stringWithFormat:@"Licence : %@   MIDI : %@ notes   Sortie : %.5g",
                       [engine[@"registration_accepted"] boolValue]
                           ? @"reconnue"
                           : @"à vérifier",
                       s[@"notes_received"] ?: @0,
                       [s[@"maximum_output"] doubleValue]];
  [self refreshParameters];
}
- (void)showError:(NSString *)message {
  NSAlert *alert = [NSAlert new];
  alert.messageText = @"Sophistry";
  alert.informativeText = message;
  if (self.window)
    [alert beginSheetModalForWindow:self.window completionHandler:nil];
  else
    [alert runModal];
}
- (BOOL)loadPresetURL:(NSURL *)url {
  NSData *data = [NSData dataWithContentsOfURL:url];
  if (!data)
    return NO;
  OSStatus result = kAudioUnitErr_InvalidPropertyValue;
  if ([url.pathExtension.lowercaseString isEqualToString:@"aupreset"]) {
    id state = [NSPropertyListSerialization
        propertyListWithData:data
                     options:NSPropertyListImmutable
                      format:nil
                       error:nil];
    if ([state isKindOfClass:NSDictionary.class]) {
      CFPropertyListRef plist = (__bridge CFPropertyListRef)state;
      result = AudioUnitSetProperty(unit_, kAudioUnitProperty_ClassInfo,
                                    kAudioUnitScope_Global, 0, &plist,
                                    sizeof(plist));
    }
  } else if (data.length >= 60) {
    const unsigned char *b = (const unsigned char *)data.bytes;
    UInt32 length = (UInt32(b[56]) << 24) | (UInt32(b[57]) << 16) |
                    (UInt32(b[58]) << 8) | b[59];
    if (!memcmp(b, "CcnK", 4) && !memcmp(b + 8, "FPCh", 4) &&
        length == data.length - 60) {
      NSData *chunk = [data subdataWithRange:NSMakeRange(60, length)];
      result = AudioUnitSetProperty(unit_, sophistry::importProgramProperty,
                                    kAudioUnitScope_Global, 0, chunk.bytes,
                                    UInt32(chunk.length));
      if (!result) {
        // FPCh stores the program label outside the opaque engine chunk.
        // Preserve it as standard AU preset metadata without altering DSP.
        const auto n = strnlen(reinterpret_cast<const char *>(b + 28), 28);
        NSString *name = [[NSString alloc] initWithBytes:b + 28
                                                  length:n
                                                encoding:NSUTF8StringEncoding];
        if (!name)
          name = [[NSString alloc] initWithBytes:b + 28
                                          length:n
                                        encoding:NSMacOSRomanStringEncoding];
        if (!name.length)
          name = url.lastPathComponent.stringByDeletingPathExtension;
        AUPreset preset{-1, (__bridge CFStringRef)name};
        result = AudioUnitSetProperty(unit_, kAudioUnitProperty_PresentPreset,
                                      kAudioUnitScope_Global, 0, &preset,
                                      sizeof(preset));
      }
    }
  }
  [self refresh:nil];
  if (!result) {
    lastPresetURL_ = url.URLByStandardizingPath;
    lastPresetLabel_ = [status(unit_)[@"preset_name"] copy];
  }
  return result == noErr;
}
- (void)previousPreset:(id)sender {
  [self navigatePreset:-1];
}
- (void)nextPreset:(id)sender {
  [self navigatePreset:1];
}
- (void)navigatePreset:(NSInteger)direction {
  if (presetNavigationBusy_)
    return;
  NSString *name = status(unit_)[@"preset_name"] ?: @"";
  if (lastPresetURL_ && [lastPresetLabel_ isEqualToString:name]) {
    NSURL *next = sophistryPresetBrowser::adjacent(
        sophistryPresetBrowser::directory(
            lastPresetURL_.URLByDeletingLastPathComponent),
        lastPresetURL_, direction);
    if (next) {
      if (![self loadPresetURL:next])
        [self showError:@"Le preset voisin n’a pas pu être chargé. Copiez le "
                        @"diagnostic."];
      return;
    }
  }
  if (!name.length || [name isEqualToString:@"empty"] ||
      [name caseInsensitiveCompare:@"Default"] == NSOrderedSame ||
      [name caseInsensitiveCompare:@"Défaut"] == NSOrderedSame) {
    [self choosePreset:nil];
    return;
  }
  CFPropertyListRef saved = CFPreferencesCopyValue(
      CFSTR("SophistryARMSampleRoot"), CFSTR("com.linplug.Sophistry"),
      kCFPreferencesCurrentUser, kCFPreferencesAnyHost);
  NSString *path = saved && CFGetTypeID(saved) == CFStringGetTypeID()
                       ? [(__bridge NSString *)saved copy]
                       : nil;
  if (saved)
    CFRelease(saved);
  if (!path.length) {
    [self choosePreset:nil];
    return;
  }
  presetNavigationBusy_ = YES;
  previousPreset_.enabled = nextPreset_.enabled = NO;
  __weak SophistryEditorView *weak = self;
  dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
    NSURL *match = sophistryPresetBrowser::find(
        [NSURL fileURLWithPath:path isDirectory:YES], name);
    dispatch_async(dispatch_get_main_queue(), ^{
      SophistryEditorView *view = weak;
      if (!view)
        return;
      view->presetNavigationBusy_ = NO;
      view->previousPreset_.enabled = view->nextPreset_.enabled = YES;
      if (![status(view->unit_)[@"preset_name"] isEqualToString:name])
        return;
      if (match) {
        NSURL *next = sophistryPresetBrowser::adjacent(
            sophistryPresetBrowser::directory(
                match.URLByDeletingLastPathComponent),
            match, direction);
        if (next) {
          if (![view loadPresetURL:next])
            [view showError:@"Le preset voisin n’a pas pu être chargé. Copiez "
                            @"le diagnostic."];
        } else
          [view choosePreset:nil];
      } else
        [view choosePreset:nil];
    });
  });
}
- (void)choosePreset:(id)sender {
  NSOpenPanel *panel = [NSOpenPanel openPanel];
  panel.allowedFileTypes = @[ @"fxp", @"aupreset" ];
  panel.allowsMultipleSelection = NO;
  panel.title = @"Charger un son Sophistry";
  panel.message =
      @"Prev et Next parcourront les presets du dossier du son choisi.";
  if (lastPresetURL_)
    panel.directoryURL = lastPresetURL_.URLByDeletingLastPathComponent;
  [panel
      beginSheetModalForWindow:self.window
             completionHandler:^(NSModalResponse result) {
               if (result == NSModalResponseOK &&
                   ![self loadPresetURL:panel.URL])
                 [self showError:
                           @"Ce preset n’a pas pu être chargé. Le diagnostic "
                           @"contient le résultat du chargement."];
             }];
}
- (void)chooseBank:(id)sender {
  NSOpenPanel *panel = [NSOpenPanel openPanel];
  panel.canChooseFiles = NO;
  panel.canChooseDirectories = YES;
  panel.allowsMultipleSelection = NO;
  panel.title = @"Banque de sons Sophistry";
  panel.message = @"Choisissez le dossier contenant tous les samples "
                  @"d’origine. Le son du projet sera rechargé ensuite.";
  [panel
      beginSheetModalForWindow:self.window
             completionHandler:^(NSModalResponse result) {
               if (result != NSModalResponseOK)
                 return;
               NSData *path =
                   [panel.URL.path dataUsingEncoding:NSUTF8StringEncoding];
               NSData *bookmark =
                   CFBridgingRelease(sophistryMac::createBankBookmark(
                       (__bridge CFURLRef)panel.URL));
               sophistry::BankLocationHeader header{1, UInt32(path.length + 1),
                                                    UInt32(bookmark.length)};
               NSMutableData *terminated =
                   [NSMutableData dataWithBytes:&header length:sizeof(header)];
               [terminated appendData:path];
               unsigned char zero = 0;
               [terminated appendBytes:&zero length:1];
               if (bookmark)
                 [terminated appendData:bookmark];
               OSStatus s = AudioUnitSetProperty(
                   self->unit_, sophistry::sampleRootProperty,
                   kAudioUnitScope_Global, 0, terminated.bytes,
                   UInt32(terminated.length));
               [self refresh:nil];
               if (s)
                 [self showError:@"La banque n’a pas pu être sélectionnée "
                                 @"ou le son rechargé. Copiez le diagnostic "
                                 @"pour examiner les samples demandés."];
             }];
}
- (void)reload:(id)sender {
  UInt32 request = 1;
  OSStatus s = AudioUnitSetProperty(unit_, sophistry::reloadStateProperty,
                                    kAudioUnitScope_Global, 0, &request,
                                    sizeof(request));
  [self refresh:nil];
  if (s)
    [self showError:@"Aucun état de son rechargeable n’est disponible, ou le "
                    @"chargement a échoué."];
}
- (void)audition:(id)sender {
  MusicDeviceMIDIEvent(unit_, 0x90, 60, 100, 0);
  __weak SophistryEditorView *weak = self;
  dispatch_after(dispatch_time(DISPATCH_TIME_NOW, NSEC_PER_SEC),
                 dispatch_get_main_queue(), ^{
                   SophistryEditorView *view = weak;
                   if (view)
                     MusicDeviceMIDIEvent(view->unit_, 0x80, 60, 0, 0);
                 });
}
- (void)copyDiagnostic:(id)sender {
  NSDictionary *s = status(unit_);
  NSData *data =
      [NSJSONSerialization dataWithJSONObject:s
                                      options:NSJSONWritingPrettyPrinted
                                        error:nil];
  NSString *text = [[NSString alloc] initWithData:data
                                         encoding:NSUTF8StringEncoding];
  if (text) {
    [NSPasteboard.generalPasteboard clearContents];
    [NSPasteboard.generalPasteboard setString:text
                                      forType:NSPasteboardTypeString];
  }
}
- (void)savePreset:(id)sender {
  CFPropertyListRef state = nullptr;
  UInt32 size = sizeof(state);
  if (AudioUnitGetProperty(unit_, kAudioUnitProperty_ClassInfo,
                           kAudioUnitScope_Global, 0, &state, &size) ||
      !state)
    return;
  NSData *data = [NSPropertyListSerialization
      dataWithPropertyList:(__bridge id)state
                    format:NSPropertyListXMLFormat_v1_0
                   options:0
                     error:nil];
  CFRelease(state);
  if (!data)
    return;
  NSSavePanel *panel = [NSSavePanel savePanel];
  panel.allowedFileTypes = @[ @"aupreset" ];
  panel.nameFieldStringValue = @"Sophistry.aupreset";
  [panel beginSheetModalForWindow:self.window
                completionHandler:^(NSModalResponse result) {
                  if (result == NSModalResponseOK) {
                    BOOL ok = [data writeToURL:panel.URL atomically:YES];
                    if (!ok)
                      [self showError:@"Le preset n’a pas pu être enregistré."];
                  }
                }];
}
- (NSDictionary *)sophistryEditorReport {
  [self refresh:nil];
  NSUInteger images = [complete_ mainSpriteCount];
  NSMutableArray *captions = [NSMutableArray array];
  for (NSView *v in mainControls_)
    if ([v isKindOfClass:SophistryPresetButton.class])
      [captions addObject:((NSButton *)v).title];
  return @{
    @"editor_footer" : footer_.stringValue,
    @"preset_name_is_white" : @([lcd_.textColor isEqual:NSColor.whiteColor]),
    @"white_preset_button_captions" : captions,
    @"parameter_count" : @(parameterIDs_.size()),
    @"main_dial_count" : @([complete_ mainDialCount]),
    @"background_images_loaded" : @(frame_ && panel_),
    @"sprite_images_loaded" : @(images),
    @"visible_original_control_count" :
        @([[complete_ report][@"controls"] count]),
    @"generic_parameter_browser_present" : @(hasGenericBrowser(self)),
    @"size" : @[ @(self.frame.size.width), @(self.frame.size.height) ],
    @"generator_panel" : [complete_ generatorReport],
    @"original_panel" : [complete_ report],
    @"selected_tab" : @(selectedTab_),
    @"last_click" : lastClick_ ?: @{},
    @"preset_navigation_busy" : @(presetNavigationBusy_),
    @"source_preset_file" : lastPresetURL_.lastPathComponent ?: @"",
    @"status" : status(unit_)
  };
}
- (BOOL)testGeneratorControl:(UInt32)tag normalized:(float)value {
  return (selectedTab_ == 1 || selectedTab_ == 2) &&
         [complete_ setControl:tag normalized:value];
}
- (BOOL)testCompleteControl:(UInt32)tag normalized:(float)value {
  return [complete_ setControl:tag normalized:value];
}
- (BOOL)testCompleteText:(UInt32)tag value:(NSString *)value {
  return [complete_ setText:tag value:value];
}
- (NSDictionary *)testAuxiliaryPage:(unsigned)page snapshot:(NSString *)path {
  if (page != 7 && page != 8)
    return @{};
  [self showAuxiliary:nil];
  auxiliary_.page = page;
  [auxiliary_ refresh];
  NSBitmapImageRep *rep =
      [auxiliary_ bitmapImageRepForCachingDisplayInRect:auxiliary_.bounds];
  BOOL saved = NO;
  if (rep) {
    [auxiliary_ cacheDisplayInRect:auxiliary_.bounds toBitmapImageRep:rep];
    saved = [[rep representationUsingType:NSBitmapImageFileTypePNG
                               properties:@{}] writeToFile:path atomically:YES];
  }
  NSMutableDictionary *report = [[auxiliary_ report] mutableCopy];
  report[@"snapshot_saved"] = @(saved);
  [auxiliaryWindow_ orderOut:nil];
  return report;
}
- (BOOL)testGeneratorRoutingClick:(unsigned)slot {
  if ((selectedTab_ != 1 && selectedTab_ != 2) || slot > 2 || !self.window)
    return NO;
  // Probe the original screen coordinates, independently of the node layout.
  NSPoint point = NSMakePoint(82 + 15, 37 + 86 + slot * 18 + 9);
  NSView *hit = [self controlAtPoint:point];
  if (![hit isKindOfClass:SophistryGeneratorNode.class] ||
      ((SophistryGeneratorNode *)hit).spec.widget !=
          sophistry::GeneratorWidget::Routing)
    return NO;
  NSEvent *click = [NSEvent mouseEventWithType:NSEventTypeLeftMouseDown
                                      location:[self convertPoint:point
                                                           toView:nil]
                                 modifierFlags:0
                                     timestamp:0
                                  windowNumber:self.window.windowNumber
                                       context:nil
                                   eventNumber:0
                                    clickCount:1
                                      pressure:1];
  [hit mouseDown:click];
  return YES;
}
- (NSView *)controlAtPoint:(NSPoint)point {
  NSPoint superPoint = [self convertPoint:point toView:self.superview];
  NSView *hit = [self hitTest:superPoint];
  lastClick_ = @{
    @"point" : @[ @(point.x), @(point.y) ],
    @"superview_point" : @[ @(superPoint.x), @(superPoint.y) ],
    @"hit_class" : hit ? NSStringFromClass(hit.class) : @"none",
    @"hit_tag" : @(hit ? hit.tag : -1)
  };
  return hit;
}
- (BOOL)testEditorButtonAtX:(double)x y:(double)y {
  NSView *hit = [self controlAtPoint:NSMakePoint(x, y)];
  if (![hit isKindOfClass:NSButton.class] || !((NSButton *)hit).enabled)
    return NO;
  [(NSButton *)hit performClick:nil];
  return YES;
}
- (BOOL)testOriginalControlAtX:(double)x y:(double)y normalized:(float)value {
  NSView *hit = [self controlAtPoint:NSMakePoint(x, y)];
  return [hit isKindOfClass:SophistryGeneratorNode.class] &&
         [(SophistryGeneratorNode *)hit activateNormalized:value];
}
- (BOOL)testOriginalXYAtX:(double)x
                        y:(double)y
              normalizedX:(float)nx
              normalizedY:(float)ny {
  NSView *hit = [self controlAtPoint:NSMakePoint(x, y)];
  return [hit isKindOfClass:SophistryOriginalXY.class] &&
         [(SophistryOriginalXY *)hit activateX:nx y:ny];
}
@end

@interface SophistryCocoaFactory : NSObject <AUCocoaUIBase>
@end
@implementation SophistryCocoaFactory
- (unsigned)interfaceVersion {
  return 0;
}
- (NSString *)description {
  return @"Sophistry";
}
- (NSView *)uiViewForAudioUnit:(AudioUnit)unit withSize:(NSSize)size {
  return [[SophistryEditorView alloc] initWithAudioUnit:unit];
}
@end
