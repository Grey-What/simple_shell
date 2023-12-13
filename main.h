#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

/**
 * struct Builtins - match input command to possible builtins
 *
 * @command: potensial builtin;
 * @function: builtin function to execute if matched
 *
 * Description: match input command to possible builtins
 */

typedef struct Builtins
{
	char *command;
	int (*function)(char **);
} Builtins;

extern Builtins builtin[3];

void prompt(void);
char **get_input();
int execute(char **input, char **av, size_t line_nr);
char *getpath(char **list);
char **construct_list(char *input, char *delim);
void check_builtin(char **list);

int _strlen(const char *string);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *src);
char *_itoa(size_t num);
char *_strcat(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
int _atoi(const char *str);
int _strcmp(const char *s1, const char *s2);

int _print(char *string);
void error(char **av, char **list, size_t line_nr);
void free_list(char **list);

#endif
