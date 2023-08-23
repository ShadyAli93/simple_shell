#include "simple_shell.h"

/**
 * _strlen - measures the length of a string
 * @str: variable
 * Return: count
 */
int _strlen(char *str)
{
int count;
count = 0;
while (str && *str != '\0')
{
count++;
str++;
}
return (count);
}
