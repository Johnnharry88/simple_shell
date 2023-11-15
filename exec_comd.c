#include "shell.h"

/**
 * srchdir - function that checks for ":" in current directory.
 * @lnk: type char pointer char.
 * @x: type int pointer of index.
 * Return: 1 if the path is searchable in the cd, 0 otherwise.
 */
int srchdir(char *lnk, int *x)
{
	unsigned int d = 1;
	char hold = ':';

	if (lnk[*x] == hold)
		return (d);

	while (lnk[*x] != hold && lnk[*x])
	{
		*x += d;
	}

	if (lnk[*x])
		*x += d;

	return (d - 1);
}

/**
 * findcomd - function that finds a command
 * @comd: Name of command argument
 * @venv: environment variable
 * Return: location of the command.
 */
char *findcomd(char *comd, char **venv)
{
	char *lnk, *p_pt, *tok_lnk, *d;
	int x_dir, xc, y, z = 0;
	struct stat st;

	lnk = envgetter("PATH", venv);
	if (lnk)
	{
		p_pt = dupstring(lnk);
		xc = xtrlent(comd);
		tok_lnk = tokxtr(p_pt, ":");
		y = z;
		while (tok_lnk != NULL)
		{
			if (srchdir(lnk, &y))
				if (stat(comd, &st) == z)
					return (comd);
			x_dir = xtrlent(tok_lnk);
			d = malloc(x_dir + xc + z + 2);
			xtrcopy(d, tok_lnk);
			xtrcat(d, "/");
			xtrcat(d, comd);
			xtrcat(d, "\0");
			if (stat(d, &st) == z)
			{
				free(p_pt);
				return (d);
			}
			free(d);
			tok_lnk = tokxtr(NULL, ":");
		}
		free(p_pt);
		if (stat(comd, &st) == z)
			return (comd);
		return (NULL);
	}
	if (comd[z] == '/')
		if (stat(comd, &st) == z)
			return (comd);
	return (NULL);
}

/**
 * chkexef - function that checks out executable command
 * @store: struct holding potential arguments
 * Return: 0 if is not executable command
 */
int chkexef(store_v *store)
{
	struct stat st;
	int x, d = 0, e = 1;
	char *xmine;

	xmine = store->argstr[d];
	for (x = d; xmine[x]; x++)
	{
		if (xmine[x] == '.')
		{
			if (xmine[x + e] == '.')
				return (d);
			if (xmine[x + e] == '/')
				continue;
			else
				break;
		}
		else if (xmine[x] == '/' && x != d)
		{
			if (xmine[x + e] == '.')
				continue;
			x = x + 1;
			break;
		}
		else
			break;
	}
	if (x == d)
		return (d);

	if (stat(xmine + x, &st) == d)
	{
		return (x);
	}
	fetcherr(store, 127);
	return (e - 2);
}

/**
 * user_chkpermit - funciton that verifies user's access
 * @d: directory dest
 * @store: struct holding potential arguments
 * Return: 1 if error occurs otherwise 0.
 */
int user_chkpermit(char *d, store_v *store)
{
	int s = 0;

	if (d == NULL)
	{
		fetcherr(store, 127);
		return (s + 1);
	}

	if (xtrcomp(store->argstr[s], d) != s)
	{
		if (access(d, X_OK) == (s - 1))
		{
			fetcherr(store, 126);
			free(d);
			return (s + 1);
		}
		free(d);
	}
	else
	{
		if (access(store->argstr[s], X_OK) == (s - 1))
		{
			fetcherr(store, 126);
			return (s + 1);
		}
	}

	return (s);
}

/**
 * comdexe - function that executes command line/s passed.
 * @store: struct holding potential arguments
 * Return: 1 on success.
 */
int comdexe(store_v *store)
{
	pid_t xty;
	pid_t alx;
	int sit;
	int x, p = 0;
	char *d;
	(void) alx;

	x = chkexef(store);
	if (x == -1)
		return (p);
	if (x == p)
	{
		d = findcomd(store->argstr[p], store->venv);
		if (user_chkpermit(d, store) == (p + 1))
			return (p + 1);
	}

	xty = fork();
	if (xty == p)
	{
		if (x == p)
			d = findcomd(store->argstr[p], store->venv);
		else
			d = store->argstr[p];
		execve(d + x, store->argstr, store->venv);
	}
	else if (xty < p)
	{
		perror(store->ax[p]);
		return (1);
	}
	else
	{
		while (!WIFEXITED(sit) && !WIFSIGNALED(sit))
			alx = waitpid(xty, &sit, WUNTRACED);
	}

	store->status = sit / 256;
	return (p + 1);
}
