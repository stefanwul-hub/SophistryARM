// Cocoa widgets placed from the executed original i386 constructors.
#pragma once
#include "../engine/CompleteEditorControls.h"
#include "CronoXGeneratorView.h"
#include "SampleDisplay.h"
namespace cronoxCompleteView {
inline NSString *string(const char *p, std::size_t capacity) {
  auto n = strnlen(p, capacity);
  NSString *s = [[NSString alloc] initWithBytes:p
                                         length:n
                                       encoding:NSUTF8StringEncoding];
  return s ?: [[NSString alloc] initWithBytes:p length:n encoding:NSMacOSRomanStringEncoding] ?: @"";
}
inline BOOL edit(AudioUnit unit, unsigned tag, float normalized) {
  sophistry::GeneratorControlEdit e{1, tag, std::clamp(normalized, 0.f, 1.f)};
  return !AudioUnitSetProperty(unit, sophistry::editorEditProperty,
                               kAudioUnitScope_Global, 0, &e, sizeof(e));
}
inline BOOL text(AudioUnit unit, unsigned tag, NSData *data) {
  if (data.length >= sophistry::editorStringBytes)
    return NO;
  sophistry::EditorTextEditHeader h{1, tag, UInt32(data.length + 1)};
  std::vector<char> bytes(sizeof(h) + h.bytes);
  memcpy(bytes.data(), &h, sizeof(h));
  if (data.length)
    memcpy(bytes.data() + sizeof(h), data.bytes, data.length);
  return !AudioUnitSetProperty(unit, sophistry::editorTextEditProperty,
                               kAudioUnitScope_Global, 0, bytes.data(),
                               UInt32(bytes.size()));
}
inline NSData *text(AudioUnit unit, unsigned tag) {
  std::array<char, sophistry::editorStringBytes> data{};
  UInt32 size = data.size();
  if (AudioUnitGetProperty(unit, sophistry::editorStringProperty,
                           kAudioUnitScope_Global, tag, data.data(), &size))
    return nil;
  return [NSData dataWithBytes:data.data()
                        length:strnlen(data.data(), data.size())];
}
inline BOOL file(AudioUnit unit, unsigned tag, unsigned operation,
                 NSString *path) {
  NSData *data = [path dataUsingEncoding:NSUTF8StringEncoding];
  if (!data.length || data.length >= 256)
    return NO;
  sophistry::EditorFileRequest h{1, tag, operation, UInt32(data.length + 1)};
  std::vector<char> bytes(sizeof(h) + h.pathBytes);
  memcpy(bytes.data(), &h, sizeof(h));
  memcpy(bytes.data() + sizeof(h), data.bytes, data.length);
  return !AudioUnitSetProperty(unit, sophistry::editorFileProperty,
                               kAudioUnitScope_Global, 0, bytes.data(),
                               UInt32(bytes.size()));
}
inline void drawText(NSString *s, NSRect rect, CGFloat size,
                     NSColor *color = NSColor.whiteColor) {
  cronoxGeneratorView::text(s, rect, size, color);
}
} // namespace cronoxCompleteView
@class CronoX3RecoveredNode;
@protocol CronoX3RecoveredOwner
- (void)changed:(id)sender;
- (void)chooseNode:(CronoX3RecoveredNode *)node value:(NSInteger)value;
- (void)openNode:(CronoX3RecoveredNode *)node;
- (void)actionNode:(CronoX3RecoveredNode *)node;
- (void)textNode:(CronoX3RecoveredNode *)node;
- (void)moduleMenu:(unsigned)tag value:(unsigned)value;
@end
@interface CronoX3RecoveredNode : CronoX3GeneratorNode
@property sophistry::RecoveredControl recovered;
@property(weak) id<CronoX3RecoveredOwner> owner;
@property BOOL circular;
@property float secondaryNormalized;
@property(copy) NSString *sampleLabel;
- (void)updateRecovered:(sophistry::RecoveredControl)control
                  value:(sophistry::EditorControlState)value;
