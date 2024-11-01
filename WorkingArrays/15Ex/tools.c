#include "tools.h"

FILE * getFile(void)
{
    FILE * file;
    char filename[50];

    printf("Enter filename: ");
    if (scanf("%s", filename) == 1)
    {
        file = fopen(filename, "r");
        if (file == NULL) {
            printf("Error file!\n");
            return NULL;
        } else {
            return file;
        }
    } else
    {
        printf("Empty name!\n");
        return NULL;
    }
}

double * getList(FILE * file) {
    double current;
    int i, length = 2;
    double * numbers = NULL;

    if (fscanf(file, "%lf", &current) != 1) {
        printf("File is empty!");
        return numbers;
    }

    numbers = (double *)malloc(length * sizeof(double));
    i = 1;

    do {
        if (i >= length) {
            length *= 2;
            numbers = (double *)realloc(numbers, (length * sizeof(double)));
        }
        numbers[i] = current;
        i++;
    } while (fscanf(file, "%lf", &current) == 1);

    numbers = (double *)realloc(numbers, i * sizeof(double));
    numbers[0] = i;
    return numbers;
}

void outputArray(double * array, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%.1lf\n", array[i]);
    }
    printf("\n");
}
