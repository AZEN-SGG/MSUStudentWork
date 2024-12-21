#ifndef SCP
#define SCP

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include "types.h"

#define exp 1.e-6

circle MEC(point * I, int ilen, point * N, int nlen);
bool belongs(circle crcl, point p);
double powd(double number);
circle primitive(point * N, int nlen);
circle centermass(point p1, point p2);
circle byThreePoints(point * warp);
point getCenter(point * warp);
double straightAngle(point p1, point p2);
double distance(point p1, point p2);
void printCircle(circle crcl);
int isCover(circle crcl, points pts);

#endif
