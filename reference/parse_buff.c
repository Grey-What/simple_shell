#include "main.h"
/**
 * parse_buff - will tokenize a string into command and arguments
 *
 * @buff: string containing command and arguements
 * @delim: deliminator.
 * Return: list of tokens
 */
char **parse_buff(char *buff, char *delim)
{
	char **command = NULL, *token = NULL, *temp = NULL;
	int i = 0, num_tokens = 0, check_in = 0;

	temp = _strdup(buff);
	token = strtok(temp, delim);

	while (token)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	free(temp);
	token = NULL;

	command = malloc(sizeof(char *) * (num_tokens + 1));

	if (!command)
		return (NULL);

	token = strtok(buff, delim);
	while (token)
	{
		command[i] = _strdup(token);
		if (command[i] == NULL)
		{
			free_com(command);
			return (NULL);
		}
		token = strtok(NULL, delim);
		i++;
	}
	command[i] = NULL;

	check_in = check_builtin(command);
	if (check_in == 1)
	{
		free(buff);
		return (NULL);
	}
	return (command);
}
