#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


/**
 * main - The intance, a function for Simple shell 0.1
 *
 * Return: void
 */
int main(void)
{
	int status;

	while (1)
	{
		pid_t id = fork();
		char *line = NULL, *tok;
		size_t n = 0;
		ssize_t the_getline;
		int i = 0;
		char **argv = malloc(sizeof(char *));

		if (id == 0)
		{
			printf(">> ");
			the_getline = getline(&line, &n, stdin);
			if (the_getline == -1)
			{
				printf("Exiting shell...\n");
				free(line);
				exit(-5);
			}
			tok = strtok(line, " \n");
			while (tok)
			{
				argv[i] = tok;
				tok = strtok(NULL, " \n");
				i++;
			}
			argv[i] = NULL;
			execve(argv[0], argv, NULL);
			perror("Execv failed: ");
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
