#include "main.h"
/**
* main - entry point to shell
*
* @ac: number of arguements
* @av: array of strings containing command line arguements.
*
* Return: Always 0
*/
int main(int ac, char **av)
{
	char **input;
	size_t line_nr = 0;

	(void)ac;

	do {
		if (isatty(STDIN_FILENO) == 0)
			line_nr++;

		prompt();
		input = get_input();

		if (!input)
		{
			perror(av[0]);
			continue;
		}
		execute(input, av, line_nr);

	} while (1);
	return (0);
}
