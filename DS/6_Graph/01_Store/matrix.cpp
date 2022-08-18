#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/******* Matrix way*******/
#define MaxVertexNum 100
typedef struct
{
    char Vex[MaxVertexNum];               // you can also store struct here
    int Edge[MaxVertexNum][MaxVertexNum]; // you can use bool here, for just 0 and 1
    int vexnum, arcnum;
} MGraph;

/******* No-weight *******/
#define MaxVertexNum 100
#define INFINITY 65536
typedef char VertexType;
typedef int EdgeType;
typedef struct
{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
} MGraph;

// tommoroe find a boook