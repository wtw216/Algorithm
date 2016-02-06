// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

struct Results solution(int N, int P[], int Q[], int M) {
    struct Results result;
    // write your code in C99 (gcc 4.8.2)
    
    //1. record the F array;
    int F[N + 1];
    for(int idx = 0; idx <= N; idx ++){
        F[idx] = 0;
    }
    
    for(int num = 2; num * num <= N; num ++){
        int start = num * num;
        while(start <= N){
            if(F[start] == 0)
                F[start] = num;
            start += num;
        }
    }
    
    //2. Prefix Sum
    int PS[N + 1];
    int sum = 0;
    for(int idx = 0; idx <= N; idx ++){
        if(F[idx] != 0 && F[idx / F[idx]] == 0)
            sum++;
        PS[idx] = sum;
    //    printf("F[%d]:%d\tPS[%d]:%d\n",idx,F[idx],idx,PS[idx]);
    }
       
    //3. Query
    result.A = (int *)malloc(sizeof(int) * M);
    for(int idx = 0; idx < M; idx ++){
        int end = Q[idx];
        int start = P[idx];
        result.A[idx] = PS[end] - PS[start];
        if(F[start] != 0 && F[start / F[start]] == 0)
            result.A[idx]++;
    }

    result.M = M;
    return result;
}