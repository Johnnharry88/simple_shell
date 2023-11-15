#include "shell.h"

/**
 * endnodesepadd - function that adds (;, |, &) found at the end of x_list.
 * @head: head of the x_list.
 * @x: dividers (; | &).
 * Return: address of the head addded..
 */
x_list *endnodesepadd(x_list **head, char x)
{
	x_list *f_store;
	x_list *ram;

	f_store = malloc(sizeof(x_list));
	if (f_store == NULL)
		return (NULL);

	f_store->wall = x;
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
 * endnodelineadd - function that command line at the end of l_list.
 * @head: head of the l_list.
 * @comd: command line passed.
 * Return: address of the head added.
 */
l_list *endnodelineadd(l_list **head, char *comd)
{
	l_list *fx;
	l_list *ram;

	fx = malloc(sizeof(x_list));
	if (fx == NULL)
		return (NULL);

	fx->fedline = comd;
	fx->next = NULL;
	ram = *head;

	if (ram == NULL)
	{
		*head = fx;
	}
	else
	{
		while (ram->next != NULL)
			ram = ram->next;
		ram->next = fx;
	}

	return (*head);
}

/**
 * l_listfree - function that frees l_list
 * @head: head of the l_list.
 * Return: void.
 */
void l_listfree(l_list **head)
{
	l_list *t;
	l_list *s;

	if (head != NULL)
	{
		s = *head;
		while ((t = s) != NULL)
		{
			s = s->next;
			free(t);
		}
		*head = NULL;
	}
}


/**
 * x_listfree - function that frees a x_list
 * @head: head of the x_list.
 * Return: void.
 */
void x_listfree(x_list **head)
{
	x_list *ram;
	x_list *s;

	if (head != NULL)
	{
		s = *head;
		while ((ram = s) != NULL)
		{
			s = s->next;
			free(ram);
		}
		*head = NULL;
	}
}
