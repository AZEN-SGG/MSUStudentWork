#ifndef TOOLS
#define TOOLS

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

FILE * getFile(void);
points getPoints(FILE * file);
double getShift(void);
void printPolygon(polygon plgn, const char * str);

#endif
