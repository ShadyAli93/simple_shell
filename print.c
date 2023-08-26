#include "simple_shell.h"

/**
 * print_environment - Prints
 *
 */

void print_environment(void)
{
int i = 0;
while (environ[i])
{
printf("%s\n", environ[i++]);
}
}
