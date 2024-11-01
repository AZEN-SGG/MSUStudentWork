#include "replace_local_min.h"

void test_findLocalMin(void) {
	int expected_start, expected_length, expected_next, length = 10;
	double array[] = {2, 1, 1, 0, 0, 0, 2, 2, 3, 2};
	int start_len_loc_min[3] = {-1, -2, -3};

	findLocalMin(array, length, start_len_loc_min);

	for (int i = 0; i < length; ++i) printf("%.1lf ", array[i]);
	printf("\n");
	for (int i = 0; i < 3; ++i) printf("%d\n", start_len_loc_min[i]);

	expected_start = 3, expected_length = 3, expected_next = 9;

	if (start_len_loc_min[0] != expected_start) printf("expected start: %d, but got: %d\n", expected_start, start_len_loc_min[0]);
	if (start_len_loc_min[1] != expected_length) printf("expected length: %d, but got: %d\n", expected_length, start_len_loc_min[1]);
    if (start_len_loc_min[2] != expected_next) printf("expected next min: %d, but got: %d\n", expected_next, start_len_loc_min[2]);
}

void test_replace(void) {
	int from, len_replaceable, length = 7;
	double array[] = {1, 0, 0, 0, 0, 3, 3};
	double wherewith;

	wherewith = -100;
	from = 1;
	len_replaceable = 4;

	replace(array, length, wherewith, from, len_replaceable);

	for (int i = 0; i < length; ++i) printf("%.1lf ", array[i]);
	printf("\n");

	if (array[from] != wherewith) printf("Expected replace to %.1lf, but got: %.1lf\n", wherewith, array[from]);
}
