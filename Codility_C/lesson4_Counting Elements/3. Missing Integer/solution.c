int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    int idx;
    int *B = (int *)malloc(sizeof(int) * N);
    for(idx = 0; idx < N; idx ++){
        B[idx] = 0;
    }
    
    for(idx = 0; idx < N; idx ++){
        if (A[idx] > 0 && A[idx] < N + 1){
            B[A[idx] - 1] = 1;
        }
    }
    
    for(idx = 0; idx < N; idx ++){
        if(!B[idx])
            return idx + 1;
    }
    return N + 1;       
}