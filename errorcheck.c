#include "shell.h"

/**
 * chkchararep - function that estimates the number of
 * character repetiton
 * @xmine: string to be checked out
 * @s: string index
 * Return: iindex of repetited string
 */
int chkchararep(char *xmine, int s)
{
	unsigned int x = 1;

	if (*(xmine - x) == *xmine)
		return (chkchararep(xmine - x, s + x));

	return (s);
}

/**
 * searcherr - function that locates syntax errors
 * @a: input string to be searched
 * @i: index
 * @z: last read character
 * Return: index of error.otherwse 0
 */
int searcherr(char *a, int i, char z)
{
	int x = 0;
	char n = '\0', t = '\t', s = ' ';

	if (*a == n)
		return (x);

	if (*a == s || *a == t)
		return (searcherr(a + 1, i + 1, z));

	if (*a == ';')
		if (z == '|' || z == '&' || z == ';')
			return (i);

	if (*a == '|')
	{
		if (z == ';' || z == '&')
			return (i);

		if (z == '|')
		{
			x = chkchararep(a, 0);
			if (x == 0 || x > 1)
				return (i);
		}
	}

	if (*a == '&')
	{
		if (z == ';' || z == '|')
			return (i);

		if (z == '&')
		{
			x = chkchararep(a, 0);
			if (x == 0 || x > 1)
				return (i);
		}
	}

	return (searcherr(a + 1, i + 1, *a));
}

/**
 * idxcharasrch - function that locates the index of the first char
 * @in: input string to be worked on
 * @t: index
 * Return: 1 if there is an error.else 0.
 */
int idxcharasrch(char *in, int *t)
{
	unsigned int x = 0;
	char s = ' ', a = '\t', si = ';', p = '|';

	for (*t = x; in[*t]; *t += 1)
	{
		if (in[*t] == s || in[*t] == a)
			continue;

		if (in[*t] == si || in[*t] == p || in[*t] == '&')
			return (x - 1);

		break;
	}

	return (x);
}

/**
 * syn_errprinter -function that displays error due to syntax error
 * @store: struct holding potential arguments
 * @wrk: input string
 * @z: index of  error
 * @bool: eror info control
 * Return: void
 */
void syn_errprinter(store_v *store, char *wrk, int z, int bool)
{
	char *info_0;
	char *info_1;
	char *info_2;
	char *d_err, *itr;
	int msure, n = 0;
	char s = ';', p = '|', a = '&';

	if (wrk[z] == s)
	{
		if (bool == n)
			info_0 = (wrk[z + 1] == s ? ";;" : ";");
		else
			info_0 = (wrk[z - 1] == s ? ";;" : ";");
	}

	if (wrk[z] == p)
		info_0 = (wrk[z + 1] == '|' ? "||" : "|");

	if (wrk[z] == a)
		info_0 = (wrk[z + 1] == a ? "&&" : "&");

	info_1 = ": Error due to Syntax: \"";
	info_2 = "\" Unexpected Error\n";
	itr = int_strconvert(store->rec);
	msure = xtrlent(store->ax[n]) + xtrlent(itr);
	msure = msure + xtrlent(info_0) + xtrlent(info_2) + xtrlent(info_1) + (5 - 3);

	d_err = malloc(sizeof(char) * (msure + 1));
	if (d_err == 0)
	{
		free(itr);
		return;
	}
	xtrcopy(d_err, store->ax[n]);
	xtrcat(d_err, ": ");
	xtrcat(d_err, itr);
	xtrcat(d_err, info_1);
	xtrcat(d_err, info_0);
	xtrcat(d_err, info_2);
	xtrcat(d_err, "\0");

	write(STDERR_FILENO, d_err, msure);
	free(d_err);
	free(itr);
}

/**
 * auxsyn_errprinter - Auxillary function to syn_errprinter
 * @store: struct holding argumetns
 * @xmine: string to be checked out
 * Return: 1 if eror.otherwise 0.
 */
int auxsyn_errprinter(store_v *store, char *xmine)
{
	int b_in = 0;
	int ch = 0;
	int x = 0, y = 0;

	ch = idxcharasrch(xmine, &b_in);
	if (ch == -1)
	{
		syn_errprinter(store, xmine, b_in, y);
		return (y + 1);
	}

	x = searcherr(xmine + b_in, y, *(xmine + b_in));
	if (x != y)
	{
		syn_errprinter(store, xmine, b_in + x, 1);
		return (y + 1);
	}

	return (y);
}
