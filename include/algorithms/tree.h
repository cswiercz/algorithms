#include <stdlib.h>

#ifndef __ALGORITHMS_TREE_H
#define __ALGORITHMS_TREE_H

typedef struct BinaryTreeNode
{
  int key;
  struct BinaryTreeNode* left;
  struct BinaryTreeNode* right;
} BinaryTreeNode;

typedef struct
{
  size_t size;
  BinaryTreeNode* root;
} BinaryTree;

BinaryTreeNode* binary_tree_search(BinaryTree*, int);
void binary_tree_insert(BinaryTree*, int);
void binary_tree_free(BinaryTree*);
void binary_tree_preorder(BinaryTree*, int*);
void binary_tree_postorder(BinaryTree*, int*);
void binary_tree_BFS(BinaryTree*, int*);

#endif
