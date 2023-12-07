#include "main.h"
/**
* _print - print a string to standard output
* @string: string
* Return: number of characters wrote or -1
*/
int _print(char *string)
{
	return(write(STDOUT_FILENO, string, _strlen(string)));
}
