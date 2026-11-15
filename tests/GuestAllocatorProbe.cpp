#include "../src/engine/GuestAllocator.h"
#include <iostream>
#include <vector>

using sophistry::GuestAllocator;
static void require(bool value, const char *message) {
  if (!value)
    throw std::runtime_error(message);
}
int main() {
  try {
    GuestAllocator fragmented(0x1000, 0x101000, true);
    auto a = fragmented.allocate(64), b = fragmented.allocate(128);
    auto c = fragmented.allocate(256), guard = fragmented.allocate(32);
    fragmented.release(b);
    fragmented.release(a);
    require(fragmented.allocate(176) == a, "Adjacent spans were not joined");
    fragmented.release(a);
    fragmented.release(c);
    fragmented.release(guard);
    require(!fragmented.reservedBytes() && !fragmented.liveBytes(),
            "Top free span was not reclaimed");
    GuestAllocator exact(0x1000, 0x2000, false);
    auto old = exact.allocate(1);
    exact.release(old);
    require(exact.allocate(1) == old + 16, "Reference bump layout changed");

    // Sizes vary every round: the previous exact-size-only free list exhausted
    // a small arena even though all prior blocks had been released.
    constexpr unsigned rounds = 512, blocks = 32;
    std::vector<unsigned char> memory(0x101000);
    for (unsigned round = 0; round < rounds; ++round) {
      struct Live {
        unsigned address, size;
        unsigned char tag;
      };
      std::vector<Live> live;
      for (unsigned i = 0; i < blocks; ++i) {
        unsigned size = 17 + ((round * 131 + i * 997) % 22000);
        auto address = fragmented.allocate(size);
        for (auto previous : live)
          require(address + size <= previous.address ||
                      previous.address + previous.size <= address,
                  "Live guest blocks overlap");
        const auto tag = static_cast<unsigned char>(1 + i);
        std::fill(memory.begin() + address, memory.begin() + address + size,
                  tag);
        live.push_back({address, size, tag});
      }
      for (unsigned parity = 0; parity < 2; ++parity)
        for (unsigned i = parity; i < blocks; i += 2) {
          auto item = live[i];
          require(std::all_of(memory.begin() + item.address,
                              memory.begin() + item.address + item.size,
                              [&](unsigned char c) { return c == item.tag; }),
                  "Recycling overwrote a live buffer");
          fragmented.release(item.address);
        }
      require(!fragmented.liveBlocks() && !fragmented.reservedBytes(),
              "Guest allocations accumulated between rounds");
    }
    auto whole = fragmented.allocate(900000);
    const auto before = fragmented.liveBytes();
    bool exhausted = false;
    try {
      fragmented.allocate(200000);
    } catch (const std::runtime_error &) {
      exhausted = true;
    }
    require(exhausted && fragmented.liveBytes() == before,
            "Exhaustion damaged a live allocation");
    fragmented.release(whole);
    auto recovered = fragmented.allocate(900000);
    fragmented.release(recovered);
    bool invalid = false;
    try {
      fragmented.release(recovered);
    } catch (const std::runtime_error &) {
      invalid = true;
    }
    require(invalid, "Double release was accepted");
    invalid = false;
    try {
      fragmented.release(0x12345);
    } catch (const std::runtime_error &) {
      invalid = true;
    }
    require(invalid, "Foreign pointer was accepted");
    fragmented.release(0);
    GuestAllocator large(0x800000, 0x40000000 - 0x200000, true);
    std::vector<unsigned> addresses;
    for (unsigned i = 0; i < 24; ++i)
      addresses.push_back(large.allocate(12 * 1024 * 1024));
    require(large.liveBytes() == 288u * 1024u * 1024u,
            "A live instrument exceeding 256 MiB cannot fit");
    for (auto address : addresses)
      large.release(address);
    require(!large.reservedBytes(), "Large sample spans leaked");
    std::cout
        << "{\"passed\":true,\"variable_size_rounds\":" << rounds
        << ",\"variable_size_allocations\":" << rounds * blocks
        << ",\"live_payload_bytes_checked\":true,"
           "\"coalescing_and_splitting\":true,\"reference_layout_retained\":"
           "true,"
           "\"exhaustion_recovery\":true,\"invalid_releases_rejected\":true,"
           "\"extended_arena_live_bytes\":301989888}\n";
    return 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
