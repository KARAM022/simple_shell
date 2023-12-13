#include "shell.h"

int h_built_in(char **command, char **av, int idx, int status)
{
    char cwd[1024];

    if (_strcmp(command[0], "cd") == 0)
    {
        if (command[1] == NULL || _strcmp(command[1], "~") == 0)
        {
            if (chdir(getenv("HOME")) != 0)
            {
                perror("chdir");
            }
        }
        else if (_strcmp(command[1], "-") == 0)
        {
            char *p_dir = getenv("OLDPWD");
            if (p_dir == NULL)
            {
                fprintf(stderr, "OLDPWD not set\n");
            }
            else
            {
                if (chdir(p_dir) != 0)
                {
                    perror("chdir");
                }
            }
        }
        else
        {
            if (chdir(command[1]) != 0)
            {
                perror("chdir");
            }
        }

        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            setenv("PWD", cwd, 1);
        }
        else
        {
            perror("getcwd");
        }
        freearr(command);
        return (0);
    }
    else if (_strcmp(command[0], "exit") == 0)
    {
        exit_(command);
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
