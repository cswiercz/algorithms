#ifndef __ALGORITHMS_TREE_H
#define __ALGORITHMS_TREE_H

typedef struct BinaryTree
{
  int key;
  struct BinaryTree* parent;
  struct BinaryTree* left;
  struct BinaryTree* right;
} BinaryTree;

BinaryTree* binary_tree_search(BinaryTree*, int);
void binary_tree_insert(BinaryTree**, int);
void binary_tree_free(BinaryTree*);
#endif
