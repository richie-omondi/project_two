#include "shell.h"

/**
 * check_path - checks if the current path is searchable
 * @path: pointer to the path
 *
 * Return: 1 if found, 0 if not
 */
int check_path(char *path)
{
	int i = 0;
	int found_colon = 0;

	while (path[i])
	{
		if (path[i] == ':')
		{
			found_colon = 1;
			break;
		}
		i++;
	}

	if (found_colon)
		return (1);
	else
		return (0);
}

/**
 * handle_path - Function that splits path variables
 * to individual strings
 * @shell: Struct containing data fed to the shell
 *
 * Return: A string representing tokenized path variables
 */

char *handle_path(shell_data *shell)
{
	struct stat sb;

	char *path_tokens = NULL, *path = NULL, *tokens = NULL,
	     *path_copy = NULL, *delimiter = ":";
	int buffer_size = BUFFER_SIZE;

	path = get_env_value("PATH", shell);
	if (path == NULL)
		return (NULL);
	else
	{
		path_copy = str_dup(path);
		tokens = strtok(path_copy, delimiter);
		while (tokens != NULL)
		{
			if (check_path(path))
			{
				if (stat(shell->command, &sb) == 0)
					return (shell->command);
			}
			path_tokens = _calloc(100, buffer_size * sizeof(char *));
			if (path_tokens == NULL)
			{
				perror("Path tokens malloc failure");
				exit(EXIT_FAILURE);
			}
			str_cpy(path_tokens, tokens);
			str_cat(path_tokens, "/");
			str_cat(path_tokens, shell->command);
			str_cat(path_tokens, "\0");

			if (stat(path_tokens, &sb) == 0)
			{
				free(path_copy);
					return (path_tokens);
			}
			free(path_tokens);
			tokens = strtok(NULL, delimiter);
		}
		free(path_copy);

		if (stat(shell->command, &sb) == 0)
			return (shell->command);
		return (NULL);
	}
	if (shell->command[0] == '/')
	{
		if (stat(shell->command, &sb) == 0)
			return (shell->command);
	}
	return (NULL);
}

/**
 * is_cmd - checks if the file is an executable
 * @shell: data fed to the shell
 *
 * Return: 0
 */
int is_cmd(shell_data *shell)
{
	struct stat sb;
	int j = 0;
	char *cmd = NULL;

	cmd = shell->tokens[0];
	for (j = 0; cmd[j]; j++)
	{
		if (cmd[j] == '.')
		{
			if (cmd[j + 1] == '.')
				return (0);
			if (cmd[j + 1] == '/')
				continue;
			else
				break;
		}
		else if (cmd[j] == '/' && j != 0)
		{
			if (cmd[j + 1] == '.')
				continue;
			j++;
			break;
		}
		else
			break;
	}
	if (j == 0)
		return (0);

	if (stat(cmd + j, &sb) == 0)
	{
		return (j);
	}
	print_error(127, shell);
	return (-1);
}

/**
 * check_execute_permissions - chec if user can execute file
 * @path: path to check
 * @shell: data fed to the shell
 *
 * Return: 1 if there is an error, 0 if not
 */
int check_execute_permissions(char *path, shell_data *shell)
{
	if (path == NULL)
	{
		print_error(127, shell);
		return (1);
	}

	if (str_cmp(shell->tokens[0], path) != 0)
	{
		if (access(path, X_OK) == -1)
		{
			print_error(126, shell);
			free(path);
			return (1);
		}
		free(path);
	}
	else
	{
		if (access(shell->tokens[0], X_OK) == -1)
		{
			print_error(126, shell);
			return (1);
		}
	}

	return (0);
}
