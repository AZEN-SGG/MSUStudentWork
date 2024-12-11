#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	double * arr;
	int len;
} arr;

#define exp 1.e-6

FILE * getFile(const char * name);
arr getArray(FILE * file);
bool compare(arr first, arr second);
int max(int f, int s);
int min(int f, int s); 
int write(const char * str);


FILE * getFile(const char * name) {
	FILE * file = fopen(name, "r");
	return file;
}


arr getArray(FILE * file) {
	int size = 2, len = 0;
	double * array = (double *)malloc(size * sizeof(double));
	double current;

	if (fscanf(file, "%lf", &current) != 1) return (arr){NULL, -1};
	
	do {
		if (++len > size) {
			size *= 2;
			array = (double *)realloc(array, size * sizeof(double));
		}

		array[len - 1] = current;
	} while (fscanf(file, "%lf", &current) == 1);
	
	return (arr){array, len};
}

bool compare(arr first, arr second) {
	int len = min(first.len, second.len);
	double maximf = 0, maxims = 0;

	for (int i = 0; i < len; ++i) {
		if (first.arr[i] - second.arr[i] > -exp) return false;
		maximf = max(maximf, first.arr[i]);
		maxims = max(maxims, second.arr[i]);
	}

	if (first.len > second.len) {
		for (int i = len; i < first.len; ++i) {
			if (first.arr[i] - maxims > -exp) return false;
		}
	} else {
		for (int i = len; i < second.len; ++i) {
			if (maximf - second.arr[i] > -exp) return false;
		}
	}

	return true;
}


int min(int f, int s) {
	if (f > s) return s;
	return f;
}

int max(int f, int s) {
	if (f < s) return s;
	return f;
}

int write(const char * str) {
	FILE * file = fopen("output.txt", "w");
	if (file == NULL) return -1;
	
	if (fprintf(file, "%s", str) < 1) {
		fclose(file);
		return -1;
	}
	
	if (fclose(file) != 0) return -1;
	
	return 0;
}

int main(void) {
	arr arr1, arr2;
	FILE * file;
	bool answer;

	file = getFile("ina.txt");
	if (file == NULL) return -1;
	arr1 = getArray(file);
	if (fclose(file) != 0) return -1;
	if (arr1.arr == NULL) return -1;
	
	

	file = getFile("inb.txt");
	if (file == NULL) return -1;
	arr2 = getArray(file);
	if (fclose(file) != 0) return -1;
	if (arr2.arr == NULL) return -1;
	
	answer = compare(arr1, arr2);

	if (answer) return write("YES");
	else return write("NO");
}

