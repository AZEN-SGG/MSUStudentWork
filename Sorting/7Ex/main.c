#include <stdio.h>
#include "quicksort.h"
#include "tools.h"
#include "stdlib.h"

int main(void)  {
	FILE * file = getFile();
	double * array;
	double * orig_arr;
	int length;

	if (file == NULL) return -1;
	array = getArray(file);
	if (array == NULL) return -2;
	length = (int)array[0] - 1;

	orig_arr = array;
	array = &array[1];
	testSort(array, length, quicksort);

	free(orig_arr);

	printf("\n");
	testSortRandomArray(quicksort);

	return 0;
}
