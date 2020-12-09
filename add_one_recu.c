/*
 * Add 1 to a num using recursive, one parameter only and no + / -
 */

#include <stdio.h>
#include <stdlib.h>

int AddOne(int num);

int main()
{
    int num = 1;

    system("clear");

    printf("%d\n", AddOne(num));
    return (0);
}

int AddOne(int num)
{
    int new_num = 0;

    if (0 == (num & 1))
    {
        return (num ^ 1);
    }
    
    new_num = AddOne(num >> 1);

    return (new_num << 1);
}