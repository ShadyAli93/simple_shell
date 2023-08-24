#include "simple_shell.h"
/**
 * nspaces - return the number of string
 * using the number of space
 * @s: string to check
 * Return: int
 */
unsigned int nspaces(char *s)
{
	int i, cmpt = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
			cmpt++;
	}
	return (cmpt);
}


/**
 * stoken - splits strings of different
 * @str: variable
 * Return: tokens
 */
char **stoken(char *str)
{
	int i = 0;
	const char separator[] = " ";
	int spaces = nspaces(str);
	char **tokens = malloc(sizeof(char *) * (spaces + 1));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "sh: allocation error\n");
		exit(1);
	}

	token = strtok(str, separator);

	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, separator);
		i++;
	}
	tokens[i] = NULL;

	return (tokens);
}
