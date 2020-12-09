
#include "../include/stack.h"

typedef struct Queue queue_t;

/*
 * QueueCreate: Creates a new queue with the given capacity.
 * Returns a pointer to the new queue. Will return NULL if failed to create.
 * Time Complexity: O(1).
 */
queue_t *QueueCreate(int capacity);

/*
 * QueueDestroy: Destroyes the queue and frees all its allocated memory.
 * Time Complexity: O(1).
 */
void QueueDestroy(queue_t *queue);

/*
 * QueueEnqueue: Pushes new element with the given value into the queue.
 * Returns 0 if successfull, 1 if failed.
 * Time Complexity: O(1).
 */
int QueueEnqueue(queue_t *queue, int value);

/*
 * QueueDequeue: Removes the element at begging of the queue.
 * Time Complexity: O(1).
 */
void QueueDequeue(queue_t *queue);

/*
 * QueueSize: Gives the amount of elements inside the queue.
 * Returns the amount of elements inside the queue.
 * Time Complexity: O(1).
 */
int QueueSize(queue_t *queue);

/*
 * QueuePeek: Gives the value of the element at begging of the queue.
 * Returns the value of the element at begging of the queue.
 * Time Complexity: O(1).
 */
int QueuePeek(queue_t *queue);