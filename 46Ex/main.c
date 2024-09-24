#include <stdio.h>
#include "tools.h"
#include "solution_polynomial.h"

/*
Example: 5 4 3 2 1
x: 2

Answer: 80 + 32 + 12 + 4 + 1 = 129
        160 + 48 + 12 + 2 = 222
*/

int main(void) {
    double x, derivative, polynomial;
    FILE * file = getFile();
    if (file == NULL) return 1;

    printf("Enter the x cordinate: ");
    scanf("%lf", &x);
    if (solutionPolynomial(file, x, &derivative, &polynomial)) return 1;
    printf("The solution of the polynomial is %.0lf\nThe solution of the derivative is %.0lf", polynomial, derivative);
}
