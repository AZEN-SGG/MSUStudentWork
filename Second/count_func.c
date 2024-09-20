#include "count_func.h"

int locatedIn(char symb) {
    char numbers[] = NUMBERS;

    for (int i = 0; i < 5; i++) {
        if (symb == numbers[i]) {
            return 1;
        }
    }

    return 0;
}

int countWords(FILE * file) {
    int located, now, count;
    char current;

    located = IN;
    now = OUT;
    count = 0;

    if (fscanf(file, "%c", &current) != 1) {
        printf("File is empty\n");
        return -1;
    }
    do {
        if (current == '\n' || current == '\t' || current == ' ') {
            if (now == IN && located == IN) {
                count += 1;
            }
            now = OUT;
        } else {
            if (now == OUT) {
                now = IN;
                located = IN;
            }
            if (locatedIn(current) == 0) {
                located = OUT;
            }
        }
    } while (fscanf(file, "%c", &current) == 1);

    return count;
}
