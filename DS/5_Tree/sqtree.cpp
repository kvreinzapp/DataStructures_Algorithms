#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100
struct TreeNode
{
    int value;
    bool isEmpty;
};

TreeNode t[MAXSIZE];

void InitTree(TreeNode &T)
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        t[i].isEmpty = true;
    }
}