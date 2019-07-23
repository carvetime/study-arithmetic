
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct QueueList {
    int data[MAX];
    int head;
};

void printList(struct QueueList *list){
    int temp = list->head-1;
    while(temp >= 0){
        printf("index:%d,value:%d\n",temp,list->data[temp]);
        temp --;
    }
}

void insertElement(struct QueueList *list,int element){
    list->data[list->head] = element;
    list->head++;
}

void deleteElement(struct QueueList *list){
    if (list->head > 0) {
        int temp = 0;
        while(temp < list->head){
            int next = temp + 1;
            list->data[temp] = list->data[next];
            temp ++;
        }
        list->head --;
    }
}

int main(){
    struct QueueList list;
    list.head = 0;
    insertElement(&list,0);
    insertElement(&list,1);
    insertElement(&list,2);
    insertElement(&list,3);
    insertElement(&list,4);
    printList(&list);

    printf("删除后\n");
    deleteElement(&list);
    deleteElement(&list);
    printList(&list);

    return 0;
}


