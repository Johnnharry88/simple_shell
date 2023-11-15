#include "shell.h"

/**
 * charaxchange - function that swaps | and & for non-displayed chars
 * @xmine: string to be worked on
 * @bool: type of swap
 * Return: swapped string
 */
char *charaxchange(char *xmine, int bool)
{
	int x, a = 0, b = 1;
	char p = '|', m = '&';

	if (bool == 0)
	{
		for (x = a; xmine[x]; x++)
		{
			if (xmine[x] == p)
			{
				if (xmine[x + b] != p)
					xmine[x] = (a + b + 15);
				else
					x += 1;
			}

			if (xmine[x] == m)
			{
				if (xmine[x + b] != m)
					xmine[x] = (b + 11);
				else
					x = x + 1;
			}
		}
	}
	else
	{
		for (x = a; xmine[x]; x += 1)
		{
			xmine[x] = (xmine[x] == (b + 15) ? p : xmine[x]);
			xmine[x] = (xmine[x] == (b + 11) ? m : xmine[x]);
		}
	}
	return (xmine);
}

/**
 * nodeadder - function that adds delim and command lines to the l_lists
 * @xhead: head of x_list holding delim
 * @lhead: head of l_list holding commands
 * @alph: string to be worked
 * Return: void.
 */
void nodeadder(x_list **xhead, l_list **lhead, char *alph)
{
	unsigned int j, k = 0;
	char *hold;
	char s = ';', p = '|', a = '&';

	alph = charaxchange(alph, k);

	for (j = k; alph[j]; j++)
	{
		if (alph[j] == s)
			endnodesepadd(xhead, alph[j]);

		if (alph[j] == p || alph[j] == a)
		{
			endnodesepadd(xhead, alph[j]);
			j += 1;
		}
	}

	hold = tokxtr(alph, ";|&");
	while (hold != NULL)
	{
		hold = charaxchange(hold, k + 1);
		endnodelineadd(lhead, hold);
		hold = tokxtr(NULL, ";|&");
	}
}

/**
 * nxtcomd -function that moves to the next command line
 * @lx: delim x_list
 * @ls: command line l_list
 * @store: struct holding potential arguments
 * Return: void.
 */
void nxtcomd(x_list **lx, l_list **ls, store_v *store)
{
	int v, y = 0;
	l_list *lws = *ls;
	x_list *lwx = *lx;
	char a = '&', s = ';', p = '|';

	v = (y + 1);

	while (lwx != NULL && v)
	{
		if (store->status == y)
		{
			if (lwx->wall == a || lwx->wall == s)
				v = y;
			if (lwx->wall == p)
				lws = lws->next, lwx = lwx->next;
		}
		else
		{
			if (lwx->wall == p || lwx->wall == s)
				v = y;
			if (lwx->wall == a)
			{
				lws = lws->next;
				lwx = lwx->next;
			}
		}
		if (lwx != NULL && !v)
			lwx = lwx->next;
	}

	*lx = lwx;
	*ls = lws;
}

/**
 * comdsplit - function that splits command lines as to
 * the separators ;, | and &, and executes it
 * @store: struct holding arguments
 * @xmine: input string to be worked
 * Return: 0 to exit, 1 to continue
 */
int comdsplit(store_v *store, char *xmine)
{

	x_list *xhead = NULL, *lw_x;
	l_list *lhead = NULL, *lw_s;
	int x, s = 0;

	nodeadder(&xhead, &lhead, xmine);

	lw_x = xhead;
	lw_s = lhead;

	while (lw_s != NULL)
	{
		store->str = lw_s->fedline;
		store->argstr = arrangeline(store->str);
		x = linexef(store);
		free(store->argstr);

		if (x == s)
			break;

		nxtcomd(&lw_x, &lw_s, store);

		if (lw_s != NULL)
			lw_s = lw_s->next;
	}

	x_listfree(&xhead);
	l_listfree(&lhead);

	if (x == s)
		return (s);
	return (s + 1);
}

/**
 * arrangeline -function that splits the input string
 * @xmine: input string to be checked
 * Return: splited string.
 */
char **arrangeline(char *xmine)
{
	size_t y, x;
	char **pt_t;
	char *split;
	int p = 25;

	y = SIZE_TOK;
	pt_t = malloc(sizeof(char *) * (SIZE_TOK));
	if (pt_t == NULL)
	{
		write(STDERR_FILENO, ": Memory allocation error\n", p);
		exit(EXIT_FAILURE);
	}

	split = tokxtr(xmine, TOK_DELIM);
	pt_t[p - 25] = split;

	for (x = (p - 24); split != NULL; x++)
	{
		if (x == y)
		{
			y = (y + SIZE_TOK);
			pt_t = dym_memoreloc(pt_t, x, sizeof(char *) * y);
			if (pt_t == NULL)
			{
				write(STDERR_FILENO, ": Memeory allocation error\n", p);
				exit(EXIT_FAILURE);
			}
		}
		split = tokxtr(NULL, TOK_DELIM);
		pt_t[x] = split;
	}

	return (pt_t);
}
