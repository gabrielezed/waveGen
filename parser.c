#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

int parseJaggedFrequenciesFromFile(const char* filename, DoubleMatrix* mat){
	FILE* file = fopen(filename, "r");
	if(!file){
		fprintf(stderr, "Error: impossible to open file %s\n", filename);
		return 0;
	}
	
	char buffer[1024];
	size_t row_idx = 0;
	
	while(fgets(buffer, sizeof(buffer), file)){
		buffer[strcspn(buffer, "\r\n")] = 0;
		
		if(strlen(buffer) == 0) continue;
		
		char* ptr = buffer;
		char* endptr;
		int foundInRow = 0;
		
		while(1){
			double freq = strtod(ptr, &endptr);
			
			if(ptr == endptr) break;
			
			if(freq >= 0.0){
				DoubleMatrix_push_at(mat, row_idx, freq);
				foundInRow = 1;
			}
			
			ptr = endptr;
		}
		
		if(foundInRow) row_idx++;		
	}
	
	fclose(file);
	return 1;
}

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