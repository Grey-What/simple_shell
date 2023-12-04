#include "main.h"
/**
* prompt - displays prompt in interactive mode.
* Return: void 
*/
void prompt()
{
	if (isatty(STDIN_FILENO))
	{
		_print("$ ");
	}
	return;
}

