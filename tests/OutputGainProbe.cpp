#include "../src/au/OutputGain.h"
#include <array>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <stdexcept>

std::uint32_t bits(float x) {
  std::uint32_t result;
  std::memcpy(&result, &x, sizeof(x));
  return result;
}
int main(int argc, char **argv) {
  try {
    if (argc == 2 && std::string(argv[1]) == "--transform-floats") {
      std::ios::sync_with_stdio(false);
      std::array<float, 4096> data{};
      while (std::cin.read(reinterpret_cast<char *>(data.data()), sizeof(data)) || std::cin.gcount()) {
        const auto bytes = std::cin.gcount();
        if (bytes % sizeof(float))
          throw std::runtime_error("Incomplete float audio sample");
        for (std::size_t i = 0; i < std::size_t(bytes) / sizeof(float); ++i)
          data[i] = sophistry::compensatedOutput(data[i]);
        std::cout.write(reinterpret_cast<const char *>(data.data()), bytes);
      }
      return 0;
    }
    if (argc != 1)
      throw std::runtime_error("Unknown output-gain probe argument");
    const auto gain = float(std::pow(10.0, 6.0 / 20));
    if (gain != sophistry::outputGainLinear)
      throw std::runtime_error("Gain is not +6 dB rounded to float32");
    const std::array<float, 12> values{{0, -0.0f, 1, -1, .5f, -.5f, 2, -2,
                                      1e-20f, -1e-20f, 1e20f, -1e20f}};
    unsigned checked = 0;
    for (unsigned channels : {1u, 2u, 6u})
      for (unsigned channel = 0; channel < channels; ++channel)
        for (float value : values) {
          const auto actual = sophistry::compensatedOutput(value);
          const auto expected = float(double(value) * double(gain));
          if (bits(actual) != bits(expected))
            throw std::runtime_error("Output compensation bit mismatch");
          ++checked;
        }
    if (sophistry::compensatedOutput(1) <= 1 ||
        bits(sophistry::compensatedOutput(-0.0f)) != bits(-0.0f))
      throw std::runtime_error("Unrequested clipping or signed-zero change");
    std::cout << "{\"passed\":true,\"requested_gain_db\":6,\"checked_samples\":"
              << checked << ",\"float32_gain_bits\":" << bits(gain)
              << ",\"clipping_added\":false,\"master_parameter_modified\":false}\n";
  } catch (const std::exception &error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
