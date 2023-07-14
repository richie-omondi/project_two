#include "shell.h"

/**
 * handle_signal - prints a new prompt upon a signal
 * @num: signal passed as an integer
 *
 * Return: void
 */
void handle_signal(int num)
{
	char *shell_sign = "\n($) ";

	(void)num;
	signal(SIGINT, handle_signal);
	write(STDIN_FILENO, shell_sign, 20);
}

/**
 * main - Entry point for the program
 * @ac: argument count
 * @av: array containing arguments fed to the shell
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	shell_loop();

	return (EXIT_SUCCESS);
}

/**
 * shell_loop - Function that implements looping-like functionality
 * of the shell
 * @ac: argument count
 * @av: array of argument strings
 *
 * Return: 0 on success
*/
int shell_loop(int ac, char **av)
{
	char *shell_sign = "\n($) ";
	char *str = "";
	char *input;
	char **arguments;
	int status;
	(void) **av;

	signal(SIGINT, handle_signal);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && ac == 1)
		str = shell_sign;

	do {
		print_string(shell_sign);

		input = read_input();
		arguments = split_input();
		status = execute_commands();

		free(input);
		free(arguments);
	} while (status);
}

/**
 * read_input - Reads the input typed by the user
 * @void: no arguments given to the function
 *
 * Return: input fed to the shell
 */
char *read_input(void)
{
	char *input = NULL;
	ssize_t buffer_size = 0;
	int result;

	result = getline(&input, &buffer_size, stdin);

	if (result == -1)
	{
		if (result == EOF)
			exit(errno);
		else
		{
			perror("Read input");
			exit(EXIT_FAILURE);
		}
	}

	return (input);
}
/**
 * split_input - tokenizes a string
 * @input: line written to the shell
 *
 * Return: individual tokens
 */
char *split_input(char *input)
{
	int buffer_size = BUFFER_SIZE;
	int index = 0;
	char **tokens = malloc(buffer_size * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, DELIMITERS);

	while (token != NULL)
	{
		tokens[index] = token;
		index++;

		if (index >= buffer_size)
		{
			buffer_size += BUFFER_SIZE;
			tokens = realloc(tokens, buffer_size * sizeof(char *));

			if (!tokens)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIMITERS);
	}
	tokens[index] = NULL;
	return (tokens);
}
