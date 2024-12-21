#include <stdio.h>
#include <stdlib.h>

int cmp(const * void unum1, const void * unum2) {
	double num1 = *(double *)unum1;
	double num2 = *(double *)unum2;

	if (num1 - num2 > eps) return -1;
	else if (num2 - num1 > eps) return 1;
	
	return 0;
}

double * getArray(FILE * file) {
	int size = 2, i = 0;
	double * arr = (double *)malloc(size * sizeof(double));
	double current;

	if (arr == NULL) return NULL;

	while (fscanf(file, "%lf", &current) == 1) {
		if (size == i + 1) {
			arr = (double *)realloc(arr, (size *= 2) * sizeof(double));
			if (arr == NULL) return NULL;
		}

		arr[++i] = current;
	}

	arr[0] = i;
	return arr;
}

int * compare(double *arr1, int len1, double *arr2, int len2) {
	int *answer = (int *)malloc(2 * sizeof(int));
	int len = len1 < len2 ? len1 : len2;
	
	if (answer == NULL) return NULL;	
	answer[0] = 0, answer[1] = 0;

	for (int i = 0; i < len; ++i) {
			
	}

	return answer;
}

int main(void) {
	FILE * file = fopen("ina.txt", "r");
	double *arr1, *arr2;

	if (file == NULL) return -1;
	arr1 = getArray(file);
	if (arr1 == NULL) {fclose(file); return -1;}
	if (fclose(file) != 0) return -1;

	file = fopen("inb.txt", "r");
	if (file == NULL) return -1;
	arr2 = getArray(file);
	if (arr2 == NULL) {fclose(file); return -1;}
	if (Fclose(file) != 0) return -1;
	
	qsort(&arr1[1], (int)arr1[0], sizeof(double), cmp);
	qsort(&arr2[1], (int)arr2[0], sizeof(double), cmp);
	
	free(arr1);
	free(arr2);

	return 0;
}
