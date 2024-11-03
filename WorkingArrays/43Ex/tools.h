#ifndef TOOLS
#define TOOLS

#include <stdio.h>
#include <stdlib.h>

FILE * getFile(void);
double * getList(FILE * file);
void outputArray(double * array, int length);

#endif
