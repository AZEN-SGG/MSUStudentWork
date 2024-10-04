#ifndef EXP_WEIGH_AVG
#define EXP_WEIGH_AVG

#include <stdio.h>
#include <math.h>

#define FALSE 0
#define FAULT 1.e-10

int betweenZeroOne(double lambda);
double expWeigthAvg(FILE * file, double lambda);

#endif // EXP_WEIGH_AVG
