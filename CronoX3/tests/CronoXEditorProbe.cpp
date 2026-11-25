// Native engine regression for the original CronoX UI bindings, without private preferences.
#include "../src/engine/LegacyEngine.h"
#include <fstream>
#include <filesystem>
#include <iostream>
#include <set>
#include <cstring>
#include <stdexcept>
using namespace sophistry;
void check(bool b,const char* m){if(!b)throw std::runtime_error(m);}
int main(int argc,char** argv){try{
 check(argc==3,"Expected public FXP and sample folder");
 LegacyEngineConfig cfg;cfg.audioUnitMode=true;cfg.recycleFreedBlocks=true;cfg.assetDirectories={argv[2]};cfg.collectDiagnostics=false;
 LegacyEngine e(cfg);e.initialize();std::ifstream f(argv[1],std::ios::binary);std::vector<unsigned char> fxp((std::istreambuf_iterator<char>(f)),{});check(fxp.size()>60,"Missing fixture");e.restoreChunk({fxp.begin()+60,fxp.end()},true);
 unsigned pages=0,boundaries=0,choices=0,drawings=0;std::set<unsigned> seen;
 auto inspect=[&](unsigned page){auto saved=e.saveProgram();auto s=e.completeEditor(page,[&]{++boundaries;(void)e.auParameter(134);});check(s.count>0,"Empty original page");for(unsigned i=0;i<s.count;++i){const auto& c=s.controls[i];check(c.value.tag!=766,"Serial exposed");check(std::isfinite(c.normalized),"Invalid normalized control");seen.insert(c.value.tag);if(c.value.kind==2||c.value.kind==6){auto v=e.editorChoices(c.value.tag);check(v.count==unsigned(c.value.maximum-c.value.minimum+1),"Missing original labels");++choices;}}check(saved==e.saveProgram(),"UI read changed saved program");++pages;std::cerr<<"page "<<page<<" controls "<<s.count<<"\n";};
 for(unsigned page=0;page<10;++page)inspect(page);
 for(unsigned g=0;g<4;++g)for(unsigned mode=0;mode<(g<2?4u:3u);++mode){e.setEditorControl(generatorTypeTag(g),float(mode)/(g<2?3:2));inspect(g<2?1:2);}
 for(unsigned slot=0;slot<6;++slot)for(unsigned type=0;type<12;++type){e.setEditorControl(213+slot,float(type)/11);inspect(4);}
 for(unsigned i=0;i<4;++i){e.setEditorControl(606,float(i)/3);inspect(5);}
 for(unsigned i=0;i<5;++i){e.setEditorControl(605,float(i)/4);inspect(5);}
 for(unsigned i=0;i<2;++i){e.setEditorControl(783+i,1);inspect(3);e.setEditorControl(783+i,0);}
 for(unsigned i=0;i<8;++i){auto d=e.editorDrawing(i);check(d.count>0,"Missing XY drawing");++drawings;}
 for(unsigned x: {0u,11u,50u,321u,647u}){auto k=e.editorKeyHit(x,40);check(k.note<=127&&k.velocity>=1&&k.velocity<=127,"Invalid keyboard hit");}
 for(const auto& c:recoveredControls())if(c.kind==RecoveredWidget::Drawbar){auto high=e.editorKnob(c.key,0,0),low=e.editorKnob(c.key,0,c.height);check(high>low,"Envelope fader direction reversed");}
 // Exercise actual edits and special controls, then restore the fixture.
 unsigned edits=0;
 auto original=e.saveProgram();
 for(unsigned tag:{8u,114u,482u,614u,961u,680u}) {
   e.setEditorControl(tag,.73f);++edits;
 }
 e.setEditorString(680,"0.125");++edits;
 for(unsigned tag:{420u,423u,648u}) {
   auto value=e.editorString(tag);check(!value.empty(),"Missing original sequence");
   auto changed=value;if(tag!=648)changed[0]=changed[0]=='1'?'0':'1';
   e.setEditorString(tag,changed);check(e.editorString(tag)==changed,"Sequence edit did not round trip");
   e.setEditorString(tag,value);++edits;
 }
 for(unsigned g=0;g<2;++g) {
   e.setEditorControl(generatorTypeTag(g),1.f);
   e.setEditorString(807+g,std::filesystem::absolute(std::filesystem::path(argv[2])/"BT_cronox18.wav").string());
   auto saved=e.saveProgram();auto a=e.editorDrawing(8+g),b=e.editorDrawing(8+g);
   check(a.sourceFrames>0&&a.count>0,"Original waveform unavailable");
   check(!std::memcmp(&a,&b,sizeof(a)),"Waveform cache changed drawing");
   check(saved==e.saveProgram(),"Drawing changed saved program");++drawings;
 }
 for(const auto& c:recoveredControls())if(c.kind==RecoveredWidget::Action && (c.extra[0]==92||c.extra[0]==93)){e.editorAction(c.key);++edits;}
 for(unsigned tag:{643u,644u,645u,646u,647u,610u}) {
   auto saved=e.saveProgram();
   for(unsigned op:tag==610?std::vector<unsigned>{4,5}:std::vector<unsigned>{0,1}) {
     auto info=e.editorFileInfo(tag,op);check(info.count>0,"Original file chooser metadata unavailable");
   }
   check(saved==e.saveProgram(),"File information query changed preset");
 }
 e.setEditorString(953,"32");++edits;
 e.restoreChunk(original,true);
 check(!completeControlReadable(766)&&!completeControlEditable(766)&&!completeControlStringEditable(766),"Serial control exposed");
 std::cout<<"{\"passed\":true,\"pages_and_modes\":"<<pages<<",\"unique_tags\":"<<seen.size()<<",\"choice_reads\":"<<choices<<",\"safe_boundaries\":"<<boundaries<<",\"original_drawings\":"<<drawings<<",\"edit_cases\":"<<edits<<",\"program_unchanged_by_ui_reads\":true,\"macos_ui_executed\":false}\n";return 0;
 }catch(const std::exception& x){std::cerr<<"Editor probe: "<<x.what()<<"\n";return 1;}}
