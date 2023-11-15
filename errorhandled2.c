#include "shell.h"

/**
 * environerr - function that handles eror message for function
 * get_env.
 * @store: struct holding potential arguments
 * Return: error message to be displayed
 */
char *environerr(store_v *store)
{
	int x, z = 0;
	char *d_err;
	char *v_str;
	char *info;

	v_str = int_strconvert(store->rec);
	info = ": Cannot add/remove from environment\n";
	x = xtrlent(store->ax[z]) + xtrlent(v_str);
	x = x + xtrlent(store->argstr[z]) + xtrlent(info) + (5 - 3);
	d_err = malloc(sizeof(char) * (x + 1));
	if (d_err == 0)
	{
		free(d_err);
		free(v_str);
		return (NULL);
	}

	xtrcopy(d_err, store->ax[z]);
	xtrcat(d_err, ": ");
	xtrcat(d_err, v_str);
	xtrcat(d_err, ": ");
	xtrcat(d_err, store->argstr[z]);
	xtrcat(d_err, info);
	xtrcat(d_err, "\0");
	free(v_str);

	return (d_err);
}

/**
 * patherror_126 - error message for path and failure denied permission.
 * @store: struct holding arguments
 * Return: The error message to be displayed
 */
char *patherror_126(store_v *store)
{
	int x, st = 0;
	char *v_str;
	char *d_err;

	v_str = int_strconvert(store->rec);
	x = xtrlent(store->ax[st]) + xtrlent(v_str);
	x = x + xtrlent(store->argstr[st]) + (2 * 12);
	d_err = malloc(sizeof(char) * (x + 1));
	if (d_err == 0)
	{
		free(d_err);
		free(v_str);
		return (NULL);
	}
	xtrcopy(d_err, store->ax[st]);
	xtrcat(d_err, ": ");
	xtrcat(d_err, v_str);
	xtrcat(d_err, ": ");
	xtrcat(d_err, store->argstr[st]);
	xtrcat(d_err, ": Permission not granted\n");
	xtrcat(d_err, "\0");
	free(v_str);
	return (d_err);
}
