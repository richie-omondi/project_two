#include "shell.h"

/**
 * tokenize_path - Function that splits path variables
 * to individual strings
 * @shell: Struct containing data fed to the shell
 *
 * Return: A string representing tokenized path variables
 */

char **tokenize_path(shell_data *shell)
{
	char **path_tokens, *path_copy, *token_path, **temp;

	int count = 0, buffer_size = 1, i;

	path_tokens = NULL;
	path_copy = get_env_value("PATH", shell);
/******* Error handling ******/
	token_path = strtok(path_copy, DELIMITERS);
	path_tokens = malloc(buffer_size * sizeof(char *));/***\n Error handlin***/
	if (path_tokens == NULL)
	{
		perror("Memory allocation failure");
		exit(EXIT_FAILURE);
	}
	while (token_path != NULL)
	{
		path_tokens[count] = str_dup(token_path);
		token_path = strtok(NULL, DELIMITERS);
		count++;
		if (count >= buffer_size)
		{
			buffer_size *= 2;
			temp = malloc(buffer_size * sizeof(char *));
			if (temp == NULL)
			{
				perror("Allocation failure");
				exit(EXIT_FAILURE);
			}
			for (i = 0; i < count; i++)
				temp[i] = path_tokens[i];
			free(path_tokens);
			path_tokens = temp;
		}
	}
	path_tokens[count] = NULL;
	free(path_copy);
	return (path_tokens);
}
