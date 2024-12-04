#include "tools.h"
#include "grouping.h"

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

	printArray(array, length);

	group(array, length);

	printArray(array, length);

 	free(orig_arr);

	return 0;
}
