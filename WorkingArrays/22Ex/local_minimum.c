#include "local_minimum.h"

int transposition(double * numbers, unsigned * start_end)
{
    unsigned f_start = start_end[0], f_end = start_end[1], s_start = start_end[2], s_end = start_end[3];
    unsigned f_len = f_end - f_start + 1, s_len = s_end - s_start + 1, betw_len = s_start - f_end - 1;

    double buffer[start_end[3] - start_end[0] + 1];

    for (unsigned i = 0; i < s_len; ++i) buffer[i] = numbers[s_start + i];
    for (unsigned i = 0; i < betw_len; ++i) buffer[i + s_len] = numbers[f_end + 1 + i];
    for (unsigned i = 0; i < f_len; ++i) buffer[i + s_len + betw_len] = numbers[f_start + i];
    for (unsigned i = f_start; i <= s_end; ++i) numbers[i] = buffer[i - f_start];

    return 0;
}


int searching_loc_min(double * numbers)
{
    unsigned length = (int)numbers[0];
    unsigned start_end[4];
    int curr_len = 1;

    bool min_num = false;


    for (unsigned i = 2; i < length; ++i) {
        if (fabs(numbers[i] - numbers[i - 1]) < exp) {
            if (curr_len) ++curr_len;
        } else if ((numbers[i] - numbers[i - 1]) > exp) {
            if (curr_len) {
                // It is important to remember that numbers[0] is equal to the length of the list!
                start_end[0 + (min_num * 2)] = (i - curr_len), start_end[1 + (min_num * 2)] = i - 1;

                if (min_num) {
                    if (transposition(numbers, start_end)) return -1;
                    memset(start_end, 0, sizeof(start_end));
                }

                min_num = !min_num;
                curr_len = 0;
            }
        } else {
            curr_len = 1;
        }
    }

    if (curr_len) {
        start_end[0 + (min_num * 2)] = (length - curr_len), start_end[1 + (min_num * 2)] = length - 1;

        if (min_num && transposition(numbers, start_end)) return -1;
    }

    return 0;
}
