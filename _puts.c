#include "simple_shell.h"
/**
 * _puts - function that prints a string
 * @str: pointer to the string to print
 * Return: void
 */
void _puts(char *str)
{
	int a;

	a = 0;
	while (str[a])
	{
		_putchar(str[a]);
		a++;
	}
}
