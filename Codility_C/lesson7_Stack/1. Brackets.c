typedef struct stack{
    char *A;
    int top;
}Stack;

void push(Stack* stack_nest, char key){
    stack_nest->A[stack_nest->top] = key;
    stack_nest->top ++;
}
char pop(Stack* stack_nest, char key){
	if(stack_nest->top == 0)
		return NULL;
	stack_nest->top --;
    char top = stack_nest->A[stack_nest->top];
    return top;
}
int match(char a, char b){
    if(a == '(' && b == ')')
        return 1;
    else if(a == '[' && b == ']')
        return 1;
    else if(a == '{' && b == '}')
        return 1;
    else
        return 0;
}
int solution(char *S) {
    // write your code in C99 (gcc 4.8.2)
    Stack *stack_nest = (Stack *) malloc (sizeof(Stack));
    int N = strlen(S);
    int idx;
    char temp;
    
    if(N < 2) 
        return !N;
        
    stack_nest->A = (char *)malloc(sizeof(char) * N);
    stack_nest->top = 0;
    
    for(idx = 0; idx < N; idx ++){
        if(S[idx] == '(' || S[idx] == '[' || S[idx] == '{'){
            push(stack_nest, S[idx]);
        }   else{
            temp = pop(stack_nest, S[idx]);
            if(temp == NULL || !match(temp, S[idx])) 
                return 0;
        }
    }
    if(stack_nest->top != 0)
        return 0;
    else 
        return 1;
    
}