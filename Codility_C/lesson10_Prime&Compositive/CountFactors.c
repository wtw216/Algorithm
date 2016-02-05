// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <math.h>
int solution(int N) {
    // write your code in C99 (gcc 4.8.2)
    int count = 0;
    int middle = sqrt(N);
    for(int idx = 1; idx <= middle; idx++){
        if(N % idx == 0)
            count ++;
    }
    count *= 2;
    if(middle * middle == N)
        count--;
    return count;
}