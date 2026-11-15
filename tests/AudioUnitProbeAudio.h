#pragma once
// Shared, byte-stable stereo WAV renderer used by local and remote AU probes.
#include <AudioToolbox/AudioToolbox.h>
#import <Foundation/Foundation.h>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <vector>

static void put16(std::ofstream &out, UInt32 v) {
  char b[] = {char(v), char(v >> 8)};
  out.write(b, 2);
}
static void put32(std::ofstream &out, UInt32 v) {
  char b[] = {char(v), char(v >> 8), char(v >> 16), char(v >> 24)};
  out.write(b, 4);
}
static double renderAudio(AudioUnit unit, NSString *path, UInt32 &completed,
                          OSStatus &result) {
  constexpr UInt32 total = 132300;
  float left[512]{}, right[512]{};
  struct {
    UInt32 count;
    AudioBuffer buffers[2];
  } storage{};
  auto *abl = reinterpret_cast<AudioBufferList *>(&storage);
  abl->mNumberBuffers = 2;
  std::vector<float> pcm(total * 2);
  double peak = 0;
  result = MusicDeviceMIDIEvent(unit, 0x90, 60, 100, 0);
  for (UInt32 at = 0; at < total && !result; at += 512) {
    UInt32 n = std::min(UInt32(512), total - at);
    if (at <= 88200 && 88200 < at + n)
      result = MusicDeviceMIDIEvent(unit, 0x80, 60, 0, 88200 - at);
    abl->mBuffers[0] = {1, n * 4, left};
    abl->mBuffers[1] = {1, n * 4, right};
    AudioTimeStamp timestamp{};
    timestamp.mSampleTime = at;
    timestamp.mFlags = kAudioTimeStampSampleTimeValid;
    AudioUnitRenderActionFlags flags = 0;
    if (!result)
      result = AudioUnitRender(unit, &flags, &timestamp, 0, n, abl);
    if (result)
      break;
    for (UInt32 c = 0; c < 2; ++c) {
      const auto *values = static_cast<const float *>(abl->mBuffers[c].mData);
      if (!values || abl->mBuffers[c].mDataByteSize < n * 4) {
        result = -50;
        break;
      }
      for (UInt32 i = 0; i < n; ++i) {
        if (!std::isfinite(values[i])) {
          result = -50;
          break;
        }
        pcm[(at + i) * 2 + c] = values[i];
        peak = std::max(peak, std::fabs(double(values[i])));
      }
    }
    if (!result)
      completed += n;
  }
  if (!result) {
    std::ofstream out(path.fileSystemRepresentation, std::ios::binary);
    out.write("RIFF", 4);
    put32(out, 36 + total * 8);
    out.write("WAVEfmt ", 8);
    put32(out, 16);
    put16(out, 3);
    put16(out, 2);
    put32(out, 44100);
    put32(out, 44100 * 8);
    put16(out, 8);
    put16(out, 32);
    out.write("data", 4);
    put32(out, total * 8);
    out.write(reinterpret_cast<const char *>(pcm.data()), pcm.size() * 4);
    if (!out)
      result = -50;
  }
  return peak;
}
