#include "0_createTree.h"

#define ElemType TreeNode *
#define MAXSIZE 100

typedef struct {
  ElemType data[MAXSIZE];
  int front, rear;
} Queue;

void initQueue(Queue *Q) {
  Q->front = 0;
  Q->rear = 0;
}

int enqueue(Queue *Q, TreeNode *T) {
  if (Q->rear >= MAXSIZE - 1) {
    puts("not full, but need adjust");
    return 0;
  }
  Q->data[Q->rear] = T;
  Q->rear++;
  return 1;
}
int dequeue(Queue *Q, TreeNode **T) {
  if (Q->rear == Q->front) {
    puts("Queue is empty");
    *T = NULL;
    return 0;
  }
  *T = Q->data[Q->front];
  Q->front++;
  return 1;
}
int getQueHead(Queue *Q, TreeNode **T) {
  if (Q->rear == Q->front) {
    puts("Queue is empty");
    *T = NULL;
    return 0;
  }
  *T = Q->data[Q->front];
  return 1;
}
