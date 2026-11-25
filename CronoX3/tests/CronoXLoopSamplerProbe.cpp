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
using namespace sophistry;
#ifdef __APPLE__
constexpr bool macosHost=true;
#else
constexpr bool macosHost=false;
#endif
void require(bool ok,const char* message){if(!ok)throw std::runtime_error(message);}
int main(int argc,char** argv){try{
 require(argc==3,"Expected public FXP and sample directory");
 LegacyEngineConfig cfg;cfg.audioUnitMode=true;cfg.recycleFreedBlocks=true;cfg.collectDiagnostics=false;cfg.assetDirectories={argv[2]};
 LegacyEngine e(cfg);e.initialize();e.setSampleRate(44100);e.setBlockSize(256);e.activate();std::ifstream input(argv[1],std::ios::binary);std::vector<unsigned char> fxp((std::istreambuf_iterator<char>(input)),{});require(fxp.size()>60,"Missing fixture");
 e.restoreChunk({fxp.begin()+60,fxp.end()},true);e.setEditorControl(769,1.f);
 e.setEditorString(807,std::filesystem::absolute(std::filesystem::path(argv[2])/"BT_cronox18.wav").string());
 auto& h=*e.impl_;(void)e.completeEditor(1);h.drawings.erase(8);h.envelopes.erase(8);auto saved=e.saveBank();unsigned boundaries=0;
 const auto native=e.editorDrawing(8,[&]{++boundaries;(void)e.auParameter(134);});
 require(native.sourceFrames>100000&&native.count>0,"Missing public Loop Sampler waveform");
 require(saved==e.saveBank(),"Wave drawing changed the program");
 const auto cache=h.envelopes.at(8);const auto view=h.drawings.at(8);unsigned columns=0;
 float first=float(native.sampleRate)*view.first,last=float(native.sourceFrames)-1.f;
 const float step=view.span/float(native.width);
 if(first<last)for(unsigned x=0;x<native.width;++x) {
   const float next=first+float(native.sampleRate)*step;
   h.run(0x9c8c4,{0x5b0000,x,bits32(first),bits32(std::min(next,last))});
   require(h.word(0x5b1000+x*4)==bits32(cache.columns[x][0])&&h.word(0x5b2000+x*4)==bits32(cache.columns[x][1]),"Native extrema differ from original getMaxMin");
   ++columns;if(next>=last)break;first=next;
 }
 EditorDrawing reference=native;reference.count=0;h.activeDrawing=&reference;
 auto baselineStart=std::chrono::steady_clock::now();
 h.run(0x9d83c,{0x5b0000,0x5b0200,0x5b0300,bits32(view.first),bits32(view.span)});
 h.run(0x9cbb6,{0x5b0000,0x5b0200,bits32(view.first),bits32(view.span)});h.activeDrawing=nullptr;
 const double originalMilliseconds=std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-baselineStart).count();
 require(!std::memcmp(&reference,&native,sizeof(native)),"Wave paths/markers differ from original drawSample + drawLoopPoints");
 auto markers=[](const EditorDrawing& drawing,unsigned color){unsigned count=0;for(unsigned i=0;i<drawing.count;++i){auto l=drawing.lines[i];if(l.color==color&&l.x1==l.x2&&l.y1==3&&l.y2==91)++count;}return count;};
 require(markers(native,0xff0040ff)>0&&markers(native,0xff4000a0)>0,"Original loop start/end lines missing");
 const auto count=h.waveformEnvelopeBuilds;
 const auto before=h.run(0x1ade8,{0x1000000,817});
 e.setEditorString(955,"30000");const auto edited=h.run(0x1ade8,{0x1000000,817});
 require(edited!=before&&edited>7882&&edited<49580,"Loop S numeric edit was ignored");
 e.setEditorString(957,"150000");require(h.run(0x1ade8,{0x1000000,819})>100000,"Loop E numeric edit was ignored");
 e.setEditorControl(817,.25f);const auto moved=e.completeEditor(1);bool display=false;
 for(unsigned i=0;i<moved.count;++i)if(moved.controls[i].value.tag==955){require(moved.controls[i].value.value==int(h.run(0x1ade8,{0x1000000,817})),"Numeric loop alias not refreshed after graphical edit");display=true;}
 require(display,"Loop S numeric display unavailable");
 (void)e.editorDrawing(8);require(h.waveformEnvelopeBuilds==count,"Moving markers rescanned the sample");
 auto stable=e.editorDrawing(8);e.setEditorControl(134,.5f);auto volume=e.editorDrawing(8);
 require(!std::memcmp(&stable,&volume,sizeof(stable))&&h.waveformEnvelopeBuilds==count,"Unrelated parameter invalidates waveform");
 unsigned fidelityViews=1;
 for(const auto& settings:std::array<std::array<float,2>,3>{{{0,0},{.4f,.5f},{1,1}}}) {
   e.setEditorControl(943,settings[0]);e.setEditorControl(945,settings[1]);
   auto actual=e.editorDrawing(8);auto expected=actual;expected.count=0;const auto v=h.drawings.at(8);
   h.activeDrawing=&expected;h.run(0x9d83c,{0x5b0000,0x5b0200,0x5b0300,bits32(v.first),bits32(v.span)});
   h.run(0x9cbb6,{0x5b0000,0x5b0200,bits32(v.first),bits32(v.span)});h.activeDrawing=nullptr;
   require(!std::memcmp(&actual,&expected,sizeof(actual)),"Zoom/scroll drawing differs from original");++fidelityViews;
 }
 const auto countBeforeZoom=h.waveformEnvelopeBuilds;
 std::vector<float> left(256),right(256);float* outputs[]={left.data(),right.data()};
 unsigned renderBoundaries=0;double maxSectionMs=0;auto section=std::chrono::steady_clock::now();
 e.setEditorControl(943,.3f);
 auto updated=e.editorDrawing(8,[&]{
   auto now=std::chrono::steady_clock::now();maxSectionMs=std::max(maxSectionMs,std::chrono::duration<double,std::milli>(now-section).count());
   e.process(outputs,2,256);for(float v:left)require(std::isfinite(v),"Non-finite interleaved audio");++renderBoundaries;section=std::chrono::steady_clock::now();
 });
 maxSectionMs=std::max(maxSectionMs,std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-section).count());
 require(updated.count>0&&renderBoundaries>0&&h.waveformEnvelopeBuilds==countBeforeZoom+1,"Zoom preview did not yield for audio");
 require(cronoxLoop::hit(.25f,30,{.1f,.25f,.6f})==1&&cronoxLoop::hit(.6f,30,{.1f,.25f,.6f})==2&&cronoxLoop::hit(.4f,5,{.1f,.25f,.6f})==3,"Original marker hit rules differ");
 require(cronoxLoop::parameter(0,1)==817&&cronoxLoop::parameter(1,2)==820,"Wrong graphical loop parameter mapping");
 require(cronoxLoop::drag(0,10,10,25,100,1,.2f)==.25f,"Original viewport drag mapping differs");
 e.deactivate();e.restoreChunk(saved,false);e.shutdown();
 std::cout<<"{\"passed\":true,\"original_extrema_columns_bit_equal\":"<<columns<<",\"original_zoom_scroll_views\":"<<fidelityViews<<",\"complete_original_wave_paths_bit_equal\":true,\"loop_start_end_markers\":true,\"numeric_and_graphical_edits\":true,\"marker_edits_reuse_sample_envelope\":true,\"waveform_safe_boundaries\":"<<boundaries<<",\"rendered_at_zoom_boundaries\":"<<renderBoundaries<<",\"original_full_wave_replay_ms\":"<<originalMilliseconds<<",\"largest_zoom_read_section_ms\":"<<maxSectionMs<<",\"timings_are_machine_local\":true,\"macos_host\":"<<(macosHost?"true":"false")<<",\"macos_ui_executed\":false}\n";return 0;
}catch(const std::exception& error){std::cerr<<error.what()<<"\n";return 1;}}
