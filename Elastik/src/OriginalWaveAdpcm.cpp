#include "OriginalWaveAdpcm.h"

static int from_bits(unsigned bits) noexcept { int n; __builtin_memcpy(&n, &bits, 4); return n; }
static short short_bits(unsigned bits) noexcept {
    unsigned short low = static_cast<unsigned short>(bits); short n; __builtin_memcpy(&n, &low, 2); return n;
}
static short short_le(const unsigned char* p) noexcept { return short_bits(unsigned(p[0]) | unsigned(p[1]) << 8); }
static unsigned ushort_le(const unsigned char* p) noexcept { return unsigned(p[0]) | unsigned(p[1]) << 8; }
static int add(int a,int b) noexcept { return from_bits(unsigned(a) + unsigned(b)); }
static int multiply(int a,int b) noexcept { return from_bits(unsigned(a) * unsigned(b)); }
static float normalize(short sample) noexcept {
    return sample > 0 ? static_cast<float>(sample) / 32767.0f : static_cast<float>(sample) * 0x1p-15f;
}
static const int ms_adaptation[16]{230,230,230,230,307,409,512,614,768,614,512,409,307,230,230,230};
struct MsChannel { unsigned predictor,delta; short previous,older; };
static short ms_sample(MsChannel& state,unsigned nibble,const int* coefficients) noexcept {
    int prediction = add(multiply(state.previous,coefficients[0]),multiply(state.older,coefficients[1]));
    prediction /= 256; // i386 adds 255 before SAR for a negative product sum.
    int sample = add(prediction,multiply(int(nibble) - ((nibble & 8) ? 16 : 0),int(state.delta)));
    if (sample < -32768) sample = -32768;
    else if (sample > 32767) sample = 32767;
    int delta = multiply(int(state.delta),ms_adaptation[nibble]) / 256;
    if (delta < 16) delta = 16;
    state.delta = static_cast<unsigned short>(delta);
    state.older = state.previous; state.previous = static_cast<short>(sample);
    return state.previous;
}
extern "C" void elastik_original_decode_ms_adpcm(
    const ElastikOriginalWave* w,const unsigned char* block,int first,int end,
    float* const* outputs,int destination_base) noexcept {
    const int channels = w->channels; MsChannel state[2]{};
    for (int c=0;c<channels;++c) state[c].predictor = *block++;
    for (int c=0;c<channels;++c) { state[c].delta = ushort_le(block); block += 2; }
    for (int c=0;c<channels;++c) { state[c].previous = short_le(block); block += 2; }
    for (int c=0;c<channels;++c) { state[c].older = short_le(block); block += 2; }
    if (first <= 0 && end > 0) for (int c=0;c<channels;++c)
        if (outputs[c]) outputs[c][destination_base-first] = normalize(state[c].older);
    if (first <= 1 && end > 1) for (int c=0;c<channels;++c)
        if (outputs[c]) outputs[c][destination_base+1-first] = normalize(state[c].previous);
    int remaining = channels * (int(w->ms_samples_per_block)-2);
    int frame = 1;
    while (remaining > 0) {
        short left = ms_sample(state[0],*block >> 4,w->coefficients[state[0].predictor]);
        const int right_channel = channels==1 ? 0 : 1;
        short right = ms_sample(state[right_channel],*block & 15,w->coefficients[state[right_channel].predictor]);
        ++frame;
        if (outputs[0] && first<=frame && frame<end) outputs[0][destination_base+frame-first] = normalize(left);
        if (channels==1) ++frame;
        if (outputs[right_channel] && first<=frame && frame<end) outputs[right_channel][destination_base+frame-first] = normalize(right);
        if (remaining-2 < 1) return;
        remaining -= 2; ++block;
    }
}

