// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
int cmp(const void *a, const void  *b){
    if(*(long long*)a > *(long long*)b)
        return 1;
    else if (*(long long*)a > *(long long*)b)
        return -1;
    else 
        return 0;
}

int insert_bsearch(long long *A, int N, long long key){
    int start = 0;
    int end = N - 1;
    int middle = (end + start) / 2;
    
    while(start != end - 1){
        if(key < A[middle])
            end = middle;
        else
            start = middle;
            
        middle = (end + start) / 2;
    }
    if(key >= A[end]) return end + 1;
    if(key < A[start]) return start;
    else return end;
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    long long B[N], C[N];
    int idx;
    int count = 0;
    int pos;
    if(N < 2) return 0;
    
    for(idx = 0; idx < N; idx ++){
        B[idx] = (long long)A[idx] + idx;
        C[idx] = (long long)idx - A[idx];
    }
    qsort(B, N, sizeof(long long), cmp);
    qsort(C, N, sizeof(long long), cmp);
    
    for(idx = 0; idx < N; idx ++){
        pos = insert_bsearch(C, N, B[idx]);
        count = count + pos;
        count -= idx + 1;   // delete self and doubt counts
    }
    
    if(count > 10000000)
        count = -1;
    
    return count;
}