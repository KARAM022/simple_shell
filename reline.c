#include "shell.h"
/**
 * readline - function readline
 * Return: char or null if an error or if eof is reched
 */
char *readline(void)
{
char *buffofline = NULL;
size_t sizeofle = 0;
ssize_t rb;

if (isatty(STDIN_FILENO))
{
write(STDOUT_FILENO, "$ ", 2);
}
rb = getline(&buffofline, &sizeofle, stdin);
if (rb == EOF)
{
free(buffofline);
return (NULL);
}
return (buffofline);
}
