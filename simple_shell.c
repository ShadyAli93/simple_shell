#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


#define MAX_INPUT_SIZE 1024

/**
 * execute command - Execute a command using fork, exec and wait system cal
 * @command : The command to execute
 *
 * Return: None
 */
void execute_command(char *command)
{

	/* TODO: Utilize the logic to execute the given command */
	/* You might need to utilise fork, exec and wait for system calls */

}

/**
 * main - Entry point of the simple shell program
 *
 * Return: Always 0
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];

	while (1)
	{
		printf("simple_shell$ ");
		fgets(input, MAX_INPUT_SIZE, stdin);

		/* Remove the trailing character of the newline from what exists */
		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0) {
			break;
		}

		execute_command (input);
	}

	return 0;

}
