#include "shell.h"

/**
 * env_f - khkhk
 * @command:hkhkh
 * Return: hkhk
 */

void env_f(char **command)
{
	char **env = environ;

		while (*env != NULL)
		{
			write(STDOUT_FILENO, *env, strlen(*env));
			write(STDOUT_FILENO, "\n", 1);
			env++;
		}
		freearr(command);
}
