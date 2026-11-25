// Included by CronoX3Editor.mm; Objective-C++/ARC only.
#pragma once
#include "../engine/GeneratorControls.h"
#include "CronoXTypography.h"
#import <CoreText/CoreText.h>

namespace cronoxGeneratorView {
inline NSString *string(const char *bytes, std::size_t capacity) {
  const auto size = strnlen(bytes, capacity);
  NSString *s = [[NSString alloc] initWithBytes:bytes
                                         length:size
                                       encoding:NSUTF8StringEncoding];
  if (!s)
    s = [[NSString alloc] initWithBytes:bytes
                                 length:size
                               encoding:NSMacOSRomanStringEncoding];
  return [s ?: @""
      stringByTrimmingCharactersInSet:NSCharacterSet
                                          .whitespaceAndNewlineCharacterSet];
}
inline void event(AudioUnit unit, UInt32 parameter, AudioUnitEventType type) {
  if (parameter == sophistry::noAUParameter)
    return;
  AudioUnitEvent e{};
  e.mEventType = type;
  e.mArgument.mParameter = {unit, parameter, kAudioUnitScope_Global, 0};
  AUEventListenerNotify(nullptr, nullptr, &e);
}
inline NSImage *image(NSBundle *bundle, unsigned number) {
  NSString *name = [NSString stringWithFormat:@"bmp%05u", number];
  NSURL *url = [bundle URLForResource:name
                        withExtension:@"png"
                         subdirectory:@"OriginalImages"];
  NSImage *image = url ? [[NSImage alloc] initWithContentsOfURL:url] : nil;
  // Original editor rectangles use bitmap pixels. Some PNGs declare 144,
  // 300 or 762 DPI; AppKit's point size must not shrink these sprite sheets.
  for (NSImageRep *rep in image.representations)
    if (rep.pixelsWide > 0 && rep.pixelsHigh > 0) {
      image.size = NSMakeSize(rep.pixelsWide, rep.pixelsHigh);
      break;
    }
  return image;
}
inline BOOL originalPixelSize(NSImage *image) {
  for (NSImageRep *rep in image.representations)
    if (rep.pixelsWide > 0 && rep.pixelsHigh > 0)
      return NSEqualSizes(image.size,
                          NSMakeSize(rep.pixelsWide, rep.pixelsHigh));
  return NO;
}
inline void text(NSString *s, NSRect r, CGFloat size, NSColor *color,
                 NSInteger alignment = 1) {
  if(!s.length || r.size.width<=0 || r.size.height<=0) return;
  // Match CDrawContext::drawStringUTF8(rect) 0xc1a44: an explicit baseline,
  // plain Helvetica, and clipping to the original rectangle. No small system font.
  CTFontRef font=CTFontCreateWithName(CFSTR("Helvetica"),size,nullptr);
  NSDictionary* attributes=@{(__bridge id)kCTFontAttributeName:(__bridge id)font,
    (__bridge id)kCTForegroundColorAttributeName:(__bridge id)color.CGColor};
  NSAttributedString* str=[[NSAttributedString alloc] initWithString:s attributes:attributes];
  CTLineRef line=CTLineCreateWithAttributedString((__bridge CFAttributedStringRef)str);
  CFRelease(font);
  CGFloat width=CGFloat(CTLineGetTypographicBounds(line,nullptr,nullptr,nullptr));
  CGFloat x=alignment==0?NSMinX(r):alignment==2?NSMaxX(r)-width:std::floor(NSMidX(r)-width*.5);
  CGFloat baseline=NSMaxY(r)-std::floor(r.size.height*.5)+std::floor(size*.5)-1;
  CGContextRef context=NSGraphicsContext.currentContext.CGContext;
  CGContextSaveGState(context);CGContextClipToRect(context,NSRectToCGRect(r));
  CGContextTranslateCTM(context,x,baseline);CGContextScaleCTM(context,1,-1);
  CGContextSetTextMatrix(context,CGAffineTransformIdentity);CGContextSetTextPosition(context,0,0);
  CTLineDraw(line,context);CGContextRestoreGState(context);CFRelease(line);
}

} // namespace cronoxGeneratorView

@interface CronoX3GeneratorNode : NSControl
@property AudioUnit audioUnit;
@property sophistry::GeneratorControlSpec spec;
@property sophistry::GeneratorControlState state;
@property(strong) NSImage *sprite;
@property AudioUnitPropertyID editProperty;
@property BOOL useOriginalNormalized;
@property float originalNormalized;
- (BOOL)activateNormalized:(double)value;
- (void)updateState:(sophistry::GeneratorControlState)state
               spec:(sophistry::GeneratorControlSpec)spec;
