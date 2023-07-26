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
	int i = 0;

	shell->exe = av[0];
	shell->input = NULL;
	shell->command = NULL;
	shell->tokens = NULL;
	shell->no_of_executions = 0;

	for (i = 0; environ[i]; i++)
		;

	shell->env = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		shell->env[i] = str_dup(environ[i]);
	}

	shell->env[i] = NULL;

	if (shell->env == NULL)
		exit(127);

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
}
