#include <stdio.h>
#include <stdlib.h>
#include "wav_file_gen.h"
#include "wav_sample_gen.h"

uint32_t computeTotalSamples(WavHeader* header, int audioLength){
	return (uint32_t)(header->Frequency * audioLength);
}

void deprecated_wavFileGen(WavHeader* header, int audioLength, double* freqs, int freqPerSec, int16_t amplitude){
	uint32_t totalSamples = computeTotalSamples(header, audioLength);
	
	FILE* file = fopen("signal.wav", "wb");
	if(!file){
		fprintf(stderr, "Error while opening file.\n");
		exit(EXIT_FAILURE);
	}
	
	fwrite(header, sizeof(WavHeader), 1, file);
	
	
	for(uint32_t i = 0; i < totalSamples; i++){
		int16_t sample = computeSingleWaveSample(i, header->Frequency, freqs[(i / (header->Frequency / freqPerSec))], amplitude);
		fwrite(&sample, sizeof(int16_t), 1, file);
	}
	
	fclose(file);
	printf("signal.wav generated correctly.\n");
}

void wavFileGen(WavHeader* header, int audioLength, DoubleMatrix* mat, int freqPerSec, int16_t amplitude){
	uint32_t totalSamples = computeTotalSamples(header, audioLength);
	
	FILE* file = fopen("signal.wav", "wb");
	if(!file){
		fprintf(stderr, "Error while opening file.\n");
		exit(EXIT_FAILURE);
	}
	
	fwrite(header, sizeof(WavHeader), 1, file);
	
	uint32_t samplesPerFreqChunk = header->Frequency / freqPerSec;
	
	for(uint32_t i = 0; i < totalSamples; i++){
		uint32_t rowIndex = i / samplesPerFreqChunk;
		
		double* currentFreqs = NULL;
		size_t currentLen = 0;
		
		if(rowIndex < mat->len){
			currentFreqs = mat->data[rowIndex].data;
			currentLen = mat->data[rowIndex].len;
		}
		
		int16_t sample = computeSample(i, header->Frequency, currentFreqs, currentLen, amplitude);
		
		fwrite(&sample, sizeof(int16_t), 1, file);
	}
	
	fclose(file);
	printf("signal.wav generated correctly.\n");
	
}