/*
 * Implement a function that returns the sum of all the datas inside
 * a BST
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct BSTNode Node;
typedef struct BinarySearchTree BST;

int BSTSum(BST* tree);


BST* BSTCreate();

void BSTDestroy(BST* tree);

Node* CreateNewNode(int data);

int BSTInsert(BST* tree, int data);

/*
 * PrintTree: Prints the tree, 90 degrees to the left.
 * Time Complexity: O(n).
 */
void PrintTree(BST* tree);