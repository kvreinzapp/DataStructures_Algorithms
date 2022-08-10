#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/***************************************************Declaration******************************************************/
struct ElemType // Kind of useless
{
    int value;
};

typedef struct BitNode
{
    char data;
    struct BitNode *lchild, *rchild;
} BitNode, *BitTree;

// Used in visit(), p should Point to target node, the final is p's prenode(Inorder)
BitNode *p;
BitNode *pre = NULL;
BitNode *final = NULL;

/***************************************************Basic-Functions******************************************************/

/*******************Empty***********************/
bool IsEmpty(BitNode *T)
{
    return (T->lchild == NULL && T->rchild == NULL);
}

/*******************AddNode***********************/
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

/***************************************************Main-Topic******************************************************/
void visit(BitNode *q)
{
    // Only  when q==p. or say q grows to p, pre can be the real final
    if (q == p)
        final = pre;
    else
        pre = q;

    printf("%c\n", q->data);
}

void FindPre(BitTree T) // same as InOrder
{
    if (T != NULL)
    {
        FindPre(T->lchild);
        visit(T);
        FindPre(T->rchild);
    }
}

int main(void)
{
    BitTree root;
    addRange(root, 6);
    FindPre(root);
}