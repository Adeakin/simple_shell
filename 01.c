#include "main.h"


/**
 * main - The intance, a function for Simple shell 0.1
 *
 * Return: void
 */
int main(void)
{
	int exit_code;

	while (1)
	{
		pid_t id = fork();
		char *line = NULL, *tok, **argv = malloc(sizeof(char *));
		size_t n = 0;
		ssize_t the_getline;
		int i = 0;

		if (id == 0)
		{
			_printf(">> ");
			the_getline = getline(&line, &n, stdin);
			if (the_getline == -1)
			{
				_printf("Exiting shell...\n");
				free(line);
				exit(4);
			}

			char **tokenised = tokenisation(line, " \t\n");		
			
			execve(tokenised[0], tokenised, NULL);
			perror("Execv failed: ");
		}
		else
		{
			wait(&exit_code);
			if (WEXITSTATUS(exit_code) == 4)
				exit(4);
		}
	}
	return (0);
}
