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
		line_nr++;
		prompt();
		input = get_input();
		if (input == NULL)
		{
			perror(av[0]);
			continue;
		}
		execute(input, av, line_nr);
		/*free(input);*/
	} while (1);
	return (0);
}
