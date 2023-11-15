#include "shell.h"
/**
 * exe_chd - function that executes the child process
 * @av: pointer to the argument vector
 * Return: 0 if successful
 */
int exe_chd(char *av[])
{
	char *act;
	int ex, x  = 0;

	act = exec_check(av[0]);
	if (act == NULL)
	{
		perror("Executable not found.\n");
		return (x - 1);
	}

	ex = execve(act, av, NULL);
	if (ex == (x - 1))
	{
		perror("Execve failed");
		return (-1);
	}
	return (x);
}

/**
 * exe_p - function to keep parent process on hold until child execute
 * @pid: the child process id
 * Return: 0 (Success), else -1.
 */
int exe_p(pid_t pid)
{
	int status;
	int y = 0, w_r;

	w_r = waitpid(pid, &status, 0);
	if (w_r == (y - 1))
	{
		perror("Process waitpid failed");
		return (-1);
	}
	return (y);
}

/**
 * exe_com - function to execute the command entered
 * @c_cache: command entered by users
 * Return: the pid of the calling process
 */

int exe_com(char *c_cache)
{
	char *args[MAX_ARGS];
	pid_t pid;
	int x = -1;

	if (comargs_p(c_cache, args) == x)
		return (x);
	if (checks_inbuilt(args, c_cache))
	{
		return (x + 1);
	}
	pid = fork();
	if (pid == x)
	{
		perror("Fork process failed");
		return (x);
	}
	else if (pid == 0)
	{
		return (exe_chd(args));
	}
	else
	{
		return (exe_p(pid));
	}
}
