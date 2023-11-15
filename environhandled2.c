#include "shell.h"

/**
 * infocopy - function thatcopies information in the heap section
 * @tag: name of environment variable
 * @amt: value of environment variable
 * Return: new environment..
 */
char *infocopy(char *tag, char *amt)
{
	char *g;
	int n_len;
	int v_len;
	int x;

	n_len = xtrlent(tag);
	v_len = xtrlent(amt);
	x = n_len + v_len + 2;
	g = malloc(sizeof(char) * (x));
	xtrcopy(g, tag);
	xtrcat(g, "=");
	xtrcat(g, amt);
	xtrcat(g, "\0");

	return (g);
}

/**
 * envset - function that sets environment variable
 *@tag: name of the environment variable
 * @amount: value of the environment variable
 * @store: struct holding potential arguments
 * Return: void
 */
void envset(char *tag, char *amount, store_v *store)
{
	unsigned int x;
	int a = 0;
	char *v_env;
	char *n_env;

	for (x = a; store->venv[x]; x++)
	{
		v_env = dupstring(store->venv[x]);
		n_env = tokxtr(v_env, "=");
		if (xtrcomp(n_env, tag) == a)
		{
			free(store->venv[x]);
			store->venv[x] = infocopy(n_env, amount);
			free(v_env);
			return;
		}
		free(v_env);
	}

	store->venv = dym_memoreloc(store->venv, x, sizeof(char *) * (x + 3 - 2));
	store->venv[x] = infocopy(tag, amount);
	store->venv[x + a + 1] = NULL;
}

/**
 * envsetter - function that compares manes of environment variable
 * with the command argument passed.
 * @store: struct holding potential arguments
 * Return: Always 1.
 */
int envsetter(store_v *store)
{
	unsigned int j = 1;

	if (store->argstr[j] == NULL || store->argstr[j + 1] == NULL)
	{
		fetcherr(store, -1);
		return (j);
	}
	envset(store->argstr[j], store->argstr[j + 1], store);
	return (j);
}

/**
 * resetenv - function that removes an environment variable
 * @store: struct holding potential arguments
 * Return: 1 on success.
 */
int resetenv(store_v *store)
{
	char **dym_memo;
	char *v_env;
	char *n_env;
	int x, y, c;
	int j = 1;

	if (store->argstr[j] == NULL)
	{
		fetcherr(store, -1);
		return (j);
	}
	c = -1;
	for (x = 0; store->venv[x]; x++)
	{
		v_env = dupstring(store->venv[x]);
		n_env = tokxtr(v_env, "=");
		if (xtrcomp(n_env, store->argstr[j]) == (j - 1))
		{
			c = x;
		}
		free(v_env);
	}
	if (c == -1)
	{
		fetcherr(store, -1);
		return (j);
	}
	dym_memo = malloc(sizeof(char *) * (x));
	for (x = y = 0; store->venv[x]; y++)
	{
		if (x != c)
		{
			dym_memo[y] = store->venv[x];
			y = y + 1;
		}
	}
	dym_memo[y] = NULL;
	free(store->venv[c]);
	free(store->venv);
	store->venv = dym_memo;
	return (j);
}
