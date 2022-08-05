#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 10
/******************Declaration*****************/
typedef struct
{
    char data[MAXSIZE];
    int top;
} SqStack;

/******************Initialization*****************/
void InitStack(SqStack &S)
{
    S.top = -1;
}

/******************Judge*****************/
bool Empty(SqStack S)
{
    return (S.top == -1);
}

/******************Push and Pop(and GetTop)*****************/
bool Push(SqStack &S, char x)
{
    if (S.top == MAXSIZE - 1)
        return false;
    // S.top=S.top+1;
    // S.data[S.top]=x;
    S.data[++S.top] = x;
    return true;
}
bool Pop(SqStack &S, char &x)
{
    if (S.top == -1)
        return false;
    x = S.data[S.top--];
    return true;
}
bool GetTop(SqStack S, char &x)
{
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}
