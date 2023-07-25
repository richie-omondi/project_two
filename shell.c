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
	char *shell_sign = "($)";

	int input_length;

	while (1)
	{
		print_string(shell_sign);
		input_length = read_input(shell);
		if (input_length >= 1)
		{
			split_input(shell);
			if (_strncmp(shell->tokens[0], "exit", 4) == 0)
				exit_shell(shell);
			if (shell->tokens[0] != NULL)
				find_and_execute(shell);
		}
		free_shell_data(shell);
	}
}

/**
 * read_input - Reads the input typed by the user
 * @shell: Struct containing data fed to the shell
 *
 * Return: input fed to the shell
 */
int read_input(shell_data *shell)
{
	size_t buffer_size;
	int result;

	buffer_size = 0;

	result = getline(&(shell->input), &buffer_size, stdin);

	if (result == -1)
	{
		if (result == EOF)
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(errno);
		}
		else
		{
			perror("Read input");
			exit(EXIT_FAILURE);
		}
	}

	return (str_len((shell->input)));
}

/**
 * split_input - tokenizes a string
 * @shell: struct containing data fed to the shell
 *
 * Return: individual tokens
 */
char **split_input(shell_data *shell)
{
	char *token = NULL;

	char **temp = NULL;

	int j, index = 0, buffer_size = BUFFER_SIZE;

	shell->tokens = malloc(buffer_size * sizeof(char *));

	if (!(shell->tokens))
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
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
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
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
