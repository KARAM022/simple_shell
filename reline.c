#include "shell.h"
/**
 * readline - function readline
 * Return: char or null if an error or if eof is reched
 */
char *readline(void)
{
char *line = NULL;
size_t len = 0;
ssize_t rb;

if (isatty(STDIN_FILENO))
{
write(STDOUT_FILENO, "$ ", 2);
}
rb = getline(&line, &len, stdin);
if (rb == EOF)
{
free(line);
return (NULL);
}
return (line);
}
