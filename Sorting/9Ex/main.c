#include <stdio.h>
#include "seagwithsob.h"
#include "tools.h"
#include <stdlib.h>

int main()  {	
	FILE * file = getFile();
	double * array;
	int length;
	
	if (file == NULL) return -1;
	array = getArray(file);
	if (array == NULL) return -2;
	length = (int)array[0];

	array = &array[1];
	printArray(array, length);
	sort(array, length);
	printArray(array, length);

	printf("\n");
	randomArray();

	return 0;
}
