struct min{
    float value;
    int idx;
};

int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    int * sum =(int *)malloc(sizeof(int) * N);
    int idx;
    struct min min_2, min_3;
    float sum_2, sum_3;
    
    if(N == 2)
        return 0;
        
    sum[0] = A[0];
    for(idx = 1; idx < N; idx++){
        sum[idx] = sum[idx - 1] + A[idx];
    }
    
    min_2.value = sum[1], min_2.idx = 0;
    min_3.value = sum[2], min_3.idx = 0;
   
    for(idx = 0; idx < N - 2; idx ++){
        sum_2 = sum[idx + 2] - sum[idx];
        if(sum_2 < min_2.value){
            min_2.value = sum_2;
            min_2.idx = idx + 1;
        }
    }
    
    for(idx = 0; idx < N - 3; idx ++){
        sum_3 = sum[idx + 3] - sum[idx];
        if(sum_3 < min_3.value){
            min_3.value = sum_3;
            min_3.idx = idx + 1;
        }
    }
    
    min_2.value /= 2.0;
    min_3.value /= 3.0;
    
    if(min_2.value > min_3.value)
        return min_3.idx;
    else if (min_2.value < min_3.value)
        return min_2.idx;
    else 
        return min_2.idx > min_3.idx ? min_3.idx : min_2.idx;        
}