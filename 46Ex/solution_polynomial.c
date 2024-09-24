#include "solution_polynomial.h"

int solutionPolynomial(FILE * file, double x, double * derivative, double * polynomial) {
    double current;

    if (fscanf(file, "%lf", &current) != 1) {
        printf("File is empty!");
        return 1;
    }

    *derivative = *polynomial = 0;

    do {
        *derivative = *derivative * x + *polynomial;
        *polynomial = *polynomial * x + current;
        // c4x^3 + c3x^2 + c2x + c = c = c2x + c = c3x^2 + c2x + c = ...
    } while (fscanf(file, "%lf", &current) == 1);

    return 0;
}
