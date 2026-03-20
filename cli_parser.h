#ifndef CLI_PARSER_H
#define CLI_PARSER_H

#include <stdbool.h>

/* Data structure for CLI arguments */

typedef struct{
	char* inputFile;
	char* outputFile;
	int amplitude;
	int notesPerSec;
	int sampleRate;
	bool verbose;
	
}AppConfig;

void helpMessage();
void unrecognizeArgument();
void defaultConfig(AppConfig* appConfig);
int parseArgument(int argc, char** argv, AppConfig* appConfig);

#endif