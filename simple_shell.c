#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
/**
 * display_prompt - Display the shell prompt.
 * Return : 0
 */
void display_prompt(void)
{
if (isatty(fileno(stdin)))
{
printf("Simple_shell$ ");
}
}

/**
 * main - main
 * Return : 0
 */
int main(void)
{
char command[MAX_COMMAND_LENGTH];
while (1)
{
display_prompt();

if (fgets(command, sizeof(command), stdin) == NULL)
{
if (feof(stdin))
{
printf("\nGood Bye\n");
break;
}
else
{
perror("error");
exit(EXIT_FAILURE);
}
}
command[strcspn(command, "\n")] = '\0';
if (strcmp(command, "exit") == 0)
{
printf("Exiting shell.\n");
break;
}
if (fork() == 0)
{
if (execlp(command, command, NULL) == -1)
{
perror("not found");
exit(EXIT_FAILURE);
}
}
else
{
wait(NULL);
}
}
return (0);
}
