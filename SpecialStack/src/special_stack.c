
#include <stdlib.h>

#include "../include/special_stack.h"

struct SpecialStack
{
    int sum;
    bs_stack* stack;

    bs_stack* min_stack;
    bs_stack* max_stack;
};

special_stack* SpecialStackCreate(size_t new_capacity)
{
    special_stack* new_stack = (special_stack*)malloc(sizeof(special_stack));
    if (!new_stack)
    {
        return (NULL);
    }

    new_stack->sum = 0;

    new_stack->stack = BStackCreate(new_capacity);
    if (!new_stack->stack)
    {
        free(new_stack);
        new_stack = NULL;

        return (NULL);
    }

    new_stack->min_stack = BStackCreate(new_capacity);
    if (!new_stack->min_stack)
    {
        free(new_stack->stack);
        new_stack->stack = NULL;

        free(new_stack);
        new_stack = NULL;

        return (NULL);
    }

    new_stack->max_stack = BStackCreate(new_capacity);
    if (!new_stack->max_stack)
    {
        free(new_stack->min_stack);
        new_stack->min_stack = NULL;

        free(new_stack->stack);
        new_stack->stack = NULL;

        free(new_stack);
        new_stack = NULL;

        return (NULL);
    }

    return (new_stack);
}

void SpecialStackDestroy(special_stack* stack)
{
    BStackDestroy(stack->max_stack);

    BStackDestroy(stack->min_stack);

    BStackDestroy(stack->stack);

    free(stack);
    stack = NULL;
}

int SpecialStackGetMin(special_stack* stack)
{
    if (BStackIsEmpty(stack->min_stack))
    {
        return (-1); /* Failure */
    }

    return (BStackPeek(stack->min_stack));
}

int SpecialStackGetMax(special_stack* stack)
{
    if (BStackIsEmpty(stack->max_stack))
    {
        return (-1); /* Failure */
    }

    return (BStackPeek(stack->max_stack));
}

int SpecialStackGetMedian(special_stack* stack)
{
    if (SpecialStackIsEmpty(stack))
    {
        return (0);
    }

    return ((BStackPeek(stack->min_stack) + BStackPeek(stack->max_stack)) / 2);
}

int SpecialStackGetSum(special_stack* stack)
{
    return (stack->sum);
}

int SpecialStackGetAverage(special_stack* stack)
{
    if (SpecialStackIsEmpty(stack))
    {
        return (0);
    }

    return (stack->sum / BStackSize(stack->stack));
}

int SpecialStackPush(special_stack* stack, int data)
{
    if (SpecialStackIsFull(stack))
    {
        return (-1); /* Failure */
    }

    BStackPush(stack->stack, data);
    stack->sum += data;

    if (BStackIsEmpty(stack->min_stack) || data <= BStackPeek(stack->min_stack))
    {
        BStackPush(stack->min_stack, data);
    }

    if (BStackIsEmpty(stack->max_stack) || data >= BStackPeek(stack->max_stack))
    {
        BStackPush(stack->max_stack, data);
    }

    return (0); /* Success */
}

int SpecialStackPeek(special_stack* stack)
{
    if (SpecialStackIsEmpty(stack))
    {
        return (-1); /* Failure */
    }

    return (BStackPeek(stack->stack));
}

void SpecialStackPop(special_stack* stack)
{
    if (SpecialStackIsEmpty(stack))
    {
        return;
    }

    int temp = BStackPeek(stack->stack);

    if (temp == BStackPeek(stack->min_stack))
    {
        BStackPop(stack->min_stack);
    }

    if (temp == BStackPeek(stack->max_stack))
    {
        BStackPop(stack->max_stack);
    }

    BStackPop(stack->stack);
    stack->sum -= temp;
}

size_t SpecialStackSize(special_stack* stack)
{
    return (BStackSize(stack->stack));
}

int SpecialStackIsEmpty(special_stack* stack)
{
    return (BStackIsEmpty(stack->stack));
}

int SpecialStackIsFull(special_stack* stack)
{
    return (BStackIsFull(stack->stack));
}