#include "shell.h"

/**
 * func_passer - function thst parses comd argument to inbilt function
 * @comd: command to be executed
 * Return: pointer to function of the inbuilt function
 */
int (*func_passer(char *comd))(store_v *)
{
	inbuiltfunhold_t f_hold[] = {
		{ "env", envprint },
		{ "unsetenv", resetenv },
		{ "setenv", envsetter },
		{ "exit", shellxit },
		{ "cd", shelldirxchange },
		{ "help", aidgethelp },
		{ NULL, NULL }
	};
	unsigned int f = 0;

	for (f = 0; f_hold[f].action; f++)
	{
		if (xtrcomp(f_hold[f].action, comd) == 0)
			break;
	}

	return (f_hold[f].fun);
}
