#include "count_elements.h"

int detectNumber(double number, int count) {
    if ((1 - number > INACCURACY) || (number - 5 > INACCURACY)) {
            return 0;
    }
    for (int i = 1; i < 6; i++) {
        if (fabs(number - i) < INACCURACY) return 1 << (i - 1); 
    }
    return 0;
}

int summa(int info_count) {
    int count = 0;

    for (;info_count;info_count >>= 1) {
	   count += info_count & 1; 
    }
    
    return count;
}

int countElements(FILE * file) {
    double current;
    int count;

    if (fscanf(file, "%lf", &current) != 1)
    {
        printf("File is empty!\n");
        return -1;
    }
	
    count = 0;
    do {
        count |= detectNumber(current, count);
    } while (fscanf(file, "%lf", &current) == 1);

    return summa(count);
}
