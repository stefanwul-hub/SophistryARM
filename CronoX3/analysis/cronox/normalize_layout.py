from pathlib import Path
import json,struct,collections,argparse
ROOT=Path(__file__).resolve().parents[2]
parser=argparse.ArgumentParser();parser.add_argument('input',type=Path);options=parser.parse_args();dest=options.input

r=json.load(open(dest/'original-layout.json'));meta={x['tag']:x for x in json.load(open(dest/'editor-schema.json'))};resources={0x640000+n*32:n for n in r['resource_fields'].values()};fields=r['resource_fields'];styles=[350,351,353,352,354,356,355,357,360,361,362,363,364,365,366,367,358,376,377]
def dims(image):
 p=ROOT/('reference/CronoX 3.component/Contents/Resources/bmp%05d.png'%image)
 return struct.unpack('>II',p.read_bytes()[16:24]) if p.exists() else (0,0)
def signed(n):return n if n<0x80000000 else n-0x100000000
controls=[];last={};bywidget={}
def add(kind,panel,tag,x,y,w,h,image=0,frames=0,extra=(0,0,0),value=(0,0,0,0),caption=''):
 c={'key':len(controls),'kind':kind,'panel':panel,'tag':tag,'x':signed(x),'y':signed(y),'width':w,'height':h,'image':image,'frames':frames,'extra':list(extra),'value_rect':list(value),'caption':caption}
 controls.append(c);last[tag]=c;return c
