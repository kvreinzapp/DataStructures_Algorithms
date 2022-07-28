#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

LinkList List_TaliInsert(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next == NULL; // You'd better write this
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

LinkList List_HeadInsert(LinkList &L)
{
    LNode *s; // why you write it here? necessray?
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL; // must have in headinsert. or the list will point to anywhere
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next; // here's why L->next must be NULL
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

void ListPrint(LinkList L)
{
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        printf("%d ", p->data);
    }
}

int main(void)
{
    LinkList L;
    List_TaliInsert(L);
    ListPrint(L);
}