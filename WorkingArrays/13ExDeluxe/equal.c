#include "equal.h"

int canFixArray(double * numbers) {
    unsigned short indexNonEqualNumber = 0, indexSecondNonEqualNumber = 0, numberDiffernce = 0, length = (int)numbers[0];

    for (int i = 2; i < length; ++i) {
        if (!isEqual(numbers[i - 1], numbers[i])) {
            numberDiffernce++;
            if (!indexNonEqualNumber) indexNonEqualNumber = i;
            else if (!indexSecondNonEqualNumber) indexSecondNonEqualNumber = i - 1;
        }
    }

    if (numberDiffernce > 2) return -1;
    else if (numberDiffernce == 2 && (!isEqual(numbers[indexNonEqualNumber - 1], numbers[length - 1]) || indexNonEqualNumber != indexSecondNonEqualNumber)) return -2;
    else if (numberDiffernce == 1 && ((indexNonEqualNumber != 2) && (indexNonEqualNumber != (length - 1)))) return -3;

    return 0;
}

bool isEqual(double first, double second) {
    return (fabs(first - second) < eps);
}
