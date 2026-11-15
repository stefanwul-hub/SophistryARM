// Native Cocoa view. Original panel/knob images are drawn directly; the
// parameter browser uses the original AU IDs and value-string property.
#include "BankAccess.h"
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
} // namespace

@interface SophistryParameter : NSObject
@property UInt32 identifier;
@property float minimum, maximum, defaultValue;
@property UInt32 unit, flags;
@property(copy) NSString *name;
@property(strong) NSArray<NSString *> *choices;
@end
@implementation SophistryParameter
@end

@interface SophistryDial : NSControl
@property AudioUnit audioUnit;
@property(strong) SophistryParameter *parameter;
@property(strong) NSImage *sprite;
@property NSUInteger frames;
@property float value;
- (void)refresh;
@end
@implementation SophistryDial
- (BOOL)isFlipped {
  return YES;
}
- (BOOL)acceptsFirstResponder {
  return YES;
}
- (void)refresh {
  float value = 0;
  if (!AudioUnitGetParameter(_audioUnit, _parameter.identifier,
                             kAudioUnitScope_Global, 0, &value)) {
    if (value != _value) {
      _value = value;
      self.needsDisplay = YES;
    }
    self.toolTip = [NSString
        stringWithFormat:@"%@ : %@", _parameter.name,
                         valueText(_audioUnit, _parameter.identifier, value)];
    self.accessibilityLabel = _parameter.name;
    self.accessibilityValue = @(value);
  }
}
- (void)drawRect:(NSRect)dirty {
  if (!_sprite || !_frames)
    return;
  const double range = _parameter.maximum - _parameter.minimum;
  const double normalized =
      range > 0
          ? std::clamp(double((_value - _parameter.minimum) / range), 0.0, 1.0)
          : 0;
  const NSUInteger frame = NSUInteger(std::lround(normalized * (_frames - 1)));
  const CGFloat height = _sprite.size.height / _frames;
  [_sprite drawInRect:self.bounds
             fromRect:NSMakeRect(0, _sprite.size.height - (frame + 1) * height,
                                 _sprite.size.width, height)
            operation:NSCompositingOperationSourceOver
             fraction:1
       respectFlipped:YES
                hints:nil];
}
- (void)setFromNormalized:(double)value {
  value = std::clamp(value, 0.0, 1.0);
  float physical =
      _parameter.minimum + value * (_parameter.maximum - _parameter.minimum);
  if (!AudioUnitSetParameter(_audioUnit, _parameter.identifier,
                             kAudioUnitScope_Global, 0, physical, 0)) {
    event(_audioUnit, _parameter.identifier,
          kAudioUnitEvent_ParameterValueChange);
    [self refresh];
    [self sendAction:self.action to:self.target];
  }
}
- (void)mouseDown:(NSEvent *)down {
  [self.window makeFirstResponder:self];
  event(_audioUnit, _parameter.identifier,
        kAudioUnitEvent_BeginParameterChangeGesture);
  if (down.modifierFlags & NSEventModifierFlagCommand) {
    AudioUnitSetParameter(_audioUnit, _parameter.identifier,
                          kAudioUnitScope_Global, 0, _parameter.defaultValue,
                          0);
    event(_audioUnit, _parameter.identifier,
          kAudioUnitEvent_ParameterValueChange);
    [self refresh];
  } else {
    const double range = _parameter.maximum - _parameter.minimum;
    double initial = range > 0 ? (_value - _parameter.minimum) / range : 0;
    NSPoint origin = down.locationInWindow;
    for (;;) {
      NSEvent *next =
          [self.window nextEventMatchingMask:NSEventMaskLeftMouseDragged |
                                             NSEventMaskLeftMouseUp];
      if (!next || next.type == NSEventTypeLeftMouseUp)
        break;
      double sensitivity =
          (next.modifierFlags & NSEventModifierFlagOption) ? 600 : 150;
      [self setFromNormalized:initial + (next.locationInWindow.y - origin.y) /
                                            sensitivity];
      [self displayIfNeeded];
    }
  }
  event(_audioUnit, _parameter.identifier,
        kAudioUnitEvent_EndParameterChangeGesture);
}
- (void)scrollWheel:(NSEvent *)input {
  const double range = _parameter.maximum - _parameter.minimum;
  if (range <= 0)
    return;
  event(_audioUnit, _parameter.identifier,
        kAudioUnitEvent_BeginParameterChangeGesture);
  [self setFromNormalized:(_value - _parameter.minimum) / range +
                          input.scrollingDeltaY / 200];
  event(_audioUnit, _parameter.identifier,
        kAudioUnitEvent_EndParameterChangeGesture);
}
@end

