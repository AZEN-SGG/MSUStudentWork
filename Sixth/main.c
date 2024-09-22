#include <stdio.h>
#include "tools.h"
#include "exp_weigh_avg.h"

/*
Задание 38
Пример:
5 4 3 2 1 и лямбда: 0.5
Ответ: 1.83...
*/

int main(void) {
    double lambda;
    FILE * file = getFile();

    printf("Enter lambda: ");
    scanf("%lf", &lambda);
    if (betweenZeroOne(lambda) == FALSE) {
        printf("Lambda is not between 0 to 1!");
        return -1;
    }

    printf("The exponentially weighted average is %lf\n", expWeigthAvg(file, lambda));
    return 0;
}
