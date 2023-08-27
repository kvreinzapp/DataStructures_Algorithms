#include "00_typedefNode.h"
#include <stdio.h>

void test(Node *L) { L->data = 52; }

int main() {
  Node *L = init();
  L->data = 42;
  test(L);
  printf("%d", L->data);
}
