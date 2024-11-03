#include <stdio.h>
#include "pow.h"

#define IOE "InputError!\n"

int main(void) {
	double number;
	int power;

	printf("Enter your number: ");
	if (scanf("%lf", &number) == 0) {
		printf("%s", IOE);
		return -1;	
	}

	printf("Enter the power: ");
	if (scanf("%d", &power) == 0) {
	       printf("%s", IOE);
	       return -2;
	}
	
	printf("The number %.1lf to the power of %d is %.1lf\n", number, power, bitwisePow(number, power));
	return 0;
}
