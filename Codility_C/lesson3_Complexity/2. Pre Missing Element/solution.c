int solution(int A[], int N) {
    if(N){
        long long sum_N = (long long)(1 + N + 1) * (N + 1) / 2;
        int idx;
        long long sum_A = 0;
        for(idx = 0; idx < N; idx++){
            sum_A += A[idx];
        }
        return sum_N - sum_A;
    } else return 1;
}