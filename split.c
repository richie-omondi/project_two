#include "shell.h"

/**
 * str_tok - Tokenizes input using delimiters
 * @str: String to split
 * @delim: Delimiters
 *
 * Return: String representing tokenized input
 */

char *str_tok(char *str, const char *delim)
{
	static char *last_token = NULL;
	char *token_start = NULL;
	bool delim_found = false;

	if (str == NULL)
		str = last_token;

	while (*str != '\0' && str_chr(delim, *str) != NULL)
		str++;
	if (*str == '\0')
	{
		last_token = NULL;
		return (NULL);
	}
	token_start = str;

	while (*str != '\0' && str_chr(delim, *str) == NULL)
		str++;

	if (*str != '\0')
	{
		*str = '\0';
		delim_found = true;
	}

	last_token = delim_found ? str + 1 : str;

	return (token_start);
}
