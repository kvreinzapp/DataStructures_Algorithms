#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct node {
  ElemType data;
  struct node *next;
} Node;

// void init(Node *L) {
//   L = (Node *)malloc(sizeof(Node));
//   L->next = NULL;
// }
Node *init() {
  Node *head = (Node *)malloc(sizeof(Node));
  head->data = 0;
  head->next = NULL;
  return head;
}

void head_insert(Node *L, ElemType e) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->data = e;
  p->next = L->next;
  L->next = p;
}

Node *getTail(Node *L) {
  Node *p = L;
  while (p->next != NULL) {
    p = p->next;
  }
  return p;
}
void tail_insert(Node *L, ElemType e) {
  Node *p = getTail(L);
  Node *q = (Node *)malloc(sizeof(Node));
  p->next = q;
  q->next = NULL;
  q->data = e;
}

void traverse(Node *L) {
  Node *p = L;
  while (p->next != NULL) {
    p = p->next;
    printf("%d ", p->data);
  }
  puts("");
}

void traverse_withoutHead(Node *L) {
  Node *p = L;
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
  puts("");
}

void free_list(Node *L) {
  Node *p = L;
  while (p != NULL) {
    Node *q = p->next;
    free(p);
    p = q;
  }
}
