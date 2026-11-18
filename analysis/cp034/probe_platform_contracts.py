#!/usr/bin/env python3
"""Original i386 / CP032 lift agreement for feature selection and time conversion.

Controlled platform responses isolate the internal machine-code translation.
They do not certify that the production platform adapter supplies real time.
"""
import argparse,ctypes,hashlib,json,struct,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sys.path[:0]=[str(ROOT/'scripts'),str(ROOT/'tests')]
from compare_lifted_dsp import Native,Original,SHA
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX

word=lambda x:struct.pack('<I',x&0xffffffff)
readword=lambda b:struct.unpack('<I',b)[0]

def regwrite(backend,offset,value):
    if isinstance(backend,Native):backend.regwrite(offset,word(value))
    else:backend.uc.reg_write(UC_X86_REG_EAX if offset==0 else UC_X86_REG_EDX,value&0xffffffff)

def eax(backend):
    if isinstance(backend,Original):return backend.uc.reg_read(UC_X86_REG_EAX)
    result=ctypes.create_string_buffer(4)
    assert not backend.l.sl_reg_read(backend.c,0,result,4)
    return readword(result.raw)

def run(library):
    image=(ROOT/'reference/Sophistry.i386').read_bytes()
    assert hashlib.sha256(image).hexdigest()==SHA
    lib=ctypes.CDLL(str(library.resolve()));features=[];timers=[]
    for mask,advanced in [(0,0),(1<<26,0),(0,1),(1<<26,1)]:
        values=[]
        for backend in [Original(image),Native(lib,image)]:
            def gestalt(at,b=backend):
                sp=b.esp();selector=readword(b.read(sp+4,4));pointer=readword(b.read(sp+8,4))
                assert selector in [0x78383666,0x78383661]
                b.write(pointer,word(mask if selector==0x78383666 else advanced))
                regwrite(b,0,0);b.ret()
            backend.hook(0x1034e7,gestalt)
            backend.run(0xae8a0,[]);values.append(eax(backend));backend.close()
        assert values[0]==values[1]
        features.append({'x86_features':mask,'x86_additional_features':advanced,'original_result':values[0],'lifted_result':values[1],'exact':True})
    for numerator,denominator,ticks in [(1,1,1000),(1,1,2000),(1,1,5000),(1,1,1000000),(1,1,1000000000),(1,1,1234567890123),(125,3,24000000),(125,3,48000000)]:
        values=[]
        for backend in [Original(image),Native(lib,image)]:
            backend.write(0xfc210,b'\0'*8)
            def timebase(at,b=backend):
                pointer=readword(b.read(b.esp()+4,4));b.write(pointer,word(numerator)+word(denominator));regwrite(b,0,0);b.ret()
            def absolute(at,b=backend):
                regwrite(b,0,ticks);regwrite(b,8,ticks>>32);b.ret()
            backend.hook(0x1032ee,timebase);backend.hook(0x103307,absolute)
            backend.run(0x2e1c0,[0x210000]);values.append(eax(backend));backend.close()
        assert values[0]==values[1],(numerator,denominator,ticks,values)
        timers.append({'numerator':numerator,'denominator':denominator,'ticks':ticks,'original_milliseconds':values[0],'lifted_milliseconds':values[1],'exact':True})
    return {'scope':'Isolated actual original i386 feature-selection and time-conversion routines versus the unmodified CP032 C++ lift, with identical controlled platform inputs','original_sha256':SHA,'feature_function':'0xae8a0','time_function':'0x2e1c0','feature_cases':features,'time_cases':timers,'production_feature_mode':features[-1]['lifted_result'],'production_synthetic_clock_first_queries_return_zero_milliseconds':all(r['lifted_milliseconds']==0 for r in timers[:3]),'shared_inputs_do_not_establish_production_adapter_fidelity':True,'passed':True}

if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('library',type=Path);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    result=run(args.library);args.output.parent.mkdir(parents=True,exist_ok=True);args.output.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2))
