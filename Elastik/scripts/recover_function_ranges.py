#!/usr/bin/env python3
"""Read original 32-bit Mach-O EH frame ranges; never run its machine code."""
import argparse
import io
import json
from pathlib import Path
import sys

# Optional local development dependency; normal virtualenv installations work too.
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'work/python-tools'))
from elftools.dwarf.callframe import CallFrameInfo,FDE
from elftools.dwarf.structs import DWARFStructs


def recover(binary,inventory,output):
    record=json.loads(inventory.read_text());arch=next(x for x in record['architectures']if x['architecture']=='i386')
    code=[x for x in arch['sections']if x.get('flags',0)&0x80000400];frame=next(x for x in arch['sections']if x['name']=='__eh_frame')
    blob=binary.read_bytes()[frame['offset']:frame['offset']+frame['bytes']]
    entries=CallFrameInfo(io.BytesIO(blob),len(blob),frame['address'],DWARFStructs(little_endian=True,dwarf_format=32,address_size=4),for_eh_frame=True).get_entries()
    ranges=[]
    for e in entries:
        if not isinstance(e,FDE):continue
        # DW_EH_PE_pcrel|absptr on this Mach-O stores a wrapped 32-bit
        # displacement. pyelftools uses Python's unbounded integer arithmetic.
        start=e['initial_location']&0xffffffff;size=e['address_range']
        if any(s['address']<=start<start+size<=s['address']+s['bytes'] for s in code):
            ranges.append((start,size))
    ranges=sorted(set(ranges));output.mkdir(parents=True,exist_ok=True)
    (output/'function-ranges.csv').write_text('address,size\n'+''.join(f'0x{address:08x},{size}\n'for address,size in ranges))
    result={'checkpoint':'ELA001','range_source':'Original __eh_frame metadata, normalized to 32-bit addresses','eh_frame_records':len(entries),'function_ranges_in_code_sections':len(ranges),'sum_function_bytes':sum(n for _,n in ranges),'code_section_bytes':sum(s['bytes']for s in code),'exports_confirmed':all(any(a==s['address']for a,n in ranges)for s in arch['defined_text_exports']),'all_function_names_or_semantics_recovered':False,'machine_code_executed':False,'native_port_built':False}
    (output/'function-recovery.json').write_text(json.dumps(result,indent=2)+'\n');return result


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('binary',type=Path);p.add_argument('inventory',type=Path);p.add_argument('--output',type=Path,required=True);a=p.parse_args();print(json.dumps(recover(a.binary,a.inventory,a.output),indent=2))
