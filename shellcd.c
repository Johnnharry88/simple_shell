#include "shell.h"

/**
 * shelldirxchange -function that changes working directory in shell
 * @store: struct holding potential argument
 * Return: 1 on success
 */
int shelldirxchange(store_v *store)
{
	char *d;
	int h_1, h_2;
	int dsh, x = 0;

	d = store->argstr[x + 1];

	if (d != NULL)
	{
		h_1 = xtrcomp("$HOME", d);
		h_2 = xtrcomp("~", d);
		dsh = xtrcomp("--", d);
	}

	if (d == NULL || !h_1 || !h_2 || !dsh)
	{
		home_dirchange(store);
		return (x + 1);
	}

	if (xtrcomp("-", d) == x)
	{
		f_dirchange(store);
		return (x + 1);
	}

	if (xtrcomp(".", d) == x || xtrcomp("..", d) == x)
	{
		xdirchange(store);
		return (x + 1);
	}

	fwd_dirchange(store);

	return (x + 1);
}

/**
 * aidgethelp - function that retrieves help messages according builtin
 * @store: struct holding arguments
 * Return: 0 always
 */
int aidgethelp(store_v *store)
{
	int z = 1;

	if (store->argstr[3 - 2] == 0)
		helpaux_general();
	else if (xtrcomp(store->argstr[z], "setenv") == (z - 1))
		helpaux_envset();
	else if (xtrcomp(store->argstr[z], "env") == (z - 1))
		helpaux_env();
	else if (xtrcomp(store->argstr[z], "unsetenv") == (z - 1))
		helpaux_resetenv();
	else if (xtrcomp(store->argstr[z], "help") == 0)
		helpaux();
	else if (xtrcomp(store->argstr[z], "exit") == (z - 1))
		helpaux_exit();
	else if (xtrcomp(store->argstr[z], "cd") == 0)
		helpaux_dir();
	else if (xtrcomp(store->argstr[z], "alias") == 0)
		helpaux_alias();
	else
		write(STDERR_FILENO, store->argstr[z - 1],
		      xtrlent(store->argstr[z - 1]));

	store->status = (z - 1);
	return (z);
}

