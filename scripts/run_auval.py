#!/usr/bin/env python3
"""Run native macOS auval with a bounded timeout and retain its complete log."""
import argparse
import json
from pathlib import Path
import subprocess
import sys

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--log',type=Path,required=True)
    parser.add_argument('--timeout',type=int,default=180)
    args=parser.parse_args()
    if sys.platform!='darwin' or not 30<=args.timeout<=600:
        print(json.dumps({'error':'auval requires macOS and a timeout between 30 and 600 seconds'}))
        return 2
    try:
        with args.log.open('wb') as log:
            try:
                result=subprocess.run(['/usr/bin/auval','-v','aumu','Sop3','LinP'],stdout=log,stderr=subprocess.STDOUT,timeout=args.timeout)
                status=result.returncode;timed_out=False
            except subprocess.TimeoutExpired:
                status=124;timed_out=True
        print(json.dumps({'identity':'aumu/Sop3/LinP','auval_executed':True,'exitcode':status,'timed_out':timed_out,'passed':status==0}))
        return 0 if status==0 else 1
    except OSError:
        print(json.dumps({'auval_executed':False,'passed':False,'error':'Cannot launch auval or create its report log'}))
        return 1

if __name__=='__main__':
    sys.exit(main())
