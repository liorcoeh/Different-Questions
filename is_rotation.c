/*
 * Given two strings, return if one string is a rotation of the other.
 */

#include <stdio.h>
#include <string.h>

int IsRotate(const char *str1, const char *str2);

int main()
{
	char s1[] = "12345";
	char s2[] = "45123";
	char s3[] = "54123";

	printf("s2 is a rotation of s1 (1): %d\n", IsRotate(s1, s2));

	printf("s3 is not a rotation of s1 (0): %d\n", IsRotate(s1, s3));
	
	return (0);

}

int IsRotate(const char *str1, const char *str2)
{
	int i = 0;
	int n = 0;
	int count = 0;
	int length = strlen(str1);
	
	if (length != strlen(str2))
	{
		return (0);
	}
	
	for (i = 0; i < length; ++i)
	{
		if (count == length)
		{
			return (0);
		}
		else if (str2[i] != str1[0])
		{
			++count;
		}
		else
		{
			n = i;
		}
	}
	
	for (i = 0; i < length; ++i)
	{
		if (n == length)
		{
			n = 0;
		}
		
		if (str2[n] == str1[i])
		{
			++n;
		}
		else if (str2[n] != str1[i])
		{
			return (0);
		}
		
		if (i == length - 1)
		{
			return (1);
		}
	}
}
	
