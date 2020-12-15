/*
 * Givens a sorted int array and a number, implement a function that
 * returns two numbers in the array that add up to sum the number.
 * If there are no two numbers like that it will return two zeros.
 * Example:
 * {2,5,7,8,11,15} and the sum 16, the function should return 5, 11.
 */

#include <stdio.h>

#define SIZE (6)

int SumOfTwo(int arr[], int size, int sum, int *first, int *second);

int main()
{
    int arr[SIZE] = {2, 3, 7, 8, 11, 15};
    int first = 0;
    int second = 0;

    int sum_to_check = 26;

    SumOfTwo(arr, SIZE, sum_to_check, &first, &second);

    printf("first is: %d and second is: %d\n", first, second);

    return (0);
}

int SumOfTwo(int arr[], int size, int sum, int *first, int *second)
{
    int i = 0;
    int j = size - 1;

    while (i < j)
    {
        if (sum == arr[i] + arr[j])
        {
            *first = arr[i];
            *second = arr[j];
            return (0);
        }
        else if (sum > (arr[i] + arr[j]))
        {
            ++i;
        }
        else
        {
            --j;
        }
    }
    return (1);
}