// Architectural state must be committed even at an interior stop or a fault.
#include "LifterRuntime.h"
#include <stdio.h>
#include <string.h>

static void put32(SlU8* p,SlU32 value){memcpy(p,&value,4);}
static SlU32 get32(const SlU8* p){SlU32 value;memcpy(&value,p,4);return value;}
int main(int argc,char** argv){
    if(argc!=2)return 2;
    SlCpu* c=sl_create(0x800000);if(!c)return 2;
    FILE* image=fopen(argv[1],"rb");if(!image)return 2;
    const SlSize bytes=fread(c->memory,1,c->memory_size,image);
    const bool loaded=bytes&&!ferror(image)&&feof(image);fclose(image);
    if(!loaded)return 2;
    struct Case{SlU32 stop;SlU64 limit;bool badLoad;SlU32 fault,pc;SlU64 steps;SlU32 coverage;bool eaxChanged,stored;};
    const Case cases[]={
        {0x184d4,20,false,0,0x184d4,0,0,false,false},
        {0x184d7,20,false,0,0x184d7,1,1,true,false},
        {0x184db,20,false,0,0x184db,2,2,true,true},
        {0x500100,0,false,4,0x184d4,1,1,false,false},
        {0x500100,1,false,4,0x184d7,2,2,true,false},
        {0x500100,20,true,1,0x184d7,1,1,true,false}
    };
    unsigned tested=0;
    for(const auto& test:cases){
        SlU8 expected[sizeof(c->reg)]={};memset(expected,0xa5,32);memset(expected+0x200,0x5a,16);
        const SlU32 sp=0x70f000,source=test.badLoad?SlU32(c->memory_size-8):0x210000;
        put32(expected+0x10,sp);put32(expected+0x18,source);
        memcpy(c->reg,expected,sizeof(expected));memset(c->seen,0,sizeof(c->seen));
        put32(c->memory+0x21000c,0x11223344);put32(c->memory+sp+8,0xdeadbeef);
        const int fault=sl_run(c,0x184d4,test.stop,test.limit);
        if(test.eaxChanged)put32(expected,test.badLoad?0:0x11223344);
        if(fault!=int(test.fault)||sl_get_pc(c)!=test.pc||sl_get_steps(c)!=test.steps||
           sl_coverage_count(c)!=test.coverage||memcmp(c->reg,expected,sizeof(expected))||
           get32(c->memory+sp+8)!=(test.stored?0x11223344u:0xdeadbeefu)){
            fprintf(stderr,"Storage/stop/fault regression in case %u: fault %d pc %x steps %llu\n",tested,fault,sl_get_pc(c),(unsigned long long)sl_get_steps(c));
            sl_destroy(c);return 1;
        }
        ++tested;
    }
    sl_destroy(c);
    printf("{\"scope\":\"GP/flag cache commits at interior stops, memory fault and exact instruction limits\",\"cases\":%u,\"compared_register_bytes\":%u,\"guest_memory_pc_steps_and_coverage_checked\":true,\"passed\":true}\n",tested,tested*0x2000u);
    return 0;
}
