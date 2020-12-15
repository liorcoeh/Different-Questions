/*
 * Given an array between two ints and a random number btween those
 * two ints, find the nubmer using binary search.
 */

#include <stdio.h>

#define LOW (150)
#define HIGH (176)

int Attempts(int arr[], int size, int num);

int main()
{
    int arr[26] = {0};
    int i = 0;

    for (i = 0; i < 26; ++i)
    {
        arr[i] = i + 150;
    }

    Attempts(arr, 26, 170);

    return (0);
}

int Attempts(int arr[], int size, int num)
{
    int guess = 0;
    int half = 0;
    int to_chose = 0;
    int a = arr[0];
    int b = arr[size - 1];
    int attempts = 0;

    while (guess != num)
    {
        printf("Enter a number between %d and %d\n", a, b);
        half = (b - a) / 2;
        to_chose = a + half;
        printf("The best to chose is %d\n", to_chose);

        scanf("%d", &guess);

        if (guess == num)
        {
            printf("The right number\n");
        }
        else if (guess < num)
        {
            printf("Number is smaller\n");
            a = guess + 1;
        }
        else
        {
            printf("Nubmer is bigger\n");
            b = guess - 1;
        }
        
        ++attempts;
    }

    return (attempts);
}