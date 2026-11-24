#!/usr/bin/env python3
"""Audit CronoX instruction entries and all RTTI vtable adjustments.

Static coverage is a prerequisite, not proof of complete musical behavior.
"""
import gzip,hashlib,json,re,struct,sys
from pathlib import Path
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'scripts'))
from legacy_image import LegacyImage,SHA

image=LegacyImage((ROOT/'reference/CronoX3.i386').read_bytes());mapped=bytes(image.mapped())
meta=json.loads((ROOT/'analysis/cronox/macho.json').read_text())
classes=json.loads((ROOT/'analysis/cronox/vtables.json').read_text())
text=next(s for s in image.sections if s['name']=='__text')
is_code=lambda p:text['address']<=p<text['address']+text['size']
imports={x['address'] for x in image.stubs}
rows={}
with gzip.open(ROOT/'analysis/cronox/pcode/instructions.jsonl.gz','rt') as f:
    for line in f:
        i=json.loads(line);pc=int(i['address'],16);assert pc not in rows;rows[pc]=i
emitted={}
for p in (ROOT/'src/lifter/cronox').glob('Unit*.cpp'):
    for m in re.finditer(r'^L_([0-9a-f]+):',p.read_text(),re.M):
        pc=int(m[1],16);assert pc not in emitted;emitted[pc]=p.name
function_entries={s['address'] for s in meta['symbols'] if s['section']==1 and s['address']}
edges=[]
for pc,row in rows.items():
    for op in row['pcode']:
        if op['op'] in ['CALL','BRANCH','CBRANCH'] and op['inputs'][0]['space']=='ram':
            target=int(op['inputs'][0]['offset'],16)
            if target not in rows and target not in imports:
                edges.append({'from':hex(pc),'target':hex(target),'kind':op['op'],'asm':row['asm']})
md=Cs(CS_ARCH_X86,CS_MODE_32);bad=[]
for pc,row in rows.items():
    instruction=next(md.disasm(mapped[pc:pc+row['length']],pc,count=1),None)
    if not instruction or instruction.size!=row['length']:bad.append(hex(pc))
word=lambda p:struct.unpack_from('<I',mapped,p)[0]
vtables=[];targets=set()
for cls in classes:
    rtti=int(cls['rtti'],16)
    for section in image.sections:
        if section['segment']!='__DATA' or section['name'] not in ['__const','__const_coal']:continue
        for p in range(section['address'],section['address']+section['size']-12,4):
            adjustment=struct.unpack_from('<i',mapped,p)[0]
            if word(p+4)!=rtti or adjustment>0 or adjustment<-0x1000000:continue
            funcs=[];at=p+8
            while at+4<=section['address']+section['size'] and (is_code(word(at)) or word(at) in imports):
                funcs.append(word(at));at+=4
            if funcs:
                targets.update(x for x in funcs if is_code(x))
                vtables.append({'class':cls['name'],'object_offset':-adjustment,'address_point':hex(p+8),
                                'functions':[hex(x) for x in funcs]})
manifest=json.loads((ROOT/'src/lifter/cronox/manifest.json').read_text())
hash_errors=[]
for f in manifest['generated_files']:
    p=ROOT/'src/lifter/cronox'/f['name']
    if p.stat().st_size!=f['bytes'] or hashlib.sha256(p.read_bytes()).hexdigest()!=f['sha256']:hash_errors.append(f['name'])
report={'project':'CronoX 3 ARM64','original_sha256':SHA,'detected_instructions':len(rows),'compiled_labels':len(emitted),
        'missing_labels':[hex(p) for p in sorted(set(rows)-set(emitted))],
        'extra_labels':[hex(p) for p in sorted(set(emitted)-set(rows))],
        'unique_symbol_function_entries':len(function_entries),'missing_named_function_entries':[hex(p) for p in sorted(function_entries-set(rows))],
        'rtti_classes':len(classes),'vtable_address_points':len(vtables),'unique_internal_vtable_targets':len(targets),
        'missing_vtable_targets':[hex(p) for p in sorted(targets-set(rows))],'unresolved_direct_edges':edges,
        'capstone_length_disagreements':bad,'generated_files_verified':len(manifest['generated_files']),
        'generated_file_hash_errors':hash_errors,'inventory_is_not_exhaustive_behavior_proof':True}
report['passed']=not any(report[k] for k in ['missing_labels','extra_labels','missing_named_function_entries','missing_vtable_targets','unresolved_direct_edges','capstone_length_disagreements','generated_file_hash_errors'])
(ROOT/'evidence/cronox-code-inventory.json').write_text(json.dumps(report,indent=2)+'\n')
(ROOT/'analysis/cronox/vtable-layouts.json').write_text(json.dumps(vtables,indent=2)+'\n')
print(json.dumps(report,indent=2))
