#include "quicksort.h"

void quicksort(double * array, int length) {
	int head, si = 0, ei = length - 1;
	double temp;

	srand(time(NULL));
	head = rand() % length;

	do {
		while (array[si] < array[head]) ++si;
		while (array[ei] > array[head]) --ei;

		if (si < ei) {
			temp = array[si];
			array[si] = array[ei];
			array[ei] = temp;

			if (si == head || ei == head) head = si == head ? ei++ : si--;
			++si, --ei;
		}
	} while (si < ei);

	if (si > 1) quicksort(array, si);
	if (ei < length - 2) quicksort(&array[head + 1], length - ei - 1);
}