for e in r['events']:
 k=e['kind'];a=e.get('args',[]);panel=e.get('panel',-1)
 if k=='attach':
  c=bywidget.get(e['widget'])
  if c:
   c['panel']=panel;c['extra']=(e['tags'][1:]+[0,0,0])[:3]
   if c['kind']=='Scrollbar':c['extra'][1:]=[12,1]
  continue
 if k=='value':
  c=last.get(e['tag'])
  if c:
   x,y,w,h=e['rect'];c['value_rect']=[x-w//2,y-h//2,w,h]
  continue
 if k=='pm':
  x,y,xx,yy=e['rects'][0];text,minus,plus=e['rects'][1:];c=add('Step',panel,e['tag'],x,y,xx-x,yy-y,extra=(minus[0]-x,plus[0]-x,1),value=(text[0],text[1],text[2]-text[0],text[3]-text[1]))
 elif k=='dial':
  style=a[1];_,w,h,frames,_=r['styles'][style];offset=signed(a[6]);value=[a[4]-18,a[5]+offset-4,36,8] if offset else [0,0,0,0]
  add('Dial',panel,a[3],a[4]-w//2,a[5]-h//2,w,h,r['styles'][style][4],frames,value=value,extra=(int(a[7]==0xff400000),0,0))
 elif k=='step':add('Step',panel,a[2],a[3],a[4],71 if a[5] else 56,15)
 elif k=='toggle':
  tag=a[2];im=resources.get(a[5],0);w,h=dims(im);frames=meta[tag]['maximum']-meta[tag]['minimum']+1
  add('Toggle',panel,tag,a[3],a[4],w,h//max(1,frames),im,frames)
 elif k=='radio':
  im=resources.get(a[7],0);w,h=dims(im);rows=abs(signed(a[6]));cols=a[5];denom=cols*rows if signed(a[6])<0 else 2
  add('Radio',panel,a[2],a[3],a[4],w,h//denom,im,denom,extra=(cols,rows,int(signed(a[6])<0)))
 elif k=='menu-s':
  im=resources.get(a[4],0);add('Menu',panel,a[3],a[5],a[6],a[7],a[8],im,1)
 elif k=='gator':
  im=resources.get(a[6],0);w,h=dims(im);add('Gator',panel,a[2],a[4],a[5],w*a[3],h//2,im,2,extra=(a[3],0,0))
 elif k=='file-list':
  im=resources.get(a[3],0);add('File',panel,a[2],a[4],a[5],a[6],a[7],im,1)
 elif k in ['menu','menu-image']:
  if k=='menu':tag=a[3];x,y,w,h=a[4:8];im=0
  else:tag=a[4];x,y=a[5:7];im=resources.get(a[3],0);w,h=dims(im)
  add('Menu',panel,tag,x,y,w,h,im,1)
 elif k=='slider':
  tag=a[2];im=377 if a[5] else 376;w,h=(10,73) if a[5] else (19,86);x=a[3] if a[5] else a[3]-4
  value=[a[3]+6-17,a[4]-12-4,34,8] if a[6] else [0,0,0,0]
  # Original helper 0x54594 sets CControlPl+0x73 to reverse both the displayed
  # normalized value (0x16a4/0x1704) and the pointer result (0x1ce0).
  add('Drawbar',panel,tag,x,a[4],w,h,im,1,extra=(8 if a[5] else 10,1,0),value=value)
 elif k=='horizontal-slider':add('HorizontalSlider',panel,a[2],a[3],a[4],65,11,374,33)
 elif k=='thin-slider':
  add('ThinSlider',panel,a[1],a[2],a[3],a[4],a[5],resources.get(a[11],0),1,extra=(10,13,0))
 elif k in ['edit','display']:
  add('Text' if k=='edit' else 'Display',panel,a[2],a[3],a[4],a[5],a[6])
 elif k=='label':add('Label',panel,0,a[2]*0+12,10+a[2]*13,55,11,caption=e['label'])
 elif k=='button':add('Action',panel,a[2],a[6],a[7],a[8],a[9],extra=(a[3],signed(a[4]),signed(a[5])))
 elif k=='file':add('File',panel,a[2],a[8],a[9],a[10],a[11],extra=(a[7],0,0))
 elif k=='xy':add('XY',panel,a[2],a[3],a[4],a[5],a[5],extra=(a[2]+1,0,0))
 elif k in ['waveform','scrollbar','arpeggiator','keyboard','surround','text']:
  x,y,xx,yy=e['rect'];name={'waveform':'Wave','scrollbar':'Scrollbar','arpeggiator':'Arpeggiator','keyboard':'Keyboard','surround':'Surround','text':'Display'}[k]
  c=add(name,-1,e['tag'],x,y,xx-x,yy-y);bywidget[e['widget']]=c
 elif k=='licence':add('Licence',panel,766,a[2],a[3],a[5],a[6])
 elif k=='field':add('Display',panel,a[2],a[3],a[4],a[5],a[6])
 else:raise ValueError(k)
# Only attached controls are part of the original UI. Helpers make no standalone controls for reserved EnhEnv panels.
controls=[c for c in controls if c['panel']>=0 and c['width']>0 and c['height']>0 and (c['tag']!=766 or c['kind']=='Licence')]
for rule in r['selectors']:rule['children']=[p for p in rule['children'] if p>0]
for i,c in enumerate(controls):c['key']=i
out={'scope':'Original UI constructors executed in i386 with recording platform adapters; only Main name fields use existing native preset handling','original_image_sha256':r['original_image_sha256'],'panels':r['panels'],'selectors':r['selectors'],'controls':controls,'canonical_au':{str(t):v['aliases'][0] for t,v in meta.items() if v['aliases']},'reserved_empty_panels':[70,71,82,83,84,85,86]}
(dest/'recovered-editor-layout.json').write_text(json.dumps(out,indent=2)+'\n')
# The table is a fixed result of executing original constructors, shared by Cocoa and the engine.
kindnames=['Dial','Step','Toggle','Radio','Menu','Drawbar','HorizontalSlider','ThinSlider','Text','Display','Label','Action','File','XY','Wave','Scrollbar','Arpeggiator','Keyboard','Surround','Licence','Gator']
head='''#pragma once
#include "EditorControls.h"
#include <functional>
namespace sophistry {
enum class RecoveredWidget {'''+','.join(kindnames)+'''};
struct RecoveredControl {
 unsigned key,panel,tag; RecoveredWidget kind; int x,y,width,height; unsigned image,frames;
 std::array<int,3> extra; std::array<int,4> valueRect; const char* caption;
};
struct RecoveredPanel { unsigned id; int x,y; unsigned image; };
inline const std::vector<RecoveredPanel>& recoveredPanels(){static const std::vector<RecoveredPanel> v={\n'''
for p in r['panels']:head+=' {%d,%d,%d,%d},\n'%(p['id'],p['x'],p['y'],p['image'])
head+='};return v;}\ninline const std::vector<RecoveredControl>& recoveredControls(){static const std::vector<RecoveredControl> v={\n'
for c in controls:
 head+=' {%d,%d,%d,RecoveredWidget::%s,%d,%d,%d,%d,%d,%d,{%s},{%s},%s},\n'%(c['key'],c['panel'],c['tag'],c['kind'],c['x'],c['y'],c['width'],c['height'],c['image'],c['frames'],','.join(map(str,c['extra'])),','.join(map(str,c['value_rect'])),json.dumps(c['caption']))
head+='};return v;}\nstruct RecoveredSelector {unsigned tag,parent; std::vector<unsigned> children;};\ninline const std::vector<RecoveredSelector>& recoveredSelectors(){static const std::vector<RecoveredSelector> v={\n'
for rule in r['selectors']:head+=' {%d,%d,{%s}},\n'%(rule['tag'],rule['parent'],','.join(map(str,rule['children'])))
head+='};return v;}\ninline unsigned recoveredAUParameter(unsigned tag){ switch(tag){\n'
for tag,row in meta.items():
 if row['aliases']:head+=' case %d:return %d;\n'%(tag,row['aliases'][0])
head+=' default:return noAUParameter;}}\n} // namespace sophistry\n'
(dest/'RecoveredEditorLayout.h').write_text(head)
print(len(controls),'controls',len(set(c['tag'] for c in controls)),'tags',collections.Counter(c['kind'] for c in controls))
print('Unusable sizes',[(c['kind'],c['tag'],c['width'],c['height']) for c in controls if c['width']<1 or c['height']<1])
