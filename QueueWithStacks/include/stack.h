#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack stack_t;

/*
 * StackCreate: Creates a new stack with the given capacity.
 * Returns a pointer to the new stack. Will return NULL if failed to create.
 * Time Complexity: O(1).
 */
stack_t *StackCreate(int capacity);

/*
 * StackDestroy: Destroyes the stack and frees all its allocated memory.
 * Time Complexity: O(1).
 */
void StackDestroy(stack_t *stack);

/*
 * StackPush: Pushes new element with the given value on top of the stack.
 * Returns 0 if successfull, 1 if failed.
 * Time Complexity: O(1).
 */
int StackPush(stack_t *stack, int value);

/*
 * StackPop: Removes the element at the top of the stack.
 * Time Complexity: O(1).
 */
void StackPop(stack_t *stack);

/*
 * StackPeek: Gives the value of the element at the top of the stack.
 * Returns the value of the element at the top of the stack.
 * Time Complexity: O(1).
 */
int StackPeek(stack_t *stack);

/*
 * StackIsFull: Checks if the stack is full.
 * Returns 1 if it is full, 0 if it's not.
 * Time Complexity: O(1).
 */
int StackIsFull(stack_t *stack);

/*
 * StackIsEmpty: Checks if the stack is empty.
 * Returns 1 if it is empty, 0 if it's not.
 * Time Complexity: O(1).
 */
int StackIsEmpty(stack_t *stack);

#endif /* STACK_H */