#include <math.h>
#include "wav_sample_gen.h"

#define M_PI 3.14159265358979323846

double compute_t(uint32_t i, uint32_t sampleRate){
	
	return (double)i / sampleRate;
}


double compute_wave(double freq, double t){
	
	return sin(2.0 * M_PI * freq * t);
}


int16_t compute_sample(uint32_t i, uint32_t sampleRate, double freq, int16_t amplitude){
	
	
	return (int16_t)(compute_wave(freq, compute_t(i, sampleRate)) * amplitude);	
}