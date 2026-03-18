#ifndef WAV_FILE_GEN
#define WAV_FILE_GEN

#include <stdint.h>
#include "wav_header.h"
#include "lib/wavGenTypes.h"

uint32_t compute_totalSamples(WavHeader* header, int audioLength);
void deprecated_wavFileGen(WavHeader* header, int audioLength, double* freqs, int freqPerSec, int16_t amplitude);
void wavFileGen(WavHeader* header, int audioLength, DoubleMatrix* mat, int freqPerSec, int16_t amplitude);


#endif