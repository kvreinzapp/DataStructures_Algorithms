#include "00_stackSeq.h"

char *expr;

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
} precedence;

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

int print_token(precedence token) {
  switch (token) {
  case ADD:
    printf("+");
    break;
  case SUB:
    printf("-");
    break;
  case MUL:
    printf("*");
    break;
  case DIV:
    printf("/");
    break;
  case MOD:
    printf("%%");
    break;
  default:
    return 0;
  }
  return 1;
}

void postfix(Stack *S) {
  /*  (   )   +   -   *   /   %  EOS */
  int in_stack[] = {0, 19, 12, 12, 13, 13, 13, 0};
  int out_stack[] = {20, 19, 12, 12, 13, 13, 13, 0};
  /*  (   )   +   -   *   /   %  EOS */
  // the sequence of operators's precedences is same as how we defined in enum
  char symbol;
  int index = 0;
  precedence token;
  S->top = 0;
  S->data[0] = EOS;

  token = get_token(&symbol, &index);
  while (token != EOS) {
    if (token == NUM)
      printf("%c", symbol);
    else if (RIGHT_PARE == token) {
      while (S->data[S->top] != LEFT_PARE) {
        print_token(pop(S));
      }
      pop(S); // now the top is LEFT_PARE, we pop it but don't print it
    } else {
      while (in_stack[S->data[S->top]] >= out_stack[token]) {
        print_token(pop(S));
      }
      push(S, token);
    }
    token = get_token(&symbol, &index);
  }
  token = pop(S);
  while (token != EOS) {
    print_token(token);
    token = pop(S);
  }
  puts("");
}

int main(int argc, char **argv) {
  Stack S;
  init_stack(&S);

  expr = argv[1];
  printf("input is %s\n", expr);
  postfix(&S);
  return 0;
}
