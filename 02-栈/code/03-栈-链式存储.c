#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node *next;
}StackNode;

typedef struct List{
    StackNode *top;
    int count;
}StackList;


void printStack(StackList *list){
    StackNode *temp = list->top;
    int index = list->count;
    while(temp){
        printf("index:%d,data:%d\n",index,temp->data);
        temp = temp->next;
        index--;
    }
}

void push(StackList *list,StackNode *node){
    StackNode *temp = list->top;
    if (temp) {
        node->next = temp;
    }
    list->top = node;
    list->count++;
}

void pop(StackList *list){
    StackNode *temp = list->top;
    if (temp){
        list->top = list->top->next;
        list->count --;
    }
}

int main(){
    StackList *list = malloc(sizeof(StackList));
    list->top = NULL;
    list->count = 0;
    printf("push之前\n");
    printStack(list);
    StackNode node1 = {1,NULL};
    StackNode node2 = {2,NULL};
    StackNode node3 = {3,NULL};
    StackNode node4 = {4,NULL};
    push(list,&node1);
    push(list,&node2);
    push(list,&node3);
    push(list,&node4);

    printf("push之后\n");
    printStack(list);


    printf("pop后\n");
    pop(list);
    printStack(list);
    return 0;
}