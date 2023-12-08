#include "main.h"
/**
 * builtin_exit - exit the shell with exit code if specified
 *
 * @list: array of strings, containing command + arguments
 *
 * Return: 1
 */
int builtin_exit(char **list)
{
	int count = 0;
	int status = 0;

	while (list[count] != NULL)
	{
		count++;
	}
	if (count > 1)
	{
		status = _atoi(list[1]);
		free_list(list);
		exit(status);
	}
	else
	{
		free_list(list);
		exit(EXIT_SUCCESS);
	}

	return (1);
}
Builtins builtin[] = { {"exit", builtin_exit}, {NULL, NULL} };
/**
 * check_builtin - function check if command entered is a builtin
 *
 * @list: array containing command and it's arguments if present
 *
 * Return: void
 */
void check_builtin(char **list)
{
	int i; /*count = 0*/
	int check = 0;
	(void)check;

	for (i = 0; builtin[i].command != NULL; i++)
	{
		if (_strcmp(list[0], builtin[i].command) == 0)
		{
			check = builtin[i].function(list);
		}
	}
}
