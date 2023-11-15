#include "shell.h"
/**
 * comargs_p - function that gets command arguments ready
 * @c_cache: command entered
 * @args: array to store command arguments.
 * Return: 0 if successful, -1 if an error occurs.
 */

int comargs_p(char *c_cache, char **args)
{
	char *delim = " ";
	char *tokx;
	int arg_ix = 0;

	tokx = tokxtr(c_cache, delim);
	while (tokx != NULL)
	{
		args[arg_ix++] = tokx;
		tokx = tokxtr(NULL, delim);
		if (arg_ix >= MAX_ARGS - 1)
		{
			perror("Too many arguments.\n");
			return (-1);
		}
	}
	args[arg_ix] = NULL;
	return (0);
}
