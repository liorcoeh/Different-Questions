/*
 * Given an array of ints, with size N with all the number from 1 to N + 1,
 * except one number that is missing.
 * Find the missing number in two different ways
 */

#include <stdio.h>

int MissNumArr(int arr[], size_t n);

int MissNumArrXOR(int arr[], size_t n);

int main()
{
	int arr[9] = {1, 2, 3, 5, 6, 7, 8, 9, 10};

	printf("Missing number is(4): %d\n", MissNumArr(arr, 9));
	printf("Missing number is(4): %d\n", MissNumArrXOR(arr, 9));

	return (0);
}

int MissNumArr(int arr[], size_t n)
{
	size_t sum_array = 0;
	size_t sum_total = 0;
	size_t i = 0;

	for (i = 0; i < n; ++i)
	{
		sum_array += arr[i];
		sum_total += (i + 1);
	}

	sum_total += (i + 1);

	return (sum_total - sum_array);
}

int MissNumArrXOR(int arr[], size_t n)
{
	size_t i = 0;
	int missing_num = 0;
	int total_xor = 0;

	for (i = 0; i < n; ++i)
	{
		missing_num ^= arr[i];
		total_xor ^= (i + 1);
	}

	total_xor ^= (i + 1);

	missing_num ^= total_xor;

	return (missing_num);
}
