#include "max_difference.h"

int max(int first, int second) {
    if (first > second) return first;
    return second;
}

int maxDifference(FILE * file) {
    int current, last, maxim;
    if (fscanf(file, "%d", &current) != 1) {
        printf("File is empty!\n");
        return -1;
    }

    last = current;
    maxim = 0;

    while (fscanf(file, "%d", &current) == 1) {
        maxim = max(maxim, abs(last - current));
        last = current;
    }
    return maxim;
}
