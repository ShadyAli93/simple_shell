#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INPUT_LENGTH 1024
int main() 
{
char input[MAX_INPUT_LENGTH];
while (1) 
{
printf("Shady$");
if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL) 
{
break;
}
input[strcspn(input, "\n")] = '\0';
printf("You entered: %s\n", input);
}
return (0);
}

