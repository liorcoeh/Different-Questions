
#include <stdlib.h>

#include "binary_tree.h"

struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
};

struct BinaryTree
{
    Node* root;
};

static void BTreeRecuMirror(Node* node);
static void SwapNodes(Node* node);

static void BTreeRecuDestroy(Node* node);
static int BTreeRecuInsert(Node* node, int data);
static void PrintTreeRecu(Node* node, int level);

Tree* BTreeCreate()
{
    Tree* new_tree = (Tree*)malloc(sizeof(Tree));

    if (!new_tree)
    {
        return (NULL);
    }

    new_tree->root = NULL;

    return (new_tree);
}

void BTreeDestroy(Tree* tree)
{
    BTreeRecuDestroy(tree->root);

    free(tree);
    tree = NULL;
}

static void BTreeRecuDestroy(Node* node)
{
    if (NULL == node)
    {
        return;
    }

    BTreeRecuDestroy(node->left);
    BTreeRecuDestroy(node->right);

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

int BTreeInsert(Tree* tree, int data)
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

    return (BTreeRecuInsert(tree->root, data));
}

static int BTreeRecuInsert(Node* node, int data)
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
        return (BTreeRecuInsert(node->left, data));
    }
    else if (data > node->data)
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
        return (BTreeRecuInsert(node->right, data));
    }
}

void BTreeMirror(Tree* tree)
{
    if (NULL == tree->root)
    {
        return;
    }

    BTreeRecuMirror(tree->root);
}

static void BTreeRecuMirror(Node* node)
{
    if (NULL == node)
    {
        return;
    }

    BTreeRecuMirror(node->left);
    BTreeRecuMirror(node->right);

    SwapNodes(node);
}

static void SwapNodes(Node* node)
{
    Node* temp = node->left;
    node->left = node->right;
    node->right = temp;
}

void PrintTree(Tree* tree)
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