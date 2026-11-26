// Validate the actual AU, Cocoa factory, state recall and audio. No licence
// values or raw AU banks are written to the report.
#include "../src/au/CronoXIdentity.h"
#include "../src/au/SophistryProperties.h"
#include "../src/au/CronoXPresetNames.h"
#include "../src/au/CronoXPresetCatalog.h"
#include "../src/au/CronoXCocoaPaths.h"
#include "../src/engine/GeneratorControls.h"
#import <AppKit/AppKit.h>
#import <AudioToolbox/AudioToolbox.h>
#import <AudioToolbox/AUCocoaUIView.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <time.h>
@interface NSView (CronoXComparisonProbe)
- (BOOL)loadPresetURL:(NSURL*)url;
- (NSDictionary*)cronoxComparisonReport;
- (NSArray*)cronoxEditorPagesReport;
- (void)setPresetLibraryURL:(NSURL*)root persist:(BOOL)persist;
- (NSMenu*)bankMenu;
- (NSMenu*)presetMenu;
- (NSDictionary*)presetBrowserReport;
- (NSDictionary*)cronoxKeyboardReport;
- (void)completeChanged:(id)sender;
@end
namespace {
void check(OSStatus value,const char* action){if(value)throw std::runtime_error(std::string(action)+": "+std::to_string(value));}
CFDictionaryRef originalPreferences(){return CFPreferencesCopyMultiple(nullptr,CFSTR("com.linplug.CronoX3"),kCFPreferencesCurrentUser,kCFPreferencesAnyHost);}
bool same(CFTypeRef a,CFTypeRef b){return (!a&&!b)||(a&&b&&CFEqual(a,b));}
unsigned components(UInt32 subtype){AudioComponentDescription d{cronox::identity::type,subtype,cronox::identity::manufacturer,0,0};unsigned count=0;AudioComponent next=nullptr;while((next=AudioComponentFindNext(next,&d)))++count;return count;}
CFPropertyListRef save(AudioUnit unit){CFPropertyListRef state=nullptr;UInt32 bytes=sizeof(state);check(AudioUnitGetProperty(unit,kAudioUnitProperty_ClassInfo,kAudioUnitScope_Global,0,&state,&bytes),"Save state");return state;}
void restore(AudioUnit unit,CFPropertyListRef state){check(AudioUnitSetProperty(unit,kAudioUnitProperty_ClassInfo,kAudioUnitScope_Global,0,&state,sizeof(state)),"Restore state");}
void setup(AudioUnit unit,unsigned channels,double rate=44100){AudioStreamBasicDescription f{rate,kAudioFormatLinearPCM,kAudioFormatFlagIsFloat|kAudioFormatFlagIsPacked|kAudioFormatFlagIsNonInterleaved,4,1,4,channels,32,0};UInt32 frames=256;check(AudioUnitSetProperty(unit,kAudioUnitProperty_StreamFormat,kAudioUnitScope_Output,0,&f,sizeof(f)),"Stream format");check(AudioUnitSetProperty(unit,kAudioUnitProperty_MaximumFramesPerSlice,kAudioUnitScope_Global,0,&frames,sizeof(frames)),"Maximum frames");check(AudioUnitInitialize(unit),"Initialize");}
NSDictionary* status(AudioUnit unit){std::vector<char> text(sophistry::runtimeStatusBytes);UInt32 bytes=UInt32(text.size());check(AudioUnitGetProperty(unit,sophistry::runtimeStatusProperty,kAudioUnitScope_Global,0,text.data(),&bytes),"Runtime status");NSData* data=[NSData dataWithBytes:text.data() length:strnlen(text.data(),text.size())];id value=[NSJSONSerialization JSONObjectWithData:data options:0 error:nil];return [value isKindOfClass:NSDictionary.class]?value:@{};}
struct Audio {
  double peak=0,squared=0,cpu=0;unsigned frames=0,channels=0;bool keyboardObserved=false;
  std::vector<std::vector<float>> data;
};
double cpuTime(){timespec t{};if(clock_gettime(CLOCK_THREAD_CPUTIME_ID,&t))throw std::runtime_error("CPU clock unavailable");return double(t.tv_sec)+t.tv_nsec*1e-9;}
Audio render(AudioUnit unit,unsigned channels,NSView* view=nil){
  Audio out;out.channels=channels;out.frames=8192;out.data.resize(channels,std::vector<float>(out.frames));
  alignas(AudioBufferList) std::array<unsigned char,sizeof(AudioBufferList)+5*sizeof(AudioBuffer)> storage{};
  auto* list=reinterpret_cast<AudioBufferList*>(storage.data());list->mNumberBuffers=channels;
  check(MusicDeviceMIDIEvent(unit,0x90,60,100,0),"Note on");double before=cpuTime(),displayTime=0;
  for(unsigned at=0;at<out.frames;at+=256){
    if(at==4096)check(MusicDeviceMIDIEvent(unit,0x80,60,0,0),"Note off");
    for(unsigned c=0;c<channels;++c)list->mBuffers[c]={1,256*4,out.data[c].data()+at};
    AudioTimeStamp timestamp{};timestamp.mSampleTime=at;timestamp.mFlags=kAudioTimeStampSampleTimeValid;
    AudioUnitRenderActionFlags flags=0;check(AudioUnitRender(unit,&flags,&timestamp,0,256,list),"Render");
    if(view&&at<4096){double start=cpuTime();out.keyboardObserved=out.keyboardObserved||[[view cronoxKeyboardReport][@"active_notes"] count]>0;displayTime+=cpuTime()-start;}
    for(unsigned c=0;c<channels;++c)for(unsigned i=at;i<at+256;++i){double v=out.data[c][i];if(!std::isfinite(v))throw std::runtime_error("Non-finite audio");out.peak=std::max(out.peak,std::abs(v));out.squared+=v*v;}
  }
  out.cpu=cpuTime()-before-displayTime;
  if(out.peak<=1e-5)throw std::runtime_error("No audible signal from the public sample preset");return out;
}
void word(std::ofstream& f,unsigned v){char b[]={char(v),char(v>>8),char(v>>16),char(v>>24)};f.write(b,4);}
void half(std::ofstream& f,unsigned v){char b[]={char(v),char(v>>8)};f.write(b,2);}
void wave(NSString* path,const Audio& a){std::ofstream f(path.fileSystemRepresentation,std::ios::binary);if(!f)throw std::runtime_error("Cannot create WAV");unsigned bytes=a.frames*a.channels*4;f.write("RIFF",4);word(f,36+bytes);f.write("WAVEfmt ",8);word(f,16);half(f,3);half(f,a.channels);word(f,44100);word(f,44100*a.channels*4);half(f,a.channels*4);half(f,32);f.write("data",4);word(f,bytes);for(unsigned i=0;i<a.frames;++i)for(unsigned c=0;c<a.channels;++c)f.write(reinterpret_cast<const char*>(&a.data[c][i]),4);}
}
int main(int argc,char** argv){@autoreleasepool {
  [NSApplication sharedApplication];[NSApp setActivationPolicy:NSApplicationActivationPolicyProhibited];
  AudioUnit unit=nullptr,fresh=nullptr;CFBundleRef bundle=nullptr;CFDictionaryRef before=nullptr;
  NSString* output=nil;NSString* stage=@"arguments";NSView* view=nil;NSURL* menuFixture=nil;
  NSMutableDictionary* report=[NSMutableDictionary dictionaryWithDictionary:@{@"checkpoint":@"CRX013",@"subtype":@"CrT3",@"passed":@NO,@"sound_fidelity_verified":@NO}];
  @try {
   try {
    bool registered=false;NSString* bundlePath=nil;NSString* preset=nil;unsigned channels=2;
    for(int i=1;i<argc;++i){std::string arg=argv[i];auto value=[&](){if(++i>=argc)throw std::runtime_error("Missing argument value");return [NSString stringWithUTF8String:argv[i]];};if(arg=="--registered")registered=true;else if(arg=="--bundle")bundlePath=value();else if(arg=="--preset")preset=value();else if(arg=="--output")output=value();else if(arg=="--channels")channels=unsigned([value() intValue]);else throw std::runtime_error("Unknown probe option");}
    if(!output||!preset||(registered==bool(bundlePath))||(channels!=2&&channels!=6))throw std::runtime_error("Expected (--bundle path | --registered) --preset path --output path [--channels 2|6]");
    stage=@"optional browser locations";
    if(!cronox::cocoa::path(nil).empty()||!cronox::cocoa::path(@"").empty()||cronox::cocoa::path(@"/tmp/CronoX 3").string()!="/tmp/CronoX 3")
      throw std::runtime_error("Optional Cocoa path conversion differs");
    if(cronox::catalog::root(cronox::cocoa::path(@""),cronox::cocoa::path(nil),cronox::cocoa::path(preset)).empty())
      throw std::runtime_error("Preset folder fallback unavailable without saved locations");
    report[@"optional_empty_locations_handled"]=@YES;
    before=originalPreferences();unsigned originals=components(cronox::identity::originalSubtype);report[@"original_registered_count_before"]=@(originals);
    AudioComponentDescription desc{cronox::identity::type,cronox::identity::subtype,cronox::identity::manufacturer,0,0};AudioComponent component=nullptr;
    if(registered){stage=@"registered lookup";component=AudioComponentFindNext(nullptr,&desc);if(!component)throw std::runtime_error("CrT3 component not registered");if(AudioComponentFindNext(component,&desc))throw std::runtime_error("Multiple CrT3 components are registered");}
    else {
      stage=@"bundle factory";bundle=CFBundleCreate(nullptr,(__bridge CFURLRef)[NSURL fileURLWithPath:bundlePath isDirectory:YES]);
      if(!bundle||!CFBundleLoadExecutable(bundle))throw std::runtime_error("Cannot load candidate bundle");
      auto factory=reinterpret_cast<AudioComponentFactoryFunction>(CFBundleGetFunctionPointerForName(bundle,CFSTR("CronoX3ARMTestAUFactory")));
      if(!factory)throw std::runtime_error("Comparison AU factory is missing");
      component=AudioComponentRegister(&desc,CFSTR("CronoX 3 ARM comparison candidate"),0x30606,factory);if(!component)throw std::runtime_error("Local factory registration failed");
    }
    stage=@"create instance";check(AudioComponentInstanceNew(component,&unit),"Create instance");
    CFStringRef version=nullptr;UInt32 versionBytes=sizeof(version);check(AudioUnitGetProperty(unit,0x53705672,kAudioUnitScope_Global,0,&version,&versionBytes),"Build version");
    if(!version||!CFEqual(version,CFSTR("CronoX3ARM CRX-013")))throw std::runtime_error("An unexpected comparison build was loaded");CFRelease(version);
    stage=@"AU parameters";UInt32 bytes=0;Boolean writable=false;check(AudioUnitGetPropertyInfo(unit,kAudioUnitProperty_ParameterList,kAudioUnitScope_Global,0,&bytes,&writable),"Parameter count");
    if(bytes!=522*sizeof(UInt32))throw std::runtime_error("Original AU parameter count differs");std::vector<UInt32> ids(522);check(AudioUnitGetProperty(unit,kAudioUnitProperty_ParameterList,kAudioUnitScope_Global,0,ids.data(),&bytes),"Parameter IDs");
    for(UInt32 id:ids){AudioUnitParameterInfo info{};UInt32 size=sizeof(info);check(AudioUnitGetProperty(unit,kAudioUnitProperty_ParameterInfo,kAudioUnitScope_Global,id,&info,&size),"Parameter info");float value=0;check(AudioUnitGetParameter(unit,id,kAudioUnitScope_Global,0,&value),"Parameter value");if(!std::isfinite(value)||info.minValue>info.maxValue)throw std::runtime_error("Invalid original AU metadata");if(info.flags&kAudioUnitParameterFlag_CFNameRelease){if(info.cfNameString)CFRelease(info.cfNameString);}}
    report[@"parameters"]=@522;
    stage=@"Cocoa view";AudioUnitCocoaViewInfo cocoa{};UInt32 size=sizeof(cocoa);check(AudioUnitGetProperty(unit,kAudioUnitProperty_CocoaUI,kAudioUnitScope_Global,0,&cocoa,&size),"Cocoa view property");
    NSBundle* ui=[NSBundle bundleWithURL:(__bridge NSURL*)cocoa.mCocoaAUViewBundleLocation];if(!ui||![ui load])throw std::runtime_error("Cocoa bundle cannot load");
    Class type=NSClassFromString((__bridge NSString*)cocoa.mCocoaAUViewClass[0]);id<AUCocoaUIBase> factory=[[type alloc] init];
    view=[factory uiViewForAudioUnit:unit withSize:NSMakeSize(600,220)];CFRelease(cocoa.mCocoaAUViewBundleLocation);CFRelease(cocoa.mCocoaAUViewClass[0]);
    if(!view||![view respondsToSelector:@selector(loadPresetURL:)]||view.frame.size.height>600)throw std::runtime_error("Original comparison view unavailable");
    if(![view loadPresetURL:[NSURL fileURLWithPath:preset]])throw std::runtime_error("The comparison view could not load the public FXP");
    stage=@"bank and preset menus";
    menuFixture=[[NSURL fileURLWithPath:NSTemporaryDirectory() isDirectory:YES] URLByAppendingPathComponent:[@"CronoX-menu-" stringByAppendingString:NSUUID.UUID.UUIDString] isDirectory:YES];
    NSFileManager* fm=NSFileManager.defaultManager;
    for(NSString* bank in @[@"Bank A",@"Bank B"]){NSURL* folder=[menuFixture URLByAppendingPathComponent:bank isDirectory:YES];
      if(![fm createDirectoryAtURL:folder withIntermediateDirectories:YES attributes:nil error:nil])throw std::runtime_error("Cannot prepare menu fixture");
      NSArray* names=[bank isEqual:@"Bank A"]?@[@"01 first.FXP",@"02 second.FXP"]:@[@"01 first.FXP"];
      for(NSString* fileName in names){NSMutableData* data=[[NSData dataWithContentsOfFile:preset] mutableCopy];
        NSString* title=[bank stringByAppendingString:[fileName hasPrefix:@"01"]?@" first":@" second"];
        if(data.length<60)throw std::runtime_error("Missing public fixture header");
        auto* bytes=static_cast<unsigned char*>(data.mutableBytes);std::memset(bytes+28,0,28);std::memcpy(bytes+28,title.UTF8String,MIN(27,strlen(title.UTF8String)));
        if(![data writeToURL:[folder URLByAppendingPathComponent:fileName] atomically:YES])throw std::runtime_error("Cannot write menu fixture");
      }
    }
    [view setPresetLibraryURL:menuFixture persist:NO];
    NSMenuItem* firstBank=[[view bankMenu] itemWithTitle:@"Bank A"];
    if(!firstBank||![NSApp sendAction:firstBank.action to:firstBank.target from:firstBank]||![status(unit)[@"preset_name"] isEqual:@"Bank A first"])
      throw std::runtime_error("Original bank selection must load its first preset");
    NSMenuItem* secondPreset=[[view presetMenu] itemWithTitle:@"02 second"];
    if(!secondPreset||![NSApp sendAction:secondPreset.action to:secondPreset.target from:secondPreset]||![status(unit)[@"preset_name"] isEqual:@"Bank A second"])
      throw std::runtime_error("Preset menu selection failed");
    NSMenuItem* secondBank=[[view bankMenu] itemWithTitle:@"Bank B"];
    if(!secondBank||![NSApp sendAction:secondBank.action to:secondBank.target from:secondBank]||![status(unit)[@"preset_name"] isEqual:@"Bank B first"])
      throw std::runtime_error("Changing bank did not select its first preset");
    report[@"bank_and_preset_menu_actions_passed"]=@YES;
    [view setPresetLibraryURL:nil persist:NO];if(![view loadPresetURL:[NSURL fileURLWithPath:preset]])throw std::runtime_error("Cannot restore public preset after menu checks");
    sophistry::GeneratorControlEdit keyboardEdit{1,604,1};
    check(AudioUnitSetProperty(unit,sophistry::editorEditProperty,kAudioUnitScope_Global,0,&keyboardEdit,sizeof(keyboardEdit)),"Show original keyboard");[view completeChanged:nil];
    report[@"editor"]=[view cronoxComparisonReport];
    NSDictionary* editor=report[@"editor"];
    NSDictionary* browser=editor[@"preset_browser"];
    if([browser[@"font_points"] intValue]!=12||![browser[@"rgb"] isEqual:@[@210,@210,@210]]||[browser[@"bank_top"] intValue]!=228||[browser[@"preset_top"] intValue]!=244||[browser[@"row_height"] intValue]!=15)
      throw std::runtime_error("Bank/preset style differs from original createMenuFileList");
    if(![editor[@"original_font_available"] boolValue] || ![editor[@"footer"] isEqual:@"CronoX 3 ARM64 port OA 2026 . CRX013"])
      throw std::runtime_error("Original font or CRX013 footer differs");
    if(![editor[@"bank_and_preset_centered"] boolValue] || [editor[@"footer_font_size"] doubleValue]!=9 || [editor[@"footer_top"] doubleValue]!=487)
      throw std::runtime_error("Bank/preset alignment or footer geometry differs");
    NSArray* buttons=editor[@"utility_buttons"];
    if(buttons.count!=3)throw std::runtime_error("Utility buttons unavailable");
    for(NSDictionary* button in buttons)if(std::abs([button[@"center_y"] doubleValue]-499)>0.01)
      throw std::runtime_error("Utility buttons are not vertically centered");
    stage=@"original editor pages";
    NSArray* pages=[view cronoxEditorPagesReport];
    if(pages.count!=7)throw std::runtime_error("Original editor pages unavailable");
    for(NSDictionary* page in pages) {
      if([page[@"status"] intValue] || ![page[@"controls"] count] || ![page[@"sprites_loaded"] boolValue] || ![page[@"image_dimensions_match_original_pixels"] boolValue])
        throw std::runtime_error("Original editor page or image check failed");
    }
    report[@"original_editor_pages"]=pages;
    NSDictionary* modulation=pages[5];
    if([modulation[@"modulation_destinations"] count]!=10||[modulation[@"arpeggiators"] count]!=1)throw std::runtime_error("Original Matrix or arpeggiator views missing");
    for(NSDictionary* menu in modulation[@"modulation_destinations"])
      if([menu[@"categories"] intValue]!=16||[menu[@"destinations"] intValue]!=58||![menu[@"internal_markers_hidden"] boolValue])throw std::runtime_error("Matrix categories or labels differ from original");
    NSDictionary* arp=[modulation[@"arpeggiators"] firstObject];
    if([arp[@"columns"] intValue]!=4||[arp[@"displayed_value_columns"] intValue]!=4||![arp[@"indicator_loaded"] boolValue]||[arp[@"indicator_bitmap"] intValue]!=306)throw std::runtime_error("Original arp columns or indicator missing");
    stage=@"initialize";setup(unit,channels);
    stage=@"render";Audio audio=render(unit,channels,view);wave([output stringByAppendingPathExtension:@"wav"],audio);
    if(!audio.keyboardObserved)throw std::runtime_error("Played notes were not reflected in the original keyboard view");report[@"played_notes_reach_keyboard"]=@YES;
    report[@"frames"]=@(audio.frames);report[@"channels"]=@(channels);report[@"sample_rate"]=@44100;report[@"peak"]=@(audio.peak);report[@"rms"]=@(std::sqrt(audio.squared/(audio.frames*channels)));report[@"render_cpu_seconds"]=@(audio.cpu);report[@"render_cpu_ratio"]=@(audio.cpu/(audio.frames/44100.0));
    NSDictionary* runtime=status(unit);NSString* name=runtime[@"preset_name"];report[@"preset_name"]=name?:@"";report[@"original_registration_accepted"]=runtime[@"engine"][@"registration_accepted"]?:@NO;
    NSString* bank=runtime[@"preset_bank_name"];report[@"preset_bank_name"]=bank?:@"";
    if(![bank isEqual:preset.stringByDeletingLastPathComponent.lastPathComponent] || ![editor[@"preset_bank_name"] isEqual:bank])
      throw std::runtime_error("Selected preset folder is missing from the bank line");
    NSData* file=[NSData dataWithContentsOfFile:preset];const auto header=cronox::fxpProgramName(file.bytes,file.length);
    NSString* expected=[[NSString alloc] initWithBytes:header.data() length:header.size() encoding:NSUTF8StringEncoding];
    if(!expected)expected=[[NSString alloc] initWithBytes:header.data() length:header.size() encoding:NSMacOSRomanStringEncoding];
    if(!cronox::usablePresetName(name.UTF8String?:"") || (expected.length && ![name isEqual:expected]) || ![editor[@"preset_name"] isEqual:name])
      throw std::runtime_error("Loaded preset name differs from the original FXP header");
    if([runtime[@"engine"][@"pre_master_gain_db"] doubleValue]!=6)
      throw std::runtime_error("Expected +6 dB before Master");
    stage=@"fresh instance state recall";CFPropertyListRef state=save(unit);auto dict=static_cast<CFDictionaryRef>(state);SInt32 subtype=0;CFNumberRef number=static_cast<CFNumberRef>(CFDictionaryGetValue(dict,CFSTR("subtype")));if(!number||!CFNumberGetValue(number,kCFNumberSInt32Type,&subtype)||UInt32(subtype)!=cronox::identity::subtype)throw std::runtime_error("Saved comparison AU identity differs");
    check(AudioComponentInstanceNew(component,&fresh),"Create recall instance");restore(fresh,state);CFRelease(state);
    NSDictionary* recalled=status(fresh);if(![recalled[@"preset_name"] isEqual:name])throw std::runtime_error("Restored preset name differs");
    if(![recalled[@"preset_bank_name"] isEqual:bank])throw std::runtime_error("Restored preset bank name differs");
    std::array<char,sophistry::presetSourceBytes> source{},recalledSource{};UInt32 sourceSize=UInt32(source.size());
    check(AudioUnitGetProperty(unit,sophistry::presetSourceProperty,kAudioUnitScope_Global,0,source.data(),&sourceSize),"Source location");sourceSize=UInt32(recalledSource.size());
    check(AudioUnitGetProperty(fresh,sophistry::presetSourceProperty,kAudioUnitScope_Global,0,recalledSource.data(),&sourceSize),"Recalled source location");
    if(!source[0]||source!=recalledSource)throw std::runtime_error("Preset source location was not restored for the menus");report[@"browser_source_location_recalled"]=@YES;
    setup(fresh,channels);(void)render(fresh,channels);report[@"fresh_instance_state_recall"]=@YES;
    // Exercise original framework reinitialization at a second common rate.
    stage=@"48 kHz reinitialization";check(AudioUnitUninitialize(fresh),"Uninitialize");setup(fresh,channels,48000);check(MusicDeviceMIDIEvent(fresh,0xb0,123,0,0),"All notes off");
    stage=@"dispose";view=nil;check(AudioUnitUninitialize(fresh),"Fresh cleanup");check(AudioComponentInstanceDispose(fresh),"Fresh disposal");fresh=nullptr;check(AudioUnitUninitialize(unit),"Cleanup");check(AudioComponentInstanceDispose(unit),"Disposal");unit=nullptr;
    CFDictionaryRef after=originalPreferences();bool preserved=same(before,after);if(after)CFRelease(after);if(!preserved)throw std::runtime_error("Original preferences changed during the test");
    if(components(cronox::identity::originalSubtype)!=originals)throw std::runtime_error("Original AU registration changed");
    report[@"original_preferences_preserved"]=@YES;report[@"original_registration_preserved"]=@YES;report[@"passed"]=@YES;stage=@"completed";
   } catch(const std::exception& error){report[@"passed"]=@NO;report[@"error"]=[NSString stringWithUTF8String:error.what()];}
  } @catch(NSException* error) {
    report[@"passed"]=@NO;report[@"exception_name"]=error.name?:@"NSException";report[@"error"]=error.reason?:@"Objective-C exception";
  }
  view=nil;if(fresh){AudioUnitUninitialize(fresh);AudioComponentInstanceDispose(fresh);}if(unit){AudioUnitUninitialize(unit);AudioComponentInstanceDispose(unit);}if(before)CFRelease(before);if(bundle)CFRelease(bundle);if(menuFixture)[NSFileManager.defaultManager removeItemAtURL:menuFixture error:nil];
  report[@"stage"]=stage;NSData* json=[NSJSONSerialization dataWithJSONObject:report options:NSJSONWritingPrettyPrinted error:nil];
  if(output)[json writeToFile:[output stringByAppendingPathExtension:@"json"] atomically:YES];if(json){fwrite(json.bytes,1,json.length,stdout);fputc('\n',stdout);}return [report[@"passed"] boolValue]?0:1;
}}
