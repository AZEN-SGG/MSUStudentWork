#include "count_elements.h"

int countElements(FILE * file) {
    int current, count;

    count = 0;

    if (fscanf(file, "%d", &current) != 1)
    {
        printf("File is empty!\n");
        return -1;
    }
    do {
        if (current <= 5 && current >= 1) count++;
    } while (fscanf(file, "%d", &current) == 1);

    return count;
}