#include "shell.h"

/**
 * find_executable - Searches for an executable file
 * in the path
 * @shell: Pointer to data inputted containing the command
 * typed
 *
 * Return: A string representing the full path of the executable
 * if it exists or NULL if not found
 */

int find_executable(shell_data *shell)
{
	char *full_path;
	char **path_tokens;
	int i, retval = 0;

	if (!shell->command)
		return (2);

	if (shell->command[0] == '/' || shell->command[0] == '.')
		return (check_file(shell->command));
	
	path_tokens = tokenize_path(shell);
	if (!path_tokens || !path_tokens[0])
	{
		errno = 127;
		return (127);
	}

	for (i = 0; path_tokens[i] != NULL; i++)
	{
		full_path = malloc(str_len(path_tokens[i]) + str_len(shell->command + 2));
		if (full_path == NULL)
		{
			perror("Memory allocation failure");
			exit(EXIT_FAILURE);
		}

		str_cpy(full_path, path_tokens[i]);
		str_cat(full_path, "/");
		str_cat(full_path, shell->command);

		retval = check_file(full_path);
		if (retval == 0 || retval == 126)
			return (retval);
	}
	free(full_path);
	free(path_tokens);
	return (retval);
}
