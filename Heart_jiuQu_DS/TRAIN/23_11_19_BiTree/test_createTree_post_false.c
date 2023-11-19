#include "00_typedefBTree_char.h"

char *str = "###KH#D##EB##I#F###JGCA"; // post order output
int Index = 0;

void create_tree(BiTree *T) {
  char ch;
  ch = str[Index++];

  *T = (BiTree)malloc(sizeof(TreeNode));
  (*T)->data = ch;
  if (ch == '#')
    *T = NULL;
  else {
    create_tree(&(*T)->left_child);
    create_tree(&(*T)->right_child);
  }
}

int main() {
  BiTree T;
  create_tree(&T);
  pre_order(T);
}
