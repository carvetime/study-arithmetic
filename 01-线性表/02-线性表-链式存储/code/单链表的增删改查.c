
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// 头部插入创建链式表
struct Node * createChainListByHead(){
    struct Node *p;
    struct Node * headNode = malloc(sizeof(struct Node));
    headNode->next = NULL;
    for (int i=0; i<10; i++){
        p = malloc(sizeof(struct Node));
        p->data = rand()%100+1;
        p->next = headNode->next;
        headNode->next = p;
    }
    return headNode;
}

// 尾部插入创建链式表
void createChainListByTail(){
    struct Node *p;
    struct Node *current = malloc(sizeof(struct Node));
    for (int i=0; i<10; i++){
        p = malloc(sizeof(struct Node));
        p->data = rand()%100+1;
        current->next = p;
        current = p;
    }
    current->next = NULL;
}

// 获取所有链式表元素
void printAllOfElements(struct Node *head){
    struct Node * temp = head->next;
    while (temp){
        int data = temp->data;
        printf("%d \n",data);
        temp = temp->next;
    };
}

// 插入元素
void insertElement(int index, struct Node * node){
    struct Node * head = createChainListByHead();
    printf("插入前\n");
    printAllOfElements(head);
    struct Node * temp = head;
    int i = 0;
    while (i < index){
        if (temp->next) {
            temp = temp->next;
            i++;
        } else {
            break;
        }
    };
    node->next = temp->next;
    temp->next = node;
    printf("插入后\n");
    printAllOfElements(head);
}

// 删除链表中的某个元素
void deleteElement(int index){
    struct Node * head = createChainListByHead();
    printf("删除前\n");
    printAllOfElements(head);
    struct Node * temp = head;
    int i = 0;
    while(i < index) {
        temp = temp->next;
        i++;
    }
    if (temp->next) {
        struct Node *next = temp->next;
        temp->next = next->next;
    } else {
        printf("不存在链表的区间中");
        exit(-1);
    }
    printf("删除后\n");
    printAllOfElements(head);
}

int main(){
    // struct Node node = {99,NULL};
    // insertElement(10,&node);
    deleteElement(10);
    return 0;
}

