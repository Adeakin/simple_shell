#include "main.h"



/**
 * main - The entry point of the simple shell programm.
 *
 * Return: 0 on success.
 */
int main(void)
{
	while (1)
	{
		char **argv, **tokenised, **env;

		print_prompt();

		tokenised = read_and_tokenise();

		if (tokenised == NULL)
			continue;

		argv = execute_prompt(tokenised);

		free_ptr2ptr(argv);

		if (!(isatty(STDIN_FILENO)))
		{
			printf("\nEnvironment:\n");
			for (env = environ; *env != NULL; env++)
				printf("%s\n", *env);
		}
	}

	return (0);
}
