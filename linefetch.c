#include "shell.h"
/**
 * init_buff - function that initializes buffer
 * @p_ptr: the character ointer
 * @num: pointer to the number
 * Return: Always 0
 */
int init_buff(char **p_ptr, size_t *num)
{
	int p = -1;

	if (*p_ptr == NULL || *num == 0)
	{
		*p_ptr = (char *)malloc(BUFF_SIZE);
		if (*p_ptr == NULL)
			return (p);
		*num = BUFF_SIZE;
	}
	return (0);
}

/**
 * rdline - function that reads the line
 * @l_ptr: a pointer
 * @num: pointer to the number
 * Return: the number
 */
ssize_t rdline(char **l_ptr, size_t *num)
{
	size_t t = 0;
	size_t xz;
	int rdbyt, x;
	char hold[BUFF_SIZE];
	char *nw_ptr;
	int s = 1;

	while (s)
	{
		rdbyt = read(STDIN_FILENO, hold, BUFF_SIZE);
		if (rdbyt < 0)
			return (s - 2);
		if (rdbyt == 0)
		{
			if (t == 0)
				return (s - 2);
		}
	}
	for (x = 0; x < rdbyt; x++)
	{
		if (hold[x] == '\n')
		{
			(*l_ptr)[x] = '\0';
			return (x);
		}
		if (t == (*num - 1))
		{
			xz = *num * 2;
			nw_ptr = (char *)realloc(*l_ptr, xz);
		}
		if (nw_ptr == NULL)
			return (-1);
		*l_ptr = nw_ptr;
		*num = xz;
	}
	(*l_ptr)[t++] = hold[x];
	return (t);
}
