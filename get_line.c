#include "shell.h"

/**
 * _getline - Reads input from stream
 * @lineptr: Line buffer to store user input
 * @size: Size of buffer
 * @fp: File descriptor to read from
 * Return: No of bytes read
 */
ssize_t _getline(char **lineptr, size_t *size, FILE *fp)
{
	int j = 0, i = 0;
	static ssize_t input = 0;
	ssize_t res = 0;
	char *buf = NULL, *new_buf = NULL;
	char m = 't';

	if (input == 0)
		fflush(fp);
	else
		return (-1);
	input = 0;
	buf = (char *)_calloc(BUFFER_SIZE, sizeof(char));
	if (buf == NULL)
		return (-1);
	while (m != '\n')
	{
		j = read(STDIN_FILENO, &m, 1);
		if (j == -1 || (j == 0 && input == 0))
		{
			free(buf);
			return (-1);
		}
		if (j == 0 && input != 0)
		{
			input = input + 1;
			break;
		}
		if (input >= BUFFER_SIZE)
		{
			new_buf = (char *)_calloc(100, sizeof(char));
			if (new_buf == NULL)
			{
				free(buf);
				return (-1);
			}
			for (i = 0; i < input; i++)
				new_buf[i] = buf[i];
			free(buf);
			buf = new_buf;
		}
		buf[input] = m;
		input++;
	}
	buf[input] = '\0';
	store_line(lineptr, buf, size, input);
	res = input;
	if (j != 0)
		input = 0;
	if (*lineptr != buf)
		free(buf);
	return (res);
}

/**
 * store_line - Manages content of a line
 * @lineptr: Stores input string
 * @buf: String being store to the line
 * @size: Size of line before buffer
 * @buf_size: Buffer length
 *
 * Return: Void
 */
void store_line(char **lineptr, char *buf, size_t *size, size_t buf_size)
{
	if (lineptr == NULL || buf == NULL || size == NULL)
		return;
	if (lineptr == NULL)
	{
		if (buf_size > BUFFER_SIZE)
			*size = buf_size;
		else
			*size = BUFFER_SIZE;

		*lineptr = buf;
	}
	else if (*size < buf_size)
	{
		if (buf_size > BUFFER_SIZE)
			*size = buf_size;
		else
			*size = BUFFER_SIZE;

		*lineptr = buf;
	}
	else
	{
		str_cpy(*lineptr, buf);
		free(buf);
	}
}
