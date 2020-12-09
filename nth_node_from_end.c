/*
 * Implement a function that returns the Nth node from the end of a
 * SINGLY linked list.
 * Doing it in only one run over the entire list, no more than one time.
 * The number given will be smaller than the list size.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct SLLNode
{
    int data;
    struct SLLNode* next;
} Node;

Node* NthNodeFromEnd(Node* head, size_t num);

Node* SLLCreate(int data);
void SLLDestroy(Node* head);

Node* CreateNewNode(int data);

/* Will insert a node at the end of the list, as a last node */
/* Will return a pointer to the new node that was insertead  */
Node* SLLInsert(Node* head, int data);

void PrintList(Node* head);

int main()
{
    int i = 0;
    int num = 4;
    Node* list = SLLCreate(1);
    Node* nth = NULL;

    for (i = 2; i < 11; ++i)
    {
        SLLInsert(list, i);
    }

    PrintList(list);

    nth = NthNodeFromEnd(list, num);

    printf("%d\n", nth->data);

    SLLDestroy(list);

    return (0);
}

Node* NthNodeFromEnd(Node* list, size_t num)
{
    Node* front_iter = list;
    Node* back_iter = list;

    while (num)
    {
        front_iter = front_iter->next;
        --num;
    }

    while (NULL != front_iter)
    {
        front_iter = front_iter->next;
        back_iter = back_iter->next;
    }

    return (back_iter);
}

Node* SLLCreate(int data)
{
    Node* new_list = (Node*)malloc(sizeof(Node));

    if (!new_list)
    {
        return (NULL);
    }

    new_list->data = data;
    new_list->next = NULL;

    return (new_list);
}

void SLLDestroy(Node* head)
{
    if (NULL == head)
    {
        return;
    }

    SLLDestroy(head->next);

    free(head);
    head = NULL;
}

Node* CreateNewNode(int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));

    if (!new_node)
    {
        return (NULL);
    }

    new_node->data = data;
    new_node->next = NULL;

    return (new_node);
}

/* Will insert a node at the end of the list, as a last node */
Node* SLLInsert(Node* head, int data)
{
    Node* new_node = NULL;

    if (NULL == head->next)
    {
        new_node = CreateNewNode(data);

        if (!new_node)
        {
            return (NULL);
        }

        head->next = new_node;
        return (new_node);
    }

    return (SLLInsert(head->next, data));
}

void PrintList(Node* head)
{
    if (NULL == head)
    {
        printf("NULL\n");
        return;
    }

    printf("%d->",head->data);
    PrintList(head->next);
}