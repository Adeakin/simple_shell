#include "main.h"


/**
 * free_ptr2ptr - Free the passed mallocated double pointer.
 * @argv: The mallocated double pointer to be freed.
 *
 * Return: void
 */
void free_ptr2ptr(char **argv)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
		free(argv[i]);
	free(argv);
}
