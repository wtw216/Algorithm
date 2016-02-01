int getMax(int a, int b){
    if(a < b) 
        return b;
    else 
        return a;
}

struct Results solution(int N, int A[], int M) {
    struct Results result;
    int * C = (int *)malloc(sizeof(int) * N);
    int idx;
    int current;
    int max = 0;
    int update = 0;
    for(idx = 0; idx < N; idx ++){
        C[idx] = 0;
    }
    for(idx = 0; idx < M; idx ++){
        current = A[idx];
        if(current != N + 1){
            C[current - 1] = getMax(update, C[current - 1]) + 1;
            max = getMax(max, C[current - 1]);
        } else {
            update = max;
        }
    }
    
    for(idx = 0; idx < N; idx ++){
        C[idx] = getMax(update, C[idx]);
    }    
    result.C = C;
    result.L = N;
    return result;
}