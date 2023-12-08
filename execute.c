#include "main.h"
/**
 * free_list - frees an array of pointers
 *
 * @list: array of pointers to free
 *
 * Return: void
 */
void free_list(char **list)
{
	int i = 0;

	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
}
/**
 * construct_list - creates a list of tokens
 * @input: input string
 * @delim: delim to split input
 * Return: list of command + arguments
 */
char **construct_list(char *input, char *delim)
{
	char **list = NULL;
	char *token = NULL, *temp;
	size_t count = 0, i = 0;

	temp = _strdup(input);
	if (!temp)
		return (NULL);

	token = strtok(temp, delim);

	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}
	free(temp);

	list = malloc(sizeof(char *) * (count + 1));
	if (!list)
		return (NULL);

	token = strtok(input, delim);

	while (token != NULL)
	{
		list[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (list[i] == NULL)
		{
			free_list(list);
			return (NULL);
		}
		_strcpy(list[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	list[i] = NULL;

	return (list);
}
/**
 * execute - function execute command given as input
 *
 * @list: array of strings containing commands and arguements
 * @av: array of strings containing command line arguements
 * @line_nr: line number of command
 *
 * Return: 0
 */
int execute(char **list, char **av, size_t line_nr)
{
	pid_t pid;
	char *pathname;
	(void)av;

	if (list[0][0] != '/')
	{
		pathname = getpath(list[0]);
		if (pathname != NULL)
		{
			free(list[0]);
			list[0] = pathname;
		}
		else
		{
			error(av, list, line_nr);
			free_list(list);
			return (0);
		}
	}
	pid = fork();

	if (pid == -1)
	{
		free_list(list);
		perror("fork");
	}
	else if (pid == 0)
	{
		execve(list[0], list, environ);
		error(av, list, line_nr);
		_exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		wait(&status);
		free_list(list);
	}
	return (0);
}
