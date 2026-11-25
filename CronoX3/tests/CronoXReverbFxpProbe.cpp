// RV001 rejected even this real fixture: version@12 was compared to AU CrX3.
// This test calls the same header parser compiled into the RV002 Mac host.
#include "../diagnostics/reverb-RV002/CronoXFxpHeader.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
using namespace cronox::probe;
void check(bool b,const char* why){if(!b)throw std::runtime_error(why);}
void put(std::vector<unsigned char>& v,unsigned at,std::uint32_t n){for(int i=0;i<4;++i)v[at+i]=static_cast<unsigned char>(n>>(24-8*i));}
int main(int argc,char** argv){try{
  check(argc==2,"Expected the real reference FXP");std::ifstream input(argv[1],std::ios::binary);
  std::vector<unsigned char> real((std::istreambuf_iterator<char>(input)),{});
  auto h=inspectFxp(real.data(),real.size());
  check(real.size()==20700&&h.version==1&&h.fileID==0x43727833&&h.payloadBytes==20640&&h.programCount==1,"Reference FXP fields differ");
  check(fourCC(h.fileID)=="Crx3"&&h.payloadOffset==60,"VST ID or payload offset differs");
  check(big32(real.data()+12)!=0x43725833,"Fixture must reproduce RV001's version-versus-AU-ID rejection");
  constexpr char name[]="BT_lightgarden_02";
  check(!std::memcmp(real.data()+28,name,sizeof(name)), "Reference preset name differs");
  unsigned rejected=0;
  auto reject=[&](const void* p,std::size_t n){bool thrown=false;try{inspectFxp(p,n);}catch(const std::runtime_error&){thrown=true;}check(thrown,"Malformed FXP accepted");++rejected;};
  for(unsigned n=0;n<60;++n)reject(real.data(),n);
  reject(nullptr,60);
  auto v=real;v[0]='?';reject(v.data(),v.size());
  v=real;v[8]='?';reject(v.data(),v.size());
  v=real;put(v,56,h.payloadBytes-1);reject(v.data(),v.size());
  v=real;v.pop_back();reject(v.data(),v.size());
  v=real;put(v,56,0);v.resize(60);reject(v.data(),v.size());
  v=real;v.resize(60+1048576);put(v,56,1048576);check(inspectFxp(v.data(),v.size()).payloadBytes==1048576,"Import limit boundary rejected");
  v.push_back(0);put(v,56,1048577);reject(v.data(),v.size());
  // File version, VST ID, plug-in version and program count are separate fields.
  // Match CRX011's structural import; the engine interprets the opaque content.
  v=real;put(v,12,2);put(v,16,0x536f7033);put(v,20,0x30606);put(v,24,1);
  h=inspectFxp(v.data(),v.size());check(h.version==2&&fourCC(h.fileID)=="Sop3"&&h.pluginVersion==0x30606&&h.programCount==1,"FXP metadata fields overlap");
  v=real;put(v,4,std::uint32_t(v.size()-8));check(inspectFxp(v.data(),v.size()).payloadBytes==20640,"Nonzero standard byteSize rejected");
  check(fourCC(0)=="0x00000000","Nonprintable identifier not safely formatted");
  std::cout<<"{\"passed\":true,\"real_reference_fxp_loaded\":true,\"rv001_failure_reproduced\":true,\"version_offset\":12,\"vst_id_offset\":16,\"reference_vst_id\":\"Crx3\",\"reference_payload_bytes\":20640,\"malformed_or_truncated_inputs_rejected\":"<<rejected<<",\"engine_audio_or_macos_executed\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}}
