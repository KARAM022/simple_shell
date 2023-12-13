#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>

/**
 * struct Da_ta_s - khk
 * @line_buff:ljlj
 * @input: khkh
 * @status: khkh
 * @count: khkh
 */

typedef struct Da_ta_s
{
	char *line_buff;
	char **input;
	int status;
	int count;
} Da_ta_s;

/**
 * struct EGETENV - khkh
 * @tmp: Temp string
 * @key: Key from env
 * @value: Value from env
 * @env: Env var value
 * @i: Loop counter
 */

typedef struct EGETENV
{
	char *tmp;   /* Temp string */
	char *key;   /* Key from env */
	char *value; /* Value from env */
	char *env;   /* Env var value */
	int i;	   /* Loop counter */
} EGETENV;

#define PRINT_ERROR(name, index, cmd)\
	do {\
		write(STDERR_FILENO, name, _strlen(name));\
		write(STDERR_FILENO, ": ", 2);\
		write(STDERR_FILENO, index, _strlen(index));\
		write(STDERR_FILENO, ": ", 2);\
		write(STDERR_FILENO, cmd, _strlen(cmd));\
		write(STDERR_FILENO, " not found \n", _strlen(" not found\n") + 1);\
	} while (0)

#define TNNEW_LINE " \t\n"

char *readline(void);
char **_tokenit(char *command_input);
char *s_dup(const char *str);
int _strcmp(const char *s1, const char *s2);
int execute(char **command, char **av, int idx);
void freearr(char **ar);

char *my_getenv(char *vari);
void printerror(const char *name, const char *cmd, int idx);
char *_getApTH(const char *command);
char *s_cat(char *dest, const char *src);
int _strlen(const char *s);
void reverse(char str[], int length);
char *_itoa(int num, char *str, int base);
int h_built_in(char **command, char **av, int idx, int status);
char *s_cpy(char *dest, char *src);
extern char **environ;

void cd_f(char **command);
void exit_(char **command, int status);
void env_f(char **command);
char pth(const char *inputcommand);

#endif /*SHELL_H*/
