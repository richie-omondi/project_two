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
	if (shell->fd != 0)
		close(shell->fd);
	if (shell->tokens != NULL)
		free(shell->tokens);
	if (shell->input != NULL)
		free(shell->input);
	if (shell->command != NULL)
		free(shell->command);
	shell->tokens = NULL;
	shell->input = NULL;
	shell->command = NULL;
}
