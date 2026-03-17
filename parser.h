#ifndef PARSER_H
#define PARSER_H

#include "lib/genJaggedArr.h"

DEFINE_DYNARR(double, DoubleArr)
DEFINE_JAGGEDARR(double, DoubleRow, DoubleMatrix)

int parseFrequenciesFromFile(const char* filename, DoubleArr* arr);
int parseJaggedFrequenciesFromFile(const char* filename, DoubleMatrix* mat);
#endif