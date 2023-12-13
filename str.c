#include "shell.h" 

char *s_dup(const char *str) {
    char *k;
    int x, y;

    if (str == NULL)
        return NULL;

    x = 0;
    while (str[x] != '\0')
        x++;

    k = malloc(sizeof(char) * (x + 1));
    if (k == NULL)
        return NULL;

    for (y = 0; str[y]; y++)
        k[y] = str[y];
    k[y] = '\0'; 


    return k;
}

/**
 * _strcmp - compare string values
 * @s1: input value
 * @s2: input value
 *
 * Return: s1[i] - s2[i]
 */
int _strcmp(const char *s1, const char *s2)
{
int i;

i = 0;
while (s1[i] != '\0' && s2[i] != '\0')
{
if (s1[i] != s2[i])
{
return (s1[i] - s2[i]);
}
i++;
}
return (0);
}

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */
int _strlen(const char *s)
{
int longi = 0;
if (!s)
    return 0;
while (*s != '\0')
{
longi++;
s++;
}
return (longi);
}
char *s_cat(char *dest, const char *src) {
    char *originalDest = dest;

    while (*dest) {
        dest++;
    }

    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return originalDest;
}
/**
 * char *s_cpy - copies the string pointed to by src
 * @dest: copy to
  * @src: copy from
 * Return: string
 */
char *s_cpy(char *dest, char *src)
{
int l = 0;
int x = 0;

while (*(src + l) != '\0')
{
l++;
}
for ( ; x < l ; x++)
{
dest[x] = src[x];
}
dest[l] = '\0';
return (dest);
}
