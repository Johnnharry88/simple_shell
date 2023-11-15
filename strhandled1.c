#include "shell.h"

/**
 * xtrcat - function that concatenate two strings
 * @copy_to: char pointer the dest of the copied str
 * @copy_from: const char pointer the source of str
 * Return: concatenated string
 */
char *xtrcat(char *copy_to, const char *copy_from)
{
	unsigned int s, t;
	int x = 0;

	for (s = x; copy_to[s] != '\0'; s++)
		;

	t = s + x;
	s = x;
	for (s = x; copy_from[s] != '\0'; s++, t += 1)
	{
		copy_to[t] = copy_from[s];
	}
	copy_to[t] = '\0';
	return (copy_to);
}

/**
 * xtrcopy - function that copies the string pointed to by src.
 * @copy_to: Type char pointer the dest of the copied str
 * @copy_from: Type char pointer the source of str
 * Return: copied string.
 */
char *xtrcopy(char *copy_to, char *copy_from)
{
	int x = 0;
	int j;

	for (j = x; copy_from[j] != '\0'; j++)
	{
		copy_to[j + x] = copy_from[j];
	}
	copy_to[j] = '\0';

	return (copy_to);
}
/**
 * xtrcomp - Function that computes for equality of two strings.
 * @str_1: first string to be compared
 * @str_2: second string to be compared
 * Return: Always 0.
 */
int xtrcomp(char *str_1, char *str_2)
{
	unsigned int x, t = 2;

	x = (t - 2);
	while (str_1[x] && str_1[x] == str_2[x])
		x = x + 1;
	if (str_2[x] > str_1[x])
		return (-1);
	if (str_2[x] < str_1[x])
		return (1);
	return (t - 2);
}
/**
 * xtrchr - function that locates a character in a string,
 * @str: string to be searched
 * @z: character to be found.
 * Return: the pointer to the first occurrence of the character c.
 */
char *xtrchr(char *str, char z)
{
	unsigned int x = 0;
	char t = '\0';

	while (*(str + x) != t)
	{
		if (*(str + x) == z)
			return (str + x);
	x = x + 1;
	}
	return ('\0');
}
/**
 * xtrspn - function that gets length of a prefixed substring.
 * @str: initial segment.
 * @byt: accepted bytes.
 * Return: the number of accepted bytes.
 */
int xtrspn(char *str, char *byt)
{
	int x, y, z = 0, bool;

	for (x = z; *(str + x) != '\0'; x++)
	{
		bool = (z + 1);
		for (y = z; *(byt + y) != '\0'; y += 1)
		{
			if (*(str + x) == *(byt + y))
			{
				bool = z;
				break;
			}
		}
		if (bool == (z + 1))
			break;
	}
	return (x);
}
