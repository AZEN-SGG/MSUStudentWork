#include "max_distance.h"

int maxDistance(double * array, int length) {
	int end_first_min, start_last_min, len_local;
	
	end_first_min = 0;
	start_last_min = 0;
	len_local = 1;

	for (int i = 1; i < length; ++i) {
		if (len_local != OUT) {
			 if ((array[i] - array[i - 1]) < -exp) {
				 len_local = 1;
			 } else if ((array[i] - array[i - 1]) > exp) {
				 if (end_first_min == OUT) end_first_min = i;
				 else if (start_last_min == OUT) start_last_min = i - len_local;
				 len_local = 0;
			 } else {++len_local;}
		} else {
			if ((array[i] - array[i - 1]) < -exp) len_local = 1;
		}
	}

	if (len_local != OUT) start_last_min = length - len_local;
	
	if (end_first_min == 0) return NO_LOCAL_MINIMA;
	else if (start_last_min == 0) return ONE_LOCAL_MINIMUM;
	else return start_last_min - end_first_min;	
}
			
