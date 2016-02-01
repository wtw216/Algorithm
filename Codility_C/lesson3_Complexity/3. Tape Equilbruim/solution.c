long long sumArray(int A[], int start, int end){
    int idx;
    long long sum = 0;
    for(idx = start; idx <= end; idx++){
        sum += A[idx];
    }
    return sum;
}
        
int solution(int A[], int N) {
    long long sum_A = sumArray(A, 0, N-1);
    long long sum_part1 = A[0];
    long long sum_part2 = sum_A - sum_part1;
    long long diff = abs(sum_part1 - sum_part2);
    long long temp = 0;
    int P;
    for(P = 2; P < N; P++){
        sum_part1 += A[P-1];
        sum_part2 -= A[P-1];
        temp = abs(sum_part1 - sum_part2);
        if (temp < diff)
            diff = temp;
    }
    return diff;
        
    // write your code in C99 (gcc 4.8.2)
}