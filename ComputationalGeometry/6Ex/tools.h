#ifndef TOOLS
#define TOOLS

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

#define ASCII_FIRST_LETTER 65
#define MAX_PRINT_POINTS 10
#define MAX_RAND_COORD 10000
#define RAND_MULTIPLIER 1.e-2

FILE * getFile(void);
points * getFilePoints(FILE * file)
points * GetPointsFromFile(void);
points * getRandomPoints(void);
points * getPoints(void);
void printPoints(points pts);
void generate(points * pts);

#endif
