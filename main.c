#include "shell.h"
/**
 * main - Entry point of shell program
 * @ac: argument count
 * @av: argument vector
 * Return: 0 if Success..
 */
int main(int ac, char **av)
{
	store_v store;
	(void) ac;

	signal(SIGINT, _signinteg);
	datareset(&store, av);
	hshloop(&store);
	free_store(&store);
	if (store.status < 0)
		return (255);
	return (store.status);
}
