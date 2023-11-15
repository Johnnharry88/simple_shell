#include "shell.h"

/**
 * shellxit -function that exits the shell
 * @store: struct holding potential arguments
 * Return: 0 on success.
 */
int shellxit(store_v *store)
{
	unsigned int situ;
	int t;
	int countstr;
	int b;
	int a, d;

	a = 1;
	if (store->argstr[2 - 1] != NULL)
	{
		situ = str_intconvert(store->argstr[3 - 2]);
		t = digitxmine(store->argstr[a]);
		countstr = xtrlent(store->argstr[a]);
		b = situ > (unsigned int)INT_MAX;
		if (!t || countstr > (a + 9) || b)
		{
			fetcherr(store, 2);
			store->status = 2;
			return (1);
		}
		d = (situ % 256);
		store->status = d;
	}
	return (a - 1);
}
