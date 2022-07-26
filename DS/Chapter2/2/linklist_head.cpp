#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// define a LNode
// LNode *ptr   and   LinkList ptr is same way to define a ptr pionted to node
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
        return false; // means that malloc is false, we don't have enough memory
    L->next = NULL;
    return true;
}
bool Empty(LinkList L)
{
    return (L->next == NULL);
}

/*******************************************************Insert**************************************************/
bool ListInsert(LinkList &L, int i, int e)
{
    // i can't less than 1
    if (i < 1)
        return false;
    // create a ptr point to head
    LNode *p; // p point to LNode
    p = L;
    // j  and  while are there to let p point to last node(i-1) of position i
    int j = 0;
    while (p != NULL && j < i - 1)
    {
        p = p->next; // p point to L, and p's next is actrually next
        j++;
    }
    // now j must equal to i-1  and  p point to it
    // because it is a linklist, so we have to use a loop to point i-1 one node by one node

    // the if here is for the bigger i, if i is so big, p will point to NULL, because the LinkList's end is point to NULL
    if (p == NULL)
        return false;

    // now we add a new node
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    // must save the information in new place(the new node) before we change the last node's next
    s->next = p->next;
    p->next = s;
    return true;
}

// Another way to write, using writened functions, very clear!
bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;
    LNode *p = GetElem(L, i - 1);
    return InsertNextNode(p, e);
}

// Insert next and prior node
bool InsertNextNode(LNode *p, int e) // PA: we give it a pointer, not node
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool InsertPriorNode(LNode *p, int e) // quite smart
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

/************************************************************Delete**************************************************/
bool ListDelete(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;

    LNode *p;
    p = L;

    int j = 0;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;

    // from here is diff
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return false;
}

bool DeleteNode(LNode *p) // if p is the last node, this code will have bug
{
    if (p == NULL)
        return false;
    LNode *q = p->next; // if p is the last one , p->next->data gonna be wrong, we have to use another way(give us the head pointer)
    p->data = q->data;  // teacher is code is : p->data = p->next->data;   is it necessary?
    p->next = q->next;
    free(q);
    return true;
}

/*****************************************************Find**********************************************************/
/**************find by order**********/
// GetElem can be called to find the node in the above functions
// Like : LNode *p=GetElem(L,i-1);
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)       // Here we considered the head point as the 0st point, so i<0 instead of i<1, doesn't like before
        return NULL; // not return fasle, it's NULL

    // From here is same
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    // don't need it any more, because if p==NULL, we just return it
    //  if (p == NULL)
    //      return NULL;
    return p;
}

/**************find by value*************/
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p; // same reason, if p==NULL, just return it
}
/**************calculate the length*************/
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L->next;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}
// vedio version
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}
// p=a;p—>n!=NULL;p=b,+1;p-n!NULL;p=c.+1;p-n=NULL,out
// you see , int this way, 3 node, i is two,is that right?
int main(void)
{
}