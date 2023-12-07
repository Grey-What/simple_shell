#include "main.h"
/**
 * error - displays error message
 *
 * @av: list of arguments given to program
 * @line_nr: the line_nr of command given
 *
 * Return: void
 */
void error(char **av, char **list, size_t line_nr)
{
	char error_msg[100];
	char *number_string = NULL;

	number_string = _itoa(line_nr);

	_strcpy(error_msg, av[0]);
	_strcat(error_msg, ": ");
	_strcat(error_msg, number_string);
	_strcat(error_msg, ": ");
	_print(error_msg);

	perror(list[0]);
	free(number_string);
}
