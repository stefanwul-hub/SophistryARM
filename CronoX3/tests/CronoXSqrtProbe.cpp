#include "../src/lifter/LifterRuntime.h"
#include <cstdio>
// Isolated arithmetic probe: this dispatcher is never used by the plugin.
int sl_execute(SlCpu&,SlU32,SlU32,SlU64){return 3;}
int main() {
    SlU64 input,expected;unsigned count=0;
    while(std::fread(&input,8,1,stdin)==1) {
        if(std::fread(&expected,8,1,stdin)!=1)return 2;
        SlU64 actual=static_cast<SlU64>(sl_sqrt_f64(input));
        if(actual!=expected) {
            std::fprintf(stderr,"SQRTSD case %u differs: %016llx / %016llx\n",count,
                         (unsigned long long)actual,(unsigned long long)expected);return 1;
        }
        ++count;
    }
    std::printf("{\"scope\":\"CronoX SQRTSD helper versus original machine instruction fixtures\",\"cases\":%u,\"mismatches\":0,\"passed\":true}\n",count);
    return 0;
}
