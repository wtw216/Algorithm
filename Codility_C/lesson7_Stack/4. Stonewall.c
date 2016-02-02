typedef struct stack{
    int *A;
    int top;
} Block;

void push(Block* block, int value){
    block->A[block->top] = value;
    block->top ++;
}

int pop(Block* block){
    if(block->top > 0){
        block->top --;
        return block->A[block->top];
    } else
        return NULL;
}

int solution(int H[], int N) {
    // write your code in C99 (gcc 4.8.2)
    Block* block = (Block*)malloc(sizeof(Block));
    block->A = (int *)malloc(sizeof(int) * N);
    block->top = 0;
    int idx;
    int count = 1;
    
    push(block, H[0]);
    
    for(idx = 1; idx < N; idx ++){
        while(H[idx] < block->A[block->top - 1]){       //If the current is shorter than the last, the last is interrupted
                                                        //and it should be popped out of the stack
            pop(block);
        }
        push(block, H[idx]);                            //push the current into the stack if it is not shorter than the last
        if(block->top - 1 == 0 || H[idx] != block->A[block->top - 2]){  //If the stack only has the current 
                                                        //or the one before has the same height with the current 
                                                        //The count should add one.
            count++;    
        }
    }
    return count;
}