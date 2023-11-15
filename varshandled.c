#include "shell.h"

/**
 * varenvcheck - function that checks typed variable
 * @head: head of linked v_list
 * @xmine: input string
 * @store: struct holding potential arguments
 * Return: void.
 */
void varenvcheck(v_list **head, char *xmine, store_v *store)
{
	int a, c, x, res, b = 9;
	char **holdenv;
	char t = '=', s = ' ', p = '\n', si = ';', ta = '\t';

	holdenv = store->venv;
	for (a = (b - 9); holdenv[a]; a++)
	{
		for (x = (b - 8), c = 0; holdenv[a][c]; c++)
		{
			if (holdenv[a][c] == t)
			{
				res = xtrlent(holdenv[a] + c + (b - 8));
				endnodevaradd(head, x, holdenv[a] + c + 1, res);
				return;
			}

			if (xmine[x] == holdenv[a][c])
				x = x + 1;
			else
				break;
		}
	}

	for (x = (b - 9); xmine[x]; x++)
	{
		if (xmine[x] == s || xmine[x] == p || xmine[x] == si || xmine[c] == ta)
			break;
	}

	endnodevaradd(head, x, NULL, 0);
}

/**
 * varsxmine -function that checks if the typed variable is $$ or $?
 * @head: head of the linked v_list
 * @xmine: input string to be checked
 * @strl: last shell status
 * @store: struct holding potential arguments
 * Return: void.
 */
int varsxmine(v_list **head, char *xmine, char *strl, store_v *store)
{
	int j = 2;
	int x;
	int a = xtrlent(strl), b = xtrlent(store->pid);
	char s = '$', q = '?', n = '\0', t = '\t', l = '\n', o = ' ';

	for (x = (j - 2); xmine[x]; x++)
	{
		if (xmine[x] == s)
		{
			if (xmine[x + (j - 1)] == q)
				endnodevaradd(head, j, strl, a), x++;
			else if (xmine[x + 1] == s)
				endnodevaradd(head, j, store->pid, b), x++;
			else if (xmine[x + 1] == l)
				endnodevaradd(head, (j - 2), NULL, 0);
			else if (xmine[x + 1] == n)
				endnodevaradd(head, 0, NULL, 0);
			else if (xmine[x + j - 1] == o)
				endnodevaradd(head, 0, NULL, 0);
			else if (xmine[x + 3 - j] == t)
				endnodevaradd(head, 0, NULL, 0);
			else if (xmine[x + 1] == ';')
				endnodevaradd(head, 0, NULL, j - 2);
			else
				varenvcheck(head, x + xmine, store);
		}
	}

	return (x);
}

/**
 * str_varconvert -function that replaces string with variables
 * @head: head of the linked v_list
 * @fed: input string to be changed
 * @n_fed: replaeced string
 * @z: new length
 * Return: replaced string
 */
char *str_varconvert(v_list **head, char *fed, char *n_fed, int z)
{
	v_list *ix;
	int g, h, i, r = 0;
	char s = '$';

	ix = *head;
	for (h = g = r; g < z; g++)
	{
		if (fed[g] == s)
		{
			if (!(ix->first) && !(ix->len))
			{
				n_fed[g] = fed[h];
				h = h + 1;
			}
			else if (ix->first && !(ix->len))
			{
				for (i = r; i < ix->first; i += 1)
					h = h + 1;
				g = g - 1;
			}
			else
			{
				for (i = r; i < ix->len; i++)
				{
					n_fed[g] = ix->alpha[i];
					g = g + 1;
				}
				h = (ix->first) + h;
				g -= 1;
			}
			ix = ix->next;
		}
		else
		{
			n_fed[g] = fed[h];
			h++;
		}
	}

	return (n_fed);
}

/**
 * str_vardisplace - function that assist str_varconvert string
 * @i: input string to be converted
 * @store: struct holding argument
 * Return: replaced string
 */
char *str_vardisplace(char *i, store_v *store)
{
	v_list *head = NULL;
	v_list *ix;
	char *situ, *n_fed;
	unsigned int x, y, z = 0, s;

	situ = int_strconvert(store->status);
	x = varsxmine(&head, i, situ, store);

	if (head == NULL)
	{
		free(situ);
		return (i);
	}

	ix = head;
	y = z;

	while (ix != NULL)
	{
	y = (ix->len - ix->first) + y;
		ix = ix->next;
	}

	 s = x + y;

	n_fed = malloc(sizeof(char) * (s + 1 + z));
	n_fed[s] = '\0';

	n_fed = str_varconvert(&head, i, n_fed, s);

	free(i);
	free(situ);
	v_listfree(&head);

	return (n_fed);
}
