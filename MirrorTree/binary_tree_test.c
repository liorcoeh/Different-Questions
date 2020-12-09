
#include "binary_tree.h"

int main()
{
    Tree* tree = BTreeCreate();

    BTreeInsert(tree, 50);
    BTreeInsert(tree, 30);
    BTreeInsert(tree, 70);
    BTreeInsert(tree, 40);
    BTreeInsert(tree, 90);
    BTreeInsert(tree, 60);
    BTreeInsert(tree, 20);
    BTreeInsert(tree, 80);

    PrintTree(tree);

    BTreeMirror(tree);

    PrintTree(tree);

    BTreeDestroy(tree);

    return (0);
}