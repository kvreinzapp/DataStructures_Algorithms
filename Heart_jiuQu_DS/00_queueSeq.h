#include <stdio.h>
#define MAX_SIZE 100

typedef int Elemtype;

typedef struct {
  Elemtype data[MAX_SIZE];
  int front, rear;
} Queue;

void init_queue(Queue *Q) {
  Q->front = 0;
  Q->rear = 0;
}

int is_empty(Queue *Q) {
  if (Q->front == Q->rear) {
    puts("Queue is empty");
    return 1;
  } else
    return 0;
}

int queue_full(Queue *Q) { return 1; }

int enqueue(Queue *Q, Elemtype e) {
  if (MAX_SIZE - 1 <= Q->rear) {
    queue_full();
  }
  Q->data[Q->rear] = e;
  Q->rear++;
  return 1;
}

Elemtype dequeue(Queue *Q) {
  if (Q->front == Q->rear) {
    puts("Queue is empty");
    return 0;
  }

  Elemtype e = Q->data[Q->front];
  Q->front++;
  return e;
}

int get_head(Queue *Q, Elemtype *e) {
  if (Q->front == Q->rear) {
    puts("Queue is empty");
    return 0;
  }

  *e = Q->data[Q->front];
  return 1;
}
