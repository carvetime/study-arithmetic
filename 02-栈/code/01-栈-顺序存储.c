#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct{
    char data[MAXSIZE];
    int top;
}Stack;

void printStack(Stack *stack){
    int top = stack->top;
    while(top >= 0) {
        printf("top:%d的值是:%c\n",top,stack->data[top]);
        top--;
    }
}

void push(Stack *stack,char c){
    stack->top++;
    stack->data[stack->top] = c;
}

void pop(Stack *stack){
    stack->data[stack->top] = '\0';
    stack->top--;
}


int main(){
    Stack stack = {"abcdef",5};
    printf("push前\n");
    printStack(&stack);
    printf("push后\n");
    push(&stack,'g');
    printStack(&stack);
    printf("pop后\n");
    pop(&stack);
    printStack(&stack);
    return 0;
}