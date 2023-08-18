#include <stdio.h>

#define MAX_SIZE 100

typedef int Elemtype;

typedef struct {
  Elemtype data[MAX_SIZE];
  int top;
} Stack;

void init_stack(Stack *S) { S->top = -1; }

int is_empty(Stack *S) {
  if (-1 == S->top) {
    puts("Stack is empty");
    return 1;
  } else {
    return 0;
  }
}

int push(Stack *S, Elemtype e) {
  if (S->top >= MAX_SIZE - 1) {
    puts("Stack is full");
    return 0;
  }
  S->top++;
  S->data[S->top] = e;
  return 1;
}

Elemtype pop(Stack *S) {
  if (-1 == S->top) {
    puts("Stack is empty");
    return 0;
  }
  Elemtype e = S->data[S->top];
  S->top--;
  return e;
}

int get_top(Stack *S,
            Elemtype *e) // Maybe teacher's code is wrong cause we need to
                         // return the top value of the Stack.Ohhhh,no we pass a
                         // pointer means we don't need to return it
{
  if (-1 == S->top) {
    puts("Stack is empty");
    return 0;
  }
  *e = S->data[S->top];
  return 1;
}
