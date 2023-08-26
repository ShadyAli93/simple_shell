#include "simple_shell.h"
/**
 * main - main
 * @ac: variables
 * @av: variables
 * @envp: variables
 * Return: 0
 */
int main(int ac __attribute__((unused)), char *av[], char *envp[])
{
char *b = NULL;
size_t n;
int s;
pid_t c;
signal(SIGINT, SIG_IGN);
while (1)
{
if (isatty(STDIN_FILENO))
printf("Simple_Shell$ ");
if (getline(&b, &n, stdin) == -1 || b == NULL)
break;
av = parse_input(b);
if (!av[0])
{
free(av);
continue;
}
if (strcmp(av[0], "env") == 0)
print_environment(), free(av);
else if (strcmp(av[0], "exit") == 0)
free(av), free(b), exit(0);
else
{
c = fork();
if (c == 0)
{
if (_strchr(av[0], '/') == NULL)
av[0] = path_search(av[0]);
if (execve(av[0], av, envp))
{
perror("execve"), exit(EXIT_FAILURE);
break;
}
}
wait(&s), free(av);
}
}
free(b);
return (0);
}
