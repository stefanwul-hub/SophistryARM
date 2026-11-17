from constructor_trace import *
import argparse
parser=argparse.ArgumentParser();parser.add_argument('output',type=Path);options=parser.parse_args();dest=options.output;dest.mkdir(parents=True,exist_ok=True)
blits=[];bitmap_vtable=0x6f2000;bitmap_stub=0x6f2100

def draw(pc):
 a=args(4);rect=rectangle(a[2]);source=[signed(word(a[3])),signed(word(a[3]+4))];im=resources.get(a[0],0)
 blits.append([im,*rect,*source]);finish()
b.hook(bitmap_stub,draw);put(bitmap_vtable+16,bitmap_stub)
for im in [382,383]:
 ptr=0x640000+im*32;resources[ptr]=im;put(ptr,bitmap_vtable);put(ptr+12,60 if im==382 else 48);put(ptr+16,95)
widget=h.alloc(0x4e4);rect=0x5f0000
b.write(rect,struct.pack('<4I',0,0,648,95))
b.run(0x93004,[widget,rect,0,608,0x640000+382*32,0x640000+383*32,0x200000,18,95,10,60,13])
all=[]
for note in [-1]+list(range(36,97)):
 if note>=0:b.run(0x948f2,[widget,note,100])
 blits=[];b.run(0x93174,[widget,0]);all.append({'note':note,'blits':blits})
 if note>=0:b.run(0x948f2,[widget,note,0])
(dest/'keyboard-layout.json').write_text(json.dumps(all,indent=2)+'\n')
print(len(all),'keyboard states',len(all[0]['blits']),'blits per state')
header='''#pragma once
#include <array>
#include <vector>
namespace sophistry {
struct KeyboardBlit {unsigned image;int left,top,right,bottom,sourceX,sourceY;};
inline const std::vector<KeyboardBlit>& recoveredKeyboard(unsigned state){
 static const std::array<std::vector<KeyboardBlit>,62> v={{\n'''
for a in all:
 header+=' {'+','.join('{'+','.join(map(str,b))+'}' for b in a['blits'])+'},\n'
header+='}};return v[state<62?state:0];}\n} // namespace sophistry\n'
(dest/'RecoveredKeyboard.h').write_text(header)
