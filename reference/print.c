#include "main.h"
/**
* _print - prints a string to standard output.
* @string: string
* Return: number of characters wrote or -1.
*/
int _print(char *string)
{
	return (write(STDOUT_FILENO, string, _strlen(string)));
}
/**
 * _strdup - duplicates a string
 *
 * @src: string to duplicate
 *
 * Return: pointer to new string, else NULL
 */
char *_strdup(const char *src)
{
	char *dest = malloc(_strlen(src) + 1);

	if (dest == NULL)
		return (NULL);
	_strcpy(dest, src);

	return (dest);
}
