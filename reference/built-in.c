#include "main.h"
/**
* check_builtin - check if a command is built-in
* @command: arguements.
* Return: 1 on success or else 0.
*/
int check_builtin(char **command)
{
	if (command[0] == NULL || !command)
		return (0);
	if (_strcmp(command[0], "exit") == 0)
		exit_shell(command);
	else
		return (0);
	return (1);
}
