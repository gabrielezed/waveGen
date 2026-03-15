#include <stdio.h>
#include "wav_header.h"
#include "wav_sample_gen.h"
#include "wav_file_gen.h"

#define AMPLITUDE 16000

int main(int argc, char* argv[]){
	printf("Hello, Sassari");
	
	int audioLenght = 3;
	int freqPerSec = 2;
	double freq[6] = {600.0, 800.0, 400.0, 900.0, 600.0, 800.0};
	WavHeader header = createMonoHelper441_16(audioLenght);
	
	wavFileGen(&header, audioLenght, freq, freqPerSec, AMPLITUDE);
	
	return 0;
}