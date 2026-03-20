#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "cli_parser.h"



//wip
void helpMessage(){
	printf("----------------------------wavGen----------------------------\n");
	printf("| -i 'inputFile'  --> provide input file name                |\n");
	printf("| -o 'outputFile' --> provide desired output file name       |\n");
	printf("| -a 'amplitude' --> provide a numerical value               |\n");
	printf("| -n 'notes Per Seconds' --> how many notes do you want      |\n ");
	printf("        to be played per seconds? Must be >0                 |\n");
	printf("| -s 'sampleRate' --> provide desired sample rate            |\n");
	printf("| -v --> add this flag if you want to enter verbose mode     |");
	printf("|-------------------------------------------------------------\n");
	
}

void unrecognizeArgument(){
	printf("Unrecognized flag. Use wavGen -h to view usage. \n");
}

void defaultConfig(AppConfig* appConfig){
	appConfig->inputFile = "freqs.txt";
	appConfig->outputFile = "signal.wav";
	appConfig->amplitude = 16000;
	appConfig->notesPerSec = 2;
	appConfig->sampleRate = 44100;
	appConfig->verbose = false;
	
}

int parseArgument(int argc, char** argv, AppConfig* appConfig){
	int opt;
	while((opt = getopt(argc, argv, "i:o:a:n:s:vh")) != -1){
		switch(opt){
			case 'i':
				appConfig->inputFile = optarg;
				break;
			case 'o':
				appConfig->outputFile = optarg;
				break;
			case 'a':
				appConfig->amplitude = atoi(optarg);
				break;
			case 'n':
				appConfig->notesPerSec = atoi(optarg);
				break;
			case 's':
				appConfig->sampleRate = atoi(optarg);
				break;
			case 'v':
				appConfig->verbose = true;
				break;
			case 'h':
				helpMessage();
				return 0;
				break;
			case '?':
				unrecognizeArgument();
				return 0;
				break;
		}
		
	}
	
	return 1;
}