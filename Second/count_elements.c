#include "count_elements.h"

double detectNumber(double number, double count) {
    if ((1 - number > INACCURACY) || (number - 5 > INACCURACY)) {
            return 0;
    }
    for (double i = 1.; i < 6; i++) {
        // printf("%lf ? \n", abs(number - i));
        if (fabs(number - i) < INACCURACY) return (1 - (int)(fmod(count, pow(10., i)) / pow(10., i - 1))) * pow(10., i - 1);
    }
    return 0;
}

double summa(double info_count) {
    int count = 0.;

    for (int i = 0; i < 5; i++) {
        count += fmod(info_count, 10.);
        info_count /= 10;
    }
    return count;
}

double countElements(FILE * file) {
    double current;
    double count = 100000.;

    if (fscanf(file, "%lf", &current) != 1)
    {
        printf("File is empty!\n");
        return -1;
    }
    do {
        count += detectNumber(current, count);
    } while (fscanf(file, "%lf", &current) == 1);

    return summa(count);
}
