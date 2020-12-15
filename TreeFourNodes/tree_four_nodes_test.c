
#include <stdio.h>

#include "tree_four_nodes.h"

int main()
{
    Node* tree = TreeCreate(100);

    TreeInsert(tree, 1, 1, 100, 0);
    TreeInsert(tree, 10, 10, 100, 1);
    TreeInsert(tree, 20, 20, 100, 2);
    TreeInsert(tree, 30, 30, 100, 3);

    TreeInsert(tree, 2, 2, 1, 0);
    TreeInsert(tree, 3, 3, 1, 1);
    TreeInsert(tree, 4, 4, 1, 2);
    TreeInsert(tree, 5, 5, 1, 3);

    TreeInsert(tree, 11, 11, 10, 0);
    TreeInsert(tree, 12, 12, 10, 1);
    TreeInsert(tree, 13, 13, 10, 2);
    TreeInsert(tree, 14, 14, 10, 3);

    PrintTree(tree);

    TreeDestroy(tree);

    return (0);
}