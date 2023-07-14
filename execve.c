#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "shell.h"

/**
 * execute_cmd - Executes a read command
 * @command: The input command to be read
 * @argv: Array of arguments to be passed
 *
 * Return: NULL
 */

void execute_cmd(char *command, char *argv[])
{
	if (execve(command, argv, NULL) == -1)
	{
		perror("Execution error\n");
		exit(EXIT_FAILURE);
	}
	free(command);
}
