#include "seagwithsob.h"

void sort(double * array, int length) {
       double * zero = (double *)malloc(length * sizeof(double)); 
       double * unit = (double *)malloc(length * sizeof(double)); 

       int index;
       
       for (int j = 0; j < 63; ++j) {
	       index = 0;	

	       for (int i = 0; i < length; ++i) {
		       if ((*(unsigned long long*)&array[i] >> j) & 1) unit[index++] = array[i];
		       else zero[i - index] = array[i];
	       }

	       rewrite(array, zero, length - index, unit, index);
       }
       
       index = 0;	

       for (int i = 0; i < length; ++i) {
	       if ((*(unsigned long long*)&array[i] >> 63) & 1) unit[index++] = array[i];
	       else zero[i - index] = array[i];
       }

       for (int i = 0; i < index; ++i) array[i] = unit[index - i - 1];
       for (int i = index; i < length; ++i) array[i] = zero[i - index];
	
       free(zero);
       free(unit);
}

void rewrite(double * array, double * zero, int len_zero, double * unit, int len_unit) {
	for (int i = 0; i < len_zero; ++i) array[i] = zero[i];
	for (int i = len_zero; i < len_zero + len_unit; ++i) array[i] = unit[i - len_zero];
}
