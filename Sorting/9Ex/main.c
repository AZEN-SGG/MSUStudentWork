#include <stdio.h>
#include "seagwithsob.h"

int main() {
    // Тест 1: Набор чисел в обычном порядке
    double array1[] = {10.0, 9.00001, 8.0001, 7.001, 6.01, 5.1};
    int length1 = sizeof(array1) / sizeof(array1[0]);

    printf("Test 1 - Original array:\n");
    for (int i = 0; i < length1; i++) {
        printf("%lf ", array1[i]);
    }
    printf("\n");

    sort(array1, length1);

    printf("Test 1 - Sorted array:\n");
    for (int i = 0; i < length1; i++) {
        printf("%lf ", array1[i]);
    }
    printf("\n\n");

    // Тест 2: Все числа одинаковые
    double array2[] = {1.0, 1.0, 1.0, 1.0};
    int length2 = sizeof(array2) / sizeof(array2[0]);

    printf("Test 2 - Original array:\n");
    for (int i = 0; i < length2; i++) {
        printf("%lf ", array2[i]);
    }
    printf("\n");

    sort(array2, length2);

    printf("Test 2 - Sorted array:\n");
    for (int i = 0; i < length2; i++) {
        printf("%lf ", array2[i]);
    }
    printf("\n\n");

    // Тест 3: Набор чисел с отрицательными значениями
    double array3[] = {-3.0, -1.5, -7.2, 2.1, 0.0};
    int length3 = sizeof(array3) / sizeof(array3[0]);

    printf("Test 3 - Original array:\n");
    for (int i = 0; i < length3; i++) {
        printf("%lf ", array3[i]);
    }
    printf("\n");

    sort(array3, length3);

    printf("Test 3 - Sorted array:\n");
    for (int i = 0; i < length3; i++) {
        printf("%lf ", array3[i]);
    }
    printf("\n\n");

    // Тест 4: Набор чисел с разной экспонентой
    double array4[] = {1e-10, 1e+10, 1.0, 1e-5, 1e+5};
    int length4 = sizeof(array4) / sizeof(array4[0]);

    printf("Test 4 - Original array:\n");
    for (int i = 0; i < length4; i++) {
        printf("%e ", array4[i]);
    }
    printf("\n");

    sort(array4, length4);

    printf("Test 4 - Sorted array:\n");
    for (int i = 0; i < length4; i++) {
        printf("%e ", array4[i]);
    }
    printf("\n\n");

    // Тест 5: Граничные значения (минимальное и максимальное double)
    double array5[] = {1e-308, 1e+308, 0.0, -1e-308, -1e+308};
    int length5 = sizeof(array5) / sizeof(array5[0]);

    printf("Test 5 - Original array:\n");
    for (int i = 0; i < length5; i++) {
        printf("%e ", array5[i]);
    }
    printf("\n");

    sort(array5, length5);

    printf("Test 5 - Sorted array:\n");
    for (int i = 0; i < length5; i++) {
        printf("%e ", array5[i]);
    }
    printf("\n");

    return 0;
}
