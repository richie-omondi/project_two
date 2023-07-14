/**
 * execute_commands - executes the commands passed to the shell
 * @args: tokenized arguments
 *
 * Return: 0 on success
 */
int execute_shell(char **args)
{
	pid_t child_pid;
	int status;
	int code = 0;

	child_pid = fork();
	
	if (child_pid == -1)
	{
		perror("Forking error");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		code = execve(args[0], args, NULL);

		if (code == -1)
		{
			perror("Execution error\n");
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
