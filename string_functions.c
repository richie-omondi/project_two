#include "shell.h"

/**
 * str_len - checks the length of a string
 * @string: pointer to string to check
 *
 * Return: int length of the string
 */

int str_len(char *string)
{
	int len = 0;

	while (*(string + len))
		len++;
	return (len);
}

