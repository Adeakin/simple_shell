#include "main.h"


/**
 * read_and_tokenise - Read and tokenis the input.
 *
 * Return: Tokenised input packed into a double pointer.
 */
char **read_and_tokenise()
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t read_length;

	read_length = getline(&buffer, &buffer_size, stdin);
	if (read_length == -1)
	{
		free(buffer);
		perror("Failed to read input");
		exit(EXIT_FAILURE);
	}
	if (read_length == 1)
		return (NULL);
	return (tokenise_prompt(buffer, " \t\n"));
}
