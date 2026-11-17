import sys,struct,json,hashlib
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tests'))
from probe_au_render import RenderHost,Original,LegacyImage,ROOT
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EIP
class LayoutHost(RenderHost):
 def callback(self,pc):
  if self.names.get(pc)=='_GetDblTime':
   self.b.uc.reg_write(UC_X86_REG_EAX,30);self.b.ret();return
  try:return super().callback(pc)
  except Exception:
   print('Import failure',self.names.get(pc),hex(self.word(self.b.esp())),flush=True);raise
image=LegacyImage((ROOT/'reference/Sophistry.i386').read_bytes());b=Original(bytes(image.mapped()),0x4000000);h=LayoutHost(b,image)
editor=0x300000;vtable=0x6f0000;stub=0x6f1000;events=[];panels={};resources={};widgets={};selectors=[]
word=h.word;put=h.put
args=lambda n:struct.unpack('<'+'I'*n,b.read(b.esp()+4,n*4))
signed=lambda x:x if x<0x80000000 else x-0x100000000

def finish(value=0):b.uc.reg_write(UC_X86_REG_EAX,value&0xffffffff);b.ret()
def rectangle(p):return [signed(word(p+4*i)) for i in range(4)]
def panel_number(p):return (p-0x610000)//256 if p>=0x610000 and p<0x620000 else -1

def callback(pc):
 a=args(32);value=0
 if pc==0x2645a:
  value=0x640000+a[1]*32;resources[value]=a[1]
  png=ROOT/'reference/Resources'/('bmp%05d.png'%a[1]);width=height=0
  if png.exists():width,height=struct.unpack('>II',png.read_bytes()[16:24])
  put(value+12,width);put(value+16,height)
 elif pc==0x2713a:
  value=0x610000+a[1]*256;panels[a[1]]={'id':a[1],'x':a[2],'y':a[3],'image':resources.get(a[4],0)};put(value,vtable)
  put(editor+0x25858+4*a[1],value)
 elif pc==0x25e4e:value=0x610000+a[1]*256
 elif pc==stub:
  value=0 # NS/Carbon objects are represented by recording adapters.
 elif pc==stub+16:value=0
 elif pc==0x1d532:b.write(a[2],b'\0')
 elif pc in [0x25b40,0x274c4,0x599d2,0x25864,0x28716]:pass
 elif pc==0x80756:
  selectors.append({'tag':a[1],'parent':a[2],'children':[signed(i) for i in a[3:27] if i!=0xffffffff]})
 elif pc in [0x813ba,0x80bec,0x8a516,0x93004,0x7ea14,0x05f56]:
  value=a[0];put(value,vtable);widgets[value]={'kind':{0x813ba:'waveform',0x80bec:'scrollbar',0x8a516:'arpeggiator',0x93004:'keyboard',0x7ea14:'surround',0x05f56:'text'}[pc],'rect':rectangle(a[1]),'tag':a[3]};events.append({'pc':hex(pc),'panel':None,**widgets[value],'widget':value,'args':list(a[:16])})
 elif pc==0x25a06:
  tags=[word(a[2]+4*i) for i in range(a[3])];events.append({'pc':hex(pc),'kind':'attach','panel':panel_number(a[4]),'widget':a[1],'tags':tags})
 elif pc==0x266ca:events.append({'pc':hex(pc),'kind':'attach','panel':panel_number(a[3]),'widget':a[1],'tags':[a[2]]})
 elif pc==0x0b2b0:
  events.append({'pc':hex(pc),'kind':'value','tag':(a[0]-editor-0x54)//0x68,'rect':[signed(i) for i in a[1:5]]})
 elif pc==0x817c0:pass
 else:
  kinds={0x55b42:'dial',0x56e50:'step',0x26b74:'toggle',0x25926:'radio',0x2666e:'menu',0x54594:'slider',0x54f62:'horizontal-slider',0x26e1c:'menu-image',0x26a98:'button',0x25988:'edit',0x5984e:'label',0x55a08:'display',0x267f6:'file',0x268f0:'edit',0x26ff0:'thin-slider',0x54ca4:'xy',0x29272:'field',0x28e00:'licence'}
  if pc not in kinds:raise ValueError(hex(pc))
  event={'pc':hex(pc),'kind':kinds[pc],'panel':panel_number(a[12] if pc==0x26ff0 else a[2] if pc==0x55b42 else a[1]),'args':list(a[:16])}
  if pc==0x5984e:event['label']=h.string(a[3]).decode('mac_roman')
  events.append(event)
 finish(value)


def recover(output):
 hooks=[0x2645a,0x2713a,0x25e4e,stub,stub+16,0x1d532,0x25b40,0x274c4,0x599d2,0x25864,0x28716,0x80756,0x813ba,0x80bec,0x8a516,0x93004,0x7ea14,0x05f56,0x25a06,0x266ca,0x0b2b0,0x817c0,0x55b42,0x56e50,0x26b74,0x25926,0x2666e,0x54594,0x54f62,0x26e1c,0x26a98,0x25988,0x5984e,0x55a08,0x267f6,0x268f0,0x26ff0,0x54ca4,0x29272,0x28e00]
 for pc in hooks:b.hook(pc,callback)
 for i in range(0,0x180,4):put(vtable+i,stub+16)
 put(vtable+0x24,stub)
 # Synthetic editor storage; these adapters only replace OS widget creation.
 put(editor+0x4c,0x200000);put(editor+0x24,0x610000)
 b.run(0x55064,[editor,0x200000]);b.run(0x5efe2,[editor])
 styles=[]
 for i in range(19):styles.append(list(struct.unpack('<5I',b.read(0xf0ac0+i*20,20))))
 report={'original_image_sha256':hashlib.sha256((ROOT/'reference/Sophistry.i386').read_bytes()).hexdigest(),'original_functions':['0x55064','0x5efe2'],'scope':'Original i386 constructors with recording adapters for platform widgets; no synthesis or native Mac UI','panels':list(panels.values()),'selectors':selectors,'events':events,'styles':styles,'resource_fields':{hex(off):resources[word(editor+off)] for off in range(0x27800,0x279b4,4) if word(editor+off) in resources}}
 output.write_text(json.dumps(report,indent=2)+'\n');print(len(panels),'panels',len(events),'events',len(selectors),'selectors')

if __name__=='__main__':
 import argparse
 parser=argparse.ArgumentParser();parser.add_argument('output',type=Path);options=parser.parse_args();options.output.parent.mkdir(parents=True,exist_ok=True);recover(options.output)
