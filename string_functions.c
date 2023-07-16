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

/**
 * str_dup - Returns a pointer to a newly-allocated space in memory
 * containing a copy of the string given as parameter.
 * @string: The string to be copied.
 *
 * Return: If str == NULL or insufficient memory is available - NULL.
 * Otherwise - a pointer to the duplicated string.
 */
char *str_dup(char *string)
{
	int i = 0;
	int length = 0;
	char *dup = NULL;

	if (string == NULL)
		return (NULL);

	for (i = 0; *(string + i); i++)
		length++;

	dup = malloc(sizeof(char) * (length + 1));

	if (dup == NULL)
		return (NULL);

	for (i = 0; *(string + i); i++)
		*(dup + i) = *(string + i);

	*(dup + length) = '\0';

	return (dup);
}
