#include "shell.h"
/**
 * check_file - Checks if a file exits, is not a directory and
 * has execution permissions
 * @path: path to be checked
 *
 * Return: 0 on success, 12 or 127 on error
 */

int check_file(char *path)
{
	struct stat st;

	int retval;

	retval = stat(path, &st);

	if (retval == 0)
	{
		if (S_ISDIR(st.st_mode) || !(access(path, X_OK)))
		{
			errno = 126;
			return (126);
		}
		else
			return (0);
	}
	else if (retval == -1)
	{
		errno = 127;
		return (127);
	}
	else
		return (-1);
}
