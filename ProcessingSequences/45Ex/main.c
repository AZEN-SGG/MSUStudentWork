#include <stdio.h>
#include "tools.h"
#include "solve_polynomial.h"

/*
Problem 45
Coordinate X: 2
Solution: 129
Derivative: 222
*/

int main(void) {
    double derivative, polynomial, x;
    FILE * file = getFile();
    if (file == NULL) return 1;

    printf("Enter x coordinat: ");
    scanf("%lf", &x);

    if (solvePolynomial(file, x, &derivative, &polynomial)) return 1;
    printf("Solve of the polynomial is %lf\nSolve of its derivative is %lf\n", polynomial, derivative);
    return 0;
}
