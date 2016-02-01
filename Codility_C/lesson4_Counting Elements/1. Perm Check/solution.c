int solution(int A[], int N) {
    int idx;
    int *B = (int *)malloc(sizeof(int) * N);
    for(idx = 0; idx < N; idx++)   // Check the MAX, it should not be larger than N.
        if(A[idx] > N) 
            return 0;
            
    for(idx = 0; idx < N; idx++)
        B[idx] = 0;
        
    for(idx = 0; idx < N; idx++)
        B[A[idx]-1] = 1;
    
    for(idx = 0; idx < N; idx++)
        if(!B[idx])
            return 0;
            
    return 1;
    // write your code in C99 (gcc 4.8.2)
}