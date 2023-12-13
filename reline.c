#include "shell.h"
/**
 * readline - function readline
 * Return: char or null if an error or if eof is reched
 */
#include "shell.h"

char *readline(void) {
    char *line = NULL;
    size_t len = 0;
    ssize_t n;

    if (isatty(STDIN_FILENO)) {
        write(STDOUT_FILENO, "$ ", 2);
    }

    n = getline(&line, &len, stdin);

    if (n == EOF) {
        free(line);
        return NULL;
    }

    return line;
}
