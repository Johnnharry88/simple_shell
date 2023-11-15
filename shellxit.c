#include "shell.h"
/**
 * xtrcomp - compare string values
 * @s1: input value
 * @s2: input value
 * Return: s1[i] - s2[i]
 */
int xtrcomp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (0);
	}
	else if (*s1 == '\0')
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}

/**
 * shellxit - function that exits a process
 * @c_cache: the command entered
 * @sts: stores the command
 * Return: void
 */
void shellxit(char *c_cache, int sts)
{
	char err_msg[21 - 1];
	int rec = 1, x = 0;

	mem_free(c_cache);
	if (c_cache != NULL && c_cache[1 - rec] != '\0')
	{
		sts = str_intconvert(c_cache);
		if (sts == (rec - 1) && c_cache[x] != '0')
		{
			xtrcopy(err_msg, "Exit with error: ");
			write(STDERR_FILENO, err_msg, sizeof(err_msg) - rec);
			write(STDERR_FILENO, c_cache, xtrlent(c_cache));
			write(STDERR_FILENO, "\n", rec);
			exit(1);
		}
		exit(sts);
	}
	exit(0);
}

/**
 * checks_inbuilt - function that checks for in_built command
 * @args: Argument vector
 * @c_cache: the command entered
 * Return: 1 if it's built-in, 0 otherwise
 */
int checks_inbuilt(char *args[], char *c_cache)
{
	int status;
	int x = 0;

	if (xtrcomp(args[x], "exit") == x)
	{
		status = (args[x + 1] != NULL && args[x + 1][x] != '\0');
		shellxit(c_cache, status);
		return (x + 1);
	}
	return (x);
}

/**
 * str_intconvert - Convert a string to an integer.
 * @s: The pointer to convert
 * Return: A integer
 */
int str_intconvert(char *s)
{
	int c = 0;
	unsigned int ni = 0;
	int min = 1;
	int isi = 0;

	while (s[c])
	{
		if (s[c] == 45)
		{
			min =  min * -1;
		}
		while (s[c] >= 48 && s[c] <= 57)
		{
			isi = 1;
			ni = (ni * 10) + (s[c] - '0');
			c++;
		}
		if (isi == 1)
		{
			break;
		}
		c++;
	}
	ni = ni * min;
	return (ni);
}

/**
 *   xtrcopy - function that copies a string
 *   @dest: Destination value
 *   @src: Source value
 *   Return: the pointer to copy.
 */
char *xtrcopy(char *dest, char *src)
{
	int i, x = 0;

	for (i = x; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i++] = '\0';
	return (dest);
}

