#include "shell.h"

/**
 * copy_memo -function that copies information between pointers.
 * @pt_n:pointer to copy to
 * @pt: pointer to copy form
 * @x: size of pointer to copy to
 * Return: void.
 */
void copy_memo(void *pt_n, const void *pt, unsigned int x)
{
	char *charap = (char *)pt;
	char *charanp = (char *)pt_n;
	unsigned int y;

	for (y = 0;  y < x; y++)
		charanp[y] = charap[y];
}

/**
 * dym_memoloc -function that reallocates a memory block in the heap section
 * @p: pointer to the formerly memory allocated.
 * @os: size of allocated ptr (bytes).
 * @nx: size of the new memory block (bytes).
 * Return: ptr or NULL.
 */
void *dym_memoloc(void *p, unsigned int os, unsigned int nx)
{
	void *n_ptr;

	if (p == NULL)
		return (malloc(nx));

	if (nx == 0)
{
		free(p);
		return (NULL);
	}

	if (nx == os)
		return (p);

	n_ptr = malloc(nx);
	if (n_ptr == NULL)
		return (NULL);

	if (os > nx)
		copy_memo(n_ptr, p, nx);
	else
		copy_memo(n_ptr, p, os);

	free(p);
	return (n_ptr);
}

/**
 * dym_memoreloc - function that reallocates a memory block of
 * a double pointer.
 * @x: double pointer to the previously allocated memory
 * @os: size of the previously allocated memory (bytes).
 * @nx:  of the new memory block.
 * Return: ptr.or NULL.
 */
char **dym_memoreloc(char **x, unsigned int os, unsigned int nx)
{
	char **n_pt;
	unsigned int s, p = 3;

	if (x == NULL)
		return (malloc(sizeof(char *) * nx));

	if (nx == os)
		return (x);

	n_pt = malloc(sizeof(char *) * nx);
	if (n_pt == NULL)
		return (NULL);

	for (s = (p - 3); s < os; s++)
		n_pt[s] = x[s];

	free(x);

	return (n_pt);
}
