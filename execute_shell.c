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
	int status, retval = 0;

	retval = find_executable(shell);

	if (retval)
		return (retval);
	else
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Forking error");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
		retval = execve(shell->tokens[0], shell->tokens, shell->env);

			if (retval == -1)
			{
				perror("./hsh");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
		return (0);
}
