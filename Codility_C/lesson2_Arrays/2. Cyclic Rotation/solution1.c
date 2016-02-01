/* time=O(log(N)), space=O(log(N)) */
struct Results solution(int A[], int N, int K) {
    struct Results result;
    int *B = (int *)malloc(N * sizeof(int));
    int idx_a, idx_b;
    for(idx_a = 0; idx_a < N; idx_a++){
        idx_b = (idx_a + K) % N;
        B[idx_b] = A[idx_a];
    }   
    for(idx_a = 0; idx_a < N; idx_a++){
        A[idx_a] = B[idx_a];
    }
    free(B);
    result.A = A;
    result.N = N;
    return result;
    
}