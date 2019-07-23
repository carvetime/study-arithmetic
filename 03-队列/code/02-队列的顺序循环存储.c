#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct QueueList{
    int data[MAX];
    int head;
    int tail;
}List;


void printList(List *list){
    if (list->head == list->tail) {
        printf("空队列");
    } else {
        int index = list->head;
        while(index != list->tail){
            printf("index:%d value:%d \n",index,list->data[index]);
            index = (index+1)%MAX;
        }
    }
}

void insertList(List *list,int value){
    if ((list->tail+1)%MAX == list->head){
        printf("队列已满\n");
    } else {
        list->data[list->tail] = value;
        list->tail = (list->tail + 1)%MAX;
    }
}

void removeElement(List *list){
    if (list->head == list->tail){
        printf("队列是空\n");
    } else {
        list->head = (list->head+1)%MAX;
    }
}


int main(){
    List list;
    list.head = 0;
    list.tail = 0;
    insertList(&list,0);
    insertList(&list,1);
    insertList(&list,2);
    insertList(&list,3);
    printf("删除之前\n");
    printList(&list);


    printf("删除之后\n");
    removeElement(&list);
    removeElement(&list);
    removeElement(&list);
    printList(&list);


    
    printf("插入之后\n");
    insertList(&list,4);
    insertList(&list,5);
    insertList(&list,6);

    printList(&list);


    return 0;
}