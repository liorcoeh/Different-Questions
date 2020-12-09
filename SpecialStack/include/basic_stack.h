#ifndef BASIC_STACK_H
#define BASIC_STACK_H

#include <stdio.h>

typedef struct BasicStack bs_stack;

/*
 * BStackCreate: Creates a new basic stack.
 * Returns a pointer to the new stack.
 * If failed, returns a NULL.
 * Time Complexity: O(1).
 */
bs_stack* BStackCreate(size_t new_capacity);

/*
 * BStackDestroy: Destroys the stack and frees all it's allocated memory.
 * Time Complexity: O(1).
 */
void BStackDestroy(bs_stack* stack);

/*
 * BStackPush: Pushes new data onto the stack.
 * Returns 0 if success, returns 1 if failed.
 * Time Complexity: O(1).
 */
int BStackPush(bs_stack* stack, int data);

/*
 * BStackPeek: Gives the data on the top of the stack.
 * Returns the value of the element on the top of the stack.
 * Time Complexity: O(1).
 */
int BStackPeek(bs_stack* stack);

/*
 * BStackPop: Removes the element at the top of the stack.
 * Time Complexity: O(1).
 */
void BStackPop(bs_stack* stack);

/*
 * BStackSize: Gives the amount of elements inside of the stack.
 * Returns the amount of elements in the stack.
 * Time Complexity: O(1).
 */
size_t BStackSize(bs_stack* stack);

/*
 * BStackIsEmpty: Checks if the stack has no elements in it.
 * Returns 1 (true) if the stack is empty, returns 0 (false) if not.
 * Time Complexity: O(1).
 */
int BStackIsEmpty(bs_stack* stack);

/*
 * BStackIsFull: Checks if the stack has its capacity amount of elements.
 * Returns 1 (true) if the stack is full, returns 0 (false) if not.
 * Time Complexity: O(1).
 */
int BStackIsFull(bs_stack* stack);

#endif /* BASICK_STACK_H */