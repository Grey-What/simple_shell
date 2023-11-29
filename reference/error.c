#include "main.h"
/**
* _error - prints the error message.
* @command: name of command.
* @argv: arguement vector.
* @err: a struct containing line num of command, and status of shell mode
*/
void _error(char **command, char **argv, Error *err)
{
	char *s = _itoa(err->line_nr);

	if (!s)
		return;

	_print(argv[0]);
	_print(": ");

	if (err->int_act != 1)
	{
		_print(s);
		_print(": ");
	}
	perror(command[0]);
	free(s);
}
