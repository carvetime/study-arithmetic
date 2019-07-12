#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode *prior;
    struct DNode *next;
};

struct DNode *initList(){
    struct DNode *head = malloc(sizeof(struct DNode));
    struct DNode *current = head;
    struct DNode *previous = NULL;
    for (int i=0; i<10; i++){
        struct DNode *node = malloc(sizeof(struct DNode));
        node->data = i;
        current->next = node;
        current->prior = previous;
        previous = current;
        current = node;
    }
    return head;
}

void printList(struct DNode *head){
    struct DNode *current = head->next;
    while(current->next){
        printf("data:%d 地址:%p \n",current->data,current);
        current = current->next;
    }
}

struct DNode *insert(struct DNode *head,struct DNode *node,int index){
    struct DNode *current = head;
    int i = 0;
    while(current->next && i != index) {
        current = current->next;
        i++;
    }
    struct DNode *originNext = current->next;
    current->next = node;
    node->prior = current;
    node->next = originNext;
    originNext->prior = node;
    return head;
}


int main(){

    struct DNode *head = initList();
    printf("插入前\n");
    printList(head);

    struct DNode *node = malloc(sizeof(struct DNode));
    node->data = 100;
    insert(head,node,5);
    printf("插入后\n");
    printList(head);
    return 0;
}