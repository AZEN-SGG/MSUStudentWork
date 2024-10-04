#include "max_deviation.h"

int ipow(int number, int power) {
    int result = 1;
    for (int i = 0; i < power; i++) result *= number;
    return result;
}

int maxDeviation(FILE * file) {
   int current, sq_sum, sum, count, ar_mean;
   if (fscanf(file, "%d", &current) != 1) {
        printf("File is empty!");
        return -1;
   }

   sq_sum = sum = count = 0;

   do {
        sum += current;
        sq_sum += ipow(current, 2);
        count++;
   } while (fscanf(file, "%d", &current) == 1);

   ar_mean = sum / count;
   return ((sq_sum - (sum * ar_mean * 2)) / count) + ipow(ar_mean, 2);
}
