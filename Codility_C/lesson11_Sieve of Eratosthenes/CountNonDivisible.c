// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

struct Results solution(int A[], int N) {
    struct Results result;
    // write your code in C99 (gcc 4.8.2)
    // 1. Record the frequency of the elements in array A
    int Freq[2 * N + 1];
    for(int idx = 0; idx < 2 * N + 1; idx++){ 
        Freq[idx] = 0;
    }
    for(int idx = 0; idx < N; idx ++){
        Freq[A[idx]]++;
    }

    // 2. Sieve of Eratosthenes
    int F[2 * N + 1];
    for(int idx = 0; idx < 2 * N + 1; idx++){ 
        F[idx] = 0;
    }
    for(int num = 2; num * num <= 2 * N; num++){
        int start = num * num;
        while(start <= 2 * N){
            F[start] = num;
            start += num;
        }
    }
    
    // 3. Count
    result.C = (int*) malloc(sizeof(int) * N);
    for(int idx = 0; idx < N; idx ++){
        result.C[idx] = 0;
    }
    
    for(int idx = 0; idx < N; idx ++){
        int num = A[idx];
        int divisor;

        result.C[idx] += Freq[1];
        if (num != 1)
            result.C[idx] += Freq[num];
        
        if(F[num] != 0){
            for(int start = 2; start * start <= num; start++){
                if(num % start == 0 && start * start != num){
                    result.C[idx] += Freq[start];
                    result.C[idx] += Freq[num / start];
                }
                else if (num % start == 0 && start * start == num){
                    result.C[idx] += Freq[start];
                }
            }
        }
            
        result.C[idx] = N - result.C[idx];
    }

    result.L = N;
    return result;
}