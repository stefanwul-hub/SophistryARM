// RV002: compare installed CrX3/x86_64 and CrT3/arm64, using the same AU bank.
// No DSP patch, licence hook, audio device, component installation or raw-state report.
#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#include "CronoXFxpHeader.h"
#include <CommonCrypto/CommonDigest.h>
#include <mach-o/dyld.h>
#include <sys/sysctl.h>
#include <sys/stat.h>
#include <algorithm>
#include <array>
#include <atomic>
#include <cmath>
#include <cstring>
#include <memory>
#include <stdexcept>
#include <string>
#include <time.h>

namespace {
constexpr UInt32 type=0x61756d75, originalID=0x43725833, armID=0x43725433, manufacturer=0x4c696e50;
constexpr UInt32 statusID=0x53705374, importID=0x53705072, statusBytes=128*1024;
constexpr double rate=44100;
constexpr unsigned frames=256, totalBlocks=5513, onBlock=43, offBlock=215, bucketBlocks=17;
void check(OSStatus s,const char* action){if(s)throw std::runtime_error(std::string(action)+": "+std::to_string(s));}
double seconds(clockid_t clock){timespec t{};if(clock_gettime(clock,&t))throw std::runtime_error("Clock unavailable");return t.tv_sec+t.tv_nsec*1e-9;}
NSString* hash(NSData* data){
  if(!data||data.length>UINT32_MAX)return @"";
  unsigned char digest[CC_SHA256_DIGEST_LENGTH];CC_SHA256(data.bytes,CC_LONG(data.length),digest);
  NSMutableString* value=[NSMutableString string];for(unsigned char b:digest)[value appendFormat:@"%02x",b];return value;
}
NSDictionary* status(AudioUnit u){
  std::array<char,statusBytes> text{};UInt32 bytes=text.size();
  check(AudioUnitGetProperty(u,statusID,kAudioUnitScope_Global,0,text.data(),&bytes),"Native status");
  id value=[NSJSONSerialization JSONObjectWithData:[NSData dataWithBytes:text.data() length:strnlen(text.data(),text.size())] options:0 error:nil];
  if(![value isKindOfClass:NSDictionary.class])throw std::runtime_error("Native status is not JSON");return value;
}
void writeJSON(NSDictionary* dict,NSString* path){
  NSError* error=nil;NSData* json=[NSJSONSerialization dataWithJSONObject:dict options:NSJSONWritingPrettyPrinted error:&error];
  if(!json||![json writeToFile:path options:NSDataWritingAtomic error:&error])throw std::runtime_error("Cannot write numeric report");
}
void identity(NSMutableDictionary* state,UInt32 subtype){
  state[@"type"]=@(type);state[@"subtype"]=@(subtype);state[@"manufacturer"]=@(manufacturer);state[@"version"]=@0;
}
NSMutableDictionary* cleanState(NSDictionary* source){
  NSData* bank=source[@"vstdata"];
  if(![bank isKindOfClass:NSData.class]||!bank.length||bank.length>1048576)throw std::runtime_error("Missing or oversized original AU vstdata bank");
  if([source[@"type"] unsignedIntValue]!=type||[source[@"manufacturer"] unsignedIntValue]!=manufacturer||
     ([source[@"subtype"] unsignedIntValue]!=originalID&&[source[@"subtype"] unsignedIntValue]!=armID)||[source[@"version"] intValue]!=0)
    throw std::runtime_error("The AU state is not CronoX 3 / version 0");
  NSMutableDictionary* state=[NSMutableDictionary dictionaryWithDictionary:@{@"vstdata":bank}];identity(state,originalID);
  if([source[@"name"] isKindOfClass:NSString.class])state[@"name"]=source[@"name"];
  return state;
}
NSDictionary* readState(NSString* path){
  NSData* data=[NSData dataWithContentsOfFile:path];
  if(!data||data.length>2*1024*1024)throw std::runtime_error("Cannot read local AU state");
  id plist=[NSPropertyListSerialization propertyListWithData:data options:NSPropertyListImmutable format:nil error:nil];
  if(![plist isKindOfClass:NSDictionary.class])throw std::runtime_error("AU state is not a dictionary");return cleanState(plist);
}
struct Instance{
  AudioUnit value=nullptr;
  void close(){if(value){AudioUnitUninitialize(value);AudioComponentInstanceDispose(value);value=nullptr;}}
  ~Instance(){close();}
};
void open(Instance& unit,UInt32 subtype){
  AudioComponentDescription description{type,subtype,manufacturer,0,0};
  AudioComponent component=AudioComponentFindNext(nullptr,&description);
  if(!component||AudioComponentFindNext(component,&description))throw std::runtime_error("Expected one installed AU for the requested identity");
  struct Pending{std::atomic<bool> ready{false};OSStatus error=0;AudioUnit unit=nullptr;};
  auto pending=std::make_shared<Pending>();
  AudioComponentInstantiate(component,kAudioComponentInstantiation_LoadInProcess,^(AudioComponentInstance value,OSStatus error){
    pending->unit=value;pending->error=error;pending->ready.store(true,std::memory_order_release);
  });
  const double until=seconds(CLOCK_MONOTONIC)+60;
  while(!pending->ready.load(std::memory_order_acquire)){
    if(seconds(CLOCK_MONOTONIC)>until)throw std::runtime_error("AU creation timed out");
    CFRunLoopRunInMode(kCFRunLoopDefaultMode,.01,true);
  }
  unit.value=pending->unit;check(pending->error,"Create in-process AU");if(!unit.value)throw std::runtime_error("Missing AU instance");
}
void localImage(UInt32 subtype,NSMutableDictionary* report){
  // Inspect images already loaded by the AU API. Do not load an extra bundle:
  // that could make an out-of-process instance look local by mistake.
  NSString* expected=subtype==armID?@"com.linplug.au.CronoX3.ARMTest":@"com.linplug.au.CronoX3";
  NSBundle* found=nil;
  for(uint32_t i=0;i<_dyld_image_count();++i){
    const char* image=_dyld_get_image_name(i);if(!image)continue;
    NSString* path=[NSString stringWithUTF8String:image];
    NSString* root=path.stringByDeletingLastPathComponent.stringByDeletingLastPathComponent.stringByDeletingLastPathComponent;
    if(![root.pathExtension isEqualToString:@"component"])continue;
    NSBundle* candidate=[NSBundle bundleWithPath:root];
    if([candidate.bundleIdentifier isEqualToString:expected]&&[candidate.executablePath.stringByStandardizingPath isEqualToString:path.stringByStandardizingPath]){found=candidate;break;}
  }
  if(!found)throw std::runtime_error("The requested AU executable is not loaded in this host; caller CPU would be invalid");
  report[@"in_process_request"]=@YES;report[@"expected_bundle_executable_loaded_in_host"]=@YES;
  report[@"bundle_version"]=found.infoDictionary[@"CFBundleVersion"]?:@"";
  NSData* file=[NSData dataWithContentsOfFile:found.executablePath options:NSDataReadingMappedIfSafe error:nil];
  report[@"loaded_executable_sha256"]=hash(file);
}
struct Timeline{double sample=0;};
OSStatus beat(void* opaque,Float64* value,Float64* tempo){auto* t=static_cast<Timeline*>(opaque);if(value)*value=t->sample/rate*2;if(tempo)*tempo=120;return noErr;}
OSStatus musical(void* opaque,UInt32* delta,Float32* numerator,UInt32* denominator,Float64* downbeat){
  auto* t=static_cast<Timeline*>(opaque);double now=t->sample/rate*2;if(delta)*delta=UInt32(std::ceil((std::ceil(now)-now)*rate/2));if(numerator)*numerator=4;if(denominator)*denominator=4;if(downbeat)*downbeat=std::floor(now/4)*4;return noErr;
}
OSStatus transport(void* opaque,Boolean* playing,Boolean* changed,Float64* sample,Boolean* cycling,Float64* start,Float64* end){
  auto* t=static_cast<Timeline*>(opaque);if(playing)*playing=true;if(changed)*changed=t->sample==0;if(sample)*sample=t->sample;if(cycling)*cycling=false;if(start)*start=0;if(end)*end=0;return noErr;
}
void setup(AudioUnit u,Timeline& timeline){
  AudioStreamBasicDescription format{rate,kAudioFormatLinearPCM,kAudioFormatFlagIsFloat|kAudioFormatFlagIsPacked|kAudioFormatFlagIsNonInterleaved,4,1,4,2,32,0};UInt32 block=frames;
  check(AudioUnitSetProperty(u,kAudioUnitProperty_StreamFormat,kAudioUnitScope_Output,0,&format,sizeof(format)),"Stereo float format");
  check(AudioUnitSetProperty(u,kAudioUnitProperty_MaximumFramesPerSlice,kAudioUnitScope_Global,0,&block,sizeof(block)),"256-frame buffer");
  HostCallbackInfo callbacks{};callbacks.hostUserData=&timeline;callbacks.beatAndTempoProc=beat;callbacks.musicalTimeLocationProc=musical;callbacks.transportStateProc=transport;
  check(AudioUnitSetProperty(u,kAudioUnitProperty_HostCallbacks,kAudioUnitScope_Global,0,&callbacks,sizeof(callbacks)),"120 BPM transport");
  check(AudioUnitInitialize(u),"Initialize AU");
}
void restore(AudioUnit u,NSDictionary* source,UInt32 subtype){
  NSMutableDictionary* state=[source mutableCopy];identity(state,subtype);CFPropertyListRef value=(__bridge CFPropertyListRef)state;
  check(AudioUnitSetProperty(u,kAudioUnitProperty_ClassInfo,kAudioUnitScope_Global,0,&value,sizeof(value)),"Restore identical AU bank");
}
NSDictionary* voiceCounts(AudioUnit u){
  NSDictionary* voice=status(u)[@"engine"][@"voice_activity"];NSMutableDictionary* safe=[NSMutableDictionary dictionary];
  for(NSString* key in @[@"available",@"capacity",@"occupied",@"held",@"released",@"forced_release",@"counters_consistent"])
    if([voice[key] isKindOfClass:NSNumber.class])safe[key]=voice[key];
  return safe;
}
void prepare(NSString* input,NSString* statePath,NSMutableDictionary* report){
  report[@"stage"]=@"read selected preset";report[@"preset_filename"]=input.lastPathComponent;
  NSData* file=[NSData dataWithContentsOfFile:input];if(!file||file.length>2*1024*1024)throw std::runtime_error("Cannot read the selected preset");
  NSDictionary* state=nil;
  if([input.pathExtension.lowercaseString isEqualToString:@"fxp"]||(file.length>=4&&!std::memcmp(file.bytes,"CcnK",4))){
    report[@"stage"]=@"validate FXP header";
    const auto* data=static_cast<const unsigned char*>(file.bytes);
    const auto header=cronox::probe::inspectFxp(file.bytes,file.length);
    const auto id=cronox::probe::fourCC(header.fileID);
    report[@"fxp_header"]=@{@"format":@"FPCh",@"version":@(header.version),@"vst_file_id":[NSString stringWithUTF8String:id.c_str()],
      @"plugin_version":@(header.pluginVersion),@"program_count":@(header.programCount),@"payload_offset":@(header.payloadOffset),@"payload_bytes":@(header.payloadBytes)};
    report[@"stage"]=@"open ARM AU for shared bank";
    Instance unit;open(unit,armID);localImage(armID,report);
    report[@"stage"]=@"import FXP chunk";
    check(AudioUnitSetProperty(unit.value,importID,kAudioUnitScope_Global,0,data+header.payloadOffset,header.payloadBytes),"Load local FXP");
    report[@"stage"]=@"save shared AU bank";
    CFPropertyListRef saved=nullptr;UInt32 size=sizeof(saved);
    check(AudioUnitGetProperty(unit.value,kAudioUnitProperty_ClassInfo,kAudioUnitScope_Global,0,&saved,&size),"Export shared AU bank");
    if(!saved||CFGetTypeID(saved)!=CFDictionaryGetTypeID()){if(saved)CFRelease(saved);throw std::runtime_error("Missing shared AU bank");}
    state=cleanState((__bridge NSDictionary*)saved);CFRelease(saved);
    report[@"arm_build"]=status(unit.value)[@"wrapper_version"]?:@"";
  }else {report[@"stage"]=@"read AU preset";state=readState(input);}
  report[@"stage"]=@"write private shared AU bank";
  NSData* serialized=[NSPropertyListSerialization dataWithPropertyList:state format:NSPropertyListBinaryFormat_v1_0 options:0 error:nil];
  if(!serialized||![serialized writeToFile:statePath options:NSDataWritingAtomic error:nil]||chmod(statePath.fileSystemRepresentation,0600))throw std::runtime_error("Cannot save temporary private AU bank");
  report[@"preset_filename"]=input.lastPathComponent;report[@"bank_bytes"]=@([state[@"vstdata"] length]);report[@"input_bank_sha256"]=hash(state[@"vstdata"]);
  report[@"raw_state_in_report"]=@NO;report[@"measurement_valid"]=@YES;report[@"stage"]=@"prepared";
}
void measure(UInt32 subtype,NSString* statePath,bool bypass,bool paced,NSString* ready,NSMutableDictionary* report){
  Instance unit;open(unit,subtype);localImage(subtype,report);
  NSDictionary* bank=readState(statePath);report[@"input_bank_sha256"]=hash(bank[@"vstdata"]);restore(unit.value,bank,subtype);
  Timeline timeline;setup(unit.value,timeline);
  NSMutableArray* effects=[NSMutableArray array];unsigned reverbCount=0,activeReverbs=0;
  for(unsigned slot=0;slot<6;++slot){
    float typeValue=0,on=0;check(AudioUnitGetParameter(unit.value,213+slot,kAudioUnitScope_Global,0,&typeValue),"Original effect type");
    check(AudioUnitGetParameter(unit.value,219+slot,kAudioUnitScope_Global,0,&on),"Original effect on/off");
    if(std::lround(typeValue)==6){++reverbCount;if(on>.5)++activeReverbs;if(bypass)check(AudioUnitSetParameter(unit.value,219+slot,kAudioUnitScope_Global,0,0,0),"Bypass original reverb");}
    float actual=0;check(AudioUnitGetParameter(unit.value,219+slot,kAudioUnitScope_Global,0,&actual),"Read effect on/off");
    if(bypass&&std::lround(typeValue)==6&&actual!=0)throw std::runtime_error("Reverb bypass was not applied");
    [effects addObject:@{@"slot":@(slot+1),@"type":@(typeValue),@"on_before":@(on),@"on_after":@(actual)}];
  }
  if(!activeReverbs)throw std::runtime_error("The selected preset has no active Reverb effect; select Breath and Butter");
  if(subtype==armID){NSDictionary* current=status(unit.value);report[@"arm_build"]=current[@"wrapper"]?:current[@"wrapper_version"]?:@"";
    report[@"preset_name"]=current[@"preset_name"]?:@"";
    report[@"original_registration_accepted"]=current[@"engine"][@"registration_accepted"]?:@NO;
    if(![report[@"original_registration_accepted"] boolValue])throw std::runtime_error("Native AU did not accept the original registration");}
  report[@"effects"]=effects;report[@"reverb_slots"]=@(reverbCount);report[@"reverb_bypassed"]=@(bypass);
  report[@"sample_rate"]=@(rate);report[@"buffer_frames"]=@(frames);report[@"note_on_seconds"]=@(onBlock*frames/rate);report[@"note_off_seconds"]=@(offBlock*frames/rate);
  report[@"notes"]=@[@60,@64,@67];report[@"velocity"]=@100;report[@"tempo_bpm"]=@120;
  report[@"audio_seconds"]=@(totalBlocks*frames/rate);report[@"paced_like_audio_host"]=@(paced);report[@"profiling_run"]=@(ready!=nil);
  NSMutableArray* trace=[NSMutableArray array];report[@"trace"]=trace;
  if(ready&&![@"ready\n" writeToFile:ready atomically:YES encoding:NSUTF8StringEncoding error:nil])throw std::runtime_error("Cannot signal profiling readiness");
  std::array<float,frames> left{},right{};
  struct {UInt32 count;AudioBuffer buffers[2];} list{2,{{1,frames*4,left.data()},{1,frames*4,right.data()}}};
  double wallStart=seconds(CLOCK_MONOTONIC),bucketCPU=0,bucketWall=0,bucketPeak=0,bucketSquared=0,totalCPU=0,totalProcessCPU=0;
  double bucketProcessCPU=0,bucketWorst=0,peak=0;unsigned bucketStart=0,zeroBlocks=0,silenceFlagBlocks=0;
  for(unsigned at=0;at<totalBlocks;++at){@autoreleasepool{
    timeline.sample=at*frames;
    if(at==onBlock||at==offBlock)for(unsigned note:{60u,64u,67u})check(MusicDeviceMIDIEvent(unit.value,at==onBlock?0x90:0x80,note,at==onBlock?100:0,0),"Three-note chord");
    left.fill(0);right.fill(0);
    for(unsigned c=0;c<2;++c)list.buffers[c]={1,frames*4,c?right.data():left.data()};
    AudioTimeStamp timestamp{};timestamp.mSampleTime=timeline.sample;timestamp.mFlags=kAudioTimeStampSampleTimeValid;
    AudioUnitRenderActionFlags flags=0;
    double processBefore=seconds(CLOCK_PROCESS_CPUTIME_ID),cpuBefore=seconds(CLOCK_THREAD_CPUTIME_ID),wallBefore=seconds(CLOCK_MONOTONIC);
    check(AudioUnitRender(unit.value,&flags,&timestamp,0,frames,reinterpret_cast<AudioBufferList*>(&list)),"Render AU");
    double wall=seconds(CLOCK_MONOTONIC)-wallBefore,cpu=seconds(CLOCK_THREAD_CPUTIME_ID)-cpuBefore,process=seconds(CLOCK_PROCESS_CPUTIME_ID)-processBefore;
    bucketCPU+=cpu;bucketProcessCPU+=process;bucketWall+=wall;bucketWorst=std::max(bucketWorst,wall);totalCPU+=cpu;totalProcessCPU+=process;
    if(list.count!=2)throw std::runtime_error("Unexpected output buffer count");
    double blockPeak=0;
    for(unsigned c=0;c<2;++c){
      if(!list.buffers[c].mData||list.buffers[c].mDataByteSize<frames*4)throw std::runtime_error("Short AU output buffer");
      const auto* samples=static_cast<const float*>(list.buffers[c].mData);
      for(unsigned i=0;i<frames;++i){double value=samples[i];if(!std::isfinite(value))throw std::runtime_error("Non-finite AU output");blockPeak=std::max(blockPeak,std::abs(value));bucketSquared+=value*value;}
    }
    bucketPeak=std::max(bucketPeak,blockPeak);peak=std::max(peak,blockPeak);if(blockPeak==0)++zeroBlocks;if(flags&kAudioUnitRenderAction_OutputIsSilence)++silenceFlagBlocks;
    if((at+1)%bucketBlocks==0||at+1==totalBlocks){
      unsigned count=at+1-bucketStart;double duration=count*frames/rate;
      NSMutableDictionary* row=[NSMutableDictionary dictionaryWithDictionary:@{@"start_seconds":@(bucketStart*frames/rate),@"end_seconds":@((at+1)*frames/rate),
        @"thread_cpu_seconds":@(bucketCPU),@"process_cpu_seconds":@(bucketProcessCPU),@"render_wall_seconds":@(bucketWall),@"cpu_ratio":@(bucketCPU/duration),@"worst_block_wall_seconds":@(bucketWorst),
        @"peak":@(bucketPeak),@"rms":@(std::sqrt(bucketSquared/(count*frames*2))),@"exact_zero_blocks":@(zeroBlocks),@"output_silence_flag_blocks":@(silenceFlagBlocks),@"blocks":@(count)}];
      if(subtype==armID)row[@"voices"]=voiceCounts(unit.value);[trace addObject:row];
      bucketStart=at+1;bucketCPU=bucketProcessCPU=bucketWall=bucketPeak=bucketSquared=bucketWorst=0;zeroBlocks=silenceFlagBlocks=0;
    }
    if(paced){
      CFRunLoopRunInMode(kCFRunLoopDefaultMode,0,true);
      const double due=wallStart+(at+1)*frames/rate;
      for(;;){double remaining=due-seconds(CLOCK_MONOTONIC);if(remaining<=0)break;
        timespec pause{time_t(remaining),long((remaining-std::floor(remaining))*1e9)};nanosleep(&pause,nullptr);}
    }
  }}
  report[@"peak"]=@(peak);report[@"render_thread_cpu_seconds"]=@(totalCPU);report[@"render_process_cpu_seconds"]=@(totalProcessCPU);
  report[@"render_cpu_ratio"]=@(totalCPU/(totalBlocks*frames/rate));report[@"elapsed_wall_seconds"]=@(seconds(CLOCK_MONOTONIC)-wallStart);
  report[@"measurement_valid"]=@(peak>1e-5);if(peak<=1e-5)report[@"error"]=@"This AU was silent; CPU comparison is invalid. Check the preset's samples and original licence locally.";
}
}
int main(int argc,char** argv){@autoreleasepool{
  NSMutableDictionary* report=[NSMutableDictionary dictionaryWithDictionary:@{@"diagnostic":@"RV002",@"measurement_valid":@NO,@"cpu_problem_resolved":@NO,@"raw_state_in_report":@NO}];
  NSString* output=nil;
#if defined(__arm64__) || defined(__aarch64__)
  report[@"host_architecture"]=@"arm64";
#else
  report[@"host_architecture"]=@"x86_64";
#endif
  int translated=0;size_t translatedBytes=sizeof(translated);sysctlbyname("sysctl.proc_translated",&translated,&translatedBytes,nullptr,0);report[@"host_runs_under_rosetta"]=@(translated!=0);
  @try{try{
    if(argc<5)throw std::runtime_error("Expected --prepare preset private-state report OR --measure original|arm private-state report [--bypass] [--paced] [--ready filename]");
    const std::string mode=argv[1];output=[NSString stringWithUTF8String:argv[4]];
    if(mode=="--prepare"){
#if defined(__arm64__) || defined(__aarch64__)
      if(argc!=5)throw std::runtime_error("Unexpected prepare options");prepare([NSString stringWithUTF8String:argv[2]],[NSString stringWithUTF8String:argv[3]],report);
#else
      throw std::runtime_error("Preset preparation requires the native arm64 host");
#endif
    }else if(mode=="--measure"){
      std::string identityName=argv[2];if(identityName!="original"&&identityName!="arm")throw std::runtime_error("Unknown AU identity");
      UInt32 subtype=identityName=="original"?originalID:armID;report[@"subtype"]=identityName=="original"?@"CrX3":@"CrT3";
#if defined(__arm64__) || defined(__aarch64__)
      if(subtype!=armID)throw std::runtime_error("Original Intel measurements must run in the x86_64 host");
#else
      if(subtype!=originalID)throw std::runtime_error("ARM measurements must run in the arm64 host");
#endif
      bool bypass=false,paced=false;NSString* ready=nil;
      for(int i=5;i<argc;++i){std::string option=argv[i];if(option=="--bypass")bypass=true;else if(option=="--paced")paced=true;else if(option=="--ready"&&i+1<argc)ready=[NSString stringWithUTF8String:argv[++i]];else throw std::runtime_error("Unknown measurement option");}
      measure(subtype,[NSString stringWithUTF8String:argv[3]],bypass,paced,ready,report);
    }else throw std::runtime_error("Unknown diagnostic mode");
  }catch(const std::exception& error){report[@"error"]=[NSString stringWithUTF8String:error.what()];report[@"measurement_valid"]=@NO;}}
  @catch(NSException* error){report[@"error"]=error.reason?:error.name;report[@"measurement_valid"]=@NO;}
  if(output){try{writeJSON(report,output);}catch(...){fprintf(stderr,"Cannot save report\n");return 2;}}
  fprintf(stdout,"RV002: %s\n",[report[@"measurement_valid"] boolValue]?"measurement recorded":"measurement failed; see report");
  return [report[@"measurement_valid"] boolValue]?0:1;
}}
