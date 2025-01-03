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


bool orderliness(double * array, int length) {
	for (int i = 1; i < length; ++i) if ((array[i] - array[i - 1]) < exp) return false;
	return true;
}

void testSortRandomArray(sort_op op) {
	int length;

	printf("Enter length of array: ");
	if (scanf("%d", &length) == 1) {
		double * array = (double *)malloc(length * sizeof(double));
		generate(array, length);
		testSort(array, length, op);
		free(array);
	} else {
		printf("Length not entered!\n");
	}
}

void generate(double * array, int length) {
	srand(time(NULL));

	for (int i = 0; i < length; ++i) {
		array[i] = ((rand() % 2) == 1 ? -1. : 1.) * 1.*rand() / (1. + rand()) * 1000;
	}
}

void testSort(double * array, int length, sort_op op) {
	int timer;

	printArray(array, length);

	timer = -clock();
	op(array, length);
	timer += clock();

    printArray(array, length);
	if (isSorted(array, length)) printf("The array was sorted for %lf sec.\n", (double)timer / CLOCKS_PER_SEC);
	else printf("The array was not sorted!\n");
}

void printArray(double * array, int length) {
	length = (length > 10) ? 10 : length;

	for (int i = 0; i < length; ++i) {
		printf("%.2lf ", array[i]);
	}

	printf("\n");
}

bool isSorted(double * array, int length) {
	for (int i = 0; i < length - 1; ++i) if (more(array[i], array[i + 1])) return false;
	return true;
}

bool more(double a, double b) {
	return (a - b) > exp;
}


