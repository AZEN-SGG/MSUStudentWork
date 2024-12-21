#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define eps 1.e-6

int ctv(const void * unum1, const void * unum2);
double * getArray(FILE * file);
int isContains(double * arr1, int len1, double * arr2, int len2);
int write(const char * str);

int ctv(const void * unum1, const void * unum2) {
	double num1 = *(double *)unum1;	
	double num2 = *(double *)unum2;
	
	if (num1 - num2 > eps) return 1;
	else if (num2 - num1 > eps) return -1;
	else return 0;
}

double * getArray(FILE * file) {
	int size = 2, i = 0;
	double * arr = (double *)malloc(size * sizeof(double));
	double current;

	if (arr == NULL) return NULL;


	while (fscanf(file, "%lf", &current) == 1) {
		if (size == (i + 1)) {
			arr = (double *)realloc(arr, (size *= 2) * sizeof(double));
			if (arr == NULL) return NULL;
		}
		arr[++i] = current;
	}

	arr[0] = i;
	return arr;
}

int isContains(double * arr1, int len1, double * arr2, int len2) {
	for (int i = 0, k = 0; i < len2; ++i, ++k) {
		if (fabs(arr2[i] - arr1[k]) < eps) {
			if (k + 1 == len1) return 1;
		} else if (len2 - i <= len1) return 0;
		else k = -1;
	}
	
	return 0;
}

int write(const char * str) {
	FILE * file = fopen("output.txt", "w");
	
	if (file == NULL) return -1;
	if (fprintf(file, "%s", str) < 1) {fclose(file); return -1;}
	if (fclose(file) != 0) return -1;

	return 0;
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
	if (fclose(file) != 0) return -1;

	if ((int)arr2[0] < (int)arr1[0]) return -1;

	qsort(&arr1[1], (int)arr1[0], sizeof(double), ctv);
	qsort(&arr2[1], (int)arr2[0], sizeof(double), ctv);
	
	if (isContains(&arr1[1], (int)arr1[0], &arr2[1], (int)arr2[0]) == 0) {
		free(arr1);
		free(arr2);
		
		return write("NO");
	} else {	
		free(arr1);
		free(arr2);
		
		return write("YES");
	}
}