@end

@implementation CronoX3GeneratorNode
- (BOOL)isFlipped {
  return YES;
}
- (BOOL)acceptsFirstResponder {
  return self.enabled;
}
- (double)normalized {
  if (_useOriginalNormalized)
    return _originalNormalized;
  return sophistry::generatorNormalized(_state, _state.value);
}
- (NSRect)controlRect {
  return NSMakeRect(_spec.x - self.frame.origin.x,
                    _spec.y - self.frame.origin.y, _spec.width, _spec.height);
}
- (NSRect)valueRect {
  return NSMakeRect(_spec.x + _spec.width / 2 - self.frame.origin.x - 18,
                    _spec.y + _spec.height / 2 + _spec.valueOffset -
                        self.frame.origin.y - 4,
                    36, 10);
}
- (void)updateState:(sophistry::GeneratorControlState)state
               spec:(sophistry::GeneratorControlSpec)spec {
  _state = state;
  _spec = spec;
  NSRect r = NSMakeRect(spec.x, spec.y, spec.width, spec.height);
  if (spec.widget == sophistry::GeneratorWidget::Dial && spec.valueOffset) {
    NSRect value =
        NSMakeRect(spec.x + spec.width / 2 - 18,
                   spec.y + spec.height / 2 + spec.valueOffset - 4, 36, 10);
    r = NSUnionRect(r, value);
  }
  self.frame = r;
  self.enabled = spec.widget != sophistry::GeneratorWidget::Sample;
  NSString *name =
      cronoxGeneratorView::string(state.name, sizeof(state.name));
  NSString *value =
      cronoxGeneratorView::string(state.text, sizeof(state.text));
  self.toolTip = [NSString stringWithFormat:@"%@ : %@", name, value];
  self.accessibilityLabel = name;
  self.accessibilityValue = value;
  self.needsDisplay = YES;
}
- (BOOL)applyNormalized:(double)value {
  if (!self.enabled || !std::isfinite(value))
    return NO;
  sophistry::GeneratorControlEdit request;
  request.tag = _state.tag;
  request.normalized = float(std::clamp(value, 0.0, 1.0));
  const auto result = AudioUnitSetProperty(
      _audioUnit, _editProperty ?: sophistry::generatorEditProperty,
      kAudioUnitScope_Global, 0, &request, sizeof(request));
  if (result) {
    NSBeep();
    return NO;
  }
  cronoxGeneratorView::event(_audioUnit, _state.auParameter,
                                kAudioUnitEvent_ParameterValueChange);
  [self sendAction:self.action to:self.target];
  return YES;
}
- (BOOL)activateNormalized:(double)value {
  cronoxGeneratorView::event(_audioUnit, _state.auParameter,
                                kAudioUnitEvent_BeginParameterChangeGesture);
  BOOL result = [self applyNormalized:value];
  cronoxGeneratorView::event(_audioUnit, _state.auParameter,
                                kAudioUnitEvent_EndParameterChangeGesture);
  return result;
}
- (void)choose:(NSMenuItem *)item {
  [self activateNormalized:sophistry::generatorNormalized(_state, item.tag)];
}
- (void)drawRect:(NSRect)dirty {
  using W = sophistry::GeneratorWidget;
  const auto r = [self controlRect];
  const auto n = std::clamp([self normalized], 0.0, 1.0);
  NSString *value =
      cronoxGeneratorView::string(_state.text, sizeof(_state.text));
  // Each mode background already contains its type label and step arrows.
  // Keep the native hit regions and accessibility without drawing over them.
  if (_spec.widget == W::Type)
    return;
  if (_spec.widget == W::Routing || _spec.widget == W::Radio ||
      _spec.widget == W::HorizontalRadio) {
    if (!_sprite)
      return;
    const int count = _state.maximum - _state.minimum + 1;
    if (count < 1 || count > 16)
      return;
    const BOOL horizontal = _spec.widget == W::HorizontalRadio;
    const CGFloat rowHeight =
        horizontal ? r.size.height : r.size.height / count;
    const CGFloat width = horizontal ? r.size.width / count : r.size.width;
    const CGFloat sourceHeight = _sprite.size.height / (2 * count);
    for (int i = 0; i < count; ++i) {
      const int frame = i + (_state.value == i + _state.minimum ? count : 0);
      [_sprite drawInRect:NSMakeRect(r.origin.x + (horizontal ? i * width : 0),
                                     r.origin.y +
                                         (horizontal ? 0 : i * rowHeight),
                                     width, rowHeight)
                 fromRect:NSMakeRect(0,
                                     _sprite.size.height -
                                         (frame + 1) * sourceHeight,
                                     _sprite.size.width, sourceHeight)
                operation:NSCompositingOperationSourceOver
                 fraction:1
           respectFlipped:YES
                    hints:nil];
    }
  } else if (_sprite && _spec.frames) {
    const auto frame = NSUInteger(std::clamp(
        int(float(n) * (_spec.frames - 1) + 0.001f), 0, int(_spec.frames - 1)));
    const CGFloat height = _sprite.size.height / _spec.frames;
    [_sprite
            drawInRect:r
              fromRect:NSMakeRect(0, _sprite.size.height - (frame + 1) * height,
                                  _sprite.size.width, height)
             operation:NSCompositingOperationSourceOver
              fraction:1
        respectFlipped:YES
                 hints:nil];
    if (_spec.widget == W::Dial && _spec.valueOffset)
      cronoxGeneratorView::text(value, [self valueRect], 11,
                                   _spec.darkValue ? [NSColor colorWithWhite:0.1
                                                                       alpha:1]
                                                   : [NSColor colorWithRed:0.99
                                                                     green:0.95
                                                                      blue:0.7
                                                                     alpha:1]);
  } else if (_spec.widget == W::Sample) {
    [[NSColor colorWithRed:0.2 green:0.32 blue:0.3 alpha:1] setFill];
    [[NSBezierPath bezierPathWithRoundedRect:r xRadius:3 yRadius:3] fill];
    cronoxGeneratorView::text(
        value.length ? value : @"—", NSInsetRect(r, 3, 1),
        11, NSColor.whiteColor);
  } else {
    NSRect text = r;
    if (_spec.widget == W::Step) {
      text.size.width = MAX(18, r.size.width - 25);
      cronoxGeneratorView::text(value, text, 11,
                                   [NSColor colorWithWhite:0.08 alpha:1]);
    } else
      cronoxGeneratorView::text(value, text, 11, NSColor.whiteColor);
  }
}
- (void)mouseDown:(NSEvent *)down {
  if (!self.enabled)
    return;
  using W = sophistry::GeneratorWidget;
  [self.window makeFirstResponder:self];
  const NSPoint local = [self convertPoint:down.locationInWindow fromView:nil];
  if (down.modifierFlags & NSEventModifierFlagCommand) {
    [self activateNormalized:sophistry::generatorNormalized(
                                 _state, _state.defaultValue)];
    return;
  }
  if (_spec.widget == W::Type) {
    NSMenu *menu = [NSMenu new];
    NSArray *names =
        @[ @"Oscillator", @"Time Sampler", @"Schrader", @"Loop Sampler" ];
    for (NSInteger i = _state.minimum; i <= _state.maximum && i < 4; ++i) {
      NSMenuItem *item = [[NSMenuItem alloc] initWithTitle:names[i]
                                                    action:@selector(choose:)
                                             keyEquivalent:@""];
      item.target = self;
      item.tag = i;
      item.state =
          i == _state.value ? NSControlStateValueOn : NSControlStateValueOff;
      [menu addItem:item];
    }
    [NSMenu popUpContextMenu:menu withEvent:down forView:self];
    return;
  }
  if (_spec.widget == W::Routing || _spec.widget == W::Radio ||
      _spec.widget == W::HorizontalRadio) {
    const int count = _state.maximum - _state.minimum + 1;
    const double coordinate = _spec.widget == W::HorizontalRadio
                                  ? local.x / self.bounds.size.width
                                  : local.y / self.bounds.size.height;
    [self activateNormalized:sophistry::generatorNormalized(
                                 _state, _state.minimum +
                                             std::clamp(int(coordinate * count),
                                                        0, count - 1))];
    return;
  }
  if (_spec.widget == W::Toggle) {
    const int next =
        _state.value >= _state.maximum ? _state.minimum : _state.value + 1;
    [self activateNormalized:sophistry::generatorNormalized(_state, next)];
    return;
  }
  if ((_spec.widget == W::Step && local.x >= self.bounds.size.width - 24) ||
      (down.modifierFlags & NSEventModifierFlagOption)) {
    int direction =
        (_spec.widget == W::Step && local.x >= self.bounds.size.width - 24)
            ? (local.x >= self.bounds.size.width - 12 ? 1 : -1)
            : (local.y < self.bounds.size.height / 2 ? 1 : -1);
    [self activateNormalized:sophistry::generatorNormalized(
                                 _state,
                                 std::clamp(_state.value + direction,
                                            _state.minimum, _state.maximum))];
    return;
  }
  const double initial = [self normalized];
  const NSPoint origin = down.locationInWindow;
  cronoxGeneratorView::event(_audioUnit, _state.auParameter,
                                kAudioUnitEvent_BeginParameterChangeGesture);
  for (;;) {
    NSEvent *next =
        [self.window nextEventMatchingMask:NSEventMaskLeftMouseDragged |
                                           NSEventMaskLeftMouseUp];
    if (!next || next.type == NSEventTypeLeftMouseUp)
      break;
    const double sensitivity =
        (next.modifierFlags & NSEventModifierFlagShift) ? 600 : 150;
    [self applyNormalized:initial +
                          (next.locationInWindow.y - origin.y) / sensitivity];
    [self displayIfNeeded];
  }
  cronoxGeneratorView::event(_audioUnit, _state.auParameter,
                                kAudioUnitEvent_EndParameterChangeGesture);
}
- (void)scrollWheel:(NSEvent *)input {
  double target = [self normalized] + input.scrollingDeltaY / 200;
  if (_spec.widget == sophistry::GeneratorWidget::Step ||
      _spec.widget == sophistry::GeneratorWidget::Type ||
      _spec.widget == sophistry::GeneratorWidget::Routing ||
      _spec.widget == sophistry::GeneratorWidget::Toggle)
    target = sophistry::generatorNormalized(
        _state, std::clamp(_state.value + (input.scrollingDeltaY > 0 ? 1 : -1),
                           _state.minimum, _state.maximum));
  [self activateNormalized:target];
}
- (void)keyDown:(NSEvent *)key {
  if (key.keyCode == 126 || key.keyCode == 125)
    [self activateNormalized:sophistry::generatorNormalized(
                                 _state,
                                 std::clamp(_state.value +
                                                (key.keyCode == 126 ? 1 : -1),
                                            _state.minimum, _state.maximum))];
  else
    [super keyDown:key];
}
@end

