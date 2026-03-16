#ifndef PARSER_H
#define PARSER_H

#include "lib/genDynArr.h"

DEFINE_DYNARR(double, DoubleArr)

int parseFrequenciesFromFile(const char* filename, DoubleArr* arr);

#endif