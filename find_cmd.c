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
	char **path_tokens = NULL;
	int i = 0, retval = 0;

	if (!shell->command)
		return (2);

	if (shell->command[0] == '/' || shell->command[0] == '.')
		return (check_file(shell->command));

	shell->tokens[0] = str_concat(str_dup("/"), shell->command);

	if (!shell->tokens[0])
		return (2);

	path_tokens = tokenize_path(shell);
	if (!path_tokens || !path_tokens[0])
	{
		errno = 127;
		return (127);
	}

	for (i = 0; path_tokens[i] != NULL; i++)
	{
		path_tokens[i] = str_cat(path_tokens[i], shell->tokens[0]);

		retval = check_file(path_tokens[i]);
		if (retval == 0 || retval == 126)
		{
			errno = 0;
			free(shell->tokens[0]);
			shell->tokens[0] = str_dup(path_tokens[i]);
			return (retval);
		}
	}
	free(path_tokens);
	return (retval);
}
