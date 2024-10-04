#include <stdio.h>
#include "tools.h"
#include "equal.h"

int main(void) {
    double * numbers;
    FILE * file = getFile();
    if (file == NULL) return 1;

    numbers = getList(file);
    if (numbers == NULL) return 1;

    if (equal(numbers)) printf("They are different");
    else printf("They are the same");

    return 0;
}
