#include "stdlib.h"
#include "stdio.h"
int cmp(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}
int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    int idx;
    long a, b, c;
    if(N < 3)
        return 0;
    qsort(A, N, sizeof(int), cmp);
    for(idx = 0; idx < N - 2; idx ++){
        a = A[idx]; 
        b = A[idx + 1];
        c = A[idx + 2];
        if(a + b > c && a + c > b && b + c > a)
            return 1;
    }
    return 0;
}