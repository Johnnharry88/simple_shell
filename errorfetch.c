#include "shell.h"

/**
 * fetcherr - fucntion that calls error according the inbuilt
 * syntax or permission
 * @store: struct  holding arguments
 * @errval: error value
 * Return: error
 */
int fetcherr(store_v *store, int errval)
{
	char *d_err;
	int x = 0;

	switch (errval)
	{
	case -1:
		d_err = environerr(store);
		break;
	case 126:
		d_err = patherror_126(store);
		break;
	case 127:
		d_err = neg_error(store);
		break;
	case 2:
		if (xtrcomp("exit", store->argstr[x]) == x)
			d_err = shellxiterror(store);
		else if (xtrcomp("cd", store->argstr[x]) == x)
			d_err = cdirerr(store);
		break;
	}

	if (d_err)
	{
		write(STDERR_FILENO, d_err, xtrlent(d_err));
		free(d_err);
	}

	store->status = errval;
	return (errval);
}
