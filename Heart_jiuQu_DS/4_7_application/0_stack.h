#include "0_createTree.h"
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define Elemtype TreeNode *

typedef struct {
  Elemtype data[MAXSIZE];
  int top;
} Stack;

void initStack(Stack *S) { S->top = -1; }
int is_empty(Stack *S) {
  if (S->top == -1) {
    puts("The stack is empty.");
    return 1;
  } else
    return 0;
}
int is_full(Stack *S) {
  if (S->top >= MAXSIZE - 1) {
    puts("The stack is full");
    return 1;
  } else
    return 0;
}

int push(Stack *S, Elemtype e) {
  if (is_full(S))
    return 0;
  S->top++;
  S->data[S->top] = e;
  return 1;
}

int pop(Stack *S, Elemtype *e) {
  if (is_empty(S))
    return 0;
  *e = S->data[S->top];
  S->top--;
  return 1;
}

int getTop(Stack *S, Elemtype *e) {
  if (is_empty(S))
    return 0;
  *e = S->data[S->top];
  return 1;
}
