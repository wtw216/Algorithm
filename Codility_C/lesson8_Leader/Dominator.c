// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    int start = 0;
    int last = 0;
    int top;
    int candidate;
    int count = 0;
    int leader_pos = 0; 
    for(top = 1; top < N; top ++){    
        if(A[top] != A[last])
            last--;
        else 
            last++;
            
        if(last < start){
            start = top + 1;
            last = start;
            top++;
        }
    }
    if(start >= N )
        return -1;
    else
        candidate = A[start];
    
    for(int idx = 0; idx < N; idx ++){
        if(A[idx] == candidate){
            count++;
            leader_pos = idx;
        }
    }
    
    if(count > N/2)
        return leader_pos;
    else
        return -1;
}