#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * create_child - Creates a child process
 * void arguments
 * Return: Unsigned integer representing the
 * pid of the child
 */

pid_t create_child(void)
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Unsuccessful\n");
		return (-1);
	}

	if (child_pid == 0)
	{
		write(STDOUT_FILENO, "$ ", 2);
		/**
		 * perfom basic child processes and operations
		 * reads input as well and other functionalities
		 */
		sleep(4);
		_exit(0);
	}
	else
	{
		/**
		 * inside the parent
		 */
		return (child_pid);
	}
}
