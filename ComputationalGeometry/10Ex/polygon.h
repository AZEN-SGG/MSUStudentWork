#ifndef POLYGON
#define POLYGON

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "types.h"

line getLine(point pt1, point pt2);
lines getLines(points pts);
points getVectors(points pts);
point normal(line ln);
double vector_len(point vector);
double qpow(double number);
void repairPolygon(polygon * plgn);
bool isNull(point vector);
bool isCollinear(point fvec, point svec);
void polygonDelPoint(polygon * plgn, int index);
void delVector(points * vectors, int index);
void delLine(lines * lns, int index);
polygon getPolygon(polygon * plgn, double shift); 

#endif
