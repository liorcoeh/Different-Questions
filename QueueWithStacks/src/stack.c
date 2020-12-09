
#include "../include/stack.h"

struct Stack
{
    int top;
    int capacity;
    int *array;
};

stack_t *StackCreate(int capacity)
{
    stack_t *new_stack = (stack_t*)malloc(sizeof(stack_t));
    if (!new_stack)
    {
        return (NULL);
    }

    new_stack->top = -1;
    new_stack->capacity = capacity;

    new_stack->array = (int*)malloc(capacity * sizeof(int));
    if (!new_stack->array)
    {
        free(new_stack);
        new_stack = NULL;

        return (NULL);
    }

    return (new_stack);
}

void StackDestroy(stack_t *stack)
{
    free(stack->array);
    stack->array = NULL;

    free(stack);
    stack = NULL;
}

int StackPush(stack_t *stack, int value)
{
    if (StackIsFull(stack))
    {
        return (1); /* Failure */
    }
    
    ++stack->top;
    stack->array[stack->top] = value;

    return (0); /* Success */
}

void StackPop(stack_t *stack)
{
    if (StackIsEmpty(stack))
    {
        return;
    }
    --stack->top;
}

int StackPeek(stack_t *stack)
{
    if (StackIsEmpty(stack))
    {
        printf("Stack is empty\n");
        return (1);
    }
    return (stack->array[stack->top]);
}

int StackIsFull(stack_t *stack)
{
    return (stack->top == stack->capacity - 1);
}

int StackIsEmpty(stack_t *stack)
{
    return (-1 == stack->top);
}