- (NSMenu *)recoveredMenu;
@end
@implementation CronoX3RecoveredNode
- (BOOL)isOpaque {
  return NO;
}
- (void)updateRecovered:(sophistry::RecoveredControl)c
                  value:(sophistry::EditorControlState)v {
  auto old = self.state;
  auto previous = self.recovered;
  if (previous.key == c.key && previous.kind == c.kind && previous.x == c.x &&
      previous.y == c.y && previous.width == c.width &&
      previous.height == c.height && !memcmp(&old, &v.value, sizeof(old)) &&
      self.originalNormalized == v.normalized)
    return;
  self.recovered = c;
  self.useOriginalNormalized = YES;
  self.originalNormalized = v.normalized;
  using K = sophistry::RecoveredWidget;
  using W = sophistry::GeneratorWidget;
  W kind = c.kind == K::Step                                      ? W::Step
           : c.kind == K::Toggle                                  ? W::Toggle
           : c.kind == K::Radio && (c.tag == 108 || c.tag == 109) ? W::Routing
                                                                  : W::Dial;
  sophistry::GeneratorControlSpec spec{
      c.tag, kind, c.x, c.y, c.width, c.height, c.image, c.frames, 0, false};
  [self updateState:v.value spec:spec];
  NSRect bounds = NSMakeRect(c.x, c.y, c.width, c.height);
  if (c.kind == K::ThinSlider)
    bounds.size.height = MAX(bounds.size.height, CGFloat(c.extra[1]));
  if (c.valueRect[2] > 0)
    bounds = NSUnionRect(bounds, NSMakeRect(c.valueRect[0], c.valueRect[1],
                                            c.valueRect[2], c.valueRect[3]));
  self.frame = bounds;
}
- (void)drawRect:(NSRect)dirty {
  using K = sophistry::RecoveredWidget;
  auto c = self.recovered;
  NSRect r = [self controlRect];
  float n = std::clamp(self.originalNormalized, 0.f, 1.f);
  NSString *value =
      cronoxCompleteView::string(self.state.text, sizeof(self.state.text));
  if (c.kind == K::Gator) {
    NSData *bytes = cronoxCompleteView::text(self.audioUnit, c.tag);
    auto *data = static_cast<const unsigned char *>(bytes.bytes);
    unsigned count = MAX(1,c.extra[0]); CGFloat width = r.size.width/count;
    for(unsigned i=0;i<count;++i) {
      bool on = i<bytes.length && data[i]=='1';
      [self.sprite drawInRect:NSMakeRect(r.origin.x+i*width,r.origin.y,width,r.size.height)
        fromRect:NSMakeRect(0,on?0:r.size.height,width,r.size.height)
        operation:NSCompositingOperationSourceOver fraction:1 respectFlipped:YES hints:nil];
    }
  } else if (c.kind == K::Dial || c.kind == K::Toggle || c.kind == K::HorizontalSlider)
    [super drawRect:dirty];
  else if (c.kind == K::Step) {
    NSRect text = r;
    text.size.width = MAX(1, r.size.width - 30);
    cronoxCompleteView::drawText(value, text, 9,
                                    [NSColor colorWithWhite:.08 alpha:1]);
  } else if (c.kind == K::Radio) {
    NSImage *im = self.sprite;
    int cols = MAX(1, c.extra[0]), rows = MAX(1, c.extra[1]);
    int index =
        std::clamp(self.state.value - self.state.minimum, 0, cols * rows - 1);
    if (c.extra[2]) {
      [im drawInRect:r
                fromRect:NSMakeRect(
                             0, im.size.height - (index + 1) * r.size.height,
                             im.size.width, r.size.height)
               operation:NSCompositingOperationSourceOver
                fraction:1
          respectFlipped:YES
                   hints:nil];
    } else {
      [im drawInRect:r
                fromRect:NSMakeRect(0, im.size.height - r.size.height,
                                    im.size.width, r.size.height)
               operation:NSCompositingOperationSourceOver
                fraction:1
          respectFlipped:YES
                   hints:nil];
      CGFloat w = r.size.width / cols, h = r.size.height / rows;
      int col = index / rows, row = index % rows;
      [im drawInRect:NSMakeRect(r.origin.x + col * w, r.origin.y + row * h, w,
                                h)
                fromRect:NSMakeRect(col * w,
                                    im.size.height - r.size.height -
                                        (row + 1) * h,
                                    w, h)
               operation:NSCompositingOperationSourceOver
                fraction:1
          respectFlipped:YES
                   hints:nil];
    }
  } else if (c.kind == K::Drawbar) {
    NSImage *im = self.sprite;
    const float visual = c.extra[1] ? 1.f - n : n;
    CGFloat amount = int((r.size.height - c.extra[0]) * visual);
    [im drawInRect:NSMakeRect(r.origin.x, r.origin.y, r.size.width,
                              amount + c.extra[0])
              fromRect:NSMakeRect(0, 0, r.size.width, amount + c.extra[0])
             operation:NSCompositingOperationSourceOver
              fraction:1
        respectFlipped:YES
                 hints:nil];
  } else if (c.kind == K::ThinSlider) {
    CGFloat x = r.origin.x + int((r.size.width - c.extra[0]) * n);
    [self.sprite drawInRect:NSMakeRect(x, r.origin.y, c.extra[0], c.extra[1])
                   fromRect:NSZeroRect
                  operation:NSCompositingOperationSourceOver
                   fraction:1
             respectFlipped:YES
                      hints:nil];
  } else if (c.kind == K::Scrollbar) {
    int track = int(r.size.width) - 2 * c.extra[1];
    int thumb =
        std::clamp(int(track * self.secondaryNormalized), 8, MAX(8, track));
    int x = c.extra[1] + int((track - thumb) * n + .499f);
    [[NSColor colorWithRed:148. / 255 green:158. / 255 blue:128. / 255
                     alpha:1] setFill];
    NSRectFill(NSMakeRect(r.origin.x + x, r.origin.y, thumb,
                          MAX(1, r.size.height - 1)));
  } else if (c.kind == K::Menu) {
    if (self.sprite)
      [self.sprite drawInRect:r
                     fromRect:NSZeroRect
                    operation:NSCompositingOperationSourceOver
                     fraction:1
               respectFlipped:YES
                        hints:nil];
    // Type names and the small Copy/Paste triangles are already in their skins.
    if (sophistry::generatorForTypeTag(c.tag) == 4 &&
        !(c.tag >= 639 && c.tag <= 647))
      cronoxCompleteView::drawText(
          [value stringByTrimmingCharactersInSet:NSCharacterSet
                                                     .whitespaceCharacterSet],
          NSInsetRect(r, 2, 0), 8);
  } else if (c.kind == K::Text || c.kind == K::Display) {
    if (self.state.kind == 7 && c.tag != 648)
      value = self.sampleLabel ?: @"";
    cronoxCompleteView::drawText(value, r, r.size.height <= 11 ? 7 : 9);
  }
  if (c.valueRect[2] > 0) {
    NSRect text = NSMakeRect(c.valueRect[0] - self.frame.origin.x,
                             c.valueRect[1] - self.frame.origin.y,
                             c.valueRect[2], c.valueRect[3]);
    cronoxCompleteView::drawText(value, text, 7,
                                    c.extra[0] && c.kind == K::Dial
                                        ? [NSColor colorWithWhite:.1 alpha:1]
                                        : [NSColor colorWithRed:.99
                                                          green:.95
                                                           blue:.7
                                                          alpha:1]);
  }
}
- (void)chooseRecovered:(NSMenuItem *)item {
  if ([item.representedObject isKindOfClass:NSDictionary.class]) {
    NSNumber *parameter = item.representedObject[@"full_loop"];
    if (!parameter)
      return;
    float current = 0;
    unsigned id = parameter.unsignedIntValue;
    if (AudioUnitGetParameter(self.audioUnit, id, kAudioUnitScope_Global, 0,
                              &current))
      return;
    cronoxGeneratorView::event(self.audioUnit, id,
                                  kAudioUnitEvent_BeginParameterChangeGesture);
    OSStatus result =
        AudioUnitSetParameter(self.audioUnit, id, kAudioUnitScope_Global, 0,
                              current >= .5f ? 0.f : 1.f, 0);
    if (!result)
      cronoxGeneratorView::event(self.audioUnit, id,
                                    kAudioUnitEvent_ParameterValueChange);
    cronoxGeneratorView::event(self.audioUnit, id,
                                  kAudioUnitEvent_EndParameterChangeGesture);
    if (result)
      NSBeep();
    [self.owner changed:self];
  } else if ([item.representedObject isKindOfClass:NSNumber.class])
    [self.owner moduleMenu:[item.representedObject unsignedIntValue]
                     value:unsigned(item.tag)];
  else
    [self.owner chooseNode:self value:item.tag];
}
- (NSMenu *)recoveredMenu {
  auto c = self.recovered;
  sophistry::EditorChoices choices;
  UInt32 size = sizeof(choices);
  if (AudioUnitGetProperty(self.audioUnit, sophistry::editorChoicesProperty,
                           kAudioUnitScope_Global, c.tag, &choices, &size)) {
    return nil;
  }
  NSMenu *menu = [NSMenu new];
  for (unsigned i = 0; i < choices.count; ++i) {
    NSString *title = [cronoxCompleteView::string(choices.labels[i].data(),
                                                     choices.labels[i].size())
        stringByTrimmingCharactersInSet:NSCharacterSet.whitespaceCharacterSet];
    NSMenuItem *item =
        [[NSMenuItem alloc] initWithTitle:title.length ? title : @"—"
                                   action:@selector(chooseRecovered:)
                            keyEquivalent:@""];
    item.tag = self.state.minimum + i;
    item.target = self;
    item.state = item.tag == self.state.value ? NSControlStateValueOn
                                              : NSControlStateValueOff;
    [menu addItem:item];
  }
  if (unsigned g = sophistry::generatorForTypeTag(c.tag); g < 4) {
    // The original four Time Sampler FullLoop controls (52..55) use the
    // missing bitmap 250. Preserve their original AU parameter via this menu.
    if (self.state.value == 1) {
      float value = 0;
      if (!AudioUnitGetParameter(self.audioUnit, 52 + g, kAudioUnitScope_Global,
                                 0, &value)) {
        [menu addItem:NSMenuItem.separatorItem];
        NSMenuItem *item =
            [[NSMenuItem alloc] initWithTitle:@"Full Loop"
                                       action:@selector(chooseRecovered:)
                                keyEquivalent:@""];
        item.target = self;
        item.state =
            value >= .5f ? NSControlStateValueOn : NSControlStateValueOff;
        item.representedObject = @{@"full_loop" : @(52 + g)};
        [menu addItem:item];
      }
    }
    unsigned tag = 643 + g;
    choices = {};
    size = sizeof(choices);
    if (!AudioUnitGetProperty(self.audioUnit, sophistry::editorChoicesProperty,
                              kAudioUnitScope_Global, tag, &choices, &size)) {
      [menu addItem:NSMenuItem.separatorItem];
      for (unsigned i = 0; i < choices.count; ++i) {
        NSString *title = cronoxCompleteView::string(
            choices.labels[i].data(), choices.labels[i].size());
        NSMenuItem *item =
            [[NSMenuItem alloc] initWithTitle:title
                                       action:@selector(chooseRecovered:)
                                keyEquivalent:@""];
        item.tag = i;
        item.representedObject = @(tag);
        item.target = self;
        [menu addItem:item];
      }
    }
  }
  return menu;
}
- (void)mouseDown:(NSEvent *)event {
  using K = sophistry::RecoveredWidget;
  auto c = self.recovered;
  if(c.kind == K::Gator) {
    NSMutableData *bytes = [cronoxCompleteView::text(self.audioUnit,c.tag) mutableCopy];
    unsigned count = MAX(1,c.extra[0]);
    if(bytes.length!=count) return;
    NSPoint point=[self convertPoint:event.locationInWindow fromView:nil];
    NSRect rect=[self controlRect];unsigned at=std::clamp(int((point.x-rect.origin.x)*count/rect.size.width),0,int(count-1));
    auto *data=static_cast<unsigned char *>(bytes.mutableBytes);data[at]=data[at]=='1'?'0':'1';
    if(!cronoxCompleteView::text(self.audioUnit,c.tag,bytes)) NSBeep();
    [self.owner changed:self];return;
  }
  if (c.kind == K::Menu) {
    NSMenu *menu = [self recoveredMenu];
    if (menu)
      [NSMenu popUpContextMenu:menu withEvent:event forView:self];
    else
      NSBeep();
    return;
  }
  if (c.kind == K::File) {
    [self.owner openNode:self];
    return;
  }
  if (c.kind == K::Action) {
    [self.owner actionNode:self];
    return;
  }
  if (c.kind == K::Display) {
    return;
  }
  if (c.kind == K::Text && event.clickCount > 1) {
    [self.owner textNode:self];
    return;
  }
  NSPoint p = [self convertPoint:event.locationInWindow fromView:nil];
  NSRect r = [self controlRect];
  if(c.kind == K::Step && c.extra[2] && p.x-r.origin.x >= c.extra[0]) {
    int direction=p.x-r.origin.x >= c.extra[1]?1:-1;
    [self activateNormalized:sophistry::generatorNormalized(self.state,std::clamp(self.state.value+direction,self.state.minimum,self.state.maximum))];return;
  }
  if (c.kind == K::Radio) {
    int cols = MAX(1, c.extra[0]), rows = MAX(1, c.extra[1]);
    int col = std::clamp(int((p.x - r.origin.x) * cols / r.size.width), 0,
                         cols - 1),
        row = std::clamp(int((p.y - r.origin.y) * rows / r.size.height), 0,
                         rows - 1);
    int index = col * rows + row;
    [self activateNormalized:float(index) / MAX(1, cols * rows - 1)];
    return;
  }
  if (c.kind == K::Drawbar || c.kind == K::HorizontalSlider ||
      c.kind == K::ThinSlider || c.kind == K::Scrollbar) {
    [self.window makeFirstResponder:self];
    auto current = event;
    cronoxGeneratorView::event(self.audioUnit, self.state.auParameter,
                                  kAudioUnitEvent_BeginParameterChangeGesture);
    for (;;) {
      NSPoint q = [self convertPoint:current.locationInWindow fromView:nil];
      float n = float((q.x - r.origin.x) / MAX(1, r.size.width));
      if (c.kind == K::ThinSlider) {
        n = float((q.x-r.origin.x-c.extra[0]*.5)/MAX(1,r.size.width-c.extra[0]));
      } else if (c.kind != K::HorizontalSlider) {
        UInt32 x = std::clamp(int(q.x - r.origin.x), -512, 511) + 512,
               y = std::clamp(int(q.y - r.origin.y), -512, 511) + 512;
        UInt32 bytes = sizeof(float);
        if (AudioUnitGetProperty(self.audioUnit, sophistry::editorKnobProperty,
                                 kAudioUnitScope_Global,
                                 c.key | (x << 11) | (y << 21), &n, &bytes))
          break;
      }
      [self applyNormalized:n];
      [self displayIfNeeded];
      current = [self.window nextEventMatchingMask:NSEventMaskLeftMouseDragged |
                                                   NSEventMaskLeftMouseUp];
      if (!current || current.type == NSEventTypeLeftMouseUp)
        break;
    }
    cronoxGeneratorView::event(self.audioUnit, self.state.auParameter,
                                  kAudioUnitEvent_EndParameterChangeGesture);
    return;
  }
  if (c.kind == K::Dial && self.circular &&
      !(event.modifierFlags &
        (NSEventModifierFlagCommand | NSEventModifierFlagOption |
         NSEventModifierFlagShift))) {
    cronoxGeneratorView::event(self.audioUnit, self.state.auParameter,
                                  kAudioUnitEvent_BeginParameterChangeGesture);
    NSEvent *current = event;
    for (;;) {
      NSPoint q = [self convertPoint:current.locationInWindow fromView:nil];
      UInt32 x = std::clamp(int(q.x - r.origin.x), -512, 511) + 512,
             y = std::clamp(int(q.y - r.origin.y), -512, 511) + 512;
      UInt32 element = c.key | (x << 11) | (y << 21), bytes = sizeof(float);
      float n = 0;
      if (!AudioUnitGetProperty(self.audioUnit, sophistry::editorKnobProperty,
                                kAudioUnitScope_Global, element, &n, &bytes)) {
        [self applyNormalized:n];
        [self displayIfNeeded];
      }
      current = [self.window nextEventMatchingMask:NSEventMaskLeftMouseDragged |
                                                   NSEventMaskLeftMouseUp];
      if (!current || current.type == NSEventTypeLeftMouseUp)
        break;
    }
    cronoxGeneratorView::event(self.audioUnit, self.state.auParameter,
                                  kAudioUnitEvent_EndParameterChangeGesture);
    return;
  }
  [super mouseDown:event];
}
@end

