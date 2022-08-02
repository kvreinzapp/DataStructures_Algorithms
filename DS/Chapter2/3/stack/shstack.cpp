#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 10
/******************Declaration*****************/
typedef struct
{
    int data[MAXSIZE];
    int top0;
    int top1;
} ShStack;

/******************Initialization*****************/
void InitStack(ShStack &S)
{
    S.top0 = -1;
    S.top1 = MAXSIZE;
}

/******************Judge*****************/
bool Empty(ShStack &S)
{
    return (S.top0 + S.top1 == S.top1);
}