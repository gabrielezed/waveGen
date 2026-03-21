#include "wav_header.h"

WavHeader createMonoHeader_16(int len, int notesPerSec, uint32_t frequency){
	int audioLength = len / notesPerSec;
	if(audioLength == 0) audioLength = 1;
	
	uint32_t totalSamples = frequency * audioLength;
	
	WavHeader header = {
		{'R', 'I', 'F', 'F'},
		36 + (totalSamples * sizeof(int16_t)), //FileSize
		{'W', 'A', 'V', 'E'},
        {'f', 'm', 't', ' '},
		16, //BlocSize
		1, //AudioFormat
		1, //NbrChannels
		frequency, //Frequency
		(frequency * sizeof(int16_t)), //BytePerSec
		sizeof(int16_t), //BytePerBloc
		16, //BitsPerSample
		{'d', 'a', 't', 'a'},
		totalSamples * sizeof(int16_t)		
	};
	
	return header;
}