int solution(int A[], int N){
    int i;
    int result = A[0];
    for(i = 1; i < N; i++){
        result ^= A[i];			// Use XOR to find out the odd occurrency.
    }
    return result;

}