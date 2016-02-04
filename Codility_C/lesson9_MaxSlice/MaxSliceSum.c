// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
// use long long to avoid arithmetic overflow
long long max(long long a, long long b){
    return a > b ? a : b;
}
    
long long solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    long long max_slice = A[0];
    long long  max_sum_idx = A[0];
    for(int idx = 1; idx < N; idx ++){
        max_sum_idx = max(A[idx], max_sum_idx + A[idx]);
        max_slice = max(max_slice, max_sum_idx);
    }
    return max_slice;
        
}