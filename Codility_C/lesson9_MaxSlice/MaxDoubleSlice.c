// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
int max(int a, int b){
    return a > b ? a : b;
}
int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    int max_y_ending = 0;
    int max_y_start = 0;
    int max_slice_xy[N];
    int max_slice_yz[N];
    // 1 <= y <= N - 2
    max_slice_xy[1] = 0;
    for(int idx = 2; idx < N - 1; idx ++){
        max_y_ending = max(0, max_y_ending + A[idx - 1]);
        max_slice_xy[idx] = max_y_ending;
    }
    // reverse the array
    max_slice_yz[N - 2] = 0;
    for(int idx = N - 3; idx > 0; idx --){
        max_y_start = max(0, max_y_start + A[idx + 1]);
        max_slice_yz[idx] = max_y_start;
    }
    int max_slice = 0;
    for(int idx = 1; idx < N - 1; idx ++){
        max_slice_xy[idx] += max_slice_yz[idx];
        max_slice = max(max_slice, max_slice_xy[idx]);
    }       
    return max_slice;       
}