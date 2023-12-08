#include "main.h"
/**
* _print - print a string to standard output
* @string: string
* Return: number of characters wrote or -1
*/
int _print(char *string)
{
	return (write(STDOUT_FILENO, string, _strlen(string)));
}
/**
 * _strcmp - this function compares two strings
 *
 * @s1: is the first string
 * @s2: is the second string
 *
 * Return: 0 if string is equal, >0 if s1 char is larger in ascii value then
 * char in s2, <0 if ascii value is less than that of char in s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/**
 * _atoi - convrts string to int
 *
 * @str: string to convert
 *
 * Return: the converted int
 */
int _atoi(const char *str)
{
	int result = 0;
	int sign = 1;

	if ((*str == '-') || (*str == '+'))
	{
        if (*str == '-')
	{
            sign = -1;
        }
        str++;
    }

    while ((*str >= '0') && (*str <= '9'))
    {
        result = result * 10 + (*str - '0');
        str++;
    }

    return (result * sign);
}
