#include "main.h"

/**
 * execute_prompt - Executes the procesed prompt using execve
 * @argv: Tokenised input which is now packed inside a double pointer;
 *
 * Return: The double pointer argv(contains the tokenised user input)
 */
char **execute_prompt(char **argv)
{
	int status;
	char **path_value, *init_path;
	pid_t child;

	path_value = tokenise_env_val("PATH");
	init_path = pather(path_value, argv[0]);
	if (init_path == NULL)
	{
		perror("./hsh");
		free(init_path);
		return (argv);
	}
	child = fork();

	if (child == 0)
	{
		argv[0] = init_path;
		execve(argv[0], argv, environ);
		perror("Failed to execute");
	}
	else if (child == -1)
	{
		perror("Failed to create child");
	}
	else
	{
		wait(&status);
	}
	free(init_path);
	return (argv);
}


/**
 * tokenise_env_val - Function to tokenise the environ passed key.
 * @wanted_key: The environ key to be tokenised.
 *
 * Return: The key values packed into a double pointer(**token_array).
 */
char **tokenise_env_val(char *wanted_key)
{
	int i, count = 0;
	char *key, *wanted_part, *wanted_part_cpy, *token, **token_array,
	**environ_copy;

	while (environ[count])
		count++;
	environ_copy = malloc(sizeof(char *) * (count + 1));
	for (i = 0; environ[i]; i++)
		environ_copy[i] = strdup(environ[i]);
	environ_copy[i] = NULL;
	i = 0;
	while (environ_copy[i])
	{
		key = strtok(environ_copy[i], "=");
		if (strcmp(key, wanted_key) == 0)
		{
			wanted_part = strdup(strtok(NULL, "\n"));
			free_ptr2ptr(environ_copy);
			break;
		}
		i++;
	}
	wanted_part_cpy = strdup(wanted_part);
	token = strtok(wanted_part_cpy, ":");
	for (count = 0; token; count++)
		token = strtok(NULL, ":");

	token_array = malloc(sizeof(char *) * (count + 1));
	token = strtok(wanted_part, ":");
	for (i = 0; token; i++)
	{
		token_array[i] = malloc((sizeof(char) * strlen(token)) + 1);
		strcpy(token_array[i], token);
		token = strtok(NULL, ":");
	}
	token_array[i] = NULL;
	free(wanted_part);
	free(wanted_part_cpy);
	return (token_array);
}


/**
 * pather - The function to find the actual executable path of passed cmd.
 * @token_array: The tokenised environ PATH values.
 * @prompt_input: The inputed cmd(example; ls,pwd).
 *
 * Return: The actual path that can be executed if not, return NULL.
 */
char *pather(char **token_array, char *prompt_input)
{
	int i = 0;
	char *path;
	struct stat stat_storage;

	while (token_array[i])
	{
		path = malloc(strlen(token_array[i]) + strlen(prompt_input) + 2);
		strcat(path, token_array[i]);
		strcat(path, "/");
		strcat(path, prompt_input);
		if (stat(path, &stat_storage) == 0)
		{
			free_ptr2ptr(token_array);
			return (path);
		}
		free(path);
		i++;
	}
	if (stat(prompt_input, &stat_storage) == 0)
	{
		free_ptr2ptr(token_array);
		path = strdup(prompt_input);
		return (path);
	}
	free_ptr2ptr(token_array);
	return (NULL);
}
