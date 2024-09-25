#include "make_increasing.h"

int makeIncreasing(FILE * file) {
    double current, next;
    unsigned short used = 0;

    if (fscanf(file, "%lf", &current) != 1) {
        printf("File is empty!");
        return 0;
    }

    while (fscanf(file, "%lf", &next) == 1) {
        if ((next - current) < DISREG) {
            if (used == TRUE) return 0;
            used = TRUE;
        }
        current = next;
    }

    return 1;
}
