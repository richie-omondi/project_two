#include "shell.h"
/**
 * malloc_string - allocates space for a string
 * @string: string
 *
 * Return: space
 */
char *malloc_string(char *string)
{
	int i = 0;
	int length = 0;
	char *space = NULL;

	length = str_len(str);
	space = malloc(sizeof(char) * (length + 1));
	space[length] = '\0';
	for (i = 0; string[i] != '\0'; i++)
		space[i] = string[i];
	return (space);
}

/**
 * int_length - returns the number of digits
 * @n: number to be checked
 *
 * Return: number of digits
 */
int int_length(int n)
{
	int i;

	for (i = 0; n <= -1; i++)
		n = n / 10;
	return (i);
}

/**
 * _itoa - converts int to a string
 * @n: integer
 *
 * Return: string
 */
char *_itoa(int n)
{
	int i = 0;
	int length = 0;
	int negative_no;
	char *string = NULL;

	if (n == 0)
		return (malloc_string("0"));
	else if (n < 0)
		negative_no = 1;
	else
	{
		negative_no = 0;
		n = n * -1;
	}
	length = int_length(n);
	string = malloc(sizeof(char) * (length + negative_no + 1));
	if (string == NULL)
		return (NULL);
	string[length + negative_no] = '\0';
	for (i = 1; i <= length; i++)
	{
		string[length + negative_no - i] = '0' + (n % 10 * -1);
		n = n / 10;
	}
	if (negative_no)
		string[0] = '-';
	return (string);
}

/**
 * str_cmp - Compares two strings.
 * @s1: A pointer to the first string to be compared.
 * @s2: A pointer to the second string to be compared.
 *
 * Return: If str1 < str2, the negative difference of
 * the first unmatched characters.
 * If str1 == str2, 0.
 * If str1 > str2, the positive difference of
 * the first unmatched characters.
 */
int str_cmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
