#include "main.h"
/**
 * free_com - frees array of strings containing commands and arguments
 *
 * @array: list of strings to free
 *
 * Return: nothing
 */
void free_com(char **array)
{
	int i = 0;

	if (!array)
		return;

	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
