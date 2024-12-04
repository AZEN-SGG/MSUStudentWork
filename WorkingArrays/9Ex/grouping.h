#ifndef GROUPING
#define GROUPING

#include <stdio.h>
#include <math.h>

#define eps 1.e-6

void group(double * array, int length);
void negativeToRight(double * array, int length);
void zeroesToCenter(double * array, int length);
void printArray(double * array, int length);

#endif
