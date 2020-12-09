/*
 * Write a function that receives an array of integers (will not include the 
 * number 0), each number in the array appear twice except *two* that appear
 * only once.
 * Find these two numbers and return them.
 */


#include <stdio.h>
#include <stdlib.h>

#define SIZE (10)

void TwoNums(int arr[], int size, int *a, int *b);
int CompareFunc (const void *a, const void *b);

int main()
{
    int arr[SIZE] = {1, 2, 3, 4, 5, 1, 3, 4, 5, 6};
    int a = 0;
    int b = 0;
    TwoNums(arr, SIZE, &a, &b);

    printf("%d, %d\n", a, b);

    return (0);
}

void TwoNums(int arr[], int size, int *a, int *b) // Time complexity O(n)
{
    int i = 0;
    qsort (arr, size, sizeof(int), CompareFunc);

    while (i < size)
    {
        if (arr[i] == arr[i + 1])
        {
            i += 2;
        }
        else
        {
            if (*a == 0)
            {
                *a = arr[i];
            }
            else
            {
                *b = arr[i];
            }
            ++i;
        }
    }
}

int CompareFunc (const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

