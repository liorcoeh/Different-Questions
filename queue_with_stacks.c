/*
 * Implement a queue with two stacks.
 * support Enqueue, Dequeue, size.
 */

#include <stdio.h>
#include <stdlib.h>

/* Declaring Stack and Queue structs and functions */
typedef struct Stack
{
    size_t top;
    size_t capacity;
    int *array;
} stack_t;

stack_t *StackCreate(size_t capacity);
void StackDestroy(stack_t *stack);
void StackPush(stack_t *stack, int value);
void StackPop(stack_t *stack);
int StackPeek(stack_t *stack);
int StackIsFull(stack_t *stack);
int StackIsEmpty(stack_t *stack);

typedef struct Queue
{
    size_t size;
    size_t capacity;
    stack_t *first;
    stack_t *second;
} queue_t;


queue_t *QueueCreate(size_t capacity);
void QueueDestroy(queue_t *queue);
void QueueEnqueue(queue_t *queue, int value);
void QueueDequeue(queue_t *queue);
size_t QueueSize(queue_t *queue);
int QueuePeek(queue_t *queue);

/*******************************************************************************
*******************************************************************************/

int main()
{
    double num = 17;
    int capacity = 20;
    int i = 0;

    system("clear");

    queue_t *main_queue = QueueCreate(capacity);

    printf("The queue size is(0): %ld\n", QueueSize(main_queue));

    for (i = 0; i < 25; ++i)
    {
        QueueEnqueue(main_queue, ((i + 1)* 2));
    }

    printf("The queue size now, is(20): %ld\n", QueueSize(main_queue));
    printf("\n");

    for (i = 0; i < 10; ++i)
    {
        printf("Value being poping out is(%d): %d\n", ((i + 1) * 2), QueuePeek(main_queue));
        QueueDequeue(main_queue);
    }
    
    printf("\n");
    printf("The queue size now, is(10): %ld\n", QueueSize(main_queue));
    printf("\n");

    QueueDestroy(main_queue);

    printf("\n\nThe square root of %f, is: %0.3f\n\n", num, Sqrt(num));

    return (0);
}

/*******************************************************************************
*******************************************************************************/

/* Definition of the Stack functions*/

stack_t *StackCreate(size_t capacity)
{
    stack_t *new_stack = (stack_t*)malloc(sizeof(stack_t));
    new_stack->top = -1;
    new_stack->capacity = capacity;
    new_stack->array = (int*)malloc(capacity * sizeof(int));
    return (new_stack);
}

void StackDestroy(stack_t *stack)
{
    free(stack->array);
    stack->array = NULL;

    free(stack);
    stack = NULL;
}

void StackPush(stack_t *stack, int value)
{
    if (StackIsFull(stack))
    {
        return;
    }
    ++stack->top;
    stack->array[stack->top] = value;
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

/* Definition of the Queue functions*/

queue_t *QueueCreate(size_t capacity)
{
    queue_t *new_queue = (queue_t*)malloc(sizeof(queue_t));
    new_queue->size = 0;
    new_queue->capacity = capacity;
    new_queue->first = StackCreate(capacity);
    new_queue->second = StackCreate(capacity);
}

void QueueDestroy(queue_t *queue)
{
    StackDestroy(queue->first);
    StackDestroy(queue->second);

    free(queue);
    queue = NULL;
}

void QueueEnqueue(queue_t *queue, int value)
{
    if (queue->capacity == QueueSize(queue))
    {
        printf("Queue is full - can't push\n");
        return;
    }

    StackPush(queue->first, value);
    ++queue->size;
}

void QueueDequeue(queue_t *queue)
{
    if (StackIsEmpty(queue->second))
    {
        while (!StackIsEmpty(queue->first))
        {
            StackPush(queue->second, StackPeek(queue->first));
            StackPop(queue->first);
        }
    }
    StackPop(queue->second);
    --queue->size;
}
size_t QueueSize(queue_t *queue)
{
    return (queue->size);
}

int QueuePeek(queue_t *queue)
{
    if (StackIsEmpty(queue->second))
    {
        while (!StackIsEmpty(queue->first))
        {
            StackPush(queue->second, StackPeek(queue->first));
            StackPop(queue->first);
        }
    }
    return (StackPeek(queue->second));
}

