#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*************Declaration***************/
struct ElemType
{
    int value;
};

typedef struct BitNode
{
    char data;
    struct BitNode *lchild, *rchild;
} BitNode, *BitTree;

/************Operation******************/

/*******Empty*****/
bool IsEmpty(BitNode *T)
{
    return (T->lchild == NULL && T->rchild == NULL);
}
/*******AddNode*****/
BitNode *newNode(BitNode *&parent, char ch)
{
    BitNode *seven = (BitNode *)malloc(sizeof(BitNode));
    seven->data = {ch};
    seven->lchild = NULL;
    seven->rchild = NULL;
    parent = seven;
    return seven;
}

void addRange(BitTree &root, int range)
{
    BitNode *p[20];
    p[1] = NULL;
    for (int i = 1; i <= range; i++)
    {
        if (i == 1)
            p[1] = newNode(p[1], 'A');
        else
        {
            if (i % 2 == 0)
                p[i] = newNode(p[i / 2]->lchild, 64 + i);
            else
                p[i] = newNode(p[i / 2]->rchild, 64 + i);
        }
    }
    root = p[1];
}

void visit(BitNode *T)
{
    printf("%c\n", T->data);
}

void InOrder(BitTree T)
{
    if (T != NULL)
    {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

int main(void)
{
    BitTree root;
    addRange(root, 6);
    InOrder(root);
}