#include "LineTable.h"

struct LineTable lineTable = {"abcdefghig",10};

char getElementByIndex(index)
{
    queryassert(index,lineTable);
    return lineTable.data[index];
}


int main()
{
    char element = getElementByIndex(20);
    printf("获取的元素是%c",element);
    return 0;
}


