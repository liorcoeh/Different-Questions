/*
 * Implement the following functions:
 * FlipNumDig(int num) - Flips the order of digits in an int.
 * MirrorBits(char byte) - Mirrors the bits inside a byte.
 * FlipBit(int val, unsigned int n) - Flip one bit in an int (val) at a
 * certain position (n).
 * NumOfSetBits(char byte) - Return the number of set bits in a byte.
 * RotateLeft(char byte, unsigned int nbits) - Rotate the bits in a byte, by
 * "nbits" amount.
 * SwapPointers(int **a, int **b) - Swap two pointers.
 * String Functions (strlen, strcmp, strcpy, strncpy, strcat).
 * GetNFibonacci(unsigned int n) - Get the fibonacci value of index n.
 * IntToString(char *dest, int num) - Change int "num" into a string.
 * MultiByEight(int num) - Multiply num by 8, using bitwise operations.
 * Implement three ways to swap between two ints.
 */

#include <stdio.h>
#include <stdlib.h>  /* system() */

/* Question #1 */
int FlipNumDig(int num);

/* Question #4 */
char MirrorBits(char byte);

/* Question #5 */
int FlipBit(int val, unsigned int n);

/* Question #6 */
int NumOfSetBits(char byte);

/* Question #8 */
char RotateLeft(char byte, unsigned int nbits);

/* Question #10 */
void SwapPointers(int **a, int **b);

/* Question #11 */
size_t Strlen(const char *str);
int Strcmp(const char *str1, const char *str2);
char *Strcpy(char *dest, const char *src);
char *Strncpy(char *dest, const char *src, size_t n);
char *Strcat(char *dest, const char *src);

/* Question #12 */
unsigned long GetNFibonacci(unsigned int n);

/* Queston #13 */
char *IntToString(char *dest, int num);

/* Question #14 */
int MultiByEight(int num);

/* Question #15 */
void SwapIntsA(int *a, int *b);
void SwapIntsB(int *a, int *b);
void SwapIntsC(int *a, int *b);

/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

int main()
{
    system ("clear");

    int num = 1234;
    printf("\nnum before: %d, num after: %d\n", num, FlipNumDig(num));

    char byte = 8;
    printf("\n%d\n", MirrorBits(byte));

    int val = 1;
    printf("\nval before bit flip: %d, after flip 4th bit: %d\n", val, FlipBit(val, 4));
    
    printf("\nnumber of on bite in 10 are(2): %d\n", NumOfSetBits(val));

    char new_byte = 10;
    printf("\nBefore rotate: %d, after rotate 6(-126): %d\n", new_byte, RotateLeft(new_byte, 6));

    int a = 5;
    int b = 10;
    int *p1 = &a;
    int *p2 = &b;
    printf("\nbefore swap *p1 = %d and *p2 = %d\n", *p1, *p2);
    SwapPointers(&p1, &p2);
    printf("After swap, *p1 = (10) %d and *p2 = (5) %d\n", *p1, *p2);

    char str1[] = "hello";
    char str2[] = "helLo";
    char str3[] = "OLLEH";
    char str4[] = "Lior Cohen";

    printf("\nThe length of str1, str2 and str4 is: %ld, %ld and %ld\n", Strlen(str1), Strlen(str2), Strlen(str4));
    printf("str1 is equal to str1: %d\n", Strcmp(str1, str1));
    printf("str1 is not as str2: %d\n", Strcmp(str1, str2));
    Strcpy(str3, str1);
    printf("putting str1 in str3 gives(hello): %s\n", str3);
    Strncpy(str4, str1, 8);
    printf("putting str1 in str4 with n characters gets(hello): %s\n", str4);
    Strcat(str4, str1);
    printf("putting str1 at the end of str4 gives(hellohello): %s\n", str4);

    printf("\nThe 6 element in Fibonacci is (8): %ld\n", GetNFibonacci(6));

    char buffer[256] = {0};
    num = 15;
    IntToString(buffer, num);
    printf("\nNow in the buffer(15): %s\n", buffer);

    num = 3;
    printf("\nBefore is: %d, after multiply by 8, is: %d\n", num, MultiByEight(num));

    a = 5;
    b = 10;
    printf("Before swap a = %d, and b = %d\n", a, b);
    SwapIntsA(&a, &b);
    printf("After first swap a = %d, and b = %d\n", a, b);
    SwapIntsB(&a, &b);
    printf("After second swap a = %d, and b = %d\n", a, b);
    SwapIntsC(&a, &b);
    printf("After third swap a = %d, and b = %d\n", a, b);


    return (0);
}

