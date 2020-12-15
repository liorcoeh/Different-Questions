#ifndef TREE_FOUR_NODES_H
#define TREE_FOUR_NODES_H

typedef struct TREE_NODE Node;

Node* TreeCreate(int key);
void TreeDestroy(Node *root);

Node* CreateNewNode(int key, int data);

Node* TreeFind(Node* root, int key);

int TreeInsert(Node* root, int new_key, int new_data, int where_key, int direction);

void PrintTree(Node* root);

int GetKey(Node* node);
int GetData(Node* node);

int GetLeftData(Node* node);

#endif /* TREE_FOUR_NODES_H */