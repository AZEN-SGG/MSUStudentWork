#ifndef TOOLS
#define TOOLS

#include "seagwithsob.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define exp -1.e-6

FILE * getFile();
double * getArray(FILE * file);
bool orderliness(double * array, int length);
void randomArray();
void generate(double * array, int length);
void printArray(double * array, int length);

#endif
