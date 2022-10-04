#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <omp.h>
#include <windows.h>


int main() {
#pragma omp parallel
    Sleep(omp_get_num_threads() - omp_get_thread_num()*1000);
    printf("%d", omp_get_thread_num());
}