#include "main.h"
/**
 * _getline - gets input from input stream and returns command
 *
 * Return: input string
 */
char *_getline()
{
	char *buff = NULL;
	size_t buff_size = 0;
	int char_read, i = 0;

	if (isatty(STDIN_FILENO))
	{
		_print("$ ");
	}

	char_read = getline(&buff, &buff_size, stdin);

	if (char_read == -1)
	{
		return (NULL);
	}
	while (buff[i])
	{
		if (buff[i] == '\n' && i != 0)
			buff[i] = '\0';
		i++;
	}
	return (buff);
}
