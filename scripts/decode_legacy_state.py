#!/usr/bin/env python3
"""Structural, lossless reader for the observed CronoX/Sophistry parameter stream.
Schemas are recovered from original Sophistry descriptors. This is not DSP execution.
"""
import argparse,collections,hashlib,json,plistlib,struct
from pathlib import Path

def digest(b):return hashlib.sha256(b).hexdigest()
def read_input(path):
 d=path.read_bytes()
 if path.suffix.lower()=='.aupreset':
  pl=plistlib.loads(d)
  if not isinstance(pl,dict) or not isinstance(pl.get('vstdata'),bytes):raise ValueError('Expected vstdata CFData')
  return pl['vstdata'],{'kind':'AU','identity':{k:(int(pl[k])&0xffffffff).to_bytes(4,'big').decode('ascii','replace') for k in ['type','subtype','manufacturer']},'name':pl.get('name')}
 if d[:4]==b'CcnK':
  if len(d)<60 or d[8:12]!=b'FPCh':raise ValueError('Expected FPCh FXP')
  n=struct.unpack_from('>I',d,56)[0]
  if n!=len(d)-60:raise ValueError('FXP chunk length mismatch')
  return d[60:],{'kind':'FXP','plugin_id':d[16:20].decode('ascii','replace'),'outer_declared_size':struct.unpack_from('>I',d,4)[0]}
 return d,{'kind':'raw'}

def endian_of(d):
 if len(d)<12:raise ValueError('Truncated stream')
 sizes=[(e,struct.unpack_from(e+'I',d,4)[0]) for e in ['<','>']]
 valid=[e for e,n in sizes if 12<=n<=len(d) and n%4==0]
 if len(valid)!=1:raise ValueError('Ambiguous or invalid stream endianness')
 return valid[0]

def records(d,endian=None,base=0,depth=0):
 if depth>16:raise ValueError('Too many nested programs')
 endian=endian or endian_of(d);offset=0;out=[]
 while offset<len(d):
  if len(d)-offset<12:raise ValueError('Truncated block header')
  ident,size,index=struct.unpack_from(endian+'III',d,offset)
  tag=ident.to_bytes(4,'big').decode('ascii','replace')
  if size<12 or size%4 or size>len(d)-offset:raise ValueError('Invalid block size at '+hex(base+offset))
  raw=d[offset:offset+size]
  record={'tag':tag,'index':index,'offset':base+offset,'size':size,'sha256':digest(raw),'raw':raw,'endian':endian}
  if tag=='PROG':record['children']=records(raw[12:],endian,base+offset+12,depth+1)
  out.append(record);offset+=size
 return out

def decode_fields(record,schema):
 d=record['raw'];endian=record['endian'];pos=12;fields=[]
 for f in schema['fields']:
  if pos==len(d):break
  if len(d)-pos<4:raise ValueError('Truncated field')
  at=pos;word=struct.unpack_from(endian+'I',d,pos)[0];pos+=4;kind=f['kind'];item={'index':f['index'],'name':f['name'],'kind':kind,'offset':at}
  if kind in [2,7]:
   if word%4 or word>len(d)-pos:raise ValueError('Invalid string span')
   raw=d[pos:pos+word];pos+=word
   if word and b'\0' not in raw:raise ValueError('Missing string terminator')
   # The observed Windows preset has 0xcd allocator padding after the NUL.
   value=raw.split(b'\0',1)[0].decode('utf8','replace');item['value']=value;item['storage_bytes']=word
  elif kind==8:
   if word>(len(d)-pos)//4:raise ValueError('Invalid float array span')
   item['value']=list(struct.unpack_from(endian+'f'*word,d,pos));pos+=4*word
  else:item['value']=struct.unpack_from(endian+'i',d,at)[0]
  item['raw_hex']=d[at:pos].hex();fields.append(item)
 return {'class':schema['class'],'fields':fields,'decoded_field_count':len(fields),'expected_schema_fields':len(schema['fields']),'remaining_bytes':len(d)-pos,'missing_tail_fields':len(schema['fields'])-len(fields),'raw_round_trip_supported':True}

