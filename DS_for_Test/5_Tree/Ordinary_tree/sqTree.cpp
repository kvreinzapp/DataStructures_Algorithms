#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**************PArent Tree*****************/
typedef struct
{
    Elemtype data;
    int data;
} PTnode;
typedef struct
{
    PTnode nodes[MAXSIZE];
    int num;
} PTree;

/**************Child Tree*********************/
struct CTnode
{
    int child;
    struct CTnode *next;
};
typedef struct
{
    Elemtype data;
    struct CTnode *firstChild;
} CTbox;
typedef struct
{
    CTnode nodes[MAXSIZE];
    int num, root_position;
} PTree;

/****************Child and brother *************/
typedef struct CSNode
{
    ElemType data;
    struct CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;