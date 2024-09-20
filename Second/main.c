#include <stdio.h>
#include "count_func.h"

int main(void) {
    FILE * file;
    char filename[50];

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error file!\n");
        return 1;
    }

    printf("Answer: %d", countWords(file));

    return 0;
}
