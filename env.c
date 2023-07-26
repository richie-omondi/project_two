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

	if (env_variable == NULL || shell->env == NULL)
		return (NULL);

	variable_length = str_len(env_variable);

	for (i = 0; shell->env[i]; i++)
	{
		if (_strncmp(env_variable, shell->env[i], variable_length) &&
				shell->env[i][variable_length] == '=')
			return (shell->env[i] + variable_length + 1);
	}
	return (NULL);
}
