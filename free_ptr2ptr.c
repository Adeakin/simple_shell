#include "main.h"


void free_ptr2ptr(char **argv)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
		free(argv[i]);
	free(argv);
}
