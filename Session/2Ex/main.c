#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define exp 1.e-6

typedef struct {
	double * arr;
	int len;
} array;

int min(int f, int s);
FILE * getFile(const char * name);
array getArray(FILE * file); 
bool compare(array first, array second);
int write(const char * str);

int min(int f, int s) {
	if (f > s) return s;
	return f;
}

FILE * getFile(const char * name) {
	FILE * file = fopen(name, "r");
	return file;
}

array getArray(FILE * file) {
	int size = 2, len = 0;
	double * arr = (double *)malloc(size * sizeof(double));
	double current;

	if (fscanf(file, "%lf", &current) != 1) return (array){NULL, -1};

	do {
		if (++len > size) {
			size *= 2;
			arr = (double *)realloc(arr, size * sizeof(double));
		}

		arr[len - 1] = current;
	} while (fscanf(file, "%lf", &current) == 1);
	
	return (array){arr, len};
}

bool compare(array first, array second) {
	int count = 0;
	
	for (int i = 0; i < min(first.len, second.len); ++i) {
		if (first.arr[i] - second.arr[i] > -exp) --count;
		else ++count;
	}

	if (count > 0) return true;
	else return false;
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
	array arr1, arr2;
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
