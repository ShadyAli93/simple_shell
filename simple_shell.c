#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#define MAX_INPUT_SIZE 1024

/**
 * execute_command - Execute a command using fork, exec and wait system cal
 * @args : The command to execute
 *
 * Return: None
 */
void execute_command(char *args)
{
pid_t pid = fork();
if (pid < 0)
{
perror("Fork failed");
}
else if (pid == 0)
{
if (execvp(args[0], args) == -1)
perror("Execution failed");
}
exit(EXIT_FAILURE);
}
else
{
waitpid(pid, NULL, 0);
}
}
/**
 * main - Entry point of the simple shell program
 *
 * Return: Always 0
 */
int main(void)
{
while (1)
{
printf("simple_shell$ ");
fgets(input, MAX_INPUT_SIZE, stdin);
input[strcspn(input, "\n")] = '\0';
if (strcmp(input, "exit") == 0)
{
break;
}
execute_command(input);
}
return (0);
}
