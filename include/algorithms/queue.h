#include <stdlib.h>


#ifndef __ALGORITHMS_QUEUE_H
#define __ALGORITHMS_QUEUE_H

// A queue is a list that
typedef struct QueueNode
{
  int data;
  struct QueueNode* next;
} QueueNode;

typedef struct Queue {
  size_t length;
  struct QueueNode* head;
  struct QueueNode* tail;
} Queue;


Queue* new_queue(void);
void free_queue(Queue*);
void print_queue(Queue*);
void enqueue(Queue*, int);
int dequeue(Queue*);

#endif
