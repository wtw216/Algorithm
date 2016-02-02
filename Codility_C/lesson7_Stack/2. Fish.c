typedef stack{
    int* A;
    int top;
} Fish;

void push(int* Fish, int value){
    Fish->A[Fish-top] = value;
    Fish->top ++;
}

int pop(int* Fish){
    if(Fish->top > 0){
        Fish->top--;
        return Fish->A[Fish->top];
    } else 
        return NULL;
}
int fishEat(Fish* fish, int down_size, int up_size){
    if(down_size > up_size)
        return 1;
    else{
        pop(fish);
        return 0;
    }
}
int solution(int A[], int B[], int N) {
    // write your code in C99 (gcc 4.8.2)
    int idx = 0;
    int top = 0;
    Fish *fish = (Fish *)malloc(sizeof(Fish));
    int dead_count = 0;
    //find the first 1 in B[], as stack top.
    fish->A = (int *)malloc(sizeof(int) * N);
    fish->top = 0;
    while(idx < N){
        if(B[idx] == 0){
            if(fish->top > 0){
                while(fish->top > 0){
                    int fish_live = fishEat(fish, fish->A[fish->top - 1], A[idx]);
                    if(fish_live)
                        break;
                }

            } else    
                continue;
        } else  
            push(fish, A[idx]);
        idx++;
    }

            

            
}