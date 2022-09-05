#include <stdio.h>
#include <stdlib.h>
#include "P1-02.h"

int main(void)
{
    // Local Definations
    int *newData;
    int *nodeData;
    NODE *node;

    // Statements
    newData = (int *)malloc(sizeof(int));
    *newData = 7;
    node = createNode(newData);

    newData = (int *)malloc(sizeof(int)); // Must have this one, cause we pass the adress
    *newData = 879;
    node->link = createNode(newData);

    nodeData = (int *)node->dataPtr;
    printf("First node data:%d\n", *nodeData);

    nodeData = (int *)node->link->dataPtr;
    printf("Second node data:%d\n", *nodeData);
    return 0;
}
