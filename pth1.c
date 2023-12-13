#include "shell.h"

char pth(const char *inputcommand)
{
    if (inputcommand[i] == '/')
    {
        if (stat(inputcommand, &st) == 0)
            return (s_dup(inputcommand));
        return (NULL);
    }
    i++;
}