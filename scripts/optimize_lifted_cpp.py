#!/usr/bin/env python3
"""Localize proven instruction scratch and cache GP/flags before C++ compilation.

The checked-in original lift stays intact. This build pass neither decodes x86
nor changes arithmetic, branches, instruction ticks, or host callbacks.
"""
import argparse,bisect,hashlib,json,re
from pathlib import Path
from lift_pcode_chunks import rows
from lift_pcode_cpp import SHA

ROOT=Path(__file__).resolve().parent.parent
ACCESS=re.compile(r'sl_(get|put)<(\d+)>\(c\.(temp|reg),sizeof\(c\.\3\),0x([0-9a-f]+),')
INSTRUCTION=re.compile(r'(L_([0-9a-f]+):\{ //[^\n]*\nc\.pc=[^\n]*\n)(.*?)(?=^\}\n)',re.M|re.S)

def digest(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def regions(ins):
    spans=sorted((int(v['offset'],16),int(v['offset'],16)+v['size'])
                 for op in ins['pcode']
                 for v in op['inputs']+([op['output']] if op['output'] else [])
                 if v['space']=='unique')
    merged=[]
    for a,b in spans:
        if merged and a<=merged[-1][1]:merged[-1][1]=max(b,merged[-1][1])
        else:merged.append([a,b])
    return merged

def unique_reads(op):
    return set(b for v in op['inputs'] if v['space']=='unique'
               for b in range(int(v['offset'],16),int(v['offset'],16)+v['size']))
def unique_writes(op):
    v=op['output']
    return set(range(int(v['offset'],16),int(v['offset'],16)+v['size'])) if v and v['space']=='unique' else set()

def definitely_initialized(ins):
    """Prove every scratch byte is defined on every reaching p-code path."""
    ops=ins['pcode'];n=len(ops)
    if not n:return True
    edges=[]
    for j,op in enumerate(ops):
        kind=op['op'];successors=[]
        if kind in ['BRANCH','CBRANCH','CALL']:
            v=op['inputs'][0]
            if v['space']=='const':
                delta=int(v['offset'],16);bits=v['size']*8
                if delta>=(1<<(bits-1)):delta-=1<<bits
                target=j+delta
                if not 0<=target<=n:raise ValueError('Invalid p-code local branch')
                if target<n:successors.append(target)
            if kind=='CBRANCH' and j+1<n:successors.append(j+1)
        elif kind not in ['BRANCHIND','CALLIND','RETURN'] and j+1<n:
            successors.append(j+1)
        edges.append(successors)
    reachable={0};pending=[0]
    while pending:
        for target in edges[pending.pop()]:
            if target not in reachable:reachable.add(target);pending.append(target)
    predecessors={j:[] for j in reachable}
    for j in reachable:
        for target in edges[j]:predecessors[target].append(j)
    writes=[unique_writes(op) for op in ops]
    reads=[unique_reads(op) for op in ops]
    universe=set().union(*(a|b for a,b in zip(reads,writes)))
    incoming={j:(set() if j==0 else universe.copy()) for j in reachable}
    changed=True
    while changed:
        changed=False
        for j in sorted(reachable):
            new=set() if j==0 else set.intersection(*(incoming[k]|writes[k] for k in predecessors[j]))
            if new!=incoming[j]:incoming[j]=new;changed=True
    return all(reads[j]<=incoming[j] for j in reachable)

def transform_instruction(match,expected,statistics):
    pc=int(match[2],16)
    if pc not in expected:raise ValueError('Unknown generated instruction')
    spans=expected[pc]
    declarations=''.join(f'SlU8 local_{i}[{b-a}];\n' for i,(a,b) in enumerate(spans or []))
    def replace(m):
        kind,size,space,offset=m[1],int(m[2]),m[3],int(m[4],16)
        if space=='temp':
            if spans is None:return m[0] # Preserve a scratch read not proven local.
            choices=[(a,b,f'local_{i}') for i,(a,b) in enumerate(spans)]
        else:
            choices=[(0,32,'registers.gp'),(0x200,0x210,'registers.flags')]
        for a,b,array in choices:
            if a<=offset and offset+size<=b:
                statistics[space+'_accesses_localized']+=1
                return f'sl_{kind}<{size}>({array},sizeof({array}),0x{offset-a:x},'
            if offset<b and a<offset+size:raise ValueError('Partially overlapping cached storage')
        if space=='temp':raise ValueError('Scratch access not described by p-code')
        return m[0]
    body=ACCESS.sub(replace,match[3])
    if spans is not None and 'c.temp' in body:raise ValueError('Unrecognized scratch access')
    statistics['instruction_labels_preserved']+=1
    return match[1]+declarations+body

def optimize(source,output):
    source=source.resolve();output=output.resolve()
    if source==output:raise ValueError('Keep the original lift separate from build output')
    manifest=json.loads((source/'manifest.json').read_text())
    if manifest['original_sha256']!=SHA:raise ValueError('Wrong original executable')
    base=ROOT/'analysis/lifter-full'
    inputs={'optimizer':digest(Path(__file__)),'runtime':digest(ROOT/'src/lifter/LifterRuntime.h'),
            'register_cache':digest(ROOT/'src/lifter/OptimizedLifter.h'),
            'source_manifest':digest(source/'manifest.json')}
    for name in ['instructions.jsonl.gz','integration-additions-cp032.jsonl','excluded-misaligned-cp032.json']:
        inputs[name]=digest(base/name)
    for row in manifest['generated_files']:
        if Path(row['name']).name!=row['name']:raise ValueError('Invalid generated filename')
        if digest(source/row['name'])!=row['sha256']:raise ValueError('Original generated source changed: '+row['name'])
    target=output/'manifest.json'
    if target.exists():
        previous=json.loads(target.read_text())
        if previous.get('input_sha256')==inputs and all((output/r['name']).is_file() and digest(output/r['name'])==r['sha256'] for r in previous['generated_files']):
            return {**previous,'reused':True}
    output.mkdir(parents=True,exist_ok=True)
    expected=[{} for _ in range(manifest['compilation_units'])]
    statistics={'instruction_labels_preserved':0,'instructions_with_local_scratch':0,
                'scratch_fallback_addresses':[],'maximum_local_scratch_bytes':0,
                'temp_accesses_localized':0,'reg_accesses_localized':0}
    raw=hashlib.sha256();count=0
    for data,ins in rows(base/'instructions.jsonl.gz',base/'integration-additions-cp032.jsonl',base/'excluded-misaligned-cp032.json'):
        raw.update(data);count+=1;pc=int(ins['address'],16)
        unit=max(0,bisect.bisect_right(manifest['layout_starts'],pc)-1)
        spans=regions(ins)
        if spans:
            if definitely_initialized(ins):
                statistics['instructions_with_local_scratch']+=1
                statistics['maximum_local_scratch_bytes']=max(statistics['maximum_local_scratch_bytes'],sum(b-a for a,b in spans))
            else:statistics['scratch_fallback_addresses'].append(ins['address']);spans=None
        expected[unit][pc]=spans
    if raw.hexdigest()!=manifest['input_raw_sha256'] or count!=manifest['instruction_count']:
        raise ValueError('Original p-code and generated C++ inventory differ')
    generated=[]
    for row in manifest['generated_files']:
        name=row['name'];text=(source/name).read_text()
        if name!='Dispatch.cpp':
            unit=int(name[4:8]);matches=list(INSTRUCTION.finditer(text))
            if {int(m[2],16) for m in matches}!=set(expected[unit]) or len(matches)!=len(expected[unit]):
                raise ValueError('Generated instruction boundaries differ: '+name)
            text=INSTRUCTION.sub(lambda m:transform_instruction(m,expected[unit],statistics),text)
            signature=f'int sl_unit_{unit:04d}(SlCpu& c){{\n'
            if text.count(signature)!=1:raise ValueError('Unknown compiled-unit signature')
            text=text.replace('#include "LifterRuntime.h"','#include "OptimizedLifter.h"',1)
            text=text.replace(signature,signature+'SlRegisterCache registers(c);\nSlUnitState execution(c);\n',1)
            text=re.sub(r'\bc\.(pc|fault|stop)\b',r'execution.\1',text)
            text=text.replace('sl_tick(c)','execution.tick()')
            text=text.replace('(c.memory,c.memory_size,','(execution.memory,execution.memory_size,')
            text=re.sub(r'\bsl_(get|put)<',r'sl_local_\1<',text)
            text=text.replace(',c)',',execution)').replace('sl_divide(c,','sl_local_divide(execution,')
        destination=output/name
        if not destination.exists() or destination.read_text()!=text:destination.write_text(text)
        generated.append({'name':name,'bytes':destination.stat().st_size,'sha256':digest(destination)})
    if statistics['instruction_labels_preserved']!=count:raise ValueError('Instruction lost in build pass')
    result={'scope':'Build-time storage optimization of the complete original static lift',
            'original_sha256':SHA,'original_pcode_sha256':raw.hexdigest(),'input_sha256':inputs,
            'instruction_count':count,'compilation_units':manifest['compilation_units'],
            'register_ranges_cached':[[0,32],[512,528]],'instruction_ticks_changed':False,
            'execution_fields_localized':['pc','fault','steps','stop','limit','memory','memory_size'],
            'arithmetic_operations_changed':False,'host_callbacks_at_unit_boundaries':True,
            **statistics,'generated_files':generated}
    target.write_text(json.dumps(result,indent=2)+'\n')
    return {**result,'reused':False}

if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source',type=Path);parser.add_argument('output',type=Path)
    args=parser.parse_args();result=optimize(args.source,args.output)
    print(json.dumps({k:v for k,v in result.items() if k not in ['generated_files','input_sha256']},indent=2))
