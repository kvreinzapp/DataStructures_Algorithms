#include "00_typedefBTree_char.h"

char *str = "#H#K#D#B#E#A#I#F#C#G#J#"; // in order output
int Index = 0;

void create_tree(BiTree *T) {
  char ch;
  ch = str[Index++];

  if ('#' == ch) {
    *T = NULL;
  } else {
    *T = (BiTree)malloc(sizeof(TreeNode));
    create_tree(&(*T)->left_child);
    (*T)->data = ch;
    create_tree(&(*T)->right_child);
  }
}

int main() {
  BiTree T;
  create_tree(&T);
  pre_order(T);
}
