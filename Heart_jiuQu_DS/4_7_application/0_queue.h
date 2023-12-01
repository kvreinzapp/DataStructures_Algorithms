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

int emptyQueue(Queue *Q) {
  if (Q->rear == Q->front) {
    puts("The Queue is empty.");
    return 1;
  } else
    return 0;
}

int fullQueue(Queue *Q) {
  if ((Q->rear + 1) % MAXSIZE == Q->front) {
    puts("The Queue is full.");
    return 1;
  } else
    return 0;
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
  if (emptyQueue(Q)) {
    *T = NULL;
    return 0;
  }
  *T = Q->data[Q->front];
  Q->front++;
  return 1;
}

int getQueHead(Queue *Q, TreeNode **T) {
  if (emptyQueue(Q)) {
    *T = NULL;
    return 0;
  }
  *T = Q->data[Q->front];
  return 1;
}

int sizeQueue(Queue *Q) { return Q->rear - Q->front; }