def apply_schemas(rr,schemas):
 for r in rr:
  if 'children' in r:apply_schemas(r['children'],schemas);continue
  candidates=[]
  for s in schemas:
   if not s['extraction_ok'] or s['tag']!=r['tag']:continue
   try:candidates.append(decode_fields(r,s))
   except (ValueError,struct.error):pass
  if candidates:
   candidates.sort(key=lambda c:(c['remaining_bytes'],c['missing_tail_fields']))
   r['decoded']=candidates[0]
   r['decode_scope']='all_bytes' if r['decoded']['remaining_bytes']==0 else 'prefix_only'
  else:r['decode_scope']='no_matching_schema'

def public(r):
 return {k:[public(x) for x in v] if k=='children' else v for k,v in r.items() if k not in ['raw','endian']}
def leaves(rr):
 for r in rr:
  if 'children' in r:yield from leaves(r['children'])
  else:yield r

def summarize(path,schemas):
 d,meta=read_input(path);rr=records(d);apply_schemas(rr,schemas);ll=list(leaves(rr))
 if b''.join(r['raw'] for r in rr)!=d:raise AssertionError('Lossless parse changed original')
 return {'source':str(path),'metadata':meta,'chunk_size':len(d),'chunk_sha256':digest(d),'endianness':'little' if endian_of(d)=='<' else 'big','top_level_blocks':len(rr),'leaf_blocks':len(ll),'fully_consumed_by_schema':sum(r.get('decode_scope')=='all_bytes' for r in ll),'round_trip_byte_exact':True,'records':[public(r) for r in rr],'scope':'Structural serialization decoding; no DSP or original-project compatibility established'},rr

def compare(a,b):
 def keyed(rr):
  counts=collections.Counter();out={}
  for r in leaves(rr):
   key=(r['tag'],r['index']);n=counts[key];counts[key]+=1;out[key+(n,)]=r
  return out
 aa,bb=keyed(a),keyed(b);equal=0;diff=[];unmatched=[]
 for key in sorted(aa.keys()|bb.keys()):
  if key not in aa or key not in bb:unmatched.append({'block':key,'only_in':'first' if key in aa else 'second'});continue
  x,y=aa[key],bb[key]
  if 'decoded' not in x or 'decoded' not in y:continue
  xf={f['index']:f for f in x['decoded']['fields']};yf={f['index']:f for f in y['decoded']['fields']}
  for i in sorted(xf.keys()&yf.keys()):
   p,q=xf[i],yf[i]
   if p['value']==q['value']:equal+=1
   else:diff.append({'block':key,'field':i,'name':p['name'],'first':p['value'],'second':q['value']})
 return {'shared_blocks':len(aa.keys()&bb.keys()),'equal_decoded_fields':equal,'different_decoded_fields':len(diff),'differences':diff,'unmatched_blocks':unmatched,'equivalent_sound_proven':False,'note':'Matching serialization tags does not prove that two imported states render identically. Defaults/version migrations, enums, sample paths and host metadata can differ.'}

if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('files',type=Path,nargs='+');p.add_argument('--schemas',type=Path,default=Path(__file__).resolve().parents[1]/'analysis/parameter-schemas.json');p.add_argument('--output',type=Path,required=True);n=p.parse_args();n.output.mkdir(parents=True,exist_ok=True)
 schemas=json.loads(n.schemas.read_text())['modules'];parsed=[]
 for f in n.files:
  report,rr=summarize(f,schemas);parsed.append(rr);(n.output/(f.stem+'-'+f.suffix[1:]+'.json')).write_text(json.dumps(report,indent=2,ensure_ascii=False,allow_nan=False)+'\n')
  print(json.dumps({k:report[k] for k in ['metadata','chunk_size','top_level_blocks','leaf_blocks','fully_consumed_by_schema','round_trip_byte_exact']},ensure_ascii=False))
 if len(parsed)==2:
  report=compare(*parsed);(n.output/'comparison.json').write_text(json.dumps(report,indent=2,ensure_ascii=False,allow_nan=False)+'\n');print('Shared blocks:',report['shared_blocks'],'Equal fields:',report['equal_decoded_fields'],'Different fields:',report['different_decoded_fields'])