#include "CronoXOriginalEditorView.h"

@interface CronoX3GeneratorPanel : NSView
@property NSUInteger pair;
- (instancetype)initWithAudioUnit:(AudioUnit)unit bundle:(NSBundle *)bundle;
- (void)refresh;
- (NSDictionary *)report;
- (BOOL)setControl:(UInt32)tag normalized:(float)value;
@end
@implementation CronoX3GeneratorPanel {
  AudioUnit unit_;
  NSBundle *bundle_;
  NSMutableDictionary<NSNumber *, CronoX3GeneratorNode *> *nodes_;
  NSMutableDictionary<NSNumber *, NSImage *> *images_;
  sophistry::GeneratorPanelState state_;
  OSStatus result_;
  NSMutableArray<CronoX3OriginalDrawing *> *waves_;
}
- (BOOL)isFlipped {
  return YES;
}
- (instancetype)initWithAudioUnit:(AudioUnit)unit bundle:(NSBundle *)bundle {
  if (!(self = [super initWithFrame:NSMakeRect(0, 37, 762, 290)]))
    return nil;
  unit_ = unit;
  bundle_ = bundle;
  nodes_ = [NSMutableDictionary dictionary];
  images_ = [NSMutableDictionary dictionary];
  waves_ = [NSMutableArray array];
  for (unsigned g = 0; g < 2; ++g) {
    CronoX3OriginalDrawing *view = [[CronoX3OriginalDrawing alloc]
        initWithFrame:NSMakeRect(429, g ? 161 : 24, 316, 92)];
    view.audioUnit = unit_;
    view.drawingID = 8 + g;
    view.hidden = YES;
    [self addSubview:view];
    [waves_ addObject:view];
  }
  return self;
}
- (NSImage *)image:(unsigned)n {
  NSImage *image = images_[@(n)];
  if (!image) {
    image = cronoxGeneratorView::image(bundle_, n);
    if (image)
      images_[@(n)] = image;
  }
  return image;
}
- (void)changed:(id)sender {
  [self refresh];
}
- (void)refresh {
  UInt32 bytes = sizeof(state_);
  result_ = AudioUnitGetProperty(unit_, sophistry::generatorPanelProperty,
                                 kAudioUnitScope_Global, UInt32(_pair), &state_,
                                 &bytes);
  for (CronoX3GeneratorNode *n in nodes_.allValues)
    n.hidden = YES;
  for (CronoX3OriginalDrawing *v in waves_)
    v.hidden = YES;
  if (result_ || bytes != sizeof(state_) || state_.version != 1 ||
      state_.count > state_.controls.size()) {
    self.needsDisplay = YES;
    return;
  }
  for (unsigned g = unsigned(_pair) * 2; g < unsigned(_pair) * 2 + 2; ++g)
    for (auto spec : sophistry::generatorLayout(g, state_.types[g])) {
      const sophistry::GeneratorControlState *value = nullptr;
      for (unsigned i = 0; i < state_.count; ++i)
        if (state_.controls[i].tag == spec.tag) {
          value = &state_.controls[i];
          break;
        }
      if (!value)
        continue;
      CronoX3GeneratorNode *node = nodes_[@(spec.tag)];
      if (!node) {
        node = [[CronoX3GeneratorNode alloc] initWithFrame:NSZeroRect];
        node.tag = spec.tag;
        node.audioUnit = unit_;
        node.target = self;
        node.action = @selector(changed:);
        nodes_[@(spec.tag)] = node;
        [self addSubview:node];
      }
      [node updateState:*value spec:spec];
      node.sprite = spec.image ? [self image:spec.image] : nil;
      node.hidden = NO;
    }
  if (!_pair)
    for (unsigned g = 0; g < 2; ++g)
      if (state_.types[g] == 3) {
        waves_[g].hidden = NO;
        [waves_[g] refresh];
      }
  self.needsDisplay = YES;
}
- (void)drawRect:(NSRect)dirty {
  if (result_) {
    cronoxGeneratorView::text(@"Commandes des générateurs indisponibles",
                                 NSMakeRect(130, 40, 500, 25), 12,
                                 NSColor.whiteColor);
    return;
  }
  for (unsigned i = 0; i < 2; ++i) {
    unsigned type = state_.types[unsigned(_pair) * 2 + i];
    unsigned resource = 220 + type * 2 + i;
    NSImage *image = [self image:resource];
    [image drawInRect:NSMakeRect(126, i * 145, 636, 145)
              fromRect:NSZeroRect
             operation:NSCompositingOperationSourceOver
              fraction:1
        respectFlipped:YES
                 hints:nil];
  }
}
- (BOOL)setControl:(UInt32)tag normalized:(float)value {
  [self refresh];
  CronoX3GeneratorNode *node = nodes_[@(tag)];
  return node && !node.hidden && [node activateNormalized:value];
}
- (NSDictionary *)report {
  [self refresh];
  NSMutableArray *controls = [NSMutableArray array];
  BOOL bounds = YES, images = YES;
  for (CronoX3GeneratorNode *n in nodes_.allValues) {
    if (n.hidden)
      continue;
    bounds = bounds && NSContainsRect(self.bounds, n.frame);
    images = images && (!n.spec.image || n.sprite != nil);
    const auto s = n.state;
    [controls addObject:@{
      @"tag" : @(s.tag),
      @"value" : @(s.value),
      @"normalized" : @(sophistry::generatorNormalized(s, s.value)),
      @"au_parameter" : s.auParameter == sophistry::noAUParameter
          ? [NSNull null]
          : @(s.auParameter),
      @"sample_name_read_only" : @(!n.enabled),
      @"sprite" : @(n.spec.image),
      @"frame" : @[
        @(n.frame.origin.x), @(n.frame.origin.y), @(n.frame.size.width),
        @(n.frame.size.height)
      ]
    }];
  }
  [controls sortUsingComparator:^NSComparisonResult(NSDictionary *a,
                                                    NSDictionary *b) {
    return [a[@"tag"] compare:b[@"tag"]];
  }];
  return @{
    @"property_status" : @(result_),
    @"pair" : @(_pair),
    @"types" : @[
      @(state_.types[0]), @(state_.types[1]), @(state_.types[2]),
      @(state_.types[3])
    ],
    @"controls" : controls,
    @"active_controls_in_bounds" : @(bounds),
    @"sprites_loaded" : @(images),
    @"complete_multisample_editor" : @NO,
    @"waveforms" : @[ [waves_[0] report], [waves_[1] report] ]
  };
}
@end
