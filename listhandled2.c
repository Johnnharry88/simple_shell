#include "shell.h"

/**
 * endnodevaradd - function that a variable at the end of a v_list.
 * @head: head of the v_list.
 * @a: variable length
 * @let: variable value.
 * @z: value length
 * Return: address of head added
 */
v_list *endnodevaradd(v_list **head, int a, char *let, int z)
{
	v_list *f_store;
	v_list *ram;

	f_store = malloc(sizeof(v_list));
	if (f_store == NULL)
		return (NULL);

	f_store->first = a;
	f_store->alpha = let;
	f_store->len = z;

	f_store->next = NULL;
	ram = *head;

	if (ram == NULL)
	{
		*head = f_store;
	}
	else
	{
		while (ram->next != NULL)
			ram = ram->next;
		ram->next = f_store;
	}

	return (*head);
}

/**
 * v_listfree - function that frees a v_list
 * @head: head of the v_list.
 * Return: void.
 */
void v_listfree(v_list **head)
{
	v_list *t;
	v_list *x;

	if (head != NULL)
	{
		x = *head;
		while ((t = x) != NULL)
		{
			x = x->next;
			free(t);
		}
		*head = NULL;
	}
}
