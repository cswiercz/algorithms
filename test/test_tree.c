#include <stdio.h>
#include <assert.h>
#include "algorithms/tree.h"

void test_binary_tree(void)
{
  printf("\n----- test_binary_tree()\n");
  BinaryTree* tree = 0;
  BinaryTree* x;
  BinaryTree* y;

  printf("test insert first node: 42 ...\n");
  binary_tree_insert(&tree, 42);
  assert(tree->key == 42);
  assert(tree->parent == 0);
  assert(tree->left == 0);
  assert(tree->right == 0);

  printf("test search first node: 42...\n");
  x = binary_tree_search(tree, 42);
  assert(x->key == 42);
  assert(x->parent == 0);
  assert(x->left == 0);
  assert(x->right == 0);

  printf("test insert node: 20...\n");
  binary_tree_insert(&tree, 20);
  y = binary_tree_search(tree, 20);
  assert(y->key == 20);
  assert(y->parent == x);
  assert(y->left == 0);
  assert(y->right == 0);
  assert(x->left == y);

  printf("test insert several nodes: 15, 17, 10, 30, 77, 100\n");
  binary_tree_insert(&tree, 15);
  binary_tree_insert(&tree, 17);
  binary_tree_insert(&tree, 10);
  binary_tree_insert(&tree, 30);
  binary_tree_insert(&tree, 77);
  binary_tree_insert(&tree, 100);

  printf("test pre-order traversal: ");
  int foo[8];
  binary_tree_preorder(tree, foo);
  printf("\n");

  printf("test in-order traversal:  ");
  binary_tree_inorder(tree, foo);
  printf("\n");

  printf("test post-order traversal:");
  binary_tree_postorder(tree, foo);
  printf("\n");

  binary_tree_free(tree);
}

int main(int argc, char** argv)
{
  printf("\n===== Testing Trees (Of Various Sorts)\n");
  test_binary_tree();
  printf("\n===== Done\n");
  return 0;
}
