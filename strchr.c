#include "simple_shell.h"

/**
 * _strchr - char
 * @s: variable
 * @c: variable
 * Return: s and 0
 */

char *_strchr(char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
{
return (s);
}
s++;
}
return (0);
}
