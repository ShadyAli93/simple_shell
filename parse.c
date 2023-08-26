#include "simple_shell.h"
/**
 * parse_input - parses
 * @buffer: variables
 * Return: cmd
 */
char **parse_input(char *buffer)
{
char **cmd = NULL;
char *token, *delim = " \n";
int tok_counter = 0;
cmd = malloc(sizeof(char *) * 1024);
if (cmd == NULL)
{
perror("Failed to allocate memory");
exit(EXIT_FAILURE);
}
token = strtok(buffer, delim);
while (token != NULL)
{
cmd[tok_counter] = token;
token = strtok(NULL, delim);
tok_counter++;
}
cmd[tok_counter] = NULL;
return (cmd);
}
