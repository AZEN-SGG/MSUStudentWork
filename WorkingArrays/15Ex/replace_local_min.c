#include "replace_local_min.h"

unsigned find_replace_local_min(double * array, int length) {
	int start_length_next_min[3];
	unsigned deleted = 0, have_min = 0;
	double min_element = min(array, length);

	do {
		unsigned changed_len;
		findLocalMin(&array[have_min + deleted], length - (have_min + deleted), start_length_next_min);
		replace(&array[have_min + deleted], length - (have_min + deleted), min_element, start_length_next_min[0], start_length_next_min[1]);

		deleted += have_min;
		changed_len = start_length_next_min[1] - 1;
		length -= changed_len;
		have_min = (start_length_next_min[2]) ? start_length_next_min[2] - changed_len : 0;
	} while (have_min);

	return unbs(length);
}

double min(double * array, int length) {
	unsigned min_index = 0;

	for (int i = 1; i < length; ++i) if (array[min_index] > array[i]) min_index = i;

	return array[min_index];
}

unsigned findLocalMin(double * num_array, int length, int * start_length_local_min) {
	unsigned index_next_min = 0;
	int len_local_min = 1;
	bool found = false;

	start_length_local_min[0] = 0, start_length_local_min[1] = 0, start_length_local_min[2] = 0;

	for (int i = 1; i < length; ++i) {
		if (len_local_min) {
			if (isEqual(num_array[i - 1], num_array[i])) {
				len_local_min++;
			} else if ((num_array[i] - num_array[i - 1]) < exp) {
				len_local_min = 1;
			} else {
				start_length_local_min[0] = i - len_local_min;
				start_length_local_min[1] = len_local_min;

				found = true;
                		len_local_min = 0;
			}
		} else {
			if ((num_array[i] - num_array[i - 1]) < -exp) {
				if (found) {
					start_length_local_min[2] = i;
					index_next_min = i;
					break;
				}
				len_local_min = 1;
			}
		}
	}

	if (len_local_min && !found) start_length_local_min[0] = length - len_local_min, start_length_local_min[1] = len_local_min;
	return index_next_min;
}

bool isEqual(double first, double second) {
	if (fabs(first - second) < exp) return true;
	return false;
}

void replace(double * array, int length, double wherewith, int from, int len_replaceable) {
	array[from] = wherewith;

	for (int i = from + len_replaceable; i < length ; ++i) {
		array[i - len_replaceable + 1] = array[i];
	}
}

unsigned unbs(int number) {
	return (unsigned int)((number < 0) ? -number : number);
}
