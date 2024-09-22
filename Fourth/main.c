#include <stdio.h>
#include "get_file.h"
#include "max_difference.h"

/*
36 Задача
*/

int max(int first, int second);
int maxDifference(FILE * file);

int main(void) {
    FILE * file = getFile();
    if (file == NULL) return -1;
    printf("Maximum difference between elements is %d", maxDifference(file));
    return 0;
}
