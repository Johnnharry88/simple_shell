#include "shell.h"

/**
 * str_inverse - function that reverses a string.
 * @str: input string to be reversed
 * Return: void.
 */
void str_inverse(char *str)
{
	int itr = 0, a, b, c = 0, s = 1;
	char *str1, ram, h = '\0';

	while (itr >= c)
	{
		if (str[itr] == h)
			break;
		itr = itr + 1;
	}
	str1 = str;

	for (a = c; a < (itr - s); a++)
	{
		for (b = a + s; b > c; b--)
		{
			ram = *(str1 + b);
			*(str1 + b) = *(str1 + (b - s));
			*(str1 + (b - s)) = ram;
		}
	}
}
