#include "00_BiTree.h"
#include <stdio.h>

#define MAXSIZE 40
typedef BiTree QueueElem;

typedef struct Queue {
  QueueElem data[MAXSIZE];
  int front, rear;
} Queue;

void init_queue(Queue *Q) {
  Q->front = 0;
  Q->rear = 0;
}

void enqueue(Queue *Q, BiTree T) {
  if (Q->rear >= MAXSIZE - 1)
    return;
  Q->data[Q->rear] = T;
  Q->rear++;
}

BiTree dequeue(Queue *Q) {
  if (Q->rear == Q->front)
    return NULL;
  BiTree q = Q->data[Q->front];
  Q->front++;
  return q;
}
