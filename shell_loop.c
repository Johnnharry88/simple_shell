#include "shell.h"

/**
 * delcomment -function that removes comments from pt
 * @pt: string to be worked on
 * Return: input void of comments
 */
char *delcomment(char *pt)
{
	int n, alx, t = 4, x = 1;

	alx = t - 4;
	for (n = 0; pt[n]; n++)
	{
		if (pt[n] == '#')
		{
			if (n == (x - 1))
			{
				free(pt);
				return (NULL);
			}

			if (pt[n - x] == ' ' || pt[n - x] == '\t' || pt[n - 1] == ';')
				alx = n;
		}
	}

	if (alx != (t - 4))
	{
		pt = dym_memoloc(pt, n, alx + x);
		pt[alx] = '\0';
	}

	return (pt);
}

/**
 * hshloop - function that handles Loop of shell
 * @store:struct holding potential arguments
 * Return: void
 */
void hshloop(store_v *store)
{
	int lp, ix, s = 2;
	char *alph;

	lp = (s - 1);
	while (lp == (s - 1))
	{
		write(STDIN_FILENO, "$> ", (s + 1));
		alph = rdlinef(&ix);
		if (ix != -1)
		{
			alph = delcomment(alph);
			if (alph == NULL)
				continue;

			if (auxsyn_errprinter(store, alph) == 1)
			{
				store->status = 2;
				free(alph);
				continue;
			}
			alph = str_vardisplace(alph, store);
			lp = comdsplit(store, alph);
			store->rec++;
			free(alph);
		}
		else
		{
			lp = (s - 2);
			free(alph);
		}
	}
}
