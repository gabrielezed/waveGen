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
	
	printf("---Parsing test---\n");
	
	if(!parseJaggedFrequenciesFromFile("freqs.txt", &frequencies)){
		fprintf(stderr, "Test failed: unable to open file\n");
		DoubleMatrix_deep_free(&frequencies);
		return 1;
	}
	
	printf("---Parsing Jagged Array content---\n");
	for(size_t i = 0; i < frequencies.len; i++){
		printf("Riga %zu (lunghezza %zu): ", i, frequencies.data[i].len);
		for(size_t j = 0; j < frequencies.data[i].len; j++){
			printf("%f ", frequencies.data[i].data[j]);
		}
		printf("\n");
	}
	
	DoubleMatrix_deep_free(&frequencies);
	
	/*
	//Wav generation test using data parsed from file
	
	DoubleArr frequencies;
	DoubleArr_init(&frequencies);
	
	if(!parseFrequenciesFromFile("freqs.txt", &frequencies)){
		DoubleArr_free(&frequencies);
		return 1;
	}
	
	if(frequencies.len == 0){
		fprintf(stderr, "No valid frequencies found in file.\n");
	}
	
	int freqPerSec = 2;
	int audioLenght = frequencies.len / freqPerSec;
	if(audioLenght == 0) audioLenght = 1;
	
	WavHeader header = createMonoHelper441_16(audioLenght);
	wavFileGen(&header, audioLenght, frequencies.data, freqPerSec, AMPLITUDE);
	
	DoubleArr_free(&frequencies);
	*/
	
	//Manual wav generation test
	/*int audioLenght = 3;
	int freqPerSec = 2;
	double freq[6] = {600.0, 800.0, 400.0, 900.0, 600.0, 800.0};
	WavHeader header = createMonoHelper441_16(audioLenght);
	
	wavFileGen(&header, audioLenght, freq, freqPerSec, AMPLITUDE);*/
	
	return 0;
}