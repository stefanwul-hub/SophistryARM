// macOS diagnostic host. This is NOT an Audio Unit implementation.
#include <AudioToolbox/AudioToolbox.h>
#include <AudioUnit/AudioUnit.h>
#include <CoreFoundation/CoreFoundation.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

static void check(OSStatus s, const char* operation) {
    if (s) throw std::runtime_error(std::string(operation)+": OSStatus "+std::to_string(s));
}
static void writeFile(const std::filesystem::path& p, const UInt8* data, CFIndex size) {
    std::ofstream f(p,std::ios::binary);f.write(reinterpret_cast<const char*>(data),size);
    if (!f) throw std::runtime_error("Cannot write "+p.string());
}
static CFPropertyListRef loadPreset(const char* path) {
    std::ifstream f(path,std::ios::binary);
    std::vector<UInt8> bytes((std::istreambuf_iterator<char>(f)),{});
    if (!f || bytes.empty()) throw std::runtime_error("Cannot read preset");
    CFDataRef data=CFDataCreate(nullptr,bytes.data(),bytes.size());
    CFErrorRef err=nullptr;
    CFPropertyListRef pl=CFPropertyListCreateWithData(nullptr,data,kCFPropertyListImmutable,nullptr,&err);
    CFRelease(data);
    if (!pl) { if (err)CFRelease(err);throw std::runtime_error("Invalid preset plist"); }
    if (CFGetTypeID(pl)!=CFDictionaryGetTypeID()) {CFRelease(pl);throw std::runtime_error("Preset must be a dictionary");}
    const CFStringRef keys[]={CFSTR("type"),CFSTR("subtype"),CFSTR("manufacturer")};
    const int64_t expected[]={0x61756d75,0x536f7033,0x4c696e50};
    for(int i=0;i<3;++i) {
        auto n=static_cast<CFNumberRef>(CFDictionaryGetValue(static_cast<CFDictionaryRef>(pl),keys[i]));
        int64_t value=0;
        if(!n || CFGetTypeID(n)!=CFNumberGetTypeID() || !CFNumberGetValue(n,kCFNumberSInt64Type,&value) || value!=expected[i]) {
            CFRelease(pl);throw std::runtime_error("Preset identity differs from aumu/Sop3/LinP");
        }
    }
    return pl;
}
static void saveState(AudioUnit unit,const std::filesystem::path& path) {
    CFPropertyListRef state=nullptr;UInt32 size=sizeof(state);
    check(AudioUnitGetProperty(unit,kAudioUnitProperty_ClassInfo,kAudioUnitScope_Global,0,&state,&size),"Get ClassInfo");
    CFErrorRef error=nullptr;
    CFDataRef data=CFPropertyListCreateData(nullptr,state,kCFPropertyListBinaryFormat_v1_0,0,&error);
    CFRelease(state);
    if (!data) {if(error)CFRelease(error);throw std::runtime_error("Serialize state failed");}
    writeFile(path,CFDataGetBytePtr(data),CFDataGetLength(data));CFRelease(data);
}
struct Transport {double sample=0, rate=48000;};
static OSStatus beatTempo(void* p,Float64* beat,Float64* bpm) {
    auto* t=static_cast<Transport*>(p);if(beat)*beat=t->sample/t->rate*2.;if(bpm)*bpm=120.;return noErr;
}
static OSStatus musical(void* p,UInt32* next,Float32* num,UInt32* den,Float64* down) {
    auto* t=static_cast<Transport*>(p);double beat=t->sample/t->rate*2.;
    if(next)*next=static_cast<UInt32>((std::ceil(beat)-beat)*t->rate/2.);
    if(num)*num=4;if(den)*den=4;if(down)*down=std::floor(beat/4.)*4.;return noErr;
}
static OSStatus transport(void* p,Boolean* playing,Boolean* changed,Float64* sample,
                           Boolean* cycling,Float64* start,Float64* end) {
    auto* t=static_cast<Transport*>(p);if(playing)*playing=true;if(changed)*changed=t->sample==0;
    if(sample)*sample=t->sample;if(cycling)*cycling=false;if(start)*start=0;if(end)*end=0;return noErr;
}
int main(int argc,char** argv) {
    AudioUnit unit=nullptr;ExtAudioFileRef audio=nullptr;bool initialized=false;
    try {
        if(argc<2 || argc>5)throw std::runtime_error("Usage: AUStateProbe output_directory [preset.aupreset|-] [sample_rate] [block_frames]");
        const std::filesystem::path out=argv[1];std::filesystem::create_directories(out);
        double rate=argc>3?std::stod(argv[3]):48000.;UInt32 block=argc>4?std::stoul(argv[4]):512;
        if((rate!=44100 && rate!=48000 && rate!=96000) || block<1 || block>4096)throw std::runtime_error("Unsupported rate/block");
        AudioComponentDescription desc={kAudioUnitType_MusicDevice,0x536f7033,0x4c696e50,0,0};
        AudioComponent component=AudioComponentFindNext(nullptr,&desc);
        if(!component)throw std::runtime_error("No registered Audio Unit aumu/Sop3/LinP. The supplied i386/ppc component cannot load natively on macOS 15.");
        check(AudioComponentInstanceNew(component,&unit),"Instantiate AU");
        AudioStreamBasicDescription client={};client.mSampleRate=rate;client.mFormatID=kAudioFormatLinearPCM;
        client.mFormatFlags=kAudioFormatFlagIsFloat|kAudioFormatFlagIsPacked|kAudioFormatFlagIsNonInterleaved|kAudioFormatFlagsNativeEndian;
        client.mBytesPerPacket=4;client.mFramesPerPacket=1;client.mBytesPerFrame=4;client.mChannelsPerFrame=2;client.mBitsPerChannel=32;
        check(AudioUnitSetProperty(unit,kAudioUnitProperty_StreamFormat,kAudioUnitScope_Output,0,&client,sizeof(client)),"Set stereo output format");
        check(AudioUnitSetProperty(unit,kAudioUnitProperty_MaximumFramesPerSlice,kAudioUnitScope_Global,0,&block,sizeof(block)),"Set maximum block");
        Transport time;time.rate=rate;HostCallbackInfo host={};host.hostUserData=&time;
        host.beatAndTempoProc=beatTempo;host.musicalTimeLocationProc=musical;host.transportStateProc=transport;
        check(AudioUnitSetProperty(unit,kAudioUnitProperty_HostCallbacks,kAudioUnitScope_Global,0,&host,sizeof(host)),"Set transport callbacks");
        if(argc>2 && std::string(argv[2])!="-") {
            CFPropertyListRef pl=loadPreset(argv[2]);OSStatus s=AudioUnitSetProperty(unit,kAudioUnitProperty_ClassInfo,kAudioUnitScope_Global,0,&pl,sizeof(pl));CFRelease(pl);check(s,"Restore ClassInfo");
        }
        check(AudioUnitInitialize(unit),"Initialize AU");initialized=true;
        UInt32 size=0;Boolean writable=false;
        check(AudioUnitGetPropertyInfo(unit,kAudioUnitProperty_ParameterList,kAudioUnitScope_Global,0,&size,&writable),"Get parameter list size");
        std::vector<AudioUnitParameterID> ids(size/sizeof(AudioUnitParameterID));
        if(size)check(AudioUnitGetProperty(unit,kAudioUnitProperty_ParameterList,kAudioUnitScope_Global,0,ids.data(),&size),"Get parameter IDs");
        std::ofstream params(out/"parameters.tsv");params<<"id\tvalue\n";
        for(auto id:ids){AudioUnitParameterValue value=0;check(AudioUnitGetParameter(unit,id,kAudioUnitScope_Global,0,&value),"Get parameter");params<<id<<'\t'<<value<<'\n';}
        saveState(unit,out/"state-before.aupreset");
        AudioStreamBasicDescription file=client;file.mFormatFlags &= ~kAudioFormatFlagIsNonInterleaved;
        file.mBytesPerPacket=8;file.mBytesPerFrame=8;
        auto filePath=(out/"render.wav").string();CFURLRef url=CFURLCreateFromFileSystemRepresentation(nullptr,reinterpret_cast<const UInt8*>(filePath.data()),filePath.size(),false);
        OSStatus s=ExtAudioFileCreateWithURL(url,kAudioFileWAVEType,&file,nullptr,kAudioFileFlags_EraseFile,&audio);CFRelease(url);check(s,"Create WAV");
        check(ExtAudioFileSetProperty(audio,kExtAudioFileProperty_ClientDataFormat,sizeof(client),&client),"Set WAV client format");
        check(MusicDeviceMIDIEvent(unit,0xb0,64,0,0),"Sustain off");
        check(MusicDeviceMIDIEvent(unit,0x90,60,100,0),"Note on C4");
        std::vector<float> left(block),right(block);
        struct Buffers {UInt32 count;AudioBuffer buffers[2];} buffers={2,{{1,0,nullptr},{1,0,nullptr}}};
        const UInt32 total=static_cast<UInt32>(3*rate),off=static_cast<UInt32>(2*rate);
        double peak=0,sum=0;UInt64 count=0;
        for(UInt32 frame=0;frame<total;frame+=block) {
            UInt32 n=std::min(block,total-frame);time.sample=frame;
            if(frame<=off && off<frame+n)check(MusicDeviceMIDIEvent(unit,0x80,60,0,off-frame),"Note off");
            std::fill(left.begin(),left.end(),0);std::fill(right.begin(),right.end(),0);
            buffers.buffers[0]={1,n*4,left.data()};buffers.buffers[1]={1,n*4,right.data()};
            AudioTimeStamp timestamp={};timestamp.mSampleTime=frame;timestamp.mFlags=kAudioTimeStampSampleTimeValid;
            AudioUnitRenderActionFlags flags=0;
            auto* list=reinterpret_cast<AudioBufferList*>(&buffers);
            check(AudioUnitRender(unit,&flags,&timestamp,0,n,list),"Render");
            if(list->mNumberBuffers!=2 || !list->mBuffers[0].mData || !list->mBuffers[1].mData)throw std::runtime_error("Unexpected render buffer layout");
            for(int c=0;c<2;++c){auto* samples=static_cast<float*>(list->mBuffers[c].mData);for(UInt32 i=0;i<n;++i){double x=samples[i];if(!std::isfinite(x))throw std::runtime_error("Nonfinite audio output");peak=std::max(peak,std::abs(x));sum+=x*x;++count;}}
            check(ExtAudioFileWrite(audio,n,list),"Write WAV");
        }
        check(ExtAudioFileDispose(audio),"Close WAV");audio=nullptr;
        saveState(unit,out/"state-after.aupreset");
        std::ofstream report(out/"render-report.json");report<<"{\"sample_rate\":"<<rate<<",\"block_frames\":"<<block<<",\"frames\":"<<total<<",\"peak\":"<<peak<<",\"rms\":"<<std::sqrt(sum/count)<<",\"note\":60,\"velocity\":100,\"bpm\":120,\"non_silent\":"<<(peak>1e-8?"true":"false")<<",\"project_reopening_tested\":false}\n";
        AudioUnitUninitialize(unit);initialized=false;AudioComponentInstanceDispose(unit);unit=nullptr;
        if(peak<=1e-8)throw std::runtime_error("Render is silent; this is not evidence of working synthesis");
        std::puts("Rendered 3 s and saved parameter/state snapshots. Compare to an original reference; this does not certify old DAW projects.");return 0;
    } catch(const std::exception& e) {
        if(audio)ExtAudioFileDispose(audio);if(unit){if(initialized)AudioUnitUninitialize(unit);AudioComponentInstanceDispose(unit);}
        std::fprintf(stderr,"%s\n",e.what());return 1;
    }
}
