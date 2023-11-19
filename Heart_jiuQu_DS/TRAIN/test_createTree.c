#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char data;
  struct node *left_child;
  struct node *right_child;
} TreeNode, *BiTree;

char *str = "ABDH#K###E##CFI###G#J##";
int Index = 0;

void create_tree(BiTree *T) {
  char ch;
  ch = str[Index++];

  if ('#' == ch) {
    *T = NULL;
  } else {
    *T = (BiTree)malloc(sizeof(TreeNode));
    (*T)->data = ch;
    create_tree(&(*T)->left_child);
    create_tree(&(*T)->right_child);
  }
}

int main() {
  BiTree T;
  create_tree(&T);
  pre_order(T);
}
