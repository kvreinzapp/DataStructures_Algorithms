#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MaxVertexNum 100

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
    // info
} ArcNode;

typedef struct VNode
{
    // VertexType data;
    int data;
    ArcNode *firstarc;
} VNode, AdjList[MaxVertexNum];

typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
} Graph;

void CreateDiGraph(void)
{
    int ar[5];
    for (int i = 0; i < 5; i++)
        scanf("%1d", &ar[i]);
    for (int i = 0; i < 5; i++)
        printf("%d", ar[i]);
}
void CreateUndiGraph(void);

int indegree(int num)
{
}