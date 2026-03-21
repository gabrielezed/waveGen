#ifndef WAV_HEADER_H
#define WAV_HEADER_H

#include <stdint.h>

typedef struct{
	/* Master RIFF chunk */
	char FileTypeBlocID[4];
	uint32_t FileSize;
	char FileFormatID[4];
	
	/*Chunk describing the data format */
	char FormatBlocID[4];
	uint32_t BlocSize;
	uint16_t AudioFormat;
	uint16_t NbrChannels;
	uint32_t Frequency;
	uint32_t BytePerSec;
	uint16_t BytePerBloc;
	uint16_t BitsPerSample;
	
	/* Chunk containing the sampled data */
	char DataBlocID[4];
	uint32_t DataSize;	
	
} WavHeader;

WavHeader createMonoHeader_16(int len, int notesPerSec, uint32_t frequency);

#endif