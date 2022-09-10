#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sqstack.h"
#define MAXSIZE 10
bool bracketCheck(char str[], int length)
{
    SqStack S;
    InitStack(S);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            Push(S, str[i]);
        }
        else
        {
            if (Empty(S))
            {
                printf("Single right\n");
                return false;
            }
            char topElem;
            Pop(S, topElem);
            if (str[i] == '(' && str[i] != ')')
            {
                printf("() wrong match\n");
                return false;
            }
            if (str[i] == '[' && str[i] != ']')
            {
                printf("[] wrony match\n");
                return false;
            }
            if (str[i] == '{' && str[i] != '}')
            {
                printf("{} wrong match\n");
                return false;
            }
        }
    }
    // return (Empty(S));
    if (Empty(S))
    {
        printf("Perfect mathced!");
        return false;
    }
    else
    {
        printf("Single left\n");
        return true;
    }
}
int main(void)
{
    char str1[MAXSIZE] = {'{', '{', '{', '{', '}'};
    char str2[MAXSIZE] = {'{', '}', '}', '}', '}'};
    char str3[MAXSIZE] = {'{', '{', '{', '{', ')', '}', '}', '}'};
    bracketCheck(str1, 5);
    bracketCheck(str2, 5);
    bracketCheck(str3, 8);
}
