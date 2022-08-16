#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sequenceStack.h>
#include <adjacency_list.h>

bool TopologicalSorting(Graph G)
{
    SqStack S;
    InitStack(S);
    for (int i = 0; i < G.vexnum; i++)
        if (indegree[i] == 0)
            Push(S, i);
}
