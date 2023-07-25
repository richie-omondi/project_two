#include "shell.h"

/**
 * exit_shell - exits the shell
 * @shell: data fed to the shell
 *
 * Return: 0 on failure, 1 on success
 */
int exit_shell(shell_data *shell)
{
	if (shell->tokens[1] != NULL)
		exit(_atoi(shell->tokens[1]));
	else
		return (EXIT_CODE);
}
