#include "LineTable.h"

struct LineTable lineTable = {"abcde",5};

void insert(int index, char c)
{
    insertassert(index,lineTable);
    if (index < lineTable.length) {
        for (int k = index; k < lineTable.length; k++){
            lineTable.data[k+1] = lineTable.data[k];
        }
    }
    lineTable.data[index] = c;
    lineTable.length ++;
}

int main()
{
    insert(5,'y');
    printf("插入后的线性表数据是%s,长度是%d",lineTable.data,lineTable.length);
    return 0;
}