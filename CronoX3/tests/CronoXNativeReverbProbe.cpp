// Runs on the user's Mac before component installation. Effect-only fixtures
// never initialize a synth, import private preferences or render gated voices.
#include "CronoXNativeReverbHarness.cpp"
#include "CronoXReverbExpected.h"
#include <ctime>
unsigned checkOriginalLayouts(const char* preset,const char* samples) {
  LegacyEngineConfig c;c.audioUnitMode=true;c.nativeCronoXReverb=true;c.recycleFreedBlocks=true;
  c.collectDiagnostics=false;c.assetDirectories={samples};
  LegacyEngine engine(c);engine.initialize();
  std::ifstream f(preset,std::ios::binary);std::vector<std::uint8_t> data((std::istreambuf_iterator<char>(f)),{});
  if (data.size()<60) throw std::runtime_error("Missing public FXP fixture");
  engine.restoreChunk({data.begin()+60,data.end()},true);engine.setSampleRate(44100);engine.setBlockSize(256);engine.activate();
  auto types=engine.editorChoices(213);int reverb=-1;
  for(unsigned i=0;i<types.count;++i) {
    std::string name(types.labels[i].data());for(char& x:name)if(x>='A'&&x<='Z')x+=32;
    if(name.find("reverb")!=std::string::npos)reverb=int(i);
  }
  if(reverb<0 || types.count<2)throw std::runtime_error("Original effect selector has no reverb");
  for(unsigned slot=0;slot<6;++slot)engine.setEditorControl(213+slot,float(reverb)/(types.count-1));
  // No MIDI is sent and registration is untouched. One empty block lets the
  // original buffer scheduler set its span/offset, as in an actual host.
  std::array<std::array<float,256>,2> silence{};float* outputs[]={silence[0].data(),silence[1].data()};
  engine.process(outputs,2,256);
  auto& h=*engine.impl_;cronox::ReverbMemory m{h.cpu->memory,h.cpu->memory_size};
  unsigned found=0,prepared=0;
  for (U32 instance:{0u,1u}) for(U32 offset:{0x5dc0u,0xada8u,0xfd90u}) {
    const U32 at=0x1000000+0x3f5a90+instance*0x11c94+offset;
    const U32 vt=m.word(at);if(vt!=0x128908 && vt!=0x12a4c8)continue;
    ++found;cronox::NativeReverbPlan p;
    if (p.prepare(m,0xd400e,at,256)) ++prepared;
    else if(m.flag(at+0x168)) {
      std::cerr<<"Original reverb object "<<std::hex<<at<<" input "<<m.word(at+0x120)<<" output "<<m.word(at+0x128)<<std::dec<<" did not prepare\n";
      for (U32 b:{m.word(at+0x120),m.word(at+0x128)}) if(m.range(b,0x54)) {
        std::cerr<<"buffer cap/block/offset/channels "<<m.integer(b+0x18)<<' '<<m.integer(b+0x28)<<' '<<m.integer(b+0x30)<<' '<<m.integer(b+0x10)<<" flags ";
        for(U32 i=0x20;i<0x27;++i)std::cerr<<unsigned(m.data[b+i])<<' ';std::cerr<<'\n';
      }
    }
  }
  if(found!=3 || prepared!=3)throw std::runtime_error("Some real original reverb layouts were rejected by native preflight");
  engine.deactivate();engine.shutdown();return prepared;
}
int main(int argc,char** argv) {try {
  const bool baseline=argc>1 && std::string(argv[1])=="--baseline";
  std::unique_ptr<LegacyEngine::Impl> host(static_cast<LegacyEngine::Impl*>(cr_reverb_create(!baseline)));
  if (!host) throw std::runtime_error(cr_reverb_error());
  cronox::ReverbMemory m{host->cpu->memory,host->cpu->memory_size};
  unsigned blocks=0;double seconds=0;
  for (unsigned i=0;i<reverb_fixture::cases;++i) {
    const auto c=reverb_fixture::prepare(m,i);
    for (unsigned block=0;block<3;++block) {
      const auto begin=std::clock();
      if(cr_reverb_run(host.get(),c.entry,reverb_fixture::obj,c.frames,c.flush)) throw std::runtime_error(cr_reverb_error());
      seconds+=double(std::clock()-begin)/CLOCKS_PER_SEC;
      const auto actual=reverb_fixture::hash(m.data+reverb_fixture::base,reverb_fixture::size);
      if (actual!=reverb_fixture::expected[i][block]) {
        std::ostringstream s;s<<"Original-instruction state/output mismatch at case "<<i<<", block "<<block<<", actual "<<std::hex<<actual;
        throw std::runtime_error(s.str());
      }
      ++blocks;
    }
  }
  if (!baseline && (host->nativeReverbBlocks!=blocks || host->nativeReverbFallbacks))
    throw std::runtime_error("A confirmed original reverb case did not use the native path");
  // A disabled effect still takes the original wrapper, without calling DSP.
  const auto c=reverb_fixture::prepare(m,0);m.data[reverb_fixture::obj+0x168]=0;
  const std::vector<std::uint8_t> before(m.data+reverb_fixture::base,m.data+reverb_fixture::base+reverb_fixture::size);
  if (cr_reverb_run(host.get(),0xd42d8,reverb_fixture::obj,c.frames,0) ||
      std::memcmp(before.data(),m.data+reverb_fixture::base,before.size())) throw std::runtime_error("Disabled original effect fallback differs");
  if (!baseline && host->nativeReverbFallbacks!=1) throw std::runtime_error("Missing original fallback");
  const unsigned layouts=argc>2?checkOriginalLayouts(argv[1],argv[2]):0;
  std::cout<<"{\"passed\":true,\"original_instruction_fixture_cases\":"<<reverb_fixture::cases
    <<",\"blocks\":"<<blocks<<",\"all_state_and_output_hashes_equal_original\":true,\"native_path\":"<<(!baseline?"true":"false")
    <<",\"native_blocks\":"<<host->nativeReverbBlocks<<",\"fallback_cases\":1,\"render_cpu_seconds\":"<<seconds
    <<",\"original_initialized_layouts_accepted\":"<<layouts
    <<",\"effect_fixtures_do_not_enter_synth_or_license_gate\":true,\"whole_preset_audio_validated\":false}\n";
  return 0;
} catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}}
