#include "00_binaryTree.h"

char *str = "ABDH#K###E##CFI###G#J##";
int Index = 0;

void create_tree(BiTree *T) {
  ElemType ch;
  ch = str[Index++];

  if ('#' == ch) {
    *T = NULL;
  } else {
    *T = (BiTree)malloc(sizeof(TreeNode));
    (*T)->data = ch; // () is equal to ->, associativity is left to right
    create_tree(
        &(*T)->left_child); // means left's addess
                            // we will dereferen it latter to get the left
                            // pointer.
                            // () equal to ->, left to right. & is lower.
    create_tree(&(*T)->right_child);
  }
}

int main() {
  BiTree T;
  create_tree(&T);
  pre_order(T);
  puts("");
  in_order(T);
  puts("");
  post_order(T);
  puts("");
}
