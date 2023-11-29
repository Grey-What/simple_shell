#include "main.h"
/**
 * _execute - execute command and arguments
 *
 * @command: command and arguments
 * @argv: arguments given to string
 * @path: path
 * Return: -1 on fail, else 0
 */
int _execute(char *path, char **command, char **argv)
{
	int check_exe = 0;
	pid_t pid;
	(void)argv;

	if (command == NULL || !path || *command == NULL)
		return (-1);

	pid = fork();

	if (pid == -1)
	{
		return (-1);
	}
	else if (pid == 0)
	{
		check_exe = execve(path, command, environ);

		if (check_exe)
		{
			return (-1);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		wait(&status);
	}
	return (0);
}
