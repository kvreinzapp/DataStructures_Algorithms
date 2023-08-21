#include "00_stackSeq.h"
#include <stdio.h>

typedef enum {
  LEFT_PARE,
  RIGHT_PARE,
  ADD,
  SUB,
  MUL,
  DIV,
  MOD,
  EOS,
  NUM
} precedence; // EOS: end of string, NUM: numbers

char *expr;

precedence get_token(char *symbol, int *index) {
  *symbol = expr[*index];
  *index = *index + 1;
  switch (*symbol) {
  case '(':
    return LEFT_PARE;
  case ')':
    return RIGHT_PARE;
  case '+':
    return ADD;
  case '-':
    return SUB;
  case '*':
    return MUL;
  case '/':
    return DIV;
  case '%':
    return MOD;
  case '\0':
    return EOS;
  default:
    return NUM;
  }
}

int eval(Stack *S) {
  char symbol;
  int op1, op2;
  int index = 0;
  precedence token;

  token = get_token(&symbol, &index);

  while (token != EOS) {
    if (NUM == token) {
      push(S, symbol - '0');
    } else {
      op2 = pop(S);
      op1 = pop(S);
      switch (token) {
      case ADD:
        push(S, op1 + op2);
        break;
      case SUB:
        push(S, op1 - op2);
        break;
      case MUL:
        push(S, op1 * op2);
        break;
      case DIV:
        push(S, op1 / op2);
        break;
      case MOD:
        push(S, op1 % op2);
        break;
      default:
        break;
      }
    }
    token = get_token(&symbol, &index);
  }

  int result = pop(S);
  printf("result is %d\n", result);
  return 0;
}

int main(int argc, char **argv) {
  Stack S;
  init_stack(&S);

  expr = argv[1];
  printf("intput is %s\n", expr);
  eval(&S);
  return 0;
}
