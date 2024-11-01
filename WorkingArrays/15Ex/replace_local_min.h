#ifndef REPLACE_LOCAL_MIN
#define REPLACE_LOCAL_MIN

#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define exp 1.e-6

unsigned findLocalMin(double * num_array, int length, int * start_length_local_min);
void test_findLocalMin(void);
bool isEqual(double first, double second);
void replace(double * array, int length, double wherewith, int from, int len_replaceable);
void test_replace(void);
unsigned find_replace_local_min(double * array, int length);
double min(double * array, int length);
unsigned unbs(int number);

#endif // REPLACE_LOCAL_MIN
