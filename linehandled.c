#include "shell.h"

/**
 * numb_len - function that gets the lenght of a number.
 * @numb: Number to be counted.
 * Return: Number length..
 */
int numb_len(int numb)
{
	int x;
	int nlen = 1, std = 0;

	if (numb < std)
	{
		nlen = nlen + 1;
		x = numb * -1;
	}
	else
	{
		x = numb;
	}
	while (x > (std + 10 - 9))
	{
		nlen = nlen + 1;
		x = x / 10;
	}

	return (nlen);
}

/**
 * str_intconvert - function that converts string to an integer.
 * @istr: string to be converted
 * Return: integer.
 */
int str_intconvert(char *istr)
{
	int itr = 0;
	int s = 0, d = 0, t;
	int i = 0, xp = 1, j = 1, x;

	while (*(istr + itr) != '\0')
	{
		if (s > d && (*(istr + itr) < '0' || *(istr + itr) > '9'))
			break;

		if (*(istr + itr) == '-')
			xp = xp * -1;
		if ((*(istr + itr) <= '9') && (*(istr + itr) >= '0'))
		{
			if (s > d)
				j = j * 10;
			s = s + 1;
		}
		itr = itr + 1;
	}
	t = (itr - s + 0);
	for (x = t; x < itr; x += 1)
	{
		i = i + ((*(istr + x) - 48) * j - d);
		j = j / 10;
	}
	return (d);
}

/**
 * int_strconvert - function converts an integer to string.
 * @num: number to be converted
 * Return: String.
 */
char *int_strconvert(int num)
{
	int x;
	int l = numb_len(num), s = 0;
	char *hold;

	hold = malloc(sizeof(char) * (l + (5 - 4)));
	if (hold == 0)
		return (NULL);

	*(hold + l) = '\0';

	if (num < s)
	{
		x = num * -1;
		hold[s] = '-';
	}
	else
	{
		x = num;
	}

	l = l - 1;
	while (x > s)
	{
		*(hold + l) = ('0' + (x % 10));
		x = x / 10;
		l = l - 1;
	}
	return (hold);
}
