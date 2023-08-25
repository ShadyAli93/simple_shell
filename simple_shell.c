#include "simple_shell.h"

/**
 * Shell - executes the command
 * @code: variable
 * Return: 0 & 1 & -1
 */
int Shell(char **code)
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
if (execve(code[0], code, NULL) == -1)
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
 * @argc: variable
 * @argv: variable
 * Return: 0 & -1
 */
int main(int argc, char **argv)
{
size_t bufsize = BUFSIZ;
char *buffer, **tokens;
int response;

if (argc == 2)
{
if (execve(argv[1], argv, NULL) == -1)
{
perror("Error");
exit(-1);
}
return (0);
}
buffer = (char *)malloc(bufsize * sizeof(char));
if (buffer == NULL)
{
perror("buffer is not allocated");
exit(1);
}
do {
printf("#Simple_Shell$ ");
getline(&buffer, &bufsize, stdin);
buffer[_strlen(buffer) - 1] = '\0';
tokens = stoken(buffer);
response = Shell(tokens);
if (feof(stdin))
{
printf("\n");
exit(0);
}
} while (response != -1);
return (0);
}
