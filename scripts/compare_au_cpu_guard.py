#!/usr/bin/env python3
"""Compare installed CP032 and candidate CP038 in separate native AU processes."""
import argparse,hashlib,json,math,plistlib,statistics,subprocess
from pathlib import Path
from compare_output_gain import compare_wave_bytes

def compare(args):
    args.output.mkdir(parents=True,exist_ok=True)
    info=args.baseline/'Contents/Info.plist'
    if not info.is_file():return {'scope':'CP032 versus CP038 native AU CPU comparison','executed':False,'reason':'Référence CP032 absente ; restaurez CP032 avant de valider CP038','passed':False}
    with info.open('rb') as f:baseline=plistlib.load(f)
    if baseline.get('CFBundleIdentifier')!='com.linplug.au.Sophistry' or str(baseline.get('CFBundleVersion'))!='32001':
        return {'scope':'CP032 versus CP038 native AU CPU comparison','executed':False,'reason':'Le composant de référence doit être CP032','passed':False}
    runs=[];pcm_sha=None;reference_wave=None;candidate_sha=None
    for trial in range(5):
        for mode in ['baseline','candidate'] if trial%2==0 else ['candidate','baseline']:
            version='SophistryARM CP-032' if mode=='baseline' else 'SophistryARM CP-038'
            prefix=args.output/f'cpu-{mode}-{trial}'
            command=[str(args.probe),'--bundle',str(getattr(args,mode)),'--state',str(args.state),
                     '--contract',str(args.contract),'--output-prefix',str(prefix),'--channels','2',
                     '--expected-version',version,'--render-block-size','256']
            with prefix.with_suffix('.log').open('w') as log:
                subprocess.run(command,stdout=log,stderr=subprocess.STDOUT,timeout=180,check=True)
            result=json.loads(prefix.with_suffix('.json').read_text())
            if result['error'] or result['engine_error'] or result['expected_checkpoint']!=version:
                raise ValueError('AU CPU comparison instance failed validation')
            cpu=result['render_thread_cpu_seconds'];wall=result['render_call_wall_seconds']
            if not all(math.isfinite(v) and v>0 for v in [cpu,wall]) or result['render_frames']!=132300 or result['render_block_size']!=256:
                raise ValueError('Invalid AU timing observation')
            wave=prefix.with_suffix('.wav');data=wave.read_bytes();digest=hashlib.sha256(data).hexdigest()
            if mode=='baseline':
                if reference_wave is None:reference_wave=data;pcm_sha=digest
                if data!=reference_wave:raise ValueError('CP032 reference audio differs between runs')
            else:
                if reference_wave is None or not compare_wave_bytes(reference_wave,data,6.0)['passed']:
                    raise ValueError('CP032/CP038 CPU comparison audio differs from requested +6 dB compensation')
                if candidate_sha is None:candidate_sha=digest
                if candidate_sha!=digest:raise ValueError('CP038 audio differs between runs')
            wave.unlink() # Existing preflight WAVs remain in the installation report.
            runs.append({'checkpoint':version,'trial':trial,'render_thread_cpu_seconds':cpu,
                         'render_call_wall_seconds':wall,'maximum_render_call_seconds':result['maximum_render_call_seconds'],
                         'render_calls':result['render_calls'],'audio_exact_after_requested_gain':True})
            print(f'CPU AU {mode}, passage {trial+1}/5 : {cpu:.6f} s de CPU pour 3 s audio',flush=True)
    medians={mode:statistics.median(r['render_thread_cpu_seconds'] for r in runs if r['checkpoint']==version)
             for mode,version in [('baseline','SophistryARM CP-032'),('candidate','SophistryARM CP-038')]}
    return {'scope':'Five alternating isolated-process native AU runs per checkpoint; public Lightgarden preset, one note, 44100 Hz/256 frames. Not a DAW meter or CronoX benchmark.',
            'executed':True,'runs':runs,'median_render_thread_cpu_seconds':medians,
            'median_cpu_reduction_percent':100*(1-medians['candidate']/medians['baseline']),
            'median_speedup':medians['baseline']/medians['candidate'],'wave_sha256':pcm_sha,
            'candidate_wave_sha256':candidate_sha,'requested_output_gain_db':6.0,
            'all_audio_exact_after_requested_gain':True,'performance_is_installation_gate':True,'candidate_to_cp032_cpu_ratio':medians['candidate']/medians['baseline'],'maximum_allowed_ratio':1.5,'passed':medians['candidate']<=1.5*medians['baseline']}

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ['probe','baseline','candidate','state','contract','output']:
        parser.add_argument('--'+name,type=Path,required=True)
    args=parser.parse_args()
    try:
        result=compare(args)
    except (OSError,ValueError,KeyError,subprocess.SubprocessError) as error:
        result={'scope':'CP032/CP038 native AU CPU installation guard','passed':False,'error':str(error)}
    args.output.mkdir(parents=True,exist_ok=True)
    (args.output/'cpu-comparison.json').write_text(json.dumps(result,indent=2)+'\n')
    if not result['passed']:
        raise SystemExit(result.get('error',result.get('reason','Régression CPU supérieure à 50 % face à CP032 ; candidat non installé')))
    print(f"Comparaison CPU : ratio CP038/CP032 {result['candidate_to_cp032_cpu_ratio']:.3f}, audio conforme à la compensation demandée de +6 dB.",flush=True)

if __name__=='__main__':main()
