#include "shell.h"
#include <sys/stat.h>

/**
 * _getApTH - function
 * @inputcommand:variable
 * Return: char
 */

char *_getApTH(const char *inputcommand)
{
	char *PENVTH, *FCDM, *D;
	struct stat st;

	int i = 0;
	while (inputcommand && inputcommand[i])
	{
		if (inputcommand[i] == '/')
		{
			if (stat(inputcommand, &st) == 0)
				return (s_dup(inputcommand));
			return (NULL);
		}
		i++;
	}

	PENVTH = my_getenv("PATH");

	if (!PENVTH)
		return (NULL);

	D = strtok(PENVTH, ":");

	pth(FCDM, D, inputcommand, PENVTH);

	// free(PENVTH);
	return NULL;
}
