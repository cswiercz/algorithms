#include <stdio.h>
#include <assert.h>
#include "algorithms/list.h"

void test_list(void)
{
  List l;
  ListNode* x;
  ListNode* y;

  printf("\ntesting null list...");
  assert(l.head == NULL);

  printf("\ntesting insert...");
  list_insert(&l, 1);
  list_insert(&l, 2);
  list_insert(&l, -7);
  list_insert(&l, 0);
  list_insert(&l, 3);
  list_print(l);

  printf("\ntesting search...");
  x = list_search(l, 42);
  assert(x == NULL);
  y = list_search(l, 2);
  assert(y->key == 2);

  printf("\ntesting deletion...");
  list_delete(&l, y);
  list_print(l); // should be [3 0 -7 1]

  y = list_search(l, -7);
  list_delete(&l, y);
  list_print(l); // should be [3 0 1]

  y = list_search(l, 1);
  list_delete(&l, y);
  list_print(l); // should be [3 0]

  y = list_search(l, 3);
  list_delete(&l, y);
  list_print(l); // should be [0]
  list_free(l);
}

int main(int argc, char** argv)
{
  printf("\n===== Linked Lists =====\n\n");
  test_list();
  printf("\n\n=====     Done     =====\n");
  return 0;
}
