/*
 * Implement a function that recieves a double and returns it's
 * square root.
 */

#include <stdio.h>
#include <stdlib.h>

double Sqrt(double num);

int main()
{
    double num = 100;

    printf("The square root of %f is: %0.2f\n", num, Sqrt(num));

    return (0);
}

double Sqrt(double num)
{
    double difference = 0;
    double new_num = num;

    if (0 > num)
    {
        printf("There is no solution\n");
        return (-1);
    }
    else if (0 == num)
    {
        return (0);
    }

    while ((num > new_num * new_num + 0.001) || 
           (num < new_num * new_num - 0.001))
    {
        if ((new_num * new_num) > num)
        {
            new_num /= 2;
        }
        else if ((new_num * new_num) < num)
        {
            difference = new_num / 2;
            new_num += difference;
        }
    }

    return (new_num);
}