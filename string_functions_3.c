#include "shell.h"

/**
 * is_digit - checks if a character is digit
 * @i: integer variable
 * Return: 1 if true, 0 if false
 */

int is_digit(int i)
{
	return (i >= 48 && i <= 57);
}

/**
 * str_chr - Locates a char in a string
 * @str: String
 * @c: Character
 *
 * Return: Pointer to char occurrence
 */

char *str_chr(const char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}

	return (NULL);
}
