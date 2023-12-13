#include "main.h"
/**
 * error - displays error message
 *
 * @av: list of arguments given to program
 * @list: array of strings containing command and arguements
 * @line_nr: the line_nr of command given
 *
 * Return: void
 */
void error(char **av, char **list, size_t line_nr)
{
	fprintf(stderr, "%s: %lu: %s: not found\n", av[0], line_nr, list[0]);
}
