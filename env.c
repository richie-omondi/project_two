#include "shell.h"

/**
 * get_env_value - Gets the value of the environment variable
 * @env_variable: environment variable
 * @shell: struct containing data fed to the shell
 *
 * Return: value of the variable or NULL
 */
char *get_env_value(char *env_variable, shell_data *shell)
{
	int i, variable_length;

	shell->env = environ;

	if (env_variable == NULL || shell->env == NULL)
		return (NULL);

	variable_length = str_len(env_variable);

	for (i = 0; shell->env[i] != NULL; i++)
	{
		if (_strncmp(env_variable, shell->env[i], variable_length) == 0)
		{
			if (_strncmp(env_variable, "PATH", variable_length) == 0)
			{
				variable_length++;
				return (shell->env[i] + variable_length);
			}
			else
			{
				while (shell->env[i][variable_length] == '=')
					variable_length++;
				return (shell->env[i] + variable_length);
			}
		}
	}
	return (NULL);
}
