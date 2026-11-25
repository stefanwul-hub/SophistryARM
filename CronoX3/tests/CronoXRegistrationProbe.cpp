// A fresh process queries the system AU registry only. It never calls
// AudioComponentRegister or loads a candidate bundle by path.
#include "../src/au/CronoXIdentity.h"
#include "../src/au/SophistryProperties.h"
#include <AudioToolbox/AudioToolbox.h>
#include <CoreFoundation/CoreFoundation.h>
#include <cstdio>
#include <stdexcept>
#include <string>
#include <vector>

namespace {
std::string string(CFStringRef value) {
  if(!value)return {};
  std::vector<char> bytes(CFStringGetMaximumSizeForEncoding(CFStringGetLength(value),kCFStringEncodingUTF8)+1);
  if(!CFStringGetCString(value,bytes.data(),bytes.size(),kCFStringEncodingUTF8))throw std::runtime_error("Invalid component name");
  return bytes.data();
}
std::string quote(const std::string& value) {
  std::string out="\"";
  for(unsigned char c:value){if(c=='"'||c=='\\')out+='\\';if(c<32){char escaped[7];std::snprintf(escaped,sizeof(escaped),"\\u%04x",c);out+=escaped;}else out+=char(c);}
  return out+'"';
}
void check(OSStatus code,const char* operation){if(code)throw std::runtime_error(std::string(operation)+": "+std::to_string(code));}
}
int main(){
  AudioComponentDescription desc{cronox::identity::type,cronox::identity::subtype,cronox::identity::manufacturer,0,0};
  AudioUnit instance=nullptr;unsigned count=0;UInt32 version=0;std::string name,build,error,stage="lookup";int result=6;
  try {
    AudioComponent component=nullptr,next=nullptr;
    while((next=AudioComponentFindNext(next,&desc))){component=next;++count;}
    if(!count){result=3;throw std::runtime_error("CrT3 component not registered");}
    if(count!=1){result=4;throw std::runtime_error("Multiple CrT3 components are registered");}
    stage="metadata";CFStringRef label=nullptr;check(AudioComponentCopyName(component,&label),"Component name");
    name=string(label);if(label)CFRelease(label);if(name.empty())throw std::runtime_error("Empty registered component name");
    check(AudioComponentGetVersion(component,&version),"Component version");
    stage="loaded build";check(AudioComponentInstanceNew(component,&instance),"Registered factory");
    CFStringRef marker=nullptr;UInt32 bytes=sizeof(marker);
    check(AudioUnitGetProperty(instance,0x53705672,kAudioUnitScope_Global,0,&marker,&bytes),"Build marker");
    build=string(marker);if(marker)CFRelease(marker);
    if(build!=sophistry::wrapperVersion){result=5;throw std::runtime_error("The registry still loads another comparison build");}
    stage="disposal";check(AudioComponentInstanceDispose(instance),"Dispose");instance=nullptr;stage="completed";result=0;
  }catch(const std::exception& failure){error=failure.what();}
  if(instance)AudioComponentInstanceDispose(instance);
  std::printf("{\"scope\":\"fresh system AU registry lookup\",\"subtype\":\"CrT3\",\"registered_matches\":%u,\"component_name\":%s,\"component_version\":%u,\"loaded_build\":%s,\"stage\":%s,\"error\":%s,\"passed\":%s}\n",count,quote(name).c_str(),version,quote(build).c_str(),quote(stage).c_str(),quote(error).c_str(),result==0?"true":"false");
  return result;
}
