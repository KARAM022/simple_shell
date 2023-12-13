#include "shell.h"

/**
 * my_getenv - khkhhkk
 * @vari:khhkkh
 * Return: khkhkh
 */

char *my_getenv(char *vari)
{
	EGETENV ENV;

	for (ENV.i = 0; environ[ENV.i]; ENV.i++)
	{
		ENV.tmp = s_dup(environ[ENV.i]);
		ENV.key = strtok(ENV.tmp, "=");

		if (_strcmp(ENV.key, vari) == 0)
		{
			ENV.value = strtok(NULL, "\n");
			ENV.env = s_dup(ENV.value);

			free(ENV.tmp);
			return ENV.env;
		}

		free(ENV.tmp), ENV.tmp = NULL;
	}

	return NULL;
}
