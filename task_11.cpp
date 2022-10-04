#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <omp.h>

#define MAX 30

int main() {

    int a[10];
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        a[i] = rand() % MAX;
        printf("%d ", a[i]);
    }

    printf("\n");
    int count = 0;
#pragma omp parallel for num_threads(8)
    for (int j = 0; j < 10; j++) {
        printf("%d %d %d\n", a[j], omp_get_thread_num(), count);
        if (a[j] % 9 == 0){
#pragma omp atomic
            count++;
        }
    }
    printf("\n");
    printf("count %d", count);
}