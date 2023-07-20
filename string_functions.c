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

/**
 * str_cpy - Copies the value of one string to
 * another
 * @dest: Pointer to storage of the copied string
 * @src: Pointer to the string being copied
 *
 * Return: Returns the string copied
 */

char *str_cpy(char *dest, const char *src)
{
	char *original_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (original_dest);
}

/**
 * str_cat - concatenates two strings
 * @s1: Pointer to initail string value
 * @s2: Pointer to the string being appended
 *
 * Return: A string that post the concatenation
 */

char *str_cat(const char *s1, const char *s2)
{
	ssize_t len1 = 0, len2 = 0;

	char *res;

	if (s1 != NULL)
		len1 = str_len(s1);
	if (s2 != NULL)
		len2 = str_len(s2);
	res = (char *)malloc(len1 + len2 +1);
	if (res == NULL)
	{
		perror("Memory allocation failure");
		exit(EXIT_FAILURE);
	}
	if (s1 != NULL)
		str_cpy(res, s1);
	else
		*res = '\0';
	if (s2 != NULL)
		str_cpy(res + len1, s2);

	free(res);

	return (res);
}
