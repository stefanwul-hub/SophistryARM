// Original-runtime regression. No private preferences, registration input or rendered licence bypass.
#include <algorithm>
#include <array>
#include <cmath>
#include <chrono>
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
#include "../src/engine/RecoveredKeyboardChords.h"
#include "../src/au/CronoXPresetCatalog.h"
using namespace sophistry;
void require(bool b,const char* message){if(!b)throw std::runtime_error(message);}
int main(int argc,char** argv){try{
 require(argc==2,"Expected temporary preset catalog fixture");
 namespace fs=std::filesystem;const fs::path root=argv[1];
 auto banks=cronox::catalog::banks(root);require(banks.size()==3,"Original bank directory filtering differs");
 require(banks[0].filename()=="Bank A"&&banks[1].filename()=="Bank B"&&banks[2].filename()=="Empty","Original bank order differs");
 auto sounds=cronox::catalog::presets(banks[0]);require(sounds.size()==3,"Original file filtering or AU compatibility differs");
 require(sounds[0].filename()=="01 first.FXP"&&sounds[1].filename()=="10 tenth.fxp"&&sounds[2].filename()=="2 second.aupreset","Original lexical preset ordering differs");
 require(cronox::catalog::presets(banks[1]).size()==1,"Selected-bank presets leak between banks");
 require(cronox::catalog::label(sounds[0])=="01 first","Original extension-stripped label differs");
 require(cronox::catalog::root({},root/"Samples",banks[0]/"01 first.FXP")==root,"Preset root inference differs");
 std::uint64_t hash=14695981039346656037ULL;unsigned masks=0;
 auto append=[&](std::uint64_t mask){std::array<std::uint8_t,128> notes{};for(unsigned n=0;n<61;++n)if(mask>>n&1)notes[n+36]=100;
   for(const auto& b:recoveredKeyboardChord(notes))for(int v:{int(b.image),b.left,b.top,b.right,b.bottom,b.sourceX,b.sourceY}){hash^=std::uint32_t(v);hash*=1099511628211ULL;}++masks;
 };
 for(unsigned m=0;m<4096;++m)append(m);
 std::uint64_t seed=0x3c9;for(unsigned i=0;i<256;++i){seed^=seed<<13;seed^=seed>>7;seed^=seed<<17;append(seed&((1ULL<<61)-1));}
 append((1ULL<<61)-1);append(0);
 require(hash==0xdaac17be44d82b53ULL,"Native chord rendering differs from captured original routine");
 LegacyEngineConfig cfg;cfg.audioUnitMode=true;LegacyEngine e(cfg);e.initialize();auto& h=*e.impl_;
 const auto before=e.editorKeyboardState();for(auto v:before.velocity)require(!v,"Unexpected startup key");
 constexpr U32 manager=0x1000000+0x3880,fixture=0x5c8000;
 const U32 oldTable=h.word(manager+8),oldCount=h.word(manager+12);h.zero(fixture,4*36);
 h.put(fixture,U32(1));h.put(fixture+12,U32(60));h.put(fixture+16,U32(100));
 h.put(fixture+36,U32(1));h.put(fixture+48,U32(64));h.put(fixture+52,U32(80));
 h.put(fixture+72,U32(2));h.put(fixture+84,U32(67));h.put(fixture+88,U32(127));
 h.put(fixture+108,U32(1));h.put(fixture+120,U32(64));h.put(fixture+124,U32(110));
 h.put(manager+8,fixture);h.put(manager+12,U32(4));auto pressed=e.editorKeyboardState();
 h.put(manager+8,oldTable);h.put(manager+12,oldCount);
 require(pressed.velocity[60]==100&&pressed.velocity[64]==110&&!pressed.velocity[67],"Original held/released note states differ");
 require(e.editorKeyboardState().velocity==before.velocity,"Keyboard display mutated original manager");e.shutdown();
 std::cout<<"{\"passed\":true,\"original_keyboard_chord_masks\":"<<masks<<",\"original_capture_hash_matches\":true,\"original_manager_notes_read_only\":true,\"released_notes_up\":true,\"original_bank_filter_order_and_labels\":true,\"selected_bank_isolated\":true,\"macos_ui_executed\":false}\n";return 0;
}catch(const std::exception& error){std::cerr<<error.what()<<"\n";return 1;}}
