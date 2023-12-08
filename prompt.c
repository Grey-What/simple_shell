
#include "main.h"
/**
* prompt - displays prompt in interactive mode.
*/
void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		_print("$ ");
	}
}
