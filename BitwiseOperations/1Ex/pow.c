#include "pow.h"

double bitwisePow(double number, int exponent) {
	double result = 1;

	while (exponent != 0) {
		if (exponent & 1) result *= number;
		number *= number;
		exponent >>= 1;
	}

	return result;
}
