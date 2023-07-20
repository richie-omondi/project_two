#include "shell.h"

/**
 * find_executable - Searches for an executable file
 * in the path
 * @path_tokens: Tokenized PATH directories
 * @shell: Pointer to data inputted containing the command
 * typed
 *
 * Return: A string representing the full path of the executable
 * if it exists or NULL if not found
 */

char *find_executable(char **path_tokens, shell_data *shell)
{
	char *full_path;

	int i;

	path_tokens = tokenize_path(&shell);
	for (i = 0; path_tokens[i] != NULL; i++)
	{
		full_path = malloc(str_len(path_tokens[i]) + str_len(shell->command));
		if (full_path == NULL)
		{
			perror("Memory allocation failure");
			exit(EXIT_FAILURE);
		}

		str_cpy(full_path, path_tokens[i]);
		str_cat(full_path, "/");
		str_cat(full_path, shell->command);

		if (check_file(full_path) == 0)
			return (full_path);

		free(full_path);
	}

	return (NULL);
}
