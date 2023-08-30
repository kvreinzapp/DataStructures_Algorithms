#include "00_stackWithTree.h"
#include <stdio.h>

void iter_preorder(BiTree T, Stack *S) {
  while (!(T == NULL && is_empty(S) == 1)) {
    //  while (T != NULL || is_empty(S) != 0) {
    while (T != NULL) {
      printf("%c", T->data);
      push(S, T);
      T = T->left_child;
    }
    T = pop(S);
    T = T->right_child;
  }
  puts("");
}

void iter_inorder(BiTree T, Stack *S) {
  while (!(NULL == T && is_empty(S) == 1)) {
    // while (!(NULL == T) && (is_empty(S) == 1)) {
    while (T != NULL) {
      push(S, T);
      T = T->left_child;
    }
    T = pop(S);
    printf("%c", T->data);
    T = T->right_child;
  }
  puts("");
}

void iter_postorder(BiTree T, Stack *S) {
  BiTree prev = NULL;
  while (!(T == NULL && is_empty(S) == 1)) {
    while (T != NULL) {
      push(S, T);
      T = T->left_child;
    }
    T = get_top(S);
    if (T->right_child != NULL && T->right_child != prev) {
      T = T->right_child;
    } else {
      pop(S);
      printf("%c", T->data);
      prev = T;
      T = NULL;
    }
  }
  puts("");
}

int main() {
  BiTree T;
  Stack S;
  init_stack(&S);
  create_tree(&T);

  puts("pre oder using recursion");
  iter_preorder(T, &S);
  puts("pre order without recursion:");
  pre_order(T);
  puts("");

  puts("in oder using recursion");
  iter_inorder(T, &S);
  puts("in order without recursion:");
  in_order(T);
  puts("");

  puts("post oder using recursion");
  iter_postorder(T, &S);
  puts("post order without recursion:");
  post_order(T);
  puts("");

  print_stack(&S);
}
