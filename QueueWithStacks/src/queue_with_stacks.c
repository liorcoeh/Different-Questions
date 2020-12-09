
#include "../include/queue_with_stacks.h"

struct Queue
{
    int size;
    int capacity;
    stack_t *first;
    stack_t *second;
};

queue_t *QueueCreate(int capacity)
{
    queue_t *new_queue = (queue_t*)malloc(sizeof(queue_t));

    if (!new_queue)
    {
        return (NULL);
    }

    new_queue->size = 0;
    new_queue->capacity = capacity;

    new_queue->first = StackCreate(capacity);
    if (!new_queue->first)
    {
        free(new_queue);
        new_queue = NULL;

        return (NULL);
    }

    new_queue->second = StackCreate(capacity);
    if (!new_queue->second)
    {
        free(new_queue->first);
        new_queue->first = NULL;

        free(new_queue);
        new_queue = NULL;

        return (NULL);
    }

    return (new_queue);
}

void QueueDestroy(queue_t *queue)
{
    StackDestroy(queue->first);
    StackDestroy(queue->second);

    free(queue);
    queue = NULL;
}

int QueueEnqueue(queue_t *queue, int value)
{
    if (queue->capacity == QueueSize(queue))
    {
        printf("Queue is full - can't push\n");
        return (1); /* Failure */
    }

    StackPush(queue->first, value);
    ++queue->size;

    return (0); /* Success */
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

int QueueSize(queue_t *queue)
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