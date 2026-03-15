#include "wav_header.h"

WavHeader createMonoHelper441_16(int audioLength){
	uint32_t totalSamples = 44100 * audioLength;
	WavHeader header = {
		{'R', 'I', 'F', 'F'},
		36 + (totalSamples * sizeof(int16_t)), //FileSize
		{'W', 'A', 'V', 'E'},
        {'f', 'm', 't', ' '},
		16, //BlocSize
		1, //AudioFormat
		1, //NbrChannels
		44100, //Frequency
		(44100 * sizeof(int16_t)), //BytePerSec
		sizeof(int16_t), //BytePerBloc
		16, //BitsPerSample
		{'d', 'a', 't', 'a'},
		totalSamples * sizeof(int16_t)		
	};
	
	return header;
	
}