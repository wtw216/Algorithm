// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(char *S) {
    // write your code in C99 (gcc 4.8.2)
    int count = 0; 
    int idx;    
    int N = strlen(S);
    
    if(N < 2)
        return !N;
    
    for(idx = 0; idx < N; idx ++){
        if(S[idx] == '(')
            count++;
        else if(count > 0)  
            count--;
        else
            return 0;               
    }
    
    if(count > 0)
        return 0;
    else 
        return 1;
}