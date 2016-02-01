int solution(int X, int A[], int N) {
    int * time = (int *) malloc(sizeof(int) * X);
    int idx;
    int max_time = 0;
    for(idx = 0; idx < X; idx++)
        time[idx] = N+1;
      
    for(idx = 0; idx < N; idx++)
        if(idx < time[A[idx] - 1])
            time[A[idx] - 1] = idx;
    
    for(idx = 0; idx < X; idx++)
		if(max_time < time[idx])
            max_time = time[idx];
		   
	if(max_time > N)
		return -1;
	else 
		return max_time;
    // write your code in C99 (gcc 4.8.2)
}
