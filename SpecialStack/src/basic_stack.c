
#include <stdlib.h>

#include "../include/basic_stack.h"

struct BasicStack
{
    size_t index;
    size_t capacity;
    int* container;
};

bs_stack* BStackCreate(size_t new_capacity)
{
    bs_stack* new_stack = (bs_stack*)malloc(sizeof(bs_stack));
    if (!new_stack)
    {
        return (NULL);
    }

    new_stack->container = (int*)malloc(sizeof(int) * new_capacity);
    if (!new_stack->container)
    {
        free(new_stack);
        new_stack = NULL;
        return (NULL);
    }

    new_stack->index = 0;
    new_stack->capacity = new_capacity;

    return (new_stack);
}

void BStackDestroy(bs_stack* stack)
{
    free(stack->container);
    stack->container = NULL;

    free(stack);
    stack = NULL;
}

int BStackPush(bs_stack* stack, int data)
{
    if (BStackIsFull(stack))
    {
        return (1); /* Failure */
    }

    stack->container[stack->index] = data;
    ++(stack->index);

    return (0); /* Success */
}

int BStackPeek(bs_stack* stack)
{
    if (BStackIsEmpty(stack))
    {
        return (-1); /* Failure */
    }

    return (stack->container[stack->index - 1]);
}

void BStackPop(bs_stack* stack)
{
    if (BStackIsEmpty(stack))
    {
        return;
    }

    --(stack->index);
}

size_t BStackSize(bs_stack* stack)
{
    return (stack->index);
}

int BStackIsEmpty(bs_stack* stack)
{
    if (0 == stack->index)
    {
        return (1); /* True */
    }

    return (0); /* False */
}

int BStackIsFull(bs_stack* stack)
{
    if (stack->capacity == stack->index)
    {
        return (1); /* True */
    }

    return (0); /* False */
}