#include <stdio.h>
#include "tools.h"
#include "local_minimum.h"

int main(void) {
    double * numbers;
    FILE * file = getFile();
    if (file == NULL) return -1;

    numbers = getList(file);
    if (numbers == NULL) return -1;

    if (searching_loc_min(numbers)) return -1;

    for (int i = 1; i < numbers[0]; ++i) printf("%.1lf ", numbers[i]);

    free(numbers);
    return 0;
}