@interface CronoX3ArpeggiatorView : NSView
@property AudioUnit audioUnit;
@property(weak) id<CronoX3RecoveredOwner> owner;
- (void)refresh;
- (NSDictionary *)report;
@end
@implementation CronoX3ArpeggiatorView {
  NSData *sequence_;
  OSStatus status_;
}
- (BOOL)isFlipped {
  return YES;
}
- (void)refresh {
  NSData *d = cronoxCompleteView::text(_audioUnit, 648);
  status_ = d.length == 258 ? 0 : kAudioUnitErr_InvalidPropertyValue;
  if (![d isEqual:sequence_])
    self.needsDisplay = YES;
  sequence_ = d;
}
- (NSDictionary *)report {
  return @{@"status" : @(status_), @"sequence_bytes" : @(sequence_.length)};
}
- (void)drawRect:(NSRect)dirty {
  if (status_)
    return;
  auto *b = static_cast<const unsigned char *>(sequence_.bytes);
  CGFloat w = self.bounds.size.width / 4, h = self.bounds.size.height / 8;
  for (unsigned col = 0; col < 4; ++col)
    for (unsigned row = 0; row < 8; ++row) {
      unsigned i = col * 8 + row;
      NSColor *color =
          i < unsigned(b[1] - 1) ? NSColor.whiteColor : NSColor.grayColor;
      NSString *velocity =
          b[3 + 2 * i] == 1 ? @"Off"
          : b[3 + 2 * i] == 129
              ? @"Tie"
              : [NSString stringWithFormat:@"%03u", unsigned(b[3 + 2 * i] - 1)];
      if (i == unsigned(b[0] - 1)) {
        [[NSColor colorWithRed:.55 green:.75 blue:.65 alpha:.6] setFill];
        NSRectFill(NSMakeRect(col * w, row * h, 6, h));
      }
      cronoxCompleteView::drawText(
          [NSString stringWithFormat:@"%03u", unsigned(b[2 + 2 * i] - 1)],
          NSMakeRect(col * w + 8, row * h, w / 2 - 8, h), 7, color);
      cronoxCompleteView::drawText(
          velocity, NSMakeRect(col * w + w / 2, row * h, w / 2, h), 7, color);
    }
}
- (void)mouseDown:(NSEvent *)down {
  if (status_)
    return;
  NSPoint p = [self convertPoint:down.locationInWindow fromView:nil];
  CGFloat w = self.bounds.size.width / 4, h = self.bounds.size.height / 8;
  int col = std::clamp(int(p.x / w), 0, 3),
      row = std::clamp(int(p.y / h), 0, 7), step = col * 8 + row;
  BOOL velocity = (p.x - col * w) > w / 2;
  NSUInteger at = 2 + 2 * step + velocity;
  const auto *before = static_cast<const unsigned char *>(sequence_.bytes);
  int initial = before[at] - 1;
  NSPoint origin = down.locationInWindow;
  NSEvent *event = down;
  for (;;) {
    int value =
        (down.modifierFlags & NSEventModifierFlagOption)
            ? (velocity ? 100 : 60)
            : std::clamp(initial +
                             int((event.locationInWindow.y - origin.y) / 2),
                         0, velocity ? 128 : 127);
    NSMutableData *d = [sequence_ mutableCopy];
    static_cast<unsigned char *>(d.mutableBytes)[at] = value + 1;
    if (cronoxCompleteView::text(_audioUnit, 648, d)) {
      [self.owner changed:self];
      [self refresh];
    }
    event = [self.window nextEventMatchingMask:NSEventMaskLeftMouseDragged |
                                               NSEventMaskLeftMouseUp];
    if (!event || event.type == NSEventTypeLeftMouseUp)
      break;
  }
}
@end

