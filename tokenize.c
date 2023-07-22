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
	char **path_tokens = NULL, *path, *token_path, **temp;
	char *delimiter = ":";

	int buffer_size = BUFFER_SIZE, i, j = 0;

	path = get_env_value("PATH", shell);

	if (path == NULL)
		return (NULL);

	token_path = strtok(path, delimiter);

	path_tokens = malloc(buffer_size * sizeof(char *));
	if (path_tokens == NULL)
	{
		perror("Memory allocation failure");
		exit(EXIT_FAILURE);
	}
	while (token_path != NULL)
	{
		path_tokens[j] = str_dup(token_path);
		token_path = strtok(NULL, delimiter);
		j++;
		if (j >= buffer_size)
		{
			buffer_size *= 2;
			temp = malloc(buffer_size * sizeof(char *));
			if (temp == NULL)
			{
				perror("Allocation failure");
				exit(EXIT_FAILURE);
			}
			for (i = 0; i < j; i++)
				temp[i] = path_tokens[i];
			path_tokens = temp;
		}
	}
	path_tokens[j] = NULL;
	return (path_tokens);
}
