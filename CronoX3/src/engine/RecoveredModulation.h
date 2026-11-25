#pragma once
#include <array>
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>
namespace cronox::modulation {
inline bool destination(unsigned tag) { return tag>=670 && tag<=679; }
// Original CMenuSimple::addItemShift (0x9350): remove trailing spaces,
// replace the first internal category delimiter with a space.
inline std::string menuText(std::string text) {
  while(!text.empty() && text.back()==' ')text.pop_back();
  auto at=text.find('$');if(at!=std::string::npos)text[at]=' ';
  return text;
}
struct Choice {std::string text;unsigned value;};
struct Group {std::string text;std::vector<Choice> children;unsigned first;};
inline std::vector<Group> menu(const std::vector<std::string>& labels) {
  std::vector<Group> result;
  for(unsigned i=0;i<labels.size();) {
    auto split=labels[i].find('$');unsigned end=i+1;
    // CMenuWithSub::nextIsSame 0x91f2 compares the current prefix with
    // the following entry; categories contain adjacent entries only.
    if(split!=std::string::npos && split>0)
      while(end<labels.size() && labels[end-1].find('$')!=std::string::npos &&
            labels[end].compare(0,labels[end-1].find('$'),labels[end-1],0,labels[end-1].find('$'))==0)++end;
    Group group{end>i+1?labels[i].substr(0,split):menuText(labels[i]),{},i};
    if(end>i+1)for(unsigned j=i;j<end;++j)group.children.push_back({menuText(labels[j]),j});
    result.push_back(std::move(group));i=end;
  }
  return result;
}
struct StepCell {
  int x=0,y=0,sourceY=0;
  std::array<char,4> text{};
  std::uint32_t color=0;
};
// createArpEdits 0x77786 / CStepSeqPl::draw 0xa62f2: four columns of
// eight velocity/Off/Tie values, each preceded by original bitmap 306.
inline std::array<StepCell,32> arpeggiator(const std::uint8_t* sequence) {
  std::array<StepCell,32> out{};
  for(unsigned i=0;i<32;++i) {
    auto& cell=out[i];cell.x=16+int(i/8)*56;cell.y=int(i%8)*13;
    cell.sourceY=int(sequence[0])-1==int(i)?0:12;
    cell.color=int(i)<int(sequence[1])-1?0xffd2d2d2u:0xff696969u;
    unsigned value=sequence[3+2*i];
    if(value==1)cell.text={'O','f','f',0};
    else if(value==129)cell.text={'T','i','e',0};
    else std::snprintf(cell.text.data(),cell.text.size(),"%03u",(value-1)&255);
  }
  return out;
}
inline unsigned step(int x,int y) {return unsigned(std::clamp(x/56,0,3)*8+std::clamp(y/13,0,7));}
} // namespace cronox::modulation
