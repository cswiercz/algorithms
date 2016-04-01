#include <stdio.h>
#include <assert.h>
#include "algorithms/tree.h"

void test_binary_tree(void)
{
  printf("\n----- test_binary_tree()\n");
  BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
  tree->root = NULL;

  BinaryTreeNode* x;
  BinaryTreeNode* y;

  printf("test insert first node: 42 ...\n");
  binary_tree_insert(tree, 42);
  assert(tree->root->key == 42);
  assert(tree->root->left == 0);
  assert(tree->root->right == 0);

  printf("test search first node: 42...\n");
  x = binary_tree_search(tree, 42);
  assert(x->key == 42);
  assert(x->left == 0);
  assert(x->right == 0);

  printf("test insert node: 20...\n");
  binary_tree_insert(tree, 20);
  y = binary_tree_search(tree, 20);
  assert(y->key == 20);
  assert(y->left == 0);
  assert(y->right == 0);
  assert(x->left == y);

  printf("test insert several nodes...\n");
  binary_tree_insert(tree, 15);
  binary_tree_insert(tree, 17);
  binary_tree_insert(tree, 10);
  binary_tree_insert(tree, 30);
  binary_tree_insert(tree, 77);
  binary_tree_insert(tree, 100);
  binary_tree_insert(tree, 50);

  printf("test pre-order traversal:  ");
  int values[9];
  binary_tree_preorder(tree, values);
  for (int k=0; k<9; ++k)
    printf("%d ", values[k]);
  printf("\n");
  assert(values[0] == 42);
  assert(values[1] == 20);
  assert(values[2] == 15);
  assert(values[3] == 10);
  assert(values[4] == 17);
  assert(values[5] == 30);
  assert(values[6] == 77);
  assert(values[7] == 50);
  assert(values[8] == 100);

  printf("test post-order traversal: ");
  binary_tree_postorder(tree, values);
  for (int k=0; k<9; ++k)
    printf("%d ", values[k]);
  printf("\n");
  assert(values[0] == 10);
  assert(values[1] == 17);
  assert(values[2] == 15);
  assert(values[3] == 30);
  assert(values[4] == 20);
  assert(values[5] == 50);
  assert(values[6] == 100);
  assert(values[7] == 77);
  assert(values[8] == 42);

  printf("test breadth-first-search: ");
  binary_tree_BFS(tree, values);
  for (int k=0; k<9; ++k)
    printf("%d ", values[k]);
  printf("\n");
  assert(values[0] == 42);
  assert(values[1] == 20);
  assert(values[2] == 77);
  assert(values[3] == 15);
  assert(values[4] == 30);
  assert(values[5] == 50);
  assert(values[6] == 100);
  assert(values[7] == 10);
  assert(values[8] == 17);

  binary_tree_free(tree);
}

int main(int argc, char** argv)
{
  printf("\n===== Testing Trees (Of Various Sorts)\n");
  test_binary_tree();
  printf("\n===== Done\n");
  return 0;
}
