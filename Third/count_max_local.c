#include "count_max_local.h"

int max(int first, int second) {
    if (first > second) {
        return first;
    }
    return second;
}


int getCountMaxLocal(FILE *file) {
    int current_n, last, length, maxLen;
    if (fscanf(file, "%d", &current_n) != 1) {
            printf("File is empty!\n");
            return -1;
    }

    last = current_n;
    maxLen = EMPTY;
    length = 1;

    while (fscanf(file, "%d", &current_n) == 1) {
        if (last == current_n) {
            if (length) length++;
        } else {
            if (last > current_n) {
                maxLen = max(maxLen, length);
                length = EMPTY;
            } else {
                length = 1;
            }
        }

        last = current_n;
    }
    return max(maxLen, length);
}
