#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *what(int n) {
  n++;
  struct node *pr = (struct node *)malloc(sizeof(struct node));
  pr->next = NULL;
  // int *pr = &n;
  free(pr);
  return pr;
}

int main() {
  int n = 19;
  struct node *pr = what(n);
}
