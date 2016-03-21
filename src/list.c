#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "algorithms/list.h"

Node* list_search(List l, int k)
{
  Node *x = l.head;
  while ((x != NULL) && (x->key != k))
      x = x->next;
  return x;
}

void list_insert_node(List* l, Node* x)
{
  x->next = l->head;
  if (l->head != NULL)
    l->head->prev = x;
  l->head = x;
  x->prev = NULL;
}

void list_insert(List* l, int k)
{
  Node* x = (Node*)malloc(sizeof(Node));
  x->key = k;
  list_insert_node(l, x);
}

void list_delete(List* l, Node* x)
{
  if (x->prev != NULL)
    x->prev->next = x->next;
  else // x is head
    l->head = x->next;

  if (x->next != NULL)
    x->next->prev = x->prev;
}

void list_print(List l)
{
  Node* x = l.head;
  printf("\n[");
  while (x != NULL)
    {
      printf(" %d", x->key);
      x = x->next;
    }
  printf("]");
}

void list_free(List l)
{
  Node* x = l.head;
  Node* y = l.head;
  while (x != NULL)
    {
      free(x);
      x = y->next;
      y = x;
    }
}
