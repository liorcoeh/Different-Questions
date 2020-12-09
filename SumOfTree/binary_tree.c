
#include "binary_tree.h"

struct BSTNode
{
   int data;
   struct BSTNode* left;
   struct BSTNode* right;
};

struct BinarySearchTree
{
    Node* root;
};

static void BSTRecuSum(Node* node, int* sum);

static int BSTRecuInsert(Node* node, int data);
static void BSTRecuDestroy(Node* node);

static void PrintTreeRecu(Node* node, int level);

int BSTSum(BST* tree)
{
    int sum = 0;

    BSTRecuSum(tree->root, &sum);

    return (sum);
}

void BSTRecuSum(Node* node, int* sum)
{
    if (NULL == node)
    {
        return;
    }

    BSTRecuSum(node->left, sum);

    BSTRecuSum(node->right, sum);

    (*sum) += node->data;
}

BST* BSTCreate()
{
    BST* new_tree = (BST*)malloc(sizeof(BST));
    if (!new_tree)
    {
        return (NULL);
    }

    new_tree->root = NULL;

    return (new_tree);
}

void BSTDestroy(BST* tree)
{
    BSTRecuDestroy(tree->root);

    free(tree);
    tree = NULL;
}

void BSTRecuDestroy(Node* node)
{
    if (NULL == node)
    {
        return;
    }

    BSTRecuDestroy(node->left);
    BSTRecuDestroy(node->right);

    free(node);
    node = NULL;
}

Node* CreateNewNode(int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));

    if (!new_node)
    {
        return (NULL);
    }

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}

int BSTInsert(BST* tree, int data)
{
    if (NULL == tree->root)
    {
        Node* new_node = CreateNewNode(data);
        if (!new_node)
        {
            return (1); /* Failure */
        }

        tree->root = new_node;
        return (0); /* Success */
    }

    return (BSTRecuInsert(tree->root, data));
}

int BSTRecuInsert(Node* node, int data)
{
    Node* new_node = NULL;

    if (data < node->data)
    {
        if (NULL == node->left)
        {
            new_node = CreateNewNode(data);
            if (!new_node)
            {
                return (1); /* Failure */
            }

            node->left = new_node;
            return (0); /* Success */
        }

        return (BSTRecuInsert(node->left, data));
    }

    if (data > node->data)
    {
        if (NULL == node->right)
        {
            new_node = CreateNewNode(data);
            if (!new_node)
            {
                return (1); /* Failure */
            }

            node->right = new_node;
            return (0); /* Success */
        }

        return (BSTRecuInsert(node->right, data));
    }
}

void PrintTree(BST* tree)
{
    PrintTreeRecu(tree->root, 0);

    printf("\n\n");
}

static void PrintTreeRecu(Node* node, int level)
{
    int i = 0;
	
	if (NULL == node)
	{ 
		return; 
	}

	level += 7; 
  
	PrintTreeRecu(node->right, level); 
	printf("\n"); 
	
	for (i = 7; i < level; i++) 
	{
		printf(" ");
	} 
	
	printf("%d\n", node->data); 
	
	PrintTreeRecu(node->left, level); 
}