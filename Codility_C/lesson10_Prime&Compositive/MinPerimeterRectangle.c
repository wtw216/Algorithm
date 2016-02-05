// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include<math.h>
int solution(int N) {
    // write your code in C99 (gcc 4.8.2)
    int a, b;
    int middle = sqrt(N);
    for(int idx = middle; idx > 0 ; idx--){
        if(N % idx == 0){
            a = idx;
            b = N / idx;
            return 2 * (a + b);
        }
    }
        
}