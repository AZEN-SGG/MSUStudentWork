#ifndef TOOLS
#define TOOLS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "types.h"

#define ASCII_FIRST_LETTER 65
#define MAX_PRINT_POINTS 10
#define MAX_RAND_COORD 10000
#define RAND_MULTIPLIER 1.e-2

points getPoints(void);
points getPointsFromFile(void);
FILE * getFile(void);
points getFilePoints(FILE * file);
points getRandomPoints(void);
void generatePoints(points * pts);
void printPoints(points pts);

#endif
