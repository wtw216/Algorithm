#include"string.h"

int getValue(char c){
    switch(c){
        case 'A': return 1; break;
        case 'C': return 2; break;
        case 'G': return 3; break;
        case 'T': return 4; break;
        default:  return 0; break;
    }
}

struct Results solution(char *S, int P[], int Q[], int M) {
    struct Results result;
    // write your code in C99 (gcc 4.8.2)
    int N = strlen(S);
    int map[N][4];             // = (int *)malloc(sizeof(int) * N * 4);
    int col,row,key;
    int idx;
    int p, q;
    int sub;
    for(row = 0; row < N; row++){
        key = getValue(S[row]);
        for(col = 0; col < 4 ; col++){
            if(col == key -1){
                map[row][col] = 1;
            } else {
                map[row][col] = 0;
            }
        }
    }
    
    for(col = 0; col < 4; col++){
        for(row = 1; row < N; row++){
            map[row][col] += map[row - 1][col];
        }
    }
    
    for(idx = 0; idx < M; idx++){
        p = P[idx];
        q = Q[idx];
        sub = 0;
        for(col = 0; col < 4; col++){
            if(p > 0) 
                sub = map[p - 1][col];
            if (map[q][col] - sub > 0){
                P[idx] = col + 1;
                break;
            }
        }
    }
    
    result.M = M;
    result.A = P;
    return result;
}