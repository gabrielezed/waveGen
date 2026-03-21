#include <stdio.h>

#include "wav_header.h"
#include "wav_sample_gen.h"
#include "wav_file_gen.h"
#include "parser.h"
#include "cli_parser.h"

int main(int argc, char** argv){
	printf("Hello, Sassari\n");
	
	AppConfig appConfig;
	defaultConfig(&appConfig);
	if(parseArgument(argc, argv, &appConfig) == 0) return 0;
	
	if(appConfig.notesPerSec <= 0){
		fprintf(stderr, "Error. -n value must be >0.\n");
		return 1;
	}
	if(appConfig.sampleRate <= 0){
		fprintf(stderr, "Error. -s value must be >0.\n");
		return 1;
	}
	if(appConfig.amplitude < 0 && appConfig.amplitude > 32767){
		fprintf(stderr, "Error. -a value must be between 0 and 32767.\n");
		return 1;
	}
	
	DoubleMatrix frequencies;
	DoubleMatrix_init(&frequencies);
	
	if(!parseJaggedFrequenciesFromFile(appConfig.inputFile, &frequencies, appConfig.isVerbose)){
		fprintf(stderr, "Test failed: unable to open file %s\n", appConfig.inputFile);
		DoubleMatrix_deep_free(&frequencies);
		return 1;
	}
	
	/*
	if(appConfig.verbose){
		printf("--- Parsing Frequencies ---\n");
		for(size_t i = 0; i < frequencies.len; i++){
			printf("Row %zu (%zu items): ", i, frequencies.data[i].len);
			for(size_t j = 0; j < frequencies.data[i].len; j++){
				printf("%f ", frequencies.data[i].data[j]);
			}
			printf("\n");
		}	
	}
	
	*/
	if(frequencies.len == 0){
		fprintf(stderr, "No valid frequencies found in file.\n");
	}
	
	WavHeader header = createMonoHeader_16(frequencies.len, appConfig.notesPerSec, appConfig.sampleRate);
	wavFileGen(&header, &frequencies, appConfig.notesPerSec, appConfig.amplitude, appConfig.outputFile);
	
	DoubleMatrix_deep_free(&frequencies);
	
	return 0;
}