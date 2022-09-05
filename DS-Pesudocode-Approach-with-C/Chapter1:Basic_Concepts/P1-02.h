#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    void *dataPtr;
    struct node *link;
} NODE;

NODE *createNode(void *itemData)
{
    NODE *nodePtr = (NODE *)malloc(sizeof(NODE));
    nodePtr->dataPtr = itemData;
    nodePtr->link = NULL;
    return nodePtr;
}