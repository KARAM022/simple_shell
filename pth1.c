#include "shell.h"

char *pth(char *FCDM, char *D, const char *inputcommand, char *PENVTH)
{
    struct stat st;
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
                // free(PENVTH);
                return (FCDM);
            }

            free(FCDM);
            FCDM = NULL;
            D = strtok(NULL, ":");
        }
    }
}