#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "shell.h"

/**
 * create_child - Creates a child process
 * void arguments
 * Return: Unsigned integer representing the
 * pid of the child
 */

pid_t create_child(void)
{
	pid_t child_pid;

	int status;

	char command[100];

	char *input;

	char **argv = (char **)malloc(sizeof(char *) * 2);

	argv[0] = command;
	argv[1] = NULL;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Unsuccessful\n");
		return (-1);
	}

	if (child_pid == 0)
	{
		write(STDOUT_FILENO, "$ ", 2);
		/****** Reading inputs using getline ******/
		input = read_input();
		execute_cmd(argv[0], argv);
		free(argv);
		free(input);
		_exit(EXIT_SUCCESS);
	}
	else
	{
		wait(&status);
		return (child_pid);
	}
}
