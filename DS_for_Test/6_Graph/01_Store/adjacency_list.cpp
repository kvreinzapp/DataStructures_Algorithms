#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MaxVertexNum 100

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *next;
} ArcNode;

typedef struct VNode
{
    VertexType data;
    ArcNode *first;
} VNode, AdjList[MaxVertexNum];

typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;
