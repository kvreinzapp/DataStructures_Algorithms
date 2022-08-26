
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Graph
{
    int V;
    int E;
    int **adj; // Since we need two dimensional matrix
};

struct Graph *adjMatrixOfGraph()
{
    int i, v, u;
    struct Graph *G = (struct Graph *)malloc(sizeof(struct Graph));
    if (!G)
    {
        printf("Memory Error");
        return;
    }
    scanf("Number of Vertices: %d, Number of Edges: %d", &G->V, &G->E);
    G->adj = malloc(sizeof(G->V * G->V));
}
