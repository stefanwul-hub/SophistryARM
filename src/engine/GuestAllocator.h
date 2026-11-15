#pragma once
#include <algorithm>
#include <cstdint>
#include <iterator>
#include <map>
#include <stdexcept>
#include <string>

namespace sophistry {

// Guest addresses never move. The deterministic reference mode keeps its
// historical bump layout; the plugin reuses, splits and coalesces free spans.
class GuestAllocator {
  using U32 = std::uint32_t;
  using U64 = std::uint64_t;
  struct Block {
    U32 requested, capacity;
  };
  U32 begin_, end_, cursor_, highWater_;
  bool recycle_;
  std::map<U32, Block> live_;
  std::map<U32, U32> freeAddress_;
  std::multimap<U32, U32> freeSize_;
  U64 liveBytes_ = 0, liveCapacity_ = 0, reused_ = 0;

  void eraseFree(std::map<U32, U32>::iterator entry) {
    auto range = freeSize_.equal_range(entry->second);
    auto found = range.first;
    while (found != range.second && found->second != entry->first)
      ++found;
    if (found == range.second)
      throw std::logic_error("Guest free span index mismatch");
    freeSize_.erase(found);
    freeAddress_.erase(entry);
  }
  void insertFree(U32 address, U32 size) {
    freeAddress_.emplace(address, size);
    freeSize_.emplace(size, address);
  }

public:
  GuestAllocator(U32 begin, U32 end, bool recycle)
      : begin_(begin), end_(end), cursor_(begin), highWater_(begin),
        recycle_(recycle) {
    if (begin >= end || (begin & 15))
      throw std::runtime_error("Invalid guest allocation arena");
  }
  U32 allocate(U32 requested) {
    if (requested > 0x2000000)
      throw std::runtime_error("Guest allocation exceeds limit");
    const U32 size = (std::max(requested, U32(1)) + 15) & ~U32(15);
    U32 address = 0;
    if (recycle_) {
      const auto found = freeSize_.lower_bound(size);
      if (found != freeSize_.end()) {
        const U32 available = found->first;
        address = found->second;
        eraseFree(freeAddress_.find(address));
        if (available > size)
          insertFree(address + size, available - size);
        ++reused_;
      }
    }
    if (!address) {
      if (U64(cursor_) + size + 16 > end_)
        throw std::runtime_error("Guest sample memory exhausted: requested=" +
                                 std::to_string(requested) +
                                 " live=" + std::to_string(liveBytes_) +
                                 " capacity=" + std::to_string(end_ - begin_));
      address = cursor_;
      cursor_ += size;
      highWater_ = std::max(highWater_, cursor_);
    }
    if (!live_.emplace(address, Block{requested, size}).second)
      throw std::logic_error("Overlapping guest allocation");
    liveBytes_ += requested;
    liveCapacity_ += size;
    return address;
  }
  U32 requestedBytes(U32 address) const {
    auto found = live_.find(address);
    if (found == live_.end())
      throw std::runtime_error("Invalid guest allocation");
    return found->second.requested;
  }
  void release(U32 address) {
    if (!address)
      return;
    const auto found = live_.find(address);
    if (found == live_.end())
      throw std::runtime_error("Invalid guest allocation release");
    U32 size = found->second.capacity;
    liveBytes_ -= found->second.requested;
    liveCapacity_ -= size;
    live_.erase(found);
    if (!recycle_)
      return;
    auto next = freeAddress_.lower_bound(address);
    if (next != freeAddress_.begin()) {
      auto previous = std::prev(next);
      if (U64(previous->first) + previous->second == address) {
        address = previous->first;
        size += previous->second;
        eraseFree(previous);
      }
    }
    next = freeAddress_.lower_bound(address);
    if (next != freeAddress_.end() && U64(address) + size == next->first) {
      size += next->second;
      eraseFree(next);
    }
    if (U64(address) + size == cursor_)
      cursor_ = address;
    else
      insertFree(address, size);
  }
  U32 cursor() const { return cursor_; }
  U32 reservedBytes() const { return cursor_ - begin_; }
  U32 highWaterBytes() const { return highWater_ - begin_; }
  U32 capacityBytes() const { return end_ - begin_; }
  U64 liveBytes() const { return liveBytes_; }
  U64 liveCapacityBytes() const { return liveCapacity_; }
  std::size_t liveBlocks() const { return live_.size(); }
  U64 reusedBlocks() const { return reused_; }
  U64 freeBytes() const {
    U64 result = 0;
    for (const auto &entry : freeAddress_)
      result += entry.second;
    return result;
  }
  U32 largestFreeBytes() const {
    return freeSize_.empty() ? 0 : freeSize_.rbegin()->first;
  }
};
} // namespace sophistry
