#include <stdio.h>

typedef struct Node {
  int *a;
  int *b;
} Node;

void change(Node *e) { e->a = NULL; }

int main() {
  Node e;
  Node *p = &e;
  int num = 2;
  p->a = &num;
  printf("%p\n", p->a);
  change(p);
  printf("%p\n", p->a);
}
