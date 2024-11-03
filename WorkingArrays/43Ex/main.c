#include <stdio.h>
#include "tools.h"
#include "max_distance.h"

int main(void) {
    double * numbers;
    int max_distance;
    FILE * file = getFile();
    if (file == NULL) return -1;

    numbers = getList(file);
    if (numbers == NULL) return 1;

    max_distance = maxDistance(&numbers[1], (int)numbers[0] - 1);

    if (max_distance == NO_LOCAL_MINIMA) printf("There are no local minima in the file");
    else if (max_distance == ONE_LOCAL_MINIMUM) printf("Only one local minimum");
    else printf("Max distance between local minimum is %d\n", max_distance);    

    free(numbers);

    return 0;
}
