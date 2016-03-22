#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "algorithms/queue.h"

Queue* new_queue(void)
{
  Queue* Q = (Queue*)malloc(sizeof(Queue));
  Q->length = 0;
  Q->head = NULL;
  Q->tail = NULL;
  return Q;
}

void free_queue(Queue* Q)
{
  QueueNode* x = Q->head;
  QueueNode* y = Q->head;
  while (x != NULL) {
    free(x);
    x = y->next;
    y = x;
  }
  free(Q);
}

void print_queue(Queue* Q)
{
  QueueNode* x = Q->head;
  while (x != NULL) {
    printf("%d ", x->data);
    x = x->next;
  }
}

void enqueue(Queue* Q, int k)
{
  // create the new queue node
  QueueNode* x = (QueueNode*)malloc(sizeof(QueueNode));
  x->data = k;
  x->next = NULL;

  // empty queue case: head is null iff tail is null
  if (Q->head == NULL) {
    //assert(Q->tail == NULL);
    Q->head = x;
    Q->head->next = Q->tail;
    Q->tail = x;
  } else {
    Q->tail->next = x;
    Q->tail = x;
  }

  Q->length += 1;
}

int dequeue(Queue* Q)
{
  int k;

  if (Q->head != NULL) {
    k = Q->head->data;

    // make the second element of the queue the new first element;
    Q->head = Q->head->next;
    Q->length -= 1;
    return k;
  }
}

