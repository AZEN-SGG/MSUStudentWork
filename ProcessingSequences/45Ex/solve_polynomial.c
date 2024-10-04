#include "solve_polynomial.h"

int solvePolynomial(FILE * file, double x, double * derivative, double * polynomial) {
    double current, i;

    if (fscanf(file, "%lf", &current) != 1) {
        printf("File is empty!\n");
        return 1;
    }

    *derivative = *polynomial = i = 0.;

    do {
        *polynomial += current * pow(x, i);
        *derivative += i * current * pow(x, i - 1);
        i++;
    } while (fscanf(file, "%lf", &current) == 1);

    return 0;
}