static const int dvi_index[16]{-1,-1,-1,-1,2,4,6,8,-1,-1,-1,-1,2,4,6,8};
static const int dvi_steps[89]{7,8,9,10,11,12,13,14,16,17,19,21,23,25,28,31,34,37,41,45,50,55,60,66,73,80,88,97,107,118,130,143,157,173,190,209,230,253,279,307,337,371,408,449,494,544,598,658,724,796,876,963,1060,1166,1282,1411,1552,1707,1878,2066,2272,2499,2749,3024,3327,3660,4026,4428,4871,5358,5894,6484,7132,7845,8630,9493,10442,11487,12635,13899,15289,16818,18500,20350,22385,24623,27086,29794,32767};
extern "C" void elastik_original_decode_dvi_adpcm(
    ElastikOriginalWave* w,const unsigned char* block,int first,int end,
    float* const* outputs,int destination_base,const ElastikOriginalWaveIO* diagnostics) noexcept {
    const int channels = w->channels; auto* scratch = static_cast<short*>(w->dvi_samples);
    __builtin_memset(scratch,0,channels*int(w->dvi_values_per_block)*2);
    unsigned short indices[8]{};
    for (int c=0;c<channels;++c) {
        scratch[c] = short_le(block+c*4);
        indices[c] = block[c*4+2] < 89 ? block[c*4+2] : 88;
        if (block[c*4+3] && diagnostics && diagnostics->diagnostic)
            diagnostics->diagnostic(diagnostics->bytes.context,5,0,0);
    }
    int byte_position = channels*4, sample_position = channels;
    while (byte_position < w->dvi_block_bytes) {
        for (int c=0;c<channels;++c) {
            int at = sample_position+c;
            for (int b=0;b<4;++b) {
                unsigned encoded = block[byte_position+b];
                scratch[at] = static_cast<short>(encoded & 15); at += channels;
                scratch[at] = static_cast<short>(encoded >> 4); at += channels;
            }
            byte_position += 4;
        }
        sample_position += channels*8;
    }
    const int values = channels*int(w->dvi_values_per_block);
    for (int at=channels;at<values;++at) {
        const int slot = channels>1 ? at%2 : 0; // Original uses parity, including >2 channels.
        const unsigned nibble = static_cast<unsigned short>(scratch[at]) & 15;
        const int step = dvi_steps[indices[slot]];
        short delta = static_cast<short>(step>>3);
        if (nibble&1) delta = short_bits(unsigned(int(delta)+(step>>2)));
        if (nibble&2) delta = short_bits(unsigned(int(delta)+(step>>1)));
        if (nibble&4) delta = short_bits(unsigned(int(delta)+step));
        if (nibble&8) delta = short_bits(unsigned(-int(delta)));
        int sample = int(scratch[at-channels])+int(delta);
        if (sample < -32768) sample = -32768;
        else if (sample > 32767) sample = 32767;
        int index = int(indices[slot])+dvi_index[nibble];
        if (index<0) index=0; else if (index>88) index=88;
        indices[slot] = static_cast<unsigned short>(index);scratch[at] = static_cast<short>(sample);
    }
    for (int frame=0;frame<w->dvi_values_per_block;++frame)
        if (first<=frame && frame<end) for (int c=0;c<channels;++c)
            if (outputs[c]) outputs[c][destination_base+frame-first] = normalize(scratch[frame*channels+c]);
}
extern "C" ElastikWaveStatus elastik_original_read_wave(
    ElastikOriginalWave* w,ElastikOriginalReadBuffer* pcm,float* const* outputs,
    int first,int count,const ElastikOriginalByteIO* io,const ElastikOriginalWaveReadPlatform* platform,
    const ElastikOriginalReaderDiagnostics* diagnostics,const ElastikOriginalWaveIO* codec_diagnostics) noexcept {
    if (w->format==1 || w->format==3) {
        elastik_original_read_buffered_pcm(pcm,outputs,first,count,elastik_original_wave_sample_format(w),elastik_original_wave_channel_format(w),w->data_offset,io,diagnostics);
        return ElastikWaveOk;
    }
    if (w->format!=2 && w->format!=17) return ElastikWaveOk;
    const int frames_per_block = w->format==2 ? w->ms_samples_per_block : int(w->dvi_values_per_block)/w->channels;
    const int block_bytes = w->format==2 ? w->ms_block_bytes : w->dvi_block_bytes;
    unsigned char* buffer = platform->allocate(platform->context,block_bytes);
    int offset = first%frames_per_block;
    io->seek(io->context,add(multiply(block_bytes,first/frames_per_block),w->data_offset));
    int destination = 0;
    for (;;) {
        const int valid = frames_per_block-offset < count ? frames_per_block-offset : count;
        const int end = offset+valid;int actual = block_bytes;
        if (!io->read(io->context,buffer,&actual) || actual!=block_bytes) return ElastikWaveCannotRead;
        if (w->format==2) elastik_original_decode_ms_adpcm(w,buffer,offset,end,outputs,destination);
        else elastik_original_decode_dvi_adpcm(w,buffer,offset,end,outputs,destination,codec_diagnostics);
        count -= valid;if (count<1) break;
        destination += valid;offset = 0;
    }
    platform->release(platform->context,buffer);
    return ElastikWaveOk;
}
