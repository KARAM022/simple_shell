#include "shell.h"
<<<<<<< HEAD
=======
#include <sys/stat.h>

>>>>>>> d192df0a635991136b9537d2316efaaa309f3ceb
/**
 * _getApTH - function
 * @inputcommand:variable
 * Return: char
 */
<<<<<<< HEAD
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
while (D)
{
FCDM = malloc(_strlen(D) + _strlen(inputcommand) + 2);
if (FCDM)
{
s_cpy(FCDM, D);
s_cat(FCDM, "/");
s_cat(FCDM, inputcommand);
if (stat(FCDM, &st) == 0)
{
free(PENVTH);
return (FCDM);
}
free(FCDM);
FCDM = NULL;
D = strtok(NULL, ":");
}
}
free(PENVTH);
return (NUL)L;
}
=======

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

	while (D)
	{
		FCDM = malloc(_strlen(D) + _strlen(inputcommand) + 2);

		if (FCDM)
		{
			s_cpy(FCDM, D);
			s_cat(FCDM, "/");

			s_cat(FCDM, inputcommand);

			if (stat(FCDM, &st) == 0)
			{
				free(PENVTH);
				return (FCDM);
			}

			free(FCDM);
			FCDM = NULL;
			D = strtok(NULL, ":");
		}
	}

	free(PENVTH);
	return NULL;
}
>>>>>>> d192df0a635991136b9537d2316efaaa309f3ceb
