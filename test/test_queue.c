#include <stdio.h>
#include <assert.h>
#include "algorithms/queue.h"

void test_queue(void)
{
  printf("----- creating new queue...\n");
  Queue* Q = new_queue();
  /* (Queue*)malloc(sizeof(Queue)); */
  /* Q->length = 0; */
  /* Q->head = NULL; */
  /* Q->tail = NULL; */

  printf("----- enqueueing...\n");
  enqueue(Q, 1);
  enqueue(Q, 2);
  enqueue(Q, 3);
  enqueue(Q, 4);
  enqueue(Q, 5);

  printf("----- printing queue...\n");
  print_queue(Q);

  printf("\n----- dequeueing...\n");
  int k = 0;
  k = dequeue(Q);
  printf("k = %d\n", k);
  k = dequeue(Q);
  printf("k = %d\n", k);
  k = dequeue(Q);
  printf("k = %d\n", k);

  printf("----- printing queue...\n");
  print_queue(Q);

  free_queue(Q);
}

int main(int argc, char** argv)
{
  printf("\n===== Testing Queues =====\n\n");
  test_queue();
  printf("\n\n=====     Done     =====\n");
  return 0;
}
