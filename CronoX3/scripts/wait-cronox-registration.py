#!/usr/bin/env python3
"""Wait for a fresh system lookup of the comparison AU before authoritative auval."""
from pathlib import Path
import argparse
import json
import subprocess
import sys
import time


def wait_for_registration(probe, report, timeout=30, runner=subprocess.run,
                          clock=time.monotonic, pause=time.sleep):
    deadline=clock()+timeout
    attempts=[]
    while clock()<deadline:
        index=len(attempts)+1
        prefix=report/('discovery-%02d'%index)
        try:
            result=runner([str(probe)],stdout=subprocess.PIPE,stderr=subprocess.PIPE,
                          timeout=max(.1,min(12,deadline-clock())))
            code=result.returncode
            prefix.with_suffix('.json').write_bytes(result.stdout)
            prefix.with_suffix('.log').write_bytes(result.stderr)
        except subprocess.TimeoutExpired:
            attempts.append({'attempt':index,'exit_code':124,'timed_out':True})
            break
        attempts.append({'attempt':index,'exit_code':code})
        if code==0:
            # A successful process must also produce the expected positive JSON.
            try:
                data=json.loads(result.stdout)
                valid=isinstance(data,dict) and data.get('passed') is True and data.get('subtype')=='CrT3' and data.get('registered_matches')==1
            except (ValueError,TypeError):valid=False
            if not valid:break
            return {'identity':'aumu/CrT3/LinP','passed':True,'attempts':attempts,
                    'fresh_process_per_attempt':True,'auval_executed':False}
        # Only absent components and stale build markers are transient here.
        # Duplicates and factory errors require diagnosis, not repeated loading.
        if code not in (3,5):break
        remaining=deadline-clock()
        if remaining<=0:break
        print('Registre Audio Unit : attente du composant CrT3 (essai %d)…'%index,file=sys.stderr,flush=True)
        pause(min(2,remaining))
    return {'identity':'aumu/CrT3/LinP','passed':False,'attempts':attempts,
            'fresh_process_per_attempt':True,'auval_executed':False,
            'error':'The system registry did not load the expected comparison AU'}


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--probe',type=Path,required=True)
    parser.add_argument('--report',type=Path,required=True)
    parser.add_argument('--timeout',type=int,default=30)
    args=parser.parse_args()
    if sys.platform!='darwin' or not 1<=args.timeout<=60:parser.error('macOS and a timeout between 1 and 60 seconds required')
    args.report.mkdir(parents=True,exist_ok=True)
    result=wait_for_registration(args.probe,args.report,args.timeout)
    print(json.dumps(result));return 0 if result['passed'] else 1


if __name__=='__main__':raise SystemExit(main())
