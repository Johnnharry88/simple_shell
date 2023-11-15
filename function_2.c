#include "shell.h"
/**
 * dirxchange - A built in function that changes directories
 * @args: The directory to be entered
 * Return: 0 on success else -1
 */
int dirxchange(char *args)
{
	int a, c = 0;
	char wd[PATH_MAX], *hme, *tokx;

	if (args == NULL)
	{
		hme = envgetter("HOME", environ);
		tokx = tokxtr(hme, "=");
		tokx = tokxtr(NULL, "\n");
		chdir(tokx);
		return (c);
	}
	if (xtrcomp(args, "-") == c)
	{
		getcwd(wd, sizeof(wd));
		a = xtrlent(wd);
		while (wd[a - 1] != '/')
		{
			wd[a - 1] = '\0';
			a = a - 1;
		}
		wd[a - 1] = '\0';
		chdir(wd);
		return (c);
	}
	if (chdir(args) == (c - 1))
	{
		perror("chdir error:");
		return (c - 1);
	}
	return (c);
}

/**
 * print_pwd - A function that prints the currend working directory
 * @args: The argument
 * Return: 0 on success else -1
 */
int print_pwd(char *args)
{
	char wd[PATH_MAX];
	int x = 0, y = -1;

	(void)args;
	(void)environ;
	getcwd(wd, sizeof(wd));
	if (wd == NULL)
	{
		perror("pwd error");
		return (y);
	}
	while (wd[x] != '\0')
	{
		_putchar(wd[x]);
		x = x + 1;
	}
	_putchar('\n');
	return (0);
}

/**
 * env_print - A function that prints the environment
 * @args: The argument
 * Return: 0 on success
 */
int env_print(char *args)
{
	size_t x = 0, j, y = 0;
	char *p_env = NULL;

	(void)args;
	while (environ[x] != NULL)
	{
		p_env = environ[x];
		j = y;
		while  (p_env[j] != '\0')
		{
			_putchar(p_env[j]);
			j = j + 1;
		}
		_putchar('\n');
		x++;
	}
	return (y);
}

/**
 * envgetter - A funtion that gets the values of an environment variable
 * @tag: name of the environment variable
 * @environ: The string array of environ variables
 * Return: The retrieved value of the env var
 */
char *envgetter(char *tag, char **environ)
{
	char *p_env = NULL, *tokx;
	int i = 0, y = 0;

	while (environ[i] != NULL)
	{
		p_env = environ[i];
		while (p_env[y] == tag[y] && p_env[y] != '=' && tag[y] != '\0')
			y++;
		if (tag[y] == '\0')
		{
			tokx = tokxtr(p_env, "=");
			tokx = tokxtr(NULL, "\n");
			return (tokx);
		}
		i++;
	}
	return (NULL);
}

/**
 * abs_pathgetter - A function that gets the absolute path of a command
 * @comd: The command passed
 * @environ: The string array of environ variables
 * Return:  NULL or abs path
 */
char *abs_pathgetter(char *comd, char **environ)
{
	char *pth = NULL, *abx_pth = NULL, *tokx = NULL;
	struct stat buff;
	int x = 0;

	pth = envgetter("PATH", environ);
	tokx = tokxtr(pth, ":");
	while (tokx != NULL)
	{
		abx_pth = malloc((xtrlent(tokx)) + (xtrlent(comd)) + 2);
		xtrcopy(tokx, abx_pth);
		xtrcat(abx_pth, "/");
		xtrcat(abx_pth, comd);
		if (stat(abx_pth, &buff) == x)
			return (abx_pth);
		free(abx_pth);
		tokx = tokxtr(NULL, ":");
	}
	if (stat(comd, &buff) == x)
		return (comd);
	return (NULL);
}
