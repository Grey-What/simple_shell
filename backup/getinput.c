#include "main.h"
/**
 * get_input - gets input from input stream and returns command
 * Return: input string
*/
char *get_input()
{
	char *buff = NULL;
	size_t buff_size = 0;
	int char_read, i = 0;

	char_read = getline(&buff, &buff_size, stdin);
	if (char_read == -1)
	{
		if (feof(stdin))
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
	}
	while(buff[i])
	{
		if (buff[i] == '\n' && i != 0)
		{
			buff[i] = '\0';
		}
		i++;
	}
	return (buff);
}
