#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "algorithms/queue.h"
#include "algorithms/tree.h"

BinaryTreeNode* binary_tree_search(BinaryTree* tree, int k)
{
  BinaryTreeNode* x = tree->root;

  while (x != 0) {
    if (k < x->key)
      x = x->left;
    else if (x->key < k)
      x = x->right;
    else
      return x;
    }

  return NULL;
}

void binary_tree_insert(BinaryTree* tree, int key)
{
  BinaryTreeNode* current = tree->root;
  BinaryTreeNode* previous = tree->root;
  BinaryTreeNode* x = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
  x->key = key;
  x->left = NULL;
  x->right = NULL;
  tree->size++;

  // empty tree case
  if (tree->root == NULL) {
    tree->root = x;
    return;
  }

  // traverse to the bottom of the tree
  while (current != NULL) {
    previous = current;
    if (key < current->key)
      current = current->left;
    else
      current = current->right;
  }

  // current is now NULL and previous was its parent
  current = x;
  if (key < previous->key)
    previous->left = current;
  else
    previous->right = current;
}

void binary_tree_free_node(BinaryTreeNode* x)
{
  if (x->left != NULL)
    binary_tree_free_node(x->left);
  if (x->right != NULL)
    binary_tree_free_node(x->right);
  free(x);
}
void binary_tree_free(BinaryTree* tree)
{
  binary_tree_free_node(tree->root);
  free(tree);
}

// return a post-ordering of the tree
//
int binary_tree_postorder_node(BinaryTreeNode* x, int* values,
                               int index)
{
  if (x->left != NULL)
    index = binary_tree_postorder_node(x->left, values, index);
  if (x->right != NULL)
    index = binary_tree_postorder_node(x->right, values, index);
  if (x != NULL)
    values[index] = x->key;
  return index+1;
}
void binary_tree_postorder(BinaryTree* tree, int* values)
{
  binary_tree_postorder_node(tree->root, values, 0);
}

// return a pre-ordering of the tree
//
int binary_tree_preorder_node(BinaryTreeNode* x, int* values,
                               int index)
{
  if (x != NULL)
    values[index] = x->key;
  if (x->left != NULL)
    index = binary_tree_preorder_node(x->left, values, index+1);
  if (x->right != NULL)
    index = binary_tree_preorder_node(x->right, values, index+1);
  return index;
}
void binary_tree_preorder(BinaryTree* tree, int* values)
{
  binary_tree_preorder_node(tree->root, values, 0);
}


void binary_tree_BFS(BinaryTree* tree, int* values)
{
  Queue* Q = new_queue();
  BinaryTreeNode* x = tree->root;
  int index = 0;
  int data;

  // initialize the queue with the root node value
  enqueue(Q, x->key);

  while (Q->head != NULL)
    {
      // extract and store the current node's key
      data = dequeue(Q);
      x = binary_tree_search(tree, data);
      values[index] = x->key;

      // enqueue the current node's children
      if (x->left != NULL)
        enqueue(Q, x->left->key);
      if (x->right != NULL)
        enqueue(Q, x->right->key);

      index++;
    }

  free_queue(Q);
}
