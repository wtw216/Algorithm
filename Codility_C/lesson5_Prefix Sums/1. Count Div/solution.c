int solution(int A, int B, int K) {
    // write your code in C99 (gcc 4.8.2)
    int count = 0;
    count = B / K - A / K;
    if(A % K == 0)
        count ++;
    return count;
}