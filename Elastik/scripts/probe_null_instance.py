#!/usr/bin/env python3
"""Execute only original AU entry calls with no instance in isolated Unicorn.

No engine is opened. The original's parameter-error result is the reference;
this is not native ARM execution, a licensed audio test, or project restoration.
Requires Unicorn for the development probe only.
"""
import argparse
import json
from pathlib import Path
import struct
from legacy_image import LegacyImage
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_MXCSR


def run(binary):
    image=LegacyImage(binary.read_bytes());u=Uc(UC_ARCH_X86,UC_MODE_32);u.mem_map(0,0x800000);u.mem_write(0,bytes(image.mapped()));u.reg_write(UC_X86_REG_MXCSR,0x1f80)
    imports=[]
    def stop_import(uc,pc,size,user):imports.append(pc);uc.emu_stop()
    u.hook_add(UC_HOOK_CODE,stop_import,begin=0x3da000,end=0x3dafe6)
    results=[]
    for selector,argument in [(-4,None),(-3,15),(-3,14),(-3,16),(-3,0x1234),(-2,None)]:
        imports.clear();params=struct.pack('<BBh',0,0 if argument is None else 4,selector)+(b'' if argument is None else struct.pack('<I',argument))
        u.mem_write(0x600000,params);u.mem_write(0x70f000,struct.pack('<III',0x500100,0x600000,0));u.reg_write(UC_X86_REG_ESP,0x70f000);u.emu_start(0x7490,0x500100,count=50000)
        value=u.reg_read(UC_X86_REG_EAX);pc=u.reg_read(UC_X86_REG_EIP)
        if imports or pc!=0x500100 or value!=0xffffffce:raise ValueError('Original null-instance behaviour differs from decoded entry')
        results.append({'selector':selector,'argument':argument,'completed':True,'return_signed':-50,'unbound_import_calls':0})
    return {'scope':'Original i386 null-instance calls under Unicorn; no engine initialization','results':results,'all_original_paramerr_results_match':True,'audio_rendered':False,'native_arm64_plugin_built':False}


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('binary',type=Path);p.add_argument('--output',type=Path,required=True);a=p.parse_args();a.output.write_text(json.dumps(run(a.binary),indent=2)+'\n')
