#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXSIZE 1000
#define ORIGINSIZE 10

typedef struct{
    char data[50];
    int cur;
} SNode;

SNode sList[MAXSIZE];

void initList(SNode list[]){
    for (int i=1; i<ORIGINSIZE; i++){
        char str[100];
        sprintf(str,"%d",i);
        strcpy(list[i].data,"data");
        strcat(list[i].data,str);
        list[i].cur = i+1;
    }
    list[0].cur = ORIGINSIZE+1;
    list[MAXSIZE-1].cur = 1;
}

void printList(SNode list[]){
    SNode node = list[MAXSIZE-1];
    SNode temp = list[node.cur];
    while (temp.cur){
        printf("%s \n",temp.data);
        temp = list[temp.cur];
    };
}

void insert(SNode list[],int index,char data[100]){
    if (index < 0 || index >= ORIGINSIZE) {
        printf("插入一个不存在的链表区间");
        exit(-1);
    }
    int i = list[0].cur;
    strcpy(list[i].data,data);
    list[0].cur = list[i].cur;
    if (index == 0) {
        int k = list[MAXSIZE-1].cur;
        list[i].cur = k;
        list[MAXSIZE-1].cur = i;
    } else {
        int k = list[MAXSIZE-1].cur;
        for (int j=1; j < index; j++){
            k = list[k].cur;
        }
        list[i].cur = list[k].cur;
        list[k].cur = i;
    }
        
}

void delete(SNode list[],int index){
    if (index < 0 || index >= ORIGINSIZE) {
        printf("删除的是一个不存在的链表区间");
        exit(-1);
    }
    int temp = MAXSIZE-1; // 最后一位元素的索引
    for (int i=0; i<index; i++){
        temp = list[temp].cur; // 上一位的元素索引
    }
    int currentIndex = list[temp].cur; // 这里需要暂存当前元素的索引
    SNode node = list[list[temp].cur]; // 删除的节点
    int nextTemp = node.cur; // 下一位的元素索引
    list[temp].cur = nextTemp; // 上一位元素指针指向下一位元素的索引
    
    // 接下来处理备用空间
    strcpy(node.data,"");
    node.cur = list[0].cur; // 删除的节点指向原来的第一个备用节点
    list[0].cur = currentIndex; // 备用节点执行当前删除节点的索引
}


int main(){
    initList(sList);
    printList(sList);
    // insert(sList,0,"jj");
    // printf("插入之后:\n");
    printf("删除之后:\n");
    delete(sList,9);
    printList(sList);
    return 0;
}


