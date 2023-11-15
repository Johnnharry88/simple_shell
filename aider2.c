#include "shell.h"

/**
 * helpaux -function that assists inbuilt function help with
 * information.
 * Return: void
 */
void helpaux(void)
{
	char *h = "help: help [-dms] [pattern ...]\n";
	char *i = "\tShows information concerning inbuilt commands.\n ";
	char *j = "Shows brief summaries of builtin commands.\n";

	write(STDOUT_FILENO, h, xtrlent(h));
	write(STDOUT_FILENO, i, xtrlent(i));
	write(STDOUT_FILENO, j, xtrlent(j));
}

/**
 * helpaux_alias - function that assists inbuilt allias with
 * information.
 * Return: void.
 */
void helpaux_alias(void)
{
	char *x = "alias: alias [-p] [name[=value]...]\n";
	char *y = "\tShow or displays aliases.\n ";

	write(STDOUT_FILENO, x, xtrlent(x));
	write(STDOUT_FILENO, y, xtrlent(y));
}

/**
 * helpaux_dir - function that assist inbult function cd with information
 * Return: void.
 */
void helpaux_dir(void)
{
	char *x = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";
	char *y = "\tChanges the shell working directory.\n ";

	write(STDOUT_FILENO, x, xtrlent(x));
	write(STDOUT_FILENO, y, xtrlent(y));
}
