#include "LegacyStateReader.h"
#include <limits>
#include <stdexcept>
namespace sophistry {
namespace {
constexpr std::uint32_t PROG=0x50524f47;
std::uint32_t read32(const std::vector<std::uint8_t>& b,std::size_t at,bool little) {
    if(at>b.size() || b.size()-at<4)throw std::runtime_error("Truncated integer");
    std::uint32_t value=0;
    for(unsigned i=0;i<4;++i)value|=std::uint32_t(b[at+i])<<(8*(little?i:3-i));
    return value;
}
void put32(std::vector<std::uint8_t>& b,std::uint32_t n,bool little) {
    for(unsigned i=0;i<4;++i)b.push_back(static_cast<std::uint8_t>(n>>(8*(little?i:3-i))));
}
std::vector<LegacyRecord> parse(const std::vector<std::uint8_t>& b,std::size_t start,
                              std::size_t end,bool little,unsigned depth) {
    if(depth>16)throw std::runtime_error("Excessive PROG nesting");
    std::vector<LegacyRecord> out;
    while(start<end) {
        if(end-start<12)throw std::runtime_error("Truncated record header");
        auto tag=read32(b,start,little),size=read32(b,start+4,little),index=read32(b,start+8,little);
        if(size<12 || size%4 || size>end-start)throw std::runtime_error("Invalid record size");
        LegacyRecord r;r.tag=tag;r.index=index;
        if(tag==PROG)r.children=parse(b,start+12,start+size,little,depth+1);
        else r.payload.assign(b.begin()+start+12,b.begin()+start+size);
        out.push_back(std::move(r));start+=size;
    }
    return out;
}
void append(std::vector<std::uint8_t>& b,const std::vector<LegacyRecord>& records,
            bool little,unsigned depth) {
    if(depth>16)throw std::runtime_error("Excessive PROG nesting");
    for(const auto& r:records) {
        const std::size_t start=b.size();put32(b,r.tag,little);put32(b,0,little);put32(b,r.index,little);
        if(r.tag==PROG) {
            if(!r.payload.empty())throw std::runtime_error("PROG has both children and opaque payload");
            append(b,r.children,little,depth+1);
        } else {
            if(!r.children.empty())throw std::runtime_error("Non-PROG has children");
            b.insert(b.end(),r.payload.begin(),r.payload.end());
        }
        const auto size=b.size()-start;
        if(size>std::numeric_limits<std::uint32_t>::max() || size%4)throw std::runtime_error("Invalid serialized record size");
        for(unsigned i=0;i<4;++i)b[start+4+i]=static_cast<std::uint8_t>(size>>(8*(little?i:3-i)));
    }
}
}
LegacyState read_legacy_state(const std::vector<std::uint8_t>& b) {
    if(b.size()<12)throw std::runtime_error("Empty or truncated legacy state");
    auto plausible=[&](bool little){auto n=read32(b,4,little);return n>=12 && n%4==0 && n<=b.size();};
    bool le=plausible(true),be=plausible(false);
    if(le==be)throw std::runtime_error("Ambiguous or invalid byte order");
    LegacyState state;state.little_endian=le;state.records=parse(b,0,b.size(),le,0);return state;
}
std::vector<std::uint8_t> write_legacy_state(const LegacyState& state) {
    std::vector<std::uint8_t> out;append(out,state.records,state.little_endian,0);return out;
}
}
