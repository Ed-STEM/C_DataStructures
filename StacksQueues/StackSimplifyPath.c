typedef struct {
    char** data;
    int top;
    int maxSize;
} Stack;

void initStack(Stack* stack, int size){
    stack->data = (char**)malloc(size * sizeof(char*));
    stack->top = -1;
    stack->maxSize = size;
}

bool isEmpty(Stack* stack){
    return stack->top == -1;
}

void push(Stack* stack, char* element){
    if (stack->top < stack->maxSize -1){
        stack->data[++stack->top] = element;
    }
}

char pop(Stack* stack){
    if(!isEmpty(stack)){
        return stack->data[stack->top--];
    }
    return '\0';
}

char* simplifyPath(char* path) {

    int size = strlen(path);
    Stack stack;
    initStack(&stack,size);
    
    char* token = strtok(path, "/");
    while (token != NULL){
        if(strcmp(token, "..") == 0){
            if(!isEmpty(&stack)) pop(&stack);
        } else if (strcmp(token, ".") != 0){
            push(&stack, token);
        }
        token = strtok(NULL, "/");
    }
                         
    // Construct the canonical path
    char* canonical = (char*)malloc(size +1);
    char* temp = canonical;
    
    *temp = '\0';
    if (stack.top == -1){
        strcat(temp,"/");
    }
    
    
 
    for (int i = 0; i <= stack.top; i++){
        strcat(temp, "/");
        strcat(temp, stack.data[i]);
        
    }
    
    free(stack.data);
    return canonical;
    
}