#include <stdio.h>
#include <stdlib.h>
#include "algorithms/tree.h"

BinaryTree* binary_tree_search(BinaryTree* tree, int k)
{
  BinaryTree* x = tree;

  while (x != 0) {
    if (k < x->key)
      x = x->left;
    else if (x->key < k)
      x = x->right;
    else
      return x;
    }
  return tree;
}

void binary_tree_insert(BinaryTree** tree, int key)
{
  BinaryTree* current = *tree;
  BinaryTree* previous = *tree;

  // root case: empty tree
  if (current == 0) {
    (*tree) = (BinaryTree*)malloc(sizeof(BinaryTree));
    (*tree)->key = key;
    (*tree)->parent = 0;
    (*tree)->left = 0;
    (*tree)->right = 0;
    return;
  }

  // traverse to the bottom of the tree
  while (current != 0) {
    previous = current;
    if (key < current->key)
      current = current->left;
    else
      current = current->right;
  }

  // current is now NULL and previous was its parent
  current = (BinaryTree*)malloc(sizeof(BinaryTree));
  current->key = key;
  current->parent = previous;
  current->left = 0;
  current->right = 0;
  if (key < previous->key)
    previous->left = current;
  else
    previous->right = current;
}

void binary_tree_free(BinaryTree* tree)
{
  BinaryTree* left;
  BinaryTree* right;

  if (tree->left != 0)
    binary_tree_free(tree->left);
  if (tree->right != 0)
    binary_tree_free(tree->right);

  free(tree);
}

void binary_tree_preorder(BinaryTree* tree, int* values)
{
  if (tree->left != 0)
    binary_tree_preorder(tree->left, values);
  if (tree->right != 0)
    binary_tree_preorder(tree->right, values);
  if (tree != 0)
    printf(" %d", tree->key);
}
void binary_tree_inorder(BinaryTree* tree, int* values)
{
  if (tree->left != 0)
    binary_tree_preorder(tree->left, values);
  if (tree != 0)
    printf(" %d", tree->key);
  if (tree->right != 0)
    binary_tree_preorder(tree->right, values);
}
void binary_tree_postorder(BinaryTree* tree, int* values)
{
  if (tree != 0)
    printf(" %d", tree->key);
  if (tree->left != 0)
    binary_tree_preorder(tree->left, values);
  if (tree->right != 0)
    binary_tree_preorder(tree->right, values);
}
