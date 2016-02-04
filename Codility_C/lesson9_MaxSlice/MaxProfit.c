// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
int max(int a, int b){
    return a > b ? a : b;
}
int min(int a, int b){
    return a < b ? a : b;
}
int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    int max_profit = 0;
    int min_share = A[0];

    for(int idx = 1; idx < N ; idx ++){
        min_share = min(min_share, A[idx]);
        max_profit = max(max_profit, A[idx] - min_share);
    }
    
    if(max_profit < 0)
        return 0;
    else 
        return max_profit;
}