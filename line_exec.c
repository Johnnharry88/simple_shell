#include "shell.h"

/**
 * linexef - function that inbuilt function and passes to command
 * @store: struct holding arguments
 * Return: 1 if failed else return function
 */
int linexef(store_v *store)
{
	int (*intfun)(store_v *store);
	unsigned int x = 0;

	if (store->argstr[x] == NULL)
		return (x + 1);
	intfun = func_passer(store->argstr[x]);
	if (intfun != NULL)
		return (intfun(store));
	return (comdexe(store));
}

/**
 * _signinteg - function that handles sign prompt in shell
 * @sig: Signal handler.
 * Return: void.
 */
void _signinteg(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$> ", 4);
}

/**
 * rdlinef -funtion that reads the input string.
 * @ix: value to be read
 * Return: input string
 */
char *rdlinef(int *ix)
{
	char *t = NULL;
	size_t xt = 0;

	*ix = getline(&t, &xt, stdin);

	return (t);
}

#include "shell.h"

/**
 * free_store - function that frees store structure
 * @store: struct holding arguments
 * Return: void.
 */
void free_store(store_v *store)
{
	unsigned int i;

	for (i = 0; store->venv[i]; i++)
	{
		free(store->venv[i]);
	}

	free(store->venv);
	free(store->pid);
}

/**
 * datareset - function that Initialize struct store
 * @store: struct holding arguments
 * @av: argument vector
 * Return: void.
 */
void datareset(store_v *store, char **av)
{
	unsigned int x, p = 1;

	store->ax = av;
	store->str = NULL;
	store->argstr = NULL;
	store->status = 0;
	store->rec = 1;

	for (x = 0; environ[x]; x += 1)
		;

	store->venv = malloc(sizeof(char *) * (x + p));

	for (x = (p - 1); environ[x]; x++)
	{
		store->venv[x] = dupstring(environ[x]);
	}

	store->venv[x] = NULL;
	store->pid = int_strconvert(getpid());
}
