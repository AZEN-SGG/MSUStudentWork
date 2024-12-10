#include "grouping.h"

void group(double * array, int length) {
    	double temp;
	int negative = 0, last_index = length - 1, limit;

	for (int i = 0; i <= last_index - negative; ++i) {	
		if (array[i] < -exp) limit = length - 2, --last_index;
		else if (fabs(array[i]) < exp) limit = last_index - 1, ++negative;
		else limit = -1;
		
		if (limit != -1) {
			for (int j = limit; j >= i; --j) {
				temp = array[j];
				array[j] = array[limit + 1];
				array[limit + 1] = temp;
			}
		
			--i;
		}
	}
}

void printArray(double * array, int length) {
	for (int i = 0; i < length; ++i) {
		printf("%.2lf ", array[i]);
	}
	printf("\n");
}
