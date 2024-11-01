#include <stdio.h>
#include "tools.h"
#include "replace_local_min.h"

int main(void) {
    double * numbers;
    unsigned length;
    FILE * file = getFile();
    if (file == NULL) return -1;

    numbers = getList(file);
    if (numbers == NULL) return 1;

    length = find_replace_local_min(&numbers[1], (int)numbers[0] - 1);

    for (int i = 1; i < (int)length + 1; ++i) {
        printf("%.1lf ", numbers[i]);
    }

    free(numbers);

    return 0;
}
