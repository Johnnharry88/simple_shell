#include "shell.h"
/**
 *token_rec - A functions that counts the number of tokens in a string
 * @str: The string
 * Return: The number of tokens counted
 */

int token_rec(char *str)
{
	int c = 0, a;
	char *tok = NULL;

	tok = tokxtr(str, " \n");
	while (tok != NULL)
	{
		c = c + 1;
		tok = tokxtr(NULL, " \n");
	}
	a = c;
	return (a);
}

/**
 * func_fetch - A function that checks if a command is built in and assigns the
 *            fuction to execute if it is
 * @comd: The command passed
 * args: Argument vector
 * Return: A pointer to the assigned function on success else NULL
 */
int (*func_fetch(char *comd))(char *args)
{
	inbuilt_t bi_func[] = {
		{"cd", dirxchange},
		{"pwd", print_pwd},
		{"env", env_print},
		{NULL, NULL}
	};
	int x = 0, t = 0;

	while (bi_func[x].comd != NULL)
	{
		if (xtrcomp(comd, bi_func[x].comd) != t)
			x++;
		else
			return (bi_func[x].action);
	}
	return (NULL);
}

/**
 * xtrcat - A function that concatenates a string to another
 * @str1: the string to be increased
 * @str2: contents will be added to str1 end
 * Return: str1 on success
 */
char *xtrcat(char *str1, char *str2)
{
	int x, j = 0;

	if (str2 == NULL)
		return (str1);
	for (x = (xtrlent(str1)); str2[j] != '\0'; x++)
	{
		str1[x] = str2[j];
		j++;
	}
	str1[x] = '\0';
	return (str1);
}

/**
 * tokexe - A function that breaks a string down to individual tokens
 * @str: The string
 * @rec: The number of tokens
 * @args: The string array where the string tokens will be stored
 * Return: The string array
 */
char **tokexe(char *str, int rec, char **args)
{
	char *strtok = NULL;
	int x = 0, y = 0;

	if (str == NULL || args == NULL)
		return (NULL);
	strtok = tokxtr(str, " \n");
	for (x = y; x < rec; x++)
	{
		args[x] = malloc(sizeof(char) * (xtrlent(strtok)));
		if (args[x] == NULL)
			return (NULL);
		xtrcopy(strtok, args[x]);
		strtok = tokxtr(NULL, " \n");
	}
	args[x] = NULL;
	return (args);
}

/**
 * _putchar -function that prints one character at a time to
 * standard output
 * @c: The character to put
 * Return: 1 on success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
