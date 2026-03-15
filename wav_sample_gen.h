#ifndef WAV_SAMPLE_GEN
#define WAV_SAMPLE_GEN

#include <stdint.h>

double compute_t(uint32_t i, uint32_t sampleRate); 
double compute_wave(double freq, double t);
int16_t compute_sample(uint32_t i, uint32_t sampleRate, double freq, int16_t amplitude);

#endif
