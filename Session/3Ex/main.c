#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define eps 1.e-6

double * getArray(FILE * file);
int level(double * arr1, int len1, double * arr2, int len2);
int contains(double * arr, int len, double num);

double * getArray(FILE * file) {
	int size = 2, i = 0;
	double * arr = (double *)malloc(size * sizeof(double));
	double current;

	if (arr == NULL) return NULL;

	while (fscanf(file, "%lf", &current) == 1) {
		if (size == (i + 1)) arr = (double *)realloc(arr, (size *= 2) * sizeof(double));
		arr[++i] = current;
	}

	arr = (double *)realloc(arr, (i + 1) * sizeof(double));
	arr[0] = i;

	if (i == 0) return NULL;
	return arr;
}

int level(double * arr1, int len1, double * arr2, int len2) {
	double start = 0, end = 0;
	int count = 0, len = len1 < len2 ? len2 : len1;

	for (int i = 0; i < len; ++i) {
		if (start - arr1[i % len2] > eps || (i == 0)) start = arr2[i % len2];
		if (arr1[i % len1] - end > eps || i == 0) end = arr1[i % len1];
	}



	for (int i = 0; i < len; ++i) {
		if (i < len1) if (arr1[i] - start > -eps && end - arr1[i] > -eps && (contains(arr2, len2, arr1[i]) == 0)) ++count;	
		if (i < len2) if (arr2[i] - start > -eps && end - arr2[i] > -eps) ++count;
	}

	return count;
}

int contains(double * arr, int len, double num) {
	for (int i = 0; i < len; ++i) if (fabs(arr[i] - num) < eps) return 1;
	return 0;
}

int main(void) {
	FILE * file = fopen("ina.txt", "r");
	double *arr1, *arr2;
	
	if (file == NULL) return -1;
	arr1 = getArray(file);
	if (fclose(file) != 0) return -1;
	if (arr1 == NULL) return -1;

	file = fopen("inb.txt", "r");
	if (file == NULL) return -1;
	arr2 = getArray(file);
	if (fclose(file) != 0) return -1;
	if (arr1 == NULL) return -1;

	file = fopen("output.txt", "w");
	if (file == NULL) return -1;
	if (fprintf(file, "%d", level(&arr1[1], (int)arr1[0], &arr2[1], (int)arr2[0])) <= 0) {fclose(file); return -1;}	
	if (fclose(file) != 0) return -1;
	
	free(arr1);
	free(arr2);

	return 0;
}

