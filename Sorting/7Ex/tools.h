#ifndef TOOLS
#define TOOLS

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define exp 1.e-6

typedef void (sort_op)(double * array, int length);

FILE * getFile(void);
double * getArray(FILE * file);
bool orderliness(double * array, int length);
void testSortRandomArray(sort_op op);
void generate(double * array, int length);
void printArray(double * array, int length);
void testSort(double * array, int length, sort_op op);
bool isSorted(double * array, int length);
bool more(double a, double b);

#endif
