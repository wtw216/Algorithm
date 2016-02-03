// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
int getLeader(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    int start = 0;
    int last = 0;
    int top;
    int candidate;
    int count = 0, temp_count = 0;
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

int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    
    int leader;
    int leader_pos = getLeader(A, N);
    int leader_poses[N];
    int pos = 0;
    int count = 0;
    
    if(leader_pos == -1)
        return 0;
    else 
        leader = A[leader_pos];
    
    for(int idx = 0; idx < N; idx ++){
        if(A[idx] == leader){
            leader_poses[pos] = idx;
            pos++;
        }
    }
    
    int leader_count = pos;
    pos = 0;
    int part1_leader_count = 0;
    int part2_leader_count = leader_count - part1_leader_count;
    
    for(int idx = 0; idx < N - 1; idx ++){
        int part1_N = idx + 1;
        int part2_N = N - part1_N;

        if(idx == leader_poses[pos]){
            pos++;
            part1_leader_count++;
            part2_leader_count--;
        }
        
        if(part1_leader_count > part1_N / 2 && \
            part2_leader_count > part2_N / 2)
            count ++;
    }
    return count;
}