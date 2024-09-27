#include <stdio.h>
#include "tools.h"

#define eps = 1.e-10

double fmax(double a, double b) {
    if ((a - b) > eps) return a;
    return b;
}

double fmin(double a, double b) {
    if ((a - b) > eps) return b;
    return a;
}

int countBetween(FILE * file);

int countBetween(FILE * file) {
    double first, second, current;
    int count = 0;

    if ((fscanf(file, "%lf", &first) != 1) || (fscanf(file, "%lf", &second) != 1) {
        printf("There is NO 2 variables\n");
        return 1
    }

    current = fmax(first, second);
    second = fmin(first, second);
    first = current;

    while (fscanf(file, "%lf" &current) == 1) {
        if (((current - second) > eps) && ((first - current) < eps)) count++;
    }
    return count;
}

int main(void) {
    FILE * file = getFile();
    if (file == NULL) return 1;

    printf("Count of number between first and second is %d", countBetween(file));
}
