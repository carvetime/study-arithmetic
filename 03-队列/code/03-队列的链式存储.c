#include <stdio.h>
#include <stdlib.h>

typedef struct QNode{
    int data;
    struct QNode *next;
}Node;

typedef struct QList{
    Node *head;
    Node *tail;
}List;


List *initList(){
    List *list = malloc(sizeof(List));
    Node *headNode = malloc(sizeof(Node));
    headNode->next = NULL;
    list->head = headNode;
    list->tail = headNode;
    return list;
}

void insertNode(List *list,int val){
    Node *node = malloc(sizeof(Node));
    if (!node){
        printf("分配内存空间失败");
    } else {
        node->data = val;
        node->next = NULL;
        list->tail->next = node;
        list->tail = node;
    }
}

void printList(List *list){
    Node *head = list->head;
    Node *node = head->next;
    if (!node){
        printf("栈链表为空\n");
    } else {
        while(node){
            printf("value:%d \n",node->data);
            node = node->next;
        }
    }
}

int main(){
    List *list = initList();
    insertNode(list,1);
    insertNode(list,2);
    insertNode(list,3);
    printList(list);

    return 0;
}