#include "shell.h"

/**
 * envnamecomp - function that checks out environment variables names
 * with the command argument passed.
 * @env_name: name of the environment variable
 * @tag: comd passed
 * Return: 0 if not equal. otherwise vlaue of int
 */
int envnamecomp(const char *env_name, const char *tag)
{
	unsigned int x, t = 0;

	for (x = t; env_name[x] != '='; x++)
	{
		if (env_name[x] != tag[x])
		{
			return (t);
		}
	}

	return (1 + x);
}

/**
 * envgetter - function that get environment variable
 * @tag: environment variable name
 * @env: environment variable
 * Return: NULL or value of environment.
 */
char *envgetter(const char *tag, char **env)
{
	char *p_env;
	unsigned int i;
	int x;

	p_env = NULL;
	x = 0;
	for (i = 0; env[i]; i++)
	{
		x = envnamecomp(env[i], tag);
		if (x)
		{
			p_env = env[i];
			break;
		}
	}

	return (p_env + x);
}

/**
 * envprint - displays the evironment variables
 * @store: struct holding potential arguments.
 * Return: 1 on success.
 */
int envprint(store_v *store)
{
	int x;
	int y, z = 0;

	for (x = z; store->venv[x]; x++)
	{
		for (y = z; store->venv[x][y]; y++)
			;

		write(STDOUT_FILENO, store->venv[x], y);
		write(STDOUT_FILENO, "\n", z + 1);
	}
	store->status = z;

	return (z + 1);
}
