#include "simple_shell.h"

/**
 * _strlen - measures the length of a string
 * @str: variable
 * Return: count
 */
int _strlen(char *str)
{
int a = 0;
while (str[a] != '\0')
{
a++;
}
return (a);
}
