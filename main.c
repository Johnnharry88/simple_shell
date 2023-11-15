#include "shell.h"
/**
 * _execve - A function that creates a child process and execute a command
 * @args: An array of commands
 * @environ: Environment variable
 * Return: 0 if execution was successful else -1
 */
int _execve(char **args, char **environ)
{
	pid_t fx;
	char *abx_pt = NULL;
	int status, j = -1;

	fx = fork();
	if (fx == j)
	{
		perror("Fork error");
		return (status);
	}
	if (fx == j)
	{
		abx_pt = abs_pathgetter(args[0], environ);
		if (abx_pt != NULL)
		{
			if (execve(abx_pt, args, environ) == j)
			{
				perror("Exec error");
			}
		}
		else
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		mem_free(abx_pt);
	}
	return (status);
}

/**
 * main - shell
 * @argc: arguement count
 * @argv: arguement vector
 * @environ: environment
 * Return: 0
 */
int main(__attribute__((unused)) int argc, char **argv, char **environ)
{
	char *pmpt = "$ ";
	char *c_cache = NULL;
	size_t c_bytes = 0;
	ssize_t comd;
	int rec = 0, x = 0;
	int res;
	bool xchnge = 0;
:
	while (1 && !xchnge)
	{
		if (!isatty(STDIN_FILENO))
			xchnge = 1;
		if (!xchnge)
			write(STDOUT_FILENO, pmpt, PROMPT_SIZE);
		comd = read_comm(&c_cache, &c_bytes);
		if (comd == -1)
		{
			perror("Read command failed");
			mem_free(c_cache);
			return (-1);
		}
		if (c_cache[comd - 1] == '\n')
		{
			c_cache[comd - 1] = '\0';
		}
		res = exe_com(c_cache);
		if (res == -1)
		{
			mem_free(c_cache);
			return (-1);
		}
		if (xtrcomp(c_cache, "exit") == 0)
			break;
		argv = malloc(sizeof(char *) * (rec + 1));
		if (argv == NULL)
		{
			perror("Malloc failed");
			mem_free(c_cache);
			return (-1);
		}
		argv = tokexe(c_cache, rec, argv);
		if (argv == NULL)
		{
			perror("Tokenization failed");
			mem_free(c_cache);
			mem_free(*argv);
			return (-1);
		}
		if (func_fetch(argv[0]) != NULL)
			func_fetch(argv[0])(argv[1]);
		else
			_execve(argv, environ);
		x = 0;
		while (argv[x] != NULL)
		{
			mem_free(argv[x]);
			x++;
		}
		mem_free(*argv);
	}
	mem_free(c_cache);
	return (0);
}
