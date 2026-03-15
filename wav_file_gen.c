#include <stdio.h>
#include <stdlib.h>
#include "wav_file_gen.h"
#include "wav_sample_gen.h"

uint32_t compute_totalSamples(WavHeader* header, int audioLenght){
	return (header->Frequency * audioLenght);
}

void wavFileGen(WavHeader* header, int audioLenght, double freqs[], int freqPerSec, int16_t amplitude){
	uint32_t totalSamples = compute_totalSamples(header, audioLenght);
	
	FILE* file = fopen("signal.wav", "wb");
	if(!file){
		fprintf(stderr, "Error while opening file.\n");
		exit(EXIT_FAILURE);
	}
	
	fwrite(header, sizeof(WavHeader), 1, file);
	
	
	for(uint32_t i = 0; i < totalSamples; i++){
		int16_t sample = compute_sample(i, header->Frequency, freqs[(i / (header->Frequency / freqPerSec))], amplitude);
		fwrite(&sample, sizeof(int16_t), 1, file);
	}
	
	fclose(file);
	printf("signal.wav generated correctly.\n");
}