@interface CronoX3LoopDrawing : CronoX3OriginalDrawing
@property sophistry::CompleteEditorState::Viewport viewport;
@property unsigned generator;
@property(weak) id<CronoX3RecoveredOwner> owner;
@property std::array<int, 3> markers;
@end
@implementation CronoX3LoopDrawing
- (void)mouseDown:(NSEvent *)down {
  auto v = self.viewport;
  if (!v.frames || v.span <= 0)
    return;
  NSPoint p = [self convertPoint:down.locationInWindow fromView:nil];
  float frame =
      float((v.first + p.x / self.bounds.size.width * v.span) * v.rate);
  unsigned marker = 0;
  for (unsigned i = 1; i < 3; ++i)
    if (std::abs(frame - self.markers[i]) <
        std::abs(frame - self.markers[marker]))
      marker = i;
  NSEvent *event = down;
  for (;;) {
    NSPoint q = [self convertPoint:event.locationInWindow fromView:nil];
    int at = std::clamp(
        int((v.first + q.x / self.bounds.size.width * v.span) * v.rate), 0,
        int(v.frames - 1));
    NSString *s = [NSString stringWithFormat:@"%d", at];
    if (cronoxCompleteView::text(self.audioUnit,
                                    953 + 2 * marker + self.generator,
                                    [s dataUsingEncoding:NSUTF8StringEncoding]))
      [self.owner changed:self];
    [self refresh];
    [self displayIfNeeded];
    event = [self.window nextEventMatchingMask:NSEventMaskLeftMouseDragged |
                                               NSEventMaskLeftMouseUp];
    if (!event || event.type == NSEventTypeLeftMouseUp)
      break;
  }
}
@end

#include "../engine/RecoveredKeyboard.h"
@interface CronoX3RecoveredKeyboard : NSView
@property AudioUnit audioUnit;
@property NSImage *whiteImage;
@property NSImage *blackImage;
@end
@implementation CronoX3RecoveredKeyboard {
  int pressed_;
}
- (instancetype)initWithFrame:(NSRect)frame {
  if ((self = [super initWithFrame:frame]))
    pressed_ = -1;
  return self;
}
- (BOOL)isFlipped {
  return YES;
}
- (void)drawRect:(NSRect)dirty {
  unsigned state =
      pressed_ >= 36 && pressed_ <= 96 ? unsigned(pressed_ - 35) : 0;
  for (const auto &b : sophistry::recoveredKeyboard(state)) {
    NSImage *im = b.image == 382 ? _whiteImage : _blackImage;
    [im drawInRect:NSMakeRect(b.left, b.top, b.right - b.left, b.bottom - b.top)
              fromRect:NSMakeRect(b.sourceX,
                                  im.size.height - b.sourceY -
                                      (b.bottom - b.top),
                                  b.right - b.left, b.bottom - b.top)
             operation:NSCompositingOperationSourceOver
              fraction:1
        respectFlipped:YES
                 hints:nil];
  }
}
- (void)mouseDown:(NSEvent *)down {
  NSEvent *event = down;
  for (;;) {
    NSPoint p = [self convertPoint:event.locationInWindow fromView:nil];
    if (NSPointInRect(p, self.bounds)) {
      sophistry::EditorKeyHit hit;
      UInt32 size = sizeof(hit);
      UInt32 element = (UInt32(std::clamp(int(p.y), 0, 94)) << 10) |
                       UInt32(std::clamp(int(p.x), 0, 647));
      if (!AudioUnitGetProperty(_audioUnit, sophistry::editorKeyHitProperty,
                                kAudioUnitScope_Global, element, &hit, &size) &&
          int(hit.note) != pressed_) {
        if (pressed_ >= 0)
          MusicDeviceMIDIEvent(_audioUnit, 0x80, pressed_, 0, 0);
        pressed_ = hit.note;
        MusicDeviceMIDIEvent(_audioUnit, 0x90, hit.note, hit.velocity, 0);
        self.needsDisplay = YES;
        [self displayIfNeeded];
      }
    }
    event = [self.window nextEventMatchingMask:NSEventMaskLeftMouseDragged |
                                               NSEventMaskLeftMouseUp];
    if (!event || event.type == NSEventTypeLeftMouseUp)
      break;
  }
  if (pressed_ >= 0)
    MusicDeviceMIDIEvent(_audioUnit, 0x80, pressed_, 0, 0);
  pressed_ = -1;
  self.needsDisplay = YES;
}
- (void)viewWillMoveToWindow:(NSWindow *)window {
  if (!window && pressed_ >= 0) {
    MusicDeviceMIDIEvent(_audioUnit, 0x80, pressed_, 0, 0);
    pressed_ = -1;
  }
  [super viewWillMoveToWindow:window];
}
@end

