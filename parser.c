#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

int parseFrequenciesFromFile(const char* filename, DoubleArr* arr){
	FILE* file = fopen(filename, "r");
	if(!file){
		fprintf(stderr, "Error: impossible to open file %s\n", filename);
		return 0;
	}
	
	char buffer[256];
	while(fgets(buffer, sizeof(buffer), file)){
		buffer[strcspn(buffer, "\r\n")] = 0;
		
		if(strlen(buffer) == 0) continue;
		
		char* endptr;		
		double freq = strtod(buffer, &endptr);
		
		if(endptr != buffer && freq >= 0.0){
			DoubleArr_push(arr, freq);
		}
	}
	
	fclose(file);
	return 1;
}