#include "shell.h"

/**
 * dupstring- function that duplicates a str in the heap memory.
 * @string: Type char pointer to string to be duplicated
 * Return: duplicated str
 */
char *dupstring(const char *string)
{
	char *tx;
	unsigned int p;
	int s = 1;

	p = xtrlent(string);
	tx = malloc(sizeof(char) * (p + s));
	if (tx == NULL)
		return (NULL);
	copy_memo(tx, string, p + s);
	return (tx);
}

/**
 * xtrlent - function that returns the lenght of a string.
 * @str: pointer to string to be counted
 * Return: Always 0.
 */
int xtrlent(const char *str)
{
	unsigned int x, a = 0;
	char hold = '\0';

	for (x = a; str[x + a] != hold; x++)
		;
	return (a + x);
}

/**
 * characomp - function that compare character of strings
 * @string: input string to be worked on.
 * @del: delimiter pointer
 * Return: 1 if found else return  0.
 */
int characomp(char string[], const char *del)
{
	unsigned int x, y, z, s = 0;

	for (x = s, y = s; string[x]; x++)
	{
		for (y = s; del[y]; y++)
		{
			if (string[x] == del[y])
			{
				z = z + 1;
				break;
			}
		}
	}
	if (x == z)
		return (s + 1);
	return (s);
}

/**
 * tokxtr - function that splits a string by using delimiter.
 * @str: input string to be splited
 * @d: delimiter.
 * Return: splited splited
 */
char *tokxtr(char str[], const char *d)
{
	static char *s, *str_1;
	char *str_2;
	unsigned int x, bool, t = 0, p = 1;
	char l = '\0';

	if (str != NULL)
	{
		if (characomp(str, d))
			return (NULL);
		s = str;
		x = xtrlent(str);
		str_1 = &str[x];
	}
	str_2 = s;
	if (str_2 == str_1)
		return (NULL);

	for (bool = t; *s; s += 1)
	{
		if (s != str_2)
			if (*s && *(s - p) == l)
				break;

		for (x = t; d[x]; x++)
		{
			if (*s == d[x])
			{
				*s = l;
				if (s == str_2)
					str_2++;
				break;
			}
		}
		if (bool == t && *s)
			bool = p;
	}
	if (bool == t)
		return (NULL);
	return (str_2);
}

/**
 * digitxmine - defines if string passed is a number
 *
 * @let: input string
 * Return: 1 if string is a number. 0 in other case.
 */
int digitxmine(const char *let)
{
	unsigned int u, x = 0;

	for (u = x; let[u]; u++)
	{
		if (let[u] < 48 || let[u] > 57)
			return (x);
	}
	return (x + 1);
}
