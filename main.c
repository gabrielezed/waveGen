#include <stdio.h>

#include "wav_header.h"
#include "wav_sample_gen.h"
#include "wav_file_gen.h"
#include "parser.h"

#define AMPLITUDE 16000

int main(/*int argc, char* argv[]*/){
	printf("Hello, Sassari\n");
	
	//Multiple frequencies parsing and jagged array storage test
	
	DoubleMatrix frequencies;
	DoubleMatrix_init(&frequencies);
	
	if(!parseJaggedFrequenciesFromFile("freqs.txt", &frequencies)){
		fprintf(stderr, "Test failed: unable to open file\n");
		DoubleMatrix_deep_free(&frequencies);
		return 1;
	}
	
	printf("--- Parsing Frequencies :3 ---\n");
	for(size_t i = 0; i < frequencies.len; i++){
		printf("Riga %zu (lunghezza %zu): ", i, frequencies.data[i].len);
		for(size_t j = 0; j < frequencies.data[i].len; j++){
			printf("%f ", frequencies.data[i].data[j]);
		}
		printf("\n");
	}
	
	if(frequencies.len == 0){
		fprintf(stderr, "No valid frequencies found in file.\n");
	}
	
	int freqPerSec = 32;
	int audioLenght = frequencies.len / freqPerSec;
	if(audioLenght == 0) audioLenght = 1;
	
	WavHeader header = createMonoHelper441_16(audioLenght);
	wavFileGen(&header, audioLenght, &frequencies, freqPerSec, AMPLITUDE);
	
	DoubleMatrix_deep_free(&frequencies);
	
	return 0;
}