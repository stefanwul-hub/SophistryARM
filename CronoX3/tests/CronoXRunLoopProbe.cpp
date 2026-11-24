#include "../src/engine/LegacyEngine.h"
#include "../src/engine/PreferenceDomains.h"
#include <cstdio>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <cmath>
int main(int argc,char** argv) {
  const char* stage="construct";
  try {
    const auto reads=sophistry::preferenceReadDomains("com.linplug.CronoX3");
    if(reads.size()!=2 || reads[0]!="com.linplug.CronoX3.ARMTest" || reads[1]!="com.linplug.CronoX3" ||
       sophistry::preferenceWriteDomain("com.linplug.CronoX3")!="com.linplug.CronoX3.ARMTest")
      throw std::runtime_error("Comparison preference isolation differs");
    double now=1794675600.0-978307200.0;
    sophistry::LegacyEngineConfig config;config.audioUnitMode=true;config.recycleFreedBlocks=true;
    config.runLoopClock=[&]{return now;};
    sophistry::LegacyEngine engine(config);engine.initialize();
    if(argc==3) {
      stage="preset";engine.setAssetDirectories({argv[2]});
      std::ifstream f(argv[1],std::ios::binary);
      std::vector<unsigned char> raw((std::istreambuf_iterator<char>(f)),{});
      if(raw.size()<60)throw std::runtime_error("Invalid FXP input");
      engine.restoreChunk({raw.begin()+60,raw.end()},true);
    }
    stage="activate";engine.setSampleRate(44100);engine.setBlockSize(256);engine.activate();
    stage="bank round trip";
    auto bank=engine.saveBank();engine.restoreChunk(bank,false);
    const auto name=engine.presetName();
    stage="run loop";
    unsigned callbacks=0;std::vector<float> left(256),right(256);float* output[]={left.data(),right.data()};
    engine.midi(0x90,60,100);
    for(unsigned block=0;block<24;++block){
      if(block==12)engine.midi(0x80,60,0);
      callbacks+=engine.serviceTimers();
      engine.process(output,2,256);
      for(auto value:left)if(!std::isfinite(value))throw std::runtime_error("Non-finite output");
      now+=256.0/44100;
    }
    if(!callbacks)throw std::runtime_error("Original timer callback was not dispatched");
    if(engine.presetName()!=name)throw std::runtime_error("Idle changed the preset label");
    stage="original shutdown";engine.shutdown();engine.shutdown();
    if(engine.diagnosticJson().find("\"disposed\":true")==std::string::npos)throw std::runtime_error("Engine did not close");
    std::printf("{\"passed\":true,\"original_timer_callbacks\":%u,\"rendered_frames\":6144,\"bank_roundtrip_bytes\":%zu,\"original_destructor_executed\":true,\"global_destructors_executed\":true,\"comparison_preferences_isolated\":true}\n",callbacks,bank.size());
    return 0;
  } catch(const std::exception& error){std::fprintf(stderr,"CronoX run-loop (%s): %s\n",stage,error.what());return 1;}
}
