#include "shell.h"

/**
 * free_shell_data - frees the respective fields from
 * the shell_data struct
 * @shell: shell_data struct containing data fed to the shell
 *
 * Return: void
 */
void free_shell_data(shell_data *shell)
{
	int i = 0;

	if (shell->fd != 0)
		close(shell->fd);

	if (shell->tokens)
	{
		for (i = 0; shell->tokens[i]; i++)
			free(shell->tokens[i]);
		free(shell->tokens);
	}

	for (i = 0; shell->env[i]; i++)
		free(shell->env[i]);
	free(shell->env);

	free(shell->input);

	shell->input = NULL;
}

/**
 * free_without_input - frees the respective fields from
 * the shell_data struct without freeing input
 * @shell: shell_data struct containing data fed to the shell
 *
 * Return: void
 */
void free_without_input(shell_data *shell)
{
	int i = 0;

	if (shell->fd != 0)
		close(shell->fd);

	if (shell->tokens)
	{
		if (!(shell->input))
			free(shell->tokens);
	}
	for (i = 0; shell->env[i]; i++)
		free(shell->env[i]);
	free(shell->env);
}
