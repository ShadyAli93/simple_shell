#include "simple_shell.h"

/**
 * Shell - executes the command
 * @run: command to run
 * Return: 0 on success, -1 if run is exit, 1 on any other error
 */
int Shell(char **run)
{
pid_t pid;
int output;
pid = fork();
if (pid == -1)
{
perror("Exit");
return (1);
}
else if (pid == 0)
{
if (execve(run[0], run, NULL) == -1)
{
perror("Exit");
exit(-1);
}
}
else
wait(&output);
return (0);
}

/**
 * main - main simple shell
 * @argc: number of arguments
 * @argv: list of command line arguments
 * Return: Always 0, -1 on error.
 */
int main(int argc, char **argv)
{
size_t bufsize = BUFSIZ;
char *buffer;
if (argc == 2)
{
if (execve(argv[1], argv, NULL) == -1)
{
perror("Exit");
exit(-1);
}
return (0);
}
buffer = (char *)malloc(bufsize * sizeof(char));
if (buffer == NULL)
{
perror("buffer not found");
exit(1);
}
while (1)
{
printf("#Simple_Shell$ ");
getline(&buffer, &bufsize, stdin);
buffer[_strlen(buffer) - 1] = '\0';
}
return (0);
}
