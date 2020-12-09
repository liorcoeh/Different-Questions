#ifndef SPECIAL_STACK_H
#define SPECIAL_STACK_H

/*
 * Special Stack:
 * A stack that supposed to give the follow functions in O(1) time complexity:
 * GetMinValue.
 * GetMaxValue.
 * GetMedian.
 * GetSum.
 * GetAverage.
 */

#include "basic_stack.h"

typedef struct SpecialStack special_stack;

/*
 * SpecialStackCreate: Creates a new basic stack.
 * Returns a pointer to the new stack.
 * If failed, returns a NULL.
 * Time Complexity: O(1).
 */
special_stack* SpecialStackCreate(size_t new_capacity);

/*
 * SpecialStackDestroy: Destroys the stack and frees all it's allocated memory.
 * Time Complexity: O(1).
 */
void SpecialStackDestroy(special_stack* stack);

/*
 * SpecialStackGetMin: Will get the minimum value inside the stack.
 * Returns the minimum value inside the stack.
 * Time Complexity: O(1).
 */
int SpecialStackGetMin(special_stack* stack);

/*
 * SpecialStackGetMax: Will get the maximum value inside the stack.
 * Returns the maximum value inside the stack.
 * Time Complexity: O(1).
 */
int SpecialStackGetMax(special_stack* stack);

/*
 * SpecialStackGetMedian: Will get the median value inside the stack.
 * Returns the median value inside the stack.
 * Time Complexity: O(1).
 */
int SpecialStackGetMedian(special_stack* stack);

/*
 * SpecialStackGetSum: Will get the sum of all the elements inside the stack.
 * Returns the sum of all the elements inside the stack.
 * Time Complexity: O(1).
 */
int SpecialStackGetSum(special_stack* stack);

/*
 * SpecialStackGetAverage: Will get the average of all the elements inside the
 * stack.
 * Returns the sum of all the elements inside the stack.
 * Time Complexity: O(1).
 */
int SpecialStackGetAverage(special_stack* stack);

/*
 * SpecialStackPush: Pushes new data onto the stack.
 * Returns 0 if success, returns 1 if failed.
 * Time Complexity: O(1).
 */
int SpecialStackPush(special_stack* stack, int data);

/*
 * SpecialStackPeek: Gives the data on the top of the stack.
 * Returns the value of the element on the top of the stack.
 * Time Complexity: O(1).
 */
int SpecialStackPeek(special_stack* stack);

/*
 * SpecialStackPop: Removes the element at the top of the stack.
 * Time Complexity: O(1).
 */
void SpecialStackPop(special_stack* stack);

/*
 * SpecialStackSize: Gives the amount of elements inside of the stack.
 * Returns the amount of elements in the stack.
 * Time Complexity: O(1).
 */
size_t SpecialStackSize(special_stack* stack);

/*
 * SpecialStackIsEmpty: Checks if the stack has no elements in it.
 * Returns 1 (true) if the stack is empty, returns 0 (false) if not.
 * Time Complexity: O(1).
 */
int SpecialStackIsEmpty(special_stack* stack);

/*
 * SpecialStackIsFull: Checks if the stack has its capacity amount of elements.
 * Returns 1 (true) if the stack is full, returns 0 (false) if not.
 * Time Complexity: O(1).
 */
int SpecialStackIsFull(special_stack* stack);

#endif /* special_stack_H */