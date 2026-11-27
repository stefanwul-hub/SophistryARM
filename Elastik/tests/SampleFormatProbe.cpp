#include "../src/OriginalSampleFormat.h"
#include <stdio.h>
#include <stdlib.h>

static void diagnostic(void* context, int code) { *static_cast<unsigned*>(context) |= 1u << code; }
static int run(const int* h) {
    // source/destination offsets index a single byte store, allowing alias tests.
    if (h[0] < 64 || h[0] > 1048576 || h[1] < 0 || h[2] < 0 || h[1] >= h[0] || h[2] >= h[0] || h[10] < 0 || h[10] > 4096) return 2;
    auto* storage = static_cast<unsigned char*>(malloc(h[0])); if (!storage) return 3;
    if (fread(storage, 1, h[0], stdin) != static_cast<unsigned>(h[0])) return 2;
    unsigned errors = 0;
    elastik_original_convert_channel(storage + h[1], static_cast<unsigned>(h[3]), h[4], h[5], storage + h[2], static_cast<unsigned>(h[6]), h[7], h[8], h[10], diagnostic, &errors);
    const int result[3]{elastik_original_sample_bytes(static_cast<unsigned>(h[3])), elastik_original_sample_bytes(static_cast<unsigned>(h[6])), static_cast<int>(errors)};
    if (fwrite(result, sizeof(result), 1, stdout) != 1 || fwrite(storage, 1, h[0], stdout) != static_cast<unsigned>(h[0])) return 4;
    free(storage); return 0;
}
int main() {
    for (;;) {
        int h[11]; const auto bytes = fread(h, 1, sizeof(h), stdin);
        if (!bytes && feof(stdin)) return 0;
        if (bytes != sizeof(h)) return 2;
        const int result = run(h); if (result) return result;
        if (fflush(stdout)) return 4;
    }
}
