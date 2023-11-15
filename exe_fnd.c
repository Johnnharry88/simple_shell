#include "shell.h"

/**
 * exec_check - Find the executable part of the command.
 * @c_cache: The command input.
 * Return: Pointer to the executable part of the command.
 */
char *exec_check(char *c_cache)
{
	char *delim = " ";

	return (tokxtr(c_cache, delim));
}
