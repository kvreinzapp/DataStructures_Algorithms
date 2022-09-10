#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE 13

int UFSets[SIZE];
void Initial(int s[])
{
    for (int i = 0; i < SIZE; i++)
    {
        s[i] = -1;
    }
}

/***********Find and Union******************/
int Find(int S[], int x)
{
    while (S[x] >= 0)
        x = S[x];
    return x;
}

/******Better_find*******/
int bettreFind(int S[], int x)
{
    int root = x;
    while (S[root] >= 0)
        root = S[root];
    while (x != root)
    {
        int t = S[x];
        S[x] = root;
        x = t;
    }
    return root
}

void Union(int S[], int Root1, int Root2)
{
    if (Root1 == Root2)
        return;
    S[Root2] = Root1;
}

/******Better_Union*******/
void betterUnion(int S[], int Root1, int Root2)
{
    if (Root1 == Root2)
        return;
    if (S[Root2] > S[Root1]) // Root2 have less node, so it's negative value is bigger
    {
        S[Root1] += S[Root2];
        S[Root2] = Root1;
    }
    else
    {
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
}