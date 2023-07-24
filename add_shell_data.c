#include "shell.h"

/**
 * add_data_to_shell - adds data to the shell
 * @shell: pointer to the struct
 * @ac: number of arguments
 * @av: array of strings as arguments
 *
 * Return: void
 */
void add_data_to_shell(shell_data *shell, int ac, char **av)
{
	shell->env = environ;
	shell->exe = av[0];
	shell->input = NULL;
	shell->command = NULL;
	shell->tokens = NULL;
	shell->no_of_executions = 0;

	if (ac == 1)
		shell->fd = STDIN_FILENO;
	else
	{
		shell->fd = open(av[1], O_RDONLY);
		if (shell->fd == -1)
		{
			perror(shell->exe);
			exit(127);
		}
	}

	if (shell->env == NULL)
		exit(127);
}
