import sys,struct,json
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tests'))
from probe_au_render import RenderHost,Original,LegacyImage,ROOT
image=LegacyImage((ROOT/'reference/Sophistry.i386').read_bytes());b=Original(bytes(image.mapped()),0x4000000);h=RenderHost(b,image);obj=0x200000;outer=obj-0xec
call=lambda pc,*a:(b.run(pc,list(a)),h.eax())[1]
for pc in image.initializers:call(pc)
call(0x48b0,outer,0x70001000)
for off,v in [(0,0xf2048),(8,0xf21a8),(0xe4,0xf21b4),(0xec,0xf2208)]:h.put(outer+off,v)
call(0xa6a2a,outer);call(0x2918,outer)
raw=(ROOT/'reference/Presets/lightgarden 02 BT.FXP').read_bytes()[60:];b.write(0x600000,raw);call(h.word(obj+0x24),obj+0x20,24,1,len(raw),0x600000,0)
table=h.word(obj+0x8abc);total=h.word(obj+0x9a48);rows=[];public=json.loads((ROOT/'analysis/au-parameter-contract.json').read_text())['parameter_ids']
for tag in range(total):
 if tag==765:continue
 b.write(0x5d2200,bytes(1024));call(0x1ce0e,obj,tag,0x5d2200);d=list(struct.unpack('<7I',b.read(0x5d2200,28)))
 b.write(0x5d2600,bytes(1024));call(0x1d640,obj,tag,0x5d2600);name=h.string(0x5d2600).decode('mac_roman')
 b.write(0x5d3000,bytes(4096));call(0x1d532,obj,tag,0x5d3000,127);text=h.string(0x5d3000).decode('mac_roman')
 desc=list(struct.unpack('<8I',b.read(table+tag*32,32)));aliases=[]
 for a in public:
  if list(struct.unpack('<8I',b.read(table+a*32,32)))[5:]==desc[5:]:aliases.append(a)
 labels=[];lo,hi=[x if x<0x80000000 else x-0x100000000 for x in d[1:3]]
 if d[0]==2 and d[4] and 0<=hi-lo<1024 and 0<d[5]<=128:
  labels=[b.read(d[4]+i*d[5],d[5]).split(b'\0',1)[0].decode('mac_roman') for i in range(hi-lo+1)]
 row={'tag':tag,'name':name,'kind':d[0],'minimum':lo,'maximum':hi,'default':d[3],'decimals':d[5],'curve':struct.unpack('<f',struct.pack('<I',d[6]))[0],'value':call(0x1d28c,obj,tag),'text':text,'aliases':aliases,'labels':labels};rows.append(row)
import argparse
parser=argparse.ArgumentParser();parser.add_argument('output',type=Path);options=parser.parse_args();options.output.parent.mkdir(parents=True,exist_ok=True);options.output.write_text(json.dumps(rows,indent=2)+'\n');print(len(rows),'original metadata records; protected registration parameter excluded')
