#ifndef PARSER_H
#define PARSER_H

#include <stdbool.h>

#include "lib/wavGenTypes.h"

int parseJaggedFrequenciesFromFile(const char* filename, DoubleMatrix* mat, bool isVerbose);

#endif