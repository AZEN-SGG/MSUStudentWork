#include "tools.h"

FILE * getFile(void) {
	char filename[50];

	printf("Enter file name: ");
	if (scanf("%s", filename) == 1) {
		FILE * file = fopen(filename, "r");
		if (file == NULL) {
			printf("Error file!\n)");
			return NULL;
		} else {
			return file;
		}
	} else {
		printf("Empty name!\n");
		return NULL;
	}
}

double * getArray(FILE * file) {
	int i, size = 2;
	double * array = NULL;
	double current;

	if (fscanf(file, "%lf", &current) != 1) {
		printf("File if empty!");
		return array;
	}

	array = (double *)malloc(size * sizeof(double));

	i = 1;
	do {
		if (i >= size) {
			size *= 2;
			array = (double *)realloc(array, sizeof(double) * size);
		}
		array[i] = current;
		++i;
	} while (fscanf(file, "%lf", &current) == 1);

	array = (double *)realloc(array, sizeof(double) * i);
	array[0] = (double)i;

	return array;
}
