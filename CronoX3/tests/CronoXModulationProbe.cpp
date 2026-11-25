#include "../src/engine/LegacyEngine.h"
#include "../src/engine/RecoveredModulation.h"
#include <iostream>
#include <stdexcept>
using namespace cronox::modulation;
struct Hash {
  std::uint64_t value=14695981039346656037ULL;
  void byte(unsigned v){value^=v&255;value*=1099511628211ULL;}
  void word(unsigned v){for(unsigned i=0;i<4;++i)byte(v>>(8*i));}
  void text(const std::string& s){for(unsigned char c:s)byte(c);byte(0);}
};
void require(bool b,const char* text){if(!b)throw std::runtime_error(text);}
int main(){try {
  sophistry::LegacyEngineConfig config;config.audioUnitMode=true;config.collectDiagnostics=false;
  sophistry::LegacyEngine engine(config);engine.initialize();const auto saved=engine.saveProgram();
  unsigned categories=0,leaves=0;
  for(unsigned tag=670;tag<=679;++tag) {
    auto choices=engine.editorChoices(tag);require(choices.count==58,"Missing original destinations");
    std::vector<std::string> labels;for(unsigned i=0;i<choices.count;++i)labels.emplace_back(choices.labels[i].data());
    auto groups=menu(labels);Hash hash;unsigned total=0,count=0;
    for(const auto& group:groups) {
      hash.text(group.text);hash.word(unsigned(group.children.size()));
      if(group.children.empty()){hash.text(group.text);hash.word(group.first);++total;}
      else {++count;for(const auto& child:group.children){hash.text(child.text);hash.word(child.value-group.first);++total;require(child.text.find('$')==std::string::npos,"Internal marker visible");}}
    }
    require(hash.value==0xcfd70229ae74d452ULL,"Menu labels, categories or value mapping differ from original machine capture");
    require(groups.size()==17&&count==16&&total==58,"Menu destinations lost");categories+=count;leaves+=total;
  }
  Hash hash;unsigned cases=0;
  for(unsigned length:{1u,8u,16u,32u,128u})for(unsigned current=0;current<=128;++current) {
    if(current>32&&current<126)continue;
    std::array<std::uint8_t,258> sequence{};sequence[0]=current+1;sequence[1]=length+1;
    for(unsigned i=0;i<128;++i){sequence[2+2*i]=61;sequence[3+2*i]=std::array<unsigned,6>{1,129,2,128,81,101}[i%6];}
    hash.word(length);hash.word(current);
    for(const auto& cell:arpeggiator(sequence.data())) {
      hash.word(0);for(int v:{cell.x,cell.y,cell.x+8,cell.y+12,0,cell.sourceY})hash.word(v);
      hash.word(1);hash.text(cell.text.data());for(int v:{cell.x+8,cell.y,cell.x+39,cell.y+13})hash.word(v);hash.word(cell.color);
    }
    ++cases;
  }
  require(hash.value==0x846b5a5e40732608ULL,"Arpeggiator drawing differs from original machine capture");
  require(engine.saveProgram()==saved,"UI reads changed original program");
  for(unsigned i=0;i<32;++i)require(step(16+int(i/8)*56,int(i%8)*13)==i,"Original column-major hit order differs");
  std::cout<<"{\"passed\":true,\"original_menus\":10,\"original_categories\":"<<categories<<",\"original_destinations\":"<<leaves<<",\"original_arp_frames\":"<<cases<<",\"original_draw_operations\":"<<cases*64<<",\"all_capture_hashes_identical\":true,\"program_unchanged_by_ui_reads\":true,\"macos_ui_executed\":false}\n";return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<"\n";return 1;}}
