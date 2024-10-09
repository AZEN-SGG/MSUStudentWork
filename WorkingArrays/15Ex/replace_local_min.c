#include "replace_local_min.h"

int replaceLocalMin(double * numbers) {
    int length = numbers[0];
    unsigned final_num = 1;
    unsigned local_length = 1;

    for (int i = 2; i < length; ++i, ++final_num) {
        if (numbers[i - 1] == numbers[i]) { if (local_length) ++local_length;
        } else if (numbers[i - 1] < numbers[i]) {
            if (local_length) final_num -= (local_length - 1), local_length = 0;
        } else local_length = 1;
    }

    if ((numbers[length - 1] == numbers[length - 2]) && (local_length)) final_num -= (local_length - 1);

    return final_num;
}
