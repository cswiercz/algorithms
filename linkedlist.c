#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct Node
{
  int key;
  struct Node* prev;
  struct Node* next;
} Node;

typedef struct List
{
  Node* head;
} List;



/*
  list_search(List, int)

  Returns a (the first) node with matching a given key.
*/
Node* list_search(List l, int k)
{
  Node *x = l.head;
  while ((x != NULL) && (x->key != k))
      x = x->next;
  return x;
}

/*
  list_insert(List, Node)

  Inserts a given node into a list.
*/
void list_insert_node(List* l, Node* x)
{
  x->next = l->head;
  if (l->head != NULL)
    l->head->prev = x;
  l->head = x;
  x->prev = NULL;
}

/*
  list_insert(List, int)

  Insterts a given key into a list by creating a node.
*/
void list_insert(List* l, int k)
{
  Node* x = (Node*)malloc(sizeof(Node));
  x->key = k;
  list_insert_node(l, x);
}

/*
  list_delete(List, Node)

  Removes a node from a given list. x must be a member of the list
*/
void list_delete(List* l, Node* x)
{
  if (x->prev != NULL)
    x->prev->next = x->next;
  else // x is head
    l->head = x->next;

  if (x->next != NULL)
    x->next->prev = x->prev;
}

/*
  list_print
  
  Prints a list.
*/
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


void free_list(List l)
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


int main(int argc, char** argv)
{
  List l, m;
  printf("\n===== Linked Lists =====\n\n");

  printf("\ntesting null list...");
  assert(m.head == NULL);

  printf("\ntesting insert...");
  list_insert(&l, 1);
  list_insert(&l, 2);
  list_insert(&l, -7);
  list_insert(&l, 0);
  list_insert(&l, 3);
  list_print(l);
 
  printf("\ntesting search...");
  Node* x = list_search(l, 42);
  assert(x == NULL);
  Node* y = list_search(l, 2);
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
    

  printf("\n\n=====     Done     =====\n");
  free_list(l);
  return 0;
}