/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

void SwapIntsA(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SwapIntsB(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void SwapIntsC(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}


int MultiByEight(int num)
{
    return (num << 3);
}

char *IntToString(char *dest, int num)
{
    sprintf(dest, "%d", num);

    return (dest);
}

unsigned long GetNFibonacci(unsigned int n)
{
    if (n == 0)
    {
        return (0);
    }

    if (n == 1)
    {
        return (1);
    }

    return (GetNFibonacci(n - 1) + GetNFibonacci(n - 2));
}


size_t Strlen(const char *str)
{
    char *n_str = (char *)str;
    size_t length = 0;
    while (*n_str)
    {
        ++n_str;
        ++length;
    }

    return (length);
}

int Strcmp(const char *str1, const char *str2)
{
    char *n_str1 = (char *)str1;
    char *n_str2 = (char *)str2;

    while (*n_str1 || *n_str2)
    {
        if (*n_str1 == *n_str2)
        {
            ++n_str1;
            ++n_str2;
        }
        else
        {
            return (*n_str1 - *n_str2);
        }
    }
    return (0);
}

char *Strcpy(char *dest, const char *src)
{
    char *n_src = (char *) src;
    int counter = Strlen(src);

    while (*n_src)
    {
        *dest = *n_src;
        ++dest;
        ++n_src;
    }
    *dest = '\0';
    dest -= counter;
    return (dest);
}

char *Strncpy(char *dest, const char *src, size_t n)
{
    int m = n;
    char *n_src = (char *) src;

    if (n <= Strlen(src))
    {
        while (m)
        {
            *dest = *n_src;
            ++dest;
            ++n_src;
            --m;
        }
        *dest = '\0';
        dest -= n;
        return (dest);
    }
    else
    {
        while (*n_src)
        {
            *dest = *n_src;
            ++dest;
            ++n_src;
            --m;
        }

        while (m)
        {
            *dest = '\0';
            ++dest;
            --m;
        }
        *dest = '\0';
        dest -= n;
        return (dest);
    }
}

char *Strcat(char *dest, const char *src)
{
    char *n_src = (char *) src;
    int length = Strlen(dest);

    dest += length;
    while (*n_src)
    {
        *dest = *n_src;
        ++dest;
        ++n_src;
        ++length;
    }

    *dest = '\0';
    dest -= (length + 1);
    return (dest);
}



void SwapPointers(int **a, int **b)
{
   int temp = **a;
   **a = **b;
   **b = temp;
}

char RotateLeft(char byte, unsigned int nbits)
{
   nbits = nbits % 8;

   return ((byte << nbits) | (byte >> (8 - nbits)));
}

int NumOfSetBits(char byte)
{
    int counter = 0;
    while (byte)
    {
        byte &= (byte - 1);
        ++counter;
    }

    return (counter);
}

int FlipBit(int val, unsigned int n)
{
    int mask = (1 << n);

    return (val ^ mask);
}

char MirrorBits(char byte)
{
    int counter = 7;
    char mirror = byte;
    byte = byte >> 1;

    while (byte)
    {
        mirror = mirror << 1;
        mirror |= (byte & 1);
        byte = byte >> 1;
        --counter;
    }

    mirror = mirror << counter;
    return (mirror);
}

int FlipNumDig(int num)
{
    int result = 0;

    while (num)
    {
        result *= 10;
        result += (num % 10);
        num /= 10;
    }

    return (result);
}

