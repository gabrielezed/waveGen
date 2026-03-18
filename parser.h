#ifndef PARSER_H
#define PARSER_H

#include "lib/wavGenTypes.h"

int parseFrequenciesFromFile(const char* filename, DoubleArr* arr);
int parseJaggedFrequenciesFromFile(const char* filename, DoubleMatrix* mat);

#endif