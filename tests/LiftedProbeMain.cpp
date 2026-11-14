// Standalone native replay of original i386 reference fixtures.
// Uses recorded host math by default to isolate lifted machine semantics.
#include "LifterRuntime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct Cursor {
    const SlU8* bytes;SlSize size,at=0;bool failed=false;
    const SlU8* take(SlSize n){if(at>size||n>size-at){failed=true;return nullptr;}auto* p=bytes+at;at+=n;return p;}
    SlU32 word(){const SlU8* p=take(4);SlU32 n=0;if(p)memcpy(&n,p,4);return n;}
};
struct Segment {SlU32 address,size;const SlU8* data;};
struct Host {
    SlU32 output[2]={0x240000,0x250000};
    const SlU8* math_trace=nullptr;SlU32 math_count=0,math_at=0;
    bool native_math=false;SlU64 total_math=0;
};
static SlU32 read32(SlCpu* c,SlU32 at){SlU32 n=0;if(sl_mem_read(c,at,&n,4))c->fault=6;return n;}
static void write32(SlCpu* c,SlU32 at,SlU32 n){if(sl_mem_write(c,at,&n,4))c->fault=6;}
static void callback(void* user,SlU32 address,SlCpu* c) {
    auto& h=*static_cast<Host*>(user);SlU32 sp=0;
    if(sl_reg_read(c,0x10,&sp,4)){c->fault=6;return;}
    if(address==0x103311) {
        if(h.math_at>=h.math_count){c->fault=7;return;}
        SlU64 arg_bits=0,expected_bits=0,return_bits=0;
        if(sl_mem_read(c,sp+4,&arg_bits,8)){c->fault=6;return;}
        memcpy(&expected_bits,h.math_trace+h.math_at*16,8);
        memcpy(&return_bits,h.math_trace+h.math_at*16+8,8);
        if(arg_bits!=expected_bits){c->fault=7;return;}
        double value=0,result=0;memcpy(&value,&arg_bits,8);memcpy(&result,&return_bits,8);
        if(h.native_math)result=log10(value);
        sl_push_double_return(c,result);++h.math_at;++h.total_math;
    } else if(address==0x500000||address==0x500010||address==0x500030||address==0x500040) {
        bool output=address==0x500000||address==0x500030;
        write32(c,read32(c,sp+8),output?h.output[0]:0x220000);
        if(address==0x500030||address==0x500040)write32(c,read32(c,sp+12),output?h.output[1]:0x230000);
    }
    SlU32 pc=read32(c,sp);sp+=4;
    if(sl_reg_write(c,0x10,&sp,4))c->fault=6;
    sl_set_pc(c,pc);
}
static SlU8* load(const char* path,SlSize* length) {
    FILE* f=fopen(path,"rb");if(!f){perror(path);return nullptr;}
    if(fseek(f,0,SEEK_END)){fclose(f);return nullptr;}long size=ftell(f);
    if(size<0||size>128*1024*1024||fseek(f,0,SEEK_SET)){fclose(f);return nullptr;}
    auto* p=static_cast<SlU8*>(malloc(static_cast<SlSize>(size)));
    if(!p||fread(p,1,size,f)!=static_cast<SlSize>(size)){free(p);fclose(f);return nullptr;}
    fclose(f);*length=static_cast<SlSize>(size);return p;
}
int main(int argc,char** argv) {
    if(argc<3||argc>4){fprintf(stderr,"Usage: LiftedProbe original-i386 fixtures [--native-math]\n");return 2;}
    SlSize image_size=0,fixture_size=0;SlU8* image=load(argv[1],&image_size);SlU8* fixture=load(argv[2],&fixture_size);
    if(!image||!fixture){free(image);free(fixture);return 2;}
    SlCpu* c=sl_create(0x800000);if(!c){free(image);free(fixture);return 2;}
    if(sl_mem_write(c,0,image,image_size)){fprintf(stderr,"Image does not fit\n");return 2;}
    Host host;if(argc==4){if(strcmp(argv[3],"--native-math")){fprintf(stderr,"Unknown option\n");return 2;}host.native_math=true;}
    const SlU32 hook_addresses[]={0x500000u,0x500010u,0x500020u,0x500030u,0x500040u,0x103311u};
    for(SlU32 a:hook_addresses)if(sl_hook(c,a,callback,&host))return 2;
    Cursor cur{fixture,fixture_size};const SlU8* magic=cur.take(8);
    if(!magic||memcmp(magic,"SLFT0002",8)){fprintf(stderr,"Invalid fixture version\n");return 2;}
    SlU32 count=cur.word();if(count>100000){fprintf(stderr,"Invalid case count\n");return 2;}
    SlU64 checked=0,mismatches=0;
    for(SlU32 test=0;test<count;++test) {
        SlU32 entry=cur.word(),argc_case=cur.word(),segments=cur.word(),args[16]={};
        if(argc_case>16||segments>64){cur.failed=true;break;}
        for(SlU32 i=0;i<argc_case;++i)args[i]=cur.word();
        for(SlU32 i=0;i<segments;++i){SlU32 a=cur.word(),n=cur.word();const SlU8* p=cur.take(n);if(!p||sl_mem_write(c,a,p,n)){cur.failed=true;break;}}
        SlU32 expected_count=cur.word();Segment expected[16]={};
        if(expected_count<2||expected_count>16){cur.failed=true;break;}
        for(SlU32 i=0;i<expected_count;++i){expected[i].address=cur.word();expected[i].size=cur.word();expected[i].data=cur.take(expected[i].size);}
        host.output[0]=expected[0].address;host.output[1]=expected[1].address;
        host.math_count=cur.word();host.math_at=0;
        if(host.math_count>1000000){cur.failed=true;break;}host.math_trace=cur.take(SlSize(host.math_count)*16);
        if(cur.failed)break;
        SlU32 sp=0x70f000;write32(c,sp,0x500100);
        for(SlU32 i=0;i<argc_case;++i)write32(c,sp+4+i*4,args[i]);
        sl_reg_write(c,0x10,&sp,4);
        if(sl_run(c,entry,0x500100,30000000)||host.math_at!=host.math_count){fprintf(stderr,"Case %u fault %u at 0x%x; math %u/%u\n",test,sl_get_fault(c),sl_get_pc(c),host.math_at,host.math_count);return 1;}
        for(SlU32 i=0;i<expected_count;++i) {
            const auto& s=expected[i];if(s.address>c->memory_size||s.size>c->memory_size-s.address){cur.failed=true;break;}
            for(SlU32 b=0;b<s.size;++b){if(c->memory[s.address+b]!=s.data[b]){if(mismatches<8)fprintf(stderr,"Case %u mismatch at 0x%x: %02x != %02x\n",test,s.address+b,c->memory[s.address+b],s.data[b]);++mismatches;}++checked;}
        }
        if(cur.failed)break;
    }
    bool valid=!cur.failed&&cur.at==cur.size;
    printf("{\"scope\":\"selected statically lifted DSP\",\"cases\":%u,\"compared_bytes\":%llu,\"byte_mismatches\":%llu,\"math_calls\":%llu,\"math_mode\":\"%s\",\"instruction_addresses_executed\":%u,\"fixture_valid\":%s,\"passed\":%s,\"full_synth_tested\":false}\n",count,(unsigned long long)checked,(unsigned long long)mismatches,(unsigned long long)host.total_math,host.native_math?"host libm":"recorded ABI responses",sl_coverage_count(c),valid?"true":"false",valid&&!mismatches?"true":"false");
    sl_destroy(c);free(image);free(fixture);return valid&&!mismatches?0:1;
}
