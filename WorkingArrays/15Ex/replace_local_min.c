#include "replace_local_min.h"

double min(double * numbers) {
    
    for (int i = 1; i < length; ++i) {
        
    }
}

int replaceLocalMin(double * numbers) {
    int length = numbers[0];
    unsigned final_num = 1;
    unsigned local_length = 1;

    for (int i = 2; i < length; ++i, ++final_num) {
        if (fabs(numbers[i - 1] - numbers[i]) < exp) { if (local_length) ++local_length;
        } else if ((numbers[i] - numbers[i - 1]) > exp) {
            if (local_length) final_num -= (local_length - 1), local_length = 0;
        } else local_length = 1;
    }

    if ((fabs(numbers[length - 1] - numbers[length - 2]) < exp) && (local_length)) final_num -= (local_length - 1);

    return final_num;
}
