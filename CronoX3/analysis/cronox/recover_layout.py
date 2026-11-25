# Execute the original CronoX 3.6.6 i386 editor constructors.
# Platform widgets are recording adapters; knob styles come from the executing original table.
import sys,struct,json,hashlib
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tests'))
from probe_au_render import RenderHost,Original,LegacyImage,ROOT
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EIP,UC_X86_REG_EBP
class LayoutHost(RenderHost):
 def __init__(self,backend,image):
  hook=backend.uc.hook_add
  def isolated(*args,**kwargs):
   if kwargs.get('begin')==0x103000 and kwargs.get('end')==0x1037e3:return 0
   return hook(*args,**kwargs)
  backend.uc.hook_add=isolated
  try:super().__init__(backend,image)
  finally:backend.uc.hook_add=hook
 def callback(self,pc):
  if self.names.get(pc)=='_GetDblTime':
   self.b.uc.reg_write(UC_X86_REG_EAX,30);self.b.ret();return
  name=self.names.get(pc,"")
  sp=self.b.esp();a=lambda n:self.word(sp+4+n*4)
  if name.startswith(("__ZNSs","__ZNKSs","__ZNSaIcE")):
   if name in ["__ZNSaIcEC1Ev","__ZNSaIcED1Ev","__ZNSsD1Ev"]:self.b.ret();return
   if name=="__ZNSsC1EPKcRKSaIcE":text=self.string(a(1))
   elif name=="__ZNSsC1ERKSs":text=self.string(self.word(a(1)))
   elif name in ["__ZNSsC1Ev","__ZNSs5clearEv"]:text=b""
   elif name=="__ZNSsaSERKSs":text=self.string(self.word(a(1)))
   elif name in ["__ZNSsaSEPKc","__ZNSs6assignEPKc"]:text=self.string(a(1))
   elif name=="__ZNKSs7compareERKSs":
    left=self.string(self.word(a(0)));right=self.string(self.word(a(1)));self.b.uc.reg_write(UC_X86_REG_EAX,((left>right)-(left<right))&0xffffffff);self.b.ret();return
   elif name=="__ZNKSs5c_strEv":self.b.uc.reg_write(UC_X86_REG_EAX,self.word(a(0)));self.b.ret();return
   elif name in ["__ZNKSs4sizeEv","__ZNKSs6lengthEv"]:self.b.uc.reg_write(UC_X86_REG_EAX,len(self.string(self.word(a(0)))));self.b.ret();return
   elif name=="__ZNKSs17find_first_not_ofEcm":
    value=self.string(self.word(a(0)));start=a(2);at=next((i for i in range(start,len(value)) if value[i]!=a(1)),0xffffffff);self.b.uc.reg_write(UC_X86_REG_EAX,at);self.b.ret();return
   elif name=="__ZNKSs13find_first_ofEcm":
    value=self.string(self.word(a(0)));pos=value.find(bytes([a(1)]),a(2));self.b.uc.reg_write(UC_X86_REG_EAX,pos&0xffffffff);self.b.ret();return
   elif name=="__ZNKSs12find_last_ofEcm":
    value=self.string(self.word(a(0)));pos=value.rfind(bytes([a(1)]),0,min(a(2)+1,len(value)));self.b.uc.reg_write(UC_X86_REG_EAX,pos&0xffffffff);self.b.ret();return
   elif name=="__ZNKSs6substrEmm":
    value=self.string(self.word(a(1)));text=value[a(2):][:a(3)];ptr=self.alloc(len(text)+13);self.put(ptr,len(text));self.put(ptr+4,len(text));self.put(ptr+8,0);self.b.write(ptr+12,text+b"\0");self.put(a(0),ptr+12);self.b.ret();self.b.setesp(self.b.esp()+4);return
   else:raise RuntimeError("Layout string import "+name)
   ptr=self.alloc(len(text)+13);self.put(ptr,len(text));self.put(ptr+4,len(text));self.put(ptr+8,0);self.b.write(ptr+12,text+b"\0");self.put(a(0),ptr+12);self.b.uc.reg_write(UC_X86_REG_EAX,a(0));self.b.ret();return
  try:return super().callback(pc)
  except Exception:
   print('Import failure',self.names.get(pc),hex(self.word(self.b.esp())),flush=True);raise
