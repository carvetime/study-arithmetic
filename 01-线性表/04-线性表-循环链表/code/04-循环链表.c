#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node *next;
};

typedef struct Node CNode;

CNode *initCircleList(){
    CNode *temp = malloc(sizeof(CNode));
    CNode *p = temp;
    for (int i=1; i<3; i++){
        CNode *node = malloc(sizeof(CNode));
        node->data = i;
        temp->next = node;
        temp = node;
    } 
    temp->next = p->next;
    return p;
}


int main()
{
    CNode *p = initCircleList();
    printf("第一个元素：%d 地址: %p\n",p->next->data,p->next);
    printf("下个元素：%d 地址: %p\n",p->next->next->data,p->next->next);
    printf("下下个元素：%d 地址: %p\n",p->next->next->next->data,p->next->next->next);
    return 0;
}

