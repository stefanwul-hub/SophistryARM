// Original CronoX 3.6.6 panels with native Cocoa controls and translated getters/setters.
#include "BankAccess.h"
#include "PresetBrowser.h"
#include "SophistryProperties.h"
#include "CronoXIdentity.h"
#include "CronoXPresetNames.h"
#include "CronoXPresetCatalog.h"
#include "CronoXCocoaPaths.h"
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
// CMenuFileList / createMenuFileList: Helvetica 12, RGB(210,210,210),
// rect y=191/207 + Main panel y=37, height=14+1. Draw with the original baseline.
@interface CronoX3PresetMenuField : NSTextField
@end
@implementation CronoX3PresetMenuField
- (BOOL)isFlipped{return YES;}
- (void)drawRect:(NSRect)dirty {cronoxGeneratorView::text(self.stringValue,self.bounds,12,self.textColor,1);}
- (void)mouseDown:(NSEvent*)event {[NSApp sendAction:self.action to:self.target from:self];}
@end
namespace {
CronoX3PresetMenuField* crxMenu(NSRect frame,id target,SEL action) {
 auto* field=[[CronoX3PresetMenuField alloc] initWithFrame:frame];
 field.stringValue=@"- - -";field.font=[NSFont fontWithName:@"Helvetica" size:12];
 field.textColor=[NSColor colorWithDeviceRed:210./255 green:210./255 blue:210./255 alpha:1];
 field.bordered=NO;field.drawsBackground=NO;field.editable=NO;field.selectable=NO;
 field.alignment=NSTextAlignmentCenter;field.target=target;field.action=action;return field;
}
NSString* crxPreference(CFStringRef key) {
 CFPropertyListRef raw=CFPreferencesCopyValue(key,CFSTR("com.linplug.CronoX3.ARMTest"),kCFPreferencesCurrentUser,kCFPreferencesAnyHost);
 NSString* result=raw&&CFGetTypeID(raw)==CFStringGetTypeID()?[(__bridge NSString*)raw copy]:@"";if(raw)CFRelease(raw);return result;
}
NSURL* crxURL(const std::filesystem::path& p) {std::error_code e;return p.empty()?nil:[NSURL fileURLWithFileSystemRepresentation:p.c_str() isDirectory:std::filesystem::is_directory(p,e) relativeToURL:nil];}
}
@interface CronoX3ARMTestEditorView : NSView
- (instancetype)initWithAudioUnit:(AudioUnit)unit;
- (BOOL)loadPresetURL:(NSURL*)url;
- (NSDictionary*)cronoxComparisonReport;
- (NSArray*)cronoxEditorPagesReport;
- (NSMenu*)bankMenu;
- (NSMenu*)presetMenu;
- (NSDictionary*)presetBrowserReport;
- (void)setPresetLibraryURL:(NSURL*)root persist:(BOOL)persist;
- (NSDictionary*)cronoxKeyboardReport;
@end
@implementation CronoX3ARMTestEditorView {
  AudioUnit unit_;
  NSTextField* name_;NSTextField* bank_;NSTextField* activity_;NSTextField* notice_;
  NSURL* current_;NSURL* library_;NSURL* libraryOverride_;NSURL* selectedBank_;BOOL emptyBank_;NSTimer* refresh_;
  std::shared_ptr<sophistryMac::BankAccess> libraryAccess_;
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
  bank_=crxMenu(NSMakeRect(27,228,138,15),self,@selector(showBankMenu:));[self addSubview:bank_];[browser_ addObject:bank_];
  name_=crxMenu(NSMakeRect(27,244,138,15),self,@selector(showPresetMenu:));[self addSubview:name_];[browser_ addObject:name_];
  NSString* path=crxPreference(CFSTR("CronoX3ARMPresetRoot"));
  CFPropertyListRef bookmark=CFPreferencesCopyValue(CFSTR("CronoX3ARMPresetBookmark"),CFSTR("com.linplug.CronoX3.ARMTest"),kCFPreferencesCurrentUser,kCFPreferencesAnyHost);
  if(bookmark&&CFGetTypeID(bookmark)==CFDataGetTypeID())libraryAccess_=sophistryMac::openBankBookmark((CFDataRef)bookmark,cronox::cocoa::path(path).c_str());
  if(bookmark)CFRelease(bookmark);
  const SEL actions[]={@selector(previous:),@selector(load:),@selector(next:),@selector(save:)};
  NSArray* titles=@[@"Prev",@"Load",@"Next",@"Save"];
  for(unsigned i=0;i<4;++i){
    NSButton* b=crxButton(NSMakeRect(21+38*i,265,38,15),@"",self,actions[i]);
    b.bordered=NO;b.toolTip=titles[i];[self addSubview:b];[browser_ addObject:b];
  }
  [self addSubview:crxLabel(NSMakeRect(10,487,305,16),@"CronoX 3 ARM64 port OA 2026 . CRX012",9)];
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
  std::array<char,sophistry::presetSourceBytes> source{};UInt32 sourceBytes=UInt32(source.size());
  if(!AudioUnitGetProperty(unit_,sophistry::presetSourceProperty,kAudioUnitScope_Global,0,source.data(),&sourceBytes)&&source[0]) {
    NSURL* url=[NSURL fileURLWithFileSystemRepresentation:source.data() isDirectory:NO relativeToURL:nil];
    if(![url.path isEqual:current_.path]){current_=url;selectedBank_=url.URLByDeletingLastPathComponent;emptyBank_=NO;}
  }
  name_.stringValue=emptyBank_?@"- - -":cronox::usablePresetName(preset.UTF8String?:"")?preset:@"- - -";
  NSString* bank=[s[@"preset_bank_name"] isKindOfClass:NSString.class]?s[@"preset_bank_name"]:@"";
  if(!bank.length) {
    CFPropertyListRef saved=CFPreferencesCopyValue(CFSTR("CronoX3ARMSampleRoot"),CFSTR("com.linplug.CronoX3.ARMTest"),kCFPreferencesCurrentUser,kCFPreferencesAnyHost);
    if(saved) {if(CFGetTypeID(saved)==CFStringGetTypeID())bank=[(__bridge NSString*)saved lastPathComponent];CFRelease(saved);}
  }
  bank_.stringValue=bank.length?bank:@"—";
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
  std::array<char,sophistry::presetBankNameBytes> existing{};UInt32 bankBytes=UInt32(existing.size());
  bool hasBank=!AudioUnitGetProperty(unit_,sophistry::presetBankNameProperty,kAudioUnitScope_Global,0,existing.data(),&bankBytes)&&existing[0];
  if(importedName.length||!hasBank) {
    const auto bankLabel=cronox::catalog::label(url.URLByDeletingLastPathComponent.path.fileSystemRepresentation);
    const char* label=bankLabel.c_str();
    result=AudioUnitSetProperty(unit_,sophistry::presetBankNameProperty,kAudioUnitScope_Global,0,label,UInt32(std::strlen(label)+1));
    if(result){notice_.stringValue=crxError(unit_,result);return NO;}
  }
  const char* source=url.path.fileSystemRepresentation;
  result=AudioUnitSetProperty(unit_,sophistry::presetSourceProperty,kAudioUnitScope_Global,0,source,UInt32(std::strlen(source)+1));
  if(result){notice_.stringValue=crxError(unit_,result);return NO;}
  current_=url;selectedBank_=url.URLByDeletingLastPathComponent;emptyBank_=NO;[self refresh];return YES;
}
- (NSArray<NSURL*>*)catalogBanks {
  auto root=cronox::catalog::root(cronox::cocoa::path(libraryOverride_?libraryOverride_.path:crxPreference(CFSTR("CronoX3ARMPresetRoot"))),
                                cronox::cocoa::path(crxPreference(CFSTR("CronoX3ARMSampleRoot"))),cronox::cocoa::path(current_.path));
  library_=crxURL(root);NSMutableArray<NSURL*>* banks=[NSMutableArray array];
  for(const auto& folder:cronox::catalog::banks(root)) [banks addObject:crxURL(folder)];
  if(!selectedBank_&&current_)selectedBank_=current_.URLByDeletingLastPathComponent;
  std::error_code bankError;if(selectedBank_&&!std::filesystem::is_directory(selectedBank_.path.fileSystemRepresentation,bankError))selectedBank_=nil;
  if(!selectedBank_)for(NSURL* folder in banks) {
    auto label=cronox::catalog::label(folder.path.fileSystemRepresentation);
    if([cronoxCompleteView::string(label.c_str(),label.size()) isEqual:bank_.stringValue]) {selectedBank_=folder;break;}
  }
  if(!selectedBank_&&banks.count)selectedBank_=banks.firstObject;
  if(selectedBank_&&![banks containsObject:selectedBank_]&&cronox::catalog::useful(selectedBank_.path.fileSystemRepresentation))[banks addObject:selectedBank_];
  return banks;
}
- (NSMenu*)bankMenu {
  NSMenu* menu=[[NSMenu alloc] initWithTitle:@"Banques"];menu.autoenablesItems=NO;
  for(NSURL* folder in [self catalogBanks]) {
    auto label=cronox::catalog::label(folder.path.fileSystemRepresentation);
    NSMenuItem* item=[[NSMenuItem alloc] initWithTitle:cronoxCompleteView::string(label.c_str(),label.size()) action:@selector(selectBank:) keyEquivalent:@""];
    item.target=self;item.representedObject=folder;item.state=[folder.path isEqual:selectedBank_.path]?NSControlStateValueOn:NSControlStateValueOff;[menu addItem:item];
  }
  if(!menu.numberOfItems){NSMenuItem* none=[[NSMenuItem alloc] initWithTitle:@"- - -" action:nil keyEquivalent:@""];none.enabled=NO;[menu addItem:none];}
  [menu addItem:NSMenuItem.separatorItem];
  NSMenuItem* choose=[[NSMenuItem alloc] initWithTitle:@"Choisir le dossier des banques…" action:@selector(choosePresetRoot:) keyEquivalent:@""];choose.target=self;[menu addItem:choose];return menu;
}
- (NSMenu*)presetMenu {
  (void)[self catalogBanks];NSMenu* menu=[[NSMenu alloc] initWithTitle:@"Presets"];menu.autoenablesItems=NO;
  if(selectedBank_)for(const auto& path:cronox::catalog::presets(selectedBank_.path.fileSystemRepresentation)) {
    auto label=cronox::catalog::label(path);NSMenuItem* item=[[NSMenuItem alloc] initWithTitle:cronoxCompleteView::string(label.c_str(),label.size()) action:@selector(selectPreset:) keyEquivalent:@""];
    item.target=self;item.representedObject=crxURL(path);item.state=[((NSURL*)item.representedObject).path isEqual:current_.path]?NSControlStateValueOn:NSControlStateValueOff;[menu addItem:item];
  }
  if(!menu.numberOfItems){NSMenuItem* none=[[NSMenuItem alloc] initWithTitle:@"- - -" action:nil keyEquivalent:@""];none.enabled=NO;[menu addItem:none];}
  return menu;
}
- (void)showBankMenu:(id)sender {[[self bankMenu] popUpMenuPositioningItem:nil atLocation:NSMakePoint(0,bank_.bounds.size.height) inView:bank_];}
- (void)showPresetMenu:(id)sender {[[self presetMenu] popUpMenuPositioningItem:nil atLocation:NSMakePoint(0,name_.bounds.size.height) inView:name_];}
- (void)selectPreset:(NSMenuItem*)item {
  if([item.representedObject isKindOfClass:NSURL.class]&&![self loadPresetURL:item.representedObject])[self failure:notice_.stringValue];
}
- (void)selectBank:(NSMenuItem*)item {
  NSURL* url=item.representedObject;if(![url isKindOfClass:NSURL.class])return;
  auto files=cronox::catalog::presets(url.path.fileSystemRepresentation);
  // Original Synth::setInsBnk 0x1e89c resets the program index and loads its first file.
  if(!files.empty()){if(![self loadPresetURL:crxURL(files.front())])[self failure:notice_.stringValue];return;}
  auto label=cronox::catalog::label(url.path.fileSystemRepresentation);
  OSStatus status=AudioUnitSetProperty(unit_,sophistry::presetBankNameProperty,kAudioUnitScope_Global,0,label.c_str(),UInt32(label.size()+1));
  const char empty=0;if(!status)status=AudioUnitSetProperty(unit_,sophistry::presetSourceProperty,kAudioUnitScope_Global,0,&empty,1);
  if(status){[self failure:crxError(unit_,status)];return;}
  selectedBank_=url;current_=nil;emptyBank_=YES;[self refresh];
}
- (void)choosePresetRoot:(id)sender {
  NSOpenPanel* panel=[NSOpenPanel openPanel];panel.title=@"Dossier contenant les banques de presets";
  panel.canChooseDirectories=YES;panel.canChooseFiles=NO;panel.allowsMultipleSelection=NO;panel.directoryURL=library_;
  if([panel runModal]!=NSModalResponseOK)return;
  [self setPresetLibraryURL:panel.URL persist:YES];[self showBankMenu:bank_];
}
- (void)setPresetLibraryURL:(NSURL*)root persist:(BOOL)persist {
  library_=root;libraryOverride_=root;
  if(!persist)return;
  CFDataRef bookmark=sophistryMac::createBankBookmark((__bridge CFURLRef)root);
  if(bookmark){libraryAccess_=sophistryMac::openBankBookmark(bookmark,root.path.fileSystemRepresentation);
    CFPreferencesSetValue(CFSTR("CronoX3ARMPresetBookmark"),bookmark,CFSTR("com.linplug.CronoX3.ARMTest"),kCFPreferencesCurrentUser,kCFPreferencesAnyHost);CFRelease(bookmark);}
  CFPreferencesSetValue(CFSTR("CronoX3ARMPresetRoot"),(__bridge CFStringRef)root.path,CFSTR("com.linplug.CronoX3.ARMTest"),kCFPreferencesCurrentUser,kCFPreferencesAnyHost);
  CFPreferencesSynchronize(CFSTR("com.linplug.CronoX3.ARMTest"),kCFPreferencesCurrentUser,kCFPreferencesAnyHost);
}
- (NSDictionary*)cronoxKeyboardReport {return [bottom_ keyboardReport];}
- (NSDictionary*)presetBrowserReport {
  NSMutableArray* banks=[NSMutableArray array],*presets=[NSMutableArray array];
  for(NSMenuItem* item in [self bankMenu].itemArray)if([item.representedObject isKindOfClass:NSURL.class])[banks addObject:item.title];
  for(NSMenuItem* item in [self presetMenu].itemArray)if([item.representedObject isKindOfClass:NSURL.class])[presets addObject:item.title];
  CGFloat red=0,green=0,blue=0,alpha=0;[bank_.textColor getRed:&red green:&green blue:&blue alpha:&alpha];
  return @{@"banks":banks,@"presets":presets,@"font_points":@(bank_.font.pointSize),@"rgb":@[@(std::lround(red*255)),@(std::lround(green*255)),@(std::lround(blue*255))],@"bank_top":@(bank_.frame.origin.y),@"preset_top":@(name_.frame.origin.y),@"row_height":@(bank_.frame.size.height),@"original_baseline":@YES,@"bank_click_selector":NSStringFromSelector(bank_.action),@"preset_click_selector":NSStringFromSelector(name_.action)};
}
- (void)load:(id)sender {
  NSOpenPanel* panel=[NSOpenPanel openPanel];panel.title=@"Charger un son CronoX 3";
  panel.allowedFileTypes=@[@"fxp",@"aupreset"];panel.allowsMultipleSelection=NO;
  if(current_)panel.directoryURL=current_.URLByDeletingLastPathComponent;
  if([panel runModal]==NSModalResponseOK && ![self loadPresetURL:panel.URL])[self failure:notice_.stringValue];
}
- (void)navigate:(NSInteger)direction {
  if(!current_){[self load:nil];return;}
  auto files=cronox::catalog::presets(std::filesystem::path(current_.URLByDeletingLastPathComponent.path.fileSystemRepresentation));
  NSMutableArray<NSURL*>* ordered=[NSMutableArray array];for(const auto& p:files)[ordered addObject:crxURL(p)];
  NSURL* next=sophistryPresetBrowser::adjacent(ordered,current_,direction);
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
  NSMutableArray* buttons=[NSMutableArray array];NSString* footer=@"";CGFloat footerSize=0,footerY=0;
  for(NSView* v in self.subviews) {
    if([v isKindOfClass:NSButton.class] && v.frame.origin.y>477)
      [buttons addObject:@{@"title":[(NSButton*)v title],@"center_y":@(NSMidY(v.frame))}];
    if([v isKindOfClass:NSTextField.class] && [[(NSTextField*)v stringValue] hasPrefix:@"CronoX 3 ARM64 port"]) {
      footer=[(NSTextField*)v stringValue];footerSize=[(NSTextField*)v font].pointSize;footerY=v.frame.origin.y;
    }
  }
  return @{@"comparison_view":@YES,@"original_panels_available":@YES,@"original_panel_recovery_complete":@NO,@"subtype":@"CrT3",@"width":@(self.frame.size.width),@"height":@(self.frame.size.height),@"preset_name":name_.stringValue,@"preset_browser":[self presetBrowserReport],@"preset_bank_name":bank_.stringValue,@"bank_and_preset_centered":@(bank_.alignment==NSTextAlignmentCenter&&name_.alignment==NSTextAlignmentCenter&&bank_.frame.origin.y<name_.frame.origin.y),@"original_font_available":@([NSFont fontWithName:@"Helvetica" size:11]!=nil),@"font_family":@"Helvetica",@"footer":footer,@"footer_font_size":@(footerSize),@"footer_top":@(footerY),@"utility_buttons":buttons,@"main":[panel_ report],@"shell":[root_ report],@"bottom":[bottom_ report]};
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
