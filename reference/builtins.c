#include "main.h"
/**
* exit_shell - exit the shell
* @command: arguements
*/
void exit_shell(char **command)
{
	int status = 0;

	if (command[1] != NULL)
		status = _atoi(command[1]);
	free_com(command);
	exit(status);
}
