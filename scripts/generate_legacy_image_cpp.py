#!/usr/bin/env python3
"""Pin and embed guest data, imports and initializer addresses for native C++.

The embedded i386 bytes are data for constants, tables and 32-bit addresses.
Only the separately generated static C++ functions are executed.
"""
import argparse,hashlib,json
from pathlib import Path
from legacy_image import LegacyImage,SHA

def generate(image,output):
 data=image.read_bytes();legacy=LegacyImage(data);mapped=legacy.mapped()
 output.mkdir(parents=True,exist_ok=True)
 header='''// Generated from the pinned original; guest bytes are never executed.
#pragma once
#include <cstddef>
#include <cstdint>
namespace sophistry {
struct LegacyImport { std::uint32_t address; const char* name; };
extern const unsigned char legacy_image_data[];
extern const std::size_t legacy_image_size;
extern const LegacyImport legacy_imports[];
extern const std::size_t legacy_import_count;
extern const std::uint32_t legacy_initializers[];
extern const std::size_t legacy_initializer_count;
}
'''
 (output/'LegacyImageData.h').write_text(header)
 with (output/'LegacyImageData.cpp').open('w') as f:
  f.write('// Generated guest data from i386 SHA-256 '+SHA+'\n#include "LegacyImageData.h"\nnamespace sophistry {\nconst unsigned char legacy_image_data[]={\n')
  for start in range(0,len(mapped),24):f.write(','.join(str(x) for x in mapped[start:start+24])+',\n')
  f.write('};\nconst std::size_t legacy_image_size=sizeof(legacy_image_data);\nconst LegacyImport legacy_imports[]={\n')
  for row in legacy.stubs:f.write('{0x%x,%s},\n'%(row['address'],json.dumps(row['name'])))
  f.write('};\nconst std::size_t legacy_import_count=sizeof(legacy_imports)/sizeof(legacy_imports[0]);\nconst std::uint32_t legacy_initializers[]={\n')
  f.write(','.join(hex(x) for x in legacy.initializers)+'\n};\nconst std::size_t legacy_initializer_count=sizeof(legacy_initializers)/sizeof(legacy_initializers[0]);\n}\n')
 manifest={'original_sha256':SHA,'mapped_data_sha256':hashlib.sha256(mapped).hexdigest(),'mapped_bytes':len(mapped),'function_imports':len(legacy.stubs),'initializers':len(legacy.initializers),'machine_bytes_executed':False,'generated_files':[{'file':p.name,'bytes':p.stat().st_size,'sha256':hashlib.sha256(p.read_bytes()).hexdigest()} for p in [output/'LegacyImageData.h',output/'LegacyImageData.cpp']]}
 (output/'LegacyImageData.json').write_text(json.dumps(manifest,indent=2)+'\n');return manifest
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('image',type=Path);p.add_argument('output',type=Path);n=p.parse_args();print(json.dumps(generate(n.image,n.output),indent=2))
