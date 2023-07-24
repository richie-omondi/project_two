#include "shell.h"

/**
 * print_e - prints errors
 * @string: pointer to a string
 *
 * Return: number of bytes written
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_e(char *string)
{
	return (write(STDERR_FILENO, string, str_len(string)));
}

/**
 * print_error - prints different errors
 * @shell: data fed to the shell
 * @error: error to be printed
 *
 * Return: number of bytes written
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_error(int error, shell_data *shell)
{
	char *string = NULL;

	string = _itoa(shell->no_of_executions);

	if (error == 127)
	{
		print_e(shell->exe);
		print_e(": ");
		print_e(string);
		print_e(": ");
		print_e(shell->command);
		print_e(": not found\n");
	}
	if (error == 126)
	{
		print_e(shell->exe);
		print_e(": ");
		print_e(string);
		print_e(": ");
		print_e(shell->command);
		print_e(": Permission denied\n");
	}
	return (0);
}
