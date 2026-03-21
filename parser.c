#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

int parseJaggedFrequenciesFromFile(const char* filename, DoubleMatrix* mat, bool isVerbose){
	FILE* file = fopen(filename, "r");
	if(!file){
		fprintf(stderr, "Error: impossible to open file %s\n", filename);
		return 0;
	}
	
	char buffer[1024];
	size_t row_idx = 0;
	
	if(isVerbose) printf("--- Parsing Frequencies ---\n");
	
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
		
		if(foundInRow){
			if(isVerbose){
				printf("Row %zu (%zu items): ", row_idx, mat->data[row_idx].len);
				for(size_t i = 0; i < mat->data[row_idx].len; i++){
					printf("%f ", mat->data[row_idx].data[i]);
				}
				printf("\n");
			}
			
			row_idx++;		
		}
	}
	
	fclose(file);
	return 1;
}