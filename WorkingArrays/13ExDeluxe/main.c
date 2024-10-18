#include <stdio.h>
#include "tools.h"
#include "equal.h"

int main(void) {
    double * numbers;
    FILE * file = getFile();
    if (file == NULL) return 1;

    numbers = getList(file);
    if (numbers == NULL) return 1;

    if (canFixArray(numbers)) printf("It can't be fixed!");
    else printf("It is possible to make them equal!");

    free(numbers);

    return 0;
}
