#ifndef WAV_FILE_GEN
#define WAV_FILE_GEN

#include <stdint.h>
#include "wav_header.h"

uint32_t compute_totalSamples(WavHeader* header, int audioLenght);
void wavFileGen(WavHeader* header, int audioLenght, double freqs[], int freqPerSec, int16_t amplitude);


#endif