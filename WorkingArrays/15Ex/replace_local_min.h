#ifndef REPLACE_LOCAL_MIN
#define REPLACE_LOCAL_MIN

#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define exp 1.e-6

int findAndReplaceLocalMin(double * numbers);
double min(double * numbers);
void findLocalMinimum(double * numbers, unsigned length, unsigned *start_end_minimum_index);
bool isEqual(double first, double second);

#endif // REPLACE_LOCAL_MIN
