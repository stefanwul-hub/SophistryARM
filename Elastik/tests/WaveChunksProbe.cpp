#include "../src/OriginalWaveChunks.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool output(const void* p,size_t n){return fwrite(p,1,n,stdout)==n;}
static int run(const int* h){
    int initial[7];if(fread(initial,1,28,stdin)!=28)return 2;
    auto* data=static_cast<unsigned char*>(malloc(h[1]+1));
    if(fread(data,1,h[1],stdin)!=static_cast<size_t>(h[1]))return 2;
    const unsigned char* payload=h[2]?nullptr:data;
    int status=0,state[7];memcpy(state,initial,28);unsigned char padding[3]{};unsigned char serialized[8];memset(serialized,0xa5,8);
    if(h[0]==0||h[0]==2){
        ElastikOriginalInstrumentChunk s{initial[0],initial[1],initial[2],initial[3],initial[4],initial[5],initial[6]};
        if(h[0]==0)status=elastik_original_read_instrument_chunk(&s,payload,h[1]);
        else status=elastik_original_write_instrument_chunk(&s,h[3],serialized);
        const int values[]{s.base_note,s.detune,s.low_note,s.high_note,s.low_velocity,s.high_velocity,s.gain};memcpy(state,values,28);
    }else{
        ElastikOriginalAcidChunk s;memset(&s,0xa5,sizeof(s));s.looping=static_cast<unsigned char>(initial[0]);s.numerator=initial[1];s.denominator=initial[2];s.beats=initial[3];s.root_offset=initial[4];s.root_mode=initial[5];
        status=elastik_original_read_acid_chunk(&s,payload,h[1]);
        const int values[]{s.looping,s.numerator,s.denominator,s.beats,s.root_offset,s.root_mode,initial[6]};memcpy(state,values,28);memcpy(padding,reinterpret_cast<unsigned char*>(&s)+1,3);
    }
    bool ok=output(&status,4)&&output(state,28)&&output(padding,3)&&output(serialized,8)&&output(data,h[1]);free(data);return ok&&fflush(stdout)==0?0:4;
}
int main(){for(;;){int h[4];size_t n=fread(h,1,16,stdin);if(!n&&feof(stdin))return 0;if(n!=16)return 2;int e=run(h);if(e)return e;}}
