#include <stdio.h>
#include "get_file.h"
#include "max_deviation.h"

/*
Задание 37
*/

int main(void) {
    FILE * file = getFile();
    if (file == NULL) return -1;
    printf("The standard deviation from the arithmetic mean is equal to %d", maxDeviation(file));
    return 0;
}
