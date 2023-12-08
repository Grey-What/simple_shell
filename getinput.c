#include "main.h"
/**
 * get_input - gets input from input stream and returns command
 * Return: input string
*/
char **get_input()
{
	char *input = NULL, **list = NULL;
	size_t buff_size = 0;
	int char_read, i = 0;

	char_read = getline(&input, &buff_size, stdin);
	if (char_read == -1)
	{
		if (feof(stdin))
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
	}
	while(input[i])
	{
		if (input[i] == '\n' && i != 0)
		{
		        input[i] = '\0';
		}
		i++;
	}

	list = construct_list(input, " ");
        if (list == NULL)
        {
                perror("malloc at list");
                exit(EXIT_FAILURE);
        }
	free(input);
	check_builtin(list);
	return (list);
}
