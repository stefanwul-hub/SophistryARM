// Original-runtime regression. No private preferences, registration input or rendered licence bypass.
#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>
#define private public
#include "../src/engine/LegacyEngine.h"
#undef private
#include "../src/engine/LegacyEngine.cpp"
#include "../src/au/CronoXPresetNames.h"
#include "../src/au/CronoXTypography.h"
using namespace sophistry;
void check(bool v,const char* why){if(!v)throw std::runtime_error(why);}
int main(int argc,char** argv){try{
 check(argc==3,"Expected public FXP and sample directory");
 LegacyEngineConfig a;a.audioUnitMode=true;a.recycleFreedBlocks=true;a.collectDiagnostics=false;a.assetDirectories={argv[2]};auto b=a;b.preMasterGainDb=6;
 LegacyEngine original(a),ported(b);original.initialize();ported.initialize();
 std::ifstream f(argv[1],std::ios::binary);std::vector<unsigned char> fxp((std::istreambuf_iterator<char>(f)),{});
 check(cronox::usablePresetName(cronox::fxpProgramName(fxp.data(),fxp.size())),"Missing FPCh name");
 check(!cronox::usablePresetName(" unknown ")&&!cronox::usablePresetName("Default"),"Placeholder accepted as preset name");
 original.restoreChunk({fxp.begin()+60,fxp.end()},true);ported.restoreChunk({fxp.begin()+60,fxp.end()},true);
 unsigned cases=0;const double factor=std::pow(10.0,6.0/20.0);
 auto& x=*original.impl_;auto& y=*ported.impl_;
 for(float value:{0.f,.1f,.5f,.9f,1.f,.25f,.75f,.1f,1.f}) {
   original.setEditorControl(134,value);ported.setEditorControl(134,value);
   const auto px=x.run(0x1b16e,{0x1000000,134}),py=y.run(0x1b16e,{0x1000000,134});
   check(x.word(px+0x14)==y.word(py+0x14),"Master dB value changed");
   check(x.word(px+8)==y.word(py+8),"Normalized automation changed");
   check(original.auParameter(134)==ported.auParameter(134),"AU Master changed");
   const float base=x.read<float>(px+12),gain=y.read<float>(py+12);
   check(base==0?gain==0:std::abs(double(gain)/base-factor)<1e-6,"Original Master coefficient lacks +6 dB");
   check(original.saveProgram()==ported.saveProgram(),"Gain calibration altered serialized preset");
   for(float sample:{-2.f,-.5f,0.f,.125f,1.f,2.f}) {
     const double preMaster=double(sample)*factor*base,combined=double(sample)*gain;
     check(std::abs(preMaster-combined)<1e-6,"Pre-Master signal equivalence failed");++cases;
   }
 }
 const auto bank=original.saveBank();ported.restoreChunk(bank,false);
 check(original.saveBank()==ported.saveBank(),"Gain calibration altered complete AU bank");
 const auto px=x.run(0x1b16e,{0x1000000,134}),py=y.run(0x1b16e,{0x1000000,134});
 check(std::abs(double(y.read<float>(py+12))/x.read<float>(px+12)-factor)<1e-6,"AU bank restore lost pre-Master gain");
 unsigned otherVolumes=0;
 // Original volume definitions, independently recovered from the parameter table.
 for(unsigned tag:{4u,5u,6u,7u,132u,133u,312u,313u,314u,523u,524u,525u,526u,527u,528u}) {
   const auto p=x.run(0x1b16e,{0x1000000,tag}),q=y.run(0x1b16e,{0x1000000,tag});
   if(p && q && x.word(x.word(p+0x10))==5) {
     original.setEditorControl(tag,.6f);ported.setEditorControl(tag,.6f);
     check(x.word(p+12)==y.word(q+12),"An unrelated volume was boosted");++otherVolumes;
   }
 }
 check(otherVolumes>0,"No unrelated volume controls tested");
 // Fill a real WaveRAM2 sample parameter through its original string setter.
 U32 ctor=0,dtor=0;for(const auto& item:y.imports){if(item.second=="__ZNSsC1EPKcRKSaIcE")ctor=item.first;if(item.second=="__ZNSsD1Ev")dtor=item.first;}
 y.string(0x5d7000,std::filesystem::absolute(std::filesystem::path(argv[2])/"BT_cronox18.wav").string());
 y.run(ctor,{0x5d6800,0x5d7000,0});y.run(0x1b07a,{0x1000000,841,0x5d6800});y.run(dtor,{0x5d6800});
 ported.setEditorControl(769,1.f);auto state=ported.completeEditor(1);bool filename=false;
 for(unsigned i=0;i<state.count;++i)if(state.controls[i].value.tag==841){check(std::string(state.controls[i].value.text)=="BT_cronox18.wav","Sampler display differs from original printString/getLeaf");filename=true;}
 check(filename,"Original sample table unavailable");
 unsigned fonts=0;for(const auto& c:recoveredControls())if(cronox::typography::sampleFilename(c.tag)){check(cronox::typography::textSize(c)==10,"Original sample font differs");++fonts;}
 check(fonts==16,"Incomplete original sample-name columns");
 check(cronox::typography::hiddenMenuValue(610)&&cronox::typography::hiddenMenuValue(612),"Chord/ECS menu labels not suppressed");
 std::cout<<"{\"passed\":true,\"pre_master_signal_cases\":"<<cases<<",\"unaffected_other_volume_controls\":"<<otherVolumes<<",\"master_and_serialized_state_preserved\":true,\"original_sampler_filename\":true,\"sampler_font_fields\":"<<fonts<<",\"font_family\":\"Helvetica\",\"gain_conversions\":"<<y.masterGainConversions<<",\"macos_ui_executed\":false}\n";return 0;
 }catch(const std::exception& e){std::cerr<<e.what()<<"\n";return 1;}}
