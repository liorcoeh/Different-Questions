/*
 * Get Fibonacci number in O(1) (time and space)
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Fibonacci(int n);

int main()
{
    system("clear");

    int n = 8;

    printf("\n\nFiboncci in the %d index is: %d\n\n\n", n, Fibonacci(n));

    return (0);
}

int Fibonacci(int n)
{
    return ((pow(((1 + sqrt(5)) / 2), n) - pow(((1 - sqrt(5)) / 2), n)) / sqrt(5));
}