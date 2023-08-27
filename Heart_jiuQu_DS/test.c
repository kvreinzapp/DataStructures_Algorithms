#include <stdio.h>
typedef struct NodeTree {
  char data;
  struct NodeTree *left;
  struct NodeTree *right;
} NodeTree, *BiTree;

void changeIt(BiTree T) { T = NULL; }

int main() {
  NodeTree A;
  NodeTree *I = &A;

  printf("I->left:%p\n", I->left);
  changeIt(I);
  printf("I->left:%p\n", I->left);
}