@interface SophistryFlippedView : NSView
@end
@implementation SophistryFlippedView
- (BOOL)isFlipped {
  return YES;
}
@end

@interface SophistryEditorView : SophistryFlippedView <NSSearchFieldDelegate>
- (instancetype)initWithAudioUnit:(AudioUnit)unit;
- (BOOL)loadPresetURL:(NSURL *)url;
- (NSDictionary *)sophistryEditorReport;
@end

@implementation SophistryEditorView {
  AudioUnit unit_;
  NSBundle *bundle_;
  NSImage *frame_, *panel_;
  NSInteger selectedTab_;
  NSMutableArray<SophistryParameter *> *parameters_;
  NSMutableArray<SophistryDial *> *dials_;
  NSMutableDictionary<NSNumber *, NSControl *> *rows_;
  NSMutableDictionary<NSNumber *, NSTextField *> *values_;
  NSMutableArray<NSView *> *mainControls_;
  NSTextField *preset_, *bank_, *message_, *activity_, *lcd_;
  NSSlider *master_;
  NSTextField *masterValue_;
  NSSearchField *search_;
  NSScrollView *scroll_;
  SophistryFlippedView *document_;
  NSTimer *timer_;
  NSString *lastJSON_;
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
  if (!(self = [super initWithFrame:NSMakeRect(0, 0, 1120, 477)]))
    return nil;
  unit_ = unit;
  bundle_ = [NSBundle bundleForClass:self.class];
  parameters_ = [NSMutableArray array];
  dials_ = [NSMutableArray array];
  mainControls_ = [NSMutableArray array];
  rows_ = [NSMutableDictionary dictionary];
  values_ = [NSMutableDictionary dictionary];
  UInt32 size = 0;
  Boolean writable = NO;
  if (!AudioUnitGetPropertyInfo(unit_, kAudioUnitProperty_ParameterList,
                                kAudioUnitScope_Global, 0, &size, &writable) &&
      size < 8192) {
    std::vector<UInt32> ids(size / sizeof(UInt32));
    if (!AudioUnitGetProperty(unit_, kAudioUnitProperty_ParameterList,
                              kAudioUnitScope_Global, 0, ids.data(), &size)) {
      for (UInt32 identifier : ids) {
        AudioUnitParameterInfo info{};
        UInt32 n = sizeof(info);
        if (AudioUnitGetProperty(unit_, kAudioUnitProperty_ParameterInfo,
                                 kAudioUnitScope_Global, identifier, &info, &n))
          continue;
        SophistryParameter *p = [SophistryParameter new];
        p.identifier = identifier;
        p.name = info.cfNameString
                     ? string(info.cfNameString)
                     : ([NSString stringWithUTF8String:info.name] ?: @"");
        p.minimum = info.minValue;
        p.maximum = info.maxValue;
        p.defaultValue = info.defaultValue;
        p.unit = info.unit;
        p.flags = info.flags;
        if ((info.flags & kAudioUnitParameterFlag_CFNameRelease) &&
            info.cfNameString)
          CFRelease(info.cfNameString);
        if ((info.flags & kAudioUnitParameterFlag_ValuesHaveStrings) &&
            info.unit != kAudioUnitParameterUnit_Decibels) {
          CFArrayRef array = nullptr;
          UInt32 bytes = sizeof(array);
          if (!AudioUnitGetProperty(
                  unit_, kAudioUnitProperty_ParameterValueStrings,
                  kAudioUnitScope_Global, identifier, &array, &bytes) &&
              array) {
            p.choices = [(__bridge NSArray *)array copy];
            CFRelease(array);
          }
        }
        [parameters_ addObject:p];
      }
    }
  }
  frame_ = [self image:128];
  panel_ = [self image:200];
  for (SophistryParameter *p in parameters_) {
    if (p.identifier != 134)
      continue;
    master_ = [[NSSlider alloc] initWithFrame:NSMakeRect(591, 330, 151, 17)];
    master_.minValue = p.minimum;
    master_.maxValue = p.maximum;
    master_.continuous = YES;
    master_.tag = 134;
    master_.target = self;
    master_.action = @selector(parameterChanged:);
    master_.toolTip = @"Volume principal";
    masterValue_ = label(NSMakeRect(487, 329, 67, 19), @"", 11);
    [self addSubview:master_];
    [self addSubview:masterValue_];
    break;
  }
  for (NSInteger i = 0; i < 7; ++i) {
    NSButton *tab = button(NSMakeRect(i * 109, 0, 109, 30), @"", self,
                           @selector(selectTab:));
    tab.bordered = NO;
    tab.tag = i;
    tab.toolTip = @[
      @"Main", @"Générateurs 1–2", @"Générateurs 3–4", @"Filtres", @"Effets",
      @"Modulation", @"Réglages"
    ][i];
    [self addSubview:tab];
  }
  // Main control centers/styles are from KajaEditor 0x57fe0/0x57ef8.
  const struct {
    UInt32 id, sprite, frames;
    int x, y, w, h;
  } knobs[] = {
      {484, 360, 42, 144, 94, 58, 57},  {485, 361, 42, 206, 94, 58, 57},
      {486, 362, 42, 144, 156, 58, 57}, {487, 363, 42, 206, 156, 58, 57},
      {114, 364, 42, 389, 94, 58, 57},  {115, 366, 42, 389, 156, 58, 57},
      {116, 365, 42, 451, 94, 58, 57},  {117, 367, 42, 451, 156, 58, 57},
      {492, 356, 41, 663, 94, 120, 57}, {493, 355, 41, 663, 156, 120, 57},
      {494, 352, 51, 250, 284, 73, 36}, {495, 352, 51, 336, 284, 73, 36},
      {496, 352, 51, 422, 284, 73, 36}, {497, 352, 51, 508, 284, 73, 36},
      {480, 350, 71, 692, 263, 33, 33}};
  for (auto spec : knobs) {
    SophistryParameter *parameter = nil;
    for (SophistryParameter *p in parameters_)
      if (p.identifier == spec.id) {
        parameter = p;
        break;
      }
    if (!parameter)
      continue;
    SophistryDial *dial = [[SophistryDial alloc]
        initWithFrame:NSMakeRect(spec.x - spec.w / 2, spec.y - spec.h / 2,
                                 spec.w, spec.h)];
    dial.parameter = parameter;
    dial.audioUnit = unit_;
    dial.sprite = [self image:spec.sprite];
    dial.frames = spec.frames;
    dial.target = self;
    dial.action = @selector(controlChanged:);
    [dial refresh];
    [dials_ addObject:dial];
    [mainControls_ addObject:dial];
    [self addSubview:dial];
  }
  lcd_ = label(NSMakeRect(24, 226, 145, 33), @"", 10);
  lcd_.textColor = [NSColor colorWithWhite:0.1 alpha:1];
  [self addSubview:lcd_];
  [mainControls_ addObject:lcd_];
  NSButton *load =
      button(NSMakeRect(59, 264, 38, 16), @"", self, @selector(choosePreset:));
  load.bordered = NO;
  load.toolTip = @"Charger un preset FXP ou AU";
  [self addSubview:load];
  [mainControls_ addObject:load];
  NSButton *save =
      button(NSMakeRect(135, 264, 38, 16), @"", self, @selector(savePreset:));
  save.bordered = NO;
  save.toolTip = @"Enregistrer le son au format AU";
  [self addSubview:save];
  [mainControls_ addObject:save];
  const char *edits[] = {"Générateurs", "Filtres", "Effets"};
  for (int i = 0; i < 3; i++) {
    NSButton *edit = button(NSMakeRect((int[]){161, 375, 649}[i], 111, 30, 30),
                            @"", self, @selector(editSection:));
    edit.bordered = NO;
    edit.tag = (int[]){1, 3, 4}[i];
    edit.toolTip = [NSString stringWithUTF8String:edits[i]];
    [self addSubview:edit];
    [mainControls_ addObject:edit];
  }
  preset_ = label(NSMakeRect(16, 358, 504, 21), @"Son : …", 13);
  bank_ = label(NSMakeRect(16, 383, 724, 19), @"", 11);
  message_ = label(NSMakeRect(16, 406, 724, 32), @"", 11);
  activity_ = label(NSMakeRect(16, 446, 365, 18), @"", 10);
  for (NSView *v in @[ preset_, bank_, message_, activity_ ])
    [self addSubview:v];
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
  NSTextField *title =
      label(NSMakeRect(780, 12, 316, 21), @"Commandes du son", 15);
  [self addSubview:title];
  search_ = [[NSSearchField alloc] initWithFrame:NSMakeRect(780, 43, 322, 25)];
  search_.placeholderString = @"Rechercher un paramètre…";
  search_.delegate = self;
  [self addSubview:search_];
  scroll_ = [[NSScrollView alloc] initWithFrame:NSMakeRect(774, 80, 338, 383)];
  scroll_.hasVerticalScroller = YES;
  scroll_.drawsBackground = NO;
  document_ =
      [[SophistryFlippedView alloc] initWithFrame:NSMakeRect(0, 0, 320, 383)];
  scroll_.documentView = document_;
  [self addSubview:scroll_];
  [self buildRows];
  [self refresh:nil];
  return self;
}
- (BOOL)included:(SophistryParameter *)p {
  if (search_.stringValue.length)
    return [p.name rangeOfString:search_.stringValue
                         options:NSCaseInsensitiveSearch |
                                 NSDiacriticInsensitiveSearch]
               .location != NSNotFound;
  UInt32 id = p.identifier;
  switch (selectedTab_) {
  case 0:
    return id == 134 || (id >= 480 && id <= 497) || (id >= 4 && id <= 11) ||
           (id >= 114 && id <= 117);
  case 1:
    return id < 108 && id % 4 < 2;
  case 2:
    return id < 108 && id % 4 >= 2;
  case 3:
    return id >= 108 && id < 134;
  case 4:
    return id >= 213 && id < 480;
  case 5:
    return id >= 135 && id < 213;
  case 6:
    return id == 134 || id >= 510;
  }
  return NO;
}
- (void)buildRows {
  for (NSView *v in document_.subviews.copy)
    [v removeFromSuperview];
  [rows_ removeAllObjects];
  [values_ removeAllObjects];
  CGFloat y = 0;
  for (SophistryParameter *p in parameters_) {
    if (![self included:p])
      continue;
    NSTextField *name = label(NSMakeRect(5, y, 305, 17), p.name, 11);
    [document_ addSubview:name];
    NSControl *control;
    if (p.choices.count) {
      NSPopUpButton *menu =
          [[NSPopUpButton alloc] initWithFrame:NSMakeRect(3, y + 17, 211, 23)
                                     pullsDown:NO];
      NSMenu *choices = [NSMenu new];
      choices.autoenablesItems = NO;
      for (NSString *choice in p.choices) {
        NSString *title = [choice
            stringByTrimmingCharactersInSet:NSCharacterSet
                                                .whitespaceCharacterSet];
        [choices addItem:[[NSMenuItem alloc] initWithTitle:title
                                                    action:nullptr
                                             keyEquivalent:@""]];
      }
      menu.menu = choices;
      menu.font = [NSFont systemFontOfSize:10];
      control = menu;
    } else {
      NSSlider *slider =
          [[NSSlider alloc] initWithFrame:NSMakeRect(5, y + 18, 207, 20)];
      slider.minValue = p.minimum;
      slider.maxValue = p.maximum;
      slider.continuous = YES;
      control = slider;
    }
    control.tag = p.identifier;
    control.target = self;
    control.action = @selector(parameterChanged:);
    rows_[@(p.identifier)] = control;
    [document_ addSubview:control];
    NSTextField *value = label(NSMakeRect(219, y + 18, 95, 20), @"", 10);
    values_[@(p.identifier)] = value;
    [document_ addSubview:value];
    y += 48;
  }
  document_.frame = NSMakeRect(0, 0, 320, MAX(383, y));
  [scroll_.contentView scrollToPoint:NSZeroPoint];
  [self refreshParameters];
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
  search_.stringValue = @"";
  [self buildRows];
  self.needsDisplay = YES;
}
- (void)editSection:(NSButton *)sender {
  [self selectTab:sender];
}
- (void)controlTextDidChange:(NSNotification *)note {
  [self buildRows];
}
- (void)controlChanged:(id)sender {
  [self refreshParameters];
}
- (void)parameterChanged:(NSControl *)sender {
  UInt32 id = UInt32(sender.tag);
  SophistryParameter *p = nil;
  for (SophistryParameter *candidate in parameters_)
    if (candidate.identifier == id) {
      p = candidate;
      break;
    }
  if (!p)
    return;
  float value = [sender isKindOfClass:NSPopUpButton.class]
                    ? p.minimum + [(NSPopUpButton *)sender indexOfSelectedItem]
                    : sender.floatValue;
  event(unit_, id, kAudioUnitEvent_BeginParameterChangeGesture);
  if (!AudioUnitSetParameter(unit_, id, kAudioUnitScope_Global, 0, value, 0))
    event(unit_, id, kAudioUnitEvent_ParameterValueChange);
  event(unit_, id, kAudioUnitEvent_EndParameterChangeGesture);
  [self refreshParameters];
}
- (void)refreshParameters {
  float masterValue = 0;
  if (master_ && !AudioUnitGetParameter(unit_, 134, kAudioUnitScope_Global, 0,
                                        &masterValue)) {
    master_.floatValue = masterValue;
    masterValue_.stringValue =
        [valueText(unit_, 134, masterValue) stringByAppendingString:@" dB"];
  }
  for (SophistryDial *dial in dials_)
    if (!dial.hidden)
      [dial refresh];
  for (SophistryParameter *p in parameters_) {
    NSControl *control = rows_[@(p.identifier)];
    if (!control)
      continue;
    float value = 0;
    if (AudioUnitGetParameter(unit_, p.identifier, kAudioUnitScope_Global, 0,
                              &value))
      continue;
    if ([control isKindOfClass:NSPopUpButton.class]) {
      auto *menu = (NSPopUpButton *)control;
      [menu selectItemAtIndex:std::clamp(
                                  NSInteger(std::lround(value - p.minimum)),
                                  NSInteger(0), menu.numberOfItems - 1)];
    } else
      control.floatValue = value;
    values_[@(p.identifier)].stringValue =
        valueText(unit_, p.identifier, value);
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
  if (!name.length)
    name = @"Sans nom";
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
    }
  }
  [self refresh:nil];
  return result == noErr;
}
- (void)choosePreset:(id)sender {
  NSOpenPanel *panel = [NSOpenPanel openPanel];
  panel.allowedFileTypes = @[ @"fxp", @"aupreset" ];
  panel.allowsMultipleSelection = NO;
  panel.title = @"Charger un son Sophistry";
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
                  if (result == NSModalResponseOK && ![data writeToURL:panel.URL
                                                            atomically:YES])
                    [self showError:@"Le preset n’a pas pu être enregistré."];
                }];
}
- (NSDictionary *)sophistryEditorReport {
  [self refresh:nil];
  NSUInteger images = 0;
  for (SophistryDial *dial in dials_)
    if (dial.sprite)
      ++images;
  return @{
    @"parameter_count" : @(parameters_.count),
    @"main_dial_count" : @(dials_.count),
    @"background_images_loaded" : @(frame_ && panel_),
    @"sprite_images_loaded" : @(images),
    @"visible_parameter_count" : @(rows_.count),
    @"size" : @[ @(self.frame.size.width), @(self.frame.size.height) ],
    @"status" : status(unit_)
  };
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
