#ifndef __ALGORITHMS_LIST_H
#define __ALGORITHMS_LIST_H

// A Node of a doubly-linked list
typedef struct ListNode
{
  int key;
  struct ListNode* prev;
  struct ListNode* next;
} ListNode;

// A doubly-linked list.
typedef struct List
{
  ListNode* head;
} List;


// Returns a reference to a ListNode with a matching key.
//
// Note that the reference returned is to the first occurrence of the key in the
// List.
ListNode* list_search(List, int);

// Inserts a ListNode with the given key into the List.
//
// Insertion is done at the head of the list. Internally, a function
// list_insert_node is called where a node is created containing the given key.
void list_insert(List*, int);

// Deletes a ListNode from the List.
void list_delete(List*, ListNode*);

// Prints a list.
void list_print(List);

// "Frees" a list.
//
// A helper function that frees each ListNode within a list.
void list_free(List);

#endif
