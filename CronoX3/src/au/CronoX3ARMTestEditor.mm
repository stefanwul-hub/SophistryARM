// Original CronoX 3.6.6 panels with native Cocoa controls and translated getters/setters.
#include "BankAccess.h"
#include "PresetBrowser.h"
#include "SophistryProperties.h"
#include "CronoXIdentity.h"
#include "CronoXPresetNames.h"
#import <AppKit/AppKit.h>
#import <AudioToolbox/AUCocoaUIView.h>
#import <AudioToolbox/AudioToolbox.h>
#include <cmath>
#include <cstring>
#include <vector>
namespace {
NSTextField* crxLabel(NSRect rect,NSString* text,CGFloat size) {
  auto* field=[[NSTextField alloc] initWithFrame:rect];
  field.stringValue=text;field.editable=NO;field.selectable=YES;
  field.bordered=NO;field.drawsBackground=NO;field.textColor=NSColor.whiteColor;
  field.font=[NSFont fontWithName:@"Helvetica" size:size];return field;
}
NSButton* crxButton(NSRect rect,NSString* title,id target,SEL selector) {
  auto* value=[NSButton buttonWithTitle:title target:target action:selector];
  value.frame=rect;value.bezelStyle=NSBezelStyleRounded;return value;
}
NSDictionary* crxStatus(AudioUnit unit) {
  std::vector<char> bytes(sophistry::runtimeStatusBytes);
  UInt32 size=UInt32(bytes.size());
  if(AudioUnitGetProperty(unit,sophistry::runtimeStatusProperty,kAudioUnitScope_Global,0,bytes.data(),&size)) return @{};
  NSData* data=[NSData dataWithBytes:bytes.data() length:strnlen(bytes.data(),bytes.size())];
  id parsed=[NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
  if(!parsed) {
    NSString* legacy=[[NSString alloc] initWithData:data encoding:NSMacOSRomanStringEncoding];
    NSData* utf=[legacy dataUsingEncoding:NSUTF8StringEncoding];
    parsed=utf?[NSJSONSerialization JSONObjectWithData:utf options:0 error:nil]:nil;
  }
  return [parsed isKindOfClass:NSDictionary.class]?parsed:@{};
}
UInt32 crxBig32(const unsigned char* p) {
  return UInt32(p[0])<<24|UInt32(p[1])<<16|UInt32(p[2])<<8|UInt32(p[3]);
}
NSString* crxError(AudioUnit unit,OSStatus status) {
  CFStringRef raw=nullptr;UInt32 size=sizeof(raw);
  if(!AudioUnitGetProperty(unit,0x53704572,kAudioUnitScope_Global,0,&raw,&size)&&raw) {
    NSString* value=[(__bridge NSString*)raw copy];CFRelease(raw);
    if(value.length)return [NSString stringWithFormat:@"%@ (code %d)",value,int(status)];
  }
  return [NSString stringWithFormat:@"Code Audio Unit : %d",int(status)];
}
}
namespace { NSDictionary *status(AudioUnit unit) { return crxStatus(unit); } }
#include "CronoXCompleteEditorView.h"
@interface CronoX3ARMTestEditorView : NSView
- (instancetype)initWithAudioUnit:(AudioUnit)unit;
- (BOOL)loadPresetURL:(NSURL*)url;
- (NSDictionary*)cronoxComparisonReport;
- (NSArray*)cronoxEditorPagesReport;
@end
@implementation CronoX3ARMTestEditorView {
  AudioUnit unit_;
  NSTextField* name_;NSTextField* activity_;NSTextField* notice_;
  NSURL* current_;NSTimer* refresh_;
  NSImage* originalFrame_;
  CronoX3CompletePanel *root_,*panel_,*bottom_;
  NSMutableArray<NSView*>* browser_;
  unsigned page_,bottomPage_;
}
- (BOOL)isFlipped {return YES;}
- (instancetype)initWithAudioUnit:(AudioUnit)unit {
  self=[super initWithFrame:NSMakeRect(0,0,762,521)];if(!self)return nil;
  unit_=unit;page_=0;bottomPage_=8;NSBundle* bundle=[NSBundle bundleForClass:self.class];
  originalFrame_=cronoxGeneratorView::image(bundle,128);
  root_=[[CronoX3CompletePanel alloc] initWithAudioUnit:unit bundle:bundle];
  root_.page=9;root_.frame=NSMakeRect(0,0,762,477);root_.changeTarget=self;[self addSubview:root_];
  panel_=[[CronoX3CompletePanel alloc] initWithAudioUnit:unit bundle:bundle];
  panel_.page=0;panel_.changeTarget=self;[self addSubview:panel_];
  bottom_=[[CronoX3CompletePanel alloc] initWithAudioUnit:unit bundle:bundle];
  bottom_.page=8;bottom_.frame=NSMakeRect(0,348,762,129);bottom_.changeTarget=self;[self addSubview:bottom_];
  browser_=[NSMutableArray array];
  name_=crxLabel(NSMakeRect(27,228,138,28),@"…",11);[self addSubview:name_];[browser_ addObject:name_];
  const SEL actions[]={@selector(previous:),@selector(load:),@selector(next:),@selector(save:)};
  NSArray* titles=@[@"Prev",@"Load",@"Next",@"Save"];
  for(unsigned i=0;i<4;++i){
    NSButton* b=crxButton(NSMakeRect(21+38*i,265,38,15),@"",self,actions[i]);
    b.bordered=NO;b.toolTip=titles[i];[self addSubview:b];[browser_ addObject:b];
  }
  [self addSubview:crxLabel(NSMakeRect(10,482,305,16),@"CronoX 3 ARM64 port OA 2026 . CRX007",11)];
  [self addSubview:crxButton(NSMakeRect(320,487,132,24),@"Charger un son…",self,@selector(load:))];
  [self addSubview:crxButton(NSMakeRect(458,487,132,24),@"Banque de sons…",self,@selector(bank:))];
  [self addSubview:crxButton(NSMakeRect(596,487,156,24),@"Copier le diagnostic",self,@selector(diagnostic:))];
  activity_=crxLabel(NSMakeRect(10,503,305,16),@"",9);[self addSubview:activity_];
  notice_=crxLabel(NSMakeRect(10,503,305,16),@"",9);notice_.textColor=NSColor.lightGrayColor;[self addSubview:notice_];
  [self refresh];return self;
}
- (void)completeChanged:(id)sender { [self refresh]; }
- (void)completeSelectPage:(NSNumber*)page {
  cronoxCompleteView::edit(unit_,603,float(std::clamp(page.intValue,0,6))/6);[self refresh];
}
- (void)dealloc {[refresh_ invalidate];}
- (void)viewDidMoveToWindow {
  [super viewDidMoveToWindow];[refresh_ invalidate];refresh_=nil;
  if(self.window) {
    __weak CronoX3ARMTestEditorView* weak=self;
    refresh_=[NSTimer scheduledTimerWithTimeInterval:.5 repeats:YES block:^(NSTimer*){[weak refresh];}];
  }
}
- (void)drawRect:(NSRect)dirty {
  [[NSColor colorWithRed:.13 green:.15 blue:.18 alpha:1] setFill];NSRectFill(self.bounds);
  [originalFrame_ drawInRect:NSMakeRect(0,0,762,477) fromRect:NSZeroRect operation:NSCompositingOperationSourceOver fraction:1 respectFlipped:YES hints:nil];
}
- (void)refresh {
  sophistry::CompleteEditorState shell;UInt32 shellBytes=sizeof(shell);
  if(!AudioUnitGetProperty(unit_,sophistry::completeEditorProperty,kAudioUnitScope_Global,9,&shell,&shellBytes)) {
    for(unsigned i=0;i<shell.selectionCount;++i) {
      if(shell.selections[i].tag==603)page_=std::clamp(shell.selections[i].value,0,6);
      if(shell.selections[i].tag==604)bottomPage_=7+std::clamp(shell.selections[i].value,0,1);
    }
  }
  root_.page=9;panel_.page=page_;bottom_.page=bottomPage_;
  [root_ refresh];[panel_ refresh];[bottom_ refresh];
  for(NSView* v in browser_)v.hidden=page_!=0;
  NSDictionary* s=crxStatus(unit_);
  NSString* preset=[s[@"preset_name"] isKindOfClass:NSString.class]?s[@"preset_name"]:@"";
  if(!cronox::usablePresetName(preset.UTF8String?:"")) {
    AUPreset value{};UInt32 size=sizeof(value);
    if(!AudioUnitGetProperty(unit_,kAudioUnitProperty_PresentPreset,kAudioUnitScope_Global,0,&value,&size)&&value.presetName) {
      preset=[(__bridge NSString*)value.presetName copy];CFRelease(value.presetName);
    }
  }
  name_.stringValue=cronox::usablePresetName(preset.UTF8String?:"")?preset:@"état initial";
  float master=0;BOOL hasMaster=!AudioUnitGetParameter(unit_,134,kAudioUnitScope_Global,0,&master);
  double peak=[s[@"maximum_output"] doubleValue];
  NSString* level=peak>0?[NSString stringWithFormat:@"%.1f dBFS",20*std::log10(peak)]:@"silence";
  activity_.stringValue=[NSString stringWithFormat:@"MIDI : %@ notes · Sortie : %@%@",s[@"notes_received"]?:@0,level,
    hasMaster?[NSString stringWithFormat:@" · Master : %.1f dB",double(master)]:@""];
  NSString* error=[s[@"error"] isKindOfClass:NSString.class]?s[@"error"]:@"";
  notice_.stringValue=error.length?error:@"";notice_.hidden=!error.length;activity_.hidden=error.length>0;
}
- (void)failure:(NSString*)message {
  notice_.stringValue=message?:@"Opération impossible";
  NSAlert* alert=[NSAlert new];alert.messageText=@"CronoX 3 ARM Test";alert.informativeText=message?:@"";
  [alert runModal];
}
- (BOOL)loadPresetURL:(NSURL*)url {
  BOOL access=[url startAccessingSecurityScopedResource];
  NSError* error=nil;NSData* data=[NSData dataWithContentsOfURL:url options:0 error:&error];
  OSStatus result=kAudioUnitErr_InvalidPropertyValue;NSString* importedName=nil;
  if(data.length && data.length<=2*1024*1024) {
    if([url.pathExtension.lowercaseString isEqualToString:@"aupreset"]) {
      id plist=[NSPropertyListSerialization propertyListWithData:data options:NSPropertyListImmutable format:nil error:&error];
      if([plist isKindOfClass:NSDictionary.class]) {
        CFPropertyListRef state=(__bridge CFPropertyListRef)plist;
        result=AudioUnitSetProperty(unit_,kAudioUnitProperty_ClassInfo,kAudioUnitScope_Global,0,&state,sizeof(state));
      }
    } else {
      const auto* bytes=static_cast<const unsigned char*>(data.bytes);
      if(data.length>=60 && !std::memcmp(bytes,"CcnK",4) && !std::memcmp(bytes+8,"FPCh",4) && crxBig32(bytes+56)==data.length-60) {
        auto name=cronox::fxpProgramName(data.bytes,data.length);
        importedName=!cronox::usablePresetName(name)?url.URLByDeletingPathExtension.lastPathComponent:cronoxCompleteView::string(name.c_str(),name.size());
        result=AudioUnitSetProperty(unit_,sophistry::importProgramProperty,kAudioUnitScope_Global,0,bytes+60,UInt32(data.length-60));
      }
    }
  }
  if(access)[url stopAccessingSecurityScopedResource];
  if(result) {notice_.stringValue=error.localizedDescription?:crxError(unit_,result);return NO;}
  if(importedName.length) {
    AUPreset label{-1,(__bridge CFStringRef)importedName};
    result=AudioUnitSetProperty(unit_,kAudioUnitProperty_PresentPreset,kAudioUnitScope_Global,0,&label,sizeof(label));
    if(result){notice_.stringValue=crxError(unit_,result);return NO;}
  }
  current_=url;[self refresh];return YES;
}
- (void)load:(id)sender {
  NSOpenPanel* panel=[NSOpenPanel openPanel];panel.title=@"Charger un son CronoX 3";
  panel.allowedFileTypes=@[@"fxp",@"aupreset"];panel.allowsMultipleSelection=NO;
  if(current_)panel.directoryURL=current_.URLByDeletingLastPathComponent;
  if([panel runModal]==NSModalResponseOK && ![self loadPresetURL:panel.URL])[self failure:notice_.stringValue];
}
- (void)navigate:(NSInteger)direction {
  if(!current_){[self load:nil];return;}
  NSURL* next=sophistryPresetBrowser::adjacent(sophistryPresetBrowser::directory(current_.URLByDeletingLastPathComponent),current_,direction);
  if(next){if(![self loadPresetURL:next])[self failure:notice_.stringValue];}else [self load:nil];
}
- (void)previous:(id)sender {[self navigate:-1];}
- (void)next:(id)sender {[self navigate:1];}
- (void)save:(id)sender {
  NSSavePanel* panel=[NSSavePanel savePanel];panel.allowedFileTypes=@[@"aupreset"];
  panel.title=@"Enregistrer le son";panel.nameFieldStringValue=@"CronoX 3 ARM Test.aupreset";
  if([panel runModal]!=NSModalResponseOK)return;
  CFPropertyListRef state=nullptr;UInt32 size=sizeof(state);
  OSStatus result=AudioUnitGetProperty(unit_,kAudioUnitProperty_ClassInfo,kAudioUnitScope_Global,0,&state,&size);
  if(result||!state){[self failure:crxError(unit_,result)];return;}
  NSError* error=nil;NSData* data=[NSPropertyListSerialization dataWithPropertyList:(__bridge id)state format:NSPropertyListXMLFormat_v1_0 options:0 error:&error];CFRelease(state);
  if(!data||![data writeToURL:panel.URL options:NSDataWritingAtomic error:&error]) {[self failure:error.localizedDescription];return;}
  current_=panel.URL;notice_.stringValue=@"Son enregistré.";notice_.hidden=NO;activity_.hidden=YES;
}
- (void)bank:(id)sender {
  NSOpenPanel* panel=[NSOpenPanel openPanel];panel.title=@"Banque de sons CronoX 3";
  panel.canChooseFiles=NO;panel.canChooseDirectories=YES;panel.allowsMultipleSelection=NO;
  if([panel runModal]!=NSModalResponseOK)return;
  NSURL* url=panel.URL;NSData* path=[url.path dataUsingEncoding:NSUTF8StringEncoding];
  CFDataRef raw=sophistryMac::createBankBookmark((__bridge CFURLRef)url);
  NSData* bookmark=raw?[(__bridge NSData*)raw copy]:nil;if(raw)CFRelease(raw);
  sophistry::BankLocationHeader header;header.pathBytes=UInt32(path.length+1);header.bookmarkBytes=UInt32(bookmark.length);
  NSMutableData* request=[NSMutableData dataWithBytes:&header length:sizeof(header)];
  [request appendData:path];unsigned char terminator=0;[request appendBytes:&terminator length:1];if(bookmark)[request appendData:bookmark];
  OSStatus result=AudioUnitSetProperty(unit_,sophistry::sampleRootProperty,kAudioUnitScope_Global,0,request.bytes,UInt32(request.length));
  if(result)[self failure:crxError(unit_,result)];else {[self refresh];notice_.stringValue=@"Emplacement de la banque enregistré pour ARM Test.";notice_.hidden=NO;activity_.hidden=YES;}
}
- (void)diagnostic:(id)sender {
  NSDictionary* s=crxStatus(unit_);NSData* data=[NSJSONSerialization dataWithJSONObject:s options:NSJSONWritingPrettyPrinted error:nil];
  NSString* text=data?[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding]:@"Diagnostic indisponible";
  [NSPasteboard.generalPasteboard clearContents];[NSPasteboard.generalPasteboard setString:text forType:NSPasteboardTypeString];
  notice_.stringValue=@"Diagnostic copié.";notice_.hidden=NO;activity_.hidden=YES;
}
- (NSArray*)cronoxEditorPagesReport {
  unsigned original=page_;NSMutableArray* pages=[NSMutableArray array];
  for(unsigned page=0;page<7;++page) {
    [self completeSelectPage:@(page)];
    [pages addObject:[panel_ report]];
  }
  [self completeSelectPage:@(original)];return pages;
}
- (NSDictionary*)cronoxComparisonReport {
  NSMutableArray* buttons=[NSMutableArray array];NSString* footer=@"";
  for(NSView* v in self.subviews) {
    if([v isKindOfClass:NSButton.class] && v.frame.origin.y>477)
      [buttons addObject:@{@"title":[(NSButton*)v title],@"center_y":@(NSMidY(v.frame))}];
    if([v isKindOfClass:NSTextField.class] && [[(NSTextField*)v stringValue] hasPrefix:@"CronoX 3 ARM64 port"])
      footer=[(NSTextField*)v stringValue];
  }
  return @{@"comparison_view":@YES,@"original_panels_available":@YES,@"original_panel_recovery_complete":@NO,@"subtype":@"CrT3",@"width":@(self.frame.size.width),@"height":@(self.frame.size.height),@"preset_name":name_.stringValue,@"original_font_available":@([NSFont fontWithName:@"Helvetica" size:11]!=nil),@"font_family":@"Helvetica",@"footer":footer,@"utility_buttons":buttons,@"main":[panel_ report],@"shell":[root_ report],@"bottom":[bottom_ report]};
}
@end
@interface CronoX3ARMTestCocoaFactory : NSObject <AUCocoaUIBase>
@end
@implementation CronoX3ARMTestCocoaFactory
- (unsigned)interfaceVersion {return 0;}
- (NSString*)description {return @"CronoX 3 ARM Test";}
- (NSView*)uiViewForAudioUnit:(AudioUnit)unit withSize:(NSSize)size {
  return [[CronoX3ARMTestEditorView alloc] initWithAudioUnit:unit];
}
@end
