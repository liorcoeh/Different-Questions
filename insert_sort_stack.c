/*
 * Write a function stack insert that keeps the contents of the stack
 * sorted (from lowest to highest) without using another stack
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct SortedStack
{
    size_t capacity;
    size_t index;
    int* container;
} Stack;

Stack* StackCreate(size_t new_capacity);
void StackDestroy(Stack* stack);

int StackInsert(Stack* stack, int data);

void StackPush(Stack* stack, int data);
void StackPop(Stack* stack);
int StackPeek(Stack* stack);

int StackIsEmpty(Stack* stack);

int main()
{
    Stack* stack = StackCreate(10);
    int i = 0;

    StackInsert(stack, 5);
    StackInsert(stack, 3);
    StackInsert(stack, 7);
    StackInsert(stack, 2);

    for (i = 0; i < 4; ++i)
    {
        printf("%d\n", StackPeek(stack));
        StackPop(stack);
    }

    StackDestroy(stack);

    return (0);
}

int StackInsert(Stack *stack, int data)
{
    int temp = 0;

    /* If the stack is empty or the new data is larger than the one at the top
     * just push into the stack
     */
    if (StackIsEmpty(stack) || data > StackPeek(stack))
    {
        StackPush(stack, data);
        return (0);
    }

    /* Else, holding the top in a temp variable and geting it out of the stack */
    temp = StackPeek(stack);
    StackPop(stack);

    /* Calling recursively to the StackInsertFunction */
    StackInsert(stack, data);

    /* Pushing back the value that was holded in temp */
    StackPush(stack, temp);
}

Stack* StackCreate(size_t new_capacity)
{
    Stack* new_stack = (Stack*)malloc(sizeof(Stack));

    if (!new_stack)
    {
        return (NULL);
    }

    new_stack->capacity = new_capacity;
    new_stack->index = 0;
    new_stack->container = (int*)malloc(sizeof(int) * new_capacity);
}

void StackDestroy(Stack* stack)
{
    free(stack->container);
    stack->container = NULL;

    free(stack);
    stack = NULL;
}

void StackPush(Stack* stack, int data)
{
    stack->container[stack->index] = data;
    ++(stack->index);
}

void StackPop(Stack* stack)
{
    if (StackIsEmpty(stack))
    {
        return;
    }

    --(stack->index);
}
int StackPeek(Stack* stack)
{
    if (StackIsEmpty(stack))
    {
        printf("Stack Is Empty\n");
        return (-1); /* Failure */
    }

    return (stack->container[stack->index - 1]);
}

int StackIsEmpty(Stack* stack)
{
    if (0 == stack->index)
    {
        return (1); /* Success */
    }

    return (0); /* Failure */
}