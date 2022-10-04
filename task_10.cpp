// Используя конструкцию директивы omp parallel for и omp critical
// определить минимальное и максимальное значения элементов двумерного массива.
// Реализовать аналог reduction для max и min.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

    int d[6][8];
    srand(time(NULL));

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            d[i][j] = rand() % 50;
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");

    int max = -1;
    int min = 51;

#pragma omp parallel for
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            if (d[i][j] >= min && d[i][j] <= max) {
                continue;
            }
#pragma omp critical
            if (min > d[i][j]) {
                min = d[i][j];
            }
            if (max < d[i][j]) {
                max = d[i][j];
            }
        }
    }
    printf("min is %d, max is %d\n", min, max);
}