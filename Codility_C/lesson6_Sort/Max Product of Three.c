#include "stdlib.h"
#include "stdio.h"

int cmp(const void *a, const void*b){
    return (*(int *)a - *(int *)b);
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    int max1, max2;
    qsort(A, N, sizeof(int), cmp);
    max1 = A[0] * A[1] * A[N - 1];
    max2 = A[N - 3] * A[N - 2] * A[N - 1];
    return max1 > max2 ? max1 : max2;
}