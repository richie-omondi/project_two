#include "shell.h"

/**
 * main - Entry point for the program
 * @ac: argument count
 * @av: array containing arguments fed to the shell
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	shell_data shell_info = { NULL };
	shell_data *shell = &shell_info;

	signal(SIGINT, handle_signal);
	add_data_to_shell(shell, ac, av);
	shell_loop(shell);

	return (EXIT_SUCCESS);
}

/**
 * shell_loop - Function that implements looping-like functionality
 * of the shell
 * @shell: struct containing data fd to the shell
 *
 * Return: 0 on success
*/
void shell_loop(shell_data *shell)
{
	int input_length = 0;

	char *shell_sign = "($)";

	while (++(shell->no_of_executions))
	{
		if (isatty(STDIN_FILENO))
		{
			print_string(shell_sign);
			fflush(stdout);
		}
		input_length = read_input(shell, BUFFER_SIZE);
		if (input_length >= 1)
		{
			split_input(shell);
			if (shell->tokens[0])
				execute_commands(shell);
		}
	}
	free_shell_data(shell);
}

/**
 * read_input - Reads the input typed by the user
 * @shell: Struct containing data fed to the shell
 * @buffer_size: size of the buffer
 *
 * Return: input fed to the shell
 */
int read_input(shell_data *shell, size_t buffer_size)
{
	int result;

	result = getline(&(shell->input), &buffer_size, stdin);

	if (result == -1)
	{
		if (result == EOF)
		{
			if (shell->input)
				free(shell->input);

			free_without_input(shell);
			exit(EXIT_SUCCESS);
		}
		else
			exit(EXIT_FAILURE);
	}
	return (str_len(shell->input));
}

/**
 * split_input - tokenizes a string
 * @shell: struct containing data fed to the shell
 *
 * Return: individual tokens
 */
char **split_input(shell_data *shell)
{
	int j;

	int index = 0, buffer_size = BUFFER_SIZE;

	char **temp = NULL;

	char *token = NULL;

	shell->tokens = malloc(buffer_size * sizeof(char *));

	if (!(shell->tokens))
		exit(EXIT_FAILURE);

	token = strtok(shell->input, DELIMITERS);

	while (token != NULL)
	{
		shell->tokens[index] = token;
		shell->command = shell->tokens[0];
		index++;

		if (index >= buffer_size)
		{
			buffer_size += BUFFER_SIZE;
			temp = malloc(buffer_size * sizeof(char *));

			if (!temp)
				exit(EXIT_FAILURE);
			for (j = 0; j < index; j++)
				temp[j] = shell->tokens[j];
			shell->tokens = temp;
			shell->command = shell->tokens[0];
		}
		token = strtok(NULL, DELIMITERS);
	}
	shell->tokens[index] = NULL;
	return (shell->tokens);
}

/**
 * handle_signal - prints a new prompt upon a signal
 * @signal: signal
 *
 * Return: void
 */
void handle_signal(int signal)
{
	char *shell_sign = "($)";

	if (signal == SIGINT)
	{
		print_string("\n");
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, shell_sign, 3);

		fflush(stdout);
	}
}
