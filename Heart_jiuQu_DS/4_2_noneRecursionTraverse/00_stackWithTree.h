#include "00_BiTree.h"
#include <stdio.h>
#define MAXSIZE 40
typedef BiTree StackElemType;
typedef struct stack {
  StackElemType data[MAXSIZE];
  int top;
} Stack;

void init_stack(Stack *S) { S->top = -1; }

int push(Stack *S, StackElemType e) {
  if (MAXSIZE - 1 <= S->top) {
    puts("Stack is full.");
    return 0;
  }
  S->top++;
  S->data[S->top] = e;
  return 1;
}

StackElemType pop(Stack *S) {
  if (-1 == S->top) {
    puts("Stack is empty.");
    return 0;
  }
  StackElemType e = S->data[S->top];
  S->top--;
  return e;
}

int is_empty(Stack *S) {
  if (-1 == S->top) {
    // puts("Stack is empty.");
    return 1;
  } else {
    return 0;
  }
}
StackElemType get_top(Stack *S) { return S->data[S->top]; }

void print_stack(Stack *S) {
  while (S->top != -1) {
    printf("%c", (S->data[S->top])->data);
  }
  puts("");
}
