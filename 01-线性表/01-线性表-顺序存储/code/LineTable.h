#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct LineTable {
    char data[MAX];
    int length;
};


void queryassert(int index, struct LineTable list)
{
    if (index < 0 || index >= list.length) {
        printf("%d超出了线性表的范围",index);
        exit(-1);
    }
}

void insertassert(int index, struct LineTable list)
{

    if (list.length == MAX) {
        printf("线性表已满");
        exit(-1);
    }

    if (index < 0 || index > list.length) {
        printf("%d超出了线性表的范围",index);
        exit(-1);
    }
}