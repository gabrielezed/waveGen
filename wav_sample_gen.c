#include <math.h>
#include "wav_sample_gen.h"

#define M_PI 3.14159265358979323846

double computeT(uint32_t i, uint32_t sampleRate){
	
	return (double)i / sampleRate;
}


double computeWave(double freq, double t){
	
	return sin(2.0 * M_PI * freq * t);
}


int16_t computeSingleWaveSample(uint32_t i, uint32_t sampleRate, double freq, int16_t amplitude){
	
	
	return (int16_t)(computeWave(freq, computeT(i, sampleRate)) * amplitude);	
}


int16_t computeSample(uint32_t i, uint32_t sampleRate, double* freqs, size_t freqsNum, int16_t amplitude){
	if(freqsNum == 0) return 0;
	
	double sampleSum = 0;
	double t = computeT(i, sampleRate);
	
	for(size_t j = 0; j < freqsNum; j++){
		sampleSum += computeWave(freqs[j], t);
	}
	
	return (int16_t)((sampleSum / freqsNum) * amplitude);
}