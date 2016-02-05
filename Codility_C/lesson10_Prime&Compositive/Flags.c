// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
// Why the time complexity is tested as O(N) in codility?
// It should be O(N^2) in theory??
int checkFlag(int count, int* peaks_pos, int N){
    int flag_left = count;
    int idx = 0;
    while(idx < N){
        if(peaks_pos[idx] == 1){
            flag_left--;
            idx += count;
            if(flag_left == 0)
                return 1;
        } else {
            idx ++;
        }
    }
    if(flag_left)   
        return 0;
    else 
        return 1;     
}
    
int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)

    if(N < 3)
        return 0;
    // 1. record the peaks;   
    int peaks_pos[N]; 
    for(int idx = 0; idx < N; idx ++){
        peaks_pos[idx] = 0;
    }
    int peaks_count = 0;
    for(int idx = 1; idx < N - 1; idx ++){
        if(A[idx] > A[idx - 1] && A[idx] > A[idx + 1]){
            peaks_pos[idx] = 1;
            peaks_count++;
        }
    }
    // if number of peak is 0 or 1
    if(peaks_count < 2)
        return peaks_count;
    
    //if number of peaks is equal or larger than 2
    int count = 3;
    
    while(count <= peaks_count && checkFlag(count, peaks_pos, N)){
        count ++;
    }
    
    return count - 1;
}