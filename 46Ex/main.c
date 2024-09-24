#include <stdio.h>
#include "tools.h"

/*
Example: 5 4 3 2 1
x: 2

Answer: 80 + 32 + 12 + 4 + 1 = 129
        160 + 48 + 12 + 2 = 222
*/

int solutionPolynomial(FILE * file, double x, double * derivative, double * polynomial);

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

int main(void) {
    double x, derivative, polynomial;
    FILE * file = getFile();
    if (file == NULL) return 1;

    printf("Enter the x cordinate: ");
    scanf("%lf", &x);
    if (solutionPolynomial(file, x, &derivative, &polynomial)) return 1;
    printf("The solution of the polynomial is %.0lf\nThe solution of the derivative is %.0lf", polynomial, derivative);
}
