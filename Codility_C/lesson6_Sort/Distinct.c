#include "stdlib.h"
#include "stdio.h"
int cmp(const void* a, const void* b){
    return (*(int *)a - *(int *)b);
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    int idx;
    int count = 1;
    if(N < 2)
        return N;
        
    // N is no less than 2.
    qsort(A, N, sizeof(int), cmp);

    for(idx = 0; idx < N - 1; idx ++){
        if(A[idx] != A[idx + 1])
            count++;
    }
    return count;
}