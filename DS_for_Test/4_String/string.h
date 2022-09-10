
#include <stdbool.h>
#include <stdlib.h>
#define MAXLEN 255
// Static
typedef struct
{
    char ch[MAXLEN];
    int length;
} SString;

// Dynamic
typedef struct
{
    char *ch;
    int length;
} HString;
void InitHString(HString &S)
{
    HString S;
    S.ch = (char *)malloc(MAXLEN * sizeof(char));
    S.length = 0;
}

// Link
typedef struct StringNode
{
    char ch[4]; // for a better stroing density
    struct StringNode *next;
} StringNode, *String;

// Some basic operation
// Substring
bool SubString(SString &Sub, SString &S, int pos, int len)
{
    if (pos + len - 1 > S.length) // not just less than MAXSIZE
        return false;
    for (int i = pos; i < pos + len; i++)
        Sub.ch[i - pos + 1] = S.ch[i];
    Sub.length = len;
    return true;
}

// compare two string, if the 1st is bigger, return the value>0
bool StrCompare(SString &S, SString &T)
{
    for (int i = 1; i <= S.length && i <= T.length; i++)
    {
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    }
    return S.length - T.length;
}

// length
int StrLength(SString &S)
{
    return S.length;
}

// Index the frist occurrence
bool Index(SString &S, SString &T)
{
    int i = 1, n = StrLength(S), m = StrLength(T);
    SString sub;
    while (i <= n - m + 1)
    {
        SubString(sub, S, i, m);
        if (StrCompare(Sub, T) != 0)
            ++i;
        else
            return i;
    }
    return 0;
}

//
int IndexBasic(SString S, SString T)
{
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length)
    {
        if (S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 2; // really important
            j = 1;
        }
    }
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}