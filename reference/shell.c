#include "main.h"
/**
 * main - entry point to program
 *
 * @ac: number of arguments on command line
 * @argv: array of strings containing command line arguments
 *
 * Return: Always 0
 */
int main(__attribute__ ((unused)) int ac, char **argv)
{
	char *buffer = NULL, *delim = " ", **command = NULL, *path = NULL;
	int check_exe = 0;
	Error *err = malloc(sizeof(Error));

	err->line_nr = 0;
	err->int_act = isatty(STDIN_FILENO);

	do {
		err->line_nr++;
		buffer = _getline();
		if (buffer == NULL || buffer[0] == '\0')
			break;
		else if (buffer[0] == '\n')
			continue;
		command = parse_buff(buffer, delim);
		if (!command || !*command)
		{
			free(buffer);
			free_com(command);
			continue;
		}
		if (_strncmp(command[0], "/", 1) == 0)
			path = command[0];
		else
			path = get_path(command[0]);
		if (path == NULL)
		{
			_error(command, argv, err);
			free(buffer);
			free_com(command);
			continue;
		}
		check_exe = _execute(path, command, argv);
		if (check_exe == -1)
			_error(command, argv, err);
		free_com(command);
		free(buffer);
	} while (1);
	return (0);
}
