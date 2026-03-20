#ifndef WAV_FILE_GEN
#define WAV_FILE_GEN

#include <stdint.h>
#include "wav_header.h"
#include "lib/wavGenTypes.h"

uint32_t compute_totalSamples(WavHeader* header, int audioLength);
void wavFileGen(WavHeader* header, DoubleMatrix* mat, int notesPerSec, int16_t amplitude, char* outputName);


#endif