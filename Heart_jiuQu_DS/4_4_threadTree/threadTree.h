#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct ThreadNode {
  ElemType data;
  struct ThreadNode *left_child;
  struct ThreadNode *right_child;
  int left_tag;
  int right_tag;
} ThreadNode;
typedef ThreadNode *ThreadTree;
// typedef struct ThreadNode *ThreadTree;

char *str = "ABDH#K###E##CFI###G#J##";
int Index = 0;

void create_thread_tree(ThreadTree *T) {
  ElemType ch = str[Index++];
  if ('#' == ch) {
    *T = NULL;
  } else {
    *T = (ThreadTree)malloc(sizeof(ThreadNode));
    (*T)->data = ch;
    create_thread_tree(&(*T)->left_child);
    if ((*T)->left_child != NULL) {
      (*T)->left_tag = 0;
    }
    create_thread_tree(&(*T)->right_child);
    if ((*T)->right_child != NULL) {
      (*T)->right_tag = 0;
    }
  }
}

ThreadNode *prev = NULL; // Global varible is convinence for recursion

void Threading(ThreadTree T) {
  if (T != NULL) {
    Threading(T->left_child);

    if (T->left_child == NULL) {
      T->left_tag = 1;
      T->left_child = prev;
    }
    if (prev->right_child == NULL) {
      prev->right_tag = 1;
      prev->right_child = T;
    }
    prev = T;

    Threading(T->right_child);
  }
}

void inorder_threading(
    ThreadTree *head,
    ThreadTree T) { // For special condition like head node or the last node
  *head = (ThreadTree)malloc(sizeof(ThreadNode));
  (*head)->left_tag = 0;
  (*head)->left_tag = 1;
  (*head)->right_child = *head;

  if (T == NULL) {
    (*head)->left_child = *head;
  } else {
    (*head)->left_child = T;
    prev = *head;

    Threading(T);

    prev->right_tag = 1;
    prev->right_child = *head;
    (*head)->right_child = prev;
  }
}

void thread_inorder_noRecur(ThreadTree head) {
  ThreadTree curr = head->left_child;

  while (curr != head) {
    while (curr->left_tag == 0) {
      curr = curr->left_child;
    }

    printf("%c", curr->data);

    while (curr->right_tag == 1 && curr->right_child != head) {
      curr = curr->right_child;
      printf("%c", curr->data);
    }

    curr = curr->right_child;
  }
  puts("");
}

void inorder(ThreadTree T) {
  if (T == NULL)
    return;
  inorder(T->left_child);
  printf("%c", T->data);
  inorder(T->right_child);
}
