// Replay single-instruction fixtures produced from the original i386 bytes.
#include "LifterRuntime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Reader {
    FILE* f;bool ok=true;
    void bytes(void* p,SlSize n){if(fread(p,1,n,f)!=n)ok=false;}
    SlU32 word(){SlU32 n=0;bytes(&n,4);return n;}
};
int main(int argc,char** argv){
    if(argc!=3){fprintf(stderr,"Usage: InstructionProbe original-i386 fixtures\n");return 2;}
    FILE* image=fopen(argv[1],"rb");FILE* fixture=fopen(argv[2],"rb");
    if(!image||!fixture){perror("Open reference");if(image)fclose(image);if(fixture)fclose(fixture);return 2;}
    SlCpu* cpu=sl_create(0x800000);if(!cpu)return 2;
    SlSize n=fread(cpu->memory,1,cpu->memory_size,image);
    if(ferror(image)||!feof(image)||!n){fprintf(stderr,"Invalid image\n");return 2;}
    fclose(image);Reader r{fixture};char magic[8]={};r.bytes(magic,8);
    if(memcmp(magic,"SLIP0001",8)){fprintf(stderr,"Invalid instruction fixtures\n");return 2;}
    SlU32 count=r.word();if(count>1000000)return 2;SlU64 compared=0;
    for(SlU32 test=0;test<count&&r.ok;++test){
        SlU32 entry=r.word(),stop=r.word(),fault=r.word();
        SlU32 registers=r.word(),memory=r.word(),outputs=r.word();
        if(registers>64||memory>64||outputs>64){r.ok=false;break;}
        memset(cpu->reg,0,sizeof(cpu->reg));
        for(SlU32 kind=0;kind<2;++kind){
            SlU32 segments=kind?memory:registers;
            for(SlU32 i=0;i<segments&&r.ok;++i){
                SlU32 address=r.word(),size=r.word();SlU8 bytes[256]={};
                if(size>sizeof(bytes)){r.ok=false;break;}r.bytes(bytes,size);
                if(kind?sl_mem_write(cpu,address,bytes,size):sl_reg_write(cpu,address,bytes,size))r.ok=false;
            }
        }
        if(!r.ok)break;
        const int actual=sl_run(cpu,entry,stop,1000);
        if(actual!=int(fault)||(!fault&&sl_get_pc(cpu)!=stop)){
            fprintf(stderr,"Instruction case %u at 0x%x fault %d, expected %u\n",test,entry,actual,fault);return 1;
        }
        for(SlU32 i=0;i<outputs&&r.ok;++i){
            SlU32 address=r.word(),size=r.word();SlU8 expected[256]={},actual_bytes[256]={};
            if(size>sizeof(expected)){r.ok=false;break;}r.bytes(expected,size);
            if(sl_reg_read(cpu,address,actual_bytes,size)||memcmp(expected,actual_bytes,size)){
                fprintf(stderr,"Instruction case %u register mismatch at 0x%x\n",test,address);return 1;
            }
            compared+=size;
        }
    }
    const bool valid=r.ok&&fgetc(fixture)==EOF;fclose(fixture);sl_destroy(cpu);
    printf("{\"scope\":\"isolated original instruction fixtures including explicit guards\",\"cases\":%u,\"compared_register_bytes\":%llu,\"passed\":%s,\"full_engine_tested\":false}\n",
           count,(unsigned long long)compared,valid?"true":"false");
    return valid?0:1;
}
