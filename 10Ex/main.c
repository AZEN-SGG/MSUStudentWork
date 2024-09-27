#include <stdio.h>
#include "tools.h"
#include "count_between.h"

// 10Ex

int main(void) {
    FILE * file = getFile();
    if (file == NULL) return 1;

    printf("Count of number between first and second is %d", countBetween(file));
}
