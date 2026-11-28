#!/usr/bin/env python3
"""Build an isolated translated DSP probe with local Xcode/GCC tools."""
import argparse
import json
from pathlib import Path
import shutil
import subprocess
import sys


def build(output, compiler=None, kind='planar-sum'):
    root = Path(__file__).resolve().parents[1]
    if compiler is None:
        if sys.platform == 'darwin':
            compiler = subprocess.check_output(['xcrun', '--find', 'clang++'], text=True).strip()
        else:
            compiler = shutil.which('c++')
    if not compiler:
        raise RuntimeError('A local C++ compiler is required')
    version = subprocess.check_output([compiler, '--version'], text=True)
    flags = ['-std=c++17', '-O2', '-fno-fast-math', '-ffp-contract=off']
    flags += ['-fno-vectorize', '-fno-slp-vectorize'] if 'clang' in version.lower() else ['-fno-tree-vectorize']
    output = output.resolve()
    output.parent.mkdir(parents=True, exist_ok=True)
    sources = {'planar-sum': ('src/OriginalPlanarSum.cpp', 'tests/PlanarSumProbe.cpp'),
               'voice-chunk': ('src/OriginalVoiceChunk.cpp', 'tests/VoiceChunkProbe.cpp'),
               'sample-format': ('src/OriginalSampleFormat.cpp', 'tests/SampleFormatProbe.cpp'),
               'buffered-pcm': ('src/OriginalSampleFormat.cpp', 'src/OriginalBufferedPcm.cpp', 'tests/BufferedPcmProbe.cpp'),
               'sample-cache': ('src/OriginalSampleCache.cpp', 'tests/SampleCacheProbe.cpp'),
               'sample-file': ('src/OriginalSampleCache.cpp', 'src/OriginalSampleFile.cpp', 'src/OriginalSampleFormat.cpp', 'src/OriginalBufferedPcm.cpp', 'src/OriginalVoiceChunk.cpp', 'tests/SampleFileProbe.cpp'),
               'cache-refill': ('src/OriginalSampleCache.cpp', 'src/OriginalSampleFile.cpp', 'src/OriginalCacheRefill.cpp', 'src/OriginalSampleFormat.cpp', 'src/OriginalBufferedPcm.cpp', 'src/OriginalVoiceChunk.cpp', 'tests/CacheRefillProbe.cpp'),
               'cache-lifecycle': ('src/OriginalCacheLifecycle.cpp', 'src/OriginalSampleFormat.cpp', 'tests/CacheLifecycleProbe.cpp'),
               'timer': ('src/OriginalTimer.cpp', 'tests/TimerProbe.cpp'),
               'wave': ('src/OriginalWave.cpp', 'src/OriginalWaveChunks.cpp', 'src/OriginalWaveAdpcm.cpp', 'src/OriginalSampleFormat.cpp', 'src/OriginalBufferedPcm.cpp', 'tests/WaveProbe.cpp'),
               'wave-chunks': ('src/OriginalWaveChunks.cpp', 'tests/WaveChunksProbe.cpp'),
               'wave-adpcm': ('src/OriginalWaveAdpcm.cpp', 'src/OriginalWave.cpp', 'src/OriginalSampleFormat.cpp', 'src/OriginalBufferedPcm.cpp', 'tests/WaveAdpcmProbe.cpp'),
               'file-open': ('src/OriginalFileOpen.cpp', 'src/OriginalCacheLifecycle.cpp', 'src/OriginalWave.cpp', 'src/OriginalSampleFormat.cpp', 'src/OriginalBufferedPcm.cpp', 'tests/FileOpenProbe.cpp'),
               'file-pipeline': ('src/OriginalFileOpen.cpp', 'src/OriginalCacheLifecycle.cpp', 'src/OriginalCacheRefill.cpp', 'src/OriginalSampleFile.cpp', 'src/OriginalSampleCache.cpp', 'src/OriginalVoiceChunk.cpp', 'src/OriginalWave.cpp', 'src/OriginalWaveChunks.cpp', 'src/OriginalWaveAdpcm.cpp', 'src/OriginalSampleFormat.cpp', 'src/OriginalBufferedPcm.cpp', 'tests/FilePipelineProbe.cpp'),
               'file-archive': ('src/OriginalFileArchive.cpp', 'tests/FileArchiveProbe.cpp'),
               'archive-wave': ('src/OriginalFileArchive.cpp', 'src/OriginalWave.cpp', 'src/OriginalWaveChunks.cpp', 'src/OriginalWaveAdpcm.cpp', 'src/OriginalSampleFormat.cpp', 'src/OriginalBufferedPcm.cpp', 'tests/ArchiveWaveProbe.cpp'),
               'byte-file': ('src/OriginalByteFile.cpp', 'tests/ByteFileProbe.cpp'),
               'archive-names': ('src/OriginalArchiveLookup.cpp', 'src/OriginalByteFile.cpp', 'src/OriginalFileArchive.cpp', 'tests/ArchiveNameProbe.cpp'),
               'named-archive-wave': ('src/OriginalArchiveLookup.cpp', 'src/OriginalByteFile.cpp', 'src/OriginalFileArchive.cpp', 'src/OriginalWave.cpp', 'src/OriginalWaveChunks.cpp', 'src/OriginalWaveAdpcm.cpp', 'src/OriginalSampleFormat.cpp', 'src/OriginalBufferedPcm.cpp', 'tests/NamedArchiveWaveProbe.cpp'),
               'soundbank': ('src/OriginalSoundbank.cpp', 'tests/SoundbankProbe.cpp'),
               'property-list': ('src/OriginalPropertyList.cpp', 'src/OriginalPropertyListXml.cpp', 'third_party/tinyxml2/tinyxml2.cpp', 'src/OriginalArchivePropertyList.cpp', 'src/OriginalArchiveOpen.cpp', 'src/OriginalArchiveLookup.cpp', 'src/OriginalByteFile.cpp', 'src/OriginalFileArchive.cpp', 'tests/PropertyListProbe.cpp'),
               'soundbank-archive': ('src/OriginalSoundbank.cpp', 'src/OriginalSoundbankArchive.cpp', 'src/OriginalPropertyList.cpp', 'src/OriginalPropertyListXml.cpp', 'third_party/tinyxml2/tinyxml2.cpp', 'src/OriginalArchivePropertyList.cpp', 'src/OriginalArchiveOpen.cpp', 'src/OriginalArchiveLookup.cpp', 'src/OriginalByteFile.cpp', 'src/OriginalFileArchive.cpp', 'tests/SoundbankArchiveProbe.cpp'),
               'program-voice': ('src/OriginalStateArchive.cpp', 'src/OriginalKeyedState.cpp', 'src/OriginalProgramState.cpp', 'src/OriginalProgramVoice.cpp', 'src/OriginalVoiceChunk.cpp', 'src/OriginalSampleFile.cpp', 'src/OriginalSampleCache.cpp', 'src/OriginalSampleFormat.cpp', 'tests/ProgramVoiceProbe.cpp'),
               'program-samples': ('src/OriginalProgramSamples.cpp', 'src/OriginalProgramState.cpp', 'src/OriginalStateArchive.cpp', 'src/OriginalKeyedState.cpp', 'src/OriginalArchiveOpen.cpp', 'src/OriginalArchiveLookup.cpp', 'src/OriginalByteFile.cpp', 'src/OriginalFileArchive.cpp', 'src/OriginalFileOpen.cpp', 'src/OriginalCacheLifecycle.cpp', 'src/OriginalSampleFormat.cpp', 'src/OriginalWave.cpp', 'src/OriginalWaveChunks.cpp', 'src/OriginalWaveAdpcm.cpp', 'src/OriginalBufferedPcm.cpp', 'tests/ProgramSamplesProbe.cpp'),
               'program-state': ('src/OriginalStateArchive.cpp', 'src/OriginalKeyedState.cpp', 'src/OriginalProgramState.cpp', 'tests/ProgramStateProbe.cpp'),
               'keyed-state': ('src/OriginalStateArchive.cpp', 'src/OriginalKeyedState.cpp', 'tests/KeyedStateProbe.cpp'),
               'state-archive': ('src/OriginalStateArchive.cpp', 'tests/StateArchiveProbe.cpp'),
               'archive-open': ('src/OriginalArchiveOpen.cpp', 'src/OriginalArchiveLookup.cpp', 'src/OriginalByteFile.cpp', 'src/OriginalFileArchive.cpp', 'tests/ArchiveOpenProbe.cpp')}[kind]
    command = [compiler] + flags + [str(root / name) for name in sources] + ['-o', str(output)]
    subprocess.run(command, check=True)
    print(json.dumps({'output': str(output), 'probe': kind, 'compiler': version.splitlines()[0],
                      'flags': flags, 'audio_unit_built': False}, indent=2))


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--output', type=Path, required=True)
    p.add_argument('--compiler')
    p.add_argument('--kind', choices=['planar-sum', 'voice-chunk', 'sample-format', 'buffered-pcm', 'sample-cache', 'sample-file', 'cache-refill', 'cache-lifecycle', 'timer', 'wave', 'wave-chunks', 'wave-adpcm', 'file-open', 'file-pipeline', 'file-archive', 'archive-wave', 'byte-file', 'archive-names', 'named-archive-wave', 'soundbank', 'property-list', 'soundbank-archive', 'state-archive', 'keyed-state', 'program-state', 'program-samples', 'program-voice', 'archive-open'], default='planar-sum')
    a = p.parse_args()
    build(a.output, a.compiler, a.kind)
