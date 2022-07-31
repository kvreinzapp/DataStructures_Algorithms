#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

bool ListInit(LinkList &L)
{
    L = NULL;
    return true;
}
void ListPrint(LinkList L)
{
    LNode *p = L;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int Take_int(void)
{
    int val;
    while (1 != scanf("%d", &val))
    {
        printf("Must enter integer,Enter again:");
        while (getchar() != '\n')
            ;
    }
    return val;
}

LinkList List_TailInsert(LinkList &L)
{
    int x;
    x = Take_int();
    // For first node
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = L;
    L = s;
    printf("now:%d\n", s->data);
    // For remain
    LNode *p = s;
    while (1 == scanf("%d", &x))
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        p->next = s;
        p = s;
        printf("now:%d\n", s->data);
    }
    p->next = NULL;
    return L;
}

LinkList List_HeadInsert(LinkList &L)
{
    int x = Take_int();
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = L;
    L = s;
    while (1 == scanf("%d"))
    {
        /* code */
    }
}

int main(void)
{
    LinkList L;
    List_TailInsert(L);
    ListPrint(L);
}