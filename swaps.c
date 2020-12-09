/*
 * Implement three different functions to swap ints.
 */

#include <stdio.h>

void SwapIntsA(int *a, int *b);
void SwapIntsB(int *a, int *b);
void SwapIntsC(int *a, int *b);

int main()
{
    int a = 5;
    int b = 3;

    printf("\nBefore Swap ==> a = %d, b = %d\n\n", a, b);

    SwapIntsA(&a, &b);
    printf("After first Swap ==> a = %d, b = %d\n\n", a, b);

    SwapIntsB(&a, &b);
    printf("After second Swap ==> a = %d, b = %d\n\n", a, b);

    SwapIntsC(&a, &b);
    printf("After third Swap ==> a = %d, b = %d\n\n", a, b);

	return (0);
}


void SwapIntsA(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SwapIntsB(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void SwapIntsC(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}