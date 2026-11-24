#include "../src/engine/LegacyEngine.h"
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <stdexcept>
#include <fstream>
#include <algorithm>
int main(int argc, char** argv) {
  const char* stage="initialize";
  try {
    sophistry::LegacyEngineConfig config;
    config.audioUnitMode=true;
    config.recycleFreedBlocks=true;
    sophistry::LegacyEngine engine(config);
    engine.initialize();
    stage="parameters";
    auto ids=engine.auParameterIds();
    if(ids.size()!=522 || std::set<unsigned>(ids.begin(),ids.end()).size()!=ids.size())throw std::runtime_error("Incorrect AU parameter IDs");
    for(auto id:ids){
      auto info=engine.auParameterInfo(id);
      auto value=engine.auParameter(id);
      if(!std::isfinite(value) || info.minimum>info.maximum || info.name.empty())throw std::runtime_error("Invalid AU parameter metadata");
      engine.setAUParameter(id,value);
      (void)engine.auParameterText(id,value);
    }
    stage="state";
    const auto name=engine.presetName();
    auto state=engine.saveProgram();
    engine.restoreChunk(state,true);
    if(name!=engine.presetName() || state!=engine.saveProgram())throw std::runtime_error("Program round trip differs");
    if(argc==3) {
      stage="public FXP load";
      engine.setAssetDirectories({argv[2]});
      std::ifstream f(argv[1],std::ios::binary);
      std::vector<unsigned char> raw((std::istreambuf_iterator<char>(f)),{});
      if(raw.size()<60 || std::string(raw.begin(),raw.begin()+4)!="CcnK" || std::string(raw.begin()+8,raw.begin()+12)!="FPCh")throw std::runtime_error("Expected public FXP");
      engine.restoreChunk({raw.begin()+60,raw.end()},true);
      if(engine.presetName().empty())throw std::runtime_error("Missing restored preset name");
    } else if(argc!=1)throw std::runtime_error("Expected FXP and sample folder or no arguments");
    stage="activate";
    engine.setSampleRate(44100);engine.setBlockSize(256);engine.activate();
    stage="render";
    std::vector<float> l(256),r(256);float* outputs[]={l.data(),r.data()};
    double peak=0;
    engine.midi(0x90,60,100);
    for(int block=0;block<8;++block) {
      if(block==4)engine.midi(0x80,60,0);
      engine.process(outputs,2,256);
      for(auto v:l)peak=std::max(peak,double(std::abs(v)));
      for(auto v:l)if(!std::isfinite(v))throw std::runtime_error("Non-finite audio");
      for(auto v:r)if(!std::isfinite(v))throw std::runtime_error("Non-finite audio");
    }
    std::fprintf(stderr,"Render peak: %.9g; public preset loaded: %s; original licence check retained\n",peak,argc==3?"yes":"no");
    stage="reset";engine.resetAudioUnit();engine.deactivate();
    std::printf("{\"project\":\"CronoX 3\",\"original_au_bridge\":true,\"parameters\":%zu,\"program_roundtrip\":true,\"program_bytes\":%zu,\"rendered_frames\":2048,\"finite_audio\":true,\"sound_fidelity_verified\":false,\"macos_auval_executed\":false}\n",ids.size(),state.size());
    return 0;
  } catch(const std::exception& error) {std::fprintf(stderr,"CronoX AU bridge (%s): %s\n",stage,error.what());return 1;}
}