@interface CronoX3SurroundView : NSView
@property AudioUnit audioUnit;
@property NSImage *sprite;
@property std::array<float, 7> xValues;
@property std::array<float, 7> yValues;
@property std::array<bool, 7> enabled;
@property(weak) id<CronoX3RecoveredOwner> owner;
@end
@implementation CronoX3SurroundView
- (BOOL)isFlipped {
  return YES;
}
- (void)drawRect:(NSRect)dirty {
  CGFloat w = self.bounds.size.width - 12, h = self.bounds.size.height - 12;
  for (unsigned i = 0; i < 7; ++i)
    if (self.enabled[i]) {
      CGFloat x = int(w * self.xValues[i]), y = int(h * self.yValues[i]);
      [self.sprite
              drawInRect:NSMakeRect(x, y, 12, 12)
                fromRect:NSMakeRect(0, self.sprite.size.height - (i + 1) * 12,
                                    12, 12)
               operation:NSCompositingOperationSourceOver
                fraction:1
          respectFlipped:YES
                   hints:nil];
    }
}
- (void)mouseDown:(NSEvent *)down {
  NSPoint p = [self convertPoint:down.locationInWindow fromView:nil];
  CGFloat w = self.bounds.size.width - 12, h = self.bounds.size.height - 12;
  int selected = -1;
  CGFloat best = 1e30;
  for (unsigned i = 0; i < 7; ++i)
    if (self.enabled[i]) {
      CGFloat dx = w * self.xValues[i] - p.x, dy = h * self.yValues[i] - p.y,
              d = dx * dx + dy * dy;
      if (d < best) {
        best = d;
        selected = i;
      }
    }
  if (selected < 0)
    return;
  float x = self.xValues[selected], y = self.yValues[selected];
  NSPoint origin = down.locationInWindow;
  NSEvent *event = down;
  unsigned xAU = sophistry::recoveredAUParameter(558 + selected),
           yAU = sophistry::recoveredAUParameter(565 + selected);
  cronoxGeneratorView::event(_audioUnit, xAU,
                                kAudioUnitEvent_BeginParameterChangeGesture);
  cronoxGeneratorView::event(_audioUnit, yAU,
                                kAudioUnitEvent_BeginParameterChangeGesture);
  for (;;) {
    float nx = (down.modifierFlags & NSEventModifierFlagCommand)
                   ? .5f
                   : x + float(event.locationInWindow.x - origin.x) / w;
    float ny = (down.modifierFlags & NSEventModifierFlagCommand)
                   ? .5f
                   : y - float(event.locationInWindow.y - origin.y) / h;
    if (cronoxCompleteView::edit(_audioUnit, 558 + selected, nx) &&
        cronoxCompleteView::edit(_audioUnit, 565 + selected, ny))
      [self.owner changed:self];
    [self displayIfNeeded];
    event = [self.window nextEventMatchingMask:NSEventMaskLeftMouseDragged |
                                               NSEventMaskLeftMouseUp];
    if (!event || event.type == NSEventTypeLeftMouseUp)
      break;
  }
  cronoxGeneratorView::event(_audioUnit, xAU,
                                kAudioUnitEvent_EndParameterChangeGesture);
  cronoxGeneratorView::event(_audioUnit, yAU,
                                kAudioUnitEvent_EndParameterChangeGesture);
}
@end

