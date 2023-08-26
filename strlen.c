#include "simple_shell.h"

/**
  * string_length - lenght
  * @pointer: pointer.
  * Return: c
  */

int string_length(char *pointer)
{
int c = 0;
while (*(pointer + c) != '\0')
{
c++;
}
return (c);
}
