#include "shell.h"

/**
 * exit_shell - exit built-in
 * @shell: struct containing data fed to the shell
 *
 * Return: 0 on success
 */
int exit_shell(shell_data *shell)
{
	int i = 0;

	if (shell->tokens[1] != NULL)
	{
		for (i = 0; i < str_len(shell->tokens[1]); i++)
		{
			if (!is_digit(shell->tokens[1][i]) && shell->tokens[1][i] != '+')
			{
				errno = 2;
				return (2);
			}
		}
		errno = _atoi(shell->tokens[1]);
	}
	free_shell_data(shell);
	exit(errno);
}
