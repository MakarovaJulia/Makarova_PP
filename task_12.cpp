#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main() {

    srand(time(NULL));

    int a[10];

    for (int i = 0; i < 10; i++){
        a[i] = rand() % 10;
        printf("%d ", a[i]);
    }

    int max = -1;
#pragma omp parallel for
    for (int i = 0; i < 10; i++) {
        if (a[i] % 7 == 0) {
#pragma omp critical
            {
                if(max < a[i]){
                    max = a[i];
                }
            }
        }
    }

    printf("\n%d\n", max);
}