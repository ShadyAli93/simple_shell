#ifndef SIMPLE
#define SIMPLE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int _putchar(char c);
int _strlen(char *str);
char **stoken(char *str);
unsigned int nspaces(char *s);
void _puts(char *str);
#endif
