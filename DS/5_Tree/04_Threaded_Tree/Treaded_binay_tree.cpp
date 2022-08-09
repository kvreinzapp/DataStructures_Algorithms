#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct ElemType
{
    int value;
};

typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode *ThreadTree;
