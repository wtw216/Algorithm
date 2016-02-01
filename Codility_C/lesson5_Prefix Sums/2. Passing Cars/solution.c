int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    long long count = 0;
    int sum = 0;
    int idx;
    for(idx = 0; idx < N; idx++){
        sum += A[idx];
    }
    for(idx = 0; idx < N; idx++){
        if(A[idx])
            sum --;
        else
            count += sum;
    }
    
    if(count > 1000000000)
        count = -1;
        
    return count;
}