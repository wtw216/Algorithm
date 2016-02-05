// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    if(N < 3)
        return 0;
    //1. create array to record peaks_pos
    int peaks_pos[N];
    for(int idx = 0; idx < N; idx ++){
        peaks_pos[idx] = -1;
    }
    //2. store the peakes_pos: the (pos)th peak has the index of peaks_pos[pos] in array A
    int pos = 1;
    for(int idx = 1; idx < N - 1; idx ++){
        if(A[idx] > A[idx - 1] && A[idx] > A[idx + 1]){
            peaks_pos[pos] = idx;
            pos++;
        }
    }
    int last_pos = pos - 1;
    
    if(peaks_pos[1] == -1)  //no peaks in the array.
        return 0;
    
    //3. get the possible Ks    
    int K[N];
    for(int idx = 0; idx < N; idx ++){
        K[idx] = -1;
    }
    
    for(int idx = 1, pos = 0; idx <= N; idx++){
        if(N % idx == 0){
            K[pos] = idx;
            pos++;
        }
    }

    //4. check the K
    int k;
    for(int idx = 0; K[idx] != -1; idx++){
        k = K[idx];
        if(k == 1)
            continue;
       
        int step = 1;
        for(int j = 1; j <= last_pos; j++){
            if(peaks_pos[j] <= (step * k - 1) && \
                peaks_pos[j] >= (step - 1) * k){
                    if(step == N / k)  
                        break;
                    else
                        step++;
                }
        }
        if(step == N / k && peaks_pos[last_pos] <= (N - 1) \
            && peaks_pos[last_pos] >= (N - k))
            break;
    }

    return N / k;
}