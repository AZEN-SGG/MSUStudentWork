#include "equal.h"

int equal(double * numbers) {
    for (int i = 2; i < numbers[0]; i++) if (fabs(numbers[i] - numbers[i - 1]) > eps) return 1;
    return 0;
}
