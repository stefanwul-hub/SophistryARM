#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>
namespace sophistry {

// Integration in progress: this host does not by itself implement an Audio
// Unit.
struct LegacyEngineConfig {
  std::vector<std::string> assetDirectories;
  bool deterministicTestHost = true;
  bool useLocalMacPreferences = false;
  bool recycleFreedBlocks = false;
  // Optional private input. Passed to the original SysGlo string setter;
  // the original registration check decides whether it is accepted.
  std::string privateRegistration;
  std::size_t guestMemoryBytes = 64u * 1024u * 1024u;
};

class LegacyEngine {
public:
  explicit LegacyEngine(LegacyEngineConfig config);
  ~LegacyEngine();
  LegacyEngine(const LegacyEngine &) = delete;
  LegacyEngine &operator=(const LegacyEngine &) = delete;
  void initialize();
  void restoreChunk(const std::vector<std::uint8_t> &chunk, bool program);
  std::vector<std::uint8_t> saveProgram();
  void setSampleRate(float rate);
  void setBlockSize(std::uint32_t frames);
  void activate();
  void midi(std::uint8_t status, std::uint8_t data1, std::uint8_t data2,
            std::uint32_t delta = 0);
  void process(float *const *outputs, std::uint32_t channels,
               std::uint32_t frames);
  std::uint32_t outputChannels() const;
  bool registrationAccepted() const;
  std::vector<std::uint8_t> objectSnapshot() const;
  std::vector<std::uint8_t> heapSnapshot() const;
  std::vector<std::uint8_t> globalSnapshot() const;
  std::string diagnosticJson() const;

private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};
} // namespace sophistry
