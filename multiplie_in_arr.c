/*
 * Given an array of ints, return an array that represents the multiplies of
 * of all the indexes without the the said index.
 * Example:
 * Arr is {1, 2, 3, 4};
 * NewArr is {24, 12, 8, 6};
 */

#include <stdio.h>

void MultipiedArray(size_t arr_a[], size_t arr_b[], size_t n);
void PrintArr(size_t arr[], size_t n);

int main()
{
    size_t arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t arr12[10] = {100};
    size_t arr2[] = {1, 2, 0, 4, 5, 6, 7, 8, 9, 10};
    size_t arr22[10] = {100};
    size_t arr3[] = {1, 2, 3, 0 ,5, 6, 0, 8, 9, 10};
    size_t arr32[10] = {100};
    size_t arr4[] = {1, 0, 3, 0, 5, 0, 7, 0, 9, 0};
    size_t arr42[10] = {100};


    PrintArr(arr1, 10);
    MultipiedArray(arr1, arr12, 10);
    PrintArr(arr12, 10);

    PrintArr(arr2, 10);
    MultipiedArray(arr2, arr22, 10);
    PrintArr(arr22, 10);

    PrintArr(arr3, 10);
    MultipiedArray(arr3, arr32, 10);
    PrintArr(arr32, 10);

    PrintArr(arr4, 10);
    MultipiedArray(arr4, arr42, 10);
    PrintArr(arr42, 10);

    return (0);
}


void MultipiedArray(size_t arr_a[], size_t arr_b[], size_t n)
{
    size_t i = 0;
    size_t zero_counter = 0;
    size_t zero_index = 0;
    size_t multi = 1;

    /* Getting the amount of zeros in the array:
     * If there are 2 or more zeros, the entire array will be zeros.
     * If there is one zero, the entire array will be zeros execpt the index
     * where the zero is.
     * If none is zero, than it's a multiply of the entire array devide by
     * the specifc index
     */
    for (i = 0; i < n; ++i)
    {
        if (0 == arr_a[i])
        {
            zero_index = i;
            ++zero_counter;
            ++i;
        }
        else
        {
            multi *= arr_a[i];
        }
        
        if (1 < zero_counter)
        {
            break;
        }
    }

    switch (zero_counter)
    {
        case (0):
            for (i = 0; i < n; ++i)
            {
                arr_b[i] = multi / arr_a[i];
            }
            break;

        case (1):
            for (i = 0; i < n; ++i)
            {
                arr_b[i] = 0;
            }
            arr_b[zero_index] = multi;
            break;

        default:
            for (i = 0; i < n; ++i)
            {
                arr_b[i] = 0;
            }
            break;
    }
}

void PrintArr(size_t arr[], size_t n)
{
    size_t i = 0;

    for (i = 0; i < n; ++i)
    {
        printf("%ld, ", arr[i]);
    }
    printf("\n\n");
}