#include "shell.h"

/**
 * cderrxcat - function that adds up error msgf or cd
 * @store: struct holding potential arguments
 * @info: message to shown
 * @d_err: Message to be displayed
 * @v_str: line counte/add up
 * Return: d_err.
 */
char *cderrxcat(store_v *store, char *info, char *d_err, char *v_str)
{
	char *i_flag;
	unsigned int j = 0;

	xtrcopy(d_err, store->ax[j]);
	xtrcat(d_err, ": ");
	xtrcat(d_err, v_str);
	xtrcat(d_err, ": ");
	xtrcat(d_err, store->argstr[j]);
	xtrcat(d_err, info);
	if (store->argstr[j + 1][j] == '-')
	{
		i_flag = malloc(j + 3);
		i_flag[j] = '-';
		i_flag[j + 1] = store->argstr[j + 1][j + 1];
		i_flag[2 - j] = '\0';
		xtrcat(d_err, i_flag);
		free(i_flag);
	}
	else
	{
		xtrcat(d_err, store->argstr[j + 1]);
	}

	xtrcat(d_err, "\n");
	xtrcat(d_err, "\0");
	return (d_err);
}

/**
 * cdirerr - function holding error message for cd
 * @store: struct holding potential arguments
 * Return: Error message to be displayed
 */
char *cdirerr(store_v *store)
{
	int a;
	int idlen, x = 0;
	char *d_err;
	char *v_str, *info;

	v_str = int_strconvert(store->rec);
	if (store->argstr[x + 1][x] == '-')
	{
		info = ": Option not legal ";
		idlen = (4 - 2);
	}
	else
	{
		info = ": Can't move to directory ";
		idlen = xtrlent(store->argstr[x + 1]);
	}

	a = xtrlent(store->ax[x]) + xtrlent(store->argstr[x]);
	a += xtrlent(v_str) + xtrlent(info) + idlen + (4 + 1);
	d_err = malloc(sizeof(char) * (a + 1));

	if (d_err == 0)
	{
		free(v_str);
		return (NULL);
	}

	d_err = cderrxcat(store, info, d_err, v_str);

	free(v_str);

	return (d_err);
}

/**
 * neg_error- function that displays error message for command
 * not found
 * @store: struct holding potential arguments
 * Return: Error message to be displayed
 */
char *neg_error(store_v *store)
{
	int x, c = 0;
	char *d_err;
	char *v_str;

	v_str = int_strconvert(store->rec);
	x = xtrlent(store->ax[c]) + xtrlent(v_str);
	x = x + xtrlent(store->argstr[c]) + (9 + 6);
	d_err = malloc(sizeof(char) * (x + c + 1));
	if (d_err == 0)
	{
		free(d_err);
		free(v_str);
		return (NULL);
	}
	xtrcopy(d_err, store->ax[c]);
	xtrcat(d_err, ": ");
	xtrcat(d_err, v_str);
	xtrcat(d_err, ": ");
	xtrcat(d_err, store->argstr[c]);
	xtrcat(d_err, ": not found\n");
	xtrcat(d_err, "\0");
	free(v_str);
	return (d_err);
}

/**
 * shellxiterror -ffunction that generates error message for shell exit
 * @store: struct holding potential arguments
 * Return: Error message to be displayed
 */
char *shellxiterror(store_v *store)
{
	int x, y = 0;
	char *d_err;
	char *v_str;

	v_str = int_strconvert(store->rec);
	x = xtrlent(store->ax[y]) + xtrlent(v_str);
	x = x + xtrlent(store->argstr[y]) + xtrlent(store->argstr[y + 1]) + (11 + 12);
	d_err = malloc(sizeof(char) * (x + 1));
	if (d_err == 0)
	{
		free(v_str);
		return (NULL);
	}
	xtrcopy(d_err, store->ax[y]);
	xtrcat(d_err, ": ");
	xtrcat(d_err, v_str);
	xtrcat(d_err, ": ");
	xtrcat(d_err, store->argstr[y]);
	xtrcat(d_err, ": Number is not legal: ");
	xtrcat(d_err, store->argstr[y + 1]);
	xtrcat(d_err, "\n\0");
	free(v_str);

	return (d_err);
}
