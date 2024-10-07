#include <stdio.h>
#include "tools.h"

int transposition(double * numbers);

int transposition(double * numbers) {
    unsigned length = (int)numbers[0];


    int last_index = -1;
    unsigned last_length = 0;

    return 0
}

int main(void) {
    double * numbers;
    FILE * file = getFile();
    if (file == NULL) return -1;

    numbers = getList(file);
    if (numbers == NULL) return -1;

    if (transposition(numbers) != 0) return -1;

    for (int i = 1; i < numbers[0]; ++i) printf("%d ", numbers[i]);

    free(numbers);
    return 0;
}
