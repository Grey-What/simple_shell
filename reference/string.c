#include "main.h"
/**
 * _strcpy - function copies a string
 *
 * @dest: copied string
 * @src: original string
 *
 * Return: pointer to copied string
 */
char *_strcpy(char *dest, const char *src)
{
	int i;
	int len = 0;

	while (src[len] != '\0')
	{
		len++;
	}
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - this function returns the length of a string
 *
 * @s: this is the string who's lenght must be determined
 *
 * Return: this function returns the lenght of a string
 */
int _strlen(const char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strcat - this function concatenates two strings
 *
 * @dest: is the first string
 * @src: is thesecond string
 *
 * Return: pointer to string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;
	int count = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	count = i;
	while (src[j] != '\0')
	{
		dest[count + j] = src[j];
		j++;
	}
	dest[count + j] = '\0';
	return (dest);
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
 * _strncmp - compares n number of chars in two strings
 *
 * @s1: first string
 * @s2: second string
 * @n: number of characters to compare
 *
 * Return: 0 if chars compared are equal, else differnece in chars not matching
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2)
		return (*(unsigned char *) s1 - *(unsigned char *) s2);
		if (*s1 == '\0')
		return (0);
	s1++;
	s2++;
	}
	return (0);
}
