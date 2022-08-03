#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

LinkList List_TailInsert(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next == NULL; // You'd better write this
    LNode *r = L;
    while (1 == scanf("%d", &x))
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        // key logic: why called tail
        r->next = s;
        r = s;
    }
    r->next = NULL;
    return L;
}

LinkList List_HeadInsert(LinkList &L)
{
    // LNode *s; // why you write it here? necessray? //Maybe not
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL; // must have in headinsert. or the list will point to anywhere

    while (1 == scanf("%d", &x))
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        // key logic: why called head
        s->next = L->next; // here's why L->next must be NULL
        L->next = s;
    }
    return L;
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

LinkList ListInverse(LinkList L)
{
    LinkList S = (LinkList)malloc(sizeof(LNode));
    S->next = NULL;
    LNode *p = L->next;
    while (p != NULL)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = p->data;
        // same as head_insert
        s->next = S->next;
        S->next = s;
        p = p->next;
    }
    return S;
}
int main(void)
{
    LinkList L;
    int x;

    printf("Enter you list here(1st time using head insert):\n");
    List_HeadInsert(L);
    printf("Your list is: ");
    ListPrint(L);
    // Inverse after head insert
    L = ListInverse(L);
    printf("Inversed: ");
    ListPrint(L);
}