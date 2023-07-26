#include "shell.h"

/**
 * execute_commands - executes the commands passed to the shell
 * @shell: struct containing data fed to the shell
 *
 * Return: 0 on success
 */
int execute_commands(shell_data *shell)
{
	pid_t child_pid;
	int status, code = 0;

	char *path = NULL;

	code = is_exe(shell);
	if (code == -1)
		return (1);
	if (code == 0)
	{
		path = handle_path(shell);
		if (check_execute_permissions(path, shell) == 1)
			return (1);
	}

	child_pid = fork();
	if (child_pid == 0)
	{
		if (code == 0)
			path = handle_path(shell);
		else
			path = shell->tokens[0];
		execve(path + code, shell->tokens, shell->env);
	}
	else if (child_pid < 0)
	{
		perror(shell->exe);
		return (1);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			errno = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			errno = 128 + WTERMSIG(status);
	}
	return (1);
}