@interface CronoX3CompletePanel : NSView <CronoX3RecoveredOwner>
@property unsigned page;
@property(weak) id changeTarget;
- (instancetype)initWithAudioUnit:(AudioUnit)unit bundle:(NSBundle *)bundle;
- (void)refresh;
- (NSDictionary *)report;
- (NSDictionary *)generatorReport;
- (NSUInteger)mainDialCount;
- (NSUInteger)mainSpriteCount;
- (BOOL)setControl:(unsigned)tag normalized:(float)value;
- (BOOL)setText:(unsigned)tag value:(NSString *)value;
- (void)fileCommand:(unsigned)tag operation:(unsigned)operation;
- (void)midiCommand:(NSPopUpButton *)sender;
@end
@implementation CronoX3CompletePanel {
  AudioUnit unit_;
  NSBundle *bundle_;
  sophistry::CompleteEditorState state_;
  OSStatus status_;
  sophistry::CompleteEditorLayout layout_;
  NSMutableDictionary<NSNumber *, NSView *> *views_;
  NSMutableDictionary<NSNumber *, NSImage *> *images_;
}
- (BOOL)isFlipped {
  return YES;
}
- (instancetype)initWithAudioUnit:(AudioUnit)unit bundle:(NSBundle *)bundle {
  if (!(self = [super initWithFrame:NSMakeRect(0, 37, 762, 290)]))
    return nil;
  unit_ = unit;
  bundle_ = bundle;
  views_ = [NSMutableDictionary dictionary];
  images_ = [NSMutableDictionary dictionary];
  return self;
}
- (NSImage *)image:(unsigned)number {
  NSImage *im = images_[@(number)];
  if (im)
    return im;
  im = cronoxGeneratorView::image(bundle_, number);
  if (im && (number == 357 || number == 373 || number == 376 || number == 377 ||
             number == 396)) {
    CGImageRef raw = [im CGImageForProposedRect:nil context:nil hints:nil];
    const CGFloat white[] = {255, 255, 255, 255, 255, 255};
    CGImageRef masked =
        raw ? CGImageCreateWithMaskingColors(raw, white) : nullptr;
    if (masked) {
      im = [[NSImage alloc] initWithCGImage:masked size:im.size];
      CGImageRelease(masked);
    }
  }
  if (im)
    images_[@(number)] = im;
  return im;
}
- (const sophistry::EditorControlState *)control:(unsigned)tag {
  for (unsigned i = 0; i < state_.count; ++i)
    if (state_.controls[i].value.tag == tag)
      return &state_.controls[i];
  return nullptr;
}
- (int)selection:(unsigned)tag {
  for (unsigned i = 0; i < state_.selectionCount; ++i)
    if (state_.selections[i].tag == tag)
      return state_.selections[i].value;
  return 0;
}
- (void)refresh {
  UInt32 size = sizeof(state_);
  status_ = AudioUnitGetProperty(unit_, sophistry::completeEditorProperty,
                                 kAudioUnitScope_Global, _page, &state_, &size);
  if (status_ || size != sizeof(state_) || state_.version != 1 ||
      state_.count > state_.controls.size())
    return;
  const auto oldPanels = layout_.panels;
  layout_ = sophistry::completeEditorLayout(
      _page, [&](unsigned tag) { return [self selection:tag]; });
  bool backgroundChanged = oldPanels.size() != layout_.panels.size();
  if (!backgroundChanged)
    for (unsigned i = 0; i < oldPanels.size(); ++i) {
      const auto &a = oldPanels[i], &b = layout_.panels[i];
      backgroundChanged = backgroundChanged || a.id != b.id || a.x != b.x ||
                          a.y != b.y || a.image != b.image;
    }
  NSMutableSet<NSNumber *> *active = [NSMutableSet set];
  using K = sophistry::RecoveredWidget;
  for (const auto &placed : layout_.controls) {
    auto c = placed.control;
    c.x += placed.offsetX;
    c.y += placed.offsetY;
    if (c.valueRect[2]) {
      c.valueRect[0] += placed.offsetX;
      c.valueRect[1] += placed.offsetY;
    }
    if (_page == 0 && ((c.tag >= 618 && c.tag <= 622) || c.tag == 635 || c.tag == 636)) continue;
    if (c.kind == K::Label || c.kind == K::Licence)
      continue;
    [active addObject:@(c.key)];
    NSView *v = views_[@(c.key)];
    auto value = [self control:c.tag];
    if (c.kind == K::Surround) {
      CronoX3SurroundView *map = (CronoX3SurroundView *)v;
      if (!map) {
        map = [CronoX3SurroundView new];
        map.audioUnit = unit_;
        map.owner = self;
        map.sprite = [self image:396];
        v = map;
      }
      std::array<float, 7> x{}, y{};
      std::array<bool, 7> enabled{};
      for (unsigned i = 0; i < 7; ++i) {
        auto a = [self control:558 + i], b = [self control:565 + i],
             e = [self control:572 + i];
        if (a && b && e) {
          x[i] = a->normalized;
          y[i] = b->normalized;
          enabled[i] = e->value.value != 0;
        }
      }
      map.xValues = x;
      map.yValues = y;
      map.enabled = enabled;
      map.needsDisplay = YES;
    } else if (c.kind == K::Keyboard) {
      CronoX3RecoveredKeyboard *keyboard = (CronoX3RecoveredKeyboard *)v;
      if (!keyboard) {
        keyboard =
            [[CronoX3RecoveredKeyboard alloc] initWithFrame:NSZeroRect];
        keyboard.audioUnit = unit_;
        keyboard.whiteImage = [self image:382];
        keyboard.blackImage = [self image:383];
        v = keyboard;
      }
    } else if (c.kind == K::XY) {
      auto y = [self control:c.extra[0]];
      if (!value || !y)
        continue;
      CronoX3OriginalXY *xy = (CronoX3OriginalXY *)v;
      if (!xy) {
        xy = [CronoX3OriginalXY new];
        xy.audioUnit = unit_;
        xy.changeTarget = self;
        v = xy;
      }
      xy.xControl = *value;
      xy.yControl = *y;
      xy.drawingID = c.tag >= 597 ? 6 + (c.tag - 597) / 2 : (c.tag - 585) / 2;
      [xy refresh];
    } else if (c.kind == K::Wave) {
      CronoX3LoopDrawing *wave = (CronoX3LoopDrawing *)v;
      if (!wave) {
        wave = [CronoX3LoopDrawing new];
        wave.audioUnit = unit_;
        wave.owner = self;
        v = wave;
      }
      unsigned g = c.tag - 815;
      wave.drawingID = 8 + g;
      wave.generator = g;
      wave.viewport = state_.waveforms[g];
      std::array<int, 3> markers{};
      for (unsigned i = 0; i < 3; ++i) {
        auto m = [self control:953 + g + 2 * i];
        if (m)
          markers[i] = m->value.value;
      }
      wave.markers = markers;
      [wave refresh];
    } else if (c.kind == K::Arpeggiator) {
      CronoX3ArpeggiatorView *arp = (CronoX3ArpeggiatorView *)v;
      if (!arp) {
        arp = [CronoX3ArpeggiatorView new];
        arp.audioUnit = unit_;
        arp.owner = self;
        v = arp;
      }
      [arp refresh];
    } else {
      CronoX3RecoveredNode *n = (CronoX3RecoveredNode *)v;
      if (!n) {
        n = [CronoX3RecoveredNode new];
        n.audioUnit = unit_;
        n.editProperty = sophistry::editorEditProperty;
        n.owner = self;
        n.target = self;
        n.action = @selector(changed:);
        v = n;
      }
      sophistry::EditorControlState data;
      if (value)
        data = *value;
      else
        data.value.tag = c.tag;
      [n updateRecovered:c value:data];
      NSString *sampleLabel = nil;
      if (data.value.kind == 7 && c.tag != 648) {
        NSData *full = cronoxCompleteView::text(unit_, c.tag);
        std::string path;
        if (full.length)
          path.assign(static_cast<const char *>(full.bytes), full.length);
        else
          path.assign(data.value.text, strnlen(data.value.text, sizeof(data.value.text)));
        const auto name = sophistry::sampleDisplayName(path);
        sampleLabel = cronoxCompleteView::string(name.c_str(), name.size());
        n.toolTip = sampleLabel;
      }
      if ((sampleLabel || n.sampleLabel) &&
          ![sampleLabel isEqualToString:n.sampleLabel]) {
        n.sampleLabel = sampleLabel;
        n.needsDisplay = YES;
      }
      n.sprite = c.image ? [self image:c.image] : nil;
      n.circular = [self selection:657] == 0;
      if (c.kind == K::Scrollbar) {
        auto second = [self control:c.extra[0]];
        float span = second ? second->normalized : 1;
        if (n.secondaryNormalized != span) {
          n.secondaryNormalized = span;
          n.needsDisplay = YES;
        }
      }
    }
    if (!views_[@(c.key)]) {
      views_[@(c.key)] = v;
      [self addSubview:v];
    }
    if (![v isKindOfClass:CronoX3RecoveredNode.class])
      v.frame = NSMakeRect(c.x, c.y, c.width, c.height);
    if (v.hidden)
      v.hidden = NO;
  }
  for (NSNumber *key in views_)
    if (![active containsObject:key] && !views_[key].hidden)
      views_[key].hidden = YES;
  if (backgroundChanged || _page == 6)
    self.needsDisplay = YES;
}
- (void)drawRect:(NSRect)dirty {
  for (auto &p : layout_.panels) {
    NSImage *im = [self image:p.image];
    [im drawInRect:NSMakeRect(p.x, p.y, im.size.width, im.size.height)
              fromRect:NSZeroRect
             operation:NSCompositingOperationSourceOver
              fraction:1
        respectFlipped:YES
                 hints:nil];
  }
  for (auto &placed : layout_.controls) {
    auto c = placed.control;
    if (c.kind == sophistry::RecoveredWidget::Label) {
      NSMutableParagraphStyle *style = [NSMutableParagraphStyle new];
      style.alignment = NSTextAlignmentLeft;
      style.lineBreakMode = NSLineBreakByClipping;
      [[NSString stringWithUTF8String:c.caption]
              drawInRect:NSMakeRect(c.x + placed.offsetX, c.y + placed.offsetY,
                                    c.width, c.height)
          withAttributes:@{
            NSFontAttributeName : [NSFont systemFontOfSize:7],
            NSForegroundColorAttributeName : NSColor.whiteColor,
            NSParagraphStyleAttributeName : style
          }];
    } else if (c.kind == sophistry::RecoveredWidget::Licence)
      cronoxCompleteView::drawText(
          [status(unit_)[@"engine"][@"registration_accepted"] boolValue]
              ? @"Enregistré"
              : @"À configurer",
          NSMakeRect(c.x + placed.offsetX, c.y + placed.offsetY, c.width,
                     c.height),
          9);
  }
}
- (void)changed:(id)sender {
  [self refresh];
  [NSApp sendAction:@selector(completeChanged:) to:_changeTarget from:self];
}
- (void)chooseNode:(CronoX3RecoveredNode *)node value:(NSInteger)value {
  if (sophistry::editorFileCommand(node.state.tag, unsigned(value))) {
    [self fileCommand:node.state.tag operation:unsigned(value)];
    return;
  }
  [node activateNormalized:float(value - node.state.minimum) /
                           MAX(1, node.state.maximum - node.state.minimum)];
}
- (void)moduleMenu:(unsigned)tag value:(unsigned)value {
  if (sophistry::editorFileCommand(tag, value)) {
    [self fileCommand:tag operation:value];
    return;
  }
  if (!cronoxCompleteView::edit(unit_, tag, float(value) / 4))
    NSBeep();
  [self changed:nil];
}
- (void)fileCommand:(unsigned)tag operation:(unsigned)operation {
  sophistry::EditorFileInfo info;
  UInt32 bytes = sizeof(info);
  if (AudioUnitGetProperty(unit_, sophistry::editorFileInfoProperty,
                           kAudioUnitScope_Global, tag | (operation << 16),
                           &info, &bytes) ||
      info.version != 1 || info.count > info.extensions.size()) {
    NSBeep();
    return;
  }
  NSSavePanel *panel =
      info.save ? [NSSavePanel savePanel] : [NSOpenPanel openPanel];
  if (!info.save) {
    NSOpenPanel *open = (NSOpenPanel *)panel;
    open.canChooseDirectories = NO;
    open.canChooseFiles = YES;
    open.allowsMultipleSelection = NO;
  }
  NSMutableArray *extensions = [NSMutableArray array];
  for (unsigned i = 0; i < info.count; ++i) {
    NSString *s = cronoxCompleteView::string(info.extensions[i].data(),
                                                info.extensions[i].size());
    if (s.length)
      [extensions addObject:s];
  }
  if (extensions.count)
    panel.allowedFileTypes = extensions;
  panel.title = cronoxCompleteView::string(info.title, sizeof(info.title));
  if (info.save)
    panel.nameFieldStringValue = cronoxCompleteView::string(
        info.suggestedName, sizeof(info.suggestedName));
  [panel beginSheetModalForWindow:self.window
                completionHandler:^(NSModalResponse result) {
                  if (result == NSModalResponseOK) {
                    BOOL scoped =
                        [panel.URL startAccessingSecurityScopedResource];
                    BOOL ok = cronoxCompleteView::file(unit_, tag, operation,
                                                          panel.URL.path);
                    if (scoped)
                      [panel.URL stopAccessingSecurityScopedResource];
                    if (!ok) {
                      NSAlert *a = [NSAlert new];
                      a.messageText =
                          @"Le fichier a été refusé par la routine d’origine.";
                      a.informativeText = @"Vérifiez le format et utilisez un "
                                          @"chemin de moins de 256 octets.";
                      [a runModal];
                    }
                    [self changed:nil];
                  }
                }];
}
- (void)midiCommand:(NSPopUpButton *)sender {
  NSInteger index = sender.indexOfSelectedItem - 1;
  [sender selectItemAtIndex:0];
  if (index < 0)
    return;
  if (index == 3 || index == 6) {
    NSAlert *a = [NSAlert new];
    a.messageText = index == 3 ? @"Effacer toutes les affectations MIDI ?"
                               : @"Rétablir les affectations MIDI d’usine ?";
    [a addButtonWithTitle:@"Confirmer"];
    [a addButtonWithTitle:@"Annuler"];
    if ([a runModal] != NSAlertFirstButtonReturn)
      return;
  }
  if (sophistry::editorFileCommand(610, unsigned(index)))
    [self fileCommand:610 operation:unsigned(index)];
  else if (cronoxCompleteView::edit(unit_, 610, float(index) / 6))
    [self changed:nil];
}
- (void)openNode:(CronoX3RecoveredNode *)node {
  NSOpenPanel *p = [NSOpenPanel openPanel];
  p.canChooseFiles = YES;
  p.canChooseDirectories = NO;
  p.allowsMultipleSelection = NO;
  p.allowedFileTypes = node.state.tag == 701
                           ? @[ @"tun" ]
                           : @[ @"wav", @"aif", @"aiff", @"d4t", @"d4u" ];
  unsigned tag = node.state.tag;
  [p beginSheetModalForWindow:self.window
            completionHandler:^(NSModalResponse result) {
              if (result == NSModalResponseOK) {
                BOOL scoped = [p.URL startAccessingSecurityScopedResource];
                BOOL ok = cronoxCompleteView::text(
                    unit_, tag,
                    [p.URL.path dataUsingEncoding:NSUTF8StringEncoding]);
                if (scoped)
                  [p.URL stopAccessingSecurityScopedResource];
                if (!ok)
                  NSBeep();
                [self changed:nil];
              }
            }];
}
- (void)actionNode:(CronoX3RecoveredNode *)node {
  auto c = node.recovered;
  if (c.extra[0] == 4 || c.extra[0] == 43) {
    NSAlert *a = [NSAlert new];
    a.messageText = @"Décharger le sample sélectionné ?";
    [a addButtonWithTitle:@"Décharger"];
    [a addButtonWithTitle:@"Annuler"];
    if ([a runModal] != NSAlertFirstButtonReturn)
      return;
  }
  sophistry::EditorAction action{1, c.key};
  OSStatus status =
      AudioUnitSetProperty(unit_, sophistry::editorActionProperty,
                           kAudioUnitScope_Global, 0, &action, sizeof(action));
  if (status)
    NSBeep();
  if (c.extra[0] == 94)
    [NSApp sendAction:@selector(completeSelectPage:)
                   to:_changeTarget
                 from:@(c.extra[2])];
  [self changed:nil];
}
- (void)textNode:(CronoX3RecoveredNode *)node {
  NSAlert *a = [NSAlert new];
  a.messageText =
      cronoxCompleteView::string(node.state.name, sizeof(node.state.name));
  NSTextField *field =
      [[NSTextField alloc] initWithFrame:NSMakeRect(0, 0, 220, 24)];
  field.stringValue =
      cronoxCompleteView::string(node.state.text, sizeof(node.state.text));
  a.accessoryView = field;
  [a addButtonWithTitle:@"Appliquer"];
  [a addButtonWithTitle:@"Annuler"];
  if ([a runModal] == NSAlertFirstButtonReturn) {
    if (!cronoxCompleteView::text(
            unit_, node.state.tag,
            [field.stringValue dataUsingEncoding:NSUTF8StringEncoding]))
      NSBeep();
    [self changed:nil];
  }
}
- (BOOL)setControl:(unsigned)tag normalized:(float)value {
  [self refresh];
  if (tag >= 52 && tag <= 55) {
    for (NSView *v in views_.allValues)
      if (!v.hidden && [v isKindOfClass:CronoX3RecoveredNode.class]) {
        auto *node = (CronoX3RecoveredNode *)v;
        if (sophistry::generatorForTypeTag(node.state.tag) != tag - 52)
          continue;
        for (NSMenuItem *item in [node recoveredMenu].itemArray)
          if ([item.representedObject isKindOfClass:NSDictionary.class] &&
              [item.representedObject[@"full_loop"] unsignedIntValue] == tag) {
            float current = 0;
            if (AudioUnitGetParameter(unit_, tag, kAudioUnitScope_Global, 0,
                                      &current))
              return NO;
            if ((current >= .5f) != (value >= .5f))
              [node chooseRecovered:item];
            return !AudioUnitGetParameter(unit_, tag, kAudioUnitScope_Global, 0,
                                          &current) &&
                   ((current >= .5f) == (value >= .5f));
          }
      }
    return NO;
  }
  const auto *placed = sophistry::completeEditorControl(layout_, tag);
  if (!placed)
    return NO;
  for (NSView *v in views_.allValues)
    if (!v.hidden && [v isKindOfClass:CronoX3RecoveredNode.class] &&
        ((CronoX3RecoveredNode *)v).recovered.key == placed->control.key) {
      auto *node = (CronoX3RecoveredNode *)v;
      if (node.recovered.kind == sophistry::RecoveredWidget::Menu) {
        // Test the menu actually offered by mouseDown, including each mode's
        // generator module commands, before activating its selected value.
        NSMenu *menu = [node recoveredMenu];
        const NSInteger requested =
            node.state.minimum +
            lround(std::clamp(value, 0.f, 1.f) *
                   (node.state.maximum - node.state.minimum));
        BOOL found = NO;
        unsigned modules = 0, generator = sophistry::generatorForTypeTag(tag);
        for (NSMenuItem *item in menu.itemArray) {
          if ([item.representedObject isKindOfClass:NSNumber.class]) {
            if (generator < 4 &&
                [item.representedObject unsignedIntValue] == 643 + generator)
              ++modules;
          } else if (!item.representedObject && !item.separatorItem &&
                     item.tag == requested)
            found = YES;
        }
        if (!found || (generator < 4 && modules != 5))
          return NO;
      }
      return [node activateNormalized:value];
    }
  return NO;
}
- (BOOL)setText:(unsigned)tag value:(NSString *)value {
  [self refresh];
  for (NSView *v in views_.allValues)
    if (!v.hidden && [v isKindOfClass:CronoX3RecoveredNode.class]) {
      auto *n = (CronoX3RecoveredNode *)v;
      if (n.state.tag == tag &&
          n.recovered.kind == sophistry::RecoveredWidget::Text) {
        BOOL ok = cronoxCompleteView::text(
            unit_, tag, [value dataUsingEncoding:NSUTF8StringEncoding]);
        [self changed:nil];
        return ok;
      }
    }
  return NO;
}
- (NSDictionary *)report {
  NSMutableArray *controls = [NSMutableArray array],
                 *panels = [NSMutableArray array],
                 *waves = [NSMutableArray array];
  BOOL bounds = YES, images = YES, pixelSizes = YES;
  for (auto &p : layout_.panels) {
    NSImage *image = [self image:p.image];
    images = images && image;
    pixelSizes = pixelSizes && cronoxGeneratorView::originalPixelSize(image);
    [panels addObject:@{
      @"id" : @(p.id),
      @"image" : @(p.image),
      @"x" : @(p.x),
      @"y" : @(p.y)
    }];
  }
  for (NSView *v in views_.allValues)
    if (!v.hidden) {
      bounds = bounds && NSContainsRect(self.bounds, v.frame);
      if ([v isKindOfClass:CronoX3RecoveredNode.class]) {
        auto *n = (CronoX3RecoveredNode *)v;
        images = images && (!n.spec.image || n.sprite);
        pixelSizes = pixelSizes &&
                     (!n.spec.image ||
                      cronoxGeneratorView::originalPixelSize(n.sprite));
        [controls addObject:@{
          @"tag" : @(n.state.tag),
          @"kind" : @(int(n.recovered.kind)),
          @"value" : @(n.state.value),
          @"normalized" : @(n.originalNormalized),
          @"au_parameter" : n.state.auParameter == sophistry::noAUParameter
              ? [NSNull null]
              : @(n.state.auParameter),
          @"sprite" : @(n.spec.image),
          @"sample_label" : n.sampleLabel ?: @"",
          @"frame" : @[
            @(v.frame.origin.x), @(v.frame.origin.y), @(v.frame.size.width),
            @(v.frame.size.height)
          ]
        }];
      }
      if ([v isKindOfClass:CronoX3OriginalDrawing.class])
        [waves addObject:[(CronoX3OriginalDrawing *)v report]];
    }
  return @{
    @"status" : @(status_),
    @"page" : @(_page),
    @"controls" : controls,
    @"panels" : panels,
    @"drawings" : waves,
    @"active_controls_in_bounds" : @(bounds),
    @"sprites_loaded" : @(images),
    @"image_dimensions_match_original_pixels" : @(pixelSizes),
    @"arpeggiator_bytes" : @(cronoxCompleteView::text(unit_, 648).length)
  };
}
- (NSDictionary *)generatorReport {
  NSMutableDictionary *r = [[self report] mutableCopy];
  r[@"property_status"] = @(status_);
  r[@"pair"] = @(_page == 2 ? 1 : 0);
  r[@"types"] = @[
    @([self selection:769]), @([self selection:770]), @([self selection:777]),
    @([self selection:778])
  ];
  NSMutableArray *w = [NSMutableArray array];
  for (unsigned g = 0; g < 2; ++g) {
    NSDictionary *found = nil;
    for (NSView *v in views_.allValues)
      if ([v isKindOfClass:CronoX3LoopDrawing.class] &&
          ((CronoX3LoopDrawing *)v).generator == g)
        found = [(CronoX3LoopDrawing *)v report];
    [w addObject:found ?: @{
      @"status" : @0,
      @"lines" : @0,
      @"source_frames" : @0,
      @"visible" : @NO
    }];
  }
  r[@"waveforms"] = w;
  return r;
}
- (NSUInteger)mainDialCount {
  NSUInteger count = 0;
  for (NSView *v in views_.allValues)
    if ([v isKindOfClass:CronoX3RecoveredNode.class]) {
      auto c = ((CronoX3RecoveredNode *)v).recovered;
      if (c.panel == 1 && c.kind == sophistry::RecoveredWidget::Dial)
        ++count;
    }
  return count;
}
- (NSUInteger)mainSpriteCount {
  NSUInteger count = 0;
  for (NSView *v in views_.allValues)
    if ([v isKindOfClass:CronoX3RecoveredNode.class]) {
      auto n = (CronoX3RecoveredNode *)v;
      auto c = n.recovered;
      if (c.panel == 1 && c.kind == sophistry::RecoveredWidget::Dial &&
          n.sprite)
        ++count;
    }
  return count;
}
@end
