from pathlib import Path
import sys,struct,hashlib,json,random,re,time
ROOT=Path.cwd();sys.path.insert(0,str(ROOT/'tests'));from probe_au_render import Original,LegacyImage
from unicorn.x86_const import UC_X86_REG_EAX
b=Original(bytes(LegacyImage((ROOT/'reference/CronoX3.i386').read_bytes()).mapped()),0x4000000)
ctl=0x300000;white=0x640000;black=0x640100;vtable=0x6f0000;stub=0x6f1000
put=lambda p,n:b.write(p,struct.pack('<I',n&0xffffffff))
word=lambda p:struct.unpack('<I',b.read(p,4))[0]
rect=lambda p:tuple(struct.unpack('<4i',b.read(p,16)))
blits=[]
def record(pc):
 a=struct.unpack('<4I',b.read(b.esp()+4,16));r=rect(a[2]);x,y=struct.unpack('<2i',b.read(a[3],8));blits.append((382 if a[0]==white else 383,*r,x,y));b.uc.reg_write(UC_X86_REG_EAX,0);b.ret()
b.hook(stub,record);put(vtable+0x14,stub)
for p,w in [(white,60),(black,48)]:put(p,vtable);put(p+16,w);put(p+20,95)
b.write(ctl,bytes(0x900))
for off,n in [(16,648),(20,95),(0x4d4,5),(0x4d8,3),(0x4ec,white),(0x4f0,black),(0x4f4,18),(0x4f8,95),(0x4fc,10),(0x500,60),(0x504,13),(0x508,126)]:put(ctl+off,n)
cache={}
def draw(mask):
 if mask in cache:return cache[mask]
 global blits
 b.write(ctl+0xd0,struct.pack('<128I',*[100 if mask>>i&1 else 0 for i in range(128)]));blits=[];b.run(0xae772,[ctl,0]);cache[mask]=tuple(blits);return cache[mask]
neutral=draw(0);single=[draw(1<<n) for n in range(36,97)]
assert len(neutral)==72
rows=[]
for i,base in enumerate(neutral):
 deps=[n+36 for n,bl in enumerate(single) if bl[i]!=base];assert len(deps)<=2,(i,deps)
 sources=[]
 for m in range(4):
  bits=sum(1<<n for j,n in enumerate(deps) if m>>j&1);v=draw(bits)[i];assert v[:5]==base[:5] and v[6]==base[6];sources.append(v[5])
 rows.append(dict(image=base[0],rect=base[1:5],sourceY=base[6],notes=deps+[-1]*(2-len(deps)),sourceX=sources))
def composed(mask):return tuple((r['image'],*r['rect'],r['sourceX'][sum(1<<j for j,n in enumerate(r['notes']) if n>=0 and mask>>n&1)],r['sourceY']) for r in rows)
old=[tuple(map(int,m)) for m in re.findall(r'\{(38[23]),(-?\d+),(-?\d+),(-?\d+),(-?\d+),(-?\d+),(-?\d+)\}',(ROOT/'src/engine/RecoveredKeyboard.h').read_text())]
assert tuple(old[:72])==neutral
for n in range(61):assert tuple(old[(n+1)*72:(n+2)*72])==single[n]
start=time.monotonic();seed=0x3c9;randomMasks=[]
for _ in range(256):
 seed^=(seed<<13)&0xffffffffffffffff;seed^=seed>>7;seed^=(seed<<17)&0xffffffffffffffff;seed&=0xffffffffffffffff
 randomMasks.append((seed&((1<<61)-1))<<36)
cases=[m<<36 for m in range(4096)]+randomMasks+[((1<<61)-1)<<36,0]
aggregate=14695981039346656037
for i,mask in enumerate(cases):
 assert composed(mask)==draw(mask),i
 for blit in draw(mask):
  for word in blit:aggregate=((aggregate^(word&0xffffffff))*1099511628211)&0xffffffffffffffff
 if i%1024==0:print('original chord masks',i,flush=True)
head='''#pragma once
#include "RecoveredKeyboard.h"
#include <cstdint>
namespace sophistry {
// Captured original CKeyboard2::drawKeys (0xae772). Every slice depends
// on at most two adjacent notes; all four combinations were recorded.
struct KeyboardSlice {unsigned image;int left,top,right,bottom,first,second,sourceY;std::array<int,4> sourceX;};
inline const std::array<KeyboardSlice,72>& recoveredKeyboardSlices(){static const std::array<KeyboardSlice,72> rows={{
'''
for r in rows:head+=' {%d,%s,%d,%d,%d,{%s}},\n'%(r['image'],','.join(map(str,r['rect'])),*r['notes'],r['sourceY'],','.join(map(str,r['sourceX'])))
head+='''}};return rows;}
inline std::vector<KeyboardBlit> recoveredKeyboardChord(const std::array<std::uint8_t,128>& notes) {
 std::vector<KeyboardBlit> result;result.reserve(72);
 for(const auto& r:recoveredKeyboardSlices()) {
  unsigned state=(r.first>=0&&notes[r.first]?1:0)|(r.second>=0&&notes[r.second]?2:0);
  result.push_back({r.image,r.left,r.top,r.right,r.bottom,r.sourceX[state],r.sourceY});
 }
 return result;
}
} // namespace sophistry
'''
(ROOT/'src/engine/RecoveredKeyboardChords.h').write_text(head)
report={'checkpoint':'CRX009','original_i386_sha256':hashlib.sha256((ROOT/'reference/CronoX3.i386').read_bytes()).hexdigest(),'routine':'0xae772 CKeyboard2::drawKeys','slices':72,'old_single_note_states_compared':62,'all_adjacent_note_combinations_captured':True,'original_chord_masks_compared':len(cases),'all_blits_identical':True,'ordered_blit_u32_fnv64':format(aggregate,'016x'),'duration_seconds':time.monotonic()-start,'header_sha256':hashlib.sha256(head.encode()).hexdigest(),'macos_ui_executed':False}
(ROOT/'work/crx009/keyboard-recovery.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))
