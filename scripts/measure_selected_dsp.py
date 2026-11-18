#!/usr/bin/env python3
"""Alternating timing and exact-state checks for the public selected DSP replay."""
import argparse,json,statistics,subprocess
from pathlib import Path

def measure(args):
    args.output.mkdir(parents=True,exist_ok=True);runs=[];expected_work=None
    for trial in range(5):
        for mode in ['baseline','candidate'] if trial%2==0 else ['candidate','baseline']:
            prefix=args.output/f'selected-{mode}-{trial}'
            with prefix.with_suffix('.json').open('w') as out,prefix.with_suffix('.txt').open('w') as err:
                subprocess.run([str(getattr(args,mode)),str(args.original),str(args.fixtures)],stdout=out,stderr=err,check=True)
            reference=json.loads(prefix.with_suffix('.json').read_text())
            if not reference['passed'] or reference['cases']!=704:raise ValueError('Selected reference replay failed')
            costs={};work={}
            for line in prefix.with_suffix('.txt').read_text().splitlines():
                entry,calls,steps,seconds=line.split();costs[entry]=float(seconds);work[entry]=[int(calls),int(steps)]
            if expected_work is None:expected_work=work
            if work!=expected_work:raise ValueError('Instruction or call counts changed')
            if len(costs)!=6:raise ValueError('Unexpected selected DSP entry count')
            runs.append({'mode':mode,'trial':trial,'core_wall_seconds':sum(costs.values()),'seconds_by_entry':costs,'reference_byte_exact':True})
            print(mode,trial+1,runs[-1]['core_wall_seconds'],flush=True)
    medians={mode:statistics.median(r['core_wall_seconds'] for r in runs if r['mode']==mode) for mode in ['baseline','candidate']}
    return {'scope':'Five alternating native runs per mode; 704 original-i386 DSP fixtures repeated 32 times, recorded math ABI. Timed core wall duration, not full-synth CPU or a CronoX comparison.',
            'baseline_scope':'Four historically dominant DSP units compiled from the unmodified original lift; other linked units shared with candidate',
            'baseline_units':[103,115,255,323],'runs':runs,'median_core_wall_seconds':medians,
            'median_speedup':medians['baseline']/medians['candidate'],
            'median_time_reduction_percent':100*(1-medians['candidate']/medians['baseline']),
            'calls_and_steps_by_entry':expected_work,'instruction_counts_exact':True,'all_references_byte_exact':True,'passed':True}

if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ['baseline','candidate','original','fixtures','output']:parser.add_argument('--'+name,type=Path,required=True)
    args=parser.parse_args();result=measure(args)
    (args.output/'selected-dsp-cost.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps({k:v for k,v in result.items() if k not in ['runs','calls_and_steps_by_entry']},indent=2))
