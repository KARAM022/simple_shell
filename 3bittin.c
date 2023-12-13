#include "shell.h"

int h_built_in(char **command, char **av, int idx, int status)
{
    

    if (_strcmp(command[0], "cd") == 0)
    {
        cd_f(command)
    }
    else if (_strcmp(command[0], "exit") == 0)
    {
        exit_(command, status);
    }
    else if (_strcmp(command[0], "env") == 0)
    {
        char **env = environ;

        while (*env != NULL)
        {
            write(STDOUT_FILENO, *env, strlen(*env));
            write(STDOUT_FILENO, "\n", 1);
            env++;
        }
        freearr(command);
        return 0;
    }
    return execute(command, av, idx);
}
