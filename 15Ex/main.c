#include <stdio.h>
#include "tools.h"
#include "replace_local_min.h"

int main(void) {
    double * numbers;
    FILE * file = getFile();
    if (file == NULL) return -1;

    numbers = getList(file);
    if (numbers == NULL) return 1;

    printf("Count elements in file: %d", replaceLocalMin(numbers));
    free(numbers);
}
