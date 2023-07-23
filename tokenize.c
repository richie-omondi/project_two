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
	char **path_tokens = NULL, *path = NULL, *token_path = NULL, **temp = NULL;
	char *delimiter = ":";

	int buffer_size = BUFFER_SIZE, i, j = 0;

	path = get_env_value("PATH", shell);

	if (path == NULL)
		return (NULL);

	token_path = strtok(path, delimiter);

	path_tokens = _calloc(100, buffer_size * sizeof(char *));
	if (path_tokens == NULL)
	{
		perror("Memory allocation failure");
		exit(EXIT_FAILURE);
	}
	while (token_path != NULL)
	{
		path_tokens[j] = token_path;
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
		
		token_path = strtok(NULL, delimiter);
	}
	path_tokens[j] = NULL;
	return (path_tokens);
}
