#include <stdio.h>
#include <stdlib.h>
#include "P1-02.h"

int main(void)
{
    char *newData;
    char *nodeData;
    NODE *node;

    newData = (char *)malloc(sizeof(char));
    *newData = 65;

    node = createNode(newData);

    nodeData = (char *)node->dataPtr;
    printf("New data is %c\n", *nodeData);

    // printf("New data is %d", *(int *)node->DataPtr);
}