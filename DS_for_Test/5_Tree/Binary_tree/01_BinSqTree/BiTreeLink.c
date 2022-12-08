#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100

typedef int Status;

int treeIndex = 1;
typedef char String[24];
String str;

Status StrAssign(String T, char *chars)
{
}

typedef char TElemType;
TElemType Nil = ' ';

Status visit(TElemType e)
{
    printf("%c ", e);
    return OK;
}

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

Status InitBiTree(BiTree *T)
{
    *T = NULL;
    return OK;
}

void DestroyBiTree(BiTree *T)
{
    if (*T)
    {
        if ((*T)->lchild)
            DestroyBiTree((*T)->lchild);
        if ((*T)->rchild)
            DestroyBiTree((*T)->rchild);
        free(*T);
        *T = NULL;
    }
}

void CreateBiTree(BiTree *T)
{
    TElemType ch;
}