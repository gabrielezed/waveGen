#ifndef WAV_SAMPLE_GEN_H
#define WAV_SAMPLE_GEN_H

#include <stdint.h>
#include <stddef.h>

//Deprecated functions and old version of computeSample
/*double computeT(uint32_t i, uint32_t sampleRate); 
double computeWave(double freq, double t);
int16_t computeSample(uint32_t i, uint32_t sampleRate, double* freqs, size_t freqsNum, int16_t amplitude);*/

int16_t computeSample(uint32_t sampleRate, double* freqs, size_t freqsNum, int16_t amplitude, double* phases);
#endif
