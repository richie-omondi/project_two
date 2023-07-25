#include "shell.h"

/**
 * exit_shell - A function that exits the shell
 * @shell: A data struct storing shell input
 *
 * Return: Void
 */
void exit_shell(shell_data *shell)
{
	int status;
	free_shell_data(shell);

	while (wait(&status) > 0)
		;
	exit(0);
}
