#include "exp_weigh_avg.h"

int betweenZeroOne(double lambda) {
    if ((lambda < FAULT) || ((1 - lambda) <= FAULT)) return 0;
    return 1;
}

double expWeigthAvg(FILE * file, double lambda) {
    double current, i, eavg, lambda_n;
    if (fscanf(file, "%lf", &current) != 1) {
        printf("File is empty!\n");
        return -1.;
    }

    i = 1.;
    eavg = 0.;

    do {
        eavg += current * pow(lambda, -i);
        i++;
    } while (fscanf(file, "%lf", &current) == 1);
    lambda_n = pow(lambda, i - 1);
    return (eavg * lambda_n) * ((1 - lambda) / (1 - lambda_n));
}
