/*
 * Implement a function that will mirror a binary tree/
 */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>

typedef struct BinaryTreeNode Node;
typedef struct BinaryTree Tree;

/*
 * BTreeMirror: Mirrors a  binary tree.
 * Time Complexity: O(n).
 */
void BTreeMirror(Tree* tree);

/*
 * BTreeCreate: Creates a new binary tree.
 * Returns a pointer to the new tree. Will return NULL if failed to create.
 * Time Complexity: O(1).
 */
Tree* BTreeCreate();

/*
 * BTreeDestroy: Destroyes the binary tree and frees all its allocated memory.
 * Time Complexity: O(n).
 */
void BTreeDestroy(Tree* tree);

/*
 * CreateNewNode: Creates a new binary tree node.
 * Returns a pointer to the new node. Will return NULL if failed to create.
 * Time Complexity: O(1).
 */
Node* CreateNewNode(int data);

/*
 * BTreeInsert: Inserts a new node with the requasted data into the right place.
 * Returns 0 if it was successful, returns 1 if it failed.
 * Time Complexity: O(log(n)).
 */
int BTreeInsert(Tree* tree, int data);

/*
 * PrintTree: Prints the tree, 90 degrees to the left.
 * Time Complexity: O(n).
 */
void PrintTree(Tree* tree);

#endif /* BINARY_TREE_H */