#include "shell.h"

/**
 * compare_env_var - compares environemnt variable name
 * with the name passed.
 * @variable: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if not equal, another value if they are.
 */
int compare_env_var(char *variable, char *name)
{
	int i = 0;

	for (i = 0; variable[i] != '='; i++)
	{
		if (variable[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * get_env_value - get the environment variable value
 * @variable: name of the environment variable
 * @shell: struct containing environemnt data
 *
 * Return: value of the environment variable.
 * Else, return NULL.
 */
char *get_env_value(char *variable, shell_data *shell)
{
	char *variable_pointer = NULL;
	int i = 0, result = 0;

	for (i = 0; shell->env[i]; i++)
	{
		result = compare_env_var(shell->env[i], variable);
		if (result)
		{
			variable_pointer = shell->env[i];
			break;
		}
	}

	return (variable_pointer + result);
}
