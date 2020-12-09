
#include <stdlib.h>
#include <time.h>

#include "../include/special_stack.h"

#define SIZE (20)

void PrintArr(int arr[], int size);
void SortArr(int arr[], int size);
int ArrSum(int arr[], int size);
int ArrAve(int arr[], int size);
void Swap(int *a, int *b);

int main()
{
    int i = 0;
    int random = 0;
    int arr_start[SIZE] = {0};
    int arr_end[SIZE / 2] = {0};
    special_stack* stack = SpecialStackCreate(20);

    printf("The size is: %ld\n", SpecialStackSize(stack));
    printf("Is Empty: %d\n", SpecialStackIsEmpty(stack));
    printf("Is Full: %d\n\n", SpecialStackIsFull(stack));

    srand(time(NULL));

    for (i = 0; i < SIZE; ++i)
    {
        random = (rand() % 200) + 1;
        /* random = 10; */
        SpecialStackPush(stack, random);
        arr_start[i] = random;
    }

    for (i = 0; i < SIZE / 2; ++i)
    {
        arr_end[i] = arr_start[i];
    }

    PrintArr(arr_start, SIZE);
    SortArr(arr_start, SIZE);
    PrintArr(arr_start, SIZE);

    SortArr(arr_end, SIZE / 2);

    printf("The min in stack is: %d\n", SpecialStackGetMin(stack));
    printf("The min in arr_start is: %d\n\n", arr_start[0]);

    printf("The max int stack is: %d\n", SpecialStackGetMax(stack));
    printf("The max in arr_start is: %d\n\n", arr_start[SIZE - 1]);

    printf("The Median in stack is: %d\n", SpecialStackGetMedian(stack));
    printf("The Median in arr_start is: %d\n\n", (arr_start[0] + arr_start[SIZE - 1]) / 2);

    printf("The Sum in stack is: %d\n", SpecialStackGetSum(stack));
    printf("The Sum of arr_start is: %d\n\n", ArrSum(arr_start, SIZE));

    printf("The Average in stack is: %d\n", SpecialStackGetAverage(stack));
    printf("The Average of arr_start is: %d\n\n", ArrAve(arr_start, SIZE));

    for (i = 0; i < SIZE / 2; ++i)
    {
        printf("%d, ", SpecialStackPeek(stack));
        SpecialStackPop(stack);
    }
    printf("\n\n");

    printf("The min in stack is: %d\n", SpecialStackGetMin(stack));
    printf("The min in arr_end is: %d\n\n", arr_end[0]);

    printf("The max int stack is: %d\n", SpecialStackGetMax(stack));
    printf("The max in arr_end is: %d\n\n", arr_end[(SIZE / 2) - 1]);

    printf("The Median in stack is: %d\n", SpecialStackGetMedian(stack));
    printf("The Median in arr_end is: %d\n\n", (arr_end[0] + arr_end[(SIZE / 2) - 1]) / 2);

    printf("The Sum in stack is: %d\n", SpecialStackGetSum(stack));
    printf("The Sum of arr_end is: %d\n\n", ArrSum(arr_end, SIZE / 2));

    printf("The Average in stack is: %d\n", SpecialStackGetAverage(stack));
    printf("The Average of arr_end is: %d\n\n", ArrAve(arr_end, SIZE / 2));

    SpecialStackDestroy(stack);

    return (0);
}

void PrintArr(int arr[], int size)
{
    int i = 0;
    for (i = 0; i < size - 1; ++i)
    {
        printf("%d, ", arr[i]);
    }
    printf("%d\n\n", arr[i]);
}

void SortArr(int arr[], int size)
{
    int i = 1;
    int j = i;

    while (i < size)
    {
        if (arr[i] < arr[i - 1])
        {
            while ((arr[j] < arr[j - 1]) && j > 0)
            {
                Swap(&arr[j], &arr[j - 1]);
                --j;
            }
        }

        ++i;
        j = i;
    }
}

int ArrSum(int arr[], int size)
{
    int i = 0;
    int sum = 0;

    for (i = 0; i < size; ++i)
    {
        sum += arr[i];
    }

    return (sum);
}

int ArrAve(int arr[], int size)
{
    int sum = ArrSum(arr, size);

    return (sum / size);
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}