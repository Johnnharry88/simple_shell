#include "shell.h"
/**
 * mem_free - function thatcleans up the memory allocated
 * @c_cache: the memory to free
 * Return: void
 */
void mem_free(char *c_cache)
{
	free(c_cache);
}
