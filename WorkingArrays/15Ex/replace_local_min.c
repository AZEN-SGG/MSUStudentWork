#include "replace_local_min.h"


int findAndReplaceLocalMin(double * numbers) {
    double min_element = min(numbers);
    int length = (int)numbers[0];
    unsigned start_end_minimum_index[3] = {0};
    do {
        unsigned start_index = (start_end_minimum_index[2]) ? start_end_minimum_index[2] : 1;
        findLocalMinimum(&numbers[start_index], length - start_index, start_end_minimum_index);
        replaceLocalMinimum(&numbers[start_index], start_end_minimum_index, min_element);
    } while start_end_minimum_index[0];

    for (int i = 0; i < 3; ++i) {
        printf("%d\n", start_end_minimum_index[i]);
    }

    return 0;
}


double min(double * numbers) {
    unsigned index_min_el = 0;
    for (int i = 1; i < (int)numbers[0]; ++i) {
        if ((numbers[index_min_el] - numbers[i]) > exp || !index_min_el) index_min_el = i;
    }
    return numbers[index_min_el];
}


void findLocalMinimum(double * numbers, unsigned length, unsigned *start_end_minimum_index) {
    unsigned local_length = 1;

    for (unsigned i = 1; i < length; ++i) {
        if (isEqual(numbers[i - 1], numbers[i])) {
            if (local_length) ++local_length;
        } else if ((numbers[i - 1] - numbers[i]) < exp) {
            if (local_length) {
                start_end_minimum_index[0] = i - local_length, start_end_minimum_index[1] = i - 1;
                local_length = 0;
            }
        } else {
            if (start_end_minimum_index[1]) {
                start_end_minimum_index[2] = i;
            }
        }
    }
}


bool isEqual(double first, double second) {
    return (fabs(first - second) < exp);
}


void replaceLocalMinimum(double * numbers, unsigned * start_end_minimum_index, double minimum) {
    unsigned start_i = start_end_minimum_index[0], end_i = start_end_minimum_index[1]
    numbers[start_i] = minimum;

    for (int i = 0)
}