image=LegacyImage((ROOT/'reference/CronoX3.i386').read_bytes());b=Original(bytes(image.mapped()),0x4000000);h=LayoutHost(b,image)
for imported in image.stubs:b.hook(imported["address"],h.callback)
editor=0x300000;vtable=0x6f0000;stub=0x6f1000;events=[];panels={};resources={};widgets={};selectors=[]
capturing_style=False
recovered_styles=[]
word=h.word;put=h.put
args=lambda n:struct.unpack('<'+'I'*n,b.read(b.esp()+4,n*4))
signed=lambda x:x if x<0x80000000 else x-0x100000000

def finish(value=0):b.uc.reg_write(UC_X86_REG_EAX,value&0xffffffff);b.ret()
def rectangle(p):return [signed(word(p+4*i)) for i in range(4)]
def panel_number(p):return (p-0x610000)//256 if p>=0x610000 and p<0x620000 else -1

def callback(pc):
 global capturing_style
 if capturing_style and pc==0x743c6:return
 if capturing_style and pc==stub+16:
  fp=b.uc.reg_read(UC_X86_REG_EBP);start=fp-0x300;data=b.read(start,0x300)
  matches=[]
  for off in range(0,len(data)-17*20+1,4):
   rows=[list(struct.unpack_from('<5I',data,off+i*20)) for i in range(17)]
   if all(row[0]==i and 0<row[1]<200 and 0<row[2]<200 and row[3]>1 and row[4] in resources for i,row in enumerate(rows)):matches.append(rows)
  if len(matches)!=1:raise RuntimeError('Original knob style table is ambiguous')
  recovered_styles.extend(matches[0]);b.uc.reg_write(UC_X86_REG_EIP,0x500100);return
 a=args(32);value=0
 if pc==0x2914c:
  value=0x640000+a[1]*32;resources[value]=a[1]
  png=ROOT/'reference/CronoX 3.component/Contents/Resources'/('bmp%05d.png'%a[1]);width=height=0
  if png.exists():width,height=struct.unpack('>II',png.read_bytes()[16:24])
  put(value+16,width);put(value+20,height)
 elif pc==0x291ea:
  value=0x610000+a[1]*256;panels[a[1]]={'id':a[1],'x':a[2],'y':a[3],'image':resources.get(a[4],0)};put(value,vtable)
  put(editor+0x4e068+4*a[1],value)
 elif pc==0x286cc:value=0x610000+a[1]*256
 elif pc==stub:
  value=0 # NS/Carbon objects are represented by recording adapters.
 elif pc==stub+16:value=0
 elif pc==stub+32:
  # The string was initialized by the real caller; leave its empty value intact.
  value=0
 elif pc==0x1c6cc:b.write(a[2],b'\0')
 elif pc in [0x28030,0x8072c,0x2a154,0x73fe6,0x27f70,0x2c3cc]:pass
 elif pc==0x2ba34:
  events.append({'pc':hex(pc),'kind':'pm','panel':panel_number(a[1]),'tag':a[2],'rects':[rectangle(ptr) for ptr in a[3:7]],'args':list(a[:16])})
 elif pc==0x29068:
  selectors.append({'tag':a[1],'parent':a[2],'children':[signed(i) for i in a[3:27] if i not in (0xffffffff,0)]})
 elif pc in [0x9dd5c,0x9c77c,0xa6d70,0xb0d1e,0x9aa16,0x847a]:
  # CLabelPl is 0x847a in this image. 0x898a belongs to another widget;
  # using it lost the sample-table labels before createGeneralPl attached them.
  value=a[0];put(value,vtable);widgets[value]={'kind':{0x9dd5c:'waveform',0x9c77c:'scrollbar',0xa6d70:'arpeggiator',0xb0d1e:'keyboard',0x9aa16:'surround',0x847a:'text'}[pc],'rect':rectangle(a[1]),'tag':a[3]};events.append({'pc':hex(pc),'panel':None,**widgets[value],'widget':value,'args':list(a[:16])})
 elif pc==0x2986a:
  tags=[word(a[2]+4*i) for i in range(a[3])];events.append({'pc':hex(pc),'kind':'attach','panel':panel_number(a[4]),'widget':a[1],'tags':tags})
 elif pc==0x29984:events.append({'pc':hex(pc),'kind':'attach','panel':panel_number(a[3]),'widget':a[1],'tags':[a[2]]})
 elif pc==0xd7ac:
  events.append({'pc':hex(pc),'kind':'value','tag':(a[0]-editor-0x58)//0x14,'rect':[signed(i) for i in a[2:6]]})
 elif pc==0x9dc92:pass
 else:
  kinds={0x743c6:'dial',0x742e0:'horizontal-slider',0x2b6c2:'toggle',0x2b7f8:'radio',0x2b3e6:'menu',0x7c058:'slider',0x2b36a:'menu-image',0x29d1c:'button',0x2abc0:'edit',0x74d4c:'label',0x2bcb2:'display',0x29b8c:'file',0x2abc0:'edit',0x29bf8:'thin-slider',0x7acba:'xy',0x2aa3e:'field',0x2aee6:'licence',0x2b8fc:'gator',0x2b1f8:'menu-s',0x2bba6:'edit',0x2b456:'file-list',0x2b658:'file-list'}
  if pc not in kinds:raise ValueError(hex(pc))
  event={'pc':hex(pc),'kind':kinds[pc],'panel':panel_number(a[12] if pc==0x29bf8 else a[2] if pc==0x743c6 else a[1]),'args':list(a[:16])}
  if pc==0x74d4c:event['label']=h.string(a[3]).decode('mac_roman')
  events.append(event)
 finish(value)


def recover(output):
 global capturing_style
 hooks=[0x2ba34,0x28030,0x2914c,0x291ea,0x286cc,stub,stub+16,stub+32,0x1c6cc,0x8072c,0x2a154,0x73fe6,0x27f70,0x2c3cc,0x29068,0x9dd5c,0x9c77c,0xa6d70,0xb0d1e,0x9aa16,0x847a,0x2986a,0x29984,0xd7ac,0x9dc92,0x743c6,0x742e0,0x2b6c2,0x2b7f8,0x2b3e6,0x7c058,0x2b36a,0x29d1c,0x2abc0,0x74d4c,0x2bcb2,0x29b8c,0x2abc0,0x29bf8,0x7acba,0x2aa3e,0x2aee6,0x2b8fc,0x2b1f8,0x2bba6,0x2b456,0x2b658]
 for pc in dict.fromkeys(hooks):b.hook(pc,callback)
 for i in range(0,0x200,4):put(vtable+i,stub+16)
 for i in range(0,0x600,4):put(0x6f0800+i,stub+16)
 put(0x6f0800+0x300,stub+32);put(0x200000,0x6f0800)
 put(vtable+0x24,stub)
 # Synthetic editor storage; these adapters only replace OS widget creation.
 put(editor+0x50,0x200000);put(editor+0x28,0x610000)
 b.run(0x72ec0,[editor,0x200000]);
 put(0x610100,vtable)
 capturing_style=True
 b.run(0x743c6,[editor,0,0x610100,0,100,100,0,0xffffffff])
 capturing_style=False
 try:b.run(0x7f530,[editor])
 except Exception:
  print('Editor vtable',hex(word(editor)),'slotcc',hex(word(word(editor)+0xcc)),'EBP',hex(b.uc.reg_read(UC_X86_REG_EBP)),flush=True)
  print('Failed pc',hex(b.uc.reg_read(UC_X86_REG_EIP)), 'esp',hex(b.esp()),'return',hex(word(b.esp())), 'events',events[-4:], flush=True)
  raise
 styles=[row[:4]+[resources[row[4]]] for row in recovered_styles]
 report={'original_image_sha256':hashlib.sha256((ROOT/'reference/CronoX3.i386').read_bytes()).hexdigest(),'original_functions':['0x72ec0','0x7f530'],'scope':'Original i386 constructors with recording adapters for platform widgets; no synthesis or native Mac UI','panels':list(panels.values()),'selectors':selectors,'events':events,'styles':styles,'style_provenance':'Actual local table read while original createKnob executes, before the first platform frame call','resource_fields':{hex(off):resources[word(editor+off)] for off in range(0x4efc0,0x4f168,4) if word(editor+off) in resources}}
 output.write_text(json.dumps(report,indent=2)+'\n');print(len(panels),'panels',len(events),'events',len(selectors),'selectors')

if __name__=='__main__':
 import argparse
 parser=argparse.ArgumentParser();parser.add_argument('output',type=Path);options=parser.parse_args();options.output.parent.mkdir(parents=True,exist_ok=True);recover(options.output)
