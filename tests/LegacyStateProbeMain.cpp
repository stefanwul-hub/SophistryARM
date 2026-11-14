#include "LegacyStateReader.h"
#include <cstdio>
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>
static std::size_t leaves(const std::vector<sophistry::LegacyRecord>& records) {
    std::size_t n=0;for(auto& r:records)n+=r.tag==0x50524f47?leaves(r.children):1;return n;
}
int main(int argc,char** argv) {
    try {
        if(argc<2)throw std::runtime_error("Usage: LegacyStateProbe chunk.bin [chunk2.bin...]");
        for(int k=1;k<argc;++k) {
            std::ifstream f(argv[k],std::ios::binary);
            std::vector<std::uint8_t> b((std::istreambuf_iterator<char>(f)),{});
            if(!f || b.empty())throw std::runtime_error("Cannot read fixture");
            auto state=sophistry::read_legacy_state(b);auto encoded=sophistry::write_legacy_state(state);
            if(encoded!=b)throw std::runtime_error("Round-trip mismatch");
            // A corrupted declared size must be rejected.
            auto corrupt=b;corrupt[4]=0;corrupt[5]=0;corrupt[6]=0;corrupt[7]=0;
            bool rejected=false;try{(void)sophistry::read_legacy_state(corrupt);}catch(const std::exception&){rejected=true;}
            if(!rejected)throw std::runtime_error("Invalid length accepted");
            // Re-encode numeric headers in big endian and parse again; opaque
            // payload bytes remain untouched, so this tests headers only.
            auto swapped=state;swapped.little_endian=!state.little_endian;
            auto reversed=sophistry::write_legacy_state(swapped);auto read=sophistry::read_legacy_state(reversed);
            if(read.records.size()!=state.records.size() || sophistry::write_legacy_state(read)!=reversed)throw std::runtime_error("Header byte-order round trip failed");
            std::printf("{\"bytes\":%zu,\"top_level_records\":%zu,\"leaf_records\":%zu,\"byte_exact_round_trip\":true,\"invalid_size_rejected\":true,\"numeric_header_endianness_tested\":true,\"dsp_restoration_tested\":false}\n",b.size(),state.records.size(),leaves(state.records));
        }
        return 0;
    } catch(const std::exception& e){std::fprintf(stderr,"%s\n",e.what());return 1;}
}
