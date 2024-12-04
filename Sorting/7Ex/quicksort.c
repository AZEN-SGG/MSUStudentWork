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

	if (si > 1) {
        if (si < 7) bubble(array, si);
        else quicksort(array, si);
    }
	if (ei < length - 2) {
        if (si < 7) bubble(&array[head + 1], length - ei - 1);
        else quicksort(&array[head + 1], length - ei - 1);
    }
}

void bubble(double *arr, int length) {
    double temp; 
    bool swapped;
    
    for (int i = 0; i < length; ++i) {
        swapped = false;
        
        for (int j = 0; j < length - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swapped = true;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        
        if (!swapped) break;
    }
}
