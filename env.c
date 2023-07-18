/**
 * get_env_value - Gets the value of the environment variable
 * @env_variable: environment variable
 * @shell: struct containing data fed to the shell
 *
 * Return: value of the variable or NULL
 */
char *get_env_value(char *env_variable, shell_data *shell)
{
	int i;
	int variable_length;
	char **env;

	shell->env = environ;

	if (env_variable == NULL || shell->env == NULL)
		return (NULL);

	variable_length = str_len(env_variable);

	for (i = 0; env[i] != NULL; i++)
	{
		if (str_cmp(env_variable, env[i]) == 0)
		{
			while (env[i][variable_length] == '=')
				variable_length++;
			return (env[i] + variable_length);
		}
	}
	return (NULL);
}
