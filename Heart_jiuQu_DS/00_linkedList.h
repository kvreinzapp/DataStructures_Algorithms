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

void traverse(Node *L) {
  Node *p = L;
  while (p->next != NULL) {
    p = p->next;
    printf("%d ", p->data);
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
