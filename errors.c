#include "shell.h"

/**
 * print_e - writes an array of chars to the standard error
 * @string: pointer to the array of chars
 *
 * Return: the number of bytes written
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_e(char *string)
{
	return (write(STDERR_FILENO, string, str_length(string)));
}
