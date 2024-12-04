#include "grouping.h"

void group(double * array, int length) {
	negativeToRight(array, length);
	zeroesToCenter(array, length);
}

void negativeToRight(double * array, int length) {
    double temp;
	int negative = 0, last_index = length - 1;

	for (int i = 0; i <= last_index - negative; ++i) {
	    // Так как мы передвигаем каждый отрицательный эл-нт в конец
	    // То тогда нам не нужно проверять последний эл-нт (т.к. он отрицательный) - поэтому я его пропускаю - -negative
		if (array[i] < 0) {
			for (int j = length - 2; j >= i; --j) {
				// Сначала последний эл-нт копируется в предпоследний, а предпоследний в последний
				// Далее каждый следующий j-й элемент заменяется тем, что находится на месте последнего, а последний элемент заменяется на j
				// Так шаг за шагов элементы переставляются и наш i-й элемент оказывается на месте последнего (типа ЭП2)
				temp = array[j];
				array[j] = array[last_index];
				array[last_index] = temp;
            }

            --i, ++negative;
		}
	}
}

void zeroesToCenter(double * array, int length) {
    // Аналогичный способ перемещения эл-тов, но только не в конец, а в место между отрицательными и положительными числами
    double temp;
    int zeroes = 0, last_index = 0;

    while (array[last_index] >= 0 && last_index < length) ++last_index;
    // last_index < length - очень важен, так как если нет отрицательных чисел, то цикл уёдет в бесконечность
    --last_index; // Так как изначально указывает на первый отрицательный элемент, а нам нужен последний положительный

    for (int i = 0; i <= last_index - zeroes; ++i) {
		if (fabs(array[i]) < eps) {
			for (int j = last_index - 1; j >= i; --j) {
				temp = array[j];
				array[j] = array[last_index];
				array[last_index] = temp;
            }

            --i, ++zeroes;
		}
	}
}


void printArray(double * array, int length) {
	for (int i = 0; i < length; ++i) {
		printf("%.2lf ", array[i]);
	}
	printf("\n");
}
