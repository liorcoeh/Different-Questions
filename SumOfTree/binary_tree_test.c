
#include "binary_tree.h"

int main()
{
    int i = 0;
    int sum = 0;
    int random;
    BST* tree = BSTCreate();

    srand(time(NULL));

    for (i = 0; i < 10; ++i)
    {
        random = (rand() % 500 + 1);
        sum += random;
        BSTInsert(tree, random);
        printf("%d, ", random);
    }
    printf("\n\n");

    PrintTree(tree);

    printf("\n\nTree sum is: %d\n", BSTSum(tree));
    printf("Total sum is: %d\n", sum);

    BSTDestroy(tree);

    return (0);
}