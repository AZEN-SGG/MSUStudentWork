#ifndef POLYGON
#define POLYGON

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "types.h"

#define DELFUNC(NAME, TYPE) \
	void del##NAME(TYPE * array, int index) { \
		DEL(array->arr, index, array->len) \
		array -> len--; \
	}

#define DEL(DATA, INDEX, LEN) \
	for (int i = INDEX; i < (LEN) - 1; ++i) { \
		(DATA)[i] = (DATA)[i + 1]; \
	}

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
