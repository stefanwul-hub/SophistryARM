#!/usr/bin/env python3
"""Validate only the comparison AU; preserve a bounded, complete auval log."""
from pathlib import Path
import argparse,json,subprocess,sys
p=argparse.ArgumentParser();p.add_argument('--log',type=Path,required=True);p.add_argument('--timeout',type=int,default=180);a=p.parse_args()
if sys.platform!='darwin' or not 30<=a.timeout<=600:raise SystemExit('auval demande macOS et un délai de 30 à 600 secondes')
with a.log.open('wb') as out:
 try:
  r=subprocess.run(['/usr/bin/arch','-arm64','/usr/bin/auval','-v','aumu','CrT3','LinP'],stdout=out,stderr=subprocess.STDOUT,timeout=a.timeout)
  code=r.returncode;timeout=False
 except subprocess.TimeoutExpired:code=124;timeout=True
print(json.dumps({'identity':'aumu/CrT3/LinP','auval_executed':True,'passed':code==0,'exitcode':code,'timed_out':timeout,'original_identity_targeted':False}))
sys.exit(0 if code==0 else 1)
