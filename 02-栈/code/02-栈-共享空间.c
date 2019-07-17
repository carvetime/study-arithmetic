#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct{
    char data[MAXSIZE];
    int top1;
    int top2;
}Stack;

int isFull(Stack *stack){
    if (stack->top1+1 == stack->top2){
        return 1;
    } else {
        return 0;
    }
}

void printStack(Stack *stack){
    int top1 = stack->top1;
    while(top1 >= 0) {
        printf("top:%d的值是:%c\n",top1,stack->data[top1]);
        top1--;
    }
    int top2 = stack->top2;
    while(top2 < MAXSIZE) {
        printf("top:%d的值是:%c\n",top2,stack->data[top2]);
        top2++;
    }
}

void push(Stack *stack,char c, int stackNumber){
    if (isFull(stack)) {
        printf("栈已满");
        exit(-1);
    }

    if (stackNumber == 1) {
        stack->top1++;
        stack->data[stack->top1] = c;
    } else {
        stack->top2--;
        stack->data[stack->top2] = c;
    }
}


int main(){
    Stack stack = {"",-1,MAXSIZE};

    printf("push前\n");
    printStack(&stack);
    printf("push后\n");
    push(&stack,'a',1);
    push(&stack,'b',1);
    push(&stack,'c',2);
    printStack(&stack);
    return 0;
}