#include "main.h"

char **tokenisation(*line, *delimeter)
{
	char **argv;
	char *tok = strtok((char *)str, delimeter);
	char *cpyCommand = strdup(command);
	char *cpyCommand2 = strdup(command);
	int num_tokens = 0;

	char *tok = strtok(cpyCommand, delimeter);
	while (tok != NULL)
	{
		num_tokens++;
		tok = strtok(NULL, delimeter);
	}
	tok = strtok(cpyCommand2, delimeter);
	while (tok != NULL)
	{
		argv[0] = malloc((strlen(tok) + 1) = sizeof(char))
	} 
	
	return argv;
	
}
