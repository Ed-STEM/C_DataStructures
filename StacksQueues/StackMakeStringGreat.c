typedef struct {
    char* data;
    int top;
    int maxSize;
} Stack;

// Function to initialize the stack
void initStack(Stack* stack, int size)
{
    stack->data = (char*)malloc(size * sizeof(char));
    stack->top = -1;
    stack->maxSize = size;
}

bool isEmpty(Stack* stack)
{
    return stack->top == -1; 
}

// Function to push an element onto the stack
void push(Stack* stack, char element)
{
    if(stack->top < stack->maxSize -1)
    {
        stack->data[++stack->top] = element;
    }

}

char pop(Stack* stack){
    if(!isEmpty(stack)){
        return stack->data[stack->top--];
    }
    return '\0';
}
    
char peek(Stack* stack){
    if (!isEmpty(stack)){
        return stack->data[stack->top];
    }
    return '\0';
}

char* makeGood(char* s){
    
    int size = strlen(s);
    Stack stack;
    initStack(&stack, size);
    
    for (int i =0; i <size; i++){
        char current = s[i];
        if (!isEmpty(&stack) && abs(peek(&stack) - current) == 32){
            pop(&stack);
        } else {
            push(&stack, current);
        }
    }
    
    char* result = (char*)malloc((stack.top + 2) * sizeof(char));
    result[stack.top + 1] = '\0';
    for (int i = stack.top; i >= 0; i--){
        result[i] = pop(&stack);
    }
    
    free(stack.data);
    return result;
     
}
