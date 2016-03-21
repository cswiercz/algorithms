#ifndef __ALGORITHMS_LIST_H
#define __ALGORITHMS_LIST_H

// A Node of a doubly-linked list
typedef struct Node
{
  int key;
  struct Node* prev;
  struct Node* next;
} Node;

// A doubly-linked list.
typedef struct List
{
  Node* head;
} List;


// Returns a reference to a Node with a matching key.
//
// Note that the reference returned is to the first occurrence of the key in the
// List.
Node* list_search(List, int);

// Inserts a Node with the given key into the List.
//
// Insertion is done at the head of the list. Internally, a function
// list_insert_node is called where a node is created containing the given key.
void list_insert(List*, int);

// Deletes a Node from the List.
void list_delete(List*, Node*);

// Prints a list.
void list_print(List);

// "Frees" a list.
//
// A helper function that frees each Node within a list.
void list_free(List);

#endif
