#ifndef TOOLS
#define TOOLS

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define exp 1.e-6

typedef void (sort_op)(double * array, int length);

FILE * getFile(void);
double * getArray(FILE * file);
bool orderliness(double * array, int length);
void testSortRandomArray(sort_op op);
void compareSorts(sort_op first, sort_op second);
void generate(double * array, int length);
void copy(double * from, double * to, int length);
void printArray(double * array, int length);
int testSort(double * array, int length, sort_op op);
bool isSorted(double * array, int length);
bool more(double a, double b);
int compare(const void * ufirst, const void * usecond);

#endif
