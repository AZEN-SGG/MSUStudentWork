#include <stdio.h>
#include "get_file.h"
#include "count_elements.h"

int main(void) {
    FILE * file = getFile();
    if (file == NULL) {
        return -1;
    }
    printf("Count of numbers between 1 to 5 is %lf", countElements(file));
    return 0;
}
