#!/usr/bin/env python3
"""Summarize numeric AU traces without exporting the private shared AU state."""
import json
from pathlib import Path
import sys


def weighted_cpu(rows, start, end):
    selected = [r for r in rows if r['start_seconds'] >= start and r['end_seconds'] <= end]
    duration = sum(r['end_seconds'] - r['start_seconds'] for r in selected)
    return sum(r['thread_cpu_seconds'] for r in selected) / duration if duration else None


def describe(data):
    rows = data.get('trace', [])
    if not data.get('measurement_valid') or not rows:
        return {'valid': False, 'error': data.get('error', 'Missing valid trace')}
    off = data['note_off_seconds']
    described = {'valid': True, 'subtype': data['subtype'],
                 'cpu_during_chord': weighted_cpu(rows, data['note_on_seconds'] + .1, off),
                 'cpu_last_three_seconds': weighted_cpu(rows, data['audio_seconds'] - 3, data['audio_seconds']),
                 'audio_seconds': data['audio_seconds'], 'peak': data['peak'],
                 'reverb_bypassed': data['reverb_bypassed'], 'after_last_signal': {}}
    for db in (-60, -90, -120):
        threshold = 10 ** (db / 20)
        last = max((r['end_seconds'] for r in rows if r['peak'] > threshold), default=0)
        has_later_silence = last < rows[-1]['start_seconds']
        described['after_last_signal'][str(db)] = {
            'threshold_dbfs': db, 'last_above_threshold_seconds': last,
            'last_above_threshold_after_note_off_seconds': max(0, last - off),
            'below_threshold_until_end': has_later_silence,
            'cpu_next_two_seconds': weighted_cpu(rows, last, min(last + 2, data['audio_seconds'])) if has_later_silence else None,
            'cpu_two_to_five_seconds_later': weighted_cpu(rows, last + 2, min(last + 5, data['audio_seconds'])) if has_later_silence else None,
            'cpu_five_to_eight_seconds_later': weighted_cpu(rows, last + 5, min(last + 8, data['audio_seconds'])) if has_later_silence else None,
        }
    described['all_last_second_blocks_exact_zero'] = all(r['exact_zero_blocks'] == r['blocks'] for r in rows if r['start_seconds'] >= data['audio_seconds'] - 1)
    voices = [r['voices'] for r in rows if 'voices' in r]
    if voices:
        described['voices_last_observation'] = voices[-1]
        described['voice_counters_consistent_throughout'] = all(v.get('counters_consistent') for v in voices)
    return described


def summarize(folder):
    names = ('original-reverb', 'arm-reverb', 'arm-bypass', 'original-bypass')
    summary = {'diagnostic': 'RV002', 'cpu_problem_resolved': False,
               'scope': 'Same AU bank, notes and 44.1 kHz/256, separate in-process Intel/Rosetta and ARM hosts; no editor or audio device',
               'ratios_are_render_cpu_per_audio_second_not_live_meter_percent': True,
               'trials': {}, 'all_four_measurements_valid': True}
    preparation = folder / 'preparation.json'
    if preparation.exists():
        try:
            prepared = json.loads(preparation.read_text())
            summary['preparation'] = {k: prepared[k] for k in ('diagnostic', 'measurement_valid', 'stage', 'preset_filename', 'fxp_header', 'error') if k in prepared}
            if not prepared.get('measurement_valid'):
                summary['all_four_measurements_valid'] = False
                summary['measurements_not_started'] = True
                return summary
        except (OSError, ValueError, TypeError):
            summary['preparation_report_unreadable'] = True
    for name in names:
        p = folder / (name + '.json')
        try:
            data = json.loads(p.read_text())
            summary['trials'][name] = describe(data)
        except (OSError, ValueError, KeyError, TypeError) as e:
            summary['trials'][name] = {'valid': False, 'error': str(e)}
        summary['all_four_measurements_valid'] &= summary['trials'][name]['valid']
    if summary['all_four_measurements_valid']:
        trials = summary['trials']
        banks = [json.loads((folder / (n + '.json')).read_text()).get('input_bank_sha256') for n in names]
        summary['all_input_banks_identical'] = bool(banks[0]) and len(set(banks)) == 1
        summary['all_four_measurements_valid'] &= summary['all_input_banks_identical']
        if not summary['all_four_measurements_valid']:
            return summary
        original = trials['original-reverb']['cpu_during_chord']
        native = trials['arm-reverb']['cpu_during_chord']
        summary['arm_over_original_cpu_during_chord'] = native / original if original else None
        summary['note'] = 'Different implementations and Rosetta are included in these costs; this does not identify a cause by itself.'
    return summary


if __name__ == '__main__':
    folder = Path(sys.argv[1])
    result = summarize(folder)
    (folder / 'resume.json').write_text(json.dumps(result, indent=2, allow_nan=False) + '\n')
    if result.get('measurements_not_started'):
        preparation = result['preparation']
        print('RV002 : arrêt pendant la préparation — ' + preparation.get('stage', 'chargement du preset') + ' : ' + preparation.get('error', 'voir preparation.json'))
    else:
        print('RV002 : quatre mesures valides.' if result['all_four_measurements_valid'] else 'RV002 : mesures incomplètes, voir les fichiers JSON et les journaux.')
