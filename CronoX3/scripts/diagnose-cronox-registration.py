#!/usr/bin/env python3
"""Read only the comparison bundle and its AU registration diagnostics."""
from pathlib import Path
import argparse,json,os,plistlib,stat,subprocess,sys

TARGET=Path('/Library/Audio/Plug-Ins/Components/CronoX 3 ARM Test.component')

def command(args,limit=15):
    try:
        result=subprocess.run(args,stdout=subprocess.PIPE,stderr=subprocess.PIPE,timeout=limit)
        return {'exit_code':result.returncode,'stdout':result.stdout.decode('utf-8','replace')[-120000:],
                'stderr':result.stderr.decode('utf-8','replace')[-12000:]}
    except (OSError,subprocess.TimeoutExpired) as error:
        return {'error':type(error).__name__}

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--logs',action='store_true');args=parser.parse_args()
    if sys.platform!='darwin':parser.error('macOS required')
    out={'identity':'aumu/CrT3/LinP','read_only':True,'original_component_targeted':False,'paths':[]}
    binary=TARGET/'Contents/MacOS/CronoX3ARMTest'
    for path in [Path('/Library'),Path('/Library/Audio'),Path('/Library/Audio/Plug-Ins'),TARGET.parent,TARGET,TARGET/'Contents',binary.parent,binary]:
        try:
            s=path.stat();out['paths'].append({'path':str(path),'mode':oct(stat.S_IMODE(s.st_mode)),
                'uid':s.st_uid,'gid':s.st_gid,'quarantine_present':'com.apple.quarantine' in os.listxattr(path)})
        except OSError as error:out['paths'].append({'path':str(path),'error':type(error).__name__})
    try:
        with (TARGET/'Contents/Info.plist').open('rb') as f:info=plistlib.load(f)
        out['bundle']={key:info.get(key) for key in ['CFBundleIdentifier','CFBundleExecutable','CFBundleVersion','AudioComponents']}
    except (OSError,ValueError) as error:out['bundle']={'error':type(error).__name__}
    out['signature']=command(['/usr/bin/codesign','--verify','--strict',str(TARGET)])
    out['architecture']=command(['/usr/bin/lipo','-archs',str(binary)])
    catalogue=command(['/usr/bin/arch','-arm64','/usr/bin/auval','-a'])
    # Listing also lets the registry complete its scan. Keep only CronoX rows.
    catalogue['stdout']='\n'.join(line for line in catalogue.get('stdout','').splitlines()
        if any(token in line for token in ['CrT3','CrX3','CronoX 3 ARM Test']))
    out['cronox_catalogue']=catalogue
    if args.logs:
        predicate='(process == "AudioComponentRegistrar" OR process == "auvaltool") AND (eventMessage CONTAINS[c] "CrT3" OR eventMessage CONTAINS[c] "CronoX3.ARMTest" OR eventMessage CONTAINS[c] "CronoX 3 ARM Test")'
        out['registration_log']=command(['/usr/bin/log','show','--last','2m','--style','compact','--predicate',predicate])
    print(json.dumps(out,indent=2));return 0

if __name__=='__main__':raise SystemExit(main())
