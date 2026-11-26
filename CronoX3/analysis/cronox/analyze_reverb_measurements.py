#!/usr/bin/env python3
"""Summarize RV003 numeric measurements without exporting raw private reports.

Use process CPU: this report's Intel/Rosetta thread clock is inconsistent with
both process CPU and render elapsed time. Do not report its automatic 220x ratio.
"""
import argparse
import hashlib
import json
from pathlib import Path
import statistics


def window(data, begin, end):
    rows = [r for r in data['trace'] if r['start_seconds'] >= begin and r['end_seconds'] <= end]
    seconds = sum(r['end_seconds'] - r['start_seconds'] for r in rows)
    return {
        'begin_audio_seconds': begin, 'end_audio_seconds': end,
        'process_cpu_ratio': sum(r['process_cpu_seconds'] for r in rows) / seconds,
        'thread_cpu_ratio': sum(r['thread_cpu_seconds'] for r in rows) / seconds,
        'render_elapsed_ratio': sum(r['render_wall_seconds'] for r in rows) / seconds,
        'peak': max(r['peak'] for r in rows),
    }


def analyze(folder):
    names = ['original-reverb', 'arm-reverb', 'original-bypass', 'arm-bypass']
    trials = {n: json.loads((folder / (n + '.json')).read_text()) for n in names}
    assert all(d['measurement_valid'] for d in trials.values())
    assert len({d['input_bank_sha256'] for d in trials.values()}) == 1
    assert len({d['asset_manifest_sha256'] for d in trials.values()}) == 1
    result = {
        'diagnostic': 'RV003', 'preset': 'Breath And Butter',
        'scope': 'Offline AU hosts at real-time cadence, 44.1 kHz / 256; process CPU per audio second, not the Live meter',
        'same_input_bank_and_sample_manifest': True,
        'cpu_measurement_used': 'CLOCK_PROCESS_CPUTIME_ID',
        'intel_thread_clock_not_used_for_cross_architecture_ratio': True,
        'thread_clock_limitation': 'Intel/Rosetta thread time is about 42x lower than process CPU and render elapsed; an OS-wide cause is not established by this report',
        'trials': {}, 'cpu_issue_resolved': False, 'raw_state_or_private_report_published': False,
    }
    for name, data in trials.items():
        rows = data['trace']
        voice_zero = next((r['end_seconds'] for r in rows if r['end_seconds'] > data['note_off_seconds'] and 'voices' in r and not r['voices']['occupied']), None)
        result['trials'][name] = {
            'chord': window(data, .35, 1.2),
            'late_tail': window(data, 10, 12),
            'idle': window(data, 20, 23),
            'last_nonzero_interval_end': max((r['end_seconds'] for r in rows if r['exact_zero_blocks'] != r['blocks']), default=0),
            'first_zero_occupied_voices_after_note_off': voice_zero,
            'voice_counters_consistent': all(r['voices']['counters_consistent'] for r in rows if 'voices' in r),
            'peak': data['peak'],
        }
    t = result['trials']
    result['chord_arm_over_intel_process_cpu'] = t['arm-reverb']['chord']['process_cpu_ratio'] / t['original-reverb']['chord']['process_cpu_ratio']
    result['late_tail_arm_over_intel_process_cpu'] = t['arm-reverb']['late_tail']['process_cpu_ratio'] / t['original-reverb']['late_tail']['process_cpu_ratio']
    result['same_last_nonzero_interval_with_reverb'] = t['arm-reverb']['last_nonzero_interval_end'] == t['original-reverb']['last_nonzero_interval_end']
    result['same_last_nonzero_interval_without_reverb'] = t['arm-bypass']['last_nonzero_interval_end'] == t['original-bypass']['last_nonzero_interval_end']
    result['conclusion'] = 'This three-note case retires its voices; expensive translated reverb calculations account for most of the late CPU load. Do not shorten tails or cap voices as a fix.'
    return result, trials


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('report_folder', type=Path)
    parser.add_argument('--json', type=Path, required=True)
    parser.add_argument('--plot', type=Path)
    args = parser.parse_args()
    result, trials = analyze(args.report_folder)
    args.json.parent.mkdir(parents=True, exist_ok=True)
    args.json.write_text(json.dumps(result, indent=2) + '\n')
    if args.plot:
        import matplotlib
        matplotlib.use('Agg')
        import matplotlib.pyplot as plt
        fig, ax = plt.subplots(figsize=(10, 4.5), constrained_layout=True)
        for name, title, color, style in [
            ('arm-reverb', 'ARM, réverbération active', '#b5302d', '-'),
            ('arm-bypass', 'ARM, réverbération coupée', '#b5302d', '--'),
            ('original-reverb', 'Intel, réverbération active', '#2166ac', '-'),
            ('original-bypass', 'Intel, réverbération coupée', '#2166ac', '--')]:
            data = trials[name]
            times = [(r['start_seconds'] + r['end_seconds']) / 2 for r in data['trace']]
            values = [100 * r['process_cpu_seconds'] / (r['end_seconds'] - r['start_seconds']) for r in data['trace']]
            ax.plot(times, values, color=color, linestyle=style, linewidth=1.3, label=title)
        ax.axvline(2.07238095238, color='#777777', alpha=.6, linewidth=1)
        ax.text(2.2, 64, 'Voix libérées (ARM)', fontsize=8)
        ax.axvline(16.8751020408, color='#777777', alpha=.6, linewidth=1)
        ax.text(17.05, 30, 'Fin de la sortie non nulle\ndans les deux versions', fontsize=8)
        ax.set(xlim=(0, 32), ylim=(0, 70), xlabel='Temps audio (secondes)', ylabel='CPU du processus (% d’un cœur)',
               title='Breath And Butter — comparaison AU hors DAW, 44,1 kHz / 256')
        ax.grid(alpha=.18)
        ax.legend(loc='upper right', fontsize=8)
        fig.savefig(args.plot, dpi=160)
        plt.close(fig)
    print(json.dumps({k: result[k] for k in ['chord_arm_over_intel_process_cpu', 'late_tail_arm_over_intel_process_cpu', 'same_last_nonzero_interval_with_reverb']}))


if __name__ == '__main__':
    main()
