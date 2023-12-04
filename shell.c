#include "main.h"
/**
* main - entry point to shell
* @ac: number of arguements
* @av: array of strings containing command line arguements.
* Return : Always 0
*/
int main(int ac, char **av)
{
	char *input;

	(void)ac;
	(void)av;

	
	do {
		prompt();
		input = get_input();
		_print(input);
		free(input);
	} while (1);
	return (0);
}
