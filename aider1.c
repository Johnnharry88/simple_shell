#include "shell.h"

/**
 * helpaux_env - function that helps with information for
 * the inbuilt function
 * Return: void
 */
void helpaux_env(void)
{
	char *x = "env: env [option] [name=value] [command [argument string]]\n\t";
	char *y =  "Prints out shell environment.\n";

	write(STDOUT_FILENO, x, xtrlent(x));
	write(STDOUT_FILENO, y, xtrlent(y));

}
/**
 * helpaux_envset - function that helps information for
 * the inbuilt functin setenv
 * Return: void.
 */
void helpaux_envset(void)
{

	char *x = "setenv: setenv (const char *name, const char *value,";
	char *y = "integer replace)\n\t";
	char *z  =  "Adds new definition to the environment\n";

	write(STDOUT_FILENO, x, xtrlent(x));
	write(STDOUT_FILENO, y, xtrlent(y));
	write(STDOUT_FILENO, z, xtrlent(z));
}
/**
 * helpaux_resetenv -function that helps with the information for
 * the inbuilt function resetenv
 * Return: void.
 */
void helpaux_resetenv(void)
{
	char *x = "unsetenv: unsetenv (const char *name)\n\t";
	char *y = "Removes an entry entirely from environment\n";


	write(STDOUT_FILENO, x, xtrlent(x));
	write(STDOUT_FILENO, y, xtrlent(y));
}

/**
 * helpaux_general - fucntion that holds point of entry information for
 * inbuilt function aidgethelp
 * Return: void
 */
void helpaux_general(void)
{
	char *x_1 = " $> : Ver 2.00(1)-2023\n";
	char *x_2 = " These commands are internally defined.\n";
	char *x_3 = " Type 'help' to view the list\n";
	char *x_4 = " Type 'help name' to view more about function 'name'.\n";
	char *x_5 = " alias: alias [name=['string']]\n";
	char *x_10 = " cd: cd [-L|[-P [-e]] [-@]] [dir[\n";
	char *x_6 = " nexit: exit [n]\n";
	char *x_9 = " env: env [option] [name=value] [command] [args]\n ";
	char *x_7 = " setenv: setenv [variable] [value]\n";
	char *x_8 = " unsetenv: unsetenv [variable]\n";

	write(STDOUT_FILENO, x_1, xtrlent(x_1));
	write(STDOUT_FILENO, x_2, xtrlent(x_2));
	write(STDOUT_FILENO, x_3, xtrlent(x_3));
	write(STDOUT_FILENO, x_4, xtrlent(x_4));
	write(STDOUT_FILENO, x_8, xtrlent(x_8));
	write(STDOUT_FILENO, x_6, xtrlent(x_6));
	write(STDOUT_FILENO, x_9, xtrlent(x_9));
	write(STDOUT_FILENO, x_7, xtrlent(x_7));
	write(STDOUT_FILENO, x_5, xtrlent(x_5));
	write(STDOUT_FILENO, x_10, xtrlent(x_10));
}
/**
 * helpaux_exit -function that assists inbuilin exit with
 * help infomration
 * Return: void.
 */
void helpaux_exit(void)
{
	char *a = "exit: exit [n]\n Exit shell.\n";
	char *b = "Exits the shell with status of N. If N is ommited";
	char *c = ", the statuus of the last command executed\n";

	write(STDOUT_FILENO, a, xtrlent(a));
	write(STDOUT_FILENO, b, xtrlent(b));
	write(STDOUT_FILENO, c, xtrlent(c));
}